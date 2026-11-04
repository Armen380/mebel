using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Shop;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.CarPark
{
    /// <summary>
    /// Car customers (prototype <c>carT / spawnCar / updCars / carLeave</c>): every 6–11 s a car takes a random free slot
    /// among the first min(8, 4 + shop level) when a product is owned, parks nose-in, its driver shops, walks back, and
    /// the car reverses out and drives off east, freeing the slot. Cars are pooled per colour.
    /// </summary>
    public sealed class CarDirector : MonoBehaviour
    {
        const string ShopPadId = "shop";

        [Tooltip("One prefab per car colour (prototype CAR_COLORS).")]
        [SerializeField] List<Car> variants = new List<Car>();
        [SerializeField] CustomerDirector customers;

        readonly List<Car> _cars = new List<Car>(8);
        readonly List<Stack<Car>> _free = new List<Stack<Car>>();
        readonly List<int> _slotScratch = new List<int>(8);
        Car[] _slots;

        EconomyConfig _economy;
        WorldLayout.CarParkSettings _lot;
        WorldLayout.RoadSettings _road;
        IUpgradeLevels _levels;
        WorldStateSnapshot _state;
        float _timer;

        public IReadOnlyList<Car> Cars => _cars;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<Car> carVariants, CustomerDirector customerDirector)
        {
            variants = carVariants;
            customers = customerDirector;
        }

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _lot = db.world.carPark;
            _road = db.world.road;
            _levels = Services.Get<IUpgradeLevels>();
            _state = Services.Get<WorldStateSnapshot>();
            _slots = new Car[_lot.slotCount];
            _timer = _economy.carFirstSpawnSeconds;
            for (int v = 0; v < variants.Count; v++) _free.Add(new Stack<Car>());
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            _timer -= dt;
            if (_timer <= 0f)
            {
                _timer = Random.Range(_economy.carSpawnMinSeconds, _economy.carSpawnMaxSeconds);
                TrySpawn();
            }

            for (int i = _cars.Count - 1; i >= 0; i--)
            {
                Car car = _cars[i];
                car.StateTime += dt;
                if (car.State == Car.Phase.Parked)
                {
                    if (car.DriverBack) Leave(car);
                    continue;
                }
                car.Motion.Step(dt, _lot, _economy);
                car.Sync();
                if (!car.Motion.Arrived) continue;
                if (car.State == Car.Phase.Arriving)
                {
                    car.State = Car.Phase.Parked;
                    car.StateTime = 0f;
                    if (!customers.SpawnFromCar(car)) Leave(car);
                }
                else Despawn(i);
            }
        }

        void TrySpawn()
        {
            if (variants.Count == 0 || _state.OwnedProducts.Count == 0) return;
            _slotScratch.Clear();
            int open = Mathf.Min(_slots.Length, _economy.CarSlots(_levels.GetLevel(ShopPadId)));
            for (int s = 0; s < open; s++)
                if (_slots[s] == null) _slotScratch.Add(s);
            if (_slotScratch.Count == 0) return;

            int slot = _slotScratch[Random.Range(0, _slotScratch.Count)];
            Car car = Take(Random.Range(0, variants.Count));
            car.ResetRide();
            car.Slot = slot;
            car.State = Car.Phase.Arriving;
            car.DriverDoor = CarRoute.DriverDoor(_lot, slot);
            car.Motion.Place(CarRoute.Spawn(_lot, _road), -Mathf.PI / 2f);
            CarRoute.Arrive(_lot, _road, slot, car.Motion.Path);
            car.Sync();
            _slots[slot] = car;
            _cars.Add(car);
        }

        void Leave(Car car)
        {
            car.State = Car.Phase.Leaving;
            car.StateTime = 0f;
            CarRoute.Depart(_lot, _road, car.Slot, car.Motion.Path);
        }

        Car Take(int variant)
        {
            Car car = _free[variant].Count > 0 ? _free[variant].Pop() : Create(variant);
            car.gameObject.SetActive(true);
            return car;
        }

        Car Create(int variant)
        {
            Car car = Instantiate(variants[variant], transform);
            car.name = variants[variant].name;
            car.PoolIndex = variant;
            return car;
        }

        void Despawn(int index)
        {
            Car car = _cars[index];
            _cars.RemoveAt(index);
            if (car.Slot >= 0 && ReferenceEquals(_slots[car.Slot], car)) _slots[car.Slot] = null;
            car.Slot = -1;
            car.State = Car.Phase.Gone;
            car.gameObject.SetActive(false);
            _free[car.PoolIndex].Push(car);
        }
    }
}
