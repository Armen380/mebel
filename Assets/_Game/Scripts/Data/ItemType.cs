namespace FF.Data
{
    public enum ItemType
    {
        None,
        Log,
        Plank,
        Clay,
        Iron,
        Bill,
        Chair,
        Sofa,
        Wardrobe,
        Table,
        Kitchen,
        Sink,
        Material,
    }

    public enum ShopKind
    {
        Main,
        Materials,
    }

    /// <summary>Which line of the factory yard a factory stands in (user layout: pairs across the fence).</summary>
    public enum FactoryRow
    {
        /// <summary>In front of the fence, facing the road (Sawmill 1's line).</summary>
        Front,
        /// <summary>Behind the fence in the back yard, facing the front row (Sawmill 2's line).</summary>
        Back,
    }

    public enum HatType
    {
        None,
        Beanie,
        Hard,
        Cap,
        Crown,
    }
}
