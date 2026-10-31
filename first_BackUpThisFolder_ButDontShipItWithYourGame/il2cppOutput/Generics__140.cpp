#include "pch-cpp.hpp"





template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		R ret;
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct InvokerFuncInvoker3;
template <typename R, typename T1, typename T2, typename T3>
struct InvokerFuncInvoker3<R, T1, T2*, T3>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2, T3 p3)
	{
		R ret;
		void* params[3] = { &p1, p2, &p3 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887;
struct BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0;
struct BaseRenderGraphPass_2_t407183B2A4BB1007A162B44C240D1E1C26C7FB21;
struct Dictionary_2_t7096FDAEA6CE93401BE4CE39471636261DB28BF5;
struct DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE;
struct DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240;
struct DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0;
struct DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA;
struct DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C;
struct DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0;
struct DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D;
struct DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0;
struct DynamicArray_1_t843ECB88E0EEDBBB658FF535E6B19186D9F69540;
struct IEnumerator_1_t3365AA8A9EB3D51E9974F10F4E3E0156E5726E29;
struct IEnumerator_1_tE1B105F7A153524933EC1CF046C9226B3AC796B2;
struct List_1_t93556F5BC290149F13350CCB1F0DBFFECE376CA3;
struct List_1_t38894513E46A6B97A5AAD6E40AC40F8D0E361549;
struct List_1_tAFCDB9CCBAF11013AA7B0EC7BB51B10127AB467C;
struct List_1_t67B4F73A05A1220FF45824DBE29F391490B25A0C;
struct List_1_t4ACF9489301B655268E8A9C77CAED339DA26EE65;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6;
struct NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62;
struct RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D;
struct RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81;
struct RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56;
struct RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5;
struct RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5;
struct TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7;
struct TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD;
struct TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689;
struct HashEntry_1U5BU5D_t824A58AA39DA3EA6BB6A4E34CA6440B5CA88A5D5;
struct List_1U5BU5D_tBC36CD3A22E16740615AC57FE9C6B659DAC8ECD8;
struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA;
struct NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653;
struct NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07;
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3;
struct TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52;
struct TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9;
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct NameU5BU5D_t4796CCD8033B1FE5DA6C621A2EBFD0581735BF6A;
struct RendererListLegacyResourceU5BU5D_tEB1276E40F8D87935FAB65686AA2A4267B529F38;
struct RendererListResourceU5BU5D_t466A5554891C5C5685BE25122B5C21F312288D5C;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TextureAccessU5BU5D_t02D7243719E98C8FA4B2925C4AACC249913D7293;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251;
struct RandomWriteResourceInfoU5BU5D_t79D1DFED62BB70EF55CFEEDFC5B0413F84F882F3;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7;
struct CompilerContextData_t0E7B5B9E1A939E4546A3AE9D8357556FC956A77D;
struct CullingAllocationInfo_tB260F5CD0B290F74E145EB16E54B901CC68D9D5A;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8;
struct Exception_t;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503;
struct MethodInfo_t;
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8;
struct ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE;
struct RasterCommandBuffer_t4300C4F080EA3CF43C7ACFDBD4F94EA633FE98E8;
struct RenderGraphDefaultResources_tCE331152C84ED1A36CF186CA0092AE10E599E25D;
struct RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437;
struct RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral9AB16B3999460DDC981865934D979087351A14F2;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralC4719FC1E3A10EA1E011F803751AE6CB4774ADA9;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA;
struct NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653;
struct NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07;
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3;
struct TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52;
struct TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9;
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE  : public RuntimeObject
{
	HashEntry_1U5BU5D_t824A58AA39DA3EA6BB6A4E34CA6440B5CA88A5D5* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA  : public RuntimeObject
{
	NameU5BU5D_t4796CCD8033B1FE5DA6C621A2EBFD0581735BF6A* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C  : public RuntimeObject
{
	RendererListLegacyResourceU5BU5D_tEB1276E40F8D87935FAB65686AA2A4267B529F38* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0  : public RuntimeObject
{
	RendererListResourceU5BU5D_t466A5554891C5C5685BE25122B5C21F312288D5C* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D  : public RuntimeObject
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___m_Array;
	int32_t ___U3CsizeU3Ek__BackingField;
};
struct List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6  : public RuntimeObject
{
	float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5 : public RuntimeObject {};
struct TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7  : public RuntimeObject
{
	NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* ____slots;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____slotMap;
	int32_t ____inUseCount;
	int32_t ____pageId;
	int32_t ____nextFreeSlotLine;
};
struct TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD  : public RuntimeObject
{
	NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* ____slots;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____slotMap;
	int32_t ____inUseCount;
	int32_t ____pageId;
	int32_t ____nextFreeSlotLine;
};
struct TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689  : public RuntimeObject
{
	NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* ____slots;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____slotMap;
	int32_t ____inUseCount;
	int32_t ____pageId;
	int32_t ____nextFreeSlotLine;
};
struct RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437  : public RuntimeObject
{
	Dictionary_2_t7096FDAEA6CE93401BE4CE39471636261DB28BF5* ___m_ArrayPool;
	List_1_t93556F5BC290149F13350CCB1F0DBFFECE376CA3* ___m_AllocatedArrays;
	List_1_tAFCDB9CCBAF11013AA7B0EC7BB51B10127AB467C* ___m_AllocatedMaterialPropertyBlocks;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5 
{
	int32_t ___hash;
	int32_t ___lastFrameUsed;
	Il2CppSharedGenericObject* ___compiledGraph;
};
struct NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 
{
	int32_t ____nodeID;
	int32_t ____mainTreeNodeID;
};
struct NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF 
{
	int32_t ____nodeID;
	int32_t ____mainTreeNodeID;
};
struct NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 
{
	int32_t ____nodeID;
	int32_t ____mainTreeNodeID;
};
struct RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 
{
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ____tree;
	int32_t ____version;
	int32_t ____index;
	int32_t ____mainTreeNodeId;
	int32_t ____current;
};
struct RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF 
{
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ____tree;
	int32_t ____version;
	int32_t ____index;
	int32_t ____mainTreeNodeId;
	Il2CppSharedGenericObject* ____current;
};
typedef Il2CppFullySharedGenericStruct RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4;
struct Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 
{
	int32_t ___Start;
	int32_t ___Count;
};
struct RangeIterator_t3E60B0712EA543E538163E8DD9B9F6F036DC1DA3 
{
	DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t559C14703A83268020B566598777B0F935714003 
{
	DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t31377641C6AF599E134F1D01E479C81E62433830 
{
	DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t89474B790B4B6CCD57E3D6A6A4C10DA21890338D 
{
	DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_tE742F0E0379E08C8853BFFCDA8503DA7480AB16B 
{
	DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t97C3725D846495A296FAE832767B011BD390E9F5 
{
	DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t6EA0AFB0D60C265995C33CF173AE593EEBD60514 
{
	DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359 
{
	DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0* ___owner;
	int32_t ___index;
	int32_t ___first;
	int32_t ___last;
};
struct ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
};
struct ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
};
struct ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD 
{
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* ___Ptr;
	int32_t ___Length;
};
struct ReadOnly_t620C834D6C54D781225D753876F232E09821956C 
{
	Il2CppFullySharedGenericStruct* ___Ptr;
	int32_t ___Length;
};
struct ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 
{
	int32_t ___Item1;
	float ___Item2;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 
{
	union
	{
		struct
		{
			uint64_t ___m_rawData;
		};
		uint8_t EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8__padding[8];
	};
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
#pragma pack(push, tp, 1)
struct FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					uint64_t ___byte0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint64_t ___byte0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0008_OffsetPadding[8];
					uint64_t ___byte0008;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0008_OffsetPadding_forAlignmentOnly[8];
					uint64_t ___byte0008_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4__padding[16];
	};
};
#pragma pack(pop, tp)
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 
{
	float ___m00;
	float ___m10;
	float ___m20;
	float ___m30;
	float ___m01;
	float ___m11;
	float ___m21;
	float ___m31;
	float ___m02;
	float ___m12;
	float ___m22;
	float ___m32;
	float ___m03;
	float ___m13;
	float ___m23;
	float ___m33;
};
struct Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354 
{
	String_t* ___name;
	int32_t ___utf8ByteCount;
};
struct Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354_marshaled_pinvoke
{
	char* ___name;
	int32_t ___utf8ByteCount;
};
struct Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354_marshaled_com
{
	Il2CppChar* ___name;
	int32_t ___utf8ByteCount;
};
struct RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 
{
	InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* ___wrappedContext;
	RasterCommandBuffer_t4300C4F080EA3CF43C7ACFDBD4F94EA633FE98E8* ___cmd;
};
struct RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_marshaled_pinvoke
{
	InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* ___wrappedContext;
	RasterCommandBuffer_t4300C4F080EA3CF43C7ACFDBD4F94EA633FE98E8* ___cmd;
};
struct RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_marshaled_com
{
	InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* ___wrappedContext;
	RasterCommandBuffer_t4300C4F080EA3CF43C7ACFDBD4F94EA633FE98E8* ___cmd;
};
struct RenderQueueRange_t7518252AA6426B1EA45D3D9B394F304EEF784D71 
{
	int32_t ___m_LowerBound;
	int32_t ___m_UpperBound;
};
struct ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 
{
	int32_t ___m_Id;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct SortingLayerRange_t96D04CFB4E8824978FEB2CFFFCFEAC37E56D52C9 
{
	int16_t ___m_LowerBound;
	int16_t ___m_UpperBound;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UIntPtr_t 
{
	void* ____pointer;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct float3_t7600B73F092B37F484B12910A5269F30C778D31E 
{
	float ___x;
	float ___y;
	float ___z;
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct U3CshaderPassNamesU3Ee__FixedBuffer_t5EDC823777BDDC9D50E55FF3779FBC1B3820126D 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CshaderPassNamesU3Ee__FixedBuffer_t5EDC823777BDDC9D50E55FF3779FBC1B3820126D__padding[64];
	};
};
struct ByReference_1_t96DAE667B9BC20DC5FA90542D560148F31E98B83 
{
	intptr_t ____value;
};
struct ByReference_1_tCE52B202D24A2ECB85FE96F1DA3C0C6BB73E4001 
{
	intptr_t ____value;
};
struct NodeColor_t60CC6B48EF16CC76598762EF71BFEABD73151911 
{
	int32_t ___value__;
};
struct NodeColor_t3E6579E49ADCA0D1C69F8C6EB9E166F5EEC169EF 
{
	int32_t ___value__;
};
struct NodeColor_t5D6A7FB1CA13C3C221E75A658354858C04D545BC 
{
	int32_t ___value__;
};
struct RangeEnumerable_tCAD7F3DAA47B97F08A0613982FF4A7D5140A9DF8 
{
	RangeIterator_t3E60B0712EA543E538163E8DD9B9F6F036DC1DA3 ___iterator;
};
struct RangeEnumerable_tCAD628CBF84231C9CEF650FBC7333EB79187A10D 
{
	RangeIterator_t559C14703A83268020B566598777B0F935714003 ___iterator;
};
struct RangeEnumerable_t607766088A4B9A781937E9ADBEA1C91E181991EA 
{
	RangeIterator_t31377641C6AF599E134F1D01E479C81E62433830 ___iterator;
};
struct RangeEnumerable_t121EDA184D5371A51AC6E8AD01CF83DDEE591B40 
{
	RangeIterator_t89474B790B4B6CCD57E3D6A6A4C10DA21890338D ___iterator;
};
struct RangeEnumerable_t4FCA60379B38791D5887EECCD10DAD0387B19913 
{
	RangeIterator_tE742F0E0379E08C8853BFFCDA8503DA7480AB16B ___iterator;
};
struct RangeEnumerable_tE3D98CD48F50F5B96255AA07B1AFE8D6B67425AB 
{
	RangeIterator_t97C3725D846495A296FAE832767B011BD390E9F5 ___iterator;
};
struct RangeEnumerable_tD59ED13C16F823F13028F512316C08725D7BA129 
{
	RangeIterator_t6EA0AFB0D60C265995C33CF173AE593EEBD60514 ___iterator;
};
struct RangeEnumerable_t6137B8AC2ED5E0CEDFF987BAF29215CE71A88B05 
{
	RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359 ___iterator;
};
struct UnsafeList_1_t239C74D869DA59B0CA5E63716E71208DEC68A70B 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct AccessFlags_tB7D400C853C05A1DB9C6B56DF14E43721F0B1739 
{
	int32_t ___value__;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct CullingResults_tD6B7EF20B68D47DFF3A99EB2EA73F47F1D460267 
{
	intptr_t ___ptr;
	CullingAllocationInfo_tB260F5CD0B290F74E145EB16E54B901CC68D9D5A* ___m_AllocationInfo;
};
struct CullingSplitMask_t2A1035F9735A157C78BA65C9EC5D892EF682A10D 
{
	uint8_t ___value__;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct DistanceMetric_t071B9815BB961E33F7CA2C553CA725F61AE09EDE 
{
	int32_t ___value__;
};
struct DrawRendererFlags_t3AD0574208BFF93F323D5E1E92012F19EAE972CD 
{
	int32_t ___value__;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct ExtendedFeatureFlags_t736CECC24E1DDF78CDF8A2B134DFF9B1CA2BE01F 
{
	int32_t ___value__;
};
struct FilteringSettings_t75860B12A7BCF9A0E2F13CB2C2E5DCD9E1EEAD9F 
{
	RenderQueueRange_t7518252AA6426B1EA45D3D9B394F304EEF784D71 ___m_RenderQueueRange;
	int32_t ___m_LayerMask;
	uint32_t ___m_RenderingLayerMask;
	uint32_t ___m_BatchLayerMask;
	int32_t ___m_ExcludeMotionVectorObjects;
	int32_t ___m_ForceAllMotionVectorObjects;
	SortingLayerRange_t96D04CFB4E8824978FEB2CFFFCFEAC37E56D52C9 ___m_SortingLayerRange;
};
#pragma pack(push, tp, 1)
struct FixedBytes32Align8_t07C7D543B487721FF9B88AD85209956AE423A779 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0016_OffsetPadding[16];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0016;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0016_OffsetPadding_forAlignmentOnly[16];
					FixedBytes16Align8_t94D49B0852778B92D3912ABC4979B11ADF6ECEE4 ___offset0016_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes32Align8_t07C7D543B487721FF9B88AD85209956AE423A779__padding[32];
	};
};
#pragma pack(pop, tp)
struct PerObjectData_t04DDCBE9ABF1113E8F9BAFCF4A7F94DD841B9CC9 
{
	int32_t ___value__;
};
struct RBTreeError_t7F1B2496C83326D0832CBD24FB32282F348CD048 
{
	int32_t ___value__;
};
struct RenderGraphPassType_tD00EC2DAA135C660EE7E71652291A4672104EA2D 
{
	int32_t ___value__;
};
struct RenderGraphResourceType_t5F552AF06E38DEC5775B77F13C8783A895FCD086 
{
	int32_t ___value__;
};
struct RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 
{
	uintptr_t ___context;
	uint32_t ___index;
	uint32_t ___frame;
	uint32_t ___type;
	uint32_t ___contextID;
};
struct ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 
{
	intptr_t ___m_Ptr;
};
struct ShadingRateCombiner_tF7F5DDD676DF45F67B2A7BC7F14373F4DFAD2B1C 
{
	int32_t ___value__;
};
struct ShadingRateFragmentSize_tE61BBA9B957F4537F04519746FCABE0F5FA94C9F 
{
	int32_t ___value__;
};
struct SortingCriteria_t4907D221CB6E6AA4A32C1ED7B5D17103FD3E7C39 
{
	int32_t ___value__;
};
struct TreeAccessMethod_t93F641AE9C014E6ABDD0A2B1EA84068077F46CC5 
{
	int32_t ___value__;
};
struct ParallelSortValueType_t6D900B4D4AFD1A3DA76F4506E1C06A442F6388E4 
{
	int32_t ___value__;
};
struct FixedList32Bytes_1_t02D797FE0EF11E83016BA95DD7B282490C8A472E 
{
	alignas(8) FixedBytes32Align8_t07C7D543B487721FF9B88AD85209956AE423A779 ___data;
};
struct NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t0AB49EE6A37F6BC668C15EDFBE9BE92A22B2F0DB 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t5576C5C8F17BB3E1BA11BBA3EC50A55FC1246445 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 
{
	int32_t ____selfId;
	int32_t ____leftId;
	int32_t ____rightId;
	int32_t ____parentId;
	int32_t ____nextId;
	int32_t ____subTreeSize;
	int32_t ____keyOfNode;
	int32_t ____nodeColor;
};
struct Node_t299905C052EE0D8A835E38326073B23299A2B8A1 
{
	int32_t ____selfId;
	int32_t ____leftId;
	int32_t ____rightId;
	int32_t ____parentId;
	int32_t ____nextId;
	int32_t ____subTreeSize;
	Il2CppSharedGenericObject* ____keyOfNode;
	int32_t ____nodeColor;
};
typedef Il2CppFullySharedGenericStruct Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034;
struct RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D  : public RuntimeObject
{
	TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81  : public RuntimeObject
{
	TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56  : public RuntimeObject
{
	TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* ____pageTable;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____pageTableMap;
	int32_t ____inUsePageCount;
	int32_t ____nextFreePageLine;
	int32_t ___root;
	int32_t ____version;
	int32_t ____inUseNodeCount;
	int32_t ____inUseSatelliteTreeCount;
	int32_t ____accessMethod;
};
struct ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000 
{
	ByReference_1_t96DAE667B9BC20DC5FA90542D560148F31E98B83 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA 
{
	ByReference_1_tCE52B202D24A2ECB85FE96F1DA3C0C6BB73E4001 ____pointer;
	int32_t ____length;
};
struct InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503  : public RuntimeObject
{
	ScriptableRenderContext_t5AB09B3602BEB456E0DC3D53926D3A3BDAF08E36 ___renderContext;
	CommandBuffer_tB56007DC84EF56296C325EC32DD12AC1E3DC91F7* ___cmd;
	RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* ___renderGraphPool;
	RenderGraphDefaultResources_tCE331152C84ED1A36CF186CA0092AE10E599E25D* ___defaultResources;
	RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93* ___executingPass;
	CompilerContextData_t0E7B5B9E1A939E4546A3AE9D8357556FC956A77D* ___compilerContext;
	bool ___contextlessTesting;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68 
{
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
	bool ___isActive;
};
struct RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68_marshaled_pinvoke
{
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
	int32_t ___isActive;
};
struct RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68_marshaled_com
{
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
	int32_t ___isActive;
};
struct ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C 
{
	uint32_t ___m_VersionIndex;
	uint32_t ___m_Validity;
	int32_t ___m_Type;
};
struct SortingSettings_t506C3B318FDFD3C2B1620E9B951829C631137E72 
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___m_WorldToCameraMatrix;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_CameraPosition;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_CustomAxis;
	int32_t ___m_Criteria;
	int32_t ___m_DistanceMetric;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887  : public MulticastDelegate_t
{
};
struct EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 
{
	FixedList32Bytes_1_t02D797FE0EF11E83016BA95DD7B282490C8A472E ___m_FixedArray;
	UnsafeList_1_t239C74D869DA59B0CA5E63716E71208DEC68A70B ___m_List;
	int32_t ___m_Length;
	bool ___m_Created;
	bool ___m_IsEmbedded;
};
struct Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 
{
	ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874 ___m_Array;
	int32_t ___m_Index;
	NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ___value;
};
struct Nullable_1_tEB29AC5A73D1D1AF8DE0D726A51B415DC226387C 
{
	bool ___hasValue;
	NativeArray_1_t0AB49EE6A37F6BC668C15EDFBE9BE92A22B2F0DB ___value;
};
struct Nullable_1_t791F8A662AA857374FA6AFEEEA22B1F1E103327B 
{
	bool ___hasValue;
	NativeArray_1_t5576C5C8F17BB3E1BA11BBA3EC50A55FC1246445 ___value;
};
struct RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530 
{
	int32_t ___radix;
	int32_t ___jobsCount;
	int32_t ___signBitRadixIndex;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___counter;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indicesSum;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
};
struct RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16 
{
	int32_t ___radix;
	int32_t ___jobsCount;
	int32_t ___signBitRadixIndex;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___counter;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indicesSum;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
};
struct RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C 
{
	int32_t ___radix;
	int32_t ___jobsCount;
	int32_t ___signBitRadixIndex;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___counter;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indicesSum;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
};
struct RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
};
struct RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
};
struct RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___buckets;
};
struct RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___arraySorted;
};
struct RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B ___arraySorted;
};
struct RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D 
{
	int32_t ___radix;
	int32_t ___batchSize;
	int32_t ___valueType;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___array;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___indices;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___arraySorted;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct DrawingSettings_t3B64EB029DB6F94A1F2A9B2D19D2969AE361BB49 
{
	SortingSettings_t506C3B318FDFD3C2B1620E9B951829C631137E72 ___m_SortingSettings;
	U3CshaderPassNamesU3Ee__FixedBuffer_t5EDC823777BDDC9D50E55FF3779FBC1B3820126D ___shaderPassNames;
	int32_t ___m_PerObjectData;
	int32_t ___m_Flags;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_OverrideShaderID;
	int32_t ___m_OverrideShaderPassIndex;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_OverrideMaterialEntityId;
	int32_t ___m_OverrideMaterialPassIndex;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_fallbackMaterialEntityId;
	int32_t ___m_MainLightIndex;
	int32_t ___m_UseSrpBatcher;
	int32_t ___m_LodCrossFadeStencilMask;
	uint8_t ___m_SplitMask;
};
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388 
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	bool ___builtin;
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_pinvoke
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	int32_t ___builtin;
};
struct TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_com
{
	ResourceHandle_tD3B1FFBD59EB9C23F0A020351836F834C4BD276C ___handle;
	int32_t ___builtin;
};
struct Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 
{
	ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0 ___m_Array;
	int32_t ___m_Index;
	EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 ___value;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1 
{
	CullingResults_tD6B7EF20B68D47DFF3A99EB2EA73F47F1D460267 ___cullingResults;
	DrawingSettings_t3B64EB029DB6F94A1F2A9B2D19D2969AE361BB49 ___drawSettings;
	FilteringSettings_t75860B12A7BCF9A0E2F13CB2C2E5DCD9E1EEAD9F ___filteringSettings;
	ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 ___tagName;
	bool ___isPassTagName;
	Nullable_1_t791F8A662AA857374FA6AFEEEA22B1F1E103327B ___tagValues;
	Nullable_1_tEB29AC5A73D1D1AF8DE0D726A51B415DC226387C ___stateBlocks;
};
struct RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1_marshaled_pinvoke
{
	CullingResults_tD6B7EF20B68D47DFF3A99EB2EA73F47F1D460267 ___cullingResults;
	DrawingSettings_t3B64EB029DB6F94A1F2A9B2D19D2969AE361BB49 ___drawSettings;
	FilteringSettings_t75860B12A7BCF9A0E2F13CB2C2E5DCD9E1EEAD9F ___filteringSettings;
	ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 ___tagName;
	int32_t ___isPassTagName;
	Nullable_1_t791F8A662AA857374FA6AFEEEA22B1F1E103327B ___tagValues;
	Nullable_1_tEB29AC5A73D1D1AF8DE0D726A51B415DC226387C ___stateBlocks;
};
struct RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1_marshaled_com
{
	CullingResults_tD6B7EF20B68D47DFF3A99EB2EA73F47F1D460267 ___cullingResults;
	DrawingSettings_t3B64EB029DB6F94A1F2A9B2D19D2969AE361BB49 ___drawSettings;
	FilteringSettings_t75860B12A7BCF9A0E2F13CB2C2E5DCD9E1EEAD9F ___filteringSettings;
	ShaderTagId_t453E2085B5EE9448FF75E550CAB111EFF690ECB0 ___tagName;
	int32_t ___isPassTagName;
	Nullable_1_t791F8A662AA857374FA6AFEEEA22B1F1E103327B ___tagValues;
	Nullable_1_tEB29AC5A73D1D1AF8DE0D726A51B415DC226387C ___stateBlocks;
};
struct TextureAccess_t68FFBA1B28C09FE70680D69372E2208931B66328 
{
	TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388 ___textureHandle;
	int32_t ___mipLevel;
	int32_t ___depthSlice;
	int32_t ___flags;
};
struct TextureAccess_t68FFBA1B28C09FE70680D69372E2208931B66328_marshaled_pinvoke
{
	TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_pinvoke ___textureHandle;
	int32_t ___mipLevel;
	int32_t ___depthSlice;
	int32_t ___flags;
};
struct TextureAccess_t68FFBA1B28C09FE70680D69372E2208931B66328_marshaled_com
{
	TextureHandle_t680ABA3F8B50859351BA5DD66220084F87F37388_marshaled_com ___textureHandle;
	int32_t ___mipLevel;
	int32_t ___depthSlice;
	int32_t ___flags;
};
struct RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93  : public RuntimeObject
{
	String_t* ___U3CnameU3Ek__BackingField;
	int32_t ___U3CindexU3Ek__BackingField;
	int32_t ___U3CtypeU3Ek__BackingField;
	ProfilingSampler_t420D4672EDB44E0EF980B31ADFD9E5747200FECE* ___U3CcustomSamplerU3Ek__BackingField;
	bool ___U3CenableAsyncComputeU3Ek__BackingField;
	bool ___U3CallowPassCullingU3Ek__BackingField;
	bool ___U3CallowGlobalStateU3Ek__BackingField;
	bool ___U3CenableFoveatedRasterizationU3Ek__BackingField;
	int32_t ___U3CextendedFeatureFlagsU3Ek__BackingField;
	TextureAccess_t68FFBA1B28C09FE70680D69372E2208931B66328 ___U3CdepthAccessU3Ek__BackingField;
	TextureAccessU5BU5D_t02D7243719E98C8FA4B2925C4AACC249913D7293* ___U3CcolorBufferAccessU3Ek__BackingField;
	int32_t ___U3CcolorBufferMaxIndexU3Ek__BackingField;
	bool ___U3ChasShadingRateImageU3Ek__BackingField;
	TextureAccess_t68FFBA1B28C09FE70680D69372E2208931B66328 ___U3CshadingRateAccessU3Ek__BackingField;
	bool ___U3ChasShadingRateStatesU3Ek__BackingField;
	int32_t ___U3CshadingRateFragmentSizeU3Ek__BackingField;
	int32_t ___U3CprimitiveShadingRateCombinerU3Ek__BackingField;
	int32_t ___U3CfragmentShadingRateCombinerU3Ek__BackingField;
	TextureAccessU5BU5D_t02D7243719E98C8FA4B2925C4AACC249913D7293* ___U3CfragmentInputAccessU3Ek__BackingField;
	int32_t ___U3CfragmentInputMaxIndexU3Ek__BackingField;
	RandomWriteResourceInfoU5BU5D_t79D1DFED62BB70EF55CFEEDFC5B0413F84F882F3* ___U3CrandomAccessResourceU3Ek__BackingField;
	int32_t ___U3CrandomAccessResourceMaxIndexU3Ek__BackingField;
	bool ___U3CgenerateDebugDataU3Ek__BackingField;
	bool ___U3CallowRendererListCullingU3Ek__BackingField;
	List_1U5BU5D_tBC36CD3A22E16740615AC57FE9C6B659DAC8ECD8* ___resourceReadLists;
	List_1U5BU5D_tBC36CD3A22E16740615AC57FE9C6B659DAC8ECD8* ___resourceWriteLists;
	List_1U5BU5D_tBC36CD3A22E16740615AC57FE9C6B659DAC8ECD8* ___transientResourceList;
	List_1_t67B4F73A05A1220FF45824DBE29F391490B25A0C* ___usedRendererListList;
	List_1_t38894513E46A6B97A5AAD6E40AC40F8D0E361549* ___setGlobalsList;
	bool ___useAllGlobalTextures;
	List_1_t4ACF9489301B655268E8A9C77CAED339DA26EE65* ___implicitReadsList;
};
struct RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214 
{
	RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1 ___desc;
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
};
struct RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214_marshaled_pinvoke
{
	RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1_marshaled_pinvoke ___desc;
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
};
struct RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214_marshaled_com
{
	RendererListParams_t13F72282BCE2DC255747FE7694C6BBC3377944B1_marshaled_com ___desc;
	RendererList_t608CE60421616EF4211F5B8AC62E3C36D4BDDF85 ___rendererList;
};
struct BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0  : public RenderGraphPass_tEFB5BD685D417024760D82991EEEA4F4D0454A93
{
	Il2CppSharedGenericObject* ___data;
	BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887* ___renderFunc;
};
struct RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5  : public BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0
{
};
struct List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6_StaticFields
{
	float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* ___s_emptyArray;
};
struct RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437_StaticFields
{
	DynamicArray_1_t843ECB88E0EEDBBB658FF535E6B19186D9F69540* ___s_AllocatedPools;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_StaticFields
{
	RasterCommandBuffer_t4300C4F080EA3CF43C7ACFDBD4F94EA633FE98E8* ___rastercmd;
};
struct float3_t7600B73F092B37F484B12910A5269F30C778D31E_StaticFields
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___zero;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5_StaticFields
{
	RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 ___c;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3  : public RuntimeArray
{
	ALIGN_FIELD (8) TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* m_Items[1];

	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA  : public RuntimeArray
{
	ALIGN_FIELD (8) Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 m_Items[1];

	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258 value)
	{
		m_Items[index] = value;
	}
};
struct TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52  : public RuntimeArray
{
	ALIGN_FIELD (8) TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* m_Items[1];

	inline TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653  : public RuntimeArray
{
	ALIGN_FIELD (8) Node_t299905C052EE0D8A835E38326073B23299A2B8A1 m_Items[1];

	inline Node_t299905C052EE0D8A835E38326073B23299A2B8A1 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Node_t299905C052EE0D8A835E38326073B23299A2B8A1* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Node_t299905C052EE0D8A835E38326073B23299A2B8A1 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____keyOfNode), (void*)NULL);
	}
	inline Node_t299905C052EE0D8A835E38326073B23299A2B8A1 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Node_t299905C052EE0D8A835E38326073B23299A2B8A1* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Node_t299905C052EE0D8A835E38326073B23299A2B8A1 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____keyOfNode), (void*)NULL);
	}
};
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppSharedGenericObject* m_Items[1];

	inline Il2CppSharedGenericObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Il2CppSharedGenericObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9  : public RuntimeArray
{
	ALIGN_FIELD (8) TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* m_Items[1];

	inline TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4  : public RuntimeArray
{
	ALIGN_FIELD (8) bool m_Items[1];

	inline bool GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline bool* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, bool value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline bool GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline bool* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, bool value)
	{
		m_Items[index] = value;
	}
};
struct float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251  : public RuntimeArray
{
	ALIGN_FIELD (8) float3_t7600B73F092B37F484B12910A5269F30C778D31E m_Items[1];

	inline float3_t7600B73F092B37F484B12910A5269F30C778D31E GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline float3_t7600B73F092B37F484B12910A5269F30C778D31E* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, float3_t7600B73F092B37F484B12910A5269F30C778D31E value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline float3_t7600B73F092B37F484B12910A5269F30C778D31E GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline float3_t7600B73F092B37F484B12910A5269F30C778D31E* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, float3_t7600B73F092B37F484B12910A5269F30C778D31E value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mD782B968CE5256E83614B6E8445F37F5F9A9592B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_gshared_inline (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_fshared_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_mF6068EC2FA94F4B17098D5C83B965F4703FA033A_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_mB8F6DE559009BD1B1683DD96A132A8AF8229F6C7_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m106D0788C3D06308F04C6400B1B3D166396CF84D_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_m54A6D752FBFA8E21B9BE911DEFEBB6EBE27F86B4_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_m8F0068910A5B84B992C5C54617A5313C2736D58B_fshared (uint32_t ___0_bitMap, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55_fshared (NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_mEEBAEC4856EDAB96F400E22D1AE495981435BD97_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, bool ___0_allocatedPage, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TreePage__ctor_m8441E60D204F8F3B8FBF96726C918F8BFD088BD5_gshared (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m02920F187E1C52D2A7E325B08685D3BC171A55F9_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TreePage_AllocSlot_m03CBA01A6EC2A97DA8820AF6BA061837EF01856D_gshared (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_userIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mDBB0AAF0158D6FC0172754C8F2BFD25191BC86E8_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m719AA62C29CBC6C387F371FB1D5D1E5C584ABA7B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_mF9C058080B3A889E3839D76BEDCFBC6BC0EC02D6_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_m1E21B59C97F89684CB754FC49B140B3AFCABA6BD_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_mFF09CA916CAF9842895161A5CCE9B5F6052358DE_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m46F19C443609B114C90100EE95489B06D7E0DF9E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_node, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mA323D5F4BBB074C3BB0A5AA90C195952F45836D0_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_position, Il2CppSharedGenericObject* ___1_item, bool ___2_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTree_1_DeleteByIndex_m66215488DD926BD6C06D66BC1DEC77A2E4AFA36F_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR int32_t RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m3F8F577B4377811997803EDFF4C6D9A87EC74B72_fshared (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_sum, int32_t ___1_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR int32_t RadixSortBatchPrefixSumJob_1_AtomicIncrement_m8EC5C7D3F99DC23EACE0C397BDF89AF029A717B0_fshared (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___0_counter, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_mA78B963B3F0E2BB984306D5941DB9E622B31192A (RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_m71DF9A259A4A7F5463EB48D94570811F2FC1D649 (RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafePtr_TisIl2CppFullySharedGenericStruct_m4AB802D5B1B296D0F976C1E7631699B0C4A4D00F_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t* UnsafeUtility_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mF01FDF0EACCFED286E93933B693A2BE11A6A8946_inline (void* ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25_fshared (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06F913AC64211C19A5F35EB50F3F45685095D3D1 (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mF718C58AF6A48CF95C20FFFAAD3B3870884C4619 (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_mE69747B2B60DA38802FCF96889C1CD7DDC1E3726 (RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6AA2337D311BABD06E7416B028FD039D11211F9A (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m3DFE0C9BE1F74820586102B27F73A072206D136C (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_m9860F3A459E28F8FF1880B9974294C3E35614701 (RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328_fshared (RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m824CF9A6053A2A13ACEB6D4E533B964B9D04DB1A (RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m3A6F0C47238FA5FD88CF5EA0E24E26202F539F73 (RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7_fshared (RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D_fshared (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, int32_t ___0_start, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m6C8D51A9406D6ED9B43B6F126A83EF286FB5DFB3_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Capacity_m5BE6D733C76E1AB093FB6D2783220A5B96EF61DF_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9 (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueTuple_2__ctor_m8AD4450A363A5626EE8665BFDFA6B773D05EE581 (ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69* __this, int32_t ___0_item1, float ___1_item2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E_fshared (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5* DynamicArray_1_get_Item_mDDF17FFCC776B434F220412BAEB139F2350600FA_gshared (DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar* DynamicArray_1_get_Item_mDFF72C07A8872B82B343DBC3B7A134FDED83E74B (DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* DynamicArray_1_get_Item_m5AC8E2913D8C0BE441403585083972B6AD1A49C6 (DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354* DynamicArray_1_get_Item_mEF92855A23D9A2995786E5910FD3425F749EB5C0 (DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68* DynamicArray_1_get_Item_m24D831579B1FD904DCCA4EE983EBD0F19E7E96D5 (DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214* DynamicArray_1_get_Item_m67A96A4CCBC69D31ADE62E5D36A9221CC7E4CAEA (DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject** DynamicArray_1_get_Item_mA2D6D01C2851B649C10AAB4D7F0EB01F2E0596EE_gshared (DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseRenderFunc_2_Invoke_m74AE14F084437149C944CF85887E55871ACC81D8_gshared_inline (BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887* __this, Il2CppSharedGenericObject* ___0_data, RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 ___1_renderGraphContext, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseRenderGraphPass_2_Release_m71C367F7732998859F6B2A4C2168D31BD2922A77_gshared_inline (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0* __this, RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* ___0_pool, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RenderGraphObjectPool_Release_TisIl2CppSharedGenericObject_m41E89F411886EB72C412391048C5DFBB4BF6BFFC_gshared (RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRenderGraphPass_2__ctor_mDB087533ED27EE1E23108F904FD875B485316D27_fshared (BaseRenderGraphPass_2_t407183B2A4BB1007A162B44C240D1E1C26C7FB21* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtility_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m79879C1B15242483D8C9C1E532366BB74B6B9526_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m3A87BBB2A08731ABFE824690AC9B5CCEA26C3230 (Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84* __this, ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 ReadOnly_GetEnumerator_m528906E3EF4A9456E20EF0C13D5EF3BDCCCA68C6 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF7175A19D7496848399699A14F05C3F459EB2A9F (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m771309A3943DD52F356713520E5847B64F5ED776 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mF2ADB2B548C4E7719F88D0ABC14770AE5E4DE14E_inline (ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtility_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m720F581823253EB0096D98EFD58895FE0BB22ADC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m364E1260B5DD21E99ABFA49B3604FCCAA6F85492 (Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70* __this, ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 ReadOnly_GetEnumerator_mE97AA423CE9B9DEC906072E0C7E82BDD9A8AF978 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3FD84C71B90DF8F9C615D1AFCB853FAF46B269DE (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m1979B3B3643C821B2D70FAFD2CFEE610F4BF1E12 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mA00771A913574E450B7709FFE23409830DB02E45_inline (ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA ReadOnly_AsReadOnlySpan_mAE13768A63AEAFD3CE987DFB3475114C49A01A6E (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* ReadOnly_GetUnsafeReadOnlyPtr_m11650CC49E2419A1F3F08A3E0B9770609DA91122_fshared_inline (ReadOnly_t620C834D6C54D781225D753876F232E09821956C* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool ReadOnly_get_IsCreated_m04CC508FD89227103673F7F50C2BE835423CFF2A_fshared_inline (ReadOnly_t620C834D6C54D781225D753876F232E09821956C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m09A002D7239A9B1138F5CBEF78D5C1F13A6E8357 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m42E8E7CFF421EAADEE0DCD1D60FDEAFAA3C63AB2 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* UnsafeUtilityInternal_AsRef_TisIl2CppFullySharedGenericStruct_m4AE204964F54C3F7626BE47CADE4A52CF2797B6B_fshared_inline (void* ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m5228B46F845892F0F239CC9D7314DF4BA90F6DDE (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtilityInternal_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m792E549B89DCE71909B3BCA2EC23DE250E72A16E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtilityInternal_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m75B3FAF2E30DFD3256DD7F68C14C58B209BDD96E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462 (int32_t ___0_internalError, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) ;
inline int32_t RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t*, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD_gshared)(__this, ___0_index, ___1_satelliteRootId, method);
}
inline bool RBTree_1_Successor_mD782B968CE5256E83614B6E8445F37F5F9A9592B (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t*, int32_t*, const RuntimeMethod*))RBTree_1_Successor_mD782B968CE5256E83614B6E8445F37F5F9A9592B_gshared)(__this, ___0_nodeId, ___1_mainTreeNodeId, method);
}
inline Il2CppSharedGenericObject* RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99_gshared)(__this, ___0_nodeId, method);
}
inline bool RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF*, const RuntimeMethod*))RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD_gshared)(__this, method);
}
inline Il2CppSharedGenericObject* RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_inline (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF*, const RuntimeMethod*))RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_gshared_inline)(__this, method);
}
inline RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502 (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502_gshared)(__this, method);
}
inline void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8 (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8_gshared)(__this, method);
}
inline void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955 (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_fshared)(__this, method);
}
inline bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_fshared)(__this, method);
}
inline void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, Il2CppFullySharedGenericAny*, const RuntimeMethod*))RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_fshared_inline)((RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*)__this, il2cppRetVal, method);
}
inline RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_fshared)(__this, method);
}
inline void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470 (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, const RuntimeMethod*))RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method) ;
inline void TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, int32_t, const RuntimeMethod*))TreePage_set_InUseCount_mF6068EC2FA94F4B17098D5C83B965F4703FA033A_fshared_inline)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
inline int32_t TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))TreePage_get_PageId_mB8F6DE559009BD1B1683DD96A132A8AF8229F6C7_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
inline void TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, int32_t, const RuntimeMethod*))TreePage_set_PageId_m106D0788C3D06308F04C6400B1B3D166396CF84D_fshared_inline)(__this, ___0_value, method);
}
inline int32_t TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*, const RuntimeMethod*))TreePage_get_InUseCount_m54A6D752FBFA8E21B9BE911DEFEBB6EBE27F86B4_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) ;
inline int32_t RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56 (uint32_t ___0_bitMap, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint32_t, const RuntimeMethod*))RBTree_1_GetIntValueFromBitMap_m8F0068910A5B84B992C5C54617A5313C2736D58B_fshared)(___0_bitMap, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329 (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method) ;
inline void NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3 (NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method)
{
	((  void (*) (NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50*, int32_t, int32_t, const RuntimeMethod*))NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55_fshared)(__this, ___0_nodeID, ___1_mainTreeNodeID, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Int32_Equals_m089564150E8AF7C63B419427E2E57E3420659B1B (int32_t* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054 (int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8 (String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E (String_t* ___0_paramName, const RuntimeMethod* method) ;
inline int32_t RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D*, const RuntimeMethod*))RBTree_1_get_Count_mEEBAEC4856EDAB96F400E22D1AE495981435BD97_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8 (RuntimeArray* __this, RuntimeObject* ___0_value, int32_t ___1_index, const RuntimeMethod* method) ;
inline void RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, const RuntimeMethod*))RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002_gshared)(__this, method);
}
inline TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	return ((  TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_InUseCount_mFF2D7912FE4FB51AD029F4EA6EB15567F19A425D_inline (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, int32_t, const RuntimeMethod*))TreePage_set_InUseCount_mF6068EC2FA94F4B17098D5C83B965F4703FA033A_fshared_inline)(__this, ___0_value, method);
}
inline void RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, const RuntimeMethod*))RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672_gshared)(__this, ___0_page, method);
}
inline int32_t TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, const RuntimeMethod*))TreePage_get_PageId_mB8F6DE559009BD1B1683DD96A132A8AF8229F6C7_fshared_inline)(__this, method);
}
inline int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, bool ___0_allocatedPage, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, bool, const RuntimeMethod*))RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710_gshared)(__this, ___0_allocatedPage, method);
}
inline void TreePage__ctor_m8441E60D204F8F3B8FBF96726C918F8BFD088BD5 (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, int32_t ___0_size, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, int32_t, const RuntimeMethod*))TreePage__ctor_m8441E60D204F8F3B8FBF96726C918F8BFD088BD5_gshared)(__this, ___0_size, method);
}
inline void TreePage_set_PageId_mFE29414DE74DE5AABA637BC8EE4168D233DC19A7_inline (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, int32_t, const RuntimeMethod*))TreePage_set_PageId_m106D0788C3D06308F04C6400B1B3D166396CF84D_fshared_inline)(__this, ___0_value, method);
}
inline int32_t TreePage_get_InUseCount_mB47BCDDF9F5A3D9F15D5491982B20F7088EA9557_inline (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, const RuntimeMethod*))TreePage_get_InUseCount_m54A6D752FBFA8E21B9BE911DEFEBB6EBE27F86B4_fshared_inline)(__this, method);
}
inline void RBTree_1_FreePage_m02920F187E1C52D2A7E325B08685D3BC171A55F9 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, const RuntimeMethod*))RBTree_1_FreePage_m02920F187E1C52D2A7E325B08685D3BC171A55F9_gshared)(__this, ___0_page, method);
}
inline int32_t RBTree_1_GetIntValueFromBitMap_m2A2C58CFA901D39A02C233D0BF42F3D7EFB44540 (uint32_t ___0_bitMap, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint32_t, const RuntimeMethod*))RBTree_1_GetIntValueFromBitMap_m8F0068910A5B84B992C5C54617A5313C2736D58B_fshared)(___0_bitMap, method);
}
inline int32_t TreePage_AllocSlot_m03CBA01A6EC2A97DA8820AF6BA061837EF01856D (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, const RuntimeMethod* method)
{
	return ((  int32_t (*) (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, const RuntimeMethod*))TreePage_AllocSlot_m03CBA01A6EC2A97DA8820AF6BA061837EF01856D_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62_gshared)(__this, ___0_x_id, method);
}
inline int32_t RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1_gshared)(__this, ___0_nodeId, ___1_rightNodeId, method);
}
inline void RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643_gshared)(__this, ___0_nodeId, ___1_parentNodeId, method);
}
inline void RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565_gshared)(__this, ___0_nodeId, ___1_nextNodeId, method);
}
inline void RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B_gshared)(__this, ___0_nodeId, ___1_key, method);
}
inline void RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3_gshared)(__this, ___0_nodeId, ___1_leftNodeId, method);
}
inline int32_t RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5_gshared)(__this, ___0_nodeId, ___1_size, method);
}
inline void RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNodeID, ___3_position, ___4_append, method);
}
inline int32_t RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, Il2CppSharedGenericObject*, const RuntimeMethod*))RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542_gshared)(__this, ___0_key, method);
}
inline int32_t RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2_gshared)(__this, ___0_nodeId, ___1_color, method);
}
inline int32_t RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline int32_t RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47_gshared)(__this, ___0_root_id, ___1_x_id, ___2_mainTreeNode, method);
}
inline NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method)
{
	return ((  NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, Il2CppSharedGenericObject*, const RuntimeMethod*))RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A_gshared)(__this, ___0_key, method);
}
inline NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_userIndex, const RuntimeMethod* method)
{
	return ((  NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517_gshared)(__this, ___0_userIndex, method);
}
inline int32_t RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97_gshared)(__this, ___0_root_id, ___1_z_id, ___2_mainTreeNodeID, method);
}
inline void RBTree_1_RecomputeSize_mDBB0AAF0158D6FC0172754C8F2BFD25191BC86E8 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_RecomputeSize_mDBB0AAF0158D6FC0172754C8F2BFD25191BC86E8_gshared)(__this, ___0_nodeId, method);
}
inline void RBTree_1_DecreaseSize_m719AA62C29CBC6C387F371FB1D5D1E5C584ABA7B (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_DecreaseSize_m719AA62C29CBC6C387F371FB1D5D1E5C584ABA7B_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_RBDeleteFixup_mF9C058080B3A889E3839D76BEDCFBC6BC0EC02D6 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))RBTree_1_RBDeleteFixup_mF9C058080B3A889E3839D76BEDCFBC6BC0EC02D6_gshared)(__this, ___0_root_id, ___1_x_id, ___2_px_id, ___3_mainTreeNodeID, method);
}
inline void RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	((  void (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D_gshared)(__this, ___0_root_id, ___1_key, method);
}
inline void NodePath__ctor_m1C03760E0A5ADF5BAC0DADDF78FC6C6645F15398 (NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method)
{
	((  void (*) (NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF*, int32_t, int32_t, const RuntimeMethod*))NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55_fshared)(__this, ___0_nodeID, ___1_mainTreeNodeID, method);
}
inline int32_t RBTree_1_GetIndexByNodePath_m1E21B59C97F89684CB754FC49B140B3AFCABA6BD (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF ___0_path, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF, const RuntimeMethod*))RBTree_1_GetIndexByNodePath_m1E21B59C97F89684CB754FC49B140B3AFCABA6BD_gshared)(__this, ___0_path, method);
}
inline int32_t RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4_gshared)(__this, ___0_nodeId, method);
}
inline int32_t RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, int32_t, const RuntimeMethod*))RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455_gshared)(__this, ___0_x_id, ___1_index, method);
}
inline void RBTreeEnumerator__ctor_mFF09CA916CAF9842895161A5CCE9B5F6052358DE (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF*, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, const RuntimeMethod*))RBTreeEnumerator__ctor_mFF09CA916CAF9842895161A5CCE9B5F6052358DE_gshared)(__this, ___0_tree, method);
}
inline int32_t RBTree_1_GetIndexByNode_m46F19C443609B114C90100EE95489B06D7E0DF9E (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_node, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_GetIndexByNode_m46F19C443609B114C90100EE95489B06D7E0DF9E_gshared)(__this, ___0_node, method);
}
inline int32_t RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E_gshared)(__this, ___0_nodeId, ___1_item, method);
}
inline int32_t RBTree_1_InsertAt_mA323D5F4BBB074C3BB0A5AA90C195952F45836D0 (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_position, Il2CppSharedGenericObject* ___1_item, bool ___2_append, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, Il2CppSharedGenericObject*, bool, const RuntimeMethod*))RBTree_1_InsertAt_mA323D5F4BBB074C3BB0A5AA90C195952F45836D0_gshared)(__this, ___0_position, ___1_item, ___2_append, method);
}
inline Il2CppSharedGenericObject* RBTree_1_DeleteByIndex_m66215488DD926BD6C06D66BC1DEC77A2E4AFA36F (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_i, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, int32_t, const RuntimeMethod*))RBTree_1_DeleteByIndex_m66215488DD926BD6C06D66BC1DEC77A2E4AFA36F_gshared)(__this, ___0_i, method);
}
inline int32_t RBTree_1_get_Count_mCCC9A110FA3CFC5542CD9056AE20466F86C2F39F (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81*, const RuntimeMethod*))RBTree_1_get_Count_mEEBAEC4856EDAB96F400E22D1AE495981435BD97_fshared)(__this, method);
}
inline void NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55 (NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813* __this, int32_t ___0_nodeID, int32_t ___1_mainTreeNodeID, const RuntimeMethod* method)
{
	((  void (*) (NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813*, int32_t, int32_t, const RuntimeMethod*))NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55_fshared)(__this, ___0_nodeID, ___1_mainTreeNodeID, method);
}
inline void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method)
{
	((  void (*) (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_fshared)(__this, ___0_tree, method);
}
inline int32_t RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m84FE82568F9EC0F33E541BAFB8DBD19DEC020514 (RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_sum, int32_t ___1_i, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* IL2CPP_PARAMETER_RESTRICT, int32_t, int32_t, const RuntimeMethod*))RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m3F8F577B4377811997803EDFF4C6D9A87EC74B72_fshared)(__this, ___0_sum, ___1_i, method);
}
inline int32_t RadixSortBatchPrefixSumJob_1_AtomicIncrement_m4176AE255919577013BEEA632E809CBB40F3B62F (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___0_counter, const RuntimeMethod* method)
{
	return ((  int32_t (*) (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C, const RuntimeMethod*))RadixSortBatchPrefixSumJob_1_AtomicIncrement_m8EC5C7D3F99DC23EACE0C397BDF89AF029A717B0_fshared)(___0_counter, method);
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_mA78B963B3F0E2BB984306D5941DB9E622B31192A (RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline int32_t RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_mCCD76D6B3B104F205739A21AE7FD43F594488F1F (RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_sum, int32_t ___1_i, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* IL2CPP_PARAMETER_RESTRICT, int32_t, int32_t, const RuntimeMethod*))RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m3F8F577B4377811997803EDFF4C6D9A87EC74B72_fshared)(__this, ___0_sum, ___1_i, method);
}
inline int32_t RadixSortBatchPrefixSumJob_1_AtomicIncrement_mE5B6D6C23E3A09431E1528BA8084A165B13D9A98 (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___0_counter, const RuntimeMethod* method)
{
	return ((  int32_t (*) (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C, const RuntimeMethod*))RadixSortBatchPrefixSumJob_1_AtomicIncrement_m8EC5C7D3F99DC23EACE0C397BDF89AF029A717B0_fshared)(___0_counter, method);
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_m71DF9A259A4A7F5463EB48D94570811F2FC1D649 (RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafePtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD2D9DC546B80A05000B107C8E09FAA4BED3B2144_inline (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafePtr_TisIl2CppFullySharedGenericStruct_m4AB802D5B1B296D0F976C1E7631699B0C4A4D00F_fshared_inline)(___0_nativeArray, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t* UnsafeUtility_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mF01FDF0EACCFED286E93933B693A2BE11A6A8946_inline (void* ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309 (int32_t* ___0_location, const RuntimeMethod* method) ;
inline void RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25 (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT, int32_t, const RuntimeMethod*))RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25_fshared)(__this, ___0_index, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06F913AC64211C19A5F35EB50F3F45685095D3D1 (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725 (int32_t ___0_value, int32_t ___1_radix, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mF718C58AF6A48CF95C20FFFAAD3B3870884C4619 (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01 (uint64_t ___0_value, int32_t ___1_radix, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_mE69747B2B60DA38802FCF96889C1CD7DDC1E3726 (RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6AA2337D311BABD06E7416B028FD039D11211F9A (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m3DFE0C9BE1F74820586102B27F73A072206D136C (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* __this, int32_t ___0_expectedTypeSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_m9860F3A459E28F8FF1880B9974294C3E35614701 (RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline void RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328 (RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93* IL2CPP_PARAMETER_RESTRICT, int32_t, const RuntimeMethod*))RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328_fshared)(__this, ___0_index, method);
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m824CF9A6053A2A13ACEB6D4E533B964B9D04DB1A (RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m3A6F0C47238FA5FD88CF5EA0E24E26202F539F73 (RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline void RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7 (RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D* IL2CPP_PARAMETER_RESTRICT, int32_t, const RuntimeMethod*))RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7_fshared)(__this, ___0_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float math_max_mC2D5D2F0EB91D3A908AE964BE8BF5EA443C3BF64_inline (float ___0_x, float ___1_y, const RuntimeMethod* method) ;
inline void Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, int32_t ___0_start, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, int32_t, int32_t, const RuntimeMethod*))Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D_fshared)(__this, ___0_start, ___1_count, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m6C8D51A9406D6ED9B43B6F126A83EF286FB5DFB3_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, const RuntimeMethod* method) ;
inline int32_t List_1_get_Capacity_m7237746FBC070DD77B7BBE2013FB35CA4F7182E9 (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6*, const RuntimeMethod*))List_1_get_Capacity_m5BE6D733C76E1AB093FB6D2783220A5B96EF61DF_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9 (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float SplineMath_DistancePointLine_m11F12FCA6C85B91C0C59F671E09DEAC31F7FFA4F (float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_p, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___1_a, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___2_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueTuple_2__ctor_m8AD4450A363A5626EE8665BFDFA6B773D05EE581 (ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69* __this, int32_t ___0_item1, float ___1_item2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
inline String_t* Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E_fshared)(__this, method);
}
inline HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5* DynamicArray_1_get_Item_mDDF17FFCC776B434F220412BAEB139F2350600FA (DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5* (*) (DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE*, int32_t, const RuntimeMethod*))DynamicArray_1_get_Item_mDDF17FFCC776B434F220412BAEB139F2350600FA_gshared)(__this, ___0_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar* DynamicArray_1_get_Item_mDFF72C07A8872B82B343DBC3B7A134FDED83E74B (DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* DynamicArray_1_get_Item_m5AC8E2913D8C0BE441403585083972B6AD1A49C6 (DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354* DynamicArray_1_get_Item_mEF92855A23D9A2995786E5910FD3425F749EB5C0 (DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68* DynamicArray_1_get_Item_m24D831579B1FD904DCCA4EE983EBD0F19E7E96D5 (DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214* DynamicArray_1_get_Item_m67A96A4CCBC69D31ADE62E5D36A9221CC7E4CAEA (DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0* __this, int32_t ___0_index, const RuntimeMethod* method) ;
inline Il2CppSharedGenericObject** DynamicArray_1_get_Item_mA2D6D01C2851B649C10AAB4D7F0EB01F2E0596EE (DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject** (*) (DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D*, int32_t, const RuntimeMethod*))DynamicArray_1_get_Item_mA2D6D01C2851B649C10AAB4D7F0EB01F2E0596EE_gshared)(__this, ___0_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RasterGraphContext_FromInternalContext_m2FE156B0C44906E824BBBE5E69F7CA4EF840BCAE (RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147* __this, InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* ___0_context, const RuntimeMethod* method) ;
inline void BaseRenderFunc_2_Invoke_m74AE14F084437149C944CF85887E55871ACC81D8_inline (BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887* __this, Il2CppSharedGenericObject* ___0_data, RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 ___1_renderGraphContext, const RuntimeMethod* method)
{
	((  void (*) (BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887*, Il2CppSharedGenericObject*, RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147, const RuntimeMethod*))BaseRenderFunc_2_Invoke_m74AE14F084437149C944CF85887E55871ACC81D8_gshared_inline)(__this, ___0_data, ___1_renderGraphContext, method);
}
inline void BaseRenderGraphPass_2_Release_m71C367F7732998859F6B2A4C2168D31BD2922A77_inline (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0* __this, RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* ___0_pool, const RuntimeMethod* method)
{
	((  void (*) (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*, RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437*, const RuntimeMethod*))BaseRenderGraphPass_2_Release_m71C367F7732998859F6B2A4C2168D31BD2922A77_gshared_inline)(__this, ___0_pool, method);
}
inline void RenderGraphObjectPool_Release_TisRasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5_mD5CB3750BC13540EB409FFFA3DF8D99254ACBEE3 (RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* __this, RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437*, RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5*, const RuntimeMethod*))RenderGraphObjectPool_Release_TisIl2CppSharedGenericObject_m41E89F411886EB72C412391048C5DFBB4BF6BFFC_gshared)(__this, ___0_value, method);
}
inline void BaseRenderGraphPass_2__ctor_mCDC1A0CF9B5800412AE9084F7EC4F02640701623 (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0* __this, const RuntimeMethod* method)
{
	((  void (*) (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*, const RuntimeMethod*))BaseRenderGraphPass_2__ctor_mDB087533ED27EE1E23108F904FD875B485316D27_fshared)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtility_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m79879C1B15242483D8C9C1E532366BB74B6B9526_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m3A87BBB2A08731ABFE824690AC9B5CCEA26C3230 (Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84* __this, ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 ReadOnly_GetEnumerator_m528906E3EF4A9456E20EF0C13D5EF3BDCCCA68C6 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF7175A19D7496848399699A14F05C3F459EB2A9F (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m771309A3943DD52F356713520E5847B64F5ED776 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mF2ADB2B548C4E7719F88D0ABC14770AE5E4DE14E_inline (ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtility_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m720F581823253EB0096D98EFD58895FE0BB22ADC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m364E1260B5DD21E99ABFA49B3604FCCAA6F85492 (Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70* __this, ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 ReadOnly_GetEnumerator_mE97AA423CE9B9DEC906072E0C7E82BDD9A8AF978 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3FD84C71B90DF8F9C615D1AFCB853FAF46B269DE (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m1979B3B3643C821B2D70FAFD2CFEE610F4BF1E12 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mA00771A913574E450B7709FFE23409830DB02E45_inline (ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA ReadOnly_AsReadOnlySpan_mAE13768A63AEAFD3CE987DFB3475114C49A01A6E (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
inline NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* ReadOnly_GetUnsafeReadOnlyPtr_m176DCA161E95AE15D5E0339254D38B095BFFD2B2_inline (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method)
{
	return ((  NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* (*) (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD*, const RuntimeMethod*))ReadOnly_GetUnsafeReadOnlyPtr_m11650CC49E2419A1F3F08A3E0B9770609DA91122_fshared_inline)(__this, method);
}
inline bool ReadOnly_get_IsCreated_m4D7E01A569059DE28E8184D5013A248982A9A43B_inline (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD*, const RuntimeMethod*))ReadOnly_get_IsCreated_m04CC508FD89227103673F7F50C2BE835423CFF2A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m09A002D7239A9B1138F5CBEF78D5C1F13A6E8357 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m42E8E7CFF421EAADEE0DCD1D60FDEAFAA3C63AB2 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Single_IsNaN_mFE637F6ECA9F7697CE8EFF56427858F4C5EDF75D_inline (float ___0_f, const RuntimeMethod* method) ;
inline int32_t* UnsafeUtilityInternal_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m77E9B9B716D93AB00C90A84F70C3C6CE55E4A342_inline (void* ___0_ptr, const RuntimeMethod* method)
{
	return ((  int32_t* (*) (void*, const RuntimeMethod*))UnsafeUtilityInternal_AsRef_TisIl2CppFullySharedGenericStruct_m4AE204964F54C3F7626BE47CADE4A52CF2797B6B_fshared_inline)(___0_ptr, method);
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m5228B46F845892F0F239CC9D7314DF4BA90F6DDE (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_item, const RuntimeMethod* method) ;
inline void RenderGraphObjectPool_Release_TisIl2CppSharedGenericObject_m41E89F411886EB72C412391048C5DFBB4BF6BFFC (RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437*, Il2CppSharedGenericObject*, const RuntimeMethod*))RenderGraphObjectPool_Release_TisIl2CppSharedGenericObject_m41E89F411886EB72C412391048C5DFBB4BF6BFFC_gshared)(__this, ___0_value, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtilityInternal_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m792E549B89DCE71909B3BCA2EC23DE250E72A16E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56 (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtilityInternal_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m75B3FAF2E30DFD3256DD7F68C14C58B209BDD96E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t BitConverter_SingleToInt32Bits_mC760C7CFC89725E3CF68DC45BE3A9A42A7E7DA73_inline (float ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60813
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		__this->____mainTreeNodeId = L_4;
		int32_t* L_5 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_5, sizeof(int32_t));
		return;
	}
}
// Method Definition Index: 60814
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m464484068CE1D76DCBFD781DDD4C8D310620B4DA (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		int32_t* L_8 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_6);
		int32_t L_9;
		L_9 = RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), L_8, NULL);
		__this->____index = L_9;
		int32_t L_10 = __this->____index;
		if (L_10)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_11;
		L_11 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0050:
	{
		int32_t* L_12 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_12, sizeof(int32_t));
		return;
	}
}
// Method Definition Index: 60815
// Method Definition Index: 60816
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = __this->____tree;
		int32_t* L_5 = (int32_t*)(&__this->____index);
		int32_t* L_6 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_4);
		bool L_7;
		L_7 = RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE(L_4, L_5, L_6, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_8 = __this->____tree;
		int32_t L_9 = __this->____index;
		NullCheck(L_8);
		int32_t L_10;
		L_10 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(L_8, L_9, NULL);
		__this->____current = L_10;
		return L_7;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115>(__this);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_mB00AE8BACE08D31B8BBB6420BC48380D35B58173(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60817
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115>(__this);
	int32_t _returnValue;
	_returnValue = RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60818
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline(__this, NULL);
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5), &L_1);
		return L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115>(__this);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_m51A6150BF88CB14DDE97B1EF33342869AEA55F6C(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60819
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4 (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		__this->____index = 0;
		RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* L_4 = __this->____tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		int32_t* L_6 = (int32_t*)(&__this->____current);
		il2cpp_codegen_initobj(L_6, sizeof(int32_t));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115>(__this);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m6EE5A4DE7A3C8DE01E59B4FACEE2DFD7F3FC45F4(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60813
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_mFF09CA916CAF9842895161A5CCE9B5F6052358DE_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		__this->____index = 0;
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		__this->____mainTreeNodeId = L_4;
		Il2CppSharedGenericObject** L_5 = (Il2CppSharedGenericObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_5, sizeof(Il2CppSharedGenericObject*));
		return;
	}
}
// Method Definition Index: 60814
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m69CBDF7BBB263D821E7F9F3F706D08BD240309BD_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_0 = ___0_tree;
		__this->____tree = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____tree), (void*)L_0);
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		__this->____version = L_2;
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		__this->____index = 0;
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		int32_t* L_8 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_6);
		int32_t L_9;
		L_9 = RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), L_8, NULL);
		__this->____index = L_9;
		int32_t L_10 = __this->____index;
		if (L_10)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_11;
		L_11 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, method);
	}

IL_0050:
	{
		Il2CppSharedGenericObject** L_12 = (Il2CppSharedGenericObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_12, sizeof(Il2CppSharedGenericObject*));
		return;
	}
}
// Method Definition Index: 60815
// Method Definition Index: 60816
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_4 = __this->____tree;
		int32_t* L_5 = (int32_t*)(&__this->____index);
		int32_t* L_6 = (int32_t*)(&__this->____mainTreeNodeId);
		NullCheck(L_4);
		bool L_7;
		L_7 = RBTree_1_Successor_mD782B968CE5256E83614B6E8445F37F5F9A9592B(L_4, L_5, L_6, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_8 = __this->____tree;
		int32_t L_9 = __this->____index;
		NullCheck(L_8);
		Il2CppSharedGenericObject* L_10;
		L_10 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(L_8, L_9, NULL);
		__this->____current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____current), (void*)L_10);
		return L_7;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF>(__this);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_m81963E6532BC9A9B8B168732E868E47314C7B1AD(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60817
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_EXTERN_C  Il2CppSharedGenericObject* RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF>(__this);
	Il2CppSharedGenericObject* _returnValue;
	_returnValue = RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60818
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0;
		L_0 = RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_inline(__this, NULL);
		return (RuntimeObject*)L_0;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF>(__this);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mBAE1BA5BCC8CB428F7A30CA8F4F6B461F335E502(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60819
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8_gshared (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____version;
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_1 = __this->____tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		__this->____index = 0;
		RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* L_4 = __this->____tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		__this->____mainTreeNodeId = L_5;
		Il2CppSharedGenericObject** L_6 = (Il2CppSharedGenericObject**)(&__this->____current);
		il2cpp_codegen_initobj(L_6, sizeof(Il2CppSharedGenericObject*));
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF>(__this);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m735ED42F433ED59EB4B5B59651A8EDE7FCDD3AB8(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60813
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	//<source_info:<no-source>:1>
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_0 = ___0_tree;
		il2cpp_codegen_write_field_data<RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),0), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), L_0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),1), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_2);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),2), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_3 = ___0_tree;
		NullCheck(L_3);
		int32_t L_4 = L_3->___root;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),3), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4), L_4);
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
// Method Definition Index: 60814
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator__ctor_mC7027B6747A32BD6A978E0DA6DE74FA6DB6AEA5C_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* ___0_tree, int32_t ___1_position, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	//<source_info:<no-source>:1>
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_0 = ___0_tree;
		il2cpp_codegen_write_field_data<RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),0), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), L_0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = ___0_tree;
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),1), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_2);
		int32_t L_3 = ___1_position;
		if (L_3)
		{
			goto IL_002b;
		}
	}
	{
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),2), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = ___0_tree;
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),3), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4), L_5);
		goto IL_0050;
	}

IL_002b:
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_6 = ___0_tree;
		int32_t L_7 = ___1_position;
		NullCheck(L_6);
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)))(L_6, ((int32_t)il2cpp_codegen_subtract(L_7, 1)), (((int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7));
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),2), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3), L_8);
		int32_t L_9 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if (L_9)
		{
			goto IL_0050;
		}
	}
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0050:
	{
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
// Method Definition Index: 60815
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4>(__this);
	RBTreeEnumerator_Dispose_m44368C76E9C0F3A17DB3342C808CA8F9582C5955(_thisAdjusted, method);
}
// Method Definition Index: 60816
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		NullCheck(L_4);
		bool L_5;
		L_5 = ((  bool (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t*, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8)))(L_4, (((int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))), (((int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_6 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		int32_t L_7 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		NullCheck(L_6);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9), L_6, L_7, (Il2CppFullySharedGenericAny*)L_8);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),4), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), L_8, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return L_5;
	}
}
IL2CPP_EXTERN_C  bool RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4>(__this);
	bool _returnValue;
	_returnValue = RBTreeEnumerator_MoveNext_mB5562C7DBD432B39AC6CDE17139006D3141A2E7E(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60817
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4>(__this);
	RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_inline(_thisAdjusted, il2cppRetVal, method);
	return;
}
// Method Definition Index: 60818
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	//<source_info:<no-source>:1>
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10), __this, (Il2CppFullySharedGenericAny*)L_0);
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5), L_0);
		return L_1;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4>(__this);
	RuntimeObject* _returnValue;
	_returnValue = RBTreeEnumerator_System_Collections_IEnumerator_get_Current_mD023E34D3906399CCC1A8E8AB645C5C9810898FB(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 60819
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_fshared (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_1 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		NullCheck(L_1);
		int32_t L_2 = L_1->____version;
		if ((((int32_t)L_0) == ((int32_t)L_2)))
		{
			goto IL_0019;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_EnumeratorModified_m8343A0E4D50C5143F6A15F0D562AB7838A3A96D1(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_0019:
	{
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),2), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3), 0);
		RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* L_4 = *(RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		NullCheck(L_4);
		int32_t L_5 = L_4->___root;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0),3), il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4), L_5);
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)))), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
IL2CPP_EXTERN_C  void RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4>(__this);
	RBTreeEnumerator_System_Collections_IEnumerator_Reset_m30C1ACC2356659BDDEC767619AA0D8B5EA06E470(_thisAdjusted, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60745
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1__ctor_m94D0C9F06C7211AEA1E7596028FE173C1C787497 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_accessMethod, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_accessMethod;
		__this->____accessMethod = L_0;
		RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
// Method Definition Index: 60746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		__this->___root = 0;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = (TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)(TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)32));
		__this->____pageTable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_0);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_1 = __this->____pageTable;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_2, ((int32_t)32))), 1))/((int32_t)32))));
		__this->____pageTableMap = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_3);
		__this->____inUsePageCount = 0;
		__this->____nextFreePageLine = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_4;
		L_4 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_5 = __this->____pageTable;
		NullCheck(L_5);
		int32_t L_6 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(L_7);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_8 = L_7->____slots;
		NullCheck(L_8);
		((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->____nodeColor = 1;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_9 = __this->____pageTable;
		NullCheck(L_9);
		int32_t L_10 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_11 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		NullCheck(L_11);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = L_11->____slotMap;
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(0), (int32_t)1);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_13 = __this->____pageTable;
		NullCheck(L_13);
		int32_t L_14 = 0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_15 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline(L_15, 1, NULL);
		__this->____inUseNodeCount = 1;
		__this->____inUseSatelliteTreeCount = 0;
		return;
	}
}
// Method Definition Index: 60747
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_0 = ___0_page;
		RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB(__this, L_0, NULL);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_1 = __this->____pageTable;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_2 = ___0_page;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_2, NULL);
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, NULL);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)NULL);
		int32_t L_4 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		return;
	}
}
// Method Definition Index: 60748
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_0029;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_2 = __this->____pageTable;
		int32_t L_3 = V_0;
		int32_t L_4 = ___0_size;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83(L_5, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)L_5);
		int32_t L_6 = V_0;
		__this->____nextFreePageLine = ((int32_t)(L_6/((int32_t)32)));
		goto IL_00a9;
	}

IL_0029:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_7 = __this->____pageTable;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_9 = (TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)(TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)il2cpp_codegen_multiply(L_8, 2)));
		V_1 = L_9;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_10 = __this->____pageTable;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_11 = V_1;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_12 = __this->____pageTable;
		NullCheck(L_12);
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_12)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, 0, (RuntimeArray*)L_11, 0, L_13, NULL);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_14 = V_1;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_15, ((int32_t)32))), 1))/((int32_t)32))));
		V_2 = L_16;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = __this->____pageTableMap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_19 = __this->____pageTableMap;
		NullCheck(L_19);
		int32_t L_20 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_19)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_17, 0, (RuntimeArray*)L_18, 0, L_20, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_21 = __this->____pageTableMap;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		__this->____nextFreePageLine = L_22;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_23 = __this->____pageTable;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		V_0 = L_24;
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_25 = V_1;
		__this->____pageTable = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_25);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_26 = V_2;
		__this->____pageTableMap = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_26);
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_27 = __this->____pageTable;
		int32_t L_28 = V_0;
		int32_t L_29 = ___0_size;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_30 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		TreePage__ctor_m44F8EC22FAAB8146AC4E2D6E299F6A122DE40C83(L_30, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)L_30);
	}

IL_00a9:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_31 = __this->____pageTable;
		int32_t L_32 = V_0;
		NullCheck(L_31);
		int32_t L_33 = L_32;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_34 = (L_31)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		int32_t L_35 = V_0;
		NullCheck(L_34);
		TreePage_set_PageId_m60FCE18172BAC6C1B1479026018D6422F2B30A70_inline(L_34, L_35, NULL);
		int32_t L_36 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_add(L_36, 1));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_37 = __this->____pageTable;
		int32_t L_38 = V_0;
		NullCheck(L_37);
		int32_t L_39 = L_38;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_40 = (L_37)->GetAt(static_cast<il2cpp_array_size_t>(L_39));
		return L_40;
	}
}
// Method Definition Index: 60749
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFull_mC50FFD42DDEC1D8C70AB4B76EA8E765F43D1A138 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_5, NULL);
		*(L_3) = ((int32_t)(L_4|((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))));
		return;
	}
}
// Method Definition Index: 60750
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_5, NULL);
		*(L_3) = ((int32_t)(L_4&((~((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))))));
		return;
	}
}
// Method Definition Index: 60751
// Method Definition Index: 60752
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		V_0 = L_3;
		int32_t L_4 = ___0_nodeId;
		V_1 = ((int32_t)(L_4&((int32_t)65535)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = V_0;
		NullCheck(L_5);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_6 = L_5->____slots;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		il2cpp_codegen_initobj(((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7))), sizeof(Node_tA8F7ED85FD786FE388B1ED3CF8DDFEDC56587258));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_8 = V_0;
		NullCheck(L_8);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = L_8->____slotMap;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		int32_t* L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_10/((int32_t)32))))));
		int32_t L_12 = *(L_11);
		int32_t L_13 = V_1;
		*(L_11) = ((int32_t)(L_12&((~((int32_t)(1<<((int32_t)(((int32_t)(L_13%((int32_t)32)))&((int32_t)31)))))))));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_14 = V_0;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_15 = L_14;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_15, NULL);
		V_2 = L_16;
		int32_t L_17 = V_2;
		NullCheck(L_15);
		TreePage_set_InUseCount_m8FA6467AC39561006A23E87B162BA73D585BADDA_inline(L_15, ((int32_t)il2cpp_codegen_subtract(L_17, 1)), NULL);
		int32_t L_18 = __this->____inUseNodeCount;
		__this->____inUseNodeCount = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_19 = V_0;
		NullCheck(L_19);
		int32_t L_20;
		L_20 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_19, NULL);
		if (L_20)
		{
			goto IL_0071;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_21 = V_0;
		RBTree_1_FreePage_m428135A97F5257D955C88324EEC40540887A061C(__this, L_21, NULL);
		return;
	}

IL_0071:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23;
		L_23 = TreePage_get_InUseCount_mEA19EFEDD63621D601EFFFE57C3D3297FC357EA4_inline(L_22, NULL);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = V_0;
		NullCheck(L_24);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_25 = L_24->____slots;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((!(((uint32_t)L_23) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_26, 1))))))
		{
			goto IL_008a;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_27 = V_0;
		RBTree_1_MarkPageFree_mDFB2F31CD9B41FEAC6E15E8798687212440448EB(__this, L_27, NULL);
	}

IL_008a:
	{
		return;
	}
}
// Method Definition Index: 60753
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, bool ___0_allocatedPage, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	uint32_t V_3 = 0;
	{
		int32_t L_0 = __this->____nextFreePageLine;
		V_0 = L_0;
		V_1 = (-1);
		goto IL_0073;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____pageTableMap;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if ((!(((uint32_t)L_4) < ((uint32_t)(-1)))))
		{
			goto IL_006f;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____pageTableMap;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_2 = L_8;
		goto IL_006a;
	}

IL_0021:
	{
		uint32_t L_9 = V_2;
		uint32_t L_10 = V_2;
		V_3 = ((int32_t)(((~((int32_t)L_9)))&((int32_t)il2cpp_codegen_add((int32_t)L_10, 1))));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____pageTableMap;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		uint32_t L_16 = V_3;
		uint64_t L_17 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_16,NULL));
		if (!((int64_t)(L_15&(int64_t)L_17)))
		{
			goto IL_003d;
		}
	}
	{
		Exception_t* L_18;
		L_18 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(3, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_18, method);
	}

IL_003d:
	{
		int32_t L_19 = V_0;
		uint32_t L_20 = V_3;
		int32_t L_21;
		L_21 = RBTree_1_GetIntValueFromBitMap_m48B51C8E9FEE3BC3018EEABB1B7171C27550AF56(L_20, NULL);
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_19, ((int32_t)32))), L_21));
		bool L_22 = ___0_allocatedPage;
		if (!L_22)
		{
			goto IL_0058;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_23 = __this->____pageTable;
		int32_t L_24 = V_1;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		if (!L_26)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_27 = V_1;
		return L_27;
	}

IL_0058:
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_28 = __this->____pageTable;
		int32_t L_29 = V_1;
		NullCheck(L_28);
		int32_t L_30 = L_29;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_31 = (L_28)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		if (L_31)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_32 = V_1;
		return L_32;
	}

IL_0064:
	{
		V_1 = (-1);
		uint32_t L_33 = V_2;
		uint32_t L_34 = V_3;
		V_2 = ((int32_t)((int32_t)L_33|(int32_t)L_34));
	}

IL_006a:
	{
		uint32_t L_35 = V_2;
		if (((int32_t)((int32_t)L_35^(-1))))
		{
			goto IL_0021;
		}
	}

IL_006f:
	{
		int32_t L_36 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_0073:
	{
		int32_t L_37 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_38 = __this->____pageTableMap;
		NullCheck(L_38);
		int32_t L_39 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_38)->max_length),NULL));
		if ((((int32_t)L_37) < ((int32_t)L_39)))
		{
			goto IL_000b;
		}
	}
	{
		int32_t L_40 = __this->____nextFreePageLine;
		if (!L_40)
		{
			goto IL_0095;
		}
	}
	{
		__this->____nextFreePageLine = 0;
		bool L_41 = ___0_allocatedPage;
		int32_t L_42;
		L_42 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, L_41, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_42;
	}

IL_0095:
	{
		int32_t L_43 = V_1;
		return L_43;
	}
}
// Method Definition Index: 60754
// Method Definition Index: 60755
// Method Definition Index: 60756
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = (TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7*)NULL;
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m44B83E5017AC18424A1CABBB5B69F4334BCACABA(__this, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_0;
		int32_t L_1 = V_1;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001c;
		}
	}
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_2 = __this->____pageTable;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_0 = L_5;
		goto IL_00a5;
	}

IL_001c:
	{
		int32_t L_6 = __this->____inUsePageCount;
		if ((((int32_t)L_6) >= ((int32_t)4)))
		{
			goto IL_0030;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_7;
		L_7 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_7;
		goto IL_00a5;
	}

IL_0030:
	{
		int32_t L_8 = __this->____inUsePageCount;
		if ((((int32_t)L_8) >= ((int32_t)((int32_t)32))))
		{
			goto IL_0048;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_9;
		L_9 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)256), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_9;
		goto IL_00a5;
	}

IL_0048:
	{
		int32_t L_10 = __this->____inUsePageCount;
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)128))))
		{
			goto IL_0063;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_11;
		L_11 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)1024), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_11;
		goto IL_00a5;
	}

IL_0063:
	{
		int32_t L_12 = __this->____inUsePageCount;
		if ((((int32_t)L_12) >= ((int32_t)((int32_t)4096))))
		{
			goto IL_007e;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_13;
		L_13 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)4096), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_13;
		goto IL_00a5;
	}

IL_007e:
	{
		int32_t L_14 = __this->____inUsePageCount;
		if ((((int32_t)L_14) >= ((int32_t)((int32_t)32768))))
		{
			goto IL_0099;
		}
	}
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_15;
		L_15 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)8192), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_15;
		goto IL_00a5;
	}

IL_0099:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_16;
		L_16 = RBTree_1_AllocPage_mB813A6A6F957374D0852A5861110677BBCA3A7BA(__this, ((int32_t)65536), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_16;
	}

IL_00a5:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18;
		L_18 = TreePage_AllocSlot_m98CE7C69F3225831EDC1F758AC133AFDBD631329(L_17, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		V_2 = L_18;
		int32_t L_19 = V_2;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_00b8;
		}
	}
	{
		Exception_t* L_20;
		L_20 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_00b8:
	{
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_21 = V_0;
		NullCheck(L_21);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_22 = L_21->____slots;
		int32_t L_23 = V_2;
		NullCheck(L_22);
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_24 = V_0;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = TreePage_get_PageId_m67122D79A6E353A965823DA629B96D3A79552519_inline(L_24, NULL);
		int32_t L_26 = V_2;
		((L_22)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_23)))->____selfId = ((int32_t)(((int32_t)(L_25<<((int32_t)16)))|L_26));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_27 = V_0;
		NullCheck(L_27);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_28 = L_27->____slots;
		int32_t L_29 = V_2;
		NullCheck(L_28);
		((L_28)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_29)))->____subTreeSize = 1;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_30 = V_0;
		NullCheck(L_30);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_31 = L_30->____slots;
		int32_t L_32 = V_2;
		NullCheck(L_31);
		int32_t L_33 = ___0_key;
		((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode = L_33;
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_34 = V_0;
		NullCheck(L_34);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_35 = L_34->____slots;
		int32_t L_36 = V_2;
		NullCheck(L_35);
		int32_t L_37 = ((L_35)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_36)))->____selfId;
		return L_37;
	}
}
// Method Definition Index: 60757
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_2, NULL);
		int32_t L_4;
		L_4 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_3, NULL);
		return L_4;
	}

IL_0017:
	{
		int32_t L_5 = ___0_x_id;
		int32_t L_6;
		L_6 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_5, NULL);
		V_0 = L_6;
		goto IL_002c;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		___0_x_id = L_7;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_8, NULL);
		V_0 = L_9;
	}

IL_002c:
	{
		int32_t L_10 = V_0;
		if (!L_10)
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_11 = ___0_x_id;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_12, NULL);
		if ((((int32_t)L_11) == ((int32_t)L_13)))
		{
			goto IL_0021;
		}
	}

IL_0039:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60758
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mBE6CC011CC22FE54A564CB8AE8247BC43146D3EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___0_nodeId;
		int32_t L_1 = *(L_0);
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t* L_2 = ___0_nodeId;
		int32_t* L_3 = ___1_mainTreeNodeId;
		int32_t L_4 = *(L_3);
		int32_t L_5;
		L_5 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_4, NULL);
		*(L_2) = L_5;
		int32_t* L_6 = ___1_mainTreeNodeId;
		*(L_6) = 0;
		goto IL_0032;
	}

IL_0013:
	{
		int32_t* L_7 = ___0_nodeId;
		int32_t* L_8 = ___0_nodeId;
		int32_t L_9 = *(L_8);
		int32_t L_10;
		L_10 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_9, NULL);
		*(L_7) = L_10;
		int32_t* L_11 = ___0_nodeId;
		int32_t L_12 = *(L_11);
		if (L_12)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_13 = ___1_mainTreeNodeId;
		int32_t L_14 = *(L_13);
		if (!L_14)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_15 = ___0_nodeId;
		int32_t* L_16 = ___1_mainTreeNodeId;
		int32_t L_17 = *(L_16);
		int32_t L_18;
		L_18 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_17, NULL);
		*(L_15) = L_18;
		int32_t* L_19 = ___1_mainTreeNodeId;
		*(L_19) = 0;
	}

IL_0032:
	{
		int32_t* L_20 = ___0_nodeId;
		int32_t L_21 = *(L_20);
		if (!L_21)
		{
			goto IL_0062;
		}
	}
	{
		int32_t* L_22 = ___0_nodeId;
		int32_t L_23 = *(L_22);
		int32_t L_24;
		L_24 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_23, NULL);
		if (!L_24)
		{
			goto IL_0060;
		}
	}
	{
		int32_t* L_25 = ___1_mainTreeNodeId;
		int32_t L_26 = *(L_25);
		if (!L_26)
		{
			goto IL_004c;
		}
	}
	{
		Exception_t* L_27;
		L_27 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)21), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_27, method);
	}

IL_004c:
	{
		int32_t* L_28 = ___1_mainTreeNodeId;
		int32_t* L_29 = ___0_nodeId;
		int32_t L_30 = *(L_29);
		*(L_28) = L_30;
		int32_t* L_31 = ___0_nodeId;
		int32_t* L_32 = ___0_nodeId;
		int32_t L_33 = *(L_32);
		int32_t L_34;
		L_34 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_33, NULL);
		int32_t L_35;
		L_35 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_34, NULL);
		*(L_31) = L_35;
	}

IL_0060:
	{
		return (bool)1;
	}

IL_0062:
	{
		return (bool)0;
	}
}
// Method Definition Index: 60759
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000b;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		___0_x_id = L_1;
	}

IL_000b:
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_2, NULL);
		if (L_3)
		{
			goto IL_0002;
		}
	}
	{
		int32_t L_4 = ___0_x_id;
		return L_4;
	}
}
// Method Definition Index: 60760
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_3, NULL);
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_2, L_4, NULL);
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_7, NULL);
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_8, L_9, NULL);
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, NULL);
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_10, L_12, NULL);
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_13, NULL);
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_17, L_18, NULL);
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_20, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_19, L_21, NULL);
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_24, NULL);
		int32_t L_26;
		L_26 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_25, NULL);
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, NULL);
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_28, L_29, NULL);
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_30, NULL);
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_31, L_32, NULL);
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_33, L_34, NULL);
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_35, L_36, NULL);
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_39, NULL);
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_40, NULL);
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_43, NULL);
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_45, NULL);
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_47, NULL);
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_48, NULL);
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), NULL);
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_52, NULL);
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_53, NULL);
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_55, NULL);
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_56, NULL);
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_58, NULL);
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_60, NULL);
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_61, NULL);
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), NULL);
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60761
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_3, NULL);
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_2, L_4, NULL);
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_7, NULL);
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_8, L_9, NULL);
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, NULL);
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_10, L_12, NULL);
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_13, NULL);
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_17, L_18, NULL);
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_20, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_19, L_21, NULL);
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_24, NULL);
		int32_t L_26;
		L_26 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_25, NULL);
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, NULL);
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_28, L_29, NULL);
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_30, NULL);
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_31, L_32, NULL);
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_33, L_34, NULL);
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_35, L_36, NULL);
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_39, NULL);
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_40, NULL);
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_43, NULL);
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_45, NULL);
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_47, NULL);
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_48, NULL);
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), NULL);
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_52, NULL);
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_53, NULL);
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_55, NULL);
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_56, NULL);
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_58, NULL);
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_60, NULL);
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_61, NULL);
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), NULL);
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60762
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B54_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		V_0 = 0;
		int32_t L_1 = ___0_root_id;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_2 = ___0_root_id;
		G_B3_0 = L_2;
		goto IL_001c;
	}

IL_0016:
	{
		int32_t L_3 = __this->___root;
		G_B3_0 = L_3;
	}

IL_001c:
	{
		V_1 = G_B3_0;
		int32_t L_4 = __this->____accessMethod;
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_01f8;
		}
	}
	{
		bool L_5 = ___4_append;
		if (L_5)
		{
			goto IL_01f8;
		}
	}
	{
		goto IL_01f0;
	}

IL_0035:
	{
		int32_t L_6 = V_1;
		RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8(__this, L_6, NULL);
		int32_t L_7 = V_1;
		V_0 = L_7;
		int32_t L_8 = ___0_root_id;
		if (!L_8)
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_9 = ___1_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_9, NULL);
		int32_t L_11 = V_1;
		int32_t L_12;
		L_12 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_11, NULL);
		int32_t L_13;
		L_13 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_10, L_12);
		G_B9_0 = L_13;
		goto IL_006b;
	}

IL_0057:
	{
		int32_t L_14 = ___1_x_id;
		int32_t L_15;
		L_15 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_14, NULL);
		int32_t L_16 = V_1;
		int32_t L_17;
		L_17 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_16, NULL);
		int32_t L_18;
		L_18 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_15, L_17);
		G_B9_0 = L_18;
	}

IL_006b:
	{
		V_2 = G_B9_0;
		int32_t L_19 = V_2;
		if ((((int32_t)L_19) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_20 = V_1;
		int32_t L_21;
		L_21 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_20, NULL);
		V_1 = L_21;
		goto IL_01f0;
	}

IL_007d:
	{
		int32_t L_22 = V_2;
		if ((((int32_t)L_22) <= ((int32_t)0)))
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_23 = V_1;
		int32_t L_24;
		L_24 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_23, NULL);
		V_1 = L_24;
		goto IL_01f0;
	}

IL_008e:
	{
		int32_t L_25 = ___0_root_id;
		if (!L_25)
		{
			goto IL_0098;
		}
	}
	{
		Exception_t* L_26;
		L_26 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_26, method);
	}

IL_0098:
	{
		int32_t L_27 = V_1;
		int32_t L_28;
		L_28 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_27, NULL);
		if (!L_28)
		{
			goto IL_00cd;
		}
	}
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_29, NULL);
		int32_t L_31 = ___1_x_id;
		int32_t L_32 = V_1;
		int32_t L_33;
		L_33 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, L_30, L_31, L_32, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_33;
		int32_t L_34 = V_1;
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_35, NULL);
		int32_t L_37;
		L_37 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_36, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_34, L_37, NULL);
		goto IL_01ee;
	}

IL_00cd:
	{
		V_3 = 0;
		int32_t L_38 = V_1;
		int32_t L_39;
		L_39 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_38, NULL);
		int32_t L_40;
		L_40 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_39, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_3 = L_40;
		int32_t L_41 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = V_3;
		int32_t L_43 = V_1;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_42, L_43, NULL);
		int32_t L_44 = V_3;
		int32_t L_45 = V_1;
		int32_t L_46;
		L_46 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_45, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_44, L_46, NULL);
		int32_t L_47 = V_3;
		int32_t L_48 = V_1;
		int32_t L_49;
		L_49 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_48, NULL);
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_47, L_49, NULL);
		int32_t L_50 = V_3;
		int32_t L_51 = V_1;
		int32_t L_52;
		L_52 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_51, NULL);
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_50, L_52, NULL);
		int32_t L_53 = V_3;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_54, NULL);
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_53, L_55, NULL);
		int32_t L_56 = V_1;
		int32_t L_57;
		L_57 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_56, NULL);
		int32_t L_58;
		L_58 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_57, NULL);
		int32_t L_59 = V_1;
		if ((!(((uint32_t)L_58) == ((uint32_t)L_59))))
		{
			goto IL_014b;
		}
	}
	{
		int32_t L_60 = V_1;
		int32_t L_61;
		L_61 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_60, NULL);
		int32_t L_62 = V_3;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_61, L_62, NULL);
		goto IL_0169;
	}

IL_014b:
	{
		int32_t L_63 = V_1;
		int32_t L_64;
		L_64 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_63, NULL);
		int32_t L_65;
		L_65 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_64, NULL);
		int32_t L_66 = V_1;
		if ((!(((uint32_t)L_65) == ((uint32_t)L_66))))
		{
			goto IL_0169;
		}
	}
	{
		int32_t L_67 = V_1;
		int32_t L_68;
		L_68 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_67, NULL);
		int32_t L_69 = V_3;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_68, L_69, NULL);
	}

IL_0169:
	{
		int32_t L_70 = V_1;
		int32_t L_71;
		L_71 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_70, NULL);
		if (!L_71)
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_72 = V_1;
		int32_t L_73;
		L_73 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_72, NULL);
		int32_t L_74 = V_3;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_73, L_74, NULL);
	}

IL_0180:
	{
		int32_t L_75 = V_1;
		int32_t L_76;
		L_76 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_75, NULL);
		if (!L_76)
		{
			goto IL_0197;
		}
	}
	{
		int32_t L_77 = V_1;
		int32_t L_78;
		L_78 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_77, NULL);
		int32_t L_79 = V_3;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_78, L_79, NULL);
	}

IL_0197:
	{
		int32_t L_80 = __this->___root;
		int32_t L_81 = V_1;
		if ((!(((uint32_t)L_80) == ((uint32_t)L_81))))
		{
			goto IL_01a7;
		}
	}
	{
		int32_t L_82 = V_3;
		__this->___root = L_82;
	}

IL_01a7:
	{
		int32_t L_83 = V_1;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_83, 1, NULL);
		int32_t L_84 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_84, 0, NULL);
		int32_t L_85 = V_1;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_85, 0, NULL);
		int32_t L_86 = V_1;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_86, 0, NULL);
		int32_t L_87 = V_1;
		int32_t L_88;
		L_88 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_87, NULL);
		V_4 = L_88;
		int32_t L_89 = V_1;
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_89, 1, NULL);
		int32_t L_90 = V_1;
		int32_t L_91 = ___1_x_id;
		int32_t L_92 = V_3;
		int32_t L_93;
		L_93 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, L_90, L_91, L_92, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_93;
		int32_t L_94 = V_3;
		int32_t L_95 = V_4;
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_94, L_95, NULL);
	}

IL_01ee:
	{
		int32_t L_96 = ___0_root_id;
		return L_96;
	}

IL_01f0:
	{
		int32_t L_97 = V_1;
		if (L_97)
		{
			goto IL_0035;
		}
	}
	{
		goto IL_0263;
	}

IL_01f8:
	{
		int32_t L_98 = __this->____accessMethod;
		bool L_99 = ___4_append;
		if (!((int32_t)(((((int32_t)L_98) == ((int32_t)2))? 1 : 0)|(int32_t)L_99)))
		{
			goto IL_025b;
		}
	}
	{
		int32_t L_100 = ___3_position;
		if ((!(((uint32_t)L_100) == ((uint32_t)(-1)))))
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_101 = __this->___root;
		int32_t L_102;
		L_102 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_101, NULL);
		___3_position = L_102;
		goto IL_0256;
	}

IL_021b:
	{
		int32_t L_103 = V_1;
		RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8(__this, L_103, NULL);
		int32_t L_104 = V_1;
		V_0 = L_104;
		int32_t L_105 = ___3_position;
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_106, NULL);
		int32_t L_108;
		L_108 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_107, NULL);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_105, L_108));
		int32_t L_109 = V_5;
		if ((((int32_t)L_109) > ((int32_t)0)))
		{
			goto IL_0245;
		}
	}
	{
		int32_t L_110 = V_1;
		int32_t L_111;
		L_111 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_110, NULL);
		V_1 = L_111;
		goto IL_0256;
	}

IL_0245:
	{
		int32_t L_112 = V_1;
		int32_t L_113;
		L_113 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_112, NULL);
		V_1 = L_113;
		int32_t L_114 = V_1;
		if (!L_114)
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_115 = V_5;
		___3_position = ((int32_t)il2cpp_codegen_subtract(L_115, 1));
	}

IL_0256:
	{
		int32_t L_116 = V_1;
		if (L_116)
		{
			goto IL_021b;
		}
	}
	{
		goto IL_0263;
	}

IL_025b:
	{
		Exception_t* L_117;
		L_117 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)15), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_117, method);
	}

IL_0263:
	{
		int32_t L_118 = ___1_x_id;
		int32_t L_119 = V_0;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_118, L_119, NULL);
		int32_t L_120 = V_0;
		if (L_120)
		{
			goto IL_0298;
		}
	}
	{
		int32_t L_121 = ___0_root_id;
		if (L_121)
		{
			goto IL_027d;
		}
	}
	{
		int32_t L_122 = ___1_x_id;
		__this->___root = L_122;
		goto IL_030a;
	}

IL_027d:
	{
		int32_t L_123 = ___2_mainTreeNodeID;
		int32_t L_124 = ___1_x_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_123, L_124, NULL);
		int32_t L_125 = ___2_mainTreeNodeID;
		int32_t L_126 = ___1_x_id;
		int32_t L_127;
		L_127 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_126, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_125, L_127, NULL);
		int32_t L_128 = ___1_x_id;
		___0_root_id = L_128;
		goto IL_030a;
	}

IL_0298:
	{
		V_6 = 0;
		int32_t L_129 = __this->____accessMethod;
		if ((!(((uint32_t)L_129) == ((uint32_t)1))))
		{
			goto IL_02d5;
		}
	}
	{
		int32_t L_130 = ___0_root_id;
		if (!L_130)
		{
			goto IL_02bd;
		}
	}
	{
		int32_t L_131 = ___1_x_id;
		int32_t L_132;
		L_132 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_131, NULL);
		int32_t L_133 = V_0;
		int32_t L_134;
		L_134 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_133, NULL);
		int32_t L_135;
		L_135 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_132, L_134);
		G_B49_0 = L_135;
		goto IL_02d1;
	}

IL_02bd:
	{
		int32_t L_136 = ___1_x_id;
		int32_t L_137;
		L_137 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_136, NULL);
		int32_t L_138 = V_0;
		int32_t L_139;
		L_139 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_138, NULL);
		int32_t L_140;
		L_140 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_137, L_139);
		G_B49_0 = L_140;
	}

IL_02d1:
	{
		V_6 = G_B49_0;
		goto IL_02f3;
	}

IL_02d5:
	{
		int32_t L_141 = __this->____accessMethod;
		if ((!(((uint32_t)L_141) == ((uint32_t)2))))
		{
			goto IL_02eb;
		}
	}
	{
		int32_t L_142 = ___3_position;
		if ((((int32_t)L_142) <= ((int32_t)0)))
		{
			goto IL_02e6;
		}
	}
	{
		G_B54_0 = 1;
		goto IL_02e7;
	}

IL_02e6:
	{
		G_B54_0 = (-1);
	}

IL_02e7:
	{
		V_6 = G_B54_0;
		goto IL_02f3;
	}

IL_02eb:
	{
		Exception_t* L_143;
		L_143 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)16), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_143, method);
	}

IL_02f3:
	{
		int32_t L_144 = V_6;
		if ((((int32_t)L_144) >= ((int32_t)0)))
		{
			goto IL_0302;
		}
	}
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_145, L_146, NULL);
		goto IL_030a;
	}

IL_0302:
	{
		int32_t L_147 = V_0;
		int32_t L_148 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_147, L_148, NULL);
	}

IL_030a:
	{
		int32_t L_149 = ___1_x_id;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_149, 0, NULL);
		int32_t L_150 = ___1_x_id;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_150, 0, NULL);
		int32_t L_151 = ___1_x_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_151, 0, NULL);
		int32_t L_152 = ___1_x_id;
		V_1 = L_152;
		goto IL_04ba;
	}

IL_0329:
	{
		int32_t L_153 = ___1_x_id;
		int32_t L_154;
		L_154 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_153, NULL);
		int32_t L_155 = ___1_x_id;
		int32_t L_156;
		L_156 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_155, NULL);
		int32_t L_157;
		L_157 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_156, NULL);
		int32_t L_158;
		L_158 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_157, NULL);
		if ((!(((uint32_t)L_154) == ((uint32_t)L_158))))
		{
			goto IL_0405;
		}
	}
	{
		int32_t L_159 = ___1_x_id;
		int32_t L_160;
		L_160 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_159, NULL);
		int32_t L_161;
		L_161 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_160, NULL);
		int32_t L_162;
		L_162 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_161, NULL);
		V_0 = L_162;
		int32_t L_163 = V_0;
		int32_t L_164;
		L_164 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_163, NULL);
		if (L_164)
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_165 = ___1_x_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_165, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_166, 1, NULL);
		int32_t L_167 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_167, 1, NULL);
		int32_t L_168 = ___1_x_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_168, NULL);
		int32_t L_170;
		L_170 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_169, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_170, 0, NULL);
		int32_t L_171 = ___1_x_id;
		int32_t L_172;
		L_172 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_171, NULL);
		int32_t L_173;
		L_173 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_172, NULL);
		___1_x_id = L_173;
		goto IL_04ba;
	}

IL_03a3:
	{
		int32_t L_174 = ___1_x_id;
		int32_t L_175 = ___1_x_id;
		int32_t L_176;
		L_176 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_175, NULL);
		int32_t L_177;
		L_177 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_176, NULL);
		if ((!(((uint32_t)L_174) == ((uint32_t)L_177))))
		{
			goto IL_03c7;
		}
	}
	{
		int32_t L_178 = ___1_x_id;
		int32_t L_179;
		L_179 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_178, NULL);
		___1_x_id = L_179;
		int32_t L_180 = ___0_root_id;
		int32_t L_181 = ___1_x_id;
		int32_t L_182 = ___2_mainTreeNodeID;
		int32_t L_183;
		L_183 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_180, L_181, L_182, NULL);
		___0_root_id = L_183;
	}

IL_03c7:
	{
		int32_t L_184 = ___1_x_id;
		int32_t L_185;
		L_185 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_184, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_185, 1, NULL);
		int32_t L_186 = ___1_x_id;
		int32_t L_187;
		L_187 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_186, NULL);
		int32_t L_188;
		L_188 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_187, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_188, 0, NULL);
		int32_t L_189 = ___0_root_id;
		int32_t L_190 = ___1_x_id;
		int32_t L_191;
		L_191 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_190, NULL);
		int32_t L_192;
		L_192 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_191, NULL);
		int32_t L_193 = ___2_mainTreeNodeID;
		int32_t L_194;
		L_194 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_189, L_192, L_193, NULL);
		___0_root_id = L_194;
		goto IL_04ba;
	}

IL_0405:
	{
		int32_t L_195 = ___1_x_id;
		int32_t L_196;
		L_196 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_195, NULL);
		int32_t L_197;
		L_197 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_196, NULL);
		int32_t L_198;
		L_198 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_197, NULL);
		V_0 = L_198;
		int32_t L_199 = V_0;
		int32_t L_200;
		L_200 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_199, NULL);
		if (L_200)
		{
			goto IL_045d;
		}
	}
	{
		int32_t L_201 = ___1_x_id;
		int32_t L_202;
		L_202 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_201, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_202, 1, NULL);
		int32_t L_203 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_203, 1, NULL);
		int32_t L_204 = ___1_x_id;
		int32_t L_205;
		L_205 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_204, NULL);
		int32_t L_206;
		L_206 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_205, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_206, 0, NULL);
		int32_t L_207 = ___1_x_id;
		int32_t L_208;
		L_208 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_207, NULL);
		int32_t L_209;
		L_209 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_208, NULL);
		___1_x_id = L_209;
		goto IL_04ba;
	}

IL_045d:
	{
		int32_t L_210 = ___1_x_id;
		int32_t L_211 = ___1_x_id;
		int32_t L_212;
		L_212 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_211, NULL);
		int32_t L_213;
		L_213 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_212, NULL);
		if ((!(((uint32_t)L_210) == ((uint32_t)L_213))))
		{
			goto IL_0481;
		}
	}
	{
		int32_t L_214 = ___1_x_id;
		int32_t L_215;
		L_215 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_214, NULL);
		___1_x_id = L_215;
		int32_t L_216 = ___0_root_id;
		int32_t L_217 = ___1_x_id;
		int32_t L_218 = ___2_mainTreeNodeID;
		int32_t L_219;
		L_219 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_216, L_217, L_218, NULL);
		___0_root_id = L_219;
	}

IL_0481:
	{
		int32_t L_220 = ___1_x_id;
		int32_t L_221;
		L_221 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_220, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_221, 1, NULL);
		int32_t L_222 = ___1_x_id;
		int32_t L_223;
		L_223 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_222, NULL);
		int32_t L_224;
		L_224 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_223, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_224, 0, NULL);
		int32_t L_225 = ___0_root_id;
		int32_t L_226 = ___1_x_id;
		int32_t L_227;
		L_227 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_226, NULL);
		int32_t L_228;
		L_228 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_227, NULL);
		int32_t L_229 = ___2_mainTreeNodeID;
		int32_t L_230;
		L_230 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_225, L_228, L_229, NULL);
		___0_root_id = L_230;
	}

IL_04ba:
	{
		int32_t L_231 = ___1_x_id;
		int32_t L_232;
		L_232 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_231, NULL);
		int32_t L_233;
		L_233 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_232, NULL);
		if (!L_233)
		{
			goto IL_0329;
		}
	}
	{
		int32_t L_234 = ___0_root_id;
		if (L_234)
		{
			goto IL_04de;
		}
	}
	{
		int32_t L_235 = __this->___root;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_235, 1, NULL);
		goto IL_04e6;
	}

IL_04de:
	{
		int32_t L_236 = ___0_root_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_236, 1, NULL);
	}

IL_04e6:
	{
		int32_t L_237 = ___0_root_id;
		return L_237;
	}
}
// Method Definition Index: 60763
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_UpdateNodeKey_m90FF8C96E5A0A272D878A6CB88DEE893A34E6830 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_currentKey, int32_t ___1_newKey, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_currentKey;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		V_0 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, NULL);
		if (L_4)
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		int32_t L_7 = __this->___root;
		if ((((int32_t)L_6) == ((int32_t)L_7)))
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_8 = V_0;
		int32_t L_9 = L_8.____mainTreeNodeID;
		int32_t L_10 = ___1_newKey;
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_9, L_10, NULL);
	}

IL_0031:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_11 = V_0;
		int32_t L_12 = L_11.____nodeID;
		int32_t L_13 = ___1_newKey;
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_12, L_13, NULL);
		return;
	}
}
// Method Definition Index: 60764
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_i, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_i;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		V_0 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_3, NULL);
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_7 = V_0;
		int32_t L_8 = L_7.____mainTreeNodeID;
		int32_t L_9;
		L_9 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, 0, L_6, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_4;
	}
}
// Method Definition Index: 60765
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDelete_mD650E7F92013005A24CE586C4FC1B71EE3D279C7 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_z_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_z_id;
		int32_t L_1;
		L_1 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, 0, L_0, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_1;
	}
}
// Method Definition Index: 60766
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t G_B5_0 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___1_z_id;
		int32_t L_1;
		L_1 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = ___1_z_id;
		int32_t L_3;
		L_3 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_2, NULL);
		int32_t L_4 = ___1_z_id;
		int32_t L_5;
		L_5 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_4, NULL);
		int32_t L_6 = ___1_z_id;
		int32_t L_7;
		L_7 = RBTree_1_RBDeleteX_m6AEBE3413E7ECF37B61015F652AA07DF5C9A13AC(__this, L_3, L_5, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_7;
	}

IL_0021:
	{
		V_3 = (bool)0;
		int32_t L_8 = __this->____accessMethod;
		if ((((int32_t)L_8) == ((int32_t)1)))
		{
			goto IL_002f;
		}
	}
	{
		int32_t L_9 = ___1_z_id;
		G_B5_0 = L_9;
		goto IL_0030;
	}

IL_002f:
	{
		int32_t L_10 = ___2_mainTreeNodeID;
		G_B5_0 = L_10;
	}

IL_0030:
	{
		V_4 = G_B5_0;
		int32_t L_11 = V_4;
		int32_t L_12;
		L_12 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_11, NULL);
		if (!L_12)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_13 = V_4;
		int32_t L_14;
		L_14 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_13, NULL);
		___0_root_id = L_14;
	}

IL_0046:
	{
		int32_t L_15 = V_4;
		int32_t L_16;
		L_16 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_15, NULL);
		int32_t L_17;
		L_17 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_16, NULL);
		if ((!(((uint32_t)L_17) == ((uint32_t)2))))
		{
			goto IL_005b;
		}
	}
	{
		V_3 = (bool)1;
		goto IL_0073;
	}

IL_005b:
	{
		int32_t L_18 = V_4;
		int32_t L_19;
		L_19 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_18, NULL);
		int32_t L_20;
		L_20 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_19, NULL);
		if ((!(((uint32_t)L_20) == ((uint32_t)1))))
		{
			goto IL_0073;
		}
	}
	{
		Exception_t* L_21;
		L_21 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(7, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_21, method);
	}

IL_0073:
	{
		int32_t L_22 = ___1_z_id;
		int32_t L_23;
		L_23 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_22, NULL);
		if (!L_23)
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_24 = ___1_z_id;
		int32_t L_25;
		L_25 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_24, NULL);
		if (L_25)
		{
			goto IL_0089;
		}
	}

IL_0085:
	{
		int32_t L_26 = ___1_z_id;
		V_1 = L_26;
		goto IL_0091;
	}

IL_0089:
	{
		int32_t L_27 = ___1_z_id;
		int32_t L_28;
		L_28 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_27, NULL);
		V_1 = L_28;
	}

IL_0091:
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_29, NULL);
		if (!L_30)
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_31 = V_1;
		int32_t L_32;
		L_32 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_31, NULL);
		V_0 = L_32;
		goto IL_00ac;
	}

IL_00a4:
	{
		int32_t L_33 = V_1;
		int32_t L_34;
		L_34 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_33, NULL);
		V_0 = L_34;
	}

IL_00ac:
	{
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_35, NULL);
		V_2 = L_36;
		int32_t L_37 = V_0;
		if (!L_37)
		{
			goto IL_00bf;
		}
	}
	{
		int32_t L_38 = V_0;
		int32_t L_39 = V_2;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_38, L_39, NULL);
	}

IL_00bf:
	{
		int32_t L_40 = V_2;
		if (L_40)
		{
			goto IL_00d3;
		}
	}
	{
		int32_t L_41 = ___0_root_id;
		if (L_41)
		{
			goto IL_00ce;
		}
	}
	{
		int32_t L_42 = V_0;
		__this->___root = L_42;
		goto IL_00ef;
	}

IL_00ce:
	{
		int32_t L_43 = V_0;
		___0_root_id = L_43;
		goto IL_00ef;
	}

IL_00d3:
	{
		int32_t L_44 = V_1;
		int32_t L_45 = V_2;
		int32_t L_46;
		L_46 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_45, NULL);
		if ((!(((uint32_t)L_44) == ((uint32_t)L_46))))
		{
			goto IL_00e7;
		}
	}
	{
		int32_t L_47 = V_2;
		int32_t L_48 = V_0;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_47, L_48, NULL);
		goto IL_00ef;
	}

IL_00e7:
	{
		int32_t L_49 = V_2;
		int32_t L_50 = V_0;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_49, L_50, NULL);
	}

IL_00ef:
	{
		int32_t L_51 = V_1;
		int32_t L_52 = ___1_z_id;
		if ((((int32_t)L_51) == ((int32_t)L_52)))
		{
			goto IL_010f;
		}
	}
	{
		int32_t L_53 = ___1_z_id;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_54, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_53, L_55, NULL);
		int32_t L_56 = ___1_z_id;
		int32_t L_57 = V_1;
		int32_t L_58;
		L_58 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_57, NULL);
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_56, L_58, NULL);
	}

IL_010f:
	{
		int32_t L_59 = V_4;
		int32_t L_60;
		L_60 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_59, NULL);
		if (!L_60)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_61 = ___0_root_id;
		if (L_61)
		{
			goto IL_0128;
		}
	}
	{
		int32_t L_62 = ___1_z_id;
		int32_t L_63 = V_4;
		if ((((int32_t)L_62) == ((int32_t)L_63)))
		{
			goto IL_0128;
		}
	}
	{
		Exception_t* L_64;
		L_64 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_64, method);
	}

IL_0128:
	{
		int32_t L_65 = ___0_root_id;
		if (!L_65)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_66 = V_4;
		int32_t L_67 = ___0_root_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_66, L_67, NULL);
		int32_t L_68 = V_4;
		int32_t L_69 = ___0_root_id;
		int32_t L_70;
		L_70 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_69, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_68, L_70, NULL);
	}

IL_0143:
	{
		int32_t L_71 = V_2;
		V_5 = L_71;
		goto IL_015a;
	}

IL_0148:
	{
		int32_t L_72 = V_5;
		RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A(__this, L_72, NULL);
		int32_t L_73 = V_5;
		int32_t L_74;
		L_74 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_73, NULL);
		V_5 = L_74;
	}

IL_015a:
	{
		int32_t L_75 = V_5;
		if (L_75)
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_76 = ___0_root_id;
		if (!L_76)
		{
			goto IL_017d;
		}
	}
	{
		int32_t L_77 = V_4;
		V_6 = L_77;
		goto IL_0179;
	}

IL_0167:
	{
		int32_t L_78 = V_6;
		RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F(__this, L_78, NULL);
		int32_t L_79 = V_6;
		int32_t L_80;
		L_80 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_79, NULL);
		V_6 = L_80;
	}

IL_0179:
	{
		int32_t L_81 = V_6;
		if (L_81)
		{
			goto IL_0167;
		}
	}

IL_017d:
	{
		int32_t L_82 = V_1;
		int32_t L_83;
		L_83 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_82, NULL);
		if ((!(((uint32_t)L_83) == ((uint32_t)1))))
		{
			goto IL_0193;
		}
	}
	{
		int32_t L_84 = ___0_root_id;
		int32_t L_85 = V_0;
		int32_t L_86 = V_2;
		int32_t L_87 = ___2_mainTreeNodeID;
		int32_t L_88;
		L_88 = RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89(__this, L_84, L_85, L_86, L_87, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
		___0_root_id = L_88;
	}

IL_0193:
	{
		bool L_89 = V_3;
		if (!L_89)
		{
			goto IL_02af;
		}
	}
	{
		int32_t L_90 = V_4;
		if (!L_90)
		{
			goto IL_01ae;
		}
	}
	{
		int32_t L_91 = V_4;
		int32_t L_92;
		L_92 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_91, NULL);
		int32_t L_93;
		L_93 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_92, NULL);
		if ((((int32_t)L_93) == ((int32_t)1)))
		{
			goto IL_01b6;
		}
	}

IL_01ae:
	{
		Exception_t* L_94;
		L_94 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)9), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_94, method);
	}

IL_01b6:
	{
		int32_t L_95 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_subtract(L_95, 1));
		int32_t L_96 = V_4;
		int32_t L_97;
		L_97 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_96, NULL);
		V_7 = L_97;
		int32_t L_98 = V_7;
		int32_t L_99 = V_4;
		int32_t L_100;
		L_100 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_99, NULL);
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_98, L_100, NULL);
		int32_t L_101 = V_7;
		int32_t L_102 = V_4;
		int32_t L_103;
		L_103 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_102, NULL);
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_101, L_103, NULL);
		int32_t L_104 = V_7;
		int32_t L_105 = V_4;
		int32_t L_106;
		L_106 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_105, NULL);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_104, L_106, NULL);
		int32_t L_107 = V_7;
		int32_t L_108 = V_4;
		int32_t L_109;
		L_109 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_108, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_107, L_109, NULL);
		int32_t L_110 = V_4;
		int32_t L_111;
		L_111 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_110, NULL);
		if (!L_111)
		{
			goto IL_025c;
		}
	}
	{
		int32_t L_112 = V_7;
		int32_t L_113 = V_4;
		int32_t L_114;
		L_114 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_113, NULL);
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_112, L_114, NULL);
		int32_t L_115 = V_4;
		int32_t L_116;
		L_116 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_115, NULL);
		int32_t L_117;
		L_117 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_116, NULL);
		int32_t L_118 = V_4;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_118))))
		{
			goto IL_024c;
		}
	}
	{
		int32_t L_119 = V_4;
		int32_t L_120;
		L_120 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_119, NULL);
		int32_t L_121 = V_7;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_120, L_121, NULL);
		goto IL_025c;
	}

IL_024c:
	{
		int32_t L_122 = V_4;
		int32_t L_123;
		L_123 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_122, NULL);
		int32_t L_124 = V_7;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_123, L_124, NULL);
	}

IL_025c:
	{
		int32_t L_125 = V_4;
		int32_t L_126;
		L_126 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_125, NULL);
		if (!L_126)
		{
			goto IL_0276;
		}
	}
	{
		int32_t L_127 = V_4;
		int32_t L_128;
		L_128 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_127, NULL);
		int32_t L_129 = V_7;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_128, L_129, NULL);
	}

IL_0276:
	{
		int32_t L_130 = V_4;
		int32_t L_131;
		L_131 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_130, NULL);
		if (!L_131)
		{
			goto IL_0290;
		}
	}
	{
		int32_t L_132 = V_4;
		int32_t L_133;
		L_133 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_132, NULL);
		int32_t L_134 = V_7;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_133, L_134, NULL);
	}

IL_0290:
	{
		int32_t L_135 = __this->___root;
		int32_t L_136 = V_4;
		if ((!(((uint32_t)L_135) == ((uint32_t)L_136))))
		{
			goto IL_02a2;
		}
	}
	{
		int32_t L_137 = V_7;
		__this->___root = L_137;
	}

IL_02a2:
	{
		int32_t L_138 = V_4;
		RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD(__this, L_138, NULL);
		V_4 = 0;
		goto IL_02e4;
	}

IL_02af:
	{
		int32_t L_139 = V_4;
		int32_t L_140;
		L_140 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_139, NULL);
		if (!L_140)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		if (L_141)
		{
			goto IL_02c9;
		}
	}
	{
		int32_t L_142 = ___1_z_id;
		int32_t L_143 = V_4;
		if ((((int32_t)L_142) == ((int32_t)L_143)))
		{
			goto IL_02c9;
		}
	}
	{
		Exception_t* L_144;
		L_144 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)10), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_144, method);
	}

IL_02c9:
	{
		int32_t L_145 = ___0_root_id;
		if (!L_145)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_146 = V_4;
		int32_t L_147 = ___0_root_id;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_146, L_147, NULL);
		int32_t L_148 = V_4;
		int32_t L_149 = ___0_root_id;
		int32_t L_150;
		L_150 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_149, NULL);
		RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9(__this, L_148, L_150, NULL);
	}

IL_02e4:
	{
		int32_t L_151 = V_1;
		int32_t L_152 = ___1_z_id;
		if ((((int32_t)L_151) == ((int32_t)L_152)))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_153 = V_1;
		int32_t L_154 = ___1_z_id;
		int32_t L_155;
		L_155 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_154, NULL);
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_153, L_155, NULL);
		int32_t L_156 = V_1;
		int32_t L_157 = ___1_z_id;
		int32_t L_158;
		L_158 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_157, NULL);
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_156, L_158, NULL);
		int32_t L_159 = V_1;
		int32_t L_160 = ___1_z_id;
		int32_t L_161;
		L_161 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_160, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_159, L_161, NULL);
		int32_t L_162 = V_1;
		int32_t L_163 = ___1_z_id;
		int32_t L_164;
		L_164 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_163, NULL);
		RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55(__this, L_162, L_164, NULL);
		int32_t L_165 = ___1_z_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_165, NULL);
		if (!L_166)
		{
			goto IL_036a;
		}
	}
	{
		int32_t L_167 = V_1;
		int32_t L_168 = ___1_z_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_168, NULL);
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_167, L_169, NULL);
		int32_t L_170 = ___1_z_id;
		int32_t L_171;
		L_171 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_170, NULL);
		int32_t L_172;
		L_172 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_171, NULL);
		int32_t L_173 = ___1_z_id;
		if ((!(((uint32_t)L_172) == ((uint32_t)L_173))))
		{
			goto IL_035a;
		}
	}
	{
		int32_t L_174 = ___1_z_id;
		int32_t L_175;
		L_175 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_174, NULL);
		int32_t L_176 = V_1;
		RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063(__this, L_175, L_176, NULL);
		goto IL_0372;
	}

IL_035a:
	{
		int32_t L_177 = ___1_z_id;
		int32_t L_178;
		L_178 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_177, NULL);
		int32_t L_179 = V_1;
		RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45(__this, L_178, L_179, NULL);
		goto IL_0372;
	}

IL_036a:
	{
		int32_t L_180 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_180, 0, NULL);
	}

IL_0372:
	{
		int32_t L_181 = ___1_z_id;
		int32_t L_182;
		L_182 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_181, NULL);
		if (!L_182)
		{
			goto IL_0389;
		}
	}
	{
		int32_t L_183 = ___1_z_id;
		int32_t L_184;
		L_184 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_183, NULL);
		int32_t L_185 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_184, L_185, NULL);
	}

IL_0389:
	{
		int32_t L_186 = ___1_z_id;
		int32_t L_187;
		L_187 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_186, NULL);
		if (!L_187)
		{
			goto IL_03a0;
		}
	}
	{
		int32_t L_188 = ___1_z_id;
		int32_t L_189;
		L_189 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_188, NULL);
		int32_t L_190 = V_1;
		RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9(__this, L_189, L_190, NULL);
	}

IL_03a0:
	{
		int32_t L_191 = __this->___root;
		int32_t L_192 = ___1_z_id;
		if ((!(((uint32_t)L_191) == ((uint32_t)L_192))))
		{
			goto IL_03b2;
		}
	}
	{
		int32_t L_193 = V_1;
		__this->___root = L_193;
		goto IL_03b9;
	}

IL_03b2:
	{
		int32_t L_194 = ___0_root_id;
		int32_t L_195 = ___1_z_id;
		if ((!(((uint32_t)L_194) == ((uint32_t)L_195))))
		{
			goto IL_03b9;
		}
	}
	{
		int32_t L_196 = V_1;
		___0_root_id = L_196;
	}

IL_03b9:
	{
		int32_t L_197 = V_4;
		if (!L_197)
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_198 = V_4;
		int32_t L_199;
		L_199 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_198, NULL);
		int32_t L_200 = ___1_z_id;
		if ((!(((uint32_t)L_199) == ((uint32_t)L_200))))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_201 = V_4;
		int32_t L_202 = V_1;
		RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8(__this, L_201, L_202, NULL);
	}

IL_03d1:
	{
		int32_t L_203 = ___1_z_id;
		RBTree_1_FreeNode_m142FC91FA594DC91799F5231F7AE945DCC6922FD(__this, L_203, NULL);
		int32_t L_204 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_204, 1));
		int32_t L_205 = ___1_z_id;
		return L_205;
	}
}
// Method Definition Index: 60767
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m25667C31EC6662F3899EA7CDFF622F9DB394AF89 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B24_0 = 0;
	int32_t G_B28_0 = 0;
	int32_t G_B34_0 = 0;
	int32_t G_B38_0 = 0;
	int32_t G_B47_0 = 0;
	int32_t G_B52_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B60_0 = 0;
	{
		int32_t L_0 = ___1_x_id;
		if (L_0)
		{
			goto IL_0305;
		}
	}
	{
		int32_t L_1 = ___2_px_id;
		if (L_1)
		{
			goto IL_0305;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		int32_t L_2 = ___1_x_id;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_3 = ___1_x_id;
		int32_t L_4 = ___1_x_id;
		int32_t L_5;
		L_5 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_4, NULL);
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, NULL);
		if ((((int32_t)L_3) == ((int32_t)L_6)))
		{
			goto IL_0033;
		}
	}

IL_0021:
	{
		int32_t L_7 = ___1_x_id;
		if (L_7)
		{
			goto IL_0168;
		}
	}
	{
		int32_t L_8 = ___2_px_id;
		int32_t L_9;
		L_9 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_8, NULL);
		if (L_9)
		{
			goto IL_0168;
		}
	}

IL_0033:
	{
		int32_t L_10 = ___1_x_id;
		if (!L_10)
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_11, NULL);
		int32_t L_13;
		L_13 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_12, NULL);
		G_B10_0 = L_13;
		goto IL_004c;
	}

IL_0045:
	{
		int32_t L_14 = ___2_px_id;
		int32_t L_15;
		L_15 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_14, NULL);
		G_B10_0 = L_15;
	}

IL_004c:
	{
		V_0 = G_B10_0;
		int32_t L_16 = V_0;
		if (L_16)
		{
			goto IL_0058;
		}
	}
	{
		Exception_t* L_17;
		L_17 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)14), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_0058:
	{
		int32_t L_18 = V_0;
		int32_t L_19;
		L_19 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_18, NULL);
		if (L_19)
		{
			goto IL_0097;
		}
	}
	{
		int32_t L_20 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_20, 1, NULL);
		int32_t L_21 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_21, 0, NULL);
		int32_t L_22 = ___0_root_id;
		int32_t L_23 = ___2_px_id;
		int32_t L_24 = ___3_mainTreeNodeID;
		int32_t L_25;
		L_25 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_22, L_23, L_24, NULL);
		___0_root_id = L_25;
		int32_t L_26 = ___1_x_id;
		if (!L_26)
		{
			goto IL_008f;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_27, NULL);
		int32_t L_29;
		L_29 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_28, NULL);
		G_B16_0 = L_29;
		goto IL_0096;
	}

IL_008f:
	{
		int32_t L_30 = ___2_px_id;
		int32_t L_31;
		L_31 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_30, NULL);
		G_B16_0 = L_31;
	}

IL_0096:
	{
		V_0 = G_B16_0;
	}

IL_0097:
	{
		int32_t L_32 = V_0;
		int32_t L_33;
		L_33 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_32, NULL);
		int32_t L_34;
		L_34 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_33, NULL);
		if ((!(((uint32_t)L_34) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_35 = V_0;
		int32_t L_36;
		L_36 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_35, NULL);
		int32_t L_37;
		L_37 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_36, NULL);
		if ((!(((uint32_t)L_37) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_38 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_38, 0, NULL);
		int32_t L_39 = ___2_px_id;
		___1_x_id = L_39;
		int32_t L_40 = ___2_px_id;
		int32_t L_41;
		L_41 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_40, NULL);
		___2_px_id = L_41;
		goto IL_0305;
	}

IL_00d0:
	{
		int32_t L_42 = V_0;
		int32_t L_43;
		L_43 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_43, NULL);
		if ((!(((uint32_t)L_44) == ((uint32_t)1))))
		{
			goto IL_011c;
		}
	}
	{
		int32_t L_45 = V_0;
		int32_t L_46;
		L_46 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_45, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_46, 1, NULL);
		int32_t L_47 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_47, 0, NULL);
		int32_t L_48 = ___0_root_id;
		int32_t L_49 = V_0;
		int32_t L_50 = ___3_mainTreeNodeID;
		int32_t L_51;
		L_51 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_48, L_49, L_50, NULL);
		___0_root_id = L_51;
		int32_t L_52 = ___1_x_id;
		if (!L_52)
		{
			goto IL_0114;
		}
	}
	{
		int32_t L_53 = ___1_x_id;
		int32_t L_54;
		L_54 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_53, NULL);
		int32_t L_55;
		L_55 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_54, NULL);
		G_B24_0 = L_55;
		goto IL_011b;
	}

IL_0114:
	{
		int32_t L_56 = ___2_px_id;
		int32_t L_57;
		L_57 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_56, NULL);
		G_B24_0 = L_57;
	}

IL_011b:
	{
		V_0 = G_B24_0;
	}

IL_011c:
	{
		int32_t L_58 = V_0;
		int32_t L_59 = ___2_px_id;
		int32_t L_60;
		L_60 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_59, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_58, L_60, NULL);
		int32_t L_61 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_61, 1, NULL);
		int32_t L_62 = V_0;
		int32_t L_63;
		L_63 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_62, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_63, 1, NULL);
		int32_t L_64 = ___0_root_id;
		int32_t L_65 = ___2_px_id;
		int32_t L_66 = ___3_mainTreeNodeID;
		int32_t L_67;
		L_67 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_64, L_65, L_66, NULL);
		___0_root_id = L_67;
		int32_t L_68 = ___0_root_id;
		if (!L_68)
		{
			goto IL_0152;
		}
	}
	{
		int32_t L_69 = ___0_root_id;
		G_B28_0 = L_69;
		goto IL_0158;
	}

IL_0152:
	{
		int32_t L_70 = __this->___root;
		G_B28_0 = L_70;
	}

IL_0158:
	{
		___1_x_id = G_B28_0;
		int32_t L_71 = ___1_x_id;
		int32_t L_72;
		L_72 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_71, NULL);
		___2_px_id = L_72;
		goto IL_0305;
	}

IL_0168:
	{
		int32_t L_73 = ___2_px_id;
		int32_t L_74;
		L_74 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_73, NULL);
		V_0 = L_74;
		int32_t L_75 = V_0;
		int32_t L_76;
		L_76 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_75, NULL);
		if (L_76)
		{
			goto IL_01ed;
		}
	}
	{
		int32_t L_77 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_77, 1, NULL);
		int32_t L_78 = ___1_x_id;
		if (!L_78)
		{
			goto IL_01b4;
		}
	}
	{
		int32_t L_79 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_79, 0, NULL);
		int32_t L_80 = ___0_root_id;
		int32_t L_81 = ___2_px_id;
		int32_t L_82 = ___3_mainTreeNodeID;
		int32_t L_83;
		L_83 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_80, L_81, L_82, NULL);
		___0_root_id = L_83;
		int32_t L_84 = ___1_x_id;
		if (!L_84)
		{
			goto IL_01aa;
		}
	}
	{
		int32_t L_85 = ___1_x_id;
		int32_t L_86;
		L_86 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_85, NULL);
		int32_t L_87;
		L_87 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_86, NULL);
		G_B34_0 = L_87;
		goto IL_01b1;
	}

IL_01aa:
	{
		int32_t L_88 = ___2_px_id;
		int32_t L_89;
		L_89 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_88, NULL);
		G_B34_0 = L_89;
	}

IL_01b1:
	{
		V_0 = G_B34_0;
		goto IL_01ed;
	}

IL_01b4:
	{
		int32_t L_90 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_90, 0, NULL);
		int32_t L_91 = ___0_root_id;
		int32_t L_92 = ___2_px_id;
		int32_t L_93 = ___3_mainTreeNodeID;
		int32_t L_94;
		L_94 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_91, L_92, L_93, NULL);
		___0_root_id = L_94;
		int32_t L_95 = ___1_x_id;
		if (!L_95)
		{
			goto IL_01da;
		}
	}
	{
		int32_t L_96 = ___1_x_id;
		int32_t L_97;
		L_97 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_96, NULL);
		int32_t L_98;
		L_98 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_97, NULL);
		G_B38_0 = L_98;
		goto IL_01e1;
	}

IL_01da:
	{
		int32_t L_99 = ___2_px_id;
		int32_t L_100;
		L_100 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_99, NULL);
		G_B38_0 = L_100;
	}

IL_01e1:
	{
		V_0 = G_B38_0;
		int32_t L_101 = V_0;
		if (L_101)
		{
			goto IL_01ed;
		}
	}
	{
		Exception_t* L_102;
		L_102 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)11), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_102, method);
	}

IL_01ed:
	{
		int32_t L_103 = V_0;
		int32_t L_104;
		L_104 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_103, NULL);
		int32_t L_105;
		L_105 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_104, NULL);
		if ((!(((uint32_t)L_105) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_106, NULL);
		int32_t L_108;
		L_108 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_107, NULL);
		if ((!(((uint32_t)L_108) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_109 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_109, 0, NULL);
		int32_t L_110 = ___2_px_id;
		___1_x_id = L_110;
		int32_t L_111 = ___2_px_id;
		int32_t L_112;
		L_112 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_111, NULL);
		___2_px_id = L_112;
		goto IL_0305;
	}

IL_0226:
	{
		int32_t L_113 = V_0;
		int32_t L_114;
		L_114 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_113, NULL);
		int32_t L_115;
		L_115 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_114, NULL);
		if ((!(((uint32_t)L_115) == ((uint32_t)1))))
		{
			goto IL_0272;
		}
	}
	{
		int32_t L_116 = V_0;
		int32_t L_117;
		L_117 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_116, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_117, 1, NULL);
		int32_t L_118 = V_0;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_118, 0, NULL);
		int32_t L_119 = ___0_root_id;
		int32_t L_120 = V_0;
		int32_t L_121 = ___3_mainTreeNodeID;
		int32_t L_122;
		L_122 = RBTree_1_LeftRotate_mD49CD676DF4B79C1B56C4158BF78B239F3EBF7EE(__this, L_119, L_120, L_121, NULL);
		___0_root_id = L_122;
		int32_t L_123 = ___1_x_id;
		if (!L_123)
		{
			goto IL_026a;
		}
	}
	{
		int32_t L_124 = ___1_x_id;
		int32_t L_125;
		L_125 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_124, NULL);
		int32_t L_126;
		L_126 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_125, NULL);
		G_B47_0 = L_126;
		goto IL_0271;
	}

IL_026a:
	{
		int32_t L_127 = ___2_px_id;
		int32_t L_128;
		L_128 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_127, NULL);
		G_B47_0 = L_128;
	}

IL_0271:
	{
		V_0 = G_B47_0;
	}

IL_0272:
	{
		int32_t L_129 = ___1_x_id;
		if (!L_129)
		{
			goto IL_02be;
		}
	}
	{
		int32_t L_130 = V_0;
		int32_t L_131 = ___2_px_id;
		int32_t L_132;
		L_132 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_131, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_130, L_132, NULL);
		int32_t L_133 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_133, 1, NULL);
		int32_t L_134 = V_0;
		int32_t L_135;
		L_135 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_134, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_135, 1, NULL);
		int32_t L_136 = ___0_root_id;
		int32_t L_137 = ___2_px_id;
		int32_t L_138 = ___3_mainTreeNodeID;
		int32_t L_139;
		L_139 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_136, L_137, L_138, NULL);
		___0_root_id = L_139;
		int32_t L_140 = ___0_root_id;
		if (!L_140)
		{
			goto IL_02ab;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		G_B52_0 = L_141;
		goto IL_02b1;
	}

IL_02ab:
	{
		int32_t L_142 = __this->___root;
		G_B52_0 = L_142;
	}

IL_02b1:
	{
		___1_x_id = G_B52_0;
		int32_t L_143 = ___1_x_id;
		int32_t L_144;
		L_144 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_143, NULL);
		___2_px_id = L_144;
		goto IL_0305;
	}

IL_02be:
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___2_px_id;
		int32_t L_147;
		L_147 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_146, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_145, L_147, NULL);
		int32_t L_148 = ___2_px_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_148, 1, NULL);
		int32_t L_149 = V_0;
		int32_t L_150;
		L_150 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_149, NULL);
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_150, 1, NULL);
		int32_t L_151 = ___0_root_id;
		int32_t L_152 = ___2_px_id;
		int32_t L_153 = ___3_mainTreeNodeID;
		int32_t L_154;
		L_154 = RBTree_1_RightRotate_m1A016E445613E4751340CAC167426D95944FCAB2(__this, L_151, L_152, L_153, NULL);
		___0_root_id = L_154;
		int32_t L_155 = ___0_root_id;
		if (!L_155)
		{
			goto IL_02f4;
		}
	}
	{
		int32_t L_156 = ___0_root_id;
		G_B56_0 = L_156;
		goto IL_02fa;
	}

IL_02f4:
	{
		int32_t L_157 = __this->___root;
		G_B56_0 = L_157;
	}

IL_02fa:
	{
		___1_x_id = G_B56_0;
		int32_t L_158 = ___1_x_id;
		int32_t L_159;
		L_159 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_158, NULL);
		___2_px_id = L_159;
	}

IL_0305:
	{
		int32_t L_160 = ___0_root_id;
		if (!L_160)
		{
			goto IL_030b;
		}
	}
	{
		int32_t L_161 = ___0_root_id;
		G_B60_0 = L_161;
		goto IL_0311;
	}

IL_030b:
	{
		int32_t L_162 = __this->___root;
		G_B60_0 = L_162;
	}

IL_0311:
	{
		int32_t L_163 = ___1_x_id;
		if ((((int32_t)G_B60_0) == ((int32_t)L_163)))
		{
			goto IL_0321;
		}
	}
	{
		int32_t L_164 = ___1_x_id;
		int32_t L_165;
		L_165 = RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684(__this, L_164, NULL);
		if ((((int32_t)L_165) == ((int32_t)1)))
		{
			goto IL_000e;
		}
	}

IL_0321:
	{
		int32_t L_166 = ___1_x_id;
		RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371(__this, L_166, 1, NULL);
		int32_t L_167 = ___0_root_id;
		return L_167;
	}
}
// Method Definition Index: 60768
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_root_id, int32_t ___1_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B10_0 = 0;
	{
		int32_t L_0 = ___0_root_id;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_1 = __this->____accessMethod;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0014;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)17), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_root_id;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_4 = ___0_root_id;
		G_B6_0 = L_4;
		goto IL_0020;
	}

IL_001a:
	{
		int32_t L_5 = __this->___root;
		G_B6_0 = L_5;
	}

IL_0020:
	{
		V_0 = G_B6_0;
		goto IL_005e;
	}

IL_0023:
	{
		int32_t L_6 = ___0_root_id;
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_7 = ___1_key;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_8, NULL);
		int32_t L_10;
		L_10 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(6, __this, L_7, L_9);
		G_B10_0 = L_10;
		goto IL_0044;
	}

IL_0036:
	{
		int32_t L_11 = ___1_key;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_12, NULL);
		int32_t L_14;
		L_14 = VirtualFuncInvoker2< int32_t, int32_t, int32_t >::Invoke(5, __this, L_11, L_13);
		G_B10_0 = L_14;
	}

IL_0044:
	{
		V_1 = G_B10_0;
		int32_t L_15 = V_1;
		if (!L_15)
		{
			goto IL_0061;
		}
	}
	{
		int32_t L_16 = V_1;
		if ((((int32_t)L_16) >= ((int32_t)0)))
		{
			goto IL_0056;
		}
	}
	{
		int32_t L_17 = V_0;
		int32_t L_18;
		L_18 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_17, NULL);
		V_0 = L_18;
		goto IL_005e;
	}

IL_0056:
	{
		int32_t L_19 = V_0;
		int32_t L_20;
		L_20 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_19, NULL);
		V_0 = L_20;
	}

IL_005e:
	{
		int32_t L_21 = V_0;
		if (L_21)
		{
			goto IL_0023;
		}
	}

IL_0061:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 60769
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Item_m6CB743851EBBBD1D9007D28700324EA0002F3107 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 60770
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_2, NULL);
		if (!L_3)
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_4, NULL);
		int32_t L_6 = ___0_key;
		int32_t L_7;
		L_7 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, L_5, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		int32_t L_8 = V_0;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_9;
		memset((&L_9), 0, sizeof(L_9));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_9), L_7, L_8, NULL);
		return L_9;
	}

IL_0027:
	{
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = ___0_key;
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), &L_13);
		bool L_15;
		L_15 = Int32_Equals_m089564150E8AF7C63B419427E2E57E3420659B1B((&V_1), L_14, NULL);
		if (L_15)
		{
			goto IL_0046;
		}
	}
	{
		V_0 = 0;
	}

IL_0046:
	{
		int32_t L_16 = V_0;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_17;
		memset((&L_17), 0, sizeof(L_17));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_17), L_16, 0, NULL);
		return L_17;
	}
}
// Method Definition Index: 60771
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByKey_mB3893DE20533883A9097426F8B65C6548CE78176 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (-1);
		int32_t L_0 = ___0_key;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1;
		L_1 = RBTree_1_GetNodeByKey_mF4FE4024CADC8B1F8FABFA13EACA57E2B6F775F2(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		V_1 = L_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_2 = V_1;
		int32_t L_3 = L_2.____nodeID;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_4 = V_1;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5(__this, L_4, NULL);
		V_0 = L_5;
	}

IL_001a:
	{
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60772
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_node, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_node;
		int32_t L_2;
		L_2 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_1, NULL);
		return L_2;
	}

IL_0010:
	{
		int32_t L_3 = ___0_node;
		int32_t L_4;
		L_4 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_3, NULL);
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = ___0_node;
		int32_t L_6;
		L_6 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_5, NULL);
		return L_6;
	}

IL_0021:
	{
		int32_t L_7 = ___0_node;
		int32_t L_8;
		L_8 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_7, NULL);
		int32_t L_9;
		L_9 = RBTree_1_SearchSubTree_m57C42F24D37D298A0566D530361F03F6F0EB76B2(__this, 0, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		V_0 = L_9;
		int32_t L_10 = V_0;
		int32_t L_11 = ___0_node;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_12 = ___0_node;
		int32_t L_13;
		L_13 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_12, NULL);
		return L_13;
	}

IL_003c:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_14, NULL);
		int32_t L_16 = ___0_node;
		int32_t L_17;
		L_17 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_16, NULL);
		return ((int32_t)il2cpp_codegen_add(L_15, L_17));
	}
}
// Method Definition Index: 60773
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mF59D980A8D9F3D12CFE602F95AFDB04F6F6804C5 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 ___0_path, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_1 = ___0_path;
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_2, NULL);
		return L_3;
	}

IL_0015:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_4 = ___0_path;
		int32_t L_5 = L_4.____mainTreeNodeID;
		if (L_5)
		{
			goto IL_002a;
		}
	}
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_6 = ___0_path;
		int32_t L_7 = L_6.____nodeID;
		int32_t L_8;
		L_8 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_7, NULL);
		return L_8;
	}

IL_002a:
	{
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_9 = ___0_path;
		int32_t L_10 = L_9.____mainTreeNodeID;
		int32_t L_11;
		L_11 = RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087(__this, L_10, NULL);
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_12 = ___0_path;
		int32_t L_13 = L_12.____nodeID;
		int32_t L_14;
		L_14 = RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD(__this, L_13, NULL);
		return ((int32_t)il2cpp_codegen_add(L_11, L_14));
	}
}
// Method Definition Index: 60774
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_mF54D314A27930CDEE19BE0B8DE58C63A7A6DABCD (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, NULL);
		V_0 = L_2;
		goto IL_0037;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_6, NULL);
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_9, NULL);
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_10, NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(L_11, 1))));
	}

IL_0034:
	{
		int32_t L_12 = V_1;
		___0_nodeId = L_12;
	}

IL_0037:
	{
		int32_t L_13 = ___0_nodeId;
		if (L_13)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60775
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m2A8640152375F25E6DFCB524E3C5E3762A819087 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B4_1 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B5_1 = 0;
	int32_t G_B5_2 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, NULL);
		V_0 = L_2;
		goto IL_004f;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05(__this, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_6, NULL);
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_9, NULL);
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_10, NULL);
		int32_t L_12 = V_1;
		int32_t L_13;
		L_13 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_12, NULL);
		if (!L_13)
		{
			G_B4_0 = L_11;
			G_B4_1 = L_8;
			goto IL_0048;
		}
		G_B3_0 = L_11;
		G_B3_1 = L_8;
	}
	{
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_14, NULL);
		int32_t L_16;
		L_16 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_15, NULL);
		G_B5_0 = L_16;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0049;
	}

IL_0048:
	{
		G_B5_0 = 1;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0049:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B5_2, ((int32_t)il2cpp_codegen_add(G_B5_1, G_B5_0))));
	}

IL_004c:
	{
		int32_t L_17 = V_1;
		___0_nodeId = L_17;
	}

IL_004f:
	{
		int32_t L_18 = ___0_nodeId;
		if (L_18)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_19 = V_0;
		return L_19;
	}
}
// Method Definition Index: 60776
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 RBTree_1_GetNodeByIndex_m1925A1C6C371B002EE706C8EDEF3785E4AD148A8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_userIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1 = __this->___root;
		int32_t L_2 = ___0_userIndex;
		int32_t L_3;
		L_3 = RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064(__this, L_1, ((int32_t)il2cpp_codegen_add(L_2, 1)), NULL);
		V_0 = L_3;
		V_1 = 0;
		goto IL_0026;
	}

IL_001c:
	{
		int32_t L_4 = ___0_userIndex;
		int32_t L_5;
		L_5 = RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751(__this, L_4, (&V_1), NULL);
		V_0 = L_5;
	}

IL_0026:
	{
		int32_t L_6 = V_0;
		if (L_6)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_7 = __this->____accessMethod;
		if ((!(((uint32_t)2) == ((uint32_t)L_7))))
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_8 = ___0_userIndex;
		Exception_t* L_9;
		L_9 = ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054(L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0039:
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0041:
	{
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		NodePath_tB9AD0BDC7882A6AFDAB81BD2039E0C5F7BEEEF50 L_13;
		memset((&L_13), 0, sizeof(L_13));
		NodePath__ctor_m0FCF723AFBBA0142B8DC33B243EC222D8B3840F3((&L_13), L_11, L_12, NULL);
		return L_13;
	}
}
// Method Definition Index: 60777
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m6AC21A1EB09BF6660EF47F4D771F47534F2F9751 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_index;
		___0_index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t* L_1 = ___1_satelliteRootId;
		*(L_1) = 0;
		int32_t L_2 = __this->___root;
		V_0 = L_2;
		V_1 = (-1);
		goto IL_0088;
	}

IL_0013:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = V_1;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_5, NULL);
		V_0 = L_6;
		goto IL_0088;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_7, NULL);
		if (!L_8)
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_11 = ___0_index;
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		int32_t L_14;
		L_14 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_13, NULL);
		int32_t L_15;
		L_15 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_14, NULL);
		if ((((int32_t)L_11) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_12, L_15)), 1)))))
		{
			goto IL_005b;
		}
	}
	{
		int32_t* L_16 = ___1_satelliteRootId;
		int32_t L_17 = V_0;
		*(L_16) = L_17;
		int32_t L_18 = ___0_index;
		int32_t L_19 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_18, L_19)), 1));
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_20, NULL);
		int32_t L_22 = ___0_index;
		int32_t L_23;
		L_23 = RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064(__this, L_21, L_22, NULL);
		return L_23;
	}

IL_005b:
	{
		int32_t L_24 = V_0;
		int32_t L_25;
		L_25 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_24, NULL);
		if (L_25)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_26 = ___0_index;
		int32_t L_27 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_26, L_27));
		goto IL_0080;
	}

IL_006b:
	{
		int32_t L_28 = ___0_index;
		int32_t L_29 = V_1;
		int32_t L_30 = V_0;
		int32_t L_31;
		L_31 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_30, NULL);
		int32_t L_32;
		L_32 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_31, NULL);
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_28, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_29, L_32)), 1))));
	}

IL_0080:
	{
		int32_t L_33 = V_0;
		int32_t L_34;
		L_34 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_33, NULL);
		V_0 = L_34;
	}

IL_0088:
	{
		int32_t L_35 = V_0;
		if (!L_35)
		{
			goto IL_00ae;
		}
	}
	{
		int32_t L_36 = V_0;
		int32_t L_37;
		L_37 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_36, NULL);
		int32_t L_38;
		L_38 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_37, NULL);
		int32_t L_39 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		V_1 = L_39;
		int32_t L_40 = ___0_index;
		if ((!(((uint32_t)L_39) == ((uint32_t)L_40))))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_41 = V_0;
		int32_t L_42;
		L_42 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_41, NULL);
		if (L_42)
		{
			goto IL_0013;
		}
	}

IL_00ae:
	{
		int32_t L_43 = V_0;
		return L_43;
	}
}
// Method Definition Index: 60778
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m1A87F9210DD3BF7304196AFC2FF45D6E3A507064 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		goto IL_002f;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_2, NULL);
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
		int32_t L_4 = ___1_index;
		int32_t L_5 = V_1;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_6 = V_0;
		___0_x_id = L_6;
		goto IL_002f;
	}

IL_001d:
	{
		int32_t L_7 = V_1;
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_9 = ___0_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_9, NULL);
		___0_x_id = L_10;
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_1;
		___1_index = ((int32_t)il2cpp_codegen_subtract(L_11, L_12));
	}

IL_002f:
	{
		int32_t L_13 = ___0_x_id;
		if (L_13)
		{
			goto IL_0002;
		}
	}

IL_0032:
	{
		int32_t L_14 = ___0_x_id;
		return L_14;
	}
}
// Method Definition Index: 60779
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m42434109EC7D9962C6C5C151208BB39B7F503419 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60780
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Add_m89D1F5C6465A94C01A47855B3966C06B69E55969 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60781
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_GetEnumerator_m69FD7C9F88127D1B135BFEA11640F79995101010 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 L_0;
		memset((&L_0), 0, sizeof(L_0));
		RBTreeEnumerator__ctor_m2733AFDE89B7B2489A1BDA8AED77CB198FB6AE6E((&L_0), __this, NULL);
		RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 56), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 60782
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		int32_t L_0 = ___0_nodeId;
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_1 = ___0_nodeId;
		int32_t L_2;
		L_2 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_1, NULL);
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), &L_3);
		int32_t L_5 = ___1_item;
		int32_t L_6 = L_5;
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), &L_6);
		if ((!(((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(RuntimeObject*)L_7))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_GetIndexByNode_m88D61B019FE6CFCFF5BA5E43320983A7019BC297(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 58));
		return L_9;
	}

IL_0021:
	{
		int32_t L_10 = ___0_nodeId;
		int32_t L_11;
		L_11 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_10, NULL);
		int32_t L_12 = ___1_item;
		int32_t L_13;
		L_13 = RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74(__this, L_11, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59));
		int32_t L_14 = L_13;
		V_0 = L_14;
		if ((((int32_t)L_14) == ((int32_t)(-1))))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_15 = V_0;
		return L_15;
	}

IL_0036:
	{
		int32_t L_16 = ___0_nodeId;
		int32_t L_17;
		L_17 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_16, NULL);
		int32_t L_18 = ___1_item;
		int32_t L_19;
		L_19 = RBTree_1_IndexOf_m1A15AAD706F9931B99D4225D76D45140B09D6F74(__this, L_17, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59));
		int32_t L_20 = L_19;
		V_0 = L_20;
		int32_t L_21 = V_0;
		return L_21;
	}

IL_004b:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 60783
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m0A0F524F3BD046708BD7A5DB13A4AA939D96D31C (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		int32_t L_1 = ___1_item;
		int32_t L_2;
		L_2 = RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F(__this, L_0, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 60));
		return L_2;
	}
}
// Method Definition Index: 60784
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mC52B6134B733A4D25B2F3621177144038C005B4F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, int32_t ___1_item, bool ___2_append, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_mF0CCB84B822853BFDC6AFE48116DDA1F77F10568(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = ___0_position;
		bool L_4 = ___2_append;
		int32_t L_5;
		L_5 = RBTree_1_RBInsert_m0B2330653BCF5430989431DAC32328E6EBBAED4E(__this, 0, L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60785
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RemoveAt_m08FF17CF03AA93867AE42791691F967386AFB716 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_position, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		int32_t L_1;
		L_1 = RBTree_1_DeleteByIndex_m46F2E47E9EE4CDEB58E225ED10A54A4C31F485B6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 61));
		return;
	}
}
// Method Definition Index: 60786
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Clear_m2FC29230F5DF876A67B0ABDCA2D2DE205166C385 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_InitTree_mCF091A660A304A14A09AB4C817AF26E1585EA323(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		return;
	}
}
// Method Definition Index: 60787
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m8A396AD86818911F4C70E42BB8969FC6584093A3 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, NULL);
		V_0 = L_4;
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = il2cpp_codegen_array_get_length(L_5);
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_003a;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003a:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_10, NULL);
		V_1 = L_11;
		V_2 = 0;
		goto IL_006c;
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		int32_t L_13 = V_1;
		int32_t L_14;
		L_14 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_13, NULL);
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), &L_15);
		int32_t L_17 = ___1_index;
		int32_t L_18 = V_2;
		NullCheck(L_12);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_12, L_16, ((int32_t)il2cpp_codegen_add(L_17, L_18)), NULL);
		int32_t L_19 = V_1;
		int32_t L_20;
		L_20 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_19, NULL);
		V_1 = L_20;
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_006c:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004b;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60788
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_mF41FDE1C3EB16CBA24B3F43FB7590B27E8612500 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, NULL);
		V_0 = L_4;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_mD78C552E837675F90BD804EFADB6BC40A38C0615(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_0037;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0037:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m504331C88F6C6D70AA7930B661AC172AC26E1844(__this, L_10, NULL);
		V_1 = L_11;
		V_2 = 0;
		goto IL_0064;
	}

IL_0048:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = ___0_array;
		int32_t L_13 = ___1_index;
		int32_t L_14 = V_2;
		int32_t L_15 = V_1;
		int32_t L_16;
		L_16 = RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F(__this, L_15, NULL);
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_13, L_14))), (int32_t)L_16);
		int32_t L_17 = V_1;
		int32_t L_18;
		L_18 = RBTree_1_Successor_mD725A36AE3B97C64315EA2030135F2ED92601A7B(__this, L_17, NULL);
		V_1 = L_18;
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0064:
	{
		int32_t L_20 = V_2;
		int32_t L_21 = V_0;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0048;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60789
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mBC9FDABD04C4A2B8FA6E287A81438D7F24F7FA45 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_rightNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId = L_6;
		return;
	}
}
// Method Definition Index: 60790
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_mDCACA1C77E796D3D23C3A427748B9DA4AEE9B063 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_leftNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId = L_6;
		return;
	}
}
// Method Definition Index: 60791
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m955260FD345744AA0C78140873543D61C26739A9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_parentNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId = L_6;
		return;
	}
}
// Method Definition Index: 60792
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m3427CDE0656DB57DB7017969F2EE84ADC7321371 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_color;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor = L_6;
		return;
	}
}
// Method Definition Index: 60793
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m7EE967D4DCC21DDB6089A25C8995DAA2F4E192F9 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_key;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode = L_6;
		return;
	}
}
// Method Definition Index: 60794
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mAB9FEB9D8ACFE1EDE55AEE4F0C1BCDE38A6411F8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_nextNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId = L_6;
		return;
	}
}
// Method Definition Index: 60795
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mE0A9485E7AEEE896700585182F68187A4EF18D55 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_size;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize = L_6;
		return;
	}
}
// Method Definition Index: 60796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m613975F4AD06761B3DD9F26BC8162B71413A26C8 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *(L_7);
		*(L_7) = ((int32_t)il2cpp_codegen_add(L_8, 1));
		return;
	}
}
// Method Definition Index: 60797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mE849917C6B9CE571D95FFA5AE30E1E7CDB24310A (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_1, NULL);
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB(__this, L_3, NULL);
		int32_t L_5;
		L_5 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_4, NULL);
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_6, NULL);
		if (!L_7)
		{
			G_B2_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
			goto IL_0033;
		}
		G_B1_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6(__this, L_8, NULL);
		int32_t L_10;
		L_10 = RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320(__this, L_9, NULL);
		G_B3_0 = L_10;
		G_B3_1 = G_B1_0;
		goto IL_0034;
	}

IL_0033:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0034:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B3_1, G_B3_0));
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_11 = __this->____pageTable;
		int32_t L_12 = ___0_nodeId;
		NullCheck(L_11);
		int32_t L_13 = ((int32_t)(L_12>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_15 = L_14->____slots;
		int32_t L_16 = ___0_nodeId;
		NullCheck(L_15);
		int32_t L_17 = V_0;
		((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_16&((int32_t)65535))))))->____subTreeSize = L_17;
		return;
	}
}
// Method Definition Index: 60798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m2CC82F8846D718DBC61F565C78775A068556E52F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *(L_7);
		*(L_7) = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		return;
	}
}
// Method Definition Index: 60799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m109C825BA5A4ED378099E461DD8F3088625644BB (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId;
		return L_6;
	}
}
// Method Definition Index: 60800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m9828F525CE984D062ABC3DF1093D4DBD2364EC8D (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId;
		return L_6;
	}
}
// Method Definition Index: 60801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_mC5ACB29D707525AE6F38468A55AFCDAF295C7F05 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId;
		return L_6;
	}
}
// Method Definition Index: 60802
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m730B55D54D0250705A277D3760EE34E096F01684 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor;
		return L_6;
	}
}
// Method Definition Index: 60803
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_m333CBBD7AEE95D283F7AB44D46162030DDA68CA6 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId;
		return L_6;
	}
}
// Method Definition Index: 60804
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m70BBB82CBEC3F4EE83B7EAA032C884CE60A09320 (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize;
		return L_6;
	}
}
// Method Definition Index: 60805
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Key_m46412EE917172B8E3BDF590F1D916A4D6083E22F (RBTree_1_t8713B62AA89A0F1666C324D828FF52CBB922114D* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_tB25FFE4FB4871036F7C74BBC7587290FAE80CDC3* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_t3C1F7E0D55CA26D09BE28D15CDB2D9D6D0D180D7* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9A048A3F7EEEBFF785C128A6FBAA7559BA9060BA* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60745
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1__ctor_mB1EAE820984022B1FAA81A64D531D3EB6F6E8571_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_accessMethod, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_accessMethod;
		__this->____accessMethod = L_0;
		RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
// Method Definition Index: 60746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		__this->___root = 0;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = (TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52*)(TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)32));
		__this->____pageTable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_0);
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_1 = __this->____pageTable;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_2, ((int32_t)32))), 1))/((int32_t)32))));
		__this->____pageTableMap = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_3);
		__this->____inUsePageCount = 0;
		__this->____nextFreePageLine = 0;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_4;
		L_4 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_5 = __this->____pageTable;
		NullCheck(L_5);
		int32_t L_6 = 0;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(L_7);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_8 = L_7->____slots;
		NullCheck(L_8);
		((L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->____nodeColor = (int32_t)1;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_9 = __this->____pageTable;
		NullCheck(L_9);
		int32_t L_10 = 0;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_11 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		NullCheck(L_11);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = L_11->____slotMap;
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(0), (int32_t)1);
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_13 = __this->____pageTable;
		NullCheck(L_13);
		int32_t L_14 = 0;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_15 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		TreePage_set_InUseCount_mFF2D7912FE4FB51AD029F4EA6EB15567F19A425D_inline(L_15, 1, NULL);
		__this->____inUseNodeCount = 1;
		__this->____inUseSatelliteTreeCount = 0;
		return;
	}
}
// Method Definition Index: 60747
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m02920F187E1C52D2A7E325B08685D3BC171A55F9_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_0 = ___0_page;
		RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672(__this, L_0, NULL);
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_1 = __this->____pageTable;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_2 = ___0_page;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_2, NULL);
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, NULL);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)NULL);
		int32_t L_4 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		return;
	}
}
// Method Definition Index: 60748
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710(__this, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_0029;
		}
	}
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_2 = __this->____pageTable;
		int32_t L_3 = V_0;
		int32_t L_4 = ___0_size;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_5 = (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		TreePage__ctor_m8441E60D204F8F3B8FBF96726C918F8BFD088BD5(L_5, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)L_5);
		int32_t L_6 = V_0;
		__this->____nextFreePageLine = ((int32_t)(L_6/((int32_t)32)));
		goto IL_00a9;
	}

IL_0029:
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_7 = __this->____pageTable;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_9 = (TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52*)(TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)il2cpp_codegen_multiply(L_8, 2)));
		V_1 = L_9;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_10 = __this->____pageTable;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_11 = V_1;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_12 = __this->____pageTable;
		NullCheck(L_12);
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_12)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, 0, (RuntimeArray*)L_11, 0, L_13, NULL);
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_14 = V_1;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_15, ((int32_t)32))), 1))/((int32_t)32))));
		V_2 = L_16;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = __this->____pageTableMap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_19 = __this->____pageTableMap;
		NullCheck(L_19);
		int32_t L_20 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_19)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_17, 0, (RuntimeArray*)L_18, 0, L_20, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_21 = __this->____pageTableMap;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		__this->____nextFreePageLine = L_22;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_23 = __this->____pageTable;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		V_0 = L_24;
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_25 = V_1;
		__this->____pageTable = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_25);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_26 = V_2;
		__this->____pageTableMap = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_26);
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_27 = __this->____pageTable;
		int32_t L_28 = V_0;
		int32_t L_29 = ___0_size;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_30 = (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		TreePage__ctor_m8441E60D204F8F3B8FBF96726C918F8BFD088BD5(L_30, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)L_30);
	}

IL_00a9:
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_31 = __this->____pageTable;
		int32_t L_32 = V_0;
		NullCheck(L_31);
		int32_t L_33 = L_32;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_34 = (L_31)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		int32_t L_35 = V_0;
		NullCheck(L_34);
		TreePage_set_PageId_mFE29414DE74DE5AABA637BC8EE4168D233DC19A7_inline(L_34, L_35, NULL);
		int32_t L_36 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_add(L_36, 1));
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_37 = __this->____pageTable;
		int32_t L_38 = V_0;
		NullCheck(L_37);
		int32_t L_39 = L_38;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_40 = (L_37)->GetAt(static_cast<il2cpp_array_size_t>(L_39));
		return L_40;
	}
}
// Method Definition Index: 60749
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFull_mC5C22ADF52DD1D5CC81247F63F85E0612C05BBFB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_5, NULL);
		*(L_3) = ((int32_t)(L_4|((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))));
		return;
	}
}
// Method Definition Index: 60750
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_5, NULL);
		*(L_3) = ((int32_t)(L_4&((~((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))))));
		return;
	}
}
// Method Definition Index: 60751
// Method Definition Index: 60752
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		V_0 = L_3;
		int32_t L_4 = ___0_nodeId;
		V_1 = ((int32_t)(L_4&((int32_t)65535)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_5 = V_0;
		NullCheck(L_5);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_6 = L_5->____slots;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		il2cpp_codegen_initobj(((L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7))), sizeof(Node_t299905C052EE0D8A835E38326073B23299A2B8A1));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_8 = V_0;
		NullCheck(L_8);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = L_8->____slotMap;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		int32_t* L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_10/((int32_t)32))))));
		int32_t L_12 = *(L_11);
		int32_t L_13 = V_1;
		*(L_11) = ((int32_t)(L_12&((~((int32_t)(1<<((int32_t)(((int32_t)(L_13%((int32_t)32)))&((int32_t)31)))))))));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_14 = V_0;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_15 = L_14;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = TreePage_get_InUseCount_mB47BCDDF9F5A3D9F15D5491982B20F7088EA9557_inline(L_15, NULL);
		V_2 = L_16;
		int32_t L_17 = V_2;
		NullCheck(L_15);
		TreePage_set_InUseCount_mFF2D7912FE4FB51AD029F4EA6EB15567F19A425D_inline(L_15, ((int32_t)il2cpp_codegen_subtract(L_17, 1)), NULL);
		int32_t L_18 = __this->____inUseNodeCount;
		__this->____inUseNodeCount = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_19 = V_0;
		NullCheck(L_19);
		int32_t L_20;
		L_20 = TreePage_get_InUseCount_mB47BCDDF9F5A3D9F15D5491982B20F7088EA9557_inline(L_19, NULL);
		if (L_20)
		{
			goto IL_0071;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_21 = V_0;
		RBTree_1_FreePage_m02920F187E1C52D2A7E325B08685D3BC171A55F9(__this, L_21, NULL);
		return;
	}

IL_0071:
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23;
		L_23 = TreePage_get_InUseCount_mB47BCDDF9F5A3D9F15D5491982B20F7088EA9557_inline(L_22, NULL);
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_24 = V_0;
		NullCheck(L_24);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_25 = L_24->____slots;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((!(((uint32_t)L_23) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_26, 1))))))
		{
			goto IL_008a;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_27 = V_0;
		RBTree_1_MarkPageFree_m5546C110128A1D0E80DC9D74B0425E7ACFAA9672(__this, L_27, NULL);
	}

IL_008a:
	{
		return;
	}
}
// Method Definition Index: 60753
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, bool ___0_allocatedPage, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	uint32_t V_3 = 0;
	{
		int32_t L_0 = __this->____nextFreePageLine;
		V_0 = L_0;
		V_1 = (-1);
		goto IL_0073;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____pageTableMap;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if ((!(((uint32_t)L_4) < ((uint32_t)(-1)))))
		{
			goto IL_006f;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____pageTableMap;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_2 = L_8;
		goto IL_006a;
	}

IL_0021:
	{
		uint32_t L_9 = V_2;
		uint32_t L_10 = V_2;
		V_3 = ((int32_t)(((~((int32_t)L_9)))&((int32_t)il2cpp_codegen_add((int32_t)L_10, 1))));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____pageTableMap;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		uint32_t L_16 = V_3;
		uint64_t L_17 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_16,NULL));
		if (!((int64_t)(L_15&(int64_t)L_17)))
		{
			goto IL_003d;
		}
	}
	{
		Exception_t* L_18;
		L_18 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(3, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_18, method);
	}

IL_003d:
	{
		int32_t L_19 = V_0;
		uint32_t L_20 = V_3;
		int32_t L_21;
		L_21 = RBTree_1_GetIntValueFromBitMap_m2A2C58CFA901D39A02C233D0BF42F3D7EFB44540(L_20, NULL);
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_19, ((int32_t)32))), L_21));
		bool L_22 = ___0_allocatedPage;
		if (!L_22)
		{
			goto IL_0058;
		}
	}
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_23 = __this->____pageTable;
		int32_t L_24 = V_1;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		if (!L_26)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_27 = V_1;
		return L_27;
	}

IL_0058:
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_28 = __this->____pageTable;
		int32_t L_29 = V_1;
		NullCheck(L_28);
		int32_t L_30 = L_29;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_31 = (L_28)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		if (L_31)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_32 = V_1;
		return L_32;
	}

IL_0064:
	{
		V_1 = (-1);
		uint32_t L_33 = V_2;
		uint32_t L_34 = V_3;
		V_2 = ((int32_t)((int32_t)L_33|(int32_t)L_34));
	}

IL_006a:
	{
		uint32_t L_35 = V_2;
		if (((int32_t)((int32_t)L_35^(-1))))
		{
			goto IL_0021;
		}
	}

IL_006f:
	{
		int32_t L_36 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_0073:
	{
		int32_t L_37 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_38 = __this->____pageTableMap;
		NullCheck(L_38);
		int32_t L_39 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_38)->max_length),NULL));
		if ((((int32_t)L_37) < ((int32_t)L_39)))
		{
			goto IL_000b;
		}
	}
	{
		int32_t L_40 = __this->____nextFreePageLine;
		if (!L_40)
		{
			goto IL_0095;
		}
	}
	{
		__this->____nextFreePageLine = 0;
		bool L_41 = ___0_allocatedPage;
		int32_t L_42;
		L_42 = RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710(__this, L_41, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_42;
	}

IL_0095:
	{
		int32_t L_43 = V_1;
		return L_43;
	}
}
// Method Definition Index: 60754
// Method Definition Index: 60755
// Method Definition Index: 60756
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = (TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD*)NULL;
		int32_t L_0;
		L_0 = RBTree_1_GetIndexOfPageWithFreeSlot_m0379C10FF75C8AED424C8E0D9A5834A18BEBE710(__this, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_0;
		int32_t L_1 = V_1;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001c;
		}
	}
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_2 = __this->____pageTable;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_0 = L_5;
		goto IL_00a5;
	}

IL_001c:
	{
		int32_t L_6 = __this->____inUsePageCount;
		if ((((int32_t)L_6) >= ((int32_t)4)))
		{
			goto IL_0030;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_7;
		L_7 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_7;
		goto IL_00a5;
	}

IL_0030:
	{
		int32_t L_8 = __this->____inUsePageCount;
		if ((((int32_t)L_8) >= ((int32_t)((int32_t)32))))
		{
			goto IL_0048;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_9;
		L_9 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)256), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_9;
		goto IL_00a5;
	}

IL_0048:
	{
		int32_t L_10 = __this->____inUsePageCount;
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)128))))
		{
			goto IL_0063;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_11;
		L_11 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)1024), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_11;
		goto IL_00a5;
	}

IL_0063:
	{
		int32_t L_12 = __this->____inUsePageCount;
		if ((((int32_t)L_12) >= ((int32_t)((int32_t)4096))))
		{
			goto IL_007e;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_13;
		L_13 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)4096), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_13;
		goto IL_00a5;
	}

IL_007e:
	{
		int32_t L_14 = __this->____inUsePageCount;
		if ((((int32_t)L_14) >= ((int32_t)((int32_t)32768))))
		{
			goto IL_0099;
		}
	}
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_15;
		L_15 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)8192), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_15;
		goto IL_00a5;
	}

IL_0099:
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_16;
		L_16 = RBTree_1_AllocPage_m84FC966EA9AFC28ED05DA34CC22340CD10A486FB(__this, ((int32_t)65536), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_16;
	}

IL_00a5:
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18;
		L_18 = TreePage_AllocSlot_m03CBA01A6EC2A97DA8820AF6BA061837EF01856D(L_17, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		V_2 = L_18;
		int32_t L_19 = V_2;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_00b8;
		}
	}
	{
		Exception_t* L_20;
		L_20 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_00b8:
	{
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_21 = V_0;
		NullCheck(L_21);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_22 = L_21->____slots;
		int32_t L_23 = V_2;
		NullCheck(L_22);
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_24 = V_0;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = TreePage_get_PageId_m2959421A31AD502FB660044B7F735EAA89824FB2_inline(L_24, NULL);
		int32_t L_26 = V_2;
		((L_22)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_23)))->____selfId = ((int32_t)(((int32_t)(L_25<<((int32_t)16)))|L_26));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_27 = V_0;
		NullCheck(L_27);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_28 = L_27->____slots;
		int32_t L_29 = V_2;
		NullCheck(L_28);
		((L_28)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_29)))->____subTreeSize = 1;
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_30 = V_0;
		NullCheck(L_30);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_31 = L_30->____slots;
		int32_t L_32 = V_2;
		NullCheck(L_31);
		Il2CppSharedGenericObject* L_33 = ___0_key;
		((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode = L_33;
		Il2CppCodeGenWriteBarrier((void**)(&((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32)))->____keyOfNode), (void*)L_33);
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_34 = V_0;
		NullCheck(L_34);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_35 = L_34->____slots;
		int32_t L_36 = V_2;
		NullCheck(L_35);
		int32_t L_37 = ((L_35)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_36)))->____selfId;
		return L_37;
	}
}
// Method Definition Index: 60757
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_2, NULL);
		int32_t L_4;
		L_4 = RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712(__this, L_3, NULL);
		return L_4;
	}

IL_0017:
	{
		int32_t L_5 = ___0_x_id;
		int32_t L_6;
		L_6 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_5, NULL);
		V_0 = L_6;
		goto IL_002c;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		___0_x_id = L_7;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_8, NULL);
		V_0 = L_9;
	}

IL_002c:
	{
		int32_t L_10 = V_0;
		if (!L_10)
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_11 = ___0_x_id;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_12, NULL);
		if ((((int32_t)L_11) == ((int32_t)L_13)))
		{
			goto IL_0021;
		}
	}

IL_0039:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60758
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mD782B968CE5256E83614B6E8445F37F5F9A9592B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___0_nodeId;
		int32_t L_1 = *(L_0);
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t* L_2 = ___0_nodeId;
		int32_t* L_3 = ___1_mainTreeNodeId;
		int32_t L_4 = *(L_3);
		int32_t L_5;
		L_5 = RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712(__this, L_4, NULL);
		*(L_2) = L_5;
		int32_t* L_6 = ___1_mainTreeNodeId;
		*(L_6) = 0;
		goto IL_0032;
	}

IL_0013:
	{
		int32_t* L_7 = ___0_nodeId;
		int32_t* L_8 = ___0_nodeId;
		int32_t L_9 = *(L_8);
		int32_t L_10;
		L_10 = RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62(__this, L_9, NULL);
		*(L_7) = L_10;
		int32_t* L_11 = ___0_nodeId;
		int32_t L_12 = *(L_11);
		if (L_12)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_13 = ___1_mainTreeNodeId;
		int32_t L_14 = *(L_13);
		if (!L_14)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_15 = ___0_nodeId;
		int32_t* L_16 = ___1_mainTreeNodeId;
		int32_t L_17 = *(L_16);
		int32_t L_18;
		L_18 = RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62(__this, L_17, NULL);
		*(L_15) = L_18;
		int32_t* L_19 = ___1_mainTreeNodeId;
		*(L_19) = 0;
	}

IL_0032:
	{
		int32_t* L_20 = ___0_nodeId;
		int32_t L_21 = *(L_20);
		if (!L_21)
		{
			goto IL_0062;
		}
	}
	{
		int32_t* L_22 = ___0_nodeId;
		int32_t L_23 = *(L_22);
		int32_t L_24;
		L_24 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_23, NULL);
		if (!L_24)
		{
			goto IL_0060;
		}
	}
	{
		int32_t* L_25 = ___1_mainTreeNodeId;
		int32_t L_26 = *(L_25);
		if (!L_26)
		{
			goto IL_004c;
		}
	}
	{
		Exception_t* L_27;
		L_27 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)21), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_27, method);
	}

IL_004c:
	{
		int32_t* L_28 = ___1_mainTreeNodeId;
		int32_t* L_29 = ___0_nodeId;
		int32_t L_30 = *(L_29);
		*(L_28) = L_30;
		int32_t* L_31 = ___0_nodeId;
		int32_t* L_32 = ___0_nodeId;
		int32_t L_33 = *(L_32);
		int32_t L_34;
		L_34 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_33, NULL);
		int32_t L_35;
		L_35 = RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712(__this, L_34, NULL);
		*(L_31) = L_35;
	}

IL_0060:
	{
		return (bool)1;
	}

IL_0062:
	{
		return (bool)0;
	}
}
// Method Definition Index: 60759
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000b;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		___0_x_id = L_1;
	}

IL_000b:
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_2, NULL);
		if (L_3)
		{
			goto IL_0002;
		}
	}
	{
		int32_t L_4 = ___0_x_id;
		return L_4;
	}
}
// Method Definition Index: 60760
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_3, NULL);
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_2, L_4, NULL);
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_7, NULL);
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_8, L_9, NULL);
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_11, NULL);
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_10, L_12, NULL);
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_13, NULL);
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_17, L_18, NULL);
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		Il2CppSharedGenericObject* L_21;
		L_21 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_20, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_19, L_21, NULL);
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_24, NULL);
		int32_t L_26;
		L_26 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_25, NULL);
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_27, NULL);
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_28, L_29, NULL);
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_30, NULL);
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_31, L_32, NULL);
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_33, L_34, NULL);
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_35, L_36, NULL);
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_39, NULL);
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_40, NULL);
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_43, NULL);
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_45, NULL);
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_47, NULL);
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_48, NULL);
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), NULL);
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_52, NULL);
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_53, NULL);
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_55, NULL);
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_56, NULL);
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_58, NULL);
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_60, NULL);
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_61, NULL);
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), NULL);
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60761
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_3, NULL);
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_2, L_4, NULL);
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_7, NULL);
		int32_t L_9 = ___1_x_id;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_8, L_9, NULL);
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_11, NULL);
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_10, L_12, NULL);
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_13, NULL);
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_17, L_18, NULL);
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		Il2CppSharedGenericObject* L_21;
		L_21 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_20, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_19, L_21, NULL);
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_24, NULL);
		int32_t L_26;
		L_26 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_25, NULL);
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_27, NULL);
		int32_t L_29 = V_0;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_28, L_29, NULL);
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_30, NULL);
		int32_t L_32 = V_0;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_31, L_32, NULL);
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_33, L_34, NULL);
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_35, L_36, NULL);
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_39, NULL);
		int32_t L_41;
		L_41 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_40, NULL);
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_43, NULL);
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_45, NULL);
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_47, NULL);
		int32_t L_49;
		L_49 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_48, NULL);
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), NULL);
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_52, NULL);
		int32_t L_54;
		L_54 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_53, NULL);
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_55, NULL);
		int32_t L_57;
		L_57 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_56, NULL);
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_58, NULL);
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_60, NULL);
		int32_t L_62;
		L_62 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_61, NULL);
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), NULL);
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60762
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B54_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		V_0 = 0;
		int32_t L_1 = ___0_root_id;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_2 = ___0_root_id;
		G_B3_0 = L_2;
		goto IL_001c;
	}

IL_0016:
	{
		int32_t L_3 = __this->___root;
		G_B3_0 = L_3;
	}

IL_001c:
	{
		V_1 = G_B3_0;
		int32_t L_4 = __this->____accessMethod;
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_01f8;
		}
	}
	{
		bool L_5 = ___4_append;
		if (L_5)
		{
			goto IL_01f8;
		}
	}
	{
		goto IL_01f0;
	}

IL_0035:
	{
		int32_t L_6 = V_1;
		RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A(__this, L_6, NULL);
		int32_t L_7 = V_1;
		V_0 = L_7;
		int32_t L_8 = ___0_root_id;
		if (!L_8)
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_9 = ___1_x_id;
		Il2CppSharedGenericObject* L_10;
		L_10 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_9, NULL);
		int32_t L_11 = V_1;
		Il2CppSharedGenericObject* L_12;
		L_12 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_11, NULL);
		int32_t L_13;
		L_13 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(6, __this, L_10, L_12);
		G_B9_0 = L_13;
		goto IL_006b;
	}

IL_0057:
	{
		int32_t L_14 = ___1_x_id;
		Il2CppSharedGenericObject* L_15;
		L_15 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_14, NULL);
		int32_t L_16 = V_1;
		Il2CppSharedGenericObject* L_17;
		L_17 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_16, NULL);
		int32_t L_18;
		L_18 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(5, __this, L_15, L_17);
		G_B9_0 = L_18;
	}

IL_006b:
	{
		V_2 = G_B9_0;
		int32_t L_19 = V_2;
		if ((((int32_t)L_19) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_20 = V_1;
		int32_t L_21;
		L_21 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_20, NULL);
		V_1 = L_21;
		goto IL_01f0;
	}

IL_007d:
	{
		int32_t L_22 = V_2;
		if ((((int32_t)L_22) <= ((int32_t)0)))
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_23 = V_1;
		int32_t L_24;
		L_24 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_23, NULL);
		V_1 = L_24;
		goto IL_01f0;
	}

IL_008e:
	{
		int32_t L_25 = ___0_root_id;
		if (!L_25)
		{
			goto IL_0098;
		}
	}
	{
		Exception_t* L_26;
		L_26 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_26, method);
	}

IL_0098:
	{
		int32_t L_27 = V_1;
		int32_t L_28;
		L_28 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_27, NULL);
		if (!L_28)
		{
			goto IL_00cd;
		}
	}
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_29, NULL);
		int32_t L_31 = ___1_x_id;
		int32_t L_32 = V_1;
		int32_t L_33;
		L_33 = RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE(__this, L_30, L_31, L_32, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_33;
		int32_t L_34 = V_1;
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_35, NULL);
		Il2CppSharedGenericObject* L_37;
		L_37 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_36, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_34, L_37, NULL);
		goto IL_01ee;
	}

IL_00cd:
	{
		V_3 = 0;
		int32_t L_38 = V_1;
		Il2CppSharedGenericObject* L_39;
		L_39 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_38, NULL);
		int32_t L_40;
		L_40 = RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542(__this, L_39, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_3 = L_40;
		int32_t L_41 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = V_3;
		int32_t L_43 = V_1;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_42, L_43, NULL);
		int32_t L_44 = V_3;
		int32_t L_45 = V_1;
		int32_t L_46;
		L_46 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_45, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_44, L_46, NULL);
		int32_t L_47 = V_3;
		int32_t L_48 = V_1;
		int32_t L_49;
		L_49 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_48, NULL);
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_47, L_49, NULL);
		int32_t L_50 = V_3;
		int32_t L_51 = V_1;
		int32_t L_52;
		L_52 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_51, NULL);
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_50, L_52, NULL);
		int32_t L_53 = V_3;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_54, NULL);
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_53, L_55, NULL);
		int32_t L_56 = V_1;
		int32_t L_57;
		L_57 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_56, NULL);
		int32_t L_58;
		L_58 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_57, NULL);
		int32_t L_59 = V_1;
		if ((!(((uint32_t)L_58) == ((uint32_t)L_59))))
		{
			goto IL_014b;
		}
	}
	{
		int32_t L_60 = V_1;
		int32_t L_61;
		L_61 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_60, NULL);
		int32_t L_62 = V_3;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_61, L_62, NULL);
		goto IL_0169;
	}

IL_014b:
	{
		int32_t L_63 = V_1;
		int32_t L_64;
		L_64 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_63, NULL);
		int32_t L_65;
		L_65 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_64, NULL);
		int32_t L_66 = V_1;
		if ((!(((uint32_t)L_65) == ((uint32_t)L_66))))
		{
			goto IL_0169;
		}
	}
	{
		int32_t L_67 = V_1;
		int32_t L_68;
		L_68 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_67, NULL);
		int32_t L_69 = V_3;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_68, L_69, NULL);
	}

IL_0169:
	{
		int32_t L_70 = V_1;
		int32_t L_71;
		L_71 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_70, NULL);
		if (!L_71)
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_72 = V_1;
		int32_t L_73;
		L_73 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_72, NULL);
		int32_t L_74 = V_3;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_73, L_74, NULL);
	}

IL_0180:
	{
		int32_t L_75 = V_1;
		int32_t L_76;
		L_76 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_75, NULL);
		if (!L_76)
		{
			goto IL_0197;
		}
	}
	{
		int32_t L_77 = V_1;
		int32_t L_78;
		L_78 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_77, NULL);
		int32_t L_79 = V_3;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_78, L_79, NULL);
	}

IL_0197:
	{
		int32_t L_80 = __this->___root;
		int32_t L_81 = V_1;
		if ((!(((uint32_t)L_80) == ((uint32_t)L_81))))
		{
			goto IL_01a7;
		}
	}
	{
		int32_t L_82 = V_3;
		__this->___root = L_82;
	}

IL_01a7:
	{
		int32_t L_83 = V_1;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_83, (int32_t)1, NULL);
		int32_t L_84 = V_1;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_84, 0, NULL);
		int32_t L_85 = V_1;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_85, 0, NULL);
		int32_t L_86 = V_1;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_86, 0, NULL);
		int32_t L_87 = V_1;
		int32_t L_88;
		L_88 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_87, NULL);
		V_4 = L_88;
		int32_t L_89 = V_1;
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(__this, L_89, 1, NULL);
		int32_t L_90 = V_1;
		int32_t L_91 = ___1_x_id;
		int32_t L_92 = V_3;
		int32_t L_93;
		L_93 = RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE(__this, L_90, L_91, L_92, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_93;
		int32_t L_94 = V_3;
		int32_t L_95 = V_4;
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(__this, L_94, L_95, NULL);
	}

IL_01ee:
	{
		int32_t L_96 = ___0_root_id;
		return L_96;
	}

IL_01f0:
	{
		int32_t L_97 = V_1;
		if (L_97)
		{
			goto IL_0035;
		}
	}
	{
		goto IL_0263;
	}

IL_01f8:
	{
		int32_t L_98 = __this->____accessMethod;
		bool L_99 = ___4_append;
		if (!((int32_t)(((((int32_t)L_98) == ((int32_t)2))? 1 : 0)|(int32_t)L_99)))
		{
			goto IL_025b;
		}
	}
	{
		int32_t L_100 = ___3_position;
		if ((!(((uint32_t)L_100) == ((uint32_t)(-1)))))
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_101 = __this->___root;
		int32_t L_102;
		L_102 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_101, NULL);
		___3_position = L_102;
		goto IL_0256;
	}

IL_021b:
	{
		int32_t L_103 = V_1;
		RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A(__this, L_103, NULL);
		int32_t L_104 = V_1;
		V_0 = L_104;
		int32_t L_105 = ___3_position;
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_106, NULL);
		int32_t L_108;
		L_108 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_107, NULL);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_105, L_108));
		int32_t L_109 = V_5;
		if ((((int32_t)L_109) > ((int32_t)0)))
		{
			goto IL_0245;
		}
	}
	{
		int32_t L_110 = V_1;
		int32_t L_111;
		L_111 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_110, NULL);
		V_1 = L_111;
		goto IL_0256;
	}

IL_0245:
	{
		int32_t L_112 = V_1;
		int32_t L_113;
		L_113 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_112, NULL);
		V_1 = L_113;
		int32_t L_114 = V_1;
		if (!L_114)
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_115 = V_5;
		___3_position = ((int32_t)il2cpp_codegen_subtract(L_115, 1));
	}

IL_0256:
	{
		int32_t L_116 = V_1;
		if (L_116)
		{
			goto IL_021b;
		}
	}
	{
		goto IL_0263;
	}

IL_025b:
	{
		Exception_t* L_117;
		L_117 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)15), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_117, method);
	}

IL_0263:
	{
		int32_t L_118 = ___1_x_id;
		int32_t L_119 = V_0;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_118, L_119, NULL);
		int32_t L_120 = V_0;
		if (L_120)
		{
			goto IL_0298;
		}
	}
	{
		int32_t L_121 = ___0_root_id;
		if (L_121)
		{
			goto IL_027d;
		}
	}
	{
		int32_t L_122 = ___1_x_id;
		__this->___root = L_122;
		goto IL_030a;
	}

IL_027d:
	{
		int32_t L_123 = ___2_mainTreeNodeID;
		int32_t L_124 = ___1_x_id;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_123, L_124, NULL);
		int32_t L_125 = ___2_mainTreeNodeID;
		int32_t L_126 = ___1_x_id;
		Il2CppSharedGenericObject* L_127;
		L_127 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_126, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_125, L_127, NULL);
		int32_t L_128 = ___1_x_id;
		___0_root_id = L_128;
		goto IL_030a;
	}

IL_0298:
	{
		V_6 = 0;
		int32_t L_129 = __this->____accessMethod;
		if ((!(((uint32_t)L_129) == ((uint32_t)1))))
		{
			goto IL_02d5;
		}
	}
	{
		int32_t L_130 = ___0_root_id;
		if (!L_130)
		{
			goto IL_02bd;
		}
	}
	{
		int32_t L_131 = ___1_x_id;
		Il2CppSharedGenericObject* L_132;
		L_132 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_131, NULL);
		int32_t L_133 = V_0;
		Il2CppSharedGenericObject* L_134;
		L_134 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_133, NULL);
		int32_t L_135;
		L_135 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(6, __this, L_132, L_134);
		G_B49_0 = L_135;
		goto IL_02d1;
	}

IL_02bd:
	{
		int32_t L_136 = ___1_x_id;
		Il2CppSharedGenericObject* L_137;
		L_137 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_136, NULL);
		int32_t L_138 = V_0;
		Il2CppSharedGenericObject* L_139;
		L_139 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_138, NULL);
		int32_t L_140;
		L_140 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(5, __this, L_137, L_139);
		G_B49_0 = L_140;
	}

IL_02d1:
	{
		V_6 = G_B49_0;
		goto IL_02f3;
	}

IL_02d5:
	{
		int32_t L_141 = __this->____accessMethod;
		if ((!(((uint32_t)L_141) == ((uint32_t)2))))
		{
			goto IL_02eb;
		}
	}
	{
		int32_t L_142 = ___3_position;
		if ((((int32_t)L_142) <= ((int32_t)0)))
		{
			goto IL_02e6;
		}
	}
	{
		G_B54_0 = 1;
		goto IL_02e7;
	}

IL_02e6:
	{
		G_B54_0 = (-1);
	}

IL_02e7:
	{
		V_6 = G_B54_0;
		goto IL_02f3;
	}

IL_02eb:
	{
		Exception_t* L_143;
		L_143 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)16), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_143, method);
	}

IL_02f3:
	{
		int32_t L_144 = V_6;
		if ((((int32_t)L_144) >= ((int32_t)0)))
		{
			goto IL_0302;
		}
	}
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___1_x_id;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_145, L_146, NULL);
		goto IL_030a;
	}

IL_0302:
	{
		int32_t L_147 = V_0;
		int32_t L_148 = ___1_x_id;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_147, L_148, NULL);
	}

IL_030a:
	{
		int32_t L_149 = ___1_x_id;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_149, 0, NULL);
		int32_t L_150 = ___1_x_id;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_150, 0, NULL);
		int32_t L_151 = ___1_x_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_151, (int32_t)0, NULL);
		int32_t L_152 = ___1_x_id;
		V_1 = L_152;
		goto IL_04ba;
	}

IL_0329:
	{
		int32_t L_153 = ___1_x_id;
		int32_t L_154;
		L_154 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_153, NULL);
		int32_t L_155 = ___1_x_id;
		int32_t L_156;
		L_156 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_155, NULL);
		int32_t L_157;
		L_157 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_156, NULL);
		int32_t L_158;
		L_158 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_157, NULL);
		if ((!(((uint32_t)L_154) == ((uint32_t)L_158))))
		{
			goto IL_0405;
		}
	}
	{
		int32_t L_159 = ___1_x_id;
		int32_t L_160;
		L_160 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_159, NULL);
		int32_t L_161;
		L_161 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_160, NULL);
		int32_t L_162;
		L_162 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_161, NULL);
		V_0 = L_162;
		int32_t L_163 = V_0;
		int32_t L_164;
		L_164 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_163, NULL);
		if (L_164)
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_165 = ___1_x_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_165, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_166, (int32_t)1, NULL);
		int32_t L_167 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_167, (int32_t)1, NULL);
		int32_t L_168 = ___1_x_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_168, NULL);
		int32_t L_170;
		L_170 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_169, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_170, (int32_t)0, NULL);
		int32_t L_171 = ___1_x_id;
		int32_t L_172;
		L_172 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_171, NULL);
		int32_t L_173;
		L_173 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_172, NULL);
		___1_x_id = L_173;
		goto IL_04ba;
	}

IL_03a3:
	{
		int32_t L_174 = ___1_x_id;
		int32_t L_175 = ___1_x_id;
		int32_t L_176;
		L_176 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_175, NULL);
		int32_t L_177;
		L_177 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_176, NULL);
		if ((!(((uint32_t)L_174) == ((uint32_t)L_177))))
		{
			goto IL_03c7;
		}
	}
	{
		int32_t L_178 = ___1_x_id;
		int32_t L_179;
		L_179 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_178, NULL);
		___1_x_id = L_179;
		int32_t L_180 = ___0_root_id;
		int32_t L_181 = ___1_x_id;
		int32_t L_182 = ___2_mainTreeNodeID;
		int32_t L_183;
		L_183 = RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895(__this, L_180, L_181, L_182, NULL);
		___0_root_id = L_183;
	}

IL_03c7:
	{
		int32_t L_184 = ___1_x_id;
		int32_t L_185;
		L_185 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_184, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_185, (int32_t)1, NULL);
		int32_t L_186 = ___1_x_id;
		int32_t L_187;
		L_187 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_186, NULL);
		int32_t L_188;
		L_188 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_187, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_188, (int32_t)0, NULL);
		int32_t L_189 = ___0_root_id;
		int32_t L_190 = ___1_x_id;
		int32_t L_191;
		L_191 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_190, NULL);
		int32_t L_192;
		L_192 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_191, NULL);
		int32_t L_193 = ___2_mainTreeNodeID;
		int32_t L_194;
		L_194 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_189, L_192, L_193, NULL);
		___0_root_id = L_194;
		goto IL_04ba;
	}

IL_0405:
	{
		int32_t L_195 = ___1_x_id;
		int32_t L_196;
		L_196 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_195, NULL);
		int32_t L_197;
		L_197 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_196, NULL);
		int32_t L_198;
		L_198 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_197, NULL);
		V_0 = L_198;
		int32_t L_199 = V_0;
		int32_t L_200;
		L_200 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_199, NULL);
		if (L_200)
		{
			goto IL_045d;
		}
	}
	{
		int32_t L_201 = ___1_x_id;
		int32_t L_202;
		L_202 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_201, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_202, (int32_t)1, NULL);
		int32_t L_203 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_203, (int32_t)1, NULL);
		int32_t L_204 = ___1_x_id;
		int32_t L_205;
		L_205 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_204, NULL);
		int32_t L_206;
		L_206 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_205, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_206, (int32_t)0, NULL);
		int32_t L_207 = ___1_x_id;
		int32_t L_208;
		L_208 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_207, NULL);
		int32_t L_209;
		L_209 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_208, NULL);
		___1_x_id = L_209;
		goto IL_04ba;
	}

IL_045d:
	{
		int32_t L_210 = ___1_x_id;
		int32_t L_211 = ___1_x_id;
		int32_t L_212;
		L_212 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_211, NULL);
		int32_t L_213;
		L_213 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_212, NULL);
		if ((!(((uint32_t)L_210) == ((uint32_t)L_213))))
		{
			goto IL_0481;
		}
	}
	{
		int32_t L_214 = ___1_x_id;
		int32_t L_215;
		L_215 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_214, NULL);
		___1_x_id = L_215;
		int32_t L_216 = ___0_root_id;
		int32_t L_217 = ___1_x_id;
		int32_t L_218 = ___2_mainTreeNodeID;
		int32_t L_219;
		L_219 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_216, L_217, L_218, NULL);
		___0_root_id = L_219;
	}

IL_0481:
	{
		int32_t L_220 = ___1_x_id;
		int32_t L_221;
		L_221 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_220, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_221, (int32_t)1, NULL);
		int32_t L_222 = ___1_x_id;
		int32_t L_223;
		L_223 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_222, NULL);
		int32_t L_224;
		L_224 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_223, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_224, (int32_t)0, NULL);
		int32_t L_225 = ___0_root_id;
		int32_t L_226 = ___1_x_id;
		int32_t L_227;
		L_227 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_226, NULL);
		int32_t L_228;
		L_228 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_227, NULL);
		int32_t L_229 = ___2_mainTreeNodeID;
		int32_t L_230;
		L_230 = RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895(__this, L_225, L_228, L_229, NULL);
		___0_root_id = L_230;
	}

IL_04ba:
	{
		int32_t L_231 = ___1_x_id;
		int32_t L_232;
		L_232 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_231, NULL);
		int32_t L_233;
		L_233 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_232, NULL);
		if (!L_233)
		{
			goto IL_0329;
		}
	}
	{
		int32_t L_234 = ___0_root_id;
		if (L_234)
		{
			goto IL_04de;
		}
	}
	{
		int32_t L_235 = __this->___root;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_235, (int32_t)1, NULL);
		goto IL_04e6;
	}

IL_04de:
	{
		int32_t L_236 = ___0_root_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_236, (int32_t)1, NULL);
	}

IL_04e6:
	{
		int32_t L_237 = ___0_root_id;
		return L_237;
	}
}
// Method Definition Index: 60763
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_UpdateNodeKey_mC7638F81552D081E1FA0F1FB2E2633779E30064B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_currentKey, Il2CppSharedGenericObject* ___1_newKey, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Il2CppSharedGenericObject* L_0 = ___0_currentKey;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_1;
		L_1 = RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		V_0 = L_1;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_3, NULL);
		if (L_4)
		{
			goto IL_0031;
		}
	}
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		int32_t L_7 = __this->___root;
		if ((((int32_t)L_6) == ((int32_t)L_7)))
		{
			goto IL_0031;
		}
	}
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_8 = V_0;
		int32_t L_9 = L_8.____mainTreeNodeID;
		Il2CppSharedGenericObject* L_10 = ___1_newKey;
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_9, L_10, NULL);
	}

IL_0031:
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_11 = V_0;
		int32_t L_12 = L_11.____nodeID;
		Il2CppSharedGenericObject* L_13 = ___1_newKey;
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_12, L_13, NULL);
		return;
	}
}
// Method Definition Index: 60764
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTree_1_DeleteByIndex_m66215488DD926BD6C06D66BC1DEC77A2E4AFA36F_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_i, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_i;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_1;
		L_1 = RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		V_0 = L_1;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		Il2CppSharedGenericObject* L_4;
		L_4 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_3, NULL);
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_7 = V_0;
		int32_t L_8 = L_7.____mainTreeNodeID;
		int32_t L_9;
		L_9 = RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97(__this, 0, L_6, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_4;
	}
}
// Method Definition Index: 60765
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDelete_mE8A094CE2C78213D05809F099C0076865B4BD8D3_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_z_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_z_id;
		int32_t L_1;
		L_1 = RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97(__this, 0, L_0, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_1;
	}
}
// Method Definition Index: 60766
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t G_B5_0 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___1_z_id;
		int32_t L_1;
		L_1 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = ___1_z_id;
		int32_t L_3;
		L_3 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_2, NULL);
		int32_t L_4 = ___1_z_id;
		int32_t L_5;
		L_5 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_4, NULL);
		int32_t L_6 = ___1_z_id;
		int32_t L_7;
		L_7 = RBTree_1_RBDeleteX_mE94B389E8A2683A020564C9EEF29CA2B6A3D9E97(__this, L_3, L_5, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_7;
	}

IL_0021:
	{
		V_3 = (bool)0;
		int32_t L_8 = __this->____accessMethod;
		if ((((int32_t)L_8) == ((int32_t)1)))
		{
			goto IL_002f;
		}
	}
	{
		int32_t L_9 = ___1_z_id;
		G_B5_0 = L_9;
		goto IL_0030;
	}

IL_002f:
	{
		int32_t L_10 = ___2_mainTreeNodeID;
		G_B5_0 = L_10;
	}

IL_0030:
	{
		V_4 = G_B5_0;
		int32_t L_11 = V_4;
		int32_t L_12;
		L_12 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_11, NULL);
		if (!L_12)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_13 = V_4;
		int32_t L_14;
		L_14 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_13, NULL);
		___0_root_id = L_14;
	}

IL_0046:
	{
		int32_t L_15 = V_4;
		int32_t L_16;
		L_16 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_15, NULL);
		int32_t L_17;
		L_17 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_16, NULL);
		if ((!(((uint32_t)L_17) == ((uint32_t)2))))
		{
			goto IL_005b;
		}
	}
	{
		V_3 = (bool)1;
		goto IL_0073;
	}

IL_005b:
	{
		int32_t L_18 = V_4;
		int32_t L_19;
		L_19 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_18, NULL);
		int32_t L_20;
		L_20 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_19, NULL);
		if ((!(((uint32_t)L_20) == ((uint32_t)1))))
		{
			goto IL_0073;
		}
	}
	{
		Exception_t* L_21;
		L_21 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(7, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_21, method);
	}

IL_0073:
	{
		int32_t L_22 = ___1_z_id;
		int32_t L_23;
		L_23 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_22, NULL);
		if (!L_23)
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_24 = ___1_z_id;
		int32_t L_25;
		L_25 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_24, NULL);
		if (L_25)
		{
			goto IL_0089;
		}
	}

IL_0085:
	{
		int32_t L_26 = ___1_z_id;
		V_1 = L_26;
		goto IL_0091;
	}

IL_0089:
	{
		int32_t L_27 = ___1_z_id;
		int32_t L_28;
		L_28 = RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62(__this, L_27, NULL);
		V_1 = L_28;
	}

IL_0091:
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_29, NULL);
		if (!L_30)
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_31 = V_1;
		int32_t L_32;
		L_32 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_31, NULL);
		V_0 = L_32;
		goto IL_00ac;
	}

IL_00a4:
	{
		int32_t L_33 = V_1;
		int32_t L_34;
		L_34 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_33, NULL);
		V_0 = L_34;
	}

IL_00ac:
	{
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_35, NULL);
		V_2 = L_36;
		int32_t L_37 = V_0;
		if (!L_37)
		{
			goto IL_00bf;
		}
	}
	{
		int32_t L_38 = V_0;
		int32_t L_39 = V_2;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_38, L_39, NULL);
	}

IL_00bf:
	{
		int32_t L_40 = V_2;
		if (L_40)
		{
			goto IL_00d3;
		}
	}
	{
		int32_t L_41 = ___0_root_id;
		if (L_41)
		{
			goto IL_00ce;
		}
	}
	{
		int32_t L_42 = V_0;
		__this->___root = L_42;
		goto IL_00ef;
	}

IL_00ce:
	{
		int32_t L_43 = V_0;
		___0_root_id = L_43;
		goto IL_00ef;
	}

IL_00d3:
	{
		int32_t L_44 = V_1;
		int32_t L_45 = V_2;
		int32_t L_46;
		L_46 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_45, NULL);
		if ((!(((uint32_t)L_44) == ((uint32_t)L_46))))
		{
			goto IL_00e7;
		}
	}
	{
		int32_t L_47 = V_2;
		int32_t L_48 = V_0;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_47, L_48, NULL);
		goto IL_00ef;
	}

IL_00e7:
	{
		int32_t L_49 = V_2;
		int32_t L_50 = V_0;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_49, L_50, NULL);
	}

IL_00ef:
	{
		int32_t L_51 = V_1;
		int32_t L_52 = ___1_z_id;
		if ((((int32_t)L_51) == ((int32_t)L_52)))
		{
			goto IL_010f;
		}
	}
	{
		int32_t L_53 = ___1_z_id;
		int32_t L_54 = V_1;
		Il2CppSharedGenericObject* L_55;
		L_55 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_54, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_53, L_55, NULL);
		int32_t L_56 = ___1_z_id;
		int32_t L_57 = V_1;
		int32_t L_58;
		L_58 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_57, NULL);
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_56, L_58, NULL);
	}

IL_010f:
	{
		int32_t L_59 = V_4;
		int32_t L_60;
		L_60 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_59, NULL);
		if (!L_60)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_61 = ___0_root_id;
		if (L_61)
		{
			goto IL_0128;
		}
	}
	{
		int32_t L_62 = ___1_z_id;
		int32_t L_63 = V_4;
		if ((((int32_t)L_62) == ((int32_t)L_63)))
		{
			goto IL_0128;
		}
	}
	{
		Exception_t* L_64;
		L_64 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_64, method);
	}

IL_0128:
	{
		int32_t L_65 = ___0_root_id;
		if (!L_65)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_66 = V_4;
		int32_t L_67 = ___0_root_id;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_66, L_67, NULL);
		int32_t L_68 = V_4;
		int32_t L_69 = ___0_root_id;
		Il2CppSharedGenericObject* L_70;
		L_70 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_69, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_68, L_70, NULL);
	}

IL_0143:
	{
		int32_t L_71 = V_2;
		V_5 = L_71;
		goto IL_015a;
	}

IL_0148:
	{
		int32_t L_72 = V_5;
		RBTree_1_RecomputeSize_mDBB0AAF0158D6FC0172754C8F2BFD25191BC86E8(__this, L_72, NULL);
		int32_t L_73 = V_5;
		int32_t L_74;
		L_74 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_73, NULL);
		V_5 = L_74;
	}

IL_015a:
	{
		int32_t L_75 = V_5;
		if (L_75)
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_76 = ___0_root_id;
		if (!L_76)
		{
			goto IL_017d;
		}
	}
	{
		int32_t L_77 = V_4;
		V_6 = L_77;
		goto IL_0179;
	}

IL_0167:
	{
		int32_t L_78 = V_6;
		RBTree_1_DecreaseSize_m719AA62C29CBC6C387F371FB1D5D1E5C584ABA7B(__this, L_78, NULL);
		int32_t L_79 = V_6;
		int32_t L_80;
		L_80 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_79, NULL);
		V_6 = L_80;
	}

IL_0179:
	{
		int32_t L_81 = V_6;
		if (L_81)
		{
			goto IL_0167;
		}
	}

IL_017d:
	{
		int32_t L_82 = V_1;
		int32_t L_83;
		L_83 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_82, NULL);
		if ((!(((uint32_t)L_83) == ((uint32_t)1))))
		{
			goto IL_0193;
		}
	}
	{
		int32_t L_84 = ___0_root_id;
		int32_t L_85 = V_0;
		int32_t L_86 = V_2;
		int32_t L_87 = ___2_mainTreeNodeID;
		int32_t L_88;
		L_88 = RBTree_1_RBDeleteFixup_mF9C058080B3A889E3839D76BEDCFBC6BC0EC02D6(__this, L_84, L_85, L_86, L_87, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
		___0_root_id = L_88;
	}

IL_0193:
	{
		bool L_89 = V_3;
		if (!L_89)
		{
			goto IL_02af;
		}
	}
	{
		int32_t L_90 = V_4;
		if (!L_90)
		{
			goto IL_01ae;
		}
	}
	{
		int32_t L_91 = V_4;
		int32_t L_92;
		L_92 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_91, NULL);
		int32_t L_93;
		L_93 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_92, NULL);
		if ((((int32_t)L_93) == ((int32_t)1)))
		{
			goto IL_01b6;
		}
	}

IL_01ae:
	{
		Exception_t* L_94;
		L_94 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)9), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_94, method);
	}

IL_01b6:
	{
		int32_t L_95 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_subtract(L_95, 1));
		int32_t L_96 = V_4;
		int32_t L_97;
		L_97 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_96, NULL);
		V_7 = L_97;
		int32_t L_98 = V_7;
		int32_t L_99 = V_4;
		int32_t L_100;
		L_100 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_99, NULL);
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_98, L_100, NULL);
		int32_t L_101 = V_7;
		int32_t L_102 = V_4;
		int32_t L_103;
		L_103 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_102, NULL);
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_101, L_103, NULL);
		int32_t L_104 = V_7;
		int32_t L_105 = V_4;
		int32_t L_106;
		L_106 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_105, NULL);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(__this, L_104, L_106, NULL);
		int32_t L_107 = V_7;
		int32_t L_108 = V_4;
		int32_t L_109;
		L_109 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_108, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_107, L_109, NULL);
		int32_t L_110 = V_4;
		int32_t L_111;
		L_111 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_110, NULL);
		if (!L_111)
		{
			goto IL_025c;
		}
	}
	{
		int32_t L_112 = V_7;
		int32_t L_113 = V_4;
		int32_t L_114;
		L_114 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_113, NULL);
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_112, L_114, NULL);
		int32_t L_115 = V_4;
		int32_t L_116;
		L_116 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_115, NULL);
		int32_t L_117;
		L_117 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_116, NULL);
		int32_t L_118 = V_4;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_118))))
		{
			goto IL_024c;
		}
	}
	{
		int32_t L_119 = V_4;
		int32_t L_120;
		L_120 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_119, NULL);
		int32_t L_121 = V_7;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_120, L_121, NULL);
		goto IL_025c;
	}

IL_024c:
	{
		int32_t L_122 = V_4;
		int32_t L_123;
		L_123 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_122, NULL);
		int32_t L_124 = V_7;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_123, L_124, NULL);
	}

IL_025c:
	{
		int32_t L_125 = V_4;
		int32_t L_126;
		L_126 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_125, NULL);
		if (!L_126)
		{
			goto IL_0276;
		}
	}
	{
		int32_t L_127 = V_4;
		int32_t L_128;
		L_128 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_127, NULL);
		int32_t L_129 = V_7;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_128, L_129, NULL);
	}

IL_0276:
	{
		int32_t L_130 = V_4;
		int32_t L_131;
		L_131 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_130, NULL);
		if (!L_131)
		{
			goto IL_0290;
		}
	}
	{
		int32_t L_132 = V_4;
		int32_t L_133;
		L_133 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_132, NULL);
		int32_t L_134 = V_7;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_133, L_134, NULL);
	}

IL_0290:
	{
		int32_t L_135 = __this->___root;
		int32_t L_136 = V_4;
		if ((!(((uint32_t)L_135) == ((uint32_t)L_136))))
		{
			goto IL_02a2;
		}
	}
	{
		int32_t L_137 = V_7;
		__this->___root = L_137;
	}

IL_02a2:
	{
		int32_t L_138 = V_4;
		RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21(__this, L_138, NULL);
		V_4 = 0;
		goto IL_02e4;
	}

IL_02af:
	{
		int32_t L_139 = V_4;
		int32_t L_140;
		L_140 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_139, NULL);
		if (!L_140)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		if (L_141)
		{
			goto IL_02c9;
		}
	}
	{
		int32_t L_142 = ___1_z_id;
		int32_t L_143 = V_4;
		if ((((int32_t)L_142) == ((int32_t)L_143)))
		{
			goto IL_02c9;
		}
	}
	{
		Exception_t* L_144;
		L_144 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)10), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_144, method);
	}

IL_02c9:
	{
		int32_t L_145 = ___0_root_id;
		if (!L_145)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_146 = V_4;
		int32_t L_147 = ___0_root_id;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_146, L_147, NULL);
		int32_t L_148 = V_4;
		int32_t L_149 = ___0_root_id;
		Il2CppSharedGenericObject* L_150;
		L_150 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_149, NULL);
		RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B(__this, L_148, L_150, NULL);
	}

IL_02e4:
	{
		int32_t L_151 = V_1;
		int32_t L_152 = ___1_z_id;
		if ((((int32_t)L_151) == ((int32_t)L_152)))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_153 = V_1;
		int32_t L_154 = ___1_z_id;
		int32_t L_155;
		L_155 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_154, NULL);
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_153, L_155, NULL);
		int32_t L_156 = V_1;
		int32_t L_157 = ___1_z_id;
		int32_t L_158;
		L_158 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_157, NULL);
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_156, L_158, NULL);
		int32_t L_159 = V_1;
		int32_t L_160 = ___1_z_id;
		int32_t L_161;
		L_161 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_160, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_159, L_161, NULL);
		int32_t L_162 = V_1;
		int32_t L_163 = ___1_z_id;
		int32_t L_164;
		L_164 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_163, NULL);
		RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5(__this, L_162, L_164, NULL);
		int32_t L_165 = ___1_z_id;
		int32_t L_166;
		L_166 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_165, NULL);
		if (!L_166)
		{
			goto IL_036a;
		}
	}
	{
		int32_t L_167 = V_1;
		int32_t L_168 = ___1_z_id;
		int32_t L_169;
		L_169 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_168, NULL);
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_167, L_169, NULL);
		int32_t L_170 = ___1_z_id;
		int32_t L_171;
		L_171 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_170, NULL);
		int32_t L_172;
		L_172 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_171, NULL);
		int32_t L_173 = ___1_z_id;
		if ((!(((uint32_t)L_172) == ((uint32_t)L_173))))
		{
			goto IL_035a;
		}
	}
	{
		int32_t L_174 = ___1_z_id;
		int32_t L_175;
		L_175 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_174, NULL);
		int32_t L_176 = V_1;
		RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3(__this, L_175, L_176, NULL);
		goto IL_0372;
	}

IL_035a:
	{
		int32_t L_177 = ___1_z_id;
		int32_t L_178;
		L_178 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_177, NULL);
		int32_t L_179 = V_1;
		RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1(__this, L_178, L_179, NULL);
		goto IL_0372;
	}

IL_036a:
	{
		int32_t L_180 = V_1;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_180, 0, NULL);
	}

IL_0372:
	{
		int32_t L_181 = ___1_z_id;
		int32_t L_182;
		L_182 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_181, NULL);
		if (!L_182)
		{
			goto IL_0389;
		}
	}
	{
		int32_t L_183 = ___1_z_id;
		int32_t L_184;
		L_184 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_183, NULL);
		int32_t L_185 = V_1;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_184, L_185, NULL);
	}

IL_0389:
	{
		int32_t L_186 = ___1_z_id;
		int32_t L_187;
		L_187 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_186, NULL);
		if (!L_187)
		{
			goto IL_03a0;
		}
	}
	{
		int32_t L_188 = ___1_z_id;
		int32_t L_189;
		L_189 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_188, NULL);
		int32_t L_190 = V_1;
		RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643(__this, L_189, L_190, NULL);
	}

IL_03a0:
	{
		int32_t L_191 = __this->___root;
		int32_t L_192 = ___1_z_id;
		if ((!(((uint32_t)L_191) == ((uint32_t)L_192))))
		{
			goto IL_03b2;
		}
	}
	{
		int32_t L_193 = V_1;
		__this->___root = L_193;
		goto IL_03b9;
	}

IL_03b2:
	{
		int32_t L_194 = ___0_root_id;
		int32_t L_195 = ___1_z_id;
		if ((!(((uint32_t)L_194) == ((uint32_t)L_195))))
		{
			goto IL_03b9;
		}
	}
	{
		int32_t L_196 = V_1;
		___0_root_id = L_196;
	}

IL_03b9:
	{
		int32_t L_197 = V_4;
		if (!L_197)
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_198 = V_4;
		int32_t L_199;
		L_199 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_198, NULL);
		int32_t L_200 = ___1_z_id;
		if ((!(((uint32_t)L_199) == ((uint32_t)L_200))))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_201 = V_4;
		int32_t L_202 = V_1;
		RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565(__this, L_201, L_202, NULL);
	}

IL_03d1:
	{
		int32_t L_203 = ___1_z_id;
		RBTree_1_FreeNode_m7220658BAE2D8425FEADC3455CD9435D1752BA21(__this, L_203, NULL);
		int32_t L_204 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_204, 1));
		int32_t L_205 = ___1_z_id;
		return L_205;
	}
}
// Method Definition Index: 60767
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_mF9C058080B3A889E3839D76BEDCFBC6BC0EC02D6_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B24_0 = 0;
	int32_t G_B28_0 = 0;
	int32_t G_B34_0 = 0;
	int32_t G_B38_0 = 0;
	int32_t G_B47_0 = 0;
	int32_t G_B52_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B60_0 = 0;
	{
		int32_t L_0 = ___1_x_id;
		if (L_0)
		{
			goto IL_0305;
		}
	}
	{
		int32_t L_1 = ___2_px_id;
		if (L_1)
		{
			goto IL_0305;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		int32_t L_2 = ___1_x_id;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_3 = ___1_x_id;
		int32_t L_4 = ___1_x_id;
		int32_t L_5;
		L_5 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_4, NULL);
		int32_t L_6;
		L_6 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_5, NULL);
		if ((((int32_t)L_3) == ((int32_t)L_6)))
		{
			goto IL_0033;
		}
	}

IL_0021:
	{
		int32_t L_7 = ___1_x_id;
		if (L_7)
		{
			goto IL_0168;
		}
	}
	{
		int32_t L_8 = ___2_px_id;
		int32_t L_9;
		L_9 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_8, NULL);
		if (L_9)
		{
			goto IL_0168;
		}
	}

IL_0033:
	{
		int32_t L_10 = ___1_x_id;
		if (!L_10)
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_11, NULL);
		int32_t L_13;
		L_13 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_12, NULL);
		G_B10_0 = L_13;
		goto IL_004c;
	}

IL_0045:
	{
		int32_t L_14 = ___2_px_id;
		int32_t L_15;
		L_15 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_14, NULL);
		G_B10_0 = L_15;
	}

IL_004c:
	{
		V_0 = G_B10_0;
		int32_t L_16 = V_0;
		if (L_16)
		{
			goto IL_0058;
		}
	}
	{
		Exception_t* L_17;
		L_17 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)14), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_0058:
	{
		int32_t L_18 = V_0;
		int32_t L_19;
		L_19 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_18, NULL);
		if (L_19)
		{
			goto IL_0097;
		}
	}
	{
		int32_t L_20 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_20, (int32_t)1, NULL);
		int32_t L_21 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_21, (int32_t)0, NULL);
		int32_t L_22 = ___0_root_id;
		int32_t L_23 = ___2_px_id;
		int32_t L_24 = ___3_mainTreeNodeID;
		int32_t L_25;
		L_25 = RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895(__this, L_22, L_23, L_24, NULL);
		___0_root_id = L_25;
		int32_t L_26 = ___1_x_id;
		if (!L_26)
		{
			goto IL_008f;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_27, NULL);
		int32_t L_29;
		L_29 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_28, NULL);
		G_B16_0 = L_29;
		goto IL_0096;
	}

IL_008f:
	{
		int32_t L_30 = ___2_px_id;
		int32_t L_31;
		L_31 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_30, NULL);
		G_B16_0 = L_31;
	}

IL_0096:
	{
		V_0 = G_B16_0;
	}

IL_0097:
	{
		int32_t L_32 = V_0;
		int32_t L_33;
		L_33 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_32, NULL);
		int32_t L_34;
		L_34 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_33, NULL);
		if ((!(((uint32_t)L_34) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_35 = V_0;
		int32_t L_36;
		L_36 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_35, NULL);
		int32_t L_37;
		L_37 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_36, NULL);
		if ((!(((uint32_t)L_37) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_38 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_38, (int32_t)0, NULL);
		int32_t L_39 = ___2_px_id;
		___1_x_id = L_39;
		int32_t L_40 = ___2_px_id;
		int32_t L_41;
		L_41 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_40, NULL);
		___2_px_id = L_41;
		goto IL_0305;
	}

IL_00d0:
	{
		int32_t L_42 = V_0;
		int32_t L_43;
		L_43 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_42, NULL);
		int32_t L_44;
		L_44 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_43, NULL);
		if ((!(((uint32_t)L_44) == ((uint32_t)1))))
		{
			goto IL_011c;
		}
	}
	{
		int32_t L_45 = V_0;
		int32_t L_46;
		L_46 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_45, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_46, (int32_t)1, NULL);
		int32_t L_47 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_47, (int32_t)0, NULL);
		int32_t L_48 = ___0_root_id;
		int32_t L_49 = V_0;
		int32_t L_50 = ___3_mainTreeNodeID;
		int32_t L_51;
		L_51 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_48, L_49, L_50, NULL);
		___0_root_id = L_51;
		int32_t L_52 = ___1_x_id;
		if (!L_52)
		{
			goto IL_0114;
		}
	}
	{
		int32_t L_53 = ___1_x_id;
		int32_t L_54;
		L_54 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_53, NULL);
		int32_t L_55;
		L_55 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_54, NULL);
		G_B24_0 = L_55;
		goto IL_011b;
	}

IL_0114:
	{
		int32_t L_56 = ___2_px_id;
		int32_t L_57;
		L_57 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_56, NULL);
		G_B24_0 = L_57;
	}

IL_011b:
	{
		V_0 = G_B24_0;
	}

IL_011c:
	{
		int32_t L_58 = V_0;
		int32_t L_59 = ___2_px_id;
		int32_t L_60;
		L_60 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_59, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_58, L_60, NULL);
		int32_t L_61 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_61, (int32_t)1, NULL);
		int32_t L_62 = V_0;
		int32_t L_63;
		L_63 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_62, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_63, (int32_t)1, NULL);
		int32_t L_64 = ___0_root_id;
		int32_t L_65 = ___2_px_id;
		int32_t L_66 = ___3_mainTreeNodeID;
		int32_t L_67;
		L_67 = RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895(__this, L_64, L_65, L_66, NULL);
		___0_root_id = L_67;
		int32_t L_68 = ___0_root_id;
		if (!L_68)
		{
			goto IL_0152;
		}
	}
	{
		int32_t L_69 = ___0_root_id;
		G_B28_0 = L_69;
		goto IL_0158;
	}

IL_0152:
	{
		int32_t L_70 = __this->___root;
		G_B28_0 = L_70;
	}

IL_0158:
	{
		___1_x_id = G_B28_0;
		int32_t L_71 = ___1_x_id;
		int32_t L_72;
		L_72 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_71, NULL);
		___2_px_id = L_72;
		goto IL_0305;
	}

IL_0168:
	{
		int32_t L_73 = ___2_px_id;
		int32_t L_74;
		L_74 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_73, NULL);
		V_0 = L_74;
		int32_t L_75 = V_0;
		int32_t L_76;
		L_76 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_75, NULL);
		if (L_76)
		{
			goto IL_01ed;
		}
	}
	{
		int32_t L_77 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_77, (int32_t)1, NULL);
		int32_t L_78 = ___1_x_id;
		if (!L_78)
		{
			goto IL_01b4;
		}
	}
	{
		int32_t L_79 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_79, (int32_t)0, NULL);
		int32_t L_80 = ___0_root_id;
		int32_t L_81 = ___2_px_id;
		int32_t L_82 = ___3_mainTreeNodeID;
		int32_t L_83;
		L_83 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_80, L_81, L_82, NULL);
		___0_root_id = L_83;
		int32_t L_84 = ___1_x_id;
		if (!L_84)
		{
			goto IL_01aa;
		}
	}
	{
		int32_t L_85 = ___1_x_id;
		int32_t L_86;
		L_86 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_85, NULL);
		int32_t L_87;
		L_87 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_86, NULL);
		G_B34_0 = L_87;
		goto IL_01b1;
	}

IL_01aa:
	{
		int32_t L_88 = ___2_px_id;
		int32_t L_89;
		L_89 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_88, NULL);
		G_B34_0 = L_89;
	}

IL_01b1:
	{
		V_0 = G_B34_0;
		goto IL_01ed;
	}

IL_01b4:
	{
		int32_t L_90 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_90, (int32_t)0, NULL);
		int32_t L_91 = ___0_root_id;
		int32_t L_92 = ___2_px_id;
		int32_t L_93 = ___3_mainTreeNodeID;
		int32_t L_94;
		L_94 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_91, L_92, L_93, NULL);
		___0_root_id = L_94;
		int32_t L_95 = ___1_x_id;
		if (!L_95)
		{
			goto IL_01da;
		}
	}
	{
		int32_t L_96 = ___1_x_id;
		int32_t L_97;
		L_97 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_96, NULL);
		int32_t L_98;
		L_98 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_97, NULL);
		G_B38_0 = L_98;
		goto IL_01e1;
	}

IL_01da:
	{
		int32_t L_99 = ___2_px_id;
		int32_t L_100;
		L_100 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_99, NULL);
		G_B38_0 = L_100;
	}

IL_01e1:
	{
		V_0 = G_B38_0;
		int32_t L_101 = V_0;
		if (L_101)
		{
			goto IL_01ed;
		}
	}
	{
		Exception_t* L_102;
		L_102 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)11), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_102, method);
	}

IL_01ed:
	{
		int32_t L_103 = V_0;
		int32_t L_104;
		L_104 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_103, NULL);
		int32_t L_105;
		L_105 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_104, NULL);
		if ((!(((uint32_t)L_105) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_106, NULL);
		int32_t L_108;
		L_108 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_107, NULL);
		if ((!(((uint32_t)L_108) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_109 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_109, (int32_t)0, NULL);
		int32_t L_110 = ___2_px_id;
		___1_x_id = L_110;
		int32_t L_111 = ___2_px_id;
		int32_t L_112;
		L_112 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_111, NULL);
		___2_px_id = L_112;
		goto IL_0305;
	}

IL_0226:
	{
		int32_t L_113 = V_0;
		int32_t L_114;
		L_114 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_113, NULL);
		int32_t L_115;
		L_115 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_114, NULL);
		if ((!(((uint32_t)L_115) == ((uint32_t)1))))
		{
			goto IL_0272;
		}
	}
	{
		int32_t L_116 = V_0;
		int32_t L_117;
		L_117 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_116, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_117, (int32_t)1, NULL);
		int32_t L_118 = V_0;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_118, (int32_t)0, NULL);
		int32_t L_119 = ___0_root_id;
		int32_t L_120 = V_0;
		int32_t L_121 = ___3_mainTreeNodeID;
		int32_t L_122;
		L_122 = RBTree_1_LeftRotate_m55B3DB5BA7A99F3CE718200614DD64362EAB0895(__this, L_119, L_120, L_121, NULL);
		___0_root_id = L_122;
		int32_t L_123 = ___1_x_id;
		if (!L_123)
		{
			goto IL_026a;
		}
	}
	{
		int32_t L_124 = ___1_x_id;
		int32_t L_125;
		L_125 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_124, NULL);
		int32_t L_126;
		L_126 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_125, NULL);
		G_B47_0 = L_126;
		goto IL_0271;
	}

IL_026a:
	{
		int32_t L_127 = ___2_px_id;
		int32_t L_128;
		L_128 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_127, NULL);
		G_B47_0 = L_128;
	}

IL_0271:
	{
		V_0 = G_B47_0;
	}

IL_0272:
	{
		int32_t L_129 = ___1_x_id;
		if (!L_129)
		{
			goto IL_02be;
		}
	}
	{
		int32_t L_130 = V_0;
		int32_t L_131 = ___2_px_id;
		int32_t L_132;
		L_132 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_131, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_130, L_132, NULL);
		int32_t L_133 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_133, (int32_t)1, NULL);
		int32_t L_134 = V_0;
		int32_t L_135;
		L_135 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_134, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_135, (int32_t)1, NULL);
		int32_t L_136 = ___0_root_id;
		int32_t L_137 = ___2_px_id;
		int32_t L_138 = ___3_mainTreeNodeID;
		int32_t L_139;
		L_139 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_136, L_137, L_138, NULL);
		___0_root_id = L_139;
		int32_t L_140 = ___0_root_id;
		if (!L_140)
		{
			goto IL_02ab;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		G_B52_0 = L_141;
		goto IL_02b1;
	}

IL_02ab:
	{
		int32_t L_142 = __this->___root;
		G_B52_0 = L_142;
	}

IL_02b1:
	{
		___1_x_id = G_B52_0;
		int32_t L_143 = ___1_x_id;
		int32_t L_144;
		L_144 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_143, NULL);
		___2_px_id = L_144;
		goto IL_0305;
	}

IL_02be:
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___2_px_id;
		int32_t L_147;
		L_147 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_146, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_145, L_147, NULL);
		int32_t L_148 = ___2_px_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_148, (int32_t)1, NULL);
		int32_t L_149 = V_0;
		int32_t L_150;
		L_150 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_149, NULL);
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_150, (int32_t)1, NULL);
		int32_t L_151 = ___0_root_id;
		int32_t L_152 = ___2_px_id;
		int32_t L_153 = ___3_mainTreeNodeID;
		int32_t L_154;
		L_154 = RBTree_1_RightRotate_m3A85A41B4AC50DF21057340613BF2326A29B3E47(__this, L_151, L_152, L_153, NULL);
		___0_root_id = L_154;
		int32_t L_155 = ___0_root_id;
		if (!L_155)
		{
			goto IL_02f4;
		}
	}
	{
		int32_t L_156 = ___0_root_id;
		G_B56_0 = L_156;
		goto IL_02fa;
	}

IL_02f4:
	{
		int32_t L_157 = __this->___root;
		G_B56_0 = L_157;
	}

IL_02fa:
	{
		___1_x_id = G_B56_0;
		int32_t L_158 = ___1_x_id;
		int32_t L_159;
		L_159 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_158, NULL);
		___2_px_id = L_159;
	}

IL_0305:
	{
		int32_t L_160 = ___0_root_id;
		if (!L_160)
		{
			goto IL_030b;
		}
	}
	{
		int32_t L_161 = ___0_root_id;
		G_B60_0 = L_161;
		goto IL_0311;
	}

IL_030b:
	{
		int32_t L_162 = __this->___root;
		G_B60_0 = L_162;
	}

IL_0311:
	{
		int32_t L_163 = ___1_x_id;
		if ((((int32_t)G_B60_0) == ((int32_t)L_163)))
		{
			goto IL_0321;
		}
	}
	{
		int32_t L_164 = ___1_x_id;
		int32_t L_165;
		L_165 = RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912(__this, L_164, NULL);
		if ((((int32_t)L_165) == ((int32_t)1)))
		{
			goto IL_000e;
		}
	}

IL_0321:
	{
		int32_t L_166 = ___1_x_id;
		RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2(__this, L_166, (int32_t)1, NULL);
		int32_t L_167 = ___0_root_id;
		return L_167;
	}
}
// Method Definition Index: 60768
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_root_id, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B10_0 = 0;
	{
		int32_t L_0 = ___0_root_id;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_1 = __this->____accessMethod;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0014;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)17), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_root_id;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_4 = ___0_root_id;
		G_B6_0 = L_4;
		goto IL_0020;
	}

IL_001a:
	{
		int32_t L_5 = __this->___root;
		G_B6_0 = L_5;
	}

IL_0020:
	{
		V_0 = G_B6_0;
		goto IL_005e;
	}

IL_0023:
	{
		int32_t L_6 = ___0_root_id;
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		Il2CppSharedGenericObject* L_7 = ___1_key;
		int32_t L_8 = V_0;
		Il2CppSharedGenericObject* L_9;
		L_9 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_8, NULL);
		int32_t L_10;
		L_10 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(6, __this, L_7, L_9);
		G_B10_0 = L_10;
		goto IL_0044;
	}

IL_0036:
	{
		Il2CppSharedGenericObject* L_11 = ___1_key;
		int32_t L_12 = V_0;
		Il2CppSharedGenericObject* L_13;
		L_13 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_12, NULL);
		int32_t L_14;
		L_14 = VirtualFuncInvoker2< int32_t, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(5, __this, L_11, L_13);
		G_B10_0 = L_14;
	}

IL_0044:
	{
		V_1 = G_B10_0;
		int32_t L_15 = V_1;
		if (!L_15)
		{
			goto IL_0061;
		}
	}
	{
		int32_t L_16 = V_1;
		if ((((int32_t)L_16) >= ((int32_t)0)))
		{
			goto IL_0056;
		}
	}
	{
		int32_t L_17 = V_0;
		int32_t L_18;
		L_18 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_17, NULL);
		V_0 = L_18;
		goto IL_005e;
	}

IL_0056:
	{
		int32_t L_19 = V_0;
		int32_t L_20;
		L_20 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_19, NULL);
		V_0 = L_20;
	}

IL_005e:
	{
		int32_t L_21 = V_0;
		if (L_21)
		{
			goto IL_0023;
		}
	}

IL_0061:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 60769
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTree_1_get_Item_m4DC8D6E83EDAFC2FADEAF6741DDDE35C6FD26842_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_1;
		L_1 = RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		int32_t L_2 = L_1.____nodeID;
		Il2CppSharedGenericObject* L_3;
		L_3 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 60770
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		Il2CppSharedGenericObject* L_0 = ___0_key;
		int32_t L_1;
		L_1 = RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_2, NULL);
		if (!L_3)
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_4, NULL);
		Il2CppSharedGenericObject* L_6 = ___0_key;
		int32_t L_7;
		L_7 = RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D(__this, L_5, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		int32_t L_8 = V_0;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_9;
		memset((&L_9), 0, sizeof(L_9));
		NodePath__ctor_m1C03760E0A5ADF5BAC0DADDF78FC6C6645F15398((&L_9), L_7, L_8, NULL);
		return L_9;
	}

IL_0027:
	{
		int32_t L_10 = V_0;
		Il2CppSharedGenericObject* L_11;
		L_11 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_10, NULL);
		V_1 = L_11;
		Il2CppSharedGenericObject* L_12 = ___0_key;
		NullCheck((RuntimeObject*)(V_1));
		bool L_13;
		L_13 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(0, (RuntimeObject*)(V_1), (RuntimeObject*)L_12);
		if (L_13)
		{
			goto IL_0046;
		}
	}
	{
		V_0 = 0;
	}

IL_0046:
	{
		int32_t L_14 = V_0;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_15;
		memset((&L_15), 0, sizeof(L_15));
		NodePath__ctor_m1C03760E0A5ADF5BAC0DADDF78FC6C6645F15398((&L_15), L_14, 0, NULL);
		return L_15;
	}
}
// Method Definition Index: 60771
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByKey_mF4C827C5F92B0D715455DF10D2DDF8077444B56E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (-1);
		Il2CppSharedGenericObject* L_0 = ___0_key;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_1;
		L_1 = RBTree_1_GetNodeByKey_mB8EA5B24CEF71C3B51691EEE949E3A8E5E11A98A(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41));
		V_1 = L_1;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_2 = V_1;
		int32_t L_3 = L_2.____nodeID;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_4 = V_1;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNodePath_m1E21B59C97F89684CB754FC49B140B3AFCABA6BD(__this, L_4, NULL);
		V_0 = L_5;
	}

IL_001a:
	{
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60772
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m46F19C443609B114C90100EE95489B06D7E0DF9E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_node, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_node;
		int32_t L_2;
		L_2 = RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2(__this, L_1, NULL);
		return L_2;
	}

IL_0010:
	{
		int32_t L_3 = ___0_node;
		int32_t L_4;
		L_4 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_3, NULL);
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = ___0_node;
		int32_t L_6;
		L_6 = RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4(__this, L_5, NULL);
		return L_6;
	}

IL_0021:
	{
		int32_t L_7 = ___0_node;
		Il2CppSharedGenericObject* L_8;
		L_8 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_7, NULL);
		int32_t L_9;
		L_9 = RBTree_1_SearchSubTree_m88D001B41787E2E6D1E2054C4206A65CEFB8F17D(__this, 0, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48));
		V_0 = L_9;
		int32_t L_10 = V_0;
		int32_t L_11 = ___0_node;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_12 = ___0_node;
		int32_t L_13;
		L_13 = RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4(__this, L_12, NULL);
		return L_13;
	}

IL_003c:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4(__this, L_14, NULL);
		int32_t L_16 = ___0_node;
		int32_t L_17;
		L_17 = RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2(__this, L_16, NULL);
		return ((int32_t)il2cpp_codegen_add(L_15, L_17));
	}
}
// Method Definition Index: 60773
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_m1E21B59C97F89684CB754FC49B140B3AFCABA6BD_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF ___0_path, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_1 = ___0_path;
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2(__this, L_2, NULL);
		return L_3;
	}

IL_0015:
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_4 = ___0_path;
		int32_t L_5 = L_4.____mainTreeNodeID;
		if (L_5)
		{
			goto IL_002a;
		}
	}
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_6 = ___0_path;
		int32_t L_7 = L_6.____nodeID;
		int32_t L_8;
		L_8 = RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4(__this, L_7, NULL);
		return L_8;
	}

IL_002a:
	{
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_9 = ___0_path;
		int32_t L_10 = L_9.____mainTreeNodeID;
		int32_t L_11;
		L_11 = RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4(__this, L_10, NULL);
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_12 = ___0_path;
		int32_t L_13 = L_12.____nodeID;
		int32_t L_14;
		L_14 = RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2(__this, L_13, NULL);
		return ((int32_t)il2cpp_codegen_add(L_11, L_14));
	}
}
// Method Definition Index: 60774
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_m8DCD325BA4138BA6D3F73D307F6524B5AF39F4D2_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_1, NULL);
		V_0 = L_2;
		goto IL_0037;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_6, NULL);
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_9, NULL);
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_10, NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(L_11, 1))));
	}

IL_0034:
	{
		int32_t L_12 = V_1;
		___0_nodeId = L_12;
	}

IL_0037:
	{
		int32_t L_13 = ___0_nodeId;
		if (L_13)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60775
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m0932303093ACD655F4A9D131F16ED35D402579C4_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B4_1 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B5_1 = 0;
	int32_t G_B5_2 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_1, NULL);
		V_0 = L_2;
		goto IL_004f;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319(__this, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_6, NULL);
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_9, NULL);
		int32_t L_11;
		L_11 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_10, NULL);
		int32_t L_12 = V_1;
		int32_t L_13;
		L_13 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_12, NULL);
		if (!L_13)
		{
			G_B4_0 = L_11;
			G_B4_1 = L_8;
			goto IL_0048;
		}
		G_B3_0 = L_11;
		G_B3_1 = L_8;
	}
	{
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_14, NULL);
		int32_t L_16;
		L_16 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_15, NULL);
		G_B5_0 = L_16;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0049;
	}

IL_0048:
	{
		G_B5_0 = 1;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0049:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B5_2, ((int32_t)il2cpp_codegen_add(G_B5_1, G_B5_0))));
	}

IL_004c:
	{
		int32_t L_17 = V_1;
		___0_nodeId = L_17;
	}

IL_004f:
	{
		int32_t L_18 = ___0_nodeId;
		if (L_18)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_19 = V_0;
		return L_19;
	}
}
// Method Definition Index: 60776
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF RBTree_1_GetNodeByIndex_m83B266BF5647661945D158A8D908BF95B3A4F517_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_userIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1 = __this->___root;
		int32_t L_2 = ___0_userIndex;
		int32_t L_3;
		L_3 = RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455(__this, L_1, ((int32_t)il2cpp_codegen_add(L_2, 1)), NULL);
		V_0 = L_3;
		V_1 = 0;
		goto IL_0026;
	}

IL_001c:
	{
		int32_t L_4 = ___0_userIndex;
		int32_t L_5;
		L_5 = RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD(__this, L_4, (&V_1), NULL);
		V_0 = L_5;
	}

IL_0026:
	{
		int32_t L_6 = V_0;
		if (L_6)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_7 = __this->____accessMethod;
		if ((!(((uint32_t)2) == ((uint32_t)L_7))))
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_8 = ___0_userIndex;
		Exception_t* L_9;
		L_9 = ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054(L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0039:
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0041:
	{
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		NodePath_t71966ED9436E95A8961841AF77E3F94C1E3F15AF L_13;
		memset((&L_13), 0, sizeof(L_13));
		NodePath__ctor_m1C03760E0A5ADF5BAC0DADDF78FC6C6645F15398((&L_13), L_11, L_12, NULL);
		return L_13;
	}
}
// Method Definition Index: 60777
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m35534B37511AF06371695E0CB5616BDB7E8E8EFD_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_index;
		___0_index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t* L_1 = ___1_satelliteRootId;
		*(L_1) = 0;
		int32_t L_2 = __this->___root;
		V_0 = L_2;
		V_1 = (-1);
		goto IL_0088;
	}

IL_0013:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = V_1;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_5, NULL);
		V_0 = L_6;
		goto IL_0088;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_7, NULL);
		if (!L_8)
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_11 = ___0_index;
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		int32_t L_14;
		L_14 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_13, NULL);
		int32_t L_15;
		L_15 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_14, NULL);
		if ((((int32_t)L_11) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_12, L_15)), 1)))))
		{
			goto IL_005b;
		}
	}
	{
		int32_t* L_16 = ___1_satelliteRootId;
		int32_t L_17 = V_0;
		*(L_16) = L_17;
		int32_t L_18 = ___0_index;
		int32_t L_19 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_18, L_19)), 1));
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_20, NULL);
		int32_t L_22 = ___0_index;
		int32_t L_23;
		L_23 = RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455(__this, L_21, L_22, NULL);
		return L_23;
	}

IL_005b:
	{
		int32_t L_24 = V_0;
		int32_t L_25;
		L_25 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_24, NULL);
		if (L_25)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_26 = ___0_index;
		int32_t L_27 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_26, L_27));
		goto IL_0080;
	}

IL_006b:
	{
		int32_t L_28 = ___0_index;
		int32_t L_29 = V_1;
		int32_t L_30 = V_0;
		int32_t L_31;
		L_31 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_30, NULL);
		int32_t L_32;
		L_32 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_31, NULL);
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_28, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_29, L_32)), 1))));
	}

IL_0080:
	{
		int32_t L_33 = V_0;
		int32_t L_34;
		L_34 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_33, NULL);
		V_0 = L_34;
	}

IL_0088:
	{
		int32_t L_35 = V_0;
		if (!L_35)
		{
			goto IL_00ae;
		}
	}
	{
		int32_t L_36 = V_0;
		int32_t L_37;
		L_37 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_36, NULL);
		int32_t L_38;
		L_38 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_37, NULL);
		int32_t L_39 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		V_1 = L_39;
		int32_t L_40 = ___0_index;
		if ((!(((uint32_t)L_39) == ((uint32_t)L_40))))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_41 = V_0;
		int32_t L_42;
		L_42 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_41, NULL);
		if (L_42)
		{
			goto IL_0013;
		}
	}

IL_00ae:
	{
		int32_t L_43 = V_0;
		return L_43;
	}
}
// Method Definition Index: 60778
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m490DF9A8DC64CF750790A47BD75B4CA32CB99455_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		goto IL_002f;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_2, NULL);
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
		int32_t L_4 = ___1_index;
		int32_t L_5 = V_1;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_6 = V_0;
		___0_x_id = L_6;
		goto IL_002f;
	}

IL_001d:
	{
		int32_t L_7 = V_1;
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_9 = ___0_x_id;
		int32_t L_10;
		L_10 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_9, NULL);
		___0_x_id = L_10;
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_1;
		___1_index = ((int32_t)il2cpp_codegen_subtract(L_11, L_12));
	}

IL_002f:
	{
		int32_t L_13 = ___0_x_id;
		if (L_13)
		{
			goto IL_0002;
		}
	}

IL_0032:
	{
		int32_t L_14 = ___0_x_id;
		return L_14;
	}
}
// Method Definition Index: 60779
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m674D9D719DD69B001F85CF623E11C5662CFB9F02_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60780
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Add_m1FD4415756D9A1621764B014564733DA7439CB74_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60781
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_GetEnumerator_m42B4AD4A4947D36B004375B54B9146492D5EB816_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF L_0;
		memset((&L_0), 0, sizeof(L_0));
		RBTreeEnumerator__ctor_mFF09CA916CAF9842895161A5CCE9B5F6052358DE((&L_0), __this, NULL);
		RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 56), &L_1);
		return (RuntimeObject*)L_2;
	}
}
// Method Definition Index: 60782
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		int32_t L_0 = ___0_nodeId;
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_1 = ___0_nodeId;
		Il2CppSharedGenericObject* L_2;
		L_2 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_1, NULL);
		Il2CppSharedGenericObject* L_3 = ___1_item;
		if ((!(((RuntimeObject*)(Il2CppSharedGenericObject*)L_2) == ((RuntimeObject*)(Il2CppSharedGenericObject*)L_3))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_4 = ___0_nodeId;
		int32_t L_5;
		L_5 = RBTree_1_GetIndexByNode_m46F19C443609B114C90100EE95489B06D7E0DF9E(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 58));
		return L_5;
	}

IL_0021:
	{
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_6, NULL);
		Il2CppSharedGenericObject* L_8 = ___1_item;
		int32_t L_9;
		L_9 = RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E(__this, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59));
		int32_t L_10 = L_9;
		V_0 = L_10;
		if ((((int32_t)L_10) == ((int32_t)(-1))))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_11 = V_0;
		return L_11;
	}

IL_0036:
	{
		int32_t L_12 = ___0_nodeId;
		int32_t L_13;
		L_13 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_12, NULL);
		Il2CppSharedGenericObject* L_14 = ___1_item;
		int32_t L_15;
		L_15 = RBTree_1_IndexOf_m2978B5B3DDBFF5784C495F82EA569F3B67EA926E(__this, L_13, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59));
		int32_t L_16 = L_15;
		V_0 = L_16;
		int32_t L_17 = V_0;
		return L_17;
	}

IL_004b:
	{
		int32_t L_18 = V_0;
		return L_18;
	}
}
// Method Definition Index: 60783
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m55DD22526F20EBD9092A5C9B1EAFD9A4B99DC9FF_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_position, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		Il2CppSharedGenericObject* L_1 = ___1_item;
		int32_t L_2;
		L_2 = RBTree_1_InsertAt_mA323D5F4BBB074C3BB0A5AA90C195952F45836D0(__this, L_0, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 60));
		return L_2;
	}
}
// Method Definition Index: 60784
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_mA323D5F4BBB074C3BB0A5AA90C195952F45836D0_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_position, Il2CppSharedGenericObject* ___1_item, bool ___2_append, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___1_item;
		int32_t L_1;
		L_1 = RBTree_1_GetNewNode_m5863E283C2B738283FF751E044EC017FA269C542(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = ___0_position;
		bool L_4 = ___2_append;
		int32_t L_5;
		L_5 = RBTree_1_RBInsert_m0F7E610495314AF8E43945E519EE8BB599AA74BE(__this, 0, L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60785
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RemoveAt_m6FCA9040299A9638224F4531FF74C5ACB2DB3AD1_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_position, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		Il2CppSharedGenericObject* L_1;
		L_1 = RBTree_1_DeleteByIndex_m66215488DD926BD6C06D66BC1DEC77A2E4AFA36F(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 61));
		return;
	}
}
// Method Definition Index: 60786
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Clear_m2140E8692C5C2E6B07EAA27FAEF1226E11A458AB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RBTree_1_InitTree_mB4E9EFD37104F6D38AB761F3E4D895745AC2D002(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		return;
	}
}
// Method Definition Index: 60787
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m17BA2BF087CD49C3EC42C54748C788B0D36FEE0E_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mCCC9A110FA3CFC5542CD9056AE20466F86C2F39F(__this, NULL);
		V_0 = L_4;
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = il2cpp_codegen_array_get_length(L_5);
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_mCCC9A110FA3CFC5542CD9056AE20466F86C2F39F(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_003a;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003a:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712(__this, L_10, NULL);
		V_1 = L_11;
		V_2 = 0;
		goto IL_006c;
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		int32_t L_13 = V_1;
		Il2CppSharedGenericObject* L_14;
		L_14 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_13, NULL);
		int32_t L_15 = ___1_index;
		int32_t L_16 = V_2;
		NullCheck(L_12);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_12, (RuntimeObject*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), NULL);
		int32_t L_17 = V_1;
		int32_t L_18;
		L_18 = RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62(__this, L_17, NULL);
		V_1 = L_18;
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006c:
	{
		int32_t L_20 = V_2;
		int32_t L_21 = V_0;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_004b;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60788
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m337ED8C9859880431EBED7067A6F40ADDAA31626_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = RBTree_1_get_Count_mCCC9A110FA3CFC5542CD9056AE20466F86C2F39F(__this, NULL);
		V_0 = L_4;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = RBTree_1_get_Count_mCCC9A110FA3CFC5542CD9056AE20466F86C2F39F(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_0037;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0037:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = RBTree_1_Minimum_m92638EC28D7B4C793E87489440C5381402073712(__this, L_10, NULL);
		V_1 = L_11;
		V_2 = 0;
		goto IL_0064;
	}

IL_0048:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = ___0_array;
		int32_t L_13 = ___1_index;
		int32_t L_14 = V_2;
		int32_t L_15 = V_1;
		Il2CppSharedGenericObject* L_16;
		L_16 = RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99(__this, L_15, NULL);
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_13, L_14))), (Il2CppSharedGenericObject*)L_16);
		int32_t L_17 = V_1;
		int32_t L_18;
		L_18 = RBTree_1_Successor_m66C0B2AECF8F8BFE3CF4E25F4995C30C80474F62(__this, L_17, NULL);
		V_1 = L_18;
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0064:
	{
		int32_t L_20 = V_2;
		int32_t L_21 = V_0;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0048;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60789
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_mCA90AE8051905DE68BD794277CB3A6F4D7273ED1_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_rightNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId = L_6;
		return;
	}
}
// Method Definition Index: 60790
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_m1053D96D9AE2E6EBF34B5C1D9A449C5531FA59B3_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_leftNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId = L_6;
		return;
	}
}
// Method Definition Index: 60791
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_m5CA27D9474EC84E5A8823FE803C60CC047572643_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_parentNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId = L_6;
		return;
	}
}
// Method Definition Index: 60792
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m1AA617688F48F5608F3BFE15736592501D7C56E2_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_color;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor = L_6;
		return;
	}
}
// Method Definition Index: 60793
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_m5B037F7426364C8491931FA06665AEBB3C22799B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, Il2CppSharedGenericObject* ___1_key, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		Il2CppSharedGenericObject* L_6 = ___1_key;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode), (void*)L_6);
		return;
	}
}
// Method Definition Index: 60794
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mC0DDCD6E5A9738375AF9890D1F11478F03054565_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_nextNodeId;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId = L_6;
		return;
	}
}
// Method Definition Index: 60795
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_mAC7E4B0847BE0A523FB81EC26F8E3C4C9698E7E5_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_size;
		((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize = L_6;
		return;
	}
}
// Method Definition Index: 60796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m19487325BED667C17E3C544D743182B38C55CD1A_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *(L_7);
		*(L_7) = ((int32_t)il2cpp_codegen_add(L_8, 1));
		return;
	}
}
// Method Definition Index: 60797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_mDBB0AAF0158D6FC0172754C8F2BFD25191BC86E8_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8(__this, L_0, NULL);
		int32_t L_2;
		L_2 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_1, NULL);
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF(__this, L_3, NULL);
		int32_t L_5;
		L_5 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_4, NULL);
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_6, NULL);
		if (!L_7)
		{
			G_B2_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
			goto IL_0033;
		}
		G_B1_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB(__this, L_8, NULL);
		int32_t L_10;
		L_10 = RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740(__this, L_9, NULL);
		G_B3_0 = L_10;
		G_B3_1 = G_B1_0;
		goto IL_0034;
	}

IL_0033:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0034:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B3_1, G_B3_0));
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_11 = __this->____pageTable;
		int32_t L_12 = ___0_nodeId;
		NullCheck(L_11);
		int32_t L_13 = ((int32_t)(L_12>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_15 = L_14->____slots;
		int32_t L_16 = ___0_nodeId;
		NullCheck(L_15);
		int32_t L_17 = V_0;
		((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_16&((int32_t)65535))))))->____subTreeSize = L_17;
		return;
	}
}
// Method Definition Index: 60798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m719AA62C29CBC6C387F371FB1D5D1E5C584ABA7B_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (int32_t*)(&((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize);
		int32_t* L_7 = L_6;
		int32_t L_8 = *(L_7);
		*(L_7) = ((int32_t)il2cpp_codegen_subtract(L_8, 1));
		return;
	}
}
// Method Definition Index: 60799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m8345131D2DAAF56EB67726A01913A6AE213BDFCF_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____rightId;
		return L_6;
	}
}
// Method Definition Index: 60800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_mE22B9DE51468DB30B9AA6DCC943BA55CB5FE35D8_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____leftId;
		return L_6;
	}
}
// Method Definition Index: 60801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_m581B36C5DAE9077161A7459DA50AE4A9CAB71319_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____parentId;
		return L_6;
	}
}
// Method Definition Index: 60802
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_mFB47C01E80DF20AD25C265811CEAB8E390F90912_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nodeColor;
		return L_6;
	}
}
// Method Definition Index: 60803
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_mA6C2D4B5BD374789C8648A8A26C65A6A0E65C5FB_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____nextId;
		return L_6;
	}
}
// Method Definition Index: 60804
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_m2F8A093D01302774EC35FA6E43E5274569B53740_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____subTreeSize;
		return L_6;
	}
}
// Method Definition Index: 60805
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTree_1_Key_m9D6F664243506ABCAE2758113317AA7666108B99_gshared (RBTree_1_t0BF58CE37145553BFFABBB0ADAD27CF95360CB81* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t5B14094ED066775C9BEA79E766639A899E80AF52* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4AE104F96E2A268C75BD9A73D84DABD1D55D6CD* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t5E8D875F4E9D23A467AF98B63F8F978483F33653* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535))))))->____keyOfNode;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 60745
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1__ctor_mBBF836BB94CC49E8AC0AE2AFC6D8AF48529D56C1_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_accessMethod, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_accessMethod;
		__this->____accessMethod = L_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
// Method Definition Index: 60746
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_InitTree_mBD10E36368D0DE9CEC19E97A64EFAEAD9034E44E_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	{
		__this->___root = 0;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = (TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9*)(TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)32));
		__this->____pageTable = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_0);
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_1 = __this->____pageTable;
		NullCheck(L_1);
		int32_t L_2 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_1)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_2, ((int32_t)32))), 1))/((int32_t)32))));
		__this->____pageTableMap = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_3);
		__this->____inUsePageCount = 0;
		__this->____nextFreePageLine = 0;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_4;
		L_4 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_5 = __this->____pageTable;
		NullCheck(L_5);
		int32_t L_6 = 0;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(L_7);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_8 = L_7->____slots;
		NullCheck(L_8);
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_8)->GetAddressAt(static_cast<il2cpp_array_size_t>(0))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),7), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4), (int32_t)1);
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_9 = __this->____pageTable;
		NullCheck(L_9);
		int32_t L_10 = 0;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_11 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		NullCheck(L_11);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12 = L_11->____slotMap;
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(0), (int32_t)1);
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_13 = __this->____pageTable;
		NullCheck(L_13);
		int32_t L_14 = 0;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_15 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		((  void (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_15, 1, NULL);
		__this->____inUseNodeCount = 1;
		__this->____inUseSatelliteTreeCount = 0;
		return;
	}
}
// Method Definition Index: 60747
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreePage_m2957AF16D91742024D780E2EEE66A755BA85BE80_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_0 = ___0_page;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_1 = __this->____pageTable;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_2 = ___0_page;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_2, NULL);
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, NULL);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)NULL);
		int32_t L_4 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_subtract(L_4, 1));
		return;
	}
}
// Method Definition Index: 60748
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* RBTree_1_AllocPage_mC65889C74FEC664D14316BCBE4C93F0E49D63C14_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* V_1 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_0029;
		}
	}
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_2 = __this->____pageTable;
		int32_t L_3 = V_0;
		int32_t L_4 = ___0_size;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_5 = (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		((  void (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)))(L_5, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)L_5);
		int32_t L_6 = V_0;
		__this->____nextFreePageLine = ((int32_t)(L_6/((int32_t)32)));
		goto IL_00a9;
	}

IL_0029:
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_7 = __this->____pageTable;
		NullCheck(L_7);
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_7)->max_length),NULL));
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_9 = (TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9*)(TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)((int32_t)il2cpp_codegen_multiply(L_8, 2)));
		V_1 = L_9;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_10 = __this->____pageTable;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_11 = V_1;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_12 = __this->____pageTable;
		NullCheck(L_12);
		int32_t L_13 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_12)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_10, 0, (RuntimeArray*)L_11, 0, L_13, NULL);
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_14 = V_1;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_15, ((int32_t)32))), 1))/((int32_t)32))));
		V_2 = L_16;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = __this->____pageTableMap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_19 = __this->____pageTableMap;
		NullCheck(L_19);
		int32_t L_20 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_19)->max_length),NULL));
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_17, 0, (RuntimeArray*)L_18, 0, L_20, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_21 = __this->____pageTableMap;
		NullCheck(L_21);
		int32_t L_22 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_21)->max_length),NULL));
		__this->____nextFreePageLine = L_22;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_23 = __this->____pageTable;
		NullCheck(L_23);
		int32_t L_24 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_23)->max_length),NULL));
		V_0 = L_24;
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_25 = V_1;
		__this->____pageTable = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTable), (void*)L_25);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_26 = V_2;
		__this->____pageTableMap = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____pageTableMap), (void*)L_26);
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_27 = __this->____pageTable;
		int32_t L_28 = V_0;
		int32_t L_29 = ___0_size;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_30 = (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
		((  void (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)))(L_30, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)L_30);
	}

IL_00a9:
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_31 = __this->____pageTable;
		int32_t L_32 = V_0;
		NullCheck(L_31);
		int32_t L_33 = L_32;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_34 = (L_31)->GetAt(static_cast<il2cpp_array_size_t>(L_33));
		int32_t L_35 = V_0;
		NullCheck(L_34);
		((  void (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_34, L_35, NULL);
		int32_t L_36 = __this->____inUsePageCount;
		__this->____inUsePageCount = ((int32_t)il2cpp_codegen_add(L_36, 1));
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_37 = __this->____pageTable;
		int32_t L_38 = V_0;
		NullCheck(L_37);
		int32_t L_39 = L_38;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_40 = (L_37)->GetAt(static_cast<il2cpp_array_size_t>(L_39));
		return L_40;
	}
}
// Method Definition Index: 60749
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFull_mABC21002B886694A5D9EFD5F57FDCC8DDDAD86A9_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_5, NULL);
		*(L_3) = ((int32_t)(L_4|((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))));
		return;
	}
}
// Method Definition Index: 60750
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_MarkPageFree_mDCAF41D22A4AA6CE0F3F553F9E7F5AD0355DBC40_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* ___0_page, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->____pageTableMap;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_1 = ___0_page;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_1, NULL);
		NullCheck(L_0);
		int32_t* L_3 = ((L_0)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_2/((int32_t)32))))));
		int32_t L_4 = *(L_3);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_5 = ___0_page;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_5, NULL);
		*(L_3) = ((int32_t)(L_4&((~((int32_t)(1<<((int32_t)(((int32_t)(L_6%((int32_t)32)))&((int32_t)31)))))))));
		return;
	}
}
// Method Definition Index: 60751
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIntValueFromBitMap_m8F0068910A5B84B992C5C54617A5313C2736D58B_fshared (uint32_t ___0_bitMap, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		V_0 = 0;
		uint32_t L_0 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_0&((int32_t)-65536))))
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		uint32_t L_2 = ___0_bitMap;
		___0_bitMap = ((int32_t)((uint32_t)L_2>>((int32_t)16)));
	}

IL_0016:
	{
		uint32_t L_3 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_3&((int32_t)65280))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_4, 8));
		uint32_t L_5 = ___0_bitMap;
		___0_bitMap = ((int32_t)((uint32_t)L_5>>8));
	}

IL_0028:
	{
		uint32_t L_6 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_6&((int32_t)240))))
		{
			goto IL_003a;
		}
	}
	{
		int32_t L_7 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, 4));
		uint32_t L_8 = ___0_bitMap;
		___0_bitMap = ((int32_t)((uint32_t)L_8>>4));
	}

IL_003a:
	{
		uint32_t L_9 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_9&((int32_t)12))))
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 2));
		uint32_t L_11 = ___0_bitMap;
		___0_bitMap = ((int32_t)((uint32_t)L_11>>2));
	}

IL_0049:
	{
		uint32_t L_12 = ___0_bitMap;
		if (!((int32_t)((int32_t)L_12&2)))
		{
			goto IL_0052;
		}
	}
	{
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0052:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60752
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_FreeNode_m957D2B53C8CD247585E24F28EC60600C27CA9E71_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Node_t67072FD48E4F8870CBFBBC65D20A021C6EA712BC = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3));
	//<source_info:<no-source>:1>
	TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		V_0 = L_3;
		int32_t L_4 = ___0_nodeId;
		V_1 = ((int32_t)(L_4&((int32_t)65535)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_5 = V_0;
		NullCheck(L_5);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_6 = L_5->____slots;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		il2cpp_codegen_initobj(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_6)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7))), SizeOf_Node_t67072FD48E4F8870CBFBBC65D20A021C6EA712BC);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_8 = V_0;
		NullCheck(L_8);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = L_8->____slotMap;
		int32_t L_10 = V_1;
		NullCheck(L_9);
		int32_t* L_11 = ((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_10/((int32_t)32))))));
		int32_t L_12 = *(L_11);
		int32_t L_13 = V_1;
		*(L_11) = ((int32_t)(L_12&((~((int32_t)(1<<((int32_t)(((int32_t)(L_13%((int32_t)32)))&((int32_t)31)))))))));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_14 = V_0;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_15 = L_14;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(L_15, NULL);
		V_2 = L_16;
		int32_t L_17 = V_2;
		NullCheck(L_15);
		((  void (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_15, ((int32_t)il2cpp_codegen_subtract(L_17, 1)), NULL);
		int32_t L_18 = __this->____inUseNodeCount;
		__this->____inUseNodeCount = ((int32_t)il2cpp_codegen_subtract(L_18, 1));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_19 = V_0;
		NullCheck(L_19);
		int32_t L_20;
		L_20 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(L_19, NULL);
		if (L_20)
		{
			goto IL_0071;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_21 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)))(__this, L_21, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		return;
	}

IL_0071:
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23;
		L_23 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(L_22, NULL);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_24 = V_0;
		NullCheck(L_24);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_25 = L_24->____slots;
		NullCheck(L_25);
		int32_t L_26 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_25)->max_length),NULL));
		if ((!(((uint32_t)L_23) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_26, 1))))))
		{
			goto IL_008a;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_27 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_008a:
	{
		return;
	}
}
// Method Definition Index: 60753
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexOfPageWithFreeSlot_m018EEE87827A0A2B917841F12D519A405B0EA46A_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, bool ___0_allocatedPage, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	uint32_t V_3 = 0;
	{
		int32_t L_0 = __this->____nextFreePageLine;
		V_0 = L_0;
		V_1 = (-1);
		goto IL_0073;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____pageTableMap;
		int32_t L_2 = V_0;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		if ((!(((uint32_t)L_4) < ((uint32_t)(-1)))))
		{
			goto IL_006f;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->____pageTableMap;
		int32_t L_6 = V_0;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_2 = L_8;
		goto IL_006a;
	}

IL_0021:
	{
		uint32_t L_9 = V_2;
		uint32_t L_10 = V_2;
		V_3 = ((int32_t)(((~((int32_t)L_9)))&((int32_t)il2cpp_codegen_add((int32_t)L_10, 1))));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____pageTableMap;
		int32_t L_12 = V_0;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		uint32_t L_16 = V_3;
		uint64_t L_17 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_16,NULL));
		if (!((int64_t)(L_15&(int64_t)L_17)))
		{
			goto IL_003d;
		}
	}
	{
		Exception_t* L_18;
		L_18 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(3, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_18, method);
	}

IL_003d:
	{
		int32_t L_19 = V_0;
		uint32_t L_20 = V_3;
		int32_t L_21;
		L_21 = ((  int32_t (*) (uint32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(L_20, NULL);
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_19, ((int32_t)32))), L_21));
		bool L_22 = ___0_allocatedPage;
		if (!L_22)
		{
			goto IL_0058;
		}
	}
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_23 = __this->____pageTable;
		int32_t L_24 = V_1;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		if (!L_26)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_27 = V_1;
		return L_27;
	}

IL_0058:
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_28 = __this->____pageTable;
		int32_t L_29 = V_1;
		NullCheck(L_28);
		int32_t L_30 = L_29;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_31 = (L_28)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
		if (L_31)
		{
			goto IL_0064;
		}
	}
	{
		int32_t L_32 = V_1;
		return L_32;
	}

IL_0064:
	{
		V_1 = (-1);
		uint32_t L_33 = V_2;
		uint32_t L_34 = V_3;
		V_2 = ((int32_t)((int32_t)L_33|(int32_t)L_34));
	}

IL_006a:
	{
		uint32_t L_35 = V_2;
		if (((int32_t)((int32_t)L_35^(-1))))
		{
			goto IL_0021;
		}
	}

IL_006f:
	{
		int32_t L_36 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_0073:
	{
		int32_t L_37 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_38 = __this->____pageTableMap;
		NullCheck(L_38);
		int32_t L_39 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_38)->max_length),NULL));
		if ((((int32_t)L_37) < ((int32_t)L_39)))
		{
			goto IL_000b;
		}
	}
	{
		int32_t L_40 = __this->____nextFreePageLine;
		if (!L_40)
		{
			goto IL_0095;
		}
	}
	{
		__this->____nextFreePageLine = 0;
		bool L_41 = ___0_allocatedPage;
		int32_t L_42;
		L_42 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, L_41, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_42;
	}

IL_0095:
	{
		int32_t L_43 = V_1;
		return L_43;
	}
}
// Method Definition Index: 60754
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_get_Count_mEEBAEC4856EDAB96F400E22D1AE495981435BD97_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseNodeCount;
		return ((int32_t)il2cpp_codegen_subtract(L_0, 1));
	}
}
// Method Definition Index: 60755
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_get_HasDuplicates_m1E23E7D8FF36D180A0204F2A1C753820E592CC31_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		return (bool)((!(((uint32_t)L_0) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 60756
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetNewNode_m2FCEB75981A0A96DA15F70FEA6DF68C0103E7087_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_33 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*)NULL;
		int32_t L_0;
		L_0 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, (bool)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		V_1 = L_0;
		int32_t L_1 = V_1;
		if ((((int32_t)L_1) == ((int32_t)(-1))))
		{
			goto IL_001c;
		}
	}
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_2 = __this->____pageTable;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_0 = L_5;
		goto IL_00a5;
	}

IL_001c:
	{
		int32_t L_6 = __this->____inUsePageCount;
		if ((((int32_t)L_6) >= ((int32_t)4)))
		{
			goto IL_0030;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_7;
		L_7 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)32), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_7;
		goto IL_00a5;
	}

IL_0030:
	{
		int32_t L_8 = __this->____inUsePageCount;
		if ((((int32_t)L_8) >= ((int32_t)((int32_t)32))))
		{
			goto IL_0048;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_9;
		L_9 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)256), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_9;
		goto IL_00a5;
	}

IL_0048:
	{
		int32_t L_10 = __this->____inUsePageCount;
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)128))))
		{
			goto IL_0063;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_11;
		L_11 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)1024), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_11;
		goto IL_00a5;
	}

IL_0063:
	{
		int32_t L_12 = __this->____inUsePageCount;
		if ((((int32_t)L_12) >= ((int32_t)((int32_t)4096))))
		{
			goto IL_007e;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_13;
		L_13 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)4096), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_13;
		goto IL_00a5;
	}

IL_007e:
	{
		int32_t L_14 = __this->____inUsePageCount;
		if ((((int32_t)L_14) >= ((int32_t)((int32_t)32768))))
		{
			goto IL_0099;
		}
	}
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_15;
		L_15 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)8192), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_15;
		goto IL_00a5;
	}

IL_0099:
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_16;
		L_16 = ((  TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, ((int32_t)65536), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		V_0 = L_16;
	}

IL_00a5:
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18;
		L_18 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_17, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		V_2 = L_18;
		int32_t L_19 = V_2;
		if ((!(((uint32_t)L_19) == ((uint32_t)(-1)))))
		{
			goto IL_00b8;
		}
	}
	{
		Exception_t* L_20;
		L_20 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_20, method);
	}

IL_00b8:
	{
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_21 = V_0;
		NullCheck(L_21);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_22 = L_21->____slots;
		int32_t L_23 = V_2;
		NullCheck(L_22);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_24 = V_0;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = ((  int32_t (*) (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(L_24, NULL);
		int32_t L_26 = V_2;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_22)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_23))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 16), ((int32_t)(((int32_t)(L_25<<((int32_t)16)))|L_26)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_27 = V_0;
		NullCheck(L_27);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_28 = L_27->____slots;
		int32_t L_29 = V_2;
		NullCheck(L_28);
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_28)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_29))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),5), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17), 1);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_30 = V_0;
		NullCheck(L_30);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_31 = L_30->____slots;
		int32_t L_32 = V_2;
		NullCheck(L_31);
		il2cpp_codegen_memcpy(L_33, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_key : &___0_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		il2cpp_codegen_write_field_data<true>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_32))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),6), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 19), L_33, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_34 = V_0;
		NullCheck(L_34);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_35 = L_34->____slots;
		int32_t L_36 = V_2;
		NullCheck(L_35);
		int32_t L_37 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_35)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_36))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 16));
		return L_37;
	}
}
// Method Definition Index: 60757
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Successor_mB979F0580EBF365A61B9983E40058279D75F3F7C_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_4;
	}

IL_0017:
	{
		int32_t L_5 = ___0_x_id;
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_0 = L_6;
		goto IL_002c;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		___0_x_id = L_7;
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_0 = L_9;
	}

IL_002c:
	{
		int32_t L_10 = V_0;
		if (!L_10)
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_11 = ___0_x_id;
		int32_t L_12 = V_0;
		int32_t L_13;
		L_13 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if ((((int32_t)L_11) == ((int32_t)L_13)))
		{
			goto IL_0021;
		}
	}

IL_0039:
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60758
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RBTree_1_Successor_mD19FB17B25F7A938B42B347A19B6FF6525F3C54C_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t* ___0_nodeId, int32_t* ___1_mainTreeNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___0_nodeId;
		int32_t L_1 = *(L_0);
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t* L_2 = ___0_nodeId;
		int32_t* L_3 = ___1_mainTreeNodeId;
		int32_t L_4 = *(L_3);
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		*(L_2) = L_5;
		int32_t* L_6 = ___1_mainTreeNodeId;
		*(L_6) = 0;
		goto IL_0032;
	}

IL_0013:
	{
		int32_t* L_7 = ___0_nodeId;
		int32_t* L_8 = ___0_nodeId;
		int32_t L_9 = *(L_8);
		int32_t L_10;
		L_10 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		*(L_7) = L_10;
		int32_t* L_11 = ___0_nodeId;
		int32_t L_12 = *(L_11);
		if (L_12)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_13 = ___1_mainTreeNodeId;
		int32_t L_14 = *(L_13);
		if (!L_14)
		{
			goto IL_0032;
		}
	}
	{
		int32_t* L_15 = ___0_nodeId;
		int32_t* L_16 = ___1_mainTreeNodeId;
		int32_t L_17 = *(L_16);
		int32_t L_18;
		L_18 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_17, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		*(L_15) = L_18;
		int32_t* L_19 = ___1_mainTreeNodeId;
		*(L_19) = 0;
	}

IL_0032:
	{
		int32_t* L_20 = ___0_nodeId;
		int32_t L_21 = *(L_20);
		if (!L_21)
		{
			goto IL_0062;
		}
	}
	{
		int32_t* L_22 = ___0_nodeId;
		int32_t L_23 = *(L_22);
		int32_t L_24;
		L_24 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_24)
		{
			goto IL_0060;
		}
	}
	{
		int32_t* L_25 = ___1_mainTreeNodeId;
		int32_t L_26 = *(L_25);
		if (!L_26)
		{
			goto IL_004c;
		}
	}
	{
		Exception_t* L_27;
		L_27 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)21), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_27, method);
	}

IL_004c:
	{
		int32_t* L_28 = ___1_mainTreeNodeId;
		int32_t* L_29 = ___0_nodeId;
		int32_t L_30 = *(L_29);
		*(L_28) = L_30;
		int32_t* L_31 = ___0_nodeId;
		int32_t* L_32 = ___0_nodeId;
		int32_t L_33 = *(L_32);
		int32_t L_34;
		L_34 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_33, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_35;
		L_35 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, L_34, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		*(L_31) = L_35;
	}

IL_0060:
	{
		return (bool)1;
	}

IL_0062:
	{
		return (bool)0;
	}
}
// Method Definition Index: 60759
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Minimum_m1F9D3171FC5A795A74AC5CA69F3A7BF7F2B2D8C1_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_x_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_000b;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		___0_x_id = L_1;
	}

IL_000b:
	{
		int32_t L_2 = ___0_x_id;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (L_3)
		{
			goto IL_0002;
		}
	}
	{
		int32_t L_4 = ___0_x_id;
		return L_4;
	}
}
// Method Definition Index: 60760
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_LeftRotate_mE713A527FF09B1055BCBAA0D20213360E4D738F3_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_2, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_9 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_10, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_17, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_20, (Il2CppFullySharedGenericAny*)L_21);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_19, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_21: *(void**)L_21));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_26;
		L_26 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_25, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_29 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_28, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_30, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_32 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_31, L_32, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_33, L_34, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_35, L_36, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_39, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_41;
		L_41 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_40, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_42, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_44;
		L_44 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_43, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_47, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_49;
		L_49 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_52, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_54;
		L_54 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_53, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_55, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_57;
		L_57 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_56, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_58, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_60, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_62;
		L_62 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_61, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60761
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RightRotate_m7BC809299786EA77942E205DD4975F08A57487A9_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNode, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B12_2 = NULL;
	int32_t G_B11_0 = 0;
	int32_t G_B11_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B11_2 = NULL;
	int32_t G_B13_0 = 0;
	int32_t G_B13_1 = 0;
	int32_t G_B13_2 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B13_3 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B17_2 = NULL;
	int32_t G_B16_0 = 0;
	int32_t G_B16_1 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B16_2 = NULL;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* G_B18_3 = NULL;
	{
		int32_t L_0 = ___1_x_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_1;
		int32_t L_2 = ___1_x_id;
		int32_t L_3 = V_0;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_2, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_9 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_002d:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_10, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_13 = ___1_x_id;
		int32_t L_14;
		L_14 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (L_14)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_15 = ___0_root_id;
		if (L_15)
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_16 = V_0;
		__this->___root = L_16;
		goto IL_0099;
	}

IL_0050:
	{
		int32_t L_17 = ___2_mainTreeNode;
		int32_t L_18 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_17, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_19 = ___2_mainTreeNode;
		int32_t L_20 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_20, (Il2CppFullySharedGenericAny*)L_21);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_19, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_21: *(void**)L_21));
		int32_t L_22 = V_0;
		___0_root_id = L_22;
		goto IL_0099;
	}

IL_006b:
	{
		int32_t L_23 = ___1_x_id;
		int32_t L_24 = ___1_x_id;
		int32_t L_25;
		L_25 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_26;
		L_26 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_25, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((!(((uint32_t)L_23) == ((uint32_t)L_26))))
		{
			goto IL_008b;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_29 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_28, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_0099;
	}

IL_008b:
	{
		int32_t L_30 = ___1_x_id;
		int32_t L_31;
		L_31 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_30, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_32 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_31, L_32, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_0099:
	{
		int32_t L_33 = V_0;
		int32_t L_34 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_33, L_34, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_35 = ___1_x_id;
		int32_t L_36 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_35, L_36, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_37 = ___1_x_id;
		if (!L_37)
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_38 = ___1_x_id;
		int32_t L_39 = ___1_x_id;
		int32_t L_40;
		L_40 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_39, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_41;
		L_41 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_40, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_42 = ___1_x_id;
		int32_t L_43;
		L_43 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_42, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_44;
		L_44 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_43, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_45 = ___1_x_id;
		int32_t L_46;
		L_46 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_46)
		{
			G_B12_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
			G_B12_1 = L_38;
			G_B12_2 = __this;
			goto IL_00e1;
		}
		G_B11_0 = ((int32_t)il2cpp_codegen_add(L_41, L_44));
		G_B11_1 = L_38;
		G_B11_2 = __this;
	}
	{
		int32_t L_47 = ___1_x_id;
		int32_t L_48;
		L_48 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_47, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_49;
		L_49 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B13_0 = L_49;
		G_B13_1 = G_B11_0;
		G_B13_2 = G_B11_1;
		G_B13_3 = G_B11_2;
		goto IL_00e2;
	}

IL_00e1:
	{
		G_B13_0 = 1;
		G_B13_1 = G_B12_0;
		G_B13_2 = G_B12_1;
		G_B13_3 = G_B12_2;
	}

IL_00e2:
	{
		NullCheck(G_B13_3);
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(G_B13_3, G_B13_2, ((int32_t)il2cpp_codegen_add(G_B13_1, G_B13_0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
	}

IL_00e8:
	{
		int32_t L_50 = V_0;
		if (!L_50)
		{
			goto IL_0127;
		}
	}
	{
		int32_t L_51 = V_0;
		int32_t L_52 = V_0;
		int32_t L_53;
		L_53 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_52, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_54;
		L_54 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_53, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_55 = V_0;
		int32_t L_56;
		L_56 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_55, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_57;
		L_57 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_56, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_58 = V_0;
		int32_t L_59;
		L_59 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_58, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_59)
		{
			G_B17_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
			G_B17_1 = L_51;
			G_B17_2 = __this;
			goto IL_0120;
		}
		G_B16_0 = ((int32_t)il2cpp_codegen_add(L_54, L_57));
		G_B16_1 = L_51;
		G_B16_2 = __this;
	}
	{
		int32_t L_60 = V_0;
		int32_t L_61;
		L_61 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_60, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_62;
		L_62 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_61, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B18_0 = L_62;
		G_B18_1 = G_B16_0;
		G_B18_2 = G_B16_1;
		G_B18_3 = G_B16_2;
		goto IL_0121;
	}

IL_0120:
	{
		G_B18_0 = 1;
		G_B18_1 = G_B17_0;
		G_B18_2 = G_B17_1;
		G_B18_3 = G_B17_2;
	}

IL_0121:
	{
		NullCheck(G_B18_3);
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(G_B18_3, G_B18_2, ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
	}

IL_0127:
	{
		int32_t L_63 = ___0_root_id;
		return L_63;
	}
}
// Method Definition Index: 60762
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBInsert_m0EF84E30DAACA98625F2B1488C82769E71BACB0E_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_mainTreeNodeID, int32_t ___3_position, bool ___4_append, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_15 = L_10;
	const Il2CppFullySharedGenericAny L_37 = L_10;
	const Il2CppFullySharedGenericAny L_39 = L_10;
	const Il2CppFullySharedGenericAny L_127 = L_10;
	const Il2CppFullySharedGenericAny L_132 = L_10;
	const Il2CppFullySharedGenericAny L_137 = L_10;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_17 = L_12;
	const Il2CppFullySharedGenericAny L_134 = L_12;
	const Il2CppFullySharedGenericAny L_139 = L_12;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B54_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		V_0 = 0;
		int32_t L_1 = ___0_root_id;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_2 = ___0_root_id;
		G_B3_0 = L_2;
		goto IL_001c;
	}

IL_0016:
	{
		int32_t L_3 = __this->___root;
		G_B3_0 = L_3;
	}

IL_001c:
	{
		V_1 = G_B3_0;
		int32_t L_4 = __this->____accessMethod;
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_01f8;
		}
	}
	{
		bool L_5 = ___4_append;
		if (L_5)
		{
			goto IL_01f8;
		}
	}
	{
		goto IL_01f0;
	}

IL_0035:
	{
		int32_t L_6 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		int32_t L_7 = V_1;
		V_0 = L_7;
		int32_t L_8 = ___0_root_id;
		if (!L_8)
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_9 = ___1_x_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_9, (Il2CppFullySharedGenericAny*)L_10);
		int32_t L_11 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_11, (Il2CppFullySharedGenericAny*)L_12);
		int32_t L_13;
		L_13 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(6, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_10: *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_12: *(void**)L_12));
		G_B9_0 = L_13;
		goto IL_006b;
	}

IL_0057:
	{
		int32_t L_14 = ___1_x_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_14, (Il2CppFullySharedGenericAny*)L_15);
		int32_t L_16 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_16, (Il2CppFullySharedGenericAny*)L_17);
		int32_t L_18;
		L_18 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(5, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_15: *(void**)L_15), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_17: *(void**)L_17));
		G_B9_0 = L_18;
	}

IL_006b:
	{
		V_2 = G_B9_0;
		int32_t L_19 = V_2;
		if ((((int32_t)L_19) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_20 = V_1;
		int32_t L_21;
		L_21 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_1 = L_21;
		goto IL_01f0;
	}

IL_007d:
	{
		int32_t L_22 = V_2;
		if ((((int32_t)L_22) <= ((int32_t)0)))
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_23 = V_1;
		int32_t L_24;
		L_24 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_23, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_1 = L_24;
		goto IL_01f0;
	}

IL_008e:
	{
		int32_t L_25 = ___0_root_id;
		if (!L_25)
		{
			goto IL_0098;
		}
	}
	{
		Exception_t* L_26;
		L_26 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(5, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_26, method);
	}

IL_0098:
	{
		int32_t L_27 = V_1;
		int32_t L_28;
		L_28 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_28)
		{
			goto IL_00cd;
		}
	}
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_31 = ___1_x_id;
		int32_t L_32 = V_1;
		int32_t L_33;
		L_33 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)))(__this, L_30, L_31, L_32, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_33;
		int32_t L_34 = V_1;
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_35, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_36, (Il2CppFullySharedGenericAny*)L_37);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_34, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_37: *(void**)L_37));
		goto IL_01ee;
	}

IL_00cd:
	{
		V_3 = 0;
		int32_t L_38 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_38, (Il2CppFullySharedGenericAny*)L_39);
		int32_t L_40;
		L_40 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_39: *(void**)L_39));
		V_3 = L_40;
		int32_t L_41 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_add(L_41, 1));
		int32_t L_42 = V_3;
		int32_t L_43 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_42, L_43, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_44 = V_3;
		int32_t L_45 = V_1;
		int32_t L_46;
		L_46 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_44, L_46, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_47 = V_3;
		int32_t L_48 = V_1;
		int32_t L_49;
		L_49 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_47, L_49, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_50 = V_3;
		int32_t L_51 = V_1;
		int32_t L_52;
		L_52 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_51, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_50, L_52, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_53 = V_3;
		int32_t L_54 = V_1;
		int32_t L_55;
		L_55 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_54, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_53, L_55, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_56 = V_1;
		int32_t L_57;
		L_57 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_56, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_58;
		L_58 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_57, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_59 = V_1;
		if ((!(((uint32_t)L_58) == ((uint32_t)L_59))))
		{
			goto IL_014b;
		}
	}
	{
		int32_t L_60 = V_1;
		int32_t L_61;
		L_61 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_60, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_62 = V_3;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_61, L_62, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_0169;
	}

IL_014b:
	{
		int32_t L_63 = V_1;
		int32_t L_64;
		L_64 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_63, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_65;
		L_65 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_64, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_66 = V_1;
		if ((!(((uint32_t)L_65) == ((uint32_t)L_66))))
		{
			goto IL_0169;
		}
	}
	{
		int32_t L_67 = V_1;
		int32_t L_68;
		L_68 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_67, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_69 = V_3;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_68, L_69, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_0169:
	{
		int32_t L_70 = V_1;
		int32_t L_71;
		L_71 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_70, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_71)
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_72 = V_1;
		int32_t L_73;
		L_73 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_72, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_74 = V_3;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_73, L_74, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0180:
	{
		int32_t L_75 = V_1;
		int32_t L_76;
		L_76 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_75, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_76)
		{
			goto IL_0197;
		}
	}
	{
		int32_t L_77 = V_1;
		int32_t L_78;
		L_78 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_77, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_79 = V_3;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_78, L_79, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0197:
	{
		int32_t L_80 = __this->___root;
		int32_t L_81 = V_1;
		if ((!(((uint32_t)L_80) == ((uint32_t)L_81))))
		{
			goto IL_01a7;
		}
	}
	{
		int32_t L_82 = V_3;
		__this->___root = L_82;
	}

IL_01a7:
	{
		int32_t L_83 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_83, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_84 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_84, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_85 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_85, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_86 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_86, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_87 = V_1;
		int32_t L_88;
		L_88 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_87, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_4 = L_88;
		int32_t L_89 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(__this, L_89, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		int32_t L_90 = V_1;
		int32_t L_91 = ___1_x_id;
		int32_t L_92 = V_3;
		int32_t L_93;
		L_93 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)))(__this, L_90, L_91, L_92, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		___0_root_id = L_93;
		int32_t L_94 = V_3;
		int32_t L_95 = V_4;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(__this, L_94, L_95, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
	}

IL_01ee:
	{
		int32_t L_96 = ___0_root_id;
		return L_96;
	}

IL_01f0:
	{
		int32_t L_97 = V_1;
		if (L_97)
		{
			goto IL_0035;
		}
	}
	{
		goto IL_0263;
	}

IL_01f8:
	{
		int32_t L_98 = __this->____accessMethod;
		bool L_99 = ___4_append;
		if (!((int32_t)(((((int32_t)L_98) == ((int32_t)2))? 1 : 0)|(int32_t)L_99)))
		{
			goto IL_025b;
		}
	}
	{
		int32_t L_100 = ___3_position;
		if ((!(((uint32_t)L_100) == ((uint32_t)(-1)))))
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_101 = __this->___root;
		int32_t L_102;
		L_102 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_101, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		___3_position = L_102;
		goto IL_0256;
	}

IL_021b:
	{
		int32_t L_103 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34)))(__this, L_103, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		int32_t L_104 = V_1;
		V_0 = L_104;
		int32_t L_105 = ___3_position;
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_106, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_108;
		L_108 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_107, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_105, L_108));
		int32_t L_109 = V_5;
		if ((((int32_t)L_109) > ((int32_t)0)))
		{
			goto IL_0245;
		}
	}
	{
		int32_t L_110 = V_1;
		int32_t L_111;
		L_111 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_110, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_1 = L_111;
		goto IL_0256;
	}

IL_0245:
	{
		int32_t L_112 = V_1;
		int32_t L_113;
		L_113 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_112, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_1 = L_113;
		int32_t L_114 = V_1;
		if (!L_114)
		{
			goto IL_0256;
		}
	}
	{
		int32_t L_115 = V_5;
		___3_position = ((int32_t)il2cpp_codegen_subtract(L_115, 1));
	}

IL_0256:
	{
		int32_t L_116 = V_1;
		if (L_116)
		{
			goto IL_021b;
		}
	}
	{
		goto IL_0263;
	}

IL_025b:
	{
		Exception_t* L_117;
		L_117 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)15), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_117, method);
	}

IL_0263:
	{
		int32_t L_118 = ___1_x_id;
		int32_t L_119 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_118, L_119, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_120 = V_0;
		if (L_120)
		{
			goto IL_0298;
		}
	}
	{
		int32_t L_121 = ___0_root_id;
		if (L_121)
		{
			goto IL_027d;
		}
	}
	{
		int32_t L_122 = ___1_x_id;
		__this->___root = L_122;
		goto IL_030a;
	}

IL_027d:
	{
		int32_t L_123 = ___2_mainTreeNodeID;
		int32_t L_124 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_123, L_124, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_125 = ___2_mainTreeNodeID;
		int32_t L_126 = ___1_x_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_126, (Il2CppFullySharedGenericAny*)L_127);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_125, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_127: *(void**)L_127));
		int32_t L_128 = ___1_x_id;
		___0_root_id = L_128;
		goto IL_030a;
	}

IL_0298:
	{
		V_6 = 0;
		int32_t L_129 = __this->____accessMethod;
		if ((!(((uint32_t)L_129) == ((uint32_t)1))))
		{
			goto IL_02d5;
		}
	}
	{
		int32_t L_130 = ___0_root_id;
		if (!L_130)
		{
			goto IL_02bd;
		}
	}
	{
		int32_t L_131 = ___1_x_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_131, (Il2CppFullySharedGenericAny*)L_132);
		int32_t L_133 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_133, (Il2CppFullySharedGenericAny*)L_134);
		int32_t L_135;
		L_135 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(6, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_132: *(void**)L_132), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_134: *(void**)L_134));
		G_B49_0 = L_135;
		goto IL_02d1;
	}

IL_02bd:
	{
		int32_t L_136 = ___1_x_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_136, (Il2CppFullySharedGenericAny*)L_137);
		int32_t L_138 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_138, (Il2CppFullySharedGenericAny*)L_139);
		int32_t L_140;
		L_140 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(5, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_137: *(void**)L_137), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_139: *(void**)L_139));
		G_B49_0 = L_140;
	}

IL_02d1:
	{
		V_6 = G_B49_0;
		goto IL_02f3;
	}

IL_02d5:
	{
		int32_t L_141 = __this->____accessMethod;
		if ((!(((uint32_t)L_141) == ((uint32_t)2))))
		{
			goto IL_02eb;
		}
	}
	{
		int32_t L_142 = ___3_position;
		if ((((int32_t)L_142) <= ((int32_t)0)))
		{
			goto IL_02e6;
		}
	}
	{
		G_B54_0 = 1;
		goto IL_02e7;
	}

IL_02e6:
	{
		G_B54_0 = (-1);
	}

IL_02e7:
	{
		V_6 = G_B54_0;
		goto IL_02f3;
	}

IL_02eb:
	{
		Exception_t* L_143;
		L_143 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)16), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_143, method);
	}

IL_02f3:
	{
		int32_t L_144 = V_6;
		if ((((int32_t)L_144) >= ((int32_t)0)))
		{
			goto IL_0302;
		}
	}
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_145, L_146, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_030a;
	}

IL_0302:
	{
		int32_t L_147 = V_0;
		int32_t L_148 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_147, L_148, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_030a:
	{
		int32_t L_149 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_149, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_150 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_150, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_151 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_151, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_152 = ___1_x_id;
		V_1 = L_152;
		goto IL_04ba;
	}

IL_0329:
	{
		int32_t L_153 = ___1_x_id;
		int32_t L_154;
		L_154 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_153, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_155 = ___1_x_id;
		int32_t L_156;
		L_156 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_155, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_157;
		L_157 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_156, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_158;
		L_158 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_157, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((!(((uint32_t)L_154) == ((uint32_t)L_158))))
		{
			goto IL_0405;
		}
	}
	{
		int32_t L_159 = ___1_x_id;
		int32_t L_160;
		L_160 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_159, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_161;
		L_161 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_160, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_162;
		L_162 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_161, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_0 = L_162;
		int32_t L_163 = V_0;
		int32_t L_164;
		L_164 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_163, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if (L_164)
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_165 = ___1_x_id;
		int32_t L_166;
		L_166 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_165, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_166, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_167 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_167, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_168 = ___1_x_id;
		int32_t L_169;
		L_169 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_168, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_170;
		L_170 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_169, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_170, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_171 = ___1_x_id;
		int32_t L_172;
		L_172 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_171, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_173;
		L_173 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_172, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___1_x_id = L_173;
		goto IL_04ba;
	}

IL_03a3:
	{
		int32_t L_174 = ___1_x_id;
		int32_t L_175 = ___1_x_id;
		int32_t L_176;
		L_176 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_175, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_177;
		L_177 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_176, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if ((!(((uint32_t)L_174) == ((uint32_t)L_177))))
		{
			goto IL_03c7;
		}
	}
	{
		int32_t L_178 = ___1_x_id;
		int32_t L_179;
		L_179 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_178, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___1_x_id = L_179;
		int32_t L_180 = ___0_root_id;
		int32_t L_181 = ___1_x_id;
		int32_t L_182 = ___2_mainTreeNodeID;
		int32_t L_183;
		L_183 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(__this, L_180, L_181, L_182, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		___0_root_id = L_183;
	}

IL_03c7:
	{
		int32_t L_184 = ___1_x_id;
		int32_t L_185;
		L_185 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_184, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_185, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_186 = ___1_x_id;
		int32_t L_187;
		L_187 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_186, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_188;
		L_188 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_187, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_188, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_189 = ___0_root_id;
		int32_t L_190 = ___1_x_id;
		int32_t L_191;
		L_191 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_190, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_192;
		L_192 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_191, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_193 = ___2_mainTreeNodeID;
		int32_t L_194;
		L_194 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_189, L_192, L_193, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_194;
		goto IL_04ba;
	}

IL_0405:
	{
		int32_t L_195 = ___1_x_id;
		int32_t L_196;
		L_196 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_195, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_197;
		L_197 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_196, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_198;
		L_198 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_197, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_198;
		int32_t L_199 = V_0;
		int32_t L_200;
		L_200 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_199, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if (L_200)
		{
			goto IL_045d;
		}
	}
	{
		int32_t L_201 = ___1_x_id;
		int32_t L_202;
		L_202 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_201, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_202, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_203 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_203, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_204 = ___1_x_id;
		int32_t L_205;
		L_205 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_204, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_206;
		L_206 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_205, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_206, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_207 = ___1_x_id;
		int32_t L_208;
		L_208 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_207, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_209;
		L_209 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_208, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___1_x_id = L_209;
		goto IL_04ba;
	}

IL_045d:
	{
		int32_t L_210 = ___1_x_id;
		int32_t L_211 = ___1_x_id;
		int32_t L_212;
		L_212 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_211, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_213;
		L_213 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_212, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((!(((uint32_t)L_210) == ((uint32_t)L_213))))
		{
			goto IL_0481;
		}
	}
	{
		int32_t L_214 = ___1_x_id;
		int32_t L_215;
		L_215 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_214, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___1_x_id = L_215;
		int32_t L_216 = ___0_root_id;
		int32_t L_217 = ___1_x_id;
		int32_t L_218 = ___2_mainTreeNodeID;
		int32_t L_219;
		L_219 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_216, L_217, L_218, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_219;
	}

IL_0481:
	{
		int32_t L_220 = ___1_x_id;
		int32_t L_221;
		L_221 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_220, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_221, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_222 = ___1_x_id;
		int32_t L_223;
		L_223 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_222, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_224;
		L_224 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_223, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_224, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_225 = ___0_root_id;
		int32_t L_226 = ___1_x_id;
		int32_t L_227;
		L_227 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_226, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_228;
		L_228 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_227, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_229 = ___2_mainTreeNodeID;
		int32_t L_230;
		L_230 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(__this, L_225, L_228, L_229, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		___0_root_id = L_230;
	}

IL_04ba:
	{
		int32_t L_231 = ___1_x_id;
		int32_t L_232;
		L_232 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_231, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_233;
		L_233 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_232, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if (!L_233)
		{
			goto IL_0329;
		}
	}
	{
		int32_t L_234 = ___0_root_id;
		if (L_234)
		{
			goto IL_04de;
		}
	}
	{
		int32_t L_235 = __this->___root;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_235, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		goto IL_04e6;
	}

IL_04de:
	{
		int32_t L_236 = ___0_root_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_236, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
	}

IL_04e6:
	{
		int32_t L_237 = ___0_root_id;
		return L_237;
	}
}
// Method Definition Index: 60763
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_UpdateNodeKey_m814FA038F9F567C372B2A82A2B7D3749818D456B_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_currentKey, Il2CppFullySharedGenericAny ___1_newKey, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_10 = L_0;
	const Il2CppFullySharedGenericAny L_13 = L_0;
	//<source_info:<no-source>:1>
	NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_currentKey : &___0_currentKey), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_1;
		L_1 = InvokerFuncInvoker1< NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (L_4)
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		int32_t L_7 = __this->___root;
		if ((((int32_t)L_6) == ((int32_t)L_7)))
		{
			goto IL_0031;
		}
	}
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_8 = V_0;
		int32_t L_9 = L_8.____mainTreeNodeID;
		il2cpp_codegen_memcpy(L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_newKey : &___1_newKey), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_9, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_10: *(void**)L_10));
	}

IL_0031:
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_11 = V_0;
		int32_t L_12 = L_11.____nodeID;
		il2cpp_codegen_memcpy(L_13, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_newKey : &___1_newKey), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_12, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_13: *(void**)L_13));
		return;
	}
}
// Method Definition Index: 60764
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DeleteByIndex_m4E8BD5EA559A58927B5D3D8E5A0CE2A233918598_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_i, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_i;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_1;
		L_1 = ((  NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		V_0 = L_1;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_2 = V_0;
		int32_t L_3 = L_2.____nodeID;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_3, (Il2CppFullySharedGenericAny*)L_4);
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_5 = V_0;
		int32_t L_6 = L_5.____nodeID;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_7 = V_0;
		int32_t L_8 = L_7.____mainTreeNodeID;
		int32_t L_9;
		L_9 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43)))(__this, 0, L_6, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		il2cpp_codegen_memcpy(il2cppRetVal, L_4, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		return;
	}
}
// Method Definition Index: 60765
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDelete_m158CEEBBDD392C617D35B5D05A3D2936A201C277_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_z_id, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_z_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43)))(__this, 0, L_0, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_1;
	}
}
// Method Definition Index: 60766
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteX_m6C460EF1980876E2517FBD4635AFA96A81B7E274_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, int32_t ___1_z_id, int32_t ___2_mainTreeNodeID, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_55 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_70 = L_55;
	const Il2CppFullySharedGenericAny L_150 = L_55;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t G_B5_0 = 0;
	{
		V_0 = 0;
		int32_t L_0 = ___1_z_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_1)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = ___1_z_id;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_4 = ___1_z_id;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_6 = ___1_z_id;
		int32_t L_7;
		L_7 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43)))(__this, L_3, L_5, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 43));
		return L_7;
	}

IL_0021:
	{
		V_3 = (bool)0;
		int32_t L_8 = __this->____accessMethod;
		if ((((int32_t)L_8) == ((int32_t)1)))
		{
			goto IL_002f;
		}
	}
	{
		int32_t L_9 = ___1_z_id;
		G_B5_0 = L_9;
		goto IL_0030;
	}

IL_002f:
	{
		int32_t L_10 = ___2_mainTreeNodeID;
		G_B5_0 = L_10;
	}

IL_0030:
	{
		V_4 = G_B5_0;
		int32_t L_11 = V_4;
		int32_t L_12;
		L_12 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_12)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_13 = V_4;
		int32_t L_14;
		L_14 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		___0_root_id = L_14;
	}

IL_0046:
	{
		int32_t L_15 = V_4;
		int32_t L_16;
		L_16 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_17;
		L_17 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_16, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		if ((!(((uint32_t)L_17) == ((uint32_t)2))))
		{
			goto IL_005b;
		}
	}
	{
		V_3 = (bool)1;
		goto IL_0073;
	}

IL_005b:
	{
		int32_t L_18 = V_4;
		int32_t L_19;
		L_19 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_20;
		L_20 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_19, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		if ((!(((uint32_t)L_20) == ((uint32_t)1))))
		{
			goto IL_0073;
		}
	}
	{
		Exception_t* L_21;
		L_21 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(7, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_21, method);
	}

IL_0073:
	{
		int32_t L_22 = ___1_z_id;
		int32_t L_23;
		L_23 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_22, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_23)
		{
			goto IL_0085;
		}
	}
	{
		int32_t L_24 = ___1_z_id;
		int32_t L_25;
		L_25 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (L_25)
		{
			goto IL_0089;
		}
	}

IL_0085:
	{
		int32_t L_26 = ___1_z_id;
		V_1 = L_26;
		goto IL_0091;
	}

IL_0089:
	{
		int32_t L_27 = ___1_z_id;
		int32_t L_28;
		L_28 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		V_1 = L_28;
	}

IL_0091:
	{
		int32_t L_29 = V_1;
		int32_t L_30;
		L_30 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_29, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_30)
		{
			goto IL_00a4;
		}
	}
	{
		int32_t L_31 = V_1;
		int32_t L_32;
		L_32 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_32;
		goto IL_00ac;
	}

IL_00a4:
	{
		int32_t L_33 = V_1;
		int32_t L_34;
		L_34 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_33, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_0 = L_34;
	}

IL_00ac:
	{
		int32_t L_35 = V_1;
		int32_t L_36;
		L_36 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_35, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_2 = L_36;
		int32_t L_37 = V_0;
		if (!L_37)
		{
			goto IL_00bf;
		}
	}
	{
		int32_t L_38 = V_0;
		int32_t L_39 = V_2;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_38, L_39, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_00bf:
	{
		int32_t L_40 = V_2;
		if (L_40)
		{
			goto IL_00d3;
		}
	}
	{
		int32_t L_41 = ___0_root_id;
		if (L_41)
		{
			goto IL_00ce;
		}
	}
	{
		int32_t L_42 = V_0;
		__this->___root = L_42;
		goto IL_00ef;
	}

IL_00ce:
	{
		int32_t L_43 = V_0;
		___0_root_id = L_43;
		goto IL_00ef;
	}

IL_00d3:
	{
		int32_t L_44 = V_1;
		int32_t L_45 = V_2;
		int32_t L_46;
		L_46 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((!(((uint32_t)L_44) == ((uint32_t)L_46))))
		{
			goto IL_00e7;
		}
	}
	{
		int32_t L_47 = V_2;
		int32_t L_48 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_47, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_00ef;
	}

IL_00e7:
	{
		int32_t L_49 = V_2;
		int32_t L_50 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_49, L_50, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_00ef:
	{
		int32_t L_51 = V_1;
		int32_t L_52 = ___1_z_id;
		if ((((int32_t)L_51) == ((int32_t)L_52)))
		{
			goto IL_010f;
		}
	}
	{
		int32_t L_53 = ___1_z_id;
		int32_t L_54 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_54, (Il2CppFullySharedGenericAny*)L_55);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_53, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_55: *(void**)L_55));
		int32_t L_56 = ___1_z_id;
		int32_t L_57 = V_1;
		int32_t L_58;
		L_58 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_57, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_56, L_58, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
	}

IL_010f:
	{
		int32_t L_59 = V_4;
		int32_t L_60;
		L_60 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_59, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_60)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_61 = ___0_root_id;
		if (L_61)
		{
			goto IL_0128;
		}
	}
	{
		int32_t L_62 = ___1_z_id;
		int32_t L_63 = V_4;
		if ((((int32_t)L_62) == ((int32_t)L_63)))
		{
			goto IL_0128;
		}
	}
	{
		Exception_t* L_64;
		L_64 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_64, method);
	}

IL_0128:
	{
		int32_t L_65 = ___0_root_id;
		if (!L_65)
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_66 = V_4;
		int32_t L_67 = ___0_root_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_66, L_67, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_68 = V_4;
		int32_t L_69 = ___0_root_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_69, (Il2CppFullySharedGenericAny*)L_70);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_68, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_70: *(void**)L_70));
	}

IL_0143:
	{
		int32_t L_71 = V_2;
		V_5 = L_71;
		goto IL_015a;
	}

IL_0148:
	{
		int32_t L_72 = V_5;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44)))(__this, L_72, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		int32_t L_73 = V_5;
		int32_t L_74;
		L_74 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_73, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_5 = L_74;
	}

IL_015a:
	{
		int32_t L_75 = V_5;
		if (L_75)
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_76 = ___0_root_id;
		if (!L_76)
		{
			goto IL_017d;
		}
	}
	{
		int32_t L_77 = V_4;
		V_6 = L_77;
		goto IL_0179;
	}

IL_0167:
	{
		int32_t L_78 = V_6;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45)))(__this, L_78, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_79 = V_6;
		int32_t L_80;
		L_80 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_79, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_6 = L_80;
	}

IL_0179:
	{
		int32_t L_81 = V_6;
		if (L_81)
		{
			goto IL_0167;
		}
	}

IL_017d:
	{
		int32_t L_82 = V_1;
		int32_t L_83;
		L_83 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_82, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_83) == ((uint32_t)1))))
		{
			goto IL_0193;
		}
	}
	{
		int32_t L_84 = ___0_root_id;
		int32_t L_85 = V_0;
		int32_t L_86 = V_2;
		int32_t L_87 = ___2_mainTreeNodeID;
		int32_t L_88;
		L_88 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46)))(__this, L_84, L_85, L_86, L_87, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 46));
		___0_root_id = L_88;
	}

IL_0193:
	{
		bool L_89 = V_3;
		if (!L_89)
		{
			goto IL_02af;
		}
	}
	{
		int32_t L_90 = V_4;
		if (!L_90)
		{
			goto IL_01ae;
		}
	}
	{
		int32_t L_91 = V_4;
		int32_t L_92;
		L_92 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_91, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_93;
		L_93 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_92, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		if ((((int32_t)L_93) == ((int32_t)1)))
		{
			goto IL_01b6;
		}
	}

IL_01ae:
	{
		Exception_t* L_94;
		L_94 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)9), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_94, method);
	}

IL_01b6:
	{
		int32_t L_95 = __this->____inUseSatelliteTreeCount;
		__this->____inUseSatelliteTreeCount = ((int32_t)il2cpp_codegen_subtract(L_95, 1));
		int32_t L_96 = V_4;
		int32_t L_97;
		L_97 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_96, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		V_7 = L_97;
		int32_t L_98 = V_7;
		int32_t L_99 = V_4;
		int32_t L_100;
		L_100 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_99, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_98, L_100, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_101 = V_7;
		int32_t L_102 = V_4;
		int32_t L_103;
		L_103 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_102, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_101, L_103, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_104 = V_7;
		int32_t L_105 = V_4;
		int32_t L_106;
		L_106 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_105, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(__this, L_104, L_106, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		int32_t L_107 = V_7;
		int32_t L_108 = V_4;
		int32_t L_109;
		L_109 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_108, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_107, L_109, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_110 = V_4;
		int32_t L_111;
		L_111 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_110, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_111)
		{
			goto IL_025c;
		}
	}
	{
		int32_t L_112 = V_7;
		int32_t L_113 = V_4;
		int32_t L_114;
		L_114 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_113, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_112, L_114, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_115 = V_4;
		int32_t L_116;
		L_116 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_115, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_117;
		L_117 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_116, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_118 = V_4;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_118))))
		{
			goto IL_024c;
		}
	}
	{
		int32_t L_119 = V_4;
		int32_t L_120;
		L_120 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_119, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_121 = V_7;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_120, L_121, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_025c;
	}

IL_024c:
	{
		int32_t L_122 = V_4;
		int32_t L_123;
		L_123 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_122, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_124 = V_7;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_123, L_124, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
	}

IL_025c:
	{
		int32_t L_125 = V_4;
		int32_t L_126;
		L_126 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_125, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_126)
		{
			goto IL_0276;
		}
	}
	{
		int32_t L_127 = V_4;
		int32_t L_128;
		L_128 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_127, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_129 = V_7;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_128, L_129, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0276:
	{
		int32_t L_130 = V_4;
		int32_t L_131;
		L_131 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_130, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_131)
		{
			goto IL_0290;
		}
	}
	{
		int32_t L_132 = V_4;
		int32_t L_133;
		L_133 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_132, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_134 = V_7;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_133, L_134, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0290:
	{
		int32_t L_135 = __this->___root;
		int32_t L_136 = V_4;
		if ((!(((uint32_t)L_135) == ((uint32_t)L_136))))
		{
			goto IL_02a2;
		}
	}
	{
		int32_t L_137 = V_7;
		__this->___root = L_137;
	}

IL_02a2:
	{
		int32_t L_138 = V_4;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 47)))(__this, L_138, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 47));
		V_4 = 0;
		goto IL_02e4;
	}

IL_02af:
	{
		int32_t L_139 = V_4;
		int32_t L_140;
		L_140 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_139, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_140)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		if (L_141)
		{
			goto IL_02c9;
		}
	}
	{
		int32_t L_142 = ___1_z_id;
		int32_t L_143 = V_4;
		if ((((int32_t)L_142) == ((int32_t)L_143)))
		{
			goto IL_02c9;
		}
	}
	{
		Exception_t* L_144;
		L_144 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)10), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_144, method);
	}

IL_02c9:
	{
		int32_t L_145 = ___0_root_id;
		if (!L_145)
		{
			goto IL_02e4;
		}
	}
	{
		int32_t L_146 = V_4;
		int32_t L_147 = ___0_root_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_146, L_147, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		int32_t L_148 = V_4;
		int32_t L_149 = ___0_root_id;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_149, (Il2CppFullySharedGenericAny*)L_150);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 30), __this, L_148, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_150: *(void**)L_150));
	}

IL_02e4:
	{
		int32_t L_151 = V_1;
		int32_t L_152 = ___1_z_id;
		if ((((int32_t)L_151) == ((int32_t)L_152)))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_153 = V_1;
		int32_t L_154 = ___1_z_id;
		int32_t L_155;
		L_155 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_154, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_153, L_155, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		int32_t L_156 = V_1;
		int32_t L_157 = ___1_z_id;
		int32_t L_158;
		L_158 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_157, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_156, L_158, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		int32_t L_159 = V_1;
		int32_t L_160 = ___1_z_id;
		int32_t L_161;
		L_161 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_160, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_159, L_161, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_162 = V_1;
		int32_t L_163 = ___1_z_id;
		int32_t L_164;
		L_164 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_163, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33)))(__this, L_162, L_164, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 33));
		int32_t L_165 = ___1_z_id;
		int32_t L_166;
		L_166 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_165, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		if (!L_166)
		{
			goto IL_036a;
		}
	}
	{
		int32_t L_167 = V_1;
		int32_t L_168 = ___1_z_id;
		int32_t L_169;
		L_169 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_168, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_167, L_169, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		int32_t L_170 = ___1_z_id;
		int32_t L_171;
		L_171 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_170, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_172;
		L_172 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_171, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_173 = ___1_z_id;
		if ((!(((uint32_t)L_172) == ((uint32_t)L_173))))
		{
			goto IL_035a;
		}
	}
	{
		int32_t L_174 = ___1_z_id;
		int32_t L_175;
		L_175 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_174, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_176 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31)))(__this, L_175, L_176, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 31));
		goto IL_0372;
	}

IL_035a:
	{
		int32_t L_177 = ___1_z_id;
		int32_t L_178;
		L_178 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_177, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_179 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26)))(__this, L_178, L_179, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		goto IL_0372;
	}

IL_036a:
	{
		int32_t L_180 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_180, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0372:
	{
		int32_t L_181 = ___1_z_id;
		int32_t L_182;
		L_182 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_181, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (!L_182)
		{
			goto IL_0389;
		}
	}
	{
		int32_t L_183 = ___1_z_id;
		int32_t L_184;
		L_184 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_183, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_185 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_184, L_185, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_0389:
	{
		int32_t L_186 = ___1_z_id;
		int32_t L_187;
		L_187 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_186, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_187)
		{
			goto IL_03a0;
		}
	}
	{
		int32_t L_188 = ___1_z_id;
		int32_t L_189;
		L_189 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_188, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_190 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27)))(__this, L_189, L_190, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
	}

IL_03a0:
	{
		int32_t L_191 = __this->___root;
		int32_t L_192 = ___1_z_id;
		if ((!(((uint32_t)L_191) == ((uint32_t)L_192))))
		{
			goto IL_03b2;
		}
	}
	{
		int32_t L_193 = V_1;
		__this->___root = L_193;
		goto IL_03b9;
	}

IL_03b2:
	{
		int32_t L_194 = ___0_root_id;
		int32_t L_195 = ___1_z_id;
		if ((!(((uint32_t)L_194) == ((uint32_t)L_195))))
		{
			goto IL_03b9;
		}
	}
	{
		int32_t L_196 = V_1;
		___0_root_id = L_196;
	}

IL_03b9:
	{
		int32_t L_197 = V_4;
		if (!L_197)
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_198 = V_4;
		int32_t L_199;
		L_199 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_198, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_200 = ___1_z_id;
		if ((!(((uint32_t)L_199) == ((uint32_t)L_200))))
		{
			goto IL_03d1;
		}
	}
	{
		int32_t L_201 = V_4;
		int32_t L_202 = V_1;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)))(__this, L_201, L_202, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
	}

IL_03d1:
	{
		int32_t L_203 = ___1_z_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 47)))(__this, L_203, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 47));
		int32_t L_204 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_204, 1));
		int32_t L_205 = ___1_z_id;
		return L_205;
	}
}
// Method Definition Index: 60767
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_RBDeleteFixup_m4C5BC376B3501605CBB3EC4462A8F609A543455E_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, int32_t ___1_x_id, int32_t ___2_px_id, int32_t ___3_mainTreeNodeID, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B24_0 = 0;
	int32_t G_B28_0 = 0;
	int32_t G_B34_0 = 0;
	int32_t G_B38_0 = 0;
	int32_t G_B47_0 = 0;
	int32_t G_B52_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B60_0 = 0;
	{
		int32_t L_0 = ___1_x_id;
		if (L_0)
		{
			goto IL_0305;
		}
	}
	{
		int32_t L_1 = ___2_px_id;
		if (L_1)
		{
			goto IL_0305;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		int32_t L_2 = ___1_x_id;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_3 = ___1_x_id;
		int32_t L_4 = ___1_x_id;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if ((((int32_t)L_3) == ((int32_t)L_6)))
		{
			goto IL_0033;
		}
	}

IL_0021:
	{
		int32_t L_7 = ___1_x_id;
		if (L_7)
		{
			goto IL_0168;
		}
	}
	{
		int32_t L_8 = ___2_px_id;
		int32_t L_9;
		L_9 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		if (L_9)
		{
			goto IL_0168;
		}
	}

IL_0033:
	{
		int32_t L_10 = ___1_x_id;
		if (!L_10)
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_11 = ___1_x_id;
		int32_t L_12;
		L_12 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_13;
		L_13 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B10_0 = L_13;
		goto IL_004c;
	}

IL_0045:
	{
		int32_t L_14 = ___2_px_id;
		int32_t L_15;
		L_15 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B10_0 = L_15;
	}

IL_004c:
	{
		V_0 = G_B10_0;
		int32_t L_16 = V_0;
		if (L_16)
		{
			goto IL_0058;
		}
	}
	{
		Exception_t* L_17;
		L_17 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)14), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, method);
	}

IL_0058:
	{
		int32_t L_18 = V_0;
		int32_t L_19;
		L_19 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if (L_19)
		{
			goto IL_0097;
		}
	}
	{
		int32_t L_20 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_20, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_21 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_21, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_22 = ___0_root_id;
		int32_t L_23 = ___2_px_id;
		int32_t L_24 = ___3_mainTreeNodeID;
		int32_t L_25;
		L_25 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(__this, L_22, L_23, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		___0_root_id = L_25;
		int32_t L_26 = ___1_x_id;
		if (!L_26)
		{
			goto IL_008f;
		}
	}
	{
		int32_t L_27 = ___1_x_id;
		int32_t L_28;
		L_28 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_29;
		L_29 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_28, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B16_0 = L_29;
		goto IL_0096;
	}

IL_008f:
	{
		int32_t L_30 = ___2_px_id;
		int32_t L_31;
		L_31 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_30, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B16_0 = L_31;
	}

IL_0096:
	{
		V_0 = G_B16_0;
	}

IL_0097:
	{
		int32_t L_32 = V_0;
		int32_t L_33;
		L_33 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_32, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_34;
		L_34 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_33, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_34) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_35 = V_0;
		int32_t L_36;
		L_36 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_35, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_37;
		L_37 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_36, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_37) == ((uint32_t)1))))
		{
			goto IL_00d0;
		}
	}
	{
		int32_t L_38 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_38, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_39 = ___2_px_id;
		___1_x_id = L_39;
		int32_t L_40 = ___2_px_id;
		int32_t L_41;
		L_41 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_40, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___2_px_id = L_41;
		goto IL_0305;
	}

IL_00d0:
	{
		int32_t L_42 = V_0;
		int32_t L_43;
		L_43 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_42, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_44;
		L_44 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_43, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_44) == ((uint32_t)1))))
		{
			goto IL_011c;
		}
	}
	{
		int32_t L_45 = V_0;
		int32_t L_46;
		L_46 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_46, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_47 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_47, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_48 = ___0_root_id;
		int32_t L_49 = V_0;
		int32_t L_50 = ___3_mainTreeNodeID;
		int32_t L_51;
		L_51 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_48, L_49, L_50, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_51;
		int32_t L_52 = ___1_x_id;
		if (!L_52)
		{
			goto IL_0114;
		}
	}
	{
		int32_t L_53 = ___1_x_id;
		int32_t L_54;
		L_54 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_53, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_55;
		L_55 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_54, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B24_0 = L_55;
		goto IL_011b;
	}

IL_0114:
	{
		int32_t L_56 = ___2_px_id;
		int32_t L_57;
		L_57 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_56, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		G_B24_0 = L_57;
	}

IL_011b:
	{
		V_0 = G_B24_0;
	}

IL_011c:
	{
		int32_t L_58 = V_0;
		int32_t L_59 = ___2_px_id;
		int32_t L_60;
		L_60 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_59, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_58, L_60, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_61 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_61, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_62 = V_0;
		int32_t L_63;
		L_63 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_62, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_63, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_64 = ___0_root_id;
		int32_t L_65 = ___2_px_id;
		int32_t L_66 = ___3_mainTreeNodeID;
		int32_t L_67;
		L_67 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(__this, L_64, L_65, L_66, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		___0_root_id = L_67;
		int32_t L_68 = ___0_root_id;
		if (!L_68)
		{
			goto IL_0152;
		}
	}
	{
		int32_t L_69 = ___0_root_id;
		G_B28_0 = L_69;
		goto IL_0158;
	}

IL_0152:
	{
		int32_t L_70 = __this->___root;
		G_B28_0 = L_70;
	}

IL_0158:
	{
		___1_x_id = G_B28_0;
		int32_t L_71 = ___1_x_id;
		int32_t L_72;
		L_72 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_71, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___2_px_id = L_72;
		goto IL_0305;
	}

IL_0168:
	{
		int32_t L_73 = ___2_px_id;
		int32_t L_74;
		L_74 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_73, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_74;
		int32_t L_75 = V_0;
		int32_t L_76;
		L_76 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_75, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if (L_76)
		{
			goto IL_01ed;
		}
	}
	{
		int32_t L_77 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_77, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_78 = ___1_x_id;
		if (!L_78)
		{
			goto IL_01b4;
		}
	}
	{
		int32_t L_79 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_79, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_80 = ___0_root_id;
		int32_t L_81 = ___2_px_id;
		int32_t L_82 = ___3_mainTreeNodeID;
		int32_t L_83;
		L_83 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_80, L_81, L_82, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_83;
		int32_t L_84 = ___1_x_id;
		if (!L_84)
		{
			goto IL_01aa;
		}
	}
	{
		int32_t L_85 = ___1_x_id;
		int32_t L_86;
		L_86 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_85, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_87;
		L_87 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_86, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B34_0 = L_87;
		goto IL_01b1;
	}

IL_01aa:
	{
		int32_t L_88 = ___2_px_id;
		int32_t L_89;
		L_89 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_88, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B34_0 = L_89;
	}

IL_01b1:
	{
		V_0 = G_B34_0;
		goto IL_01ed;
	}

IL_01b4:
	{
		int32_t L_90 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_90, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_91 = ___0_root_id;
		int32_t L_92 = ___2_px_id;
		int32_t L_93 = ___3_mainTreeNodeID;
		int32_t L_94;
		L_94 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_91, L_92, L_93, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_94;
		int32_t L_95 = ___1_x_id;
		if (!L_95)
		{
			goto IL_01da;
		}
	}
	{
		int32_t L_96 = ___1_x_id;
		int32_t L_97;
		L_97 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_96, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_98;
		L_98 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_97, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B38_0 = L_98;
		goto IL_01e1;
	}

IL_01da:
	{
		int32_t L_99 = ___2_px_id;
		int32_t L_100;
		L_100 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_99, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B38_0 = L_100;
	}

IL_01e1:
	{
		V_0 = G_B38_0;
		int32_t L_101 = V_0;
		if (L_101)
		{
			goto IL_01ed;
		}
	}
	{
		Exception_t* L_102;
		L_102 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)11), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_102, method);
	}

IL_01ed:
	{
		int32_t L_103 = V_0;
		int32_t L_104;
		L_104 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_103, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_105;
		L_105 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_104, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_105) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_106 = V_0;
		int32_t L_107;
		L_107 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_106, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_108;
		L_108 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_107, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_108) == ((uint32_t)1))))
		{
			goto IL_0226;
		}
	}
	{
		int32_t L_109 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_109, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_110 = ___2_px_id;
		___1_x_id = L_110;
		int32_t L_111 = ___2_px_id;
		int32_t L_112;
		L_112 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_111, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___2_px_id = L_112;
		goto IL_0305;
	}

IL_0226:
	{
		int32_t L_113 = V_0;
		int32_t L_114;
		L_114 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_113, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_115;
		L_115 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_114, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((!(((uint32_t)L_115) == ((uint32_t)1))))
		{
			goto IL_0272;
		}
	}
	{
		int32_t L_116 = V_0;
		int32_t L_117;
		L_117 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_116, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_117, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_118 = V_0;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_118, (int32_t)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_119 = ___0_root_id;
		int32_t L_120 = V_0;
		int32_t L_121 = ___3_mainTreeNodeID;
		int32_t L_122;
		L_122 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(__this, L_119, L_120, L_121, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		___0_root_id = L_122;
		int32_t L_123 = ___1_x_id;
		if (!L_123)
		{
			goto IL_026a;
		}
	}
	{
		int32_t L_124 = ___1_x_id;
		int32_t L_125;
		L_125 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_124, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		int32_t L_126;
		L_126 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_125, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B47_0 = L_126;
		goto IL_0271;
	}

IL_026a:
	{
		int32_t L_127 = ___2_px_id;
		int32_t L_128;
		L_128 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_127, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		G_B47_0 = L_128;
	}

IL_0271:
	{
		V_0 = G_B47_0;
	}

IL_0272:
	{
		int32_t L_129 = ___1_x_id;
		if (!L_129)
		{
			goto IL_02be;
		}
	}
	{
		int32_t L_130 = V_0;
		int32_t L_131 = ___2_px_id;
		int32_t L_132;
		L_132 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_131, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_130, L_132, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_133 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_133, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_134 = V_0;
		int32_t L_135;
		L_135 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_134, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_135, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_136 = ___0_root_id;
		int32_t L_137 = ___2_px_id;
		int32_t L_138 = ___3_mainTreeNodeID;
		int32_t L_139;
		L_139 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_136, L_137, L_138, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_139;
		int32_t L_140 = ___0_root_id;
		if (!L_140)
		{
			goto IL_02ab;
		}
	}
	{
		int32_t L_141 = ___0_root_id;
		G_B52_0 = L_141;
		goto IL_02b1;
	}

IL_02ab:
	{
		int32_t L_142 = __this->___root;
		G_B52_0 = L_142;
	}

IL_02b1:
	{
		___1_x_id = G_B52_0;
		int32_t L_143 = ___1_x_id;
		int32_t L_144;
		L_144 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_143, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___2_px_id = L_144;
		goto IL_0305;
	}

IL_02be:
	{
		int32_t L_145 = V_0;
		int32_t L_146 = ___2_px_id;
		int32_t L_147;
		L_147 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_146, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_145, L_147, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_148 = ___2_px_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_148, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_149 = V_0;
		int32_t L_150;
		L_150 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_149, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_150, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_151 = ___0_root_id;
		int32_t L_152 = ___2_px_id;
		int32_t L_153 = ___3_mainTreeNodeID;
		int32_t L_154;
		L_154 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(__this, L_151, L_152, L_153, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
		___0_root_id = L_154;
		int32_t L_155 = ___0_root_id;
		if (!L_155)
		{
			goto IL_02f4;
		}
	}
	{
		int32_t L_156 = ___0_root_id;
		G_B56_0 = L_156;
		goto IL_02fa;
	}

IL_02f4:
	{
		int32_t L_157 = __this->___root;
		G_B56_0 = L_157;
	}

IL_02fa:
	{
		___1_x_id = G_B56_0;
		int32_t L_158 = ___1_x_id;
		int32_t L_159;
		L_159 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_158, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		___2_px_id = L_159;
	}

IL_0305:
	{
		int32_t L_160 = ___0_root_id;
		if (!L_160)
		{
			goto IL_030b;
		}
	}
	{
		int32_t L_161 = ___0_root_id;
		G_B60_0 = L_161;
		goto IL_0311;
	}

IL_030b:
	{
		int32_t L_162 = __this->___root;
		G_B60_0 = L_162;
	}

IL_0311:
	{
		int32_t L_163 = ___1_x_id;
		if ((((int32_t)G_B60_0) == ((int32_t)L_163)))
		{
			goto IL_0321;
		}
	}
	{
		int32_t L_164 = ___1_x_id;
		int32_t L_165;
		L_165 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(__this, L_164, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
		if ((((int32_t)L_165) == ((int32_t)1)))
		{
			goto IL_000e;
		}
	}

IL_0321:
	{
		int32_t L_166 = ___1_x_id;
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, L_166, (int32_t)1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		int32_t L_167 = ___0_root_id;
		return L_167;
	}
}
// Method Definition Index: 60768
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SearchSubTree_m2278FCE2C8A319A28EACB9E33A2ABDE22DA6BD9D_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_root_id, Il2CppFullySharedGenericAny ___1_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_11 = L_7;
	const Il2CppFullySharedGenericAny L_9 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_13 = L_9;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B10_0 = 0;
	{
		int32_t L_0 = ___0_root_id;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_1 = __this->____accessMethod;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0014;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)17), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		int32_t L_3 = ___0_root_id;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_4 = ___0_root_id;
		G_B6_0 = L_4;
		goto IL_0020;
	}

IL_001a:
	{
		int32_t L_5 = __this->___root;
		G_B6_0 = L_5;
	}

IL_0020:
	{
		V_0 = G_B6_0;
		goto IL_005e;
	}

IL_0023:
	{
		int32_t L_6 = ___0_root_id;
		if (!L_6)
		{
			goto IL_0036;
		}
	}
	{
		il2cpp_codegen_memcpy(L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_key : &___1_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_8 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_8, (Il2CppFullySharedGenericAny*)L_9);
		int32_t L_10;
		L_10 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(6, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_7: *(void**)L_7), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_9: *(void**)L_9));
		G_B10_0 = L_10;
		goto IL_0044;
	}

IL_0036:
	{
		il2cpp_codegen_memcpy(L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_key : &___1_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_12 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_12, (Il2CppFullySharedGenericAny*)L_13);
		int32_t L_14;
		L_14 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(5, __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_11: *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_13: *(void**)L_13));
		G_B10_0 = L_14;
	}

IL_0044:
	{
		V_1 = G_B10_0;
		int32_t L_15 = V_1;
		if (!L_15)
		{
			goto IL_0061;
		}
	}
	{
		int32_t L_16 = V_1;
		if ((((int32_t)L_16) >= ((int32_t)0)))
		{
			goto IL_0056;
		}
	}
	{
		int32_t L_17 = V_0;
		int32_t L_18;
		L_18 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_17, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_18;
		goto IL_005e;
	}

IL_0056:
	{
		int32_t L_19 = V_0;
		int32_t L_20;
		L_20 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_19, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_0 = L_20;
	}

IL_005e:
	{
		int32_t L_21 = V_0;
		if (L_21)
		{
			goto IL_0023;
		}
	}

IL_0061:
	{
		int32_t L_22 = V_0;
		return L_22;
	}
}
// Method Definition Index: 60769
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_get_Item_m85A0DAC718D879C1747AD809D10B1006AAA05662_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_index;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_1;
		L_1 = ((  NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 42));
		int32_t L_2 = L_1.____nodeID;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_2, (Il2CppFullySharedGenericAny*)L_3);
		il2cpp_codegen_memcpy(il2cppRetVal, L_3, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		return;
	}
}
// Method Definition Index: 60770
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 RBTree_1_GetNodeByKey_m7736051017CCB2750196AC4F1D5AEBE09FD3CC26_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	void* L_14 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_6 = L_0;
	const Il2CppFullySharedGenericAny L_11 = L_0;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	memset(V_1, 0, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_key : &___0_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_1;
		L_1 = InvokerFuncInvoker2< int32_t, int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48), __this, 0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_3)
		{
			goto IL_0027;
		}
	}
	{
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_key : &___0_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_7;
		L_7 = InvokerFuncInvoker2< int32_t, int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48), __this, L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_6: *(void**)L_6));
		int32_t L_8 = V_0;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_9;
		memset((&L_9), 0, sizeof(L_9));
		NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55((&L_9), L_7, L_8, NULL);
		return L_9;
	}

IL_0027:
	{
		int32_t L_10 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_10, (Il2CppFullySharedGenericAny*)L_11);
		il2cpp_codegen_memcpy(V_1, L_11, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		il2cpp_codegen_memcpy(L_12, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_key : &___0_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		RuntimeObject* L_13 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), L_12);
		Il2CppConstrainedCallData L_15;
		Il2CppMethodPointer L_16 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 50), (void*)(Il2CppFullySharedGenericAny*)V_1, &L_15, L_14);
		typedef bool ( *func_L_17)(void*,RuntimeObject*,const RuntimeMethod*);
		bool L_18 = ((func_L_17)L_16)(L_15.thisPtr, L_13,L_15.method);
		if (L_18)
		{
			goto IL_0046;
		}
	}
	{
		V_0 = 0;
	}

IL_0046:
	{
		int32_t L_19 = V_0;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_20;
		memset((&L_20), 0, sizeof(L_20));
		NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55((&L_20), L_19, 0, NULL);
		return L_20;
	}
}
// Method Definition Index: 60771
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByKey_mEBD7E91CE8BCB72BF19E7B466A02A74B7C60162D_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (-1);
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_key : &___0_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_1;
		L_1 = InvokerFuncInvoker1< NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 41), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_1 = L_1;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_2 = V_1;
		int32_t L_3 = L_2.____nodeID;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_4 = V_1;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 51)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 51));
		V_0 = L_5;
	}

IL_001a:
	{
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60772
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNode_m85C331EF6ABB3A54A54B0F9C544FC49C92DBB784_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_node, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_1 = ___0_node;
		int32_t L_2;
		L_2 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52)))(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52));
		return L_2;
	}

IL_0010:
	{
		int32_t L_3 = ___0_node;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = ___0_node;
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53));
		return L_6;
	}

IL_0021:
	{
		int32_t L_7 = ___0_node;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_7, (Il2CppFullySharedGenericAny*)L_8);
		int32_t L_9;
		L_9 = InvokerFuncInvoker2< int32_t, int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 48), __this, 0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_8: *(void**)L_8));
		V_0 = L_9;
		int32_t L_10 = V_0;
		int32_t L_11 = ___0_node;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_12 = ___0_node;
		int32_t L_13;
		L_13 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53)))(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53));
		return L_13;
	}

IL_003c:
	{
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53)))(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53));
		int32_t L_16 = ___0_node;
		int32_t L_17;
		L_17 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52)))(__this, L_16, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52));
		return ((int32_t)il2cpp_codegen_add(L_15, L_17));
	}
}
// Method Definition Index: 60773
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_GetIndexByNodePath_mCCD9781FA9066FD744A29AB45B6F531715F0E6DD_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 ___0_path, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_0015;
		}
	}
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_1 = ___0_path;
		int32_t L_2 = L_1.____nodeID;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52));
		return L_3;
	}

IL_0015:
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_4 = ___0_path;
		int32_t L_5 = L_4.____mainTreeNodeID;
		if (L_5)
		{
			goto IL_002a;
		}
	}
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_6 = ___0_path;
		int32_t L_7 = L_6.____nodeID;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53)))(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53));
		return L_8;
	}

IL_002a:
	{
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_9 = ___0_path;
		int32_t L_10 = L_9.____mainTreeNodeID;
		int32_t L_11;
		L_11 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 53));
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_12 = ___0_path;
		int32_t L_13 = L_12.____nodeID;
		int32_t L_14;
		L_14 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 52));
		return ((int32_t)il2cpp_codegen_add(L_11, L_14));
	}
}
// Method Definition Index: 60774
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexByNode_m4BD522857AD09DBF84332DAD3B8A1BBBDAC39770_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_2;
		L_2 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_0 = L_2;
		goto IL_0037;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_11;
		L_11 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(L_11, 1))));
	}

IL_0034:
	{
		int32_t L_12 = V_1;
		___0_nodeId = L_12;
	}

IL_0037:
	{
		int32_t L_13 = ___0_nodeId;
		if (L_13)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_14 = V_0;
		return L_14;
	}
}
// Method Definition Index: 60775
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeIndexWithSatelliteByNode_m37F70B5D75DD15DF915B5B22BF81A1F929BA2D1B_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B4_1 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B5_1 = 0;
	int32_t G_B5_2 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_2;
		L_2 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_0 = L_2;
		goto IL_004f;
	}

IL_0010:
	{
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22));
		V_1 = L_4;
		int32_t L_5 = ___0_nodeId;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if ((!(((uint32_t)L_5) == ((uint32_t)L_7))))
		{
			goto IL_004c;
		}
	}
	{
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10;
		L_10 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_11;
		L_11 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_12 = V_1;
		int32_t L_13;
		L_13 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_13)
		{
			G_B4_0 = L_11;
			G_B4_1 = L_8;
			goto IL_0048;
		}
		G_B3_0 = L_11;
		G_B3_1 = L_8;
	}
	{
		int32_t L_14 = V_1;
		int32_t L_15;
		L_15 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_16;
		L_16 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_15, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B5_0 = L_16;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		goto IL_0049;
	}

IL_0048:
	{
		G_B5_0 = 1;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
	}

IL_0049:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B5_2, ((int32_t)il2cpp_codegen_add(G_B5_1, G_B5_0))));
	}

IL_004c:
	{
		int32_t L_17 = V_1;
		___0_nodeId = L_17;
	}

IL_004f:
	{
		int32_t L_18 = ___0_nodeId;
		if (L_18)
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_19 = V_0;
		return L_19;
	}
}
// Method Definition Index: 60776
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 RBTree_1_GetNodeByIndex_m785467854C87C957E6DF39F1E24C0EDDD20BA8A0_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_userIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____inUseSatelliteTreeCount;
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1 = __this->___root;
		int32_t L_2 = ___0_userIndex;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 54)))(__this, L_1, ((int32_t)il2cpp_codegen_add(L_2, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 54));
		V_0 = L_3;
		V_1 = 0;
		goto IL_0026;
	}

IL_001c:
	{
		int32_t L_4 = ___0_userIndex;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 55)))(__this, L_4, (&V_1), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 55));
		V_0 = L_5;
	}

IL_0026:
	{
		int32_t L_6 = V_0;
		if (L_6)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_7 = __this->____accessMethod;
		if ((!(((uint32_t)2) == ((uint32_t)L_7))))
		{
			goto IL_0039;
		}
	}
	{
		int32_t L_8 = ___0_userIndex;
		Exception_t* L_9;
		L_9 = ExceptionBuilder_RowOutOfRange_m2F6883E5D2F9AF63A3F9DC5521799A7E270F1054(L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0039:
	{
		Exception_t* L_10;
		L_10 = ExceptionBuilder_InternalRBTreeError_mC54DE62BCDD6D7AE0FA4F9B4CC9598ED1E239462(((int32_t)13), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, method);
	}

IL_0041:
	{
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		NodePath_tC3CDC05C2DFAD35988FD6B5F84FAD7417B313813 L_13;
		memset((&L_13), 0, sizeof(L_13));
		NodePath__ctor_mA9A74612E0785F30CCC660C7936418FD57A9EB55((&L_13), L_11, L_12, NULL);
		return L_13;
	}
}
// Method Definition Index: 60777
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_m5A99A44B5A7E1A488A4AEBF6F2EEE08707732A51_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_index, int32_t* ___1_satelliteRootId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_index;
		___0_index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t* L_1 = ___1_satelliteRootId;
		*(L_1) = 0;
		int32_t L_2 = __this->___root;
		V_0 = L_2;
		V_1 = (-1);
		goto IL_0088;
	}

IL_0013:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = V_1;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_5 = V_0;
		int32_t L_6;
		L_6 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_6;
		goto IL_0088;
	}

IL_0021:
	{
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_7, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_8)
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_005b;
		}
	}
	{
		int32_t L_11 = ___0_index;
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		int32_t L_14;
		L_14 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_15;
		L_15 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		if ((((int32_t)L_11) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_12, L_15)), 1)))))
		{
			goto IL_005b;
		}
	}
	{
		int32_t* L_16 = ___1_satelliteRootId;
		int32_t L_17 = V_0;
		*(L_16) = L_17;
		int32_t L_18 = ___0_index;
		int32_t L_19 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_18, L_19)), 1));
		int32_t L_20 = V_0;
		int32_t L_21;
		L_21 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_22 = ___0_index;
		int32_t L_23;
		L_23 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 54)))(__this, L_21, L_22, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 54));
		return L_23;
	}

IL_005b:
	{
		int32_t L_24 = V_0;
		int32_t L_25;
		L_25 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (L_25)
		{
			goto IL_006b;
		}
	}
	{
		int32_t L_26 = ___0_index;
		int32_t L_27 = V_1;
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_26, L_27));
		goto IL_0080;
	}

IL_006b:
	{
		int32_t L_28 = ___0_index;
		int32_t L_29 = V_1;
		int32_t L_30 = V_0;
		int32_t L_31;
		L_31 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_30, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_32;
		L_32 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		___0_index = ((int32_t)il2cpp_codegen_subtract(L_28, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_29, L_32)), 1))));
	}

IL_0080:
	{
		int32_t L_33 = V_0;
		int32_t L_34;
		L_34 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_33, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		V_0 = L_34;
	}

IL_0088:
	{
		int32_t L_35 = V_0;
		if (!L_35)
		{
			goto IL_00ae;
		}
	}
	{
		int32_t L_36 = V_0;
		int32_t L_37;
		L_37 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_36, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_38;
		L_38 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_37, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_39 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		V_1 = L_39;
		int32_t L_40 = ___0_index;
		if ((!(((uint32_t)L_39) == ((uint32_t)L_40))))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_41 = V_0;
		int32_t L_42;
		L_42 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_41, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (L_42)
		{
			goto IL_0013;
		}
	}

IL_00ae:
	{
		int32_t L_43 = V_0;
		return L_43;
	}
}
// Method Definition Index: 60778
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_ComputeNodeByIndex_mC622BB66DA9CB9B5D7A9216C58D644D7EB3DD7E9_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_x_id, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		goto IL_002f;
	}

IL_0002:
	{
		int32_t L_0 = ___0_x_id;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
		int32_t L_4 = ___1_index;
		int32_t L_5 = V_1;
		if ((((int32_t)L_4) >= ((int32_t)L_5)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_6 = V_0;
		___0_x_id = L_6;
		goto IL_002f;
	}

IL_001d:
	{
		int32_t L_7 = V_1;
		int32_t L_8 = ___1_index;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_9 = ___0_x_id;
		int32_t L_10;
		L_10 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		___0_x_id = L_10;
		int32_t L_11 = ___1_index;
		int32_t L_12 = V_1;
		___1_index = ((int32_t)il2cpp_codegen_subtract(L_11, L_12));
	}

IL_002f:
	{
		int32_t L_13 = ___0_x_id;
		if (L_13)
		{
			goto IL_0002;
		}
	}

IL_0032:
	{
		int32_t L_14 = ___0_x_id;
		return L_14;
	}
}
// Method Definition Index: 60779
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m72B2F6B40374976463F8F11A2E7EFA79E9895F72_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_item : &___0_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)))(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60780
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Add_m99EC94C01E9CB2E9D21E5E181C4F62511039ECC0_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___0_item : &___0_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3;
		L_3 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)))(__this, 0, L_2, 0, (-1), (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 60781
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* RBTree_1_GetEnumerator_m9D7F6878151960C910609477C2ABDDC403196DA5_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_RBTreeEnumerator_t188BAFBAF6823188AEC40919D521E38F9A520E21 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 56));
	const RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4 L_0 = alloca(SizeOf_RBTreeEnumerator_t188BAFBAF6823188AEC40919D521E38F9A520E21);
	//<source_info:<no-source>:1>
	{
		memset(L_0, 0, SizeOf_RBTreeEnumerator_t188BAFBAF6823188AEC40919D521E38F9A520E21);
		RBTreeEnumerator__ctor_m4F958B5E04B28EDEA0C7B8FB8E7CF4ED0739BBEB((RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 57));
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 56), L_0);
		return (RuntimeObject*)L_1;
	}
}
// Method Definition Index: 60782
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_IndexOf_m767C56D618F4D7DBEE641E476C3F836EB24AA7F0_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, Il2CppFullySharedGenericAny ___1_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	const Il2CppFullySharedGenericAny L_10 = L_2;
	const Il2CppFullySharedGenericAny L_16 = L_2;
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		int32_t L_0 = ___0_nodeId;
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_1 = ___0_nodeId;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_1, (Il2CppFullySharedGenericAny*)L_2);
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), L_2);
		il2cpp_codegen_memcpy(L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_item : &___1_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		RuntimeObject* L_5 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), L_4);
		if ((!(((RuntimeObject*)(RuntimeObject*)L_3) == ((RuntimeObject*)(RuntimeObject*)L_5))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 58)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 58));
		return L_7;
	}

IL_0021:
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		il2cpp_codegen_memcpy(L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_item : &___1_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_11;
		L_11 = InvokerFuncInvoker2< int32_t, int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59), __this, L_9, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_10: *(void**)L_10));
		int32_t L_12 = L_11;
		V_0 = L_12;
		if ((((int32_t)L_12) == ((int32_t)(-1))))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_13 = V_0;
		return L_13;
	}

IL_0036:
	{
		int32_t L_14 = ___0_nodeId;
		int32_t L_15;
		L_15 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_14, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		il2cpp_codegen_memcpy(L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_item : &___1_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_17;
		L_17 = InvokerFuncInvoker2< int32_t, int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 59), __this, L_15, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_16: *(void**)L_16));
		int32_t L_18 = L_17;
		V_0 = L_18;
		int32_t L_19 = V_0;
		return L_19;
	}

IL_004b:
	{
		int32_t L_20 = V_0;
		return L_20;
	}
}
// Method Definition Index: 60783
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Insert_m44FF7B0BC249D62C2E28589FF039A4EEF9DC55C8_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_position, Il2CppFullySharedGenericAny ___1_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_item : &___1_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_2;
		L_2 = InvokerFuncInvoker3< int32_t, int32_t, Il2CppFullySharedGenericAny, bool >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 60)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 60), __this, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_1: *(void**)L_1), (bool)0);
		return L_2;
	}
}
// Method Definition Index: 60784
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_InsertAt_m39D83D8BDDEFD5C40F2C4C4BD7BD556341B316E4_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_position, Il2CppFullySharedGenericAny ___1_item, bool ___2_append, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_item : &___1_item), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		int32_t L_3 = ___0_position;
		bool L_4 = ___2_append;
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, int32_t, int32_t, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)))(__this, 0, L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
		int32_t L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 60785
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RemoveAt_m5EFA6893968F369AEE898859486614F2FD2EEB02_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_position, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_position;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 61)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 61), __this, L_0, (Il2CppFullySharedGenericAny*)L_1);
		return;
	}
}
// Method Definition Index: 60786
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Clear_m2F337DD5E6F78CF3EAD08BFB57FC0FBF19822999_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		((  void (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		return;
	}
}
// Method Definition Index: 60787
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_m6F0141E8C8CC4850142C26331F405F768437E491_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 62)))(__this, NULL);
		V_0 = L_4;
		RuntimeArray* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = il2cpp_codegen_array_get_length(L_5);
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 62)))(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_003a;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003a:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_1 = L_11;
		V_2 = 0;
		goto IL_006c;
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		int32_t L_13 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_13, (Il2CppFullySharedGenericAny*)L_14);
		RuntimeObject* L_15 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), L_14);
		int32_t L_16 = ___1_index;
		int32_t L_17 = V_2;
		NullCheck(L_12);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_12, L_15, ((int32_t)il2cpp_codegen_add(L_16, L_17)), NULL);
		int32_t L_18 = V_1;
		int32_t L_19;
		L_19 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		V_1 = L_19;
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_006c:
	{
		int32_t L_21 = V_2;
		int32_t L_22 = V_0;
		if ((((int32_t)L_21) < ((int32_t)L_22)))
		{
			goto IL_004b;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60788
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_CopyTo_mC720E37075EC229C1E6F1C22CBC20D1D9F7B2605_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Exception_t* L_1;
		L_1 = ExceptionBuilder_ArgumentNull_m2F21453F5BE7814A0D05A058EAC09F2391F99DA8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		Exception_t* L_3;
		L_3 = ExceptionBuilder_ArgumentOutOfRange_mEF2909680ADBD4B5228E611EDEBBA048D7DF219E(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, method);
	}

IL_001d:
	{
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 62)))(__this, NULL);
		V_0 = L_4;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = ___0_array;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		int32_t L_7 = ___1_index;
		int32_t L_8;
		L_8 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 62)))(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_6, L_7))) >= ((int32_t)L_8)))
		{
			goto IL_0037;
		}
	}
	{
		Exception_t* L_9;
		L_9 = ExceptionBuilder_InvalidOffsetLength_m25F593A3DD72EEDCF3B7F8616D41CD7677BD6073(NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_0037:
	{
		int32_t L_10 = __this->___root;
		int32_t L_11;
		L_11 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		V_1 = L_11;
		V_2 = 0;
		goto IL_0064;
	}

IL_0048:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = ___0_array;
		int32_t L_13 = ___1_index;
		int32_t L_14 = V_2;
		int32_t L_15 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_15, (Il2CppFullySharedGenericAny*)L_16);
		NullCheck(L_12);
		il2cpp_codegen_memcpy((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_13, L_14)))), L_16, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18), (void**)(L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_13, L_14)))), (void*)L_16);
		int32_t L_17 = V_1;
		int32_t L_18;
		L_18 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_17, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
		V_1 = L_18;
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0064:
	{
		int32_t L_20 = V_2;
		int32_t L_21 = V_0;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0048;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 60789
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetRight_m6F5B716EE80A355903BCCA9790D60EF179D27BCC_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_rightNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_rightNodeId;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 63), L_6);
		return;
	}
}
// Method Definition Index: 60790
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetLeft_m018576202FE808F71D7478B1004BB62A05ECEC29_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_leftNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_leftNodeId;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 64), L_6);
		return;
	}
}
// Method Definition Index: 60791
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetParent_mFBD5736CB91D6AF80E3C3F57D1D8A8BC0953F3EE_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_parentNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_parentNodeId;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 65), L_6);
		return;
	}
}
// Method Definition Index: 60792
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetColor_m0FF237931B977BD5E629AF6993C80773B88A20D7_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_color, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_color;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),7), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4), L_6);
		return;
	}
}
// Method Definition Index: 60793
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetKey_mA92267EE8B84DEBE9075BAF163C41EDE909D313A_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, Il2CppFullySharedGenericAny ___1_key, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18)) ? ___1_key : &___1_key), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		il2cpp_codegen_write_field_data<true>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),6), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 19), L_6, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		return;
	}
}
// Method Definition Index: 60794
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetNext_mADC0112FA54C31B0526CD220A36EC0D0BE6DECEC_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_nextNodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_nextNodeId;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),4), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 66), L_6);
		return;
	}
}
// Method Definition Index: 60795
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_SetSubTreeSize_m7B104E358671726D410173B7EA56D1FBF7D34FEC_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, int32_t ___1_size, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = ___1_size;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),5), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17), L_6);
		return;
	}
}
// Method Definition Index: 60796
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_IncreaseSize_m04BE1A67C29114844EF7BB7614574300318F7633_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (((int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17))));
		int32_t L_7 = *(L_6);
		*(L_6) = ((int32_t)il2cpp_codegen_add(L_7, 1));
		return;
	}
}
// Method Definition Index: 60797
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_RecomputeSize_m98DBD4256E245820230442566B20819D6DE055C9_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		int32_t L_0 = ___0_nodeId;
		int32_t L_1;
		L_1 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)))(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25));
		int32_t L_2;
		L_2 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_3 = ___0_nodeId;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		int32_t L_5;
		L_5 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		int32_t L_6 = ___0_nodeId;
		int32_t L_7;
		L_7 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_6, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		if (!L_7)
		{
			G_B2_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
			goto IL_0033;
		}
		G_B1_0 = ((int32_t)il2cpp_codegen_add(L_2, L_5));
	}
	{
		int32_t L_8 = ___0_nodeId;
		int32_t L_9;
		L_9 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		int32_t L_10;
		L_10 = ((  int32_t (*) (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32)))(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 32));
		G_B3_0 = L_10;
		G_B3_1 = G_B1_0;
		goto IL_0034;
	}

IL_0033:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0034:
	{
		V_0 = ((int32_t)il2cpp_codegen_add(G_B3_1, G_B3_0));
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_11 = __this->____pageTable;
		int32_t L_12 = ___0_nodeId;
		NullCheck(L_11);
		int32_t L_13 = ((int32_t)(L_12>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		NullCheck(L_14);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_15 = L_14->____slots;
		int32_t L_16 = ___0_nodeId;
		NullCheck(L_15);
		int32_t L_17 = V_0;
		il2cpp_codegen_write_field_data<int32_t, false>(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_16&((int32_t)65535)))))), il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),5), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17), L_17);
		return;
	}
}
// Method Definition Index: 60798
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_DecreaseSize_m90DA6F839AE945A03A30067022DFCD4D8DBCC067_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t* L_6 = (((int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17))));
		int32_t L_7 = *(L_6);
		*(L_6) = ((int32_t)il2cpp_codegen_subtract(L_7, 1));
		return;
	}
}
// Method Definition Index: 60799
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Right_m72E92B4214A615E1B1B09B864AD39DC358B0D9C5_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 63));
		return L_6;
	}
}
// Method Definition Index: 60800
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Left_m8EB18280FCE53424D1FD85A226F086C0DD99FFE6_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 64));
		return L_6;
	}
}
// Method Definition Index: 60801
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Parent_m68954856B3FCE9D08DE6BB7F530C1478DC4DFFDF_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 65));
		return L_6;
	}
}
// Method Definition Index: 60802
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_color_m11914A147E9CE03DEED0F5E1AD43EE14B93D4992_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		return L_6;
	}
}
// Method Definition Index: 60803
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_Next_mA15C645FF3AB14F076524B8C9B4631043371261E_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 66));
		return L_6;
	}
}
// Method Definition Index: 60804
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RBTree_1_SubTreeSize_mD0C8957CB8532F9EAF837964D1139F21E7AE696D_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		int32_t L_6 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 17));
		return L_6;
	}
}
// Method Definition Index: 60805
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RBTree_1_Key_m136C79232025E1CED0F197E7831540B33BE235A6_fshared (RBTree_1_t09C68EFC34FF48F9CAFF6208FB96D1C35CFCDA56* __this, int32_t ___0_nodeId, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
	//<source_info:<no-source>:1>
	{
		TreePageU5BU5D_t9AC380B77C33ACDAD0841FE923B2F5F66B02FCF9* L_0 = __this->____pageTable;
		int32_t L_1 = ___0_nodeId;
		NullCheck(L_0);
		int32_t L_2 = ((int32_t)(L_1>>((int32_t)16)));
		TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		NodeU5BU5D_t9EBDE2B4B8A6962AD214F9D2E76D66F654B07B07* L_4 = L_3->____slots;
		int32_t L_5 = ___0_nodeId;
		NullCheck(L_4);
		il2cpp_codegen_memcpy(L_6, il2cpp_codegen_get_field_data_pointer(((Node_t76C820C17DBF8E407C8589D8A78D7CF989ADF034*)(L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(((int32_t)(L_5&((int32_t)65535)))))), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 19)), SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		il2cpp_codegen_memcpy(il2cppRetVal, L_6, SizeOf_K_t725D041F314CEFF97DB70729BEC601CCFB8D8F14);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81831
// Method Definition Index: 81832
// Method Definition Index: 81833
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_mA78B963B3F0E2BB984306D5941DB9E622B31192A (RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = ((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)16)));
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		V_1 = 0;
		V_2 = L_1;
		goto IL_001b;
	}

IL_000e:
	{
		int32_t L_2 = V_1;
		int32_t L_3 = V_2;
		int32_t L_4;
		L_4 = RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m84FE82568F9EC0F33E541BAFB8DBD19DEC020514(__this, L_2, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_001b:
	{
		int32_t L_6 = V_2;
		int32_t L_7 = V_0;
		if ((((int32_t)L_6) < ((int32_t)L_7)))
		{
			goto IL_000e;
		}
	}
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_8 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_8)->___m_Buffer, L_9, (L_10));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_11 = __this->___counter;
		int32_t L_12;
		L_12 = RadixSortBatchPrefixSumJob_1_AtomicIncrement_m4176AE255919577013BEEA632E809CBB40F3B62F(L_11, NULL);
		if ((!(((uint32_t)L_12) == ((uint32_t)((int32_t)16)))))
		{
			goto IL_00f5;
		}
	}
	{
		V_3 = 0;
		int32_t L_13 = __this->___radix;
		int32_t L_14 = __this->___signBitRadixIndex;
		if ((((int32_t)L_13) == ((int32_t)L_14)))
		{
			goto IL_0083;
		}
	}
	{
		V_4 = 0;
		goto IL_007b;
	}

IL_0053:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_15 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_16 = V_4;
		int32_t L_17;
		L_17 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_15)->___m_Buffer, L_16);
		V_5 = L_17;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_18 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_19 = V_4;
		int32_t L_20 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_18)->___m_Buffer, L_19, (L_20));
		int32_t L_21 = V_3;
		int32_t L_22 = V_5;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, L_22));
		int32_t L_23 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007b:
	{
		int32_t L_24 = V_4;
		if ((((int32_t)L_24) < ((int32_t)((int32_t)16))))
		{
			goto IL_0053;
		}
	}
	{
		goto IL_00e8;
	}

IL_0083:
	{
		V_6 = 8;
		goto IL_00b0;
	}

IL_0088:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_25 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_26 = V_6;
		int32_t L_27;
		L_27 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_25)->___m_Buffer, L_26);
		V_7 = L_27;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_28 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_29 = V_6;
		int32_t L_30 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_28)->___m_Buffer, L_29, (L_30));
		int32_t L_31 = V_3;
		int32_t L_32 = V_7;
		V_3 = ((int32_t)il2cpp_codegen_add(L_31, L_32));
		int32_t L_33 = V_6;
		V_6 = ((int32_t)il2cpp_codegen_add(L_33, 1));
	}

IL_00b0:
	{
		int32_t L_34 = V_6;
		if ((((int32_t)L_34) < ((int32_t)((int32_t)16))))
		{
			goto IL_0088;
		}
	}
	{
		V_8 = 0;
		goto IL_00e3;
	}

IL_00bb:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_35 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_36 = V_8;
		int32_t L_37;
		L_37 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_35)->___m_Buffer, L_36);
		V_9 = L_37;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_38 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_39 = V_8;
		int32_t L_40 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_38)->___m_Buffer, L_39, (L_40));
		int32_t L_41 = V_3;
		int32_t L_42 = V_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_41, L_42));
		int32_t L_43 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_43, 1));
	}

IL_00e3:
	{
		int32_t L_44 = V_8;
		if ((((int32_t)L_44) < ((int32_t)8)))
		{
			goto IL_00bb;
		}
	}

IL_00e8:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_45 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___counter);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_45)->___m_Buffer, 0, (0));
	}

IL_00f5:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBatchPrefixSumJob_1_Execute_mA78B963B3F0E2BB984306D5941DB9E622B31192A_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBatchPrefixSumJob_1_tFCA504AFEF3CBEA61B4DD09B0FF86255FCD2F530>(__this);
	RadixSortBatchPrefixSumJob_1_Execute_mA78B963B3F0E2BB984306D5941DB9E622B31192A(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81831
// Method Definition Index: 81832
// Method Definition Index: 81833
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_m71DF9A259A4A7F5463EB48D94570811F2FC1D649 (RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = ((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)16)));
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		V_1 = 0;
		V_2 = L_1;
		goto IL_001b;
	}

IL_000e:
	{
		int32_t L_2 = V_1;
		int32_t L_3 = V_2;
		int32_t L_4;
		L_4 = RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_mCCD76D6B3B104F205739A21AE7FD43F594488F1F(__this, L_2, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_001b:
	{
		int32_t L_6 = V_2;
		int32_t L_7 = V_0;
		if ((((int32_t)L_6) < ((int32_t)L_7)))
		{
			goto IL_000e;
		}
	}
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_8 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_8)->___m_Buffer, L_9, (L_10));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_11 = __this->___counter;
		int32_t L_12;
		L_12 = RadixSortBatchPrefixSumJob_1_AtomicIncrement_mE5B6D6C23E3A09431E1528BA8084A165B13D9A98(L_11, NULL);
		if ((!(((uint32_t)L_12) == ((uint32_t)((int32_t)16)))))
		{
			goto IL_00f5;
		}
	}
	{
		V_3 = 0;
		int32_t L_13 = __this->___radix;
		int32_t L_14 = __this->___signBitRadixIndex;
		if ((((int32_t)L_13) == ((int32_t)L_14)))
		{
			goto IL_0083;
		}
	}
	{
		V_4 = 0;
		goto IL_007b;
	}

IL_0053:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_15 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_16 = V_4;
		int32_t L_17;
		L_17 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_15)->___m_Buffer, L_16);
		V_5 = L_17;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_18 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_19 = V_4;
		int32_t L_20 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_18)->___m_Buffer, L_19, (L_20));
		int32_t L_21 = V_3;
		int32_t L_22 = V_5;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, L_22));
		int32_t L_23 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007b:
	{
		int32_t L_24 = V_4;
		if ((((int32_t)L_24) < ((int32_t)((int32_t)16))))
		{
			goto IL_0053;
		}
	}
	{
		goto IL_00e8;
	}

IL_0083:
	{
		V_6 = 8;
		goto IL_00b0;
	}

IL_0088:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_25 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_26 = V_6;
		int32_t L_27;
		L_27 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_25)->___m_Buffer, L_26);
		V_7 = L_27;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_28 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_29 = V_6;
		int32_t L_30 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_28)->___m_Buffer, L_29, (L_30));
		int32_t L_31 = V_3;
		int32_t L_32 = V_7;
		V_3 = ((int32_t)il2cpp_codegen_add(L_31, L_32));
		int32_t L_33 = V_6;
		V_6 = ((int32_t)il2cpp_codegen_add(L_33, 1));
	}

IL_00b0:
	{
		int32_t L_34 = V_6;
		if ((((int32_t)L_34) < ((int32_t)((int32_t)16))))
		{
			goto IL_0088;
		}
	}
	{
		V_8 = 0;
		goto IL_00e3;
	}

IL_00bb:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_35 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_36 = V_8;
		int32_t L_37;
		L_37 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_35)->___m_Buffer, L_36);
		V_9 = L_37;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_38 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_39 = V_8;
		int32_t L_40 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_38)->___m_Buffer, L_39, (L_40));
		int32_t L_41 = V_3;
		int32_t L_42 = V_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_41, L_42));
		int32_t L_43 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_43, 1));
	}

IL_00e3:
	{
		int32_t L_44 = V_8;
		if ((((int32_t)L_44) < ((int32_t)8)))
		{
			goto IL_00bb;
		}
	}

IL_00e8:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_45 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___counter);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_45)->___m_Buffer, 0, (0));
	}

IL_00f5:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBatchPrefixSumJob_1_Execute_m71DF9A259A4A7F5463EB48D94570811F2FC1D649_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBatchPrefixSumJob_1_tA4E70A5EABABBB95B11A1B2B40F0335B5AA6ED16>(__this);
	RadixSortBatchPrefixSumJob_1_Execute_m71DF9A259A4A7F5463EB48D94570811F2FC1D649(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81831
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR int32_t RadixSortBatchPrefixSumJob_1_AtomicIncrement_m8EC5C7D3F99DC23EACE0C397BDF89AF029A717B0_fshared (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C ___0_counter, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_0 = ___0_counter;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafePtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD2D9DC546B80A05000B107C8E09FAA4BED3B2144_inline(L_0, NULL);
		int32_t* L_2;
		L_2 = UnsafeUtility_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mF01FDF0EACCFED286E93933B693A2BE11A6A8946_inline(L_1, NULL);
		int32_t L_3;
		L_3 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309(L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 81832
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR int32_t RadixSortBatchPrefixSumJob_1_JobIndexPrefixSum_m3F8F577B4377811997803EDFF4C6D9A87EC74B72_fshared (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_sum, int32_t ___1_i, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		V_0 = 0;
		goto IL_003c;
	}

IL_0004:
	{
		int32_t L_0 = ___1_i;
		int32_t L_1 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_0, ((int32_t)il2cpp_codegen_multiply(L_1, ((int32_t)256)))));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_2 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_3 = V_1;
		int32_t L_4 = ___0_sum;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_2)->___m_Buffer, L_3, (L_4));
		int32_t L_5 = ___0_sum;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_6 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		int32_t L_7 = V_1;
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_6)->___m_Buffer, L_7);
		___0_sum = ((int32_t)il2cpp_codegen_add(L_5, L_8));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_9 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		int32_t L_10 = V_1;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_9)->___m_Buffer, L_10, (0));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_003c:
	{
		int32_t L_12 = V_0;
		int32_t L_13 = __this->___jobsCount;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0004;
		}
	}
	{
		int32_t L_14 = ___0_sum;
		return L_14;
	}
}
// Method Definition Index: 81833
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25_fshared (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = ((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)16)));
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)16)));
		V_1 = 0;
		V_2 = L_1;
		goto IL_001b;
	}

IL_000e:
	{
		int32_t L_2 = V_1;
		int32_t L_3 = V_2;
		int32_t L_4;
		L_4 = ((  int32_t (*) (RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* IL2CPP_PARAMETER_RESTRICT, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(__this, L_2, L_3, NULL);
		V_1 = L_4;
		int32_t L_5 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_001b:
	{
		int32_t L_6 = V_2;
		int32_t L_7 = V_0;
		if ((((int32_t)L_6) < ((int32_t)L_7)))
		{
			goto IL_000e;
		}
	}
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_8 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_9 = ___0_index;
		int32_t L_10 = V_1;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_8)->___m_Buffer, L_9, (L_10));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_11 = __this->___counter;
		int32_t L_12;
		L_12 = ((  int32_t (*) (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(L_11, NULL);
		if ((!(((uint32_t)L_12) == ((uint32_t)((int32_t)16)))))
		{
			goto IL_00f5;
		}
	}
	{
		V_3 = 0;
		int32_t L_13 = __this->___radix;
		int32_t L_14 = __this->___signBitRadixIndex;
		if ((((int32_t)L_13) == ((int32_t)L_14)))
		{
			goto IL_0083;
		}
	}
	{
		V_4 = 0;
		goto IL_007b;
	}

IL_0053:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_15 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_16 = V_4;
		int32_t L_17;
		L_17 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_15)->___m_Buffer, L_16);
		V_5 = L_17;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_18 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_19 = V_4;
		int32_t L_20 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_18)->___m_Buffer, L_19, (L_20));
		int32_t L_21 = V_3;
		int32_t L_22 = V_5;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, L_22));
		int32_t L_23 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007b:
	{
		int32_t L_24 = V_4;
		if ((((int32_t)L_24) < ((int32_t)((int32_t)16))))
		{
			goto IL_0053;
		}
	}
	{
		goto IL_00e8;
	}

IL_0083:
	{
		V_6 = 8;
		goto IL_00b0;
	}

IL_0088:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_25 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_26 = V_6;
		int32_t L_27;
		L_27 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_25)->___m_Buffer, L_26);
		V_7 = L_27;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_28 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_29 = V_6;
		int32_t L_30 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_28)->___m_Buffer, L_29, (L_30));
		int32_t L_31 = V_3;
		int32_t L_32 = V_7;
		V_3 = ((int32_t)il2cpp_codegen_add(L_31, L_32));
		int32_t L_33 = V_6;
		V_6 = ((int32_t)il2cpp_codegen_add(L_33, 1));
	}

IL_00b0:
	{
		int32_t L_34 = V_6;
		if ((((int32_t)L_34) < ((int32_t)((int32_t)16))))
		{
			goto IL_0088;
		}
	}
	{
		V_8 = 0;
		goto IL_00e3;
	}

IL_00bb:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_35 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_36 = V_8;
		int32_t L_37;
		L_37 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_35)->___m_Buffer, L_36);
		V_9 = L_37;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_38 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indicesSum);
		int32_t L_39 = V_8;
		int32_t L_40 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_38)->___m_Buffer, L_39, (L_40));
		int32_t L_41 = V_3;
		int32_t L_42 = V_9;
		V_3 = ((int32_t)il2cpp_codegen_add(L_41, L_42));
		int32_t L_43 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_43, 1));
	}

IL_00e3:
	{
		int32_t L_44 = V_8;
		if ((((int32_t)L_44) < ((int32_t)8)))
		{
			goto IL_00bb;
		}
	}

IL_00e8:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_45 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___counter);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_45)->___m_Buffer, 0, (0));
	}

IL_00f5:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBatchPrefixSumJob_1_t38091553B87D103286CED2992CA2392E2C1DF80C>(__this);
	RadixSortBatchPrefixSumJob_1_Execute_m6BB597EA07C1D4D81CE758241465B89316327E25(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81830
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_mE69747B2B60DA38802FCF96889C1CD7DDC1E3726 (RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* V_6 = NULL;
	int32_t V_7 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_8;
	memset((&V_8), 0, sizeof(V_8));
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_4 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		int32_t L_5;
		L_5 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_4)->___m_Length);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_0088;
		}
	}
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_9 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06F913AC64211C19A5F35EB50F3F45685095D3D1(L_9, 4, NULL);
		V_3 = L_10;
		int32_t L_11 = V_0;
		V_4 = L_11;
		goto IL_0082;
	}

IL_0044:
	{
		int32_t L_12 = V_4;
		int32_t L_13;
		L_13 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_12);
		int32_t L_14 = __this->___radix;
		int32_t L_15;
		L_15 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_13, L_14, NULL);
		V_5 = L_15;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_16 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_16;
		int32_t L_17 = V_2;
		int32_t L_18 = V_5;
		V_7 = ((int32_t)il2cpp_codegen_add(L_17, L_18));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = V_6;
		int32_t L_20 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_21 = V_6;
		int32_t L_22 = V_7;
		int32_t L_23;
		L_23 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_21)->___m_Buffer, L_22);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_19)->___m_Buffer, L_20, (((int32_t)il2cpp_codegen_add(L_23, 1))));
		int32_t L_24 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_0082:
	{
		int32_t L_25 = V_4;
		int32_t L_26 = V_1;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0044;
		}
	}
	{
		return;
	}

IL_0088:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_27 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_28;
		L_28 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mF718C58AF6A48CF95C20FFFAAD3B3870884C4619(L_27, 8, NULL);
		V_8 = L_28;
		int32_t L_29 = V_0;
		V_9 = L_29;
		goto IL_00d9;
	}

IL_009b:
	{
		int32_t L_30 = V_9;
		uint64_t L_31;
		L_31 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_8))->___m_Buffer, L_30);
		int32_t L_32 = __this->___radix;
		int32_t L_33;
		L_33 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_31, L_32, NULL);
		V_10 = L_33;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_34 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_34;
		int32_t L_35 = V_2;
		int32_t L_36 = V_10;
		V_7 = ((int32_t)il2cpp_codegen_add(L_35, L_36));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_37 = V_6;
		int32_t L_38 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_39 = V_6;
		int32_t L_40 = V_7;
		int32_t L_41;
		L_41 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_39)->___m_Buffer, L_40);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_37)->___m_Buffer, L_38, (((int32_t)il2cpp_codegen_add(L_41, 1))));
		int32_t L_42 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_42, 1));
	}

IL_00d9:
	{
		int32_t L_43 = V_9;
		int32_t L_44 = V_1;
		if ((((int32_t)L_43) < ((int32_t)L_44)))
		{
			goto IL_009b;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketCountJob_1_Execute_mE69747B2B60DA38802FCF96889C1CD7DDC1E3726_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketCountJob_1_tC9AD33E5E839CE12B0A1C15F622220EEC637D787>(__this);
	RadixSortBucketCountJob_1_Execute_mE69747B2B60DA38802FCF96889C1CD7DDC1E3726(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81830
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_m9860F3A459E28F8FF1880B9974294C3E35614701 (RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* V_6 = NULL;
	int32_t V_7 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_8;
	memset((&V_8), 0, sizeof(V_8));
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_4 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		int32_t L_5;
		L_5 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_4)->___m_Length);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_0088;
		}
	}
	{
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_9 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6AA2337D311BABD06E7416B028FD039D11211F9A(L_9, 4, NULL);
		V_3 = L_10;
		int32_t L_11 = V_0;
		V_4 = L_11;
		goto IL_0082;
	}

IL_0044:
	{
		int32_t L_12 = V_4;
		int32_t L_13;
		L_13 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_12);
		int32_t L_14 = __this->___radix;
		int32_t L_15;
		L_15 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_13, L_14, NULL);
		V_5 = L_15;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_16 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_16;
		int32_t L_17 = V_2;
		int32_t L_18 = V_5;
		V_7 = ((int32_t)il2cpp_codegen_add(L_17, L_18));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = V_6;
		int32_t L_20 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_21 = V_6;
		int32_t L_22 = V_7;
		int32_t L_23;
		L_23 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_21)->___m_Buffer, L_22);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_19)->___m_Buffer, L_20, (((int32_t)il2cpp_codegen_add(L_23, 1))));
		int32_t L_24 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_0082:
	{
		int32_t L_25 = V_4;
		int32_t L_26 = V_1;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0044;
		}
	}
	{
		return;
	}

IL_0088:
	{
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_27 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_28;
		L_28 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m3DFE0C9BE1F74820586102B27F73A072206D136C(L_27, 8, NULL);
		V_8 = L_28;
		int32_t L_29 = V_0;
		V_9 = L_29;
		goto IL_00d9;
	}

IL_009b:
	{
		int32_t L_30 = V_9;
		uint64_t L_31;
		L_31 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_8))->___m_Buffer, L_30);
		int32_t L_32 = __this->___radix;
		int32_t L_33;
		L_33 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_31, L_32, NULL);
		V_10 = L_33;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_34 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_34;
		int32_t L_35 = V_2;
		int32_t L_36 = V_10;
		V_7 = ((int32_t)il2cpp_codegen_add(L_35, L_36));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_37 = V_6;
		int32_t L_38 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_39 = V_6;
		int32_t L_40 = V_7;
		int32_t L_41;
		L_41 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_39)->___m_Buffer, L_40);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_37)->___m_Buffer, L_38, (((int32_t)il2cpp_codegen_add(L_41, 1))));
		int32_t L_42 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_42, 1));
	}

IL_00d9:
	{
		int32_t L_43 = V_9;
		int32_t L_44 = V_1;
		if ((((int32_t)L_43) < ((int32_t)L_44)))
		{
			goto IL_009b;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketCountJob_1_Execute_m9860F3A459E28F8FF1880B9974294C3E35614701_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketCountJob_1_tEAF81C7A5326AA523C221928ACEF94EE5E373D5F>(__this);
	RadixSortBucketCountJob_1_Execute_m9860F3A459E28F8FF1880B9974294C3E35614701(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81830
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328_fshared (RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* V_6 = NULL;
	int32_t V_7 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_8;
	memset((&V_8), 0, sizeof(V_8));
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_4 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		int32_t L_5;
		L_5 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(L_4, NULL);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_0088;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_9 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = ((  NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(L_9, 4, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_3 = L_10;
		int32_t L_11 = V_0;
		V_4 = L_11;
		goto IL_0082;
	}

IL_0044:
	{
		int32_t L_12 = V_4;
		int32_t L_13;
		L_13 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_12);
		int32_t L_14 = __this->___radix;
		int32_t L_15;
		L_15 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_13, L_14, NULL);
		V_5 = L_15;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_16 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_16;
		int32_t L_17 = V_2;
		int32_t L_18 = V_5;
		V_7 = ((int32_t)il2cpp_codegen_add(L_17, L_18));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = V_6;
		int32_t L_20 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_21 = V_6;
		int32_t L_22 = V_7;
		int32_t L_23;
		L_23 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_21)->___m_Buffer, L_22);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_19)->___m_Buffer, L_20, (((int32_t)il2cpp_codegen_add(L_23, 1))));
		int32_t L_24 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_0082:
	{
		int32_t L_25 = V_4;
		int32_t L_26 = V_1;
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0044;
		}
	}
	{
		return;
	}

IL_0088:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_27 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_28;
		L_28 = ((  NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_27, 8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		V_8 = L_28;
		int32_t L_29 = V_0;
		V_9 = L_29;
		goto IL_00d9;
	}

IL_009b:
	{
		int32_t L_30 = V_9;
		uint64_t L_31;
		L_31 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_8))->___m_Buffer, L_30);
		int32_t L_32 = __this->___radix;
		int32_t L_33;
		L_33 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_31, L_32, NULL);
		V_10 = L_33;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_34 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___buckets);
		V_6 = L_34;
		int32_t L_35 = V_2;
		int32_t L_36 = V_10;
		V_7 = ((int32_t)il2cpp_codegen_add(L_35, L_36));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_37 = V_6;
		int32_t L_38 = V_7;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_39 = V_6;
		int32_t L_40 = V_7;
		int32_t L_41;
		L_41 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_39)->___m_Buffer, L_40);
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_37)->___m_Buffer, L_38, (((int32_t)il2cpp_codegen_add(L_41, 1))));
		int32_t L_42 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_42, 1));
	}

IL_00d9:
	{
		int32_t L_43 = V_9;
		int32_t L_44 = V_1;
		if ((((int32_t)L_43) < ((int32_t)L_44)))
		{
			goto IL_009b;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketCountJob_1_t8CE90196DB677E4A0C7AC9264121BF2D87493A93>(__this);
	RadixSortBucketCountJob_1_Execute_m62F3E9EF52E5494D26B073D448AEB45984989328(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81835
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m824CF9A6053A2A13ACEB6D4E533B964B9D04DB1A (RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_11;
	memset((&V_11), 0, sizeof(V_11));
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_12;
	memset((&V_12), 0, sizeof(V_12));
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_4 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		int32_t L_5;
		L_5 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_4)->___m_Length);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_00a8;
		}
	}
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_9 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06F913AC64211C19A5F35EB50F3F45685095D3D1(L_9, 4, NULL);
		V_3 = L_10;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_11 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___arraySorted);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_12;
		L_12 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m06F913AC64211C19A5F35EB50F3F45685095D3D1(L_11, 4, NULL);
		V_4 = L_12;
		int32_t L_13 = V_0;
		V_5 = L_13;
		goto IL_00a2;
	}

IL_0052:
	{
		int32_t L_14 = V_5;
		int32_t L_15;
		L_15 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_14);
		V_6 = L_15;
		int32_t L_16 = V_6;
		int32_t L_17 = __this->___radix;
		int32_t L_18;
		L_18 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_16, L_17, NULL);
		V_7 = L_18;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_20 = V_2;
		int32_t L_21 = V_7;
		V_9 = ((int32_t)il2cpp_codegen_add(L_20, L_21));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_22 = L_19;
		int32_t L_23 = V_9;
		int32_t L_24;
		L_24 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_22)->___m_Buffer, L_23);
		V_10 = L_24;
		int32_t L_25 = V_9;
		int32_t L_26 = V_10;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_22)->___m_Buffer, L_25, (((int32_t)il2cpp_codegen_add(L_26, 1))));
		int32_t L_27 = V_10;
		V_8 = L_27;
		int32_t L_28 = V_8;
		int32_t L_29 = V_6;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, ((&V_4))->___m_Buffer, L_28, (L_29));
		int32_t L_30 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00a2:
	{
		int32_t L_31 = V_5;
		int32_t L_32 = V_1;
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_0052;
		}
	}
	{
		return;
	}

IL_00a8:
	{
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_33 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_34;
		L_34 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mF718C58AF6A48CF95C20FFFAAD3B3870884C4619(L_33, 8, NULL);
		V_11 = L_34;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_35 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___arraySorted);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_36;
		L_36 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mF718C58AF6A48CF95C20FFFAAD3B3870884C4619(L_35, 8, NULL);
		V_12 = L_36;
		int32_t L_37 = V_0;
		V_13 = L_37;
		goto IL_0119;
	}

IL_00c9:
	{
		int32_t L_38 = V_13;
		uint64_t L_39;
		L_39 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_11))->___m_Buffer, L_38);
		V_14 = L_39;
		uint64_t L_40 = V_14;
		int32_t L_41 = __this->___radix;
		int32_t L_42;
		L_42 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_40, L_41, NULL);
		V_15 = L_42;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_43 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_44 = V_2;
		int32_t L_45 = V_15;
		V_10 = ((int32_t)il2cpp_codegen_add(L_44, L_45));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_46 = L_43;
		int32_t L_47 = V_10;
		int32_t L_48;
		L_48 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_46)->___m_Buffer, L_47);
		V_9 = L_48;
		int32_t L_49 = V_10;
		int32_t L_50 = V_9;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_46)->___m_Buffer, L_49, (((int32_t)il2cpp_codegen_add(L_50, 1))));
		int32_t L_51 = V_9;
		V_16 = L_51;
		int32_t L_52 = V_16;
		uint64_t L_53 = V_14;
		IL2CPP_NATIVEARRAY_SET_ITEM(uint64_t, ((&V_12))->___m_Buffer, L_52, (L_53));
		int32_t L_54 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_54, 1));
	}

IL_0119:
	{
		int32_t L_55 = V_13;
		int32_t L_56 = V_1;
		if ((((int32_t)L_55) < ((int32_t)L_56)))
		{
			goto IL_00c9;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketSortJob_1_Execute_m824CF9A6053A2A13ACEB6D4E533B964B9D04DB1A_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketSortJob_1_t4FAA58B1A9BB055721412769BB8AA45AF098845B>(__this);
	RadixSortBucketSortJob_1_Execute_m824CF9A6053A2A13ACEB6D4E533B964B9D04DB1A(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81835
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_m3A6F0C47238FA5FD88CF5EA0E24E26202F539F73 (RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_11;
	memset((&V_11), 0, sizeof(V_11));
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_12;
	memset((&V_12), 0, sizeof(V_12));
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_4 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		int32_t L_5;
		L_5 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_4)->___m_Length);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_00a8;
		}
	}
	{
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_9 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6AA2337D311BABD06E7416B028FD039D11211F9A(L_9, 4, NULL);
		V_3 = L_10;
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_11 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___arraySorted);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_12;
		L_12 = NativeArray_1_Reinterpret_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6AA2337D311BABD06E7416B028FD039D11211F9A(L_11, 4, NULL);
		V_4 = L_12;
		int32_t L_13 = V_0;
		V_5 = L_13;
		goto IL_00a2;
	}

IL_0052:
	{
		int32_t L_14 = V_5;
		int32_t L_15;
		L_15 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_14);
		V_6 = L_15;
		int32_t L_16 = V_6;
		int32_t L_17 = __this->___radix;
		int32_t L_18;
		L_18 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_16, L_17, NULL);
		V_7 = L_18;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_20 = V_2;
		int32_t L_21 = V_7;
		V_9 = ((int32_t)il2cpp_codegen_add(L_20, L_21));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_22 = L_19;
		int32_t L_23 = V_9;
		int32_t L_24;
		L_24 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_22)->___m_Buffer, L_23);
		V_10 = L_24;
		int32_t L_25 = V_9;
		int32_t L_26 = V_10;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_22)->___m_Buffer, L_25, (((int32_t)il2cpp_codegen_add(L_26, 1))));
		int32_t L_27 = V_10;
		V_8 = L_27;
		int32_t L_28 = V_8;
		int32_t L_29 = V_6;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, ((&V_4))->___m_Buffer, L_28, (L_29));
		int32_t L_30 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00a2:
	{
		int32_t L_31 = V_5;
		int32_t L_32 = V_1;
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_0052;
		}
	}
	{
		return;
	}

IL_00a8:
	{
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_33 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_34;
		L_34 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m3DFE0C9BE1F74820586102B27F73A072206D136C(L_33, 8, NULL);
		V_11 = L_34;
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B* L_35 = (NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B*)(&__this->___arraySorted);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_36;
		L_36 = NativeArray_1_Reinterpret_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m3DFE0C9BE1F74820586102B27F73A072206D136C(L_35, 8, NULL);
		V_12 = L_36;
		int32_t L_37 = V_0;
		V_13 = L_37;
		goto IL_0119;
	}

IL_00c9:
	{
		int32_t L_38 = V_13;
		uint64_t L_39;
		L_39 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_11))->___m_Buffer, L_38);
		V_14 = L_39;
		uint64_t L_40 = V_14;
		int32_t L_41 = __this->___radix;
		int32_t L_42;
		L_42 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_40, L_41, NULL);
		V_15 = L_42;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_43 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_44 = V_2;
		int32_t L_45 = V_15;
		V_10 = ((int32_t)il2cpp_codegen_add(L_44, L_45));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_46 = L_43;
		int32_t L_47 = V_10;
		int32_t L_48;
		L_48 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_46)->___m_Buffer, L_47);
		V_9 = L_48;
		int32_t L_49 = V_10;
		int32_t L_50 = V_9;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_46)->___m_Buffer, L_49, (((int32_t)il2cpp_codegen_add(L_50, 1))));
		int32_t L_51 = V_9;
		V_16 = L_51;
		int32_t L_52 = V_16;
		uint64_t L_53 = V_14;
		IL2CPP_NATIVEARRAY_SET_ITEM(uint64_t, ((&V_12))->___m_Buffer, L_52, (L_53));
		int32_t L_54 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_54, 1));
	}

IL_0119:
	{
		int32_t L_55 = V_13;
		int32_t L_56 = V_1;
		if ((((int32_t)L_55) < ((int32_t)L_56)))
		{
			goto IL_00c9;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketSortJob_1_Execute_m3A6F0C47238FA5FD88CF5EA0E24E26202F539F73_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketSortJob_1_t68C34425FDC909DF8A4C73E7BD80203D7EE84DA9>(__this);
	RadixSortBucketSortJob_1_Execute_m3A6F0C47238FA5FD88CF5EA0E24E26202F539F73(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 81835
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7_fshared (RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_3;
	memset((&V_3), 0, sizeof(V_3));
	NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_11;
	memset((&V_11), 0, sizeof(V_11));
	NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B V_12;
	memset((&V_12), 0, sizeof(V_12));
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->___batchSize;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
		int32_t L_2 = V_0;
		int32_t L_3 = __this->___batchSize;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_4 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		int32_t L_5;
		L_5 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(L_4, NULL);
		int32_t L_6;
		L_6 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(((int32_t)il2cpp_codegen_add(L_2, L_3)), L_5, NULL);
		V_1 = L_6;
		int32_t L_7 = ___0_index;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)256)));
		int32_t L_8 = __this->___valueType;
		if (L_8)
		{
			goto IL_00a8;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_9 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_10;
		L_10 = ((  NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(L_9, 4, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_3 = L_10;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_11 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___arraySorted);
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C L_12;
		L_12 = ((  NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1)))(L_11, 4, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_4 = L_12;
		int32_t L_13 = V_0;
		V_5 = L_13;
		goto IL_00a2;
	}

IL_0052:
	{
		int32_t L_14 = V_5;
		int32_t L_15;
		L_15 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, ((&V_3))->___m_Buffer, L_14);
		V_6 = L_15;
		int32_t L_16 = V_6;
		int32_t L_17 = __this->___radix;
		int32_t L_18;
		L_18 = ParallelSortExtensions_GetBucketIndex_m59A772ACE45802E9CB4E3F3779CE15335FDF1725(L_16, L_17, NULL);
		V_7 = L_18;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_19 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_20 = V_2;
		int32_t L_21 = V_7;
		V_9 = ((int32_t)il2cpp_codegen_add(L_20, L_21));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_22 = L_19;
		int32_t L_23 = V_9;
		int32_t L_24;
		L_24 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_22)->___m_Buffer, L_23);
		V_10 = L_24;
		int32_t L_25 = V_9;
		int32_t L_26 = V_10;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_22)->___m_Buffer, L_25, (((int32_t)il2cpp_codegen_add(L_26, 1))));
		int32_t L_27 = V_10;
		V_8 = L_27;
		int32_t L_28 = V_8;
		int32_t L_29 = V_6;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, ((&V_4))->___m_Buffer, L_28, (L_29));
		int32_t L_30 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00a2:
	{
		int32_t L_31 = V_5;
		int32_t L_32 = V_1;
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_0052;
		}
	}
	{
		return;
	}

IL_00a8:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_33 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___array);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_34;
		L_34 = ((  NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_33, 8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		V_11 = L_34;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_35 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___arraySorted);
		NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B L_36;
		L_36 = ((  NativeArray_1_t07975297AD7F7512193094A7C0703BA872EF7A7B (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2)))(L_35, 8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		V_12 = L_36;
		int32_t L_37 = V_0;
		V_13 = L_37;
		goto IL_0119;
	}

IL_00c9:
	{
		int32_t L_38 = V_13;
		uint64_t L_39;
		L_39 = IL2CPP_NATIVEARRAY_GET_ITEM(uint64_t, ((&V_11))->___m_Buffer, L_38);
		V_14 = L_39;
		uint64_t L_40 = V_14;
		int32_t L_41 = __this->___radix;
		int32_t L_42;
		L_42 = ParallelSortExtensions_GetBucketIndex_mE4EAA948DCD4F163066FAA8A5B2B1D0F09775E01(L_40, L_41, NULL);
		V_15 = L_42;
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_43 = (NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C*)(&__this->___indices);
		int32_t L_44 = V_2;
		int32_t L_45 = V_15;
		V_10 = ((int32_t)il2cpp_codegen_add(L_44, L_45));
		NativeArray_1_tA833EB7E3E1C9AF82C37976AD964B8D4BAC38B2C* L_46 = L_43;
		int32_t L_47 = V_10;
		int32_t L_48;
		L_48 = IL2CPP_NATIVEARRAY_GET_ITEM(int32_t, (L_46)->___m_Buffer, L_47);
		V_9 = L_48;
		int32_t L_49 = V_10;
		int32_t L_50 = V_9;
		IL2CPP_NATIVEARRAY_SET_ITEM(int32_t, (L_46)->___m_Buffer, L_49, (((int32_t)il2cpp_codegen_add(L_50, 1))));
		int32_t L_51 = V_9;
		V_16 = L_51;
		int32_t L_52 = V_16;
		uint64_t L_53 = V_14;
		IL2CPP_NATIVEARRAY_SET_ITEM(uint64_t, ((&V_12))->___m_Buffer, L_52, (L_53));
		int32_t L_54 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_54, 1));
	}

IL_0119:
	{
		int32_t L_55 = V_13;
		int32_t L_56 = V_1;
		if ((((int32_t)L_55) < ((int32_t)L_56)))
		{
			goto IL_00c9;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C  void RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7_AdjustorThunk (RuntimeObject* IL2CPP_PARAMETER_RESTRICT __this, int32_t ___0_index, const RuntimeMethod* method)
{
	RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<RadixSortBucketSortJob_1_tBA53182D91917571DC0AE06FF99EF355D4E2DB5D>(__this);
	RadixSortBucketSortJob_1_Execute_mC7C51B2BB781FF47D3F2366C88535DA736ADD5D7(_thisAdjusted, ___0_index, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 85633
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RamerDouglasPeucker_1__ctor_m87CE64BB38BE9EC9A3E450CC4AFFB47E8EC21485_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, Il2CppFullySharedGenericAny ___0_points, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)) ? ___0_points : &___0_points), SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		return;
	}
}
// Method Definition Index: 85634
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RamerDouglasPeucker_1_Reduce_mC4C5A15B24E0C58BAD430CCD23C49B1DBF25C9D2_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* ___0_results, float ___1_epsilon, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)));
	void* L_29 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)));
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* L_0 = ___0_results;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral9AB16B3999460DDC981865934D979087351A14F2)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		float L_2 = ___1_epsilon;
		float L_3;
		L_3 = math_max_mC2D5D2F0EB91D3A908AE964BE8BF5EA443C3BF64_inline((1.40129846E-45f), L_2, NULL);
		il2cpp_codegen_write_field_data<float, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_3);
		Il2CppConstrainedCallData L_5;
		Il2CppMethodPointer L_6 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4), (void*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))), &L_5, L_4);
		typedef int32_t ( *func_L_7)(void*,const RuntimeMethod*);
		int32_t L_8 = ((func_L_7)L_6)(L_5.thisPtr,L_5.method);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5), L_8);
		int32_t L_9 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_10 = (BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)SZArrayNew(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var, (uint32_t)L_9);
		il2cpp_codegen_write_field_data<BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6), L_10);
		V_0 = 0;
		goto IL_0056;
	}

IL_004b:
	{
		int32_t L_11 = V_0;
		((  void (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7));
		int32_t L_12 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_0056:
	{
		int32_t L_13 = V_0;
		int32_t L_14 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		if ((((int32_t)L_13) < ((int32_t)L_14)))
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_15 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_16;
		memset((&L_16), 0, sizeof(L_16));
		Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D((&L_16), 0, L_15, NULL);
		((  void (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, L_16, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* L_17 = ___0_results;
		NullCheck(L_17);
		List_1_Clear_m6C8D51A9406D6ED9B43B6F126A83EF286FB5DFB3_inline(L_17, NULL);
		List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* L_18 = ___0_results;
		NullCheck(L_18);
		int32_t L_19;
		L_19 = List_1_get_Capacity_m7237746FBC070DD77B7BBE2013FB35CA4F7182E9(L_18, NULL);
		int32_t L_20 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		if ((((int32_t)L_19) >= ((int32_t)L_20)))
		{
			goto IL_0091;
		}
	}
	{
		List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* L_21 = ___0_results;
		int32_t L_22 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		NullCheck(L_21);
		List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9(L_21, L_22, List_1_set_Capacity_mF9D4C2FC4283D46C7FF1285A449409DBB5B41FA9_RuntimeMethod_var);
	}

IL_0091:
	{
		V_1 = 0;
		goto IL_00bb;
	}

IL_0095:
	{
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_23 = *(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		int32_t L_24 = V_1;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		uint8_t L_26 = (uint8_t)(L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		if (!L_26)
		{
			goto IL_00b7;
		}
	}
	{
		List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* L_27 = ___0_results;
		int32_t L_28 = V_1;
		Il2CppConstrainedCallData L_30;
		Il2CppMethodPointer L_31 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), (void*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))), &L_30, L_29);
		typedef float3_t7600B73F092B37F484B12910A5269F30C778D31E ( *func_L_32)(void*,int32_t,const RuntimeMethod*);
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_33 = ((func_L_32)L_31)(L_30.thisPtr, L_28,L_30.method);
		NullCheck(L_27);
		List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_inline(L_27, L_33, List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_RuntimeMethod_var);
	}

IL_00b7:
	{
		int32_t L_34 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00bb:
	{
		int32_t L_35 = V_1;
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_36 = *(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		NullCheck(L_36);
		int32_t L_37 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_36)->max_length),NULL));
		if ((((int32_t)L_35) < ((int32_t)L_37)))
		{
			goto IL_0095;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 85635
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RamerDouglasPeucker_1_Keep_m66F4A5F999BDDACAD03C4FB6428C67885A9C0AF6_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_0 = *(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		int32_t L_1 = ___0_index;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(L_1), (bool)1);
		return;
	}
}
// Method Definition Index: 85636
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RamerDouglasPeucker_1_Discard_mC1AA637C8C0FB3ACF3928F6449233C06CC7C1168_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 ___0_range, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_1 = ___0_range;
		int32_t L_2 = L_1.___Count;
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5), ((int32_t)il2cpp_codegen_subtract(L_0, L_2)));
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_3 = ___0_range;
		int32_t L_4 = L_3.___Start;
		V_0 = L_4;
		goto IL_0029;
	}

IL_001c:
	{
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_5 = *(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		int32_t L_6 = V_0;
		NullCheck(L_5);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(L_6), (bool)0);
		int32_t L_7 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, 1));
	}

IL_0029:
	{
		int32_t L_8 = V_0;
		int32_t L_9;
		L_9 = ((  int32_t (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))((&___0_range), NULL);
		if ((((int32_t)L_8) <= ((int32_t)L_9)))
		{
			goto IL_001c;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 85637
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RamerDouglasPeucker_1_Reduce_m40AF7CED644E15AACC5038BE3AF5516FCF0D0F52_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 ___0_range, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_0 = ___0_range;
		int32_t L_1 = L_0.___Count;
		if ((((int32_t)L_1) >= ((int32_t)3)))
		{
			goto IL_000a;
		}
	}
	{
		return;
	}

IL_000a:
	{
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_2 = ___0_range;
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_3;
		L_3 = ((  ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		V_0 = L_3;
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_4 = V_0;
		float L_5 = L_4.___Item2;
		float L_6 = *(float*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		if ((!(((float)L_5) < ((float)L_6))))
		{
			goto IL_003c;
		}
	}
	{
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_7 = ___0_range;
		int32_t L_8 = L_7.___Start;
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_9 = ___0_range;
		int32_t L_10 = L_9.___Count;
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_11;
		memset((&L_11), 0, sizeof(L_11));
		Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D((&L_11), ((int32_t)il2cpp_codegen_add(L_8, 1)), ((int32_t)il2cpp_codegen_subtract(L_10, 2)), NULL);
		((  void (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)))(__this, L_11, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		return;
	}

IL_003c:
	{
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_12 = ___0_range;
		int32_t L_13 = L_12.___Start;
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_14 = V_0;
		int32_t L_15 = L_14.___Item1;
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_16 = ___0_range;
		int32_t L_17 = L_16.___Start;
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_18;
		memset((&L_18), 0, sizeof(L_18));
		Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D((&L_18), L_13, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_15, L_17)), 1)), NULL);
		((  void (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, L_18, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_19 = V_0;
		int32_t L_20 = L_19.___Item1;
		int32_t L_21;
		L_21 = ((  int32_t (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))((&___0_range), NULL);
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_22 = V_0;
		int32_t L_23 = L_22.___Item1;
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_24;
		memset((&L_24), 0, sizeof(L_24));
		Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D((&L_24), L_20, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_subtract(L_21, L_23)), 1)), NULL);
		((  void (*) (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5*, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, L_24, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9));
		return;
	}
}
// Method Definition Index: 85638
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 RamerDouglasPeucker_1_FindFarthest_m2E285750FEE2F727F56DC090164CBB9B881B8C80_fshared (RamerDouglasPeucker_1_tAFD36BF5844DB259EA5923FE26135F32EB9D3CD5* __this, Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 ___0_range, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0));
	void* L_3 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)));
	void* L_10 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)));
	void* L_19 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)));
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
	const Il2CppFullySharedGenericAny L_17 = L_15;
	//<source_info:<no-source>:1>
	float V_0 = 0.0f;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	float V_3 = 0.0f;
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
	memset(V_4, 0, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
	Il2CppFullySharedGenericAny* G_B3_0 = NULL;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E G_B3_1;
	memset((&G_B3_1), 0, sizeof(G_B3_1));
	float3_t7600B73F092B37F484B12910A5269F30C778D31E G_B3_2;
	memset((&G_B3_2), 0, sizeof(G_B3_2));
	Il2CppFullySharedGenericAny* G_B2_0 = NULL;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E G_B2_1;
	memset((&G_B2_1), 0, sizeof(G_B2_1));
	float3_t7600B73F092B37F484B12910A5269F30C778D31E G_B2_2;
	memset((&G_B2_2), 0, sizeof(G_B2_2));
	{
		V_0 = (0.0f);
		V_1 = (-1);
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_0 = ___0_range;
		int32_t L_1 = L_0.___Start;
		V_2 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		goto IL_0080;
	}

IL_0013:
	{
		int32_t L_2 = V_2;
		Il2CppConstrainedCallData L_4;
		Il2CppMethodPointer L_5 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), (void*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))), &L_4, L_3);
		typedef float3_t7600B73F092B37F484B12910A5269F30C778D31E ( *func_L_6)(void*,int32_t,const RuntimeMethod*);
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_7 = ((func_L_6)L_5)(L_4.thisPtr, L_2,L_4.method);
		Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7 L_8 = ___0_range;
		int32_t L_9 = L_8.___Start;
		Il2CppConstrainedCallData L_11;
		Il2CppMethodPointer L_12 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), (void*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))), &L_11, L_10);
		typedef float3_t7600B73F092B37F484B12910A5269F30C778D31E ( *func_L_13)(void*,int32_t,const RuntimeMethod*);
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_14 = ((func_L_13)L_12)(L_11.thisPtr, L_9,L_11.method);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		il2cpp_codegen_memcpy(L_15, V_4, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		bool L_16 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), L_15);
		if (L_16)
		{
			G_B3_0 = ((Il2CppFullySharedGenericAny*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))));
			G_B3_1 = L_14;
			G_B3_2 = L_7;
			goto IL_005c;
		}
		G_B2_0 = ((Il2CppFullySharedGenericAny*)(((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2)))));
		G_B2_1 = L_14;
		G_B2_2 = L_7;
	}
	{
		il2cpp_codegen_memcpy(L_17, G_B2_0, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		il2cpp_codegen_memcpy(V_4, L_17, SizeOf_T_tB08CEFB996569A0060422E91DCB1CE1D07CF6564);
		G_B3_0 = ((Il2CppFullySharedGenericAny*)(Il2CppFullySharedGenericAny*)V_4);
		G_B3_1 = G_B2_1;
		G_B3_2 = G_B2_2;
	}

IL_005c:
	{
		int32_t L_18;
		L_18 = ((  int32_t (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))((&___0_range), NULL);
		Il2CppConstrainedCallData L_20;
		Il2CppMethodPointer L_21 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), (void*)G_B3_0, &L_20, L_19);
		typedef float3_t7600B73F092B37F484B12910A5269F30C778D31E ( *func_L_22)(void*,int32_t,const RuntimeMethod*);
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_23 = ((func_L_22)L_21)(L_20.thisPtr, L_18,L_20.method);
		float L_24;
		L_24 = SplineMath_DistancePointLine_m11F12FCA6C85B91C0C59F671E09DEAC31F7FFA4F(G_B3_2, G_B3_1, L_23, NULL);
		V_3 = L_24;
		float L_25 = V_3;
		float L_26 = V_0;
		if ((!(((float)L_25) > ((float)L_26))))
		{
			goto IL_007c;
		}
	}
	{
		float L_27 = V_3;
		V_0 = L_27;
		int32_t L_28 = V_2;
		V_1 = L_28;
	}

IL_007c:
	{
		int32_t L_29 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0080:
	{
		int32_t L_30 = V_2;
		int32_t L_31;
		L_31 = ((  int32_t (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))((&___0_range), NULL);
		if ((((int32_t)L_30) < ((int32_t)L_31)))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_32 = V_1;
		float L_33 = V_0;
		ValueTuple_2_t2ADD54A4634C073CBAB66A75153EA556FF32FB69 L_34;
		memset((&L_34), 0, sizeof(L_34));
		ValueTuple_2__ctor_m8AD4450A363A5626EE8665BFDFA6B773D05EE581((&L_34), L_32, L_33, NULL);
		return L_34;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 85639
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Range_get_End_mAEE768138A88357ECC6A2B20C32F6DF0E1D8D178_fshared (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___Start;
		int32_t L_1 = __this->___Count;
		return ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_0, L_1)), 1));
	}
}
// Method Definition Index: 85640
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Range__ctor_m92B36FCA750BF22616741935CFD06A8DF8F9E79D_fshared (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, int32_t ___0_start, int32_t ___1_count, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_start;
		__this->___Start = L_0;
		int32_t L_1 = ___1_count;
		__this->___Count = L_1;
		return;
	}
}
// Method Definition Index: 85641
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E_fshared (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC4719FC1E3A10EA1E011F803751AE6CB4774ADA9);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___Start;
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_1);
		int32_t L_3;
		L_3 = ((  int32_t (*) (Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(__this, NULL);
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralC4719FC1E3A10EA1E011F803751AE6CB4774ADA9, L_2, L_5, NULL);
		return L_6;
	}
}
IL2CPP_EXTERN_C  String_t* Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Range_t4F5C1371FE16FFB75A75FD3505EDBC28C326AEB7>(__this);
	String_t* _returnValue;
	_returnValue = Range_ToString_m0281401192EDE017D7E737F097418FFC713CF66E(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30505
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359 RangeEnumerable_GetEnumerator_m4A2522E66C381762D06DB579FDFFFF40FA1D9227_fshared (RangeEnumerable_t6137B8AC2ED5E0CEDFF987BAF29215CE71A88B05* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359 L_0 = __this->___iterator;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5* RangeIterator_get_Current_mB183B47FC92E0410DE12D1D3463D949E2176FD4F_gshared (RangeIterator_t3E60B0712EA543E538163E8DD9B9F6F036DC1DA3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_tE72575361C5FDD549EBB875190FDDFFF508A82FE* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		HashEntry_1_t0CF7FFD9BDEAB90BD66EEB375F4933A8AAFA09A5* L_2;
		L_2 = DynamicArray_1_get_Item_mDDF17FFCC776B434F220412BAEB139F2350600FA(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar* RangeIterator_get_Current_m81077035902D5975CD7A019F89330FF48D85BE30 (RangeIterator_t559C14703A83268020B566598777B0F935714003* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t1F5A6BEDEF657490AB27890A98FB6E43C483A240* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		Il2CppChar* L_2;
		L_2 = DynamicArray_1_get_Item_mDFF72C07A8872B82B343DBC3B7A134FDED83E74B(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* RangeIterator_get_Current_m421E51E9F4DC8E85B838A73AE5520583844880C6 (RangeIterator_t31377641C6AF599E134F1D01E479C81E62433830* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t67013CCCA41647589502C2A4A08FFEB4FF5634D0* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		int32_t* L_2;
		L_2 = DynamicArray_1_get_Item_m5AC8E2913D8C0BE441403585083972B6AD1A49C6(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354* RangeIterator_get_Current_mF5C50FA052318B436C8C6E5F45C63104A9C08DCF (RangeIterator_t89474B790B4B6CCD57E3D6A6A4C10DA21890338D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t1BC59A74EF1C33C3F0F6BD8068BF4B74D4C278AA* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		Name_t9E47EF25D1808C27515EB99D71DB90E187AC1354* L_2;
		L_2 = DynamicArray_1_get_Item_mEF92855A23D9A2995786E5910FD3425F749EB5C0(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68* RangeIterator_get_Current_m769DC73752793B8356C90298675DE963E2A2E473 (RangeIterator_tE742F0E0379E08C8853BFFCDA8503DA7480AB16B* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t9ACEB5B659F92FB87338A066DCCB01705B7B0F4C* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		RendererListLegacyResource_tEF05A444F7845E04F5E6568549AF26D434AD1B68* L_2;
		L_2 = DynamicArray_1_get_Item_m24D831579B1FD904DCCA4EE983EBD0F19E7E96D5(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214* RangeIterator_get_Current_mF4CF6EC452CAE39B16717BD6D1420670E07D4A92 (RangeIterator_t97C3725D846495A296FAE832767B011BD390E9F5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t7529C3B78E9609E7C5355068839333E627A14FF0* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		RendererListResource_tCB75EF1874F8A294101A45F937987CC314B92214* L_2;
		L_2 = DynamicArray_1_get_Item_m67A96A4CCBC69D31ADE62E5D36A9221CC7E4CAEA(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject** RangeIterator_get_Current_m77592FD9A7BA06F1AD745A7F40164A2565D668F8_gshared (RangeIterator_t6EA0AFB0D60C265995C33CF173AE593EEBD60514* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_t2A75BEDB4D41FF2FB6EC822B2CFBD037211F784D* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		Il2CppSharedGenericObject** L_2;
		L_2 = DynamicArray_1_get_Item_mA2D6D01C2851B649C10AAB4D7F0EB01F2E0596EE(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 30508
// Method Definition Index: 30509
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 30506
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RangeIterator__ctor_m6A9D5FD1DDEEF776D5F48CC17225B4631E77B6AE_fshared (RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359* __this, DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0* ___0_setOwner, int32_t ___1_first, int32_t ___2_numItems, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0* L_0 = ___0_setOwner;
		__this->___owner = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___owner), (void*)L_0);
		int32_t L_1 = ___1_first;
		__this->___first = L_1;
		int32_t L_2 = ___1_first;
		__this->___index = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___1_first;
		int32_t L_4 = ___2_numItems;
		__this->___last = ((int32_t)il2cpp_codegen_add(L_3, L_4));
		return;
	}
}
// Method Definition Index: 30507
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* RangeIterator_get_Current_mB6B485B99575365E2D084EA165574C71DC5437CE_fshared (RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0* L_0 = __this->___owner;
		int32_t L_1 = __this->___index;
		NullCheck(L_0);
		Il2CppFullySharedGenericAny* L_2;
		L_2 = ((  Il2CppFullySharedGenericAny* (*) (DynamicArray_1_tFD6392EE4EAA442D167A921C9964FD9C17FDCDE0*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0));
		return L_2;
	}
}
// Method Definition Index: 30508
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RangeIterator_MoveNext_m341BE96F1BF7E86C9469035642434F559A9B95B9_fshared (RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_0, 1));
		int32_t L_1 = __this->___index;
		int32_t L_2 = __this->___last;
		return (bool)((((int32_t)L_1) < ((int32_t)L_2))? 1 : 0);
	}
}
// Method Definition Index: 30509
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RangeIterator_Reset_m2418B0922B55BBE68453F8524F5A1AD48D56B067_fshared (RangeIterator_t9B29290F0B952C8C76DB721EBC8CD1533580E359* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___first;
		__this->___index = ((int32_t)il2cpp_codegen_subtract(L_0, 1));
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 33813
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RasterRenderGraphPass_1_Execute_m8E9AB6EABBDE6B665F7098A271621FA0E4094C9B_gshared (RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5* __this, InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* ___0_renderGraphContext, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(RasterRenderGraphPass_1_t55E8C9F230E8946BF84FE4AC5FD9B4E9C54BE7EE_StaticInit);
	CHECKED_LOCAL(RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(RasterRenderGraphPass_1_t55E8C9F230E8946BF84FE4AC5FD9B4E9C54BE7EE_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		InternalRenderGraphContext_t7197268EBA8C241EB895B070A5E0C71B111D7503* L_0 = ___0_renderGraphContext;
		CHECKED_LOCAL_INIT(RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_StaticInit,(RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		RasterGraphContext_FromInternalContext_m2FE156B0C44906E824BBBE5E69F7CA4EF840BCAE((&((RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___c), L_0, NULL);
		BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887* L_1 = ((BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*)__this)->___renderFunc;
		Il2CppSharedGenericObject* L_2 = ((BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*)__this)->___data;
		RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 L_3 = ((RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___c;
		NullCheck(L_1);
		BaseRenderFunc_2_Invoke_m74AE14F084437149C944CF85887E55871ACC81D8_inline(L_1, L_2, L_3, NULL);
		return;
	}
}
// Method Definition Index: 33814
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RasterRenderGraphPass_1_Release_m4AC4848F4A620A5225DA343C0544D426882F94E1_gshared (RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5* __this, RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* ___0_pool, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* L_0 = ___0_pool;
		NullCheck((BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*)__this);
		BaseRenderGraphPass_2_Release_m71C367F7732998859F6B2A4C2168D31BD2922A77_inline((BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*)__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* L_1 = ___0_pool;
		NullCheck(L_1);
		RenderGraphObjectPool_Release_TisRasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5_mD5CB3750BC13540EB409FFFA3DF8D99254ACBEE3(L_1, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
// Method Definition Index: 33815
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RasterRenderGraphPass_1__ctor_m700EBCAD42FE4FEE5907B5A0DEAF64BF1DB398AE_gshared (RasterRenderGraphPass_1_tFCA1ECEF1DBF6BAFBE377302A430ADE5461BF5C5* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		BaseRenderGraphPass_2__ctor_mCDC1A0CF9B5800412AE9084F7EC4F02640701623((BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0*)__this, NULL);
		return;
	}
}
// Method Definition Index: 33816
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RasterRenderGraphPass_1__cctor_mC61E0D1269DE77EAED9B3DD302C803A0B2A099C0_gshared (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 41228
// Method Definition Index: 41229
// Method Definition Index: 41230
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 ReadOnly_get_Item_m1021453B5C0D6A393DD18A544DF4D37A69420519 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = __this->___m_Buffer;
		int32_t L_1 = ___0_index;
		EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 L_2;
		L_2 = UnsafeUtility_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m79879C1B15242483D8C9C1E532366BB74B6B9526_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41231
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 ReadOnly_GetEnumerator_m528906E3EF4A9456E20EF0C13D5EF3BDCCCA68C6 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m3A87BBB2A08731ABFE824690AC9B5CCEA26C3230((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 41232
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF7175A19D7496848399699A14F05C3F459EB2A9F (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 L_0;
		L_0 = ReadOnly_GetEnumerator_m528906E3EF4A9456E20EF0C13D5EF3BDCCCA68C6(__this, NULL);
		Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF7175A19D7496848399699A14F05C3F459EB2A9F_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF7175A19D7496848399699A14F05C3F459EB2A9F(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 41233
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m771309A3943DD52F356713520E5847B64F5ED776 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 L_0;
		L_0 = ReadOnly_GetEnumerator_m528906E3EF4A9456E20EF0C13D5EF3BDCCCA68C6(__this, NULL);
		Enumerator_tBE854A34714FE4D84B3C7363E9CCB48170372A84 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m771309A3943DD52F356713520E5847B64F5ED776_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_IEnumerable_GetEnumerator_m771309A3943DD52F356713520E5847B64F5ED776(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 41234
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000 ReadOnly_AsReadOnlySpan_m90E1098CA34AC7F37C10E9969BA4A7013F6C54F7 (ReadOnly_t83D3DFB2E532F05897D1DF6CB3287BE0347B03C0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = __this->___m_Buffer;
		int32_t L_1 = __this->___m_Length;
		ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000 L_2;
		memset((&L_2), 0, sizeof(L_2));
		ReadOnlySpan_1__ctor_mF2ADB2B548C4E7719F88D0ABC14770AE5E4DE14E_inline((&L_2), L_0, L_1, NULL);
		return L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 41228
// Method Definition Index: 41229
// Method Definition Index: 41230
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 ReadOnly_get_Item_mA8FFFD9EE2AE2408BDB8770BDB48DAD906D7B9C7 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = __this->___m_Buffer;
		int32_t L_1 = ___0_index;
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 L_2;
		L_2 = UnsafeUtility_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m720F581823253EB0096D98EFD58895FE0BB22ADC_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 41231
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 ReadOnly_GetEnumerator_mE97AA423CE9B9DEC906072E0C7E82BDD9A8AF978 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m364E1260B5DD21E99ABFA49B3604FCCAA6F85492((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 41232
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3FD84C71B90DF8F9C615D1AFCB853FAF46B269DE (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 L_0;
		L_0 = ReadOnly_GetEnumerator_mE97AA423CE9B9DEC906072E0C7E82BDD9A8AF978(__this, NULL);
		Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3FD84C71B90DF8F9C615D1AFCB853FAF46B269DE_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m3FD84C71B90DF8F9C615D1AFCB853FAF46B269DE(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 41233
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m1979B3B3643C821B2D70FAFD2CFEE610F4BF1E12 (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 L_0;
		L_0 = ReadOnly_GetEnumerator_mE97AA423CE9B9DEC906072E0C7E82BDD9A8AF978(__this, NULL);
		Enumerator_t6A89C5006E6904372CFF0CD93293D4B5E7FA8A70 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m1979B3B3643C821B2D70FAFD2CFEE610F4BF1E12_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_IEnumerable_GetEnumerator_m1979B3B3643C821B2D70FAFD2CFEE610F4BF1E12(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 41234
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA ReadOnly_AsReadOnlySpan_m2189A51A07BB7A569F0FC48CADAA4F4770CDF01D (ReadOnly_t292A54C03EBFB000848E9F81B2C33BA04B0AD874* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = __this->___m_Buffer;
		int32_t L_1 = __this->___m_Length;
		ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA L_2;
		memset((&L_2), 0, sizeof(L_2));
		ReadOnlySpan_1__ctor_mA00771A913574E450B7709FFE23409830DB02E45_inline((&L_2), L_0, L_1, NULL);
		return L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 67750
// Method Definition Index: 67751
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA ReadOnly_op_Implicit_m1DCC4A66B101C99ED2BC131B27710F431E6B8ABC (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* ___0_container, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* L_0 = ___0_container;
		ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA L_1;
		L_1 = ReadOnly_AsReadOnlySpan_mAE13768A63AEAFD3CE987DFB3475114C49A01A6E(L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 67752
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA ReadOnly_AsReadOnlySpan_mAE13768A63AEAFD3CE987DFB3475114C49A01A6E (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_0;
		L_0 = ReadOnly_GetUnsafeReadOnlyPtr_m176DCA161E95AE15D5E0339254D38B095BFFD2B2_inline(__this, NULL);
		int32_t L_1 = __this->___Length;
		ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA L_2;
		memset((&L_2), 0, sizeof(L_2));
		ReadOnlySpan_1__ctor_mA00771A913574E450B7709FFE23409830DB02E45_inline((&L_2), (void*)L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 67753
// Method Definition Index: 67754
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ReadOnly_get_IsEmpty_m6CB2913911A1BA6BFB954525D260B2C2475415C6 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = ReadOnly_get_IsCreated_m4D7E01A569059DE28E8184D5013A248982A9A43B_inline(__this, NULL);
		if (!L_0)
		{
			goto IL_0012;
		}
	}
	{
		int32_t L_1 = __this->___Length;
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0012:
	{
		return (bool)1;
	}
}
// Method Definition Index: 67755
// Method Definition Index: 67756
// Method Definition Index: 67757
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m09A002D7239A9B1138F5CBEF78D5C1F13A6E8357 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* L_0 = (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var)));
		NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_IEnumerable_GetEnumerator_m09A002D7239A9B1138F5CBEF78D5C1F13A6E8357_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_IEnumerable_GetEnumerator_m09A002D7239A9B1138F5CBEF78D5C1F13A6E8357(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 67758
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m42E8E7CFF421EAADEE0DCD1D60FDEAFAA3C63AB2 (ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* L_0 = (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var)));
		NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C  RuntimeObject* ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m42E8E7CFF421EAADEE0DCD1D60FDEAFAA3C63AB2_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<ReadOnly_t0D4B661ADD44783DAD5E256CFABB1D2736D6C7CD>(__this);
	RuntimeObject* _returnValue;
	_returnValue = ReadOnly_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m42E8E7CFF421EAADEE0DCD1D60FDEAFAA3C63AB2(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 94113
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_x;
		int32_t L_1 = ___1_y;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_y;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_x;
		return L_3;
	}
}
// Method Definition Index: 94127
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float math_max_mC2D5D2F0EB91D3A908AE964BE8BF5EA443C3BF64_inline (float ___0_x, float ___1_y, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0 = ___1_y;
		bool L_1;
		L_1 = Single_IsNaN_mFE637F6ECA9F7697CE8EFF56427858F4C5EDF75D_inline(L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		float L_2 = ___0_x;
		float L_3 = ___1_y;
		if ((((float)L_2) > ((float)L_3)))
		{
			goto IL_000e;
		}
	}
	{
		float L_4 = ___1_y;
		return L_4;
	}

IL_000e:
	{
		float L_5 = ___0_x;
		return L_5;
	}
}
// Method Definition Index: 60817
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RBTreeEnumerator_get_Current_mCB9EE3BDCE8D688E0B6EA03B14E5D55ABF7E1325_inline (RBTreeEnumerator_tF257C6FDF2C10A1562F799244369D9CD12476115* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 60817
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* RBTreeEnumerator_get_Current_mCA7EABFD3BB38F4E43C81EB2C51698DA685F4728_gshared_inline (RBTreeEnumerator_t0E8BDA901C4E1E2B1225208B209F9CC75DE74AAF* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 60817
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RBTreeEnumerator_get_Current_m55E7496F0199640CB43772D3C21F0A10462AE734_fshared_inline (RBTreeEnumerator_tE61475E1E3545F58E0C1C1D72563D15F8461DEE4* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_K_t7B4CA93C15E2757B99FA8D99488CED98D2FAAC71);
		return;
	}
}
// Method Definition Index: 60810
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_InUseCount_mF6068EC2FA94F4B17098D5C83B965F4703FA033A_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->____inUseCount = L_0;
		return;
	}
}
// Method Definition Index: 60811
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_PageId_mB8F6DE559009BD1B1683DD96A132A8AF8229F6C7_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____pageId;
		return L_0;
	}
}
// Method Definition Index: 60812
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TreePage_set_PageId_m106D0788C3D06308F04C6400B1B3D166396CF84D_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		__this->____pageId = L_0;
		return;
	}
}
// Method Definition Index: 60809
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t TreePage_get_InUseCount_m54A6D752FBFA8E21B9BE911DEFEBB6EBE27F86B4_fshared_inline (TreePage_tF4637AF4FFA85E17BF2F4D25064C7D17EF8DC689* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->____inUseCount;
		return L_0;
	}
}
// Method Definition Index: 41286
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafePtr_TisIl2CppFullySharedGenericStruct_m4AB802D5B1B296D0F976C1E7631699B0C4A4D00F_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_0 = ___0_nativeArray;
		void* L_1 = L_0.___m_Buffer;
		return L_1;
	}
}
// Method Definition Index: 41337
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t* UnsafeUtility_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mF01FDF0EACCFED286E93933B693A2BE11A6A8946_inline (void* ___0_ptr, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_ptr;
		int32_t* L_1;
		L_1 = UnsafeUtilityInternal_AsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m77E9B9B716D93AB00C90A84F70C3C6CE55E4A342_inline(L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 11360
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m6C8D51A9406D6ED9B43B6F126A83EF286FB5DFB3_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 11352
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m641521748E28764A6131ED25D555ABC4FF9793D6_inline (List_1_tE5F26F978E0CC0A731A4FA2B7B4F7D620D6250E6* __this, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___0_item, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* L_4 = V_0;
		NullCheck(L_4);
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		float3U5BU5D_tD4EB6079482A23C25E32ADEEB6D23996502A6251* L_7 = V_0;
		int32_t L_8 = V_1;
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_9 = ___0_item;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(L_8), (float3_t7600B73F092B37F484B12910A5269F30C778D31E)L_9);
		return;
	}

IL_0034:
	{
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_10 = ___0_item;
		List_1_AddWithResize_m5228B46F845892F0F239CC9D7314DF4BA90F6DDE(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
// Method Definition Index: 33616
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseRenderFunc_2_Invoke_m74AE14F084437149C944CF85887E55871ACC81D8_gshared_inline (BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887* __this, Il2CppSharedGenericObject* ___0_data, RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147 ___1_renderGraphContext, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, RasterGraphContext_tC4D3E53FF7131476487751ACB0237D56C8327147, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_data, ___1_renderGraphContext, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 33801
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseRenderGraphPass_2_Release_m71C367F7732998859F6B2A4C2168D31BD2922A77_gshared_inline (BaseRenderGraphPass_2_t0AF6BFAED5CCF34357BCDFF4635722371B04DBB0* __this, RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* ___0_pool, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		RenderGraphObjectPool_t2F5488D55D836B54B6E85D2952105BA61AEE6437* L_0 = ___0_pool;
		Il2CppSharedGenericObject* L_1 = __this->___data;
		NullCheck(L_0);
		RenderGraphObjectPool_Release_TisIl2CppSharedGenericObject_m41E89F411886EB72C412391048C5DFBB4BF6BFFC(L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		Il2CppSharedGenericObject** L_2 = (Il2CppSharedGenericObject**)(&__this->___data);
		il2cpp_codegen_initobj(L_2, sizeof(Il2CppSharedGenericObject*));
		__this->___renderFunc = (BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___renderFunc), (void*)(BaseRenderFunc_2_t6A57B1FE582E8C654CB210BB42CE0FED1FE63887*)NULL);
		return;
	}
}
// Method Definition Index: 41328
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtility_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m79879C1B15242483D8C9C1E532366BB74B6B9526_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m792E549B89DCE71909B3BCA2EC23DE250E72A16E_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 2374
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mF2ADB2B548C4E7719F88D0ABC14770AE5E4DE14E_inline (ReadOnlySpan_1_t7F03D2582CD1D30379484DC4C7234A09661B8000* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96* L_2;
		L_2 = il2cpp_unsafe_as_ref<EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96>((uint8_t*)L_1);
		ByReference_1_t96DAE667B9BC20DC5FA90542D560148F31E98B83 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
// Method Definition Index: 41328
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtility_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m720F581823253EB0096D98EFD58895FE0BB22ADC_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m75B3FAF2E30DFD3256DD7F68C14C58B209BDD96E_inline(L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 2374
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mA00771A913574E450B7709FFE23409830DB02E45_inline (ReadOnlySpan_1_tE3210CB260ACE9EAED2369F5CCC0DB30753D60FA* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62* L_2;
		L_2 = il2cpp_unsafe_as_ref<NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62>((uint8_t*)L_1);
		ByReference_1_tCE52B202D24A2ECB85FE96F1DA3C0C6BB73E4001 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
// Method Definition Index: 67750
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* ReadOnly_GetUnsafeReadOnlyPtr_m11650CC49E2419A1F3F08A3E0B9770609DA91122_fshared_inline (ReadOnly_t620C834D6C54D781225D753876F232E09821956C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericStruct* L_0 = __this->___Ptr;
		return L_0;
	}
}
// Method Definition Index: 67753
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool ReadOnly_get_IsCreated_m04CC508FD89227103673F7F50C2BE835423CFF2A_fshared_inline (ReadOnly_t620C834D6C54D781225D753876F232E09821956C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppFullySharedGenericStruct* L_0 = __this->___Ptr;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 2430
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Single_IsNaN_mFE637F6ECA9F7697CE8EFF56427858F4C5EDF75D_inline (float ___0_f, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0 = ___0_f;
		int32_t L_1;
		L_1 = BitConverter_SingleToInt32Bits_mC760C7CFC89725E3CF68DC45BE3A9A42A7E7DA73_inline(L_0, NULL);
		return (bool)((((int32_t)((int32_t)(L_1&((int32_t)2147483647LL)))) > ((int32_t)((int32_t)2139095040)))? 1 : 0);
	}
}
// Method Definition Index: 96440
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* UnsafeUtilityInternal_AsRef_TisIl2CppFullySharedGenericStruct_m4AE204964F54C3F7626BE47CADE4A52CF2797B6B_fshared_inline (void* ___0_ptr, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_ptr;
		return (Il2CppFullySharedGenericStruct*)(L_0);
	}
}
// Method Definition Index: 96431
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 UnsafeUtilityInternal_ReadArrayElement_TisEmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96_m792E549B89DCE71909B3BCA2EC23DE250E72A16E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96 L_6 = (*(EmbeddedArray32_1_tB435A10C3DB5E0B01F53C5CF569FEF40BB061A96*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 96431
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 UnsafeUtilityInternal_ReadArrayElement_TisNativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62_m75B3FAF2E30DFD3256DD7F68C14C58B209BDD96E_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62 L_6 = (*(NativeArray_1_t3C666A50D3E0F5803B63036EC771A974D48FFF62*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
// Method Definition Index: 1034
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t BitConverter_SingleToInt32Bits_mC760C7CFC89725E3CF68DC45BE3A9A42A7E7DA73_inline (float ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>((&___0_value),NULL));
		int32_t L_1 = *(((int32_t*)L_0));
		return L_1;
	}
}
