#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
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

struct Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A;
struct Action_1_t17E52B12DC24FA6C9DD52F87043C85BEA889BB81;
struct Action_1_t2EDB30EAB747FDF563DD6410FC76AF861A09A0C2;
struct Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF;
struct Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505;
struct Action_1_tC8822DDEF41267DA3844DAD787ACE63C0C385E89;
struct Action_2_tF46B14C98A24F40F2279A1D4296BB9078938C034;
struct Action_2_t115BA48255E00E3E7D79535060D729C4822CAFF3;
struct Action_2_t302322518DED0A32BC10F069AAEE117BC9C20917;
struct Action_2_t09DA61027B1820298B3AEBAB627FBF4C0CCC66B4;
struct Action_3_tCDDEBF125C30A90B3A5061DE417B889F78E7DB83;
struct Action_3_tAD728960C80D3C14B956508C335D759770FE2F6E;
struct Action_3_t57DE42DCD9F152289CA8303B0B1AB7246E7FE864;
struct Action_3_tE77469DC1E6595CCDCD9A1404CBA045A1C0AA560;
struct Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3;
struct Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28;
struct EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4;
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8;
struct EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB;
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B;
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC;
struct EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504;
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B;
struct EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499;
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70;
struct EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862;
struct EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17;
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081;
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC;
struct Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED;
struct Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18;
struct Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD;
struct Field_1_tEE1A923EA8160028BC34CE74DF77A8FB37FCA5D3;
struct Func_1_t2BE7F58348C9CC544A8973B3A9E55541DE43C457;
struct Func_1_t9EB8CE9DFD9B703BC79F2087B16EA394B7A9F9A1;
struct Func_1_t58C51DB29153B53A9136AE397958F3FCC1F596EC;
struct Func_1_t704C051013549CDD77A31AEC405EA270221633B3;
struct Func_1_t87EB6A475C10479F9DA4442B05AC1022C1B7419C;
struct Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59;
struct Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE;
struct Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0;
struct Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219;
struct Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C;
struct Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3;
struct Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1;
struct Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98;
struct Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C;
struct Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910;
struct Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19;
struct Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE;
struct Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02;
struct VectorField_1_tA0DD3460E58AEABD9D5B33110FC64F4490179B87;
struct VectorField_1_t922D9F74763B4AFD1C1760DE2236972042F8310D;
struct VectorField_1_t7640EEE30580F0D8ABCA05DBBAB2F6B83A4713C3;
struct VectorField_1_tA0B76D2246CE6687E43856049B2DB46975532D1F;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B;
struct CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0;
struct DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A;
struct Delegate_t;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IFormatProvider_tC202922D43BFF3525109ABF3FB79625F5646AB52;
struct ISelectorInfo_t331D7C316F79BE303CAF465853FEDB7278346FA1;
struct IVariable_t3A533486D2AAB02776F3F7AF0FAF50737C3E682F;
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct StringBuilder_t;
struct TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct IContainer_tBD9F21C42D4253E306C4EF7CFC72480E0C7C89B5;
struct Panel_t3A0D2006E8AEA607A6DF5188138E463A26085295;

IL2CPP_EXTERN_C RuntimeClass* Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869;
IL2CPP_EXTERN_C String_t* _stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4  : public RuntimeObject
{
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8  : public RuntimeObject
{
};
struct EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB  : public RuntimeObject
{
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B  : public RuntimeObject
{
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC  : public RuntimeObject
{
};
struct EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504  : public RuntimeObject
{
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B  : public RuntimeObject
{
};
struct EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499  : public RuntimeObject
{
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70  : public RuntimeObject
{
};
struct EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862  : public RuntimeObject
{
};
struct EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17  : public RuntimeObject
{
};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081  : public RuntimeObject
{
};
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC  : public RuntimeObject
{
};
struct Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59  : public RuntimeObject
{
	bool ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE  : public RuntimeObject
{
	uint8_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0  : public RuntimeObject
{
	double ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219  : public RuntimeObject
{
	int16_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C  : public RuntimeObject
{
	int32_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3  : public RuntimeObject
{
	int64_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1  : public RuntimeObject
{
	int8_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98  : public RuntimeObject
{
	float ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C  : public RuntimeObject
{
	uint16_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910  : public RuntimeObject
{
	uint32_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19  : public RuntimeObject
{
	uint64_t ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE  : public RuntimeObject
{
	Il2CppSharedGenericObject* ___m_Value;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___ValueChanged;
};
struct Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02 : public RuntimeObject {};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0  : public RuntimeObject
{
	bool ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	bool ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	String_t* ___m_name;
	String_t* ___englishname;
	String_t* ___nativename;
	String_t* ___iso3lang;
	String_t* ___iso2lang;
	String_t* ___win3lang;
	String_t* ___territory;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___parent_culture;
	bool ___constructed;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D* ___m_cultureData;
	bool ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	char* ___m_name;
	char* ___englishname;
	char* ___nativename;
	char* ___iso3lang;
	char* ___iso2lang;
	char* ___win3lang;
	char* ___territory;
	char** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	Il2CppChar* ___m_name;
	Il2CppChar* ___englishname;
	Il2CppChar* ___nativename;
	Il2CppChar* ___iso3lang;
	Il2CppChar* ___iso2lang;
	Il2CppChar* ___win3lang;
	Il2CppChar* ___territory;
	Il2CppChar** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___numberGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___currencyGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___percentGroupSizes;
	String_t* ___positiveSign;
	String_t* ___negativeSign;
	String_t* ___numberDecimalSeparator;
	String_t* ___numberGroupSeparator;
	String_t* ___currencyGroupSeparator;
	String_t* ___currencyDecimalSeparator;
	String_t* ___currencySymbol;
	String_t* ___ansiCurrencySymbol;
	String_t* ___nanSymbol;
	String_t* ___positiveInfinitySymbol;
	String_t* ___negativeInfinitySymbol;
	String_t* ___percentDecimalSeparator;
	String_t* ___percentGroupSeparator;
	String_t* ___percentSymbol;
	String_t* ___perMilleSymbol;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___nativeDigits;
	int32_t ___m_dataItem;
	int32_t ___numberDecimalDigits;
	int32_t ___currencyDecimalDigits;
	int32_t ___currencyPositivePattern;
	int32_t ___currencyNegativePattern;
	int32_t ___numberNegativePattern;
	int32_t ___percentPositivePattern;
	int32_t ___percentNegativePattern;
	int32_t ___percentDecimalDigits;
	int32_t ___digitSubstitution;
	bool ___isReadOnly;
	bool ___m_useUserOverride;
	bool ___m_isInvariant;
	bool ___validForParseAsNumber;
	bool ___validForParseAsCurrency;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
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
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
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
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___byte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___byte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_1_OffsetPadding[1];
			uint8_t ___byte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___byte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_2_OffsetPadding[2];
			uint8_t ___byte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___byte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_3_OffsetPadding[3];
			uint8_t ___byte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___byte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_4_OffsetPadding[4];
			uint8_t ___byte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___byte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_5_OffsetPadding[5];
			uint8_t ___byte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___byte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_6_OffsetPadding[6];
			uint8_t ___byte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___byte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_7_OffsetPadding[7];
			uint8_t ___byte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___byte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_8_OffsetPadding[8];
			uint8_t ___byte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_8_OffsetPadding_forAlignmentOnly[8];
			uint8_t ___byte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_9_OffsetPadding[9];
			uint8_t ___byte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_9_OffsetPadding_forAlignmentOnly[9];
			uint8_t ___byte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_10_OffsetPadding[10];
			uint8_t ___byte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_10_OffsetPadding_forAlignmentOnly[10];
			uint8_t ___byte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_11_OffsetPadding[11];
			uint8_t ___byte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_11_OffsetPadding_forAlignmentOnly[11];
			uint8_t ___byte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_12_OffsetPadding[12];
			uint8_t ___byte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_12_OffsetPadding_forAlignmentOnly[12];
			uint8_t ___byte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_13_OffsetPadding[13];
			uint8_t ___byte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_13_OffsetPadding_forAlignmentOnly[13];
			uint8_t ___byte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_14_OffsetPadding[14];
			uint8_t ___byte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_14_OffsetPadding_forAlignmentOnly[14];
			uint8_t ___byte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_15_OffsetPadding[15];
			uint8_t ___byte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_15_OffsetPadding_forAlignmentOnly[15];
			uint8_t ___byte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___sbyte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___sbyte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_1_OffsetPadding[1];
			int8_t ___sbyte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___sbyte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_2_OffsetPadding[2];
			int8_t ___sbyte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___sbyte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_3_OffsetPadding[3];
			int8_t ___sbyte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___sbyte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_4_OffsetPadding[4];
			int8_t ___sbyte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___sbyte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_5_OffsetPadding[5];
			int8_t ___sbyte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___sbyte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_6_OffsetPadding[6];
			int8_t ___sbyte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___sbyte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_7_OffsetPadding[7];
			int8_t ___sbyte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___sbyte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_8_OffsetPadding[8];
			int8_t ___sbyte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_8_OffsetPadding_forAlignmentOnly[8];
			int8_t ___sbyte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_9_OffsetPadding[9];
			int8_t ___sbyte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_9_OffsetPadding_forAlignmentOnly[9];
			int8_t ___sbyte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_10_OffsetPadding[10];
			int8_t ___sbyte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_10_OffsetPadding_forAlignmentOnly[10];
			int8_t ___sbyte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_11_OffsetPadding[11];
			int8_t ___sbyte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_11_OffsetPadding_forAlignmentOnly[11];
			int8_t ___sbyte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_12_OffsetPadding[12];
			int8_t ___sbyte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_12_OffsetPadding_forAlignmentOnly[12];
			int8_t ___sbyte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_13_OffsetPadding[13];
			int8_t ___sbyte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_13_OffsetPadding_forAlignmentOnly[13];
			int8_t ___sbyte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_14_OffsetPadding[14];
			int8_t ___sbyte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_14_OffsetPadding_forAlignmentOnly[14];
			int8_t ___sbyte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_15_OffsetPadding[15];
			int8_t ___sbyte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_15_OffsetPadding_forAlignmentOnly[15];
			int8_t ___sbyte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___uint16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___uint16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_1_OffsetPadding[2];
			uint16_t ___uint16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___uint16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_2_OffsetPadding[4];
			uint16_t ___uint16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___uint16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_3_OffsetPadding[6];
			uint16_t ___uint16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___uint16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_4_OffsetPadding[8];
			uint16_t ___uint16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_4_OffsetPadding_forAlignmentOnly[8];
			uint16_t ___uint16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_5_OffsetPadding[10];
			uint16_t ___uint16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_5_OffsetPadding_forAlignmentOnly[10];
			uint16_t ___uint16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_6_OffsetPadding[12];
			uint16_t ___uint16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_6_OffsetPadding_forAlignmentOnly[12];
			uint16_t ___uint16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_7_OffsetPadding[14];
			uint16_t ___uint16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_7_OffsetPadding_forAlignmentOnly[14];
			uint16_t ___uint16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___int16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___int16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_1_OffsetPadding[2];
			int16_t ___int16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___int16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_2_OffsetPadding[4];
			int16_t ___int16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___int16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_3_OffsetPadding[6];
			int16_t ___int16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___int16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_4_OffsetPadding[8];
			int16_t ___int16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_4_OffsetPadding_forAlignmentOnly[8];
			int16_t ___int16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_5_OffsetPadding[10];
			int16_t ___int16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_5_OffsetPadding_forAlignmentOnly[10];
			int16_t ___int16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_6_OffsetPadding[12];
			int16_t ___int16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_6_OffsetPadding_forAlignmentOnly[12];
			int16_t ___int16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_7_OffsetPadding[14];
			int16_t ___int16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_7_OffsetPadding_forAlignmentOnly[14];
			int16_t ___int16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___uint32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___uint32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_1_OffsetPadding[4];
			uint32_t ___uint32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___uint32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_2_OffsetPadding[8];
			uint32_t ___uint32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_2_OffsetPadding_forAlignmentOnly[8];
			uint32_t ___uint32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_3_OffsetPadding[12];
			uint32_t ___uint32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_3_OffsetPadding_forAlignmentOnly[12];
			uint32_t ___uint32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___int32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___int32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_1_OffsetPadding[4];
			int32_t ___int32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___int32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_2_OffsetPadding[8];
			int32_t ___int32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_2_OffsetPadding_forAlignmentOnly[8];
			int32_t ___int32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_3_OffsetPadding[12];
			int32_t ___int32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_3_OffsetPadding_forAlignmentOnly[12];
			int32_t ___int32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___uint64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___uint64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint64_1_OffsetPadding[8];
			uint64_t ___uint64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint64_1_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___uint64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___int64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___int64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int64_1_OffsetPadding[8];
			int64_t ___int64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int64_1_OffsetPadding_forAlignmentOnly[8];
			int64_t ___int64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___single_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___single_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_1_OffsetPadding[4];
			float ___single_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_1_OffsetPadding_forAlignmentOnly[4];
			float ___single_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_2_OffsetPadding[8];
			float ___single_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_2_OffsetPadding_forAlignmentOnly[8];
			float ___single_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_3_OffsetPadding[12];
			float ___single_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_3_OffsetPadding_forAlignmentOnly[12];
			float ___single_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___double_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___double_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___double_1_OffsetPadding[8];
			double ___double_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___double_1_OffsetPadding_forAlignmentOnly[8];
			double ___double_1_forAlignmentOnly;
		};
	};
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
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
struct Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
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
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct Flags_tBBD3C554E9057BB9AC0476F92D0328575F2C4193 
{
	int32_t ___value__;
};
struct VectorSizeHelper_tC26CEAD1B0D88F765A24D653A74900C4C7FEBD18 
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ____placeholder;
	uint8_t ____byte;
};
struct VectorSizeHelper_tF54ACCE947CB8A38047BEB642392A4E7345A157D 
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ____placeholder;
	uint8_t ____byte;
};
struct VectorSizeHelper_tAB183E4966E0B97A19A75D213EDAE51037A6BF3C 
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ____placeholder;
	uint8_t ____byte;
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
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Widget_tE8D6AF1D7525CC84E8F2C3B73162016736A6A2FF  : public RuntimeObject
{
	int32_t ___U3CorderU3Ek__BackingField;
	Panel_t3A0D2006E8AEA607A6DF5188138E463A26085295* ___m_Panel;
	RuntimeObject* ___m_Parent;
	int32_t ___U3CflagsU3Ek__BackingField;
	String_t* ___U3CdisplayNameU3Ek__BackingField;
	String_t* ___U3CtooltipU3Ek__BackingField;
	String_t* ___U3CqueryPathU3Ek__BackingField;
	Func_1_t2BE7F58348C9CC544A8973B3A9E55541DE43C457* ___isHiddenCallback;
};
struct Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A  : public MulticastDelegate_t
{
};
struct Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505  : public MulticastDelegate_t
{
};
struct Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED  : public Widget_tE8D6AF1D7525CC84E8F2C3B73162016736A6A2FF
{
	Func_1_t9EB8CE9DFD9B703BC79F2087B16EA394B7A9F9A1* ___U3CgetterU3Ek__BackingField;
	Action_1_t17E52B12DC24FA6C9DD52F87043C85BEA889BB81* ___U3CsetterU3Ek__BackingField;
	Action_2_tF46B14C98A24F40F2279A1D4296BB9078938C034* ___onValueChanged;
};
struct Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18  : public Widget_tE8D6AF1D7525CC84E8F2C3B73162016736A6A2FF
{
	Func_1_t58C51DB29153B53A9136AE397958F3FCC1F596EC* ___U3CgetterU3Ek__BackingField;
	Action_1_t2EDB30EAB747FDF563DD6410FC76AF861A09A0C2* ___U3CsetterU3Ek__BackingField;
	Action_2_t115BA48255E00E3E7D79535060D729C4822CAFF3* ___onValueChanged;
};
struct Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD  : public Widget_tE8D6AF1D7525CC84E8F2C3B73162016736A6A2FF
{
	Func_1_t704C051013549CDD77A31AEC405EA270221633B3* ___U3CgetterU3Ek__BackingField;
	Action_1_t84D0CA347FC997E1202ECA3ED828B057841444EF* ___U3CsetterU3Ek__BackingField;
	Action_2_t302322518DED0A32BC10F069AAEE117BC9C20917* ___onValueChanged;
};
struct Field_1_tEBDBEF6C7E8EC7F1DBE1ABC4B1EA917269E20258  : public Widget_tE8D6AF1D7525CC84E8F2C3B73162016736A6A2FF
{
	Func_1_t87EB6A475C10479F9DA4442B05AC1022C1B7419C* ___U3CgetterU3Ek__BackingField;
	Action_1_tC8822DDEF41267DA3844DAD787ACE63C0C385E89* ___U3CsetterU3Ek__BackingField;
	Action_2_t09DA61027B1820298B3AEBAB627FBF4C0CCC66B4* ___onValueChanged;
};
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct VectorField_1_tA0DD3460E58AEABD9D5B33110FC64F4490179B87  : public Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED
{
	float ___incStep;
	float ___incStepMult;
	int32_t ___decimals;
};
struct VectorField_1_t922D9F74763B4AFD1C1760DE2236972042F8310D  : public Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18
{
	float ___incStep;
	float ___incStepMult;
	int32_t ___decimals;
};
struct VectorField_1_t7640EEE30580F0D8ABCA05DBBAB2F6B83A4713C3  : public Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD
{
	float ___incStep;
	float ___incStepMult;
	int32_t ___decimals;
};
struct VectorField_1_tA0B76D2246CE6687E43856049B2DB46975532D1F  : public Field_1_tEBDBEF6C7E8EC7F1DBE1ABC4B1EA917269E20258
{
	float ___incStep;
	float ___incStepMult;
	int32_t ___decimals;
};
struct EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4_StaticFields
{
	EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* ___defaultComparer;
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields
{
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* ___defaultComparer;
};
struct EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB_StaticFields
{
	EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* ___defaultComparer;
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields
{
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* ___defaultComparer;
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields
{
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* ___defaultComparer;
};
struct EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504_StaticFields
{
	EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* ___defaultComparer;
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields
{
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* ___defaultComparer;
};
struct EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499_StaticFields
{
	EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* ___defaultComparer;
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields
{
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* ___defaultComparer;
};
struct EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862_StaticFields
{
	EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* ___defaultComparer;
};
struct EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17_StaticFields
{
	EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* ___defaultComparer;
};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields
{
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* ___defaultComparer;
};
struct EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC_StaticFields
{
	EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* ___defaultComparer;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticFields
{
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___invariant_culture_info;
	RuntimeObject* ___shared_table_lock;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___default_current_culture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentUICulture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentCulture;
	Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3* ___shared_by_number;
	Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28* ___shared_by_name;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_UserPreferredCultureInfoInAppX;
	bool ___IsTaiwanSku;
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472_StaticFields
{
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___invariantInfo;
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
struct Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields
{
	int32_t ___s_count;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_zero;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_one;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_allOnes;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields
{
	int32_t ___s_count;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_zero;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_one;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_allOnes;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields
{
	int32_t ___s_count;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_zero;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_one;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_allOnes;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
struct Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED_StaticFields
{
	Action_3_tCDDEBF125C30A90B3A5061DE417B889F78E7DB83* ___onWidgetValueChangedAnalytic;
};
struct Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18_StaticFields
{
	Action_3_tAD728960C80D3C14B956508C335D759770FE2F6E* ___onWidgetValueChangedAnalytic;
};
struct Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD_StaticFields
{
	Action_3_t57DE42DCD9F152289CA8303B0B1AB7246E7FE864* ___onWidgetValueChangedAnalytic;
};
struct Field_1_tEBDBEF6C7E8EC7F1DBE1ABC4B1EA917269E20258_StaticFields
{
	Action_3_tE77469DC1E6595CCDCD9A1404CBA045A1C0AA560* ___onWidgetValueChangedAnalytic;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mEAD210FE11BB24BA65C5E0A48E07ACEC79AC434F (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* EqualityComparer_1_get_Default_mBB75BC0723DFD7850F43E72E34026DD070CF5932_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mF27191B60F7096690DC3CFE32095007E44E14592 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mF84138168B087F3A4F8BB9B909B6E2734D0C0538 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, uint8_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m91A7E802951455D643936E83680488D59E776556 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m59A35AF7F79D01DA4C22AD6BE72E8E63850ACA5B (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, double ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* EqualityComparer_1_get_Default_m12CC270D19620F4E8E3ABFE7BF8C2B1955476A04_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m349325562E935627F4A0E2D5A074E0EA38B682A5 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m86DFAABAACEF946ADDCDFBCCBAA787D657947FE9 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, int16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m58111E04F07046609ED26B4DB3AECF5CECD5B641 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m6ECD9D07F682D6221F7E010AE085DC5D8D6FE7BD (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m1EF099E4C69D63D1E408E7F2435FE7AC8361D443 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m3D7A6A7175666F2CD293B927C0877CE69FD1435C (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, int64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* EqualityComparer_1_get_Default_m76691DC579907239261E159E4DFDD8B1C3C9E5FE_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m79EA014A19F44C40E29FB554025AA37D74A1C12A (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m60AE096CCE83CBD8DB5EDE23A8CD9C6DA81AC3ED (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, int8_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m8DB2C9A817C4D6F18CAE8B25D3C317A20E283948 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mE48B2FBE844526B085300D488FCED926B1DE510F (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, float ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* EqualityComparer_1_get_Default_m20A1B9861324559044977270E1FAFB09BBE14234_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m6BD5AD55C128B6F073D226292AD298CA1184F64A (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m5AF2E2CA2E14ED72ACC65F9A7EC9667A837F3C8B (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, uint16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mE2E037FF501B8E836DC2A7E2C082BB1222A6CFA0 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m171AA2559B7763FB08BA8D99AB9FA15993F92E2D (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, uint32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* EqualityComparer_1_get_Default_mF554877B669658FD6449F84AE369214855D0BC40_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m0980A239523AA674EDBFE4BC9E76687DBE5BE9B8 (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mA7FD3EF090B4E011BDAC4DB770CEC9D343450C08 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* EqualityComparer_1_get_Default_m65C88AD76FA11C898FE9437B5D46E13B12F10B77_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mABC4B61F172A2CC6E10FB1F617C1758EBEF7E8A6 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_gshared_inline (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mAAC33DA3B7E3E3486928146EC132AAD281558C17_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m6521249C37B924F58684E926A431A201B6E48C9A_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Field_1__ctor_m6A0C971C6E2C7FC18B971B357D1CC034215D6043_fshared (Field_1_tEE1A923EA8160028BC34CE74DF77A8FB37FCA5D3* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m8212BCFF76673CC904541B2D9AF39E5FF124B359 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3C7CFE908C6BB2DC94F94F7615F2D1AF0E2777D9 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m2444D8FDCF0568D259DAE989EB7BCC77D37B2D6D (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mB42F3DAE52C3BC7579B302E623196C45A5DEAC6B_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_m43BBDDA05FDAB290038584331DB79CB33C523B83 (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetOneValue_m7E814AFD17E4D390C12EF731DA01203D262D9953_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mDA4A6115C4120BFDD773FD4D3753FD3EC2B10427 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, uint16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetAllBitsSetValue_m854DE079EA89F97089D3EF29D7C31F081F420580_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* EqualityComparer_1_CreateComparer_m3BD7BED1F69ABEE55E320BA9CCFBB473E9F57C66 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* EqualityComparer_1_CreateComparer_m66568B441EE3AB73D292C4F4CE1707FBAC360F5A (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* EqualityComparer_1_CreateComparer_m8A944543377C40C1596E4EECED12E463FC3DDFC3 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* EqualityComparer_1_CreateComparer_m4055D46D61B6AD80A0F2D4624577D7FE9D15B002 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* EqualityComparer_1_CreateComparer_m64D3D774E7DAF5FC0206DC26D9BA53BF70F1F93B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* EqualityComparer_1_CreateComparer_m73A019C274DF1E66D30647A3F24ADC27784B7114 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared (const RuntimeMethod* method) ;

IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mEAD210FE11BB24BA65C5E0A48E07ACEC79AC434F (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00 (Delegate_t* ___0_a, Delegate_t* ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3 (Delegate_t* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* EqualityComparer_1_get_Default_mBB75BC0723DFD7850F43E72E34026DD070CF5932_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mF27191B60F7096690DC3CFE32095007E44E14592 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) ;
inline void Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*, RuntimeObject*, const RuntimeMethod*))Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline)(__this, ___0_obj, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Boolean_ToString_m6646C8026B1DF381A1EE8CD13549175E9703CC63 (bool* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mF84138168B087F3A4F8BB9B909B6E2734D0C0538 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, uint8_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m91A7E802951455D643936E83680488D59E776556 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_mB80CE094B94215119578E4D796566E71D7277EE4 (uint8_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m59A35AF7F79D01DA4C22AD6BE72E8E63850ACA5B (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, double ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* EqualityComparer_1_get_Default_m12CC270D19620F4E8E3ABFE7BF8C2B1955476A04_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m349325562E935627F4A0E2D5A074E0EA38B682A5 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339 (double* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m86DFAABAACEF946ADDCDFBCCBAA787D657947FE9 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, int16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m58111E04F07046609ED26B4DB3AECF5CECD5B641 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int16_ToString_mD65153B762673B865D4F8FF9B567BECC1ABF6D23 (int16_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m6ECD9D07F682D6221F7E010AE085DC5D8D6FE7BD (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m1EF099E4C69D63D1E408E7F2435FE7AC8361D443 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m3D7A6A7175666F2CD293B927C0877CE69FD1435C (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, int64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* EqualityComparer_1_get_Default_m76691DC579907239261E159E4DFDD8B1C3C9E5FE_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m79EA014A19F44C40E29FB554025AA37D74A1C12A (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int64_ToString_m284E4E55662818E38654309A41C2B07CD436F36B (int64_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m60AE096CCE83CBD8DB5EDE23A8CD9C6DA81AC3ED (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, int8_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m8DB2C9A817C4D6F18CAE8B25D3C317A20E283948 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SByte_ToString_mAA885F58F9F739E25623423A059C735017A92708 (int8_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mE48B2FBE844526B085300D488FCED926B1DE510F (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, float ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* EqualityComparer_1_get_Default_m20A1B9861324559044977270E1FAFB09BBE14234_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m6BD5AD55C128B6F073D226292AD298CA1184F64A (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972 (float* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m5AF2E2CA2E14ED72ACC65F9A7EC9667A837F3C8B (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, uint16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mE2E037FF501B8E836DC2A7E2C082BB1222A6CFA0 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt16_ToString_m57629B7E74D92A54414073D5C27D6827C93A4DD5 (uint16_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m171AA2559B7763FB08BA8D99AB9FA15993F92E2D (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, uint32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* EqualityComparer_1_get_Default_mF554877B669658FD6449F84AE369214855D0BC40_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m0980A239523AA674EDBFE4BC9E76687DBE5BE9B8 (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt32_ToString_mB6FA6D2459C82ADCF285C55363491D9669A80154 (uint32_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mA7FD3EF090B4E011BDAC4DB770CEC9D343450C08 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* EqualityComparer_1_get_Default_m65C88AD76FA11C898FE9437B5D46E13B12F10B77_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mABC4B61F172A2CC6E10FB1F617C1758EBEF7E8A6 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt64_ToString_mD3AAE57EA18A6779F5A17E4F91C900A231EB0A6F (uint64_t* __this, const RuntimeMethod* method) ;
inline Il2CppSharedGenericObject* Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_inline (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE*, const RuntimeMethod*))Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_gshared_inline)(__this, method);
}
inline void Variable_1_set_Value_mAAC33DA3B7E3E3486928146EC132AAD281558C17 (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE*, Il2CppSharedGenericObject*, const RuntimeMethod*))Variable_1_set_Value_mAAC33DA3B7E3E3486928146EC132AAD281558C17_gshared)(__this, ___0_value, method);
}
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline)(method);
}
inline void Variable_1_SendValueChangedEvent_m6521249C37B924F58684E926A431A201B6E48C9A (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method)
{
	((  void (*) (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE*, const RuntimeMethod*))Variable_1_SendValueChangedEvent_m6521249C37B924F58684E926A431A201B6E48C9A_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline void Field_1__ctor_m7C303BA68691F2521E9EC689B23AE797B4DFBB05 (Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED* __this, const RuntimeMethod* method)
{
	((  void (*) (Field_1_tA072783C26CACD3E84F9B62900C79E98AA01B8ED*, const RuntimeMethod*))Field_1__ctor_m6A0C971C6E2C7FC18B971B357D1CC034215D6043_fshared)(__this, method);
}
inline void Field_1__ctor_m5E85360C971446C73E1A8E5ED7DA17D7EDC90E1B (Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18* __this, const RuntimeMethod* method)
{
	((  void (*) (Field_1_tC3CCA8F7619A0B639B6671BD922EC68E34595E18*, const RuntimeMethod*))Field_1__ctor_m6A0C971C6E2C7FC18B971B357D1CC034215D6043_fshared)(__this, method);
}
inline void Field_1__ctor_m987712BF4E8BBF11473DA83B4CF70877C002430C (Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD* __this, const RuntimeMethod* method)
{
	((  void (*) (Field_1_t13BBC583A7E521A9A0C5B9A2B8B537D8CEE550BD*, const RuntimeMethod*))Field_1__ctor_m6A0C971C6E2C7FC18B971B357D1CC034215D6043_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m8212BCFF76673CC904541B2D9AF39E5FF124B359 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09 (String_t* ___0_resourceFormat, RuntimeObject* ___1_p1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425 (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200 (uint16_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7 (int32_t ___0_h1, int32_t ___1_h2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3C7CFE908C6BB2DC94F94F7615F2D1AF0E2777D9 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m2444D8FDCF0568D259DAE989EB7BCC77D37B2D6D (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F (RuntimeObject* ___0_formatProvider, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt16_ToString_mBD648884B6569D3E7D779669EEFCB1ED5EE4A521 (uint16_t* __this, String_t* ___0_format, RuntimeObject* ___1_provider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mB42F3DAE52C3BC7579B302E623196C45A5DEAC6B_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
inline void Vector_1__ctor_m48CD7847B9597F3193C9C0BA97ED64E276F4340A (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_m43BBDDA05FDAB290038584331DB79CB33C523B83 (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetOneValue_m7E814AFD17E4D390C12EF731DA01203D262D9953_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mDA4A6115C4120BFDD773FD4D3753FD3EC2B10427 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, uint16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetAllBitsSetValue_m854DE079EA89F97089D3EF29D7C31F081F420580_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92 (uint64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3 (uint64_t* __this, String_t* ___0_format, RuntimeObject* ___1_provider, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
inline void Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* EqualityComparer_1_CreateComparer_m3BD7BED1F69ABEE55E320BA9CCFBB473E9F57C66 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* EqualityComparer_1_CreateComparer_m66568B441EE3AB73D292C4F4CE1707FBAC360F5A (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* EqualityComparer_1_CreateComparer_m8A944543377C40C1596E4EECED12E463FC3DDFC3 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* EqualityComparer_1_CreateComparer_m4055D46D61B6AD80A0F2D4624577D7FE9D15B002 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* EqualityComparer_1_CreateComparer_m64D3D774E7DAF5FC0206DC26D9BA53BF70F1F93B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* EqualityComparer_1_CreateComparer_m73A019C274DF1E66D30647A3F24ADC27784B7114 (const RuntimeMethod* method) ;
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared)(method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Variable_1_get_ValueUXML_m0FA7CBF4A1B8B1D2357C1B49D39A9FC90E210182 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m739B3983AE885A5EEA414BA55152C27D362B4F91 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, bool ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0 = ___0_value;
		Variable_1_set_Value_mEAD210FE11BB24BA65C5E0A48E07ACEC79AC434F(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m865960EF738D2E3229C9A4E7A0B688667BF8F51C (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mAD0AE99B72A55FD40340DB605678D32F099C1F78 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mEAD210FE11BB24BA65C5E0A48E07ACEC79AC434F (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, bool ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_0;
		L_0 = EqualityComparer_1_get_Default_mBB75BC0723DFD7850F43E72E34026DD070CF5932_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		bool L_1 = __this->___m_Value;
		bool L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, bool, bool >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		bool L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_mF27191B60F7096690DC3CFE32095007E44E14592(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m3AE5157E3D200DA615D5D93242CBAC1E13072E21 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0;
		L_0 = Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline(__this, NULL);
		bool L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mF27191B60F7096690DC3CFE32095007E44E14592 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m4557202E292DB9AAA54B916B6CFD7AF3FB4FD030 (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticInit);
	//<source_info:<no-source>:1>
	bool V_0 = false;
	{
		bool L_0;
		L_0 = Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline(__this, NULL);
		V_0 = L_0;
		CHECKED_LOCAL_INIT(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticInit,(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = Boolean_ToString_m6646C8026B1DF381A1EE8CD13549175E9703CC63((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t Variable_1_get_ValueUXML_mD3488975A8631A0F64FD0BC8E18FF34995917A6D (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t L_0;
		L_0 = Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m590E5D53CE2FFED48409A0A4731D529B94872AAF (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t L_0 = ___0_value;
		Variable_1_set_Value_mF84138168B087F3A4F8BB9B909B6E2734D0C0538(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m955570153CA71E62471CE91846DB82E1962DE46F (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m4BF1BD7F81B62C46DAFD9974A30875719F63E894 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mF84138168B087F3A4F8BB9B909B6E2734D0C0538 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0;
		L_0 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		uint8_t L_1 = __this->___m_Value;
		uint8_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		uint8_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m91A7E802951455D643936E83680488D59E776556(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_mB53AB223D37EA2FE4FAA74D0C189DA54701B2FC2 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t L_0;
		L_0 = Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline(__this, NULL);
		uint8_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m91A7E802951455D643936E83680488D59E776556 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_mFFB7D675859AE6AAB26AE7A3CBB484957BF5EF13 (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint8_t V_0 = 0x0;
	{
		uint8_t L_0;
		L_0 = Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Byte_ToString_mB80CE094B94215119578E4D796566E71D7277EE4((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Variable_1_get_ValueUXML_mDD51092F088E48FADC082383B093FB41AFD0F226 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		double L_0;
		L_0 = Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m95BA09D5A15BB0DB8A391822B3D0D5951A53A8B0 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, double ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		double L_0 = ___0_value;
		Variable_1_set_Value_m59A35AF7F79D01DA4C22AD6BE72E8E63850ACA5B(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_mD87A11B9841EAC03121FAD0719D244B5E3F13705 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mD545052D18E38889B9C71704B8A367EEE9D48011 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		double L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m59A35AF7F79D01DA4C22AD6BE72E8E63850ACA5B (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, double ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_0;
		L_0 = EqualityComparer_1_get_Default_m12CC270D19620F4E8E3ABFE7BF8C2B1955476A04_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		double L_1 = __this->___m_Value;
		double L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, double, double >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		double L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m349325562E935627F4A0E2D5A074E0EA38B682A5(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_mB074A6E2A32F2744DE6D1D8BB0D8530236C09AED (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		double L_0;
		L_0 = Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline(__this, NULL);
		double L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m349325562E935627F4A0E2D5A074E0EA38B682A5 (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m9A1A2686207A2ED33911DF3862121B064A6B59EB (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	double V_0 = 0.0;
	{
		double L_0;
		L_0 = Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int16_t Variable_1_get_ValueUXML_mA3BB8F7D94BC93D23BBFD18BAF30776A0F3C78B1 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int16_t L_0;
		L_0 = Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_mD961B7D7E7FB6BFD86024424AD127DF31F93A36B (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, int16_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int16_t L_0 = ___0_value;
		Variable_1_set_Value_m86DFAABAACEF946ADDCDFBCCBAA787D657947FE9(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m465648EA52CB1E57CD33466C37E7235E19742858 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mA26E2B242834ED03ABF0FFF818A896B4972A863C (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int16_t Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int16_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m86DFAABAACEF946ADDCDFBCCBAA787D657947FE9 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, int16_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		int16_t L_1 = __this->___m_Value;
		int16_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		int16_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m58111E04F07046609ED26B4DB3AECF5CECD5B641(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m6C546550EADB70029FAF38393CD3325D84E6E0B1 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int16_t L_0;
		L_0 = Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline(__this, NULL);
		int16_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m58111E04F07046609ED26B4DB3AECF5CECD5B641 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m3FD5D4F02AE81608C50A1D02B3BF26A81088F6C7 (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int16_t V_0 = 0;
	{
		int16_t L_0;
		L_0 = Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Int16_ToString_mD65153B762673B865D4F8FF9B567BECC1ABF6D23((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Variable_1_get_ValueUXML_mA394A8C549DD15924E95637D4980B12A5E5052BD (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_mD9FB0133A880CAA59D9F488FAA6DD1A007301FA3 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_value;
		Variable_1_set_Value_m6ECD9D07F682D6221F7E010AE085DC5D8D6FE7BD(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m791D81F424952BADCEBF99A1E8E7AA319C33E3F3 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m954706461F8A3D7DB9BC6143FDCFB3B833394981 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m6ECD9D07F682D6221F7E010AE085DC5D8D6FE7BD (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_0;
		L_0 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		int32_t L_1 = __this->___m_Value;
		int32_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		int32_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m1EF099E4C69D63D1E408E7F2435FE7AC8361D443(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m657E40245A0683A04B44A73BB2DD390F4892C189 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline(__this, NULL);
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m1EF099E4C69D63D1E408E7F2435FE7AC8361D443 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m21161400F2CB9839AC1B11C45D87B29B096FBCD2 (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t Variable_1_get_ValueUXML_m1D0C26683FEF20F6BE4BE5577C31299203724A95 (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0;
		L_0 = Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_mE73DE1883DC647CA05A2AF45B7206C695B70A91F (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, int64_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0 = ___0_value;
		Variable_1_set_Value_m3D7A6A7175666F2CD293B927C0877CE69FD1435C(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m74F7663B17BF19070295FA23AEC39D63F67BFAAD (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m71306C94B5A4B40A2F9BCB267ED24751E7F14B44 (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222 (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m3D7A6A7175666F2CD293B927C0877CE69FD1435C (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, int64_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_0;
		L_0 = EqualityComparer_1_get_Default_m76691DC579907239261E159E4DFDD8B1C3C9E5FE_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		int64_t L_1 = __this->___m_Value;
		int64_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, int64_t, int64_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		int64_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m79EA014A19F44C40E29FB554025AA37D74A1C12A(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m8ED1F57A87C83E4A075B5C019502E35E052D25DA (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0;
		L_0 = Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline(__this, NULL);
		int64_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m79EA014A19F44C40E29FB554025AA37D74A1C12A (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_mED4BCF9A46EB6ADE7AB9C670EBB28912EEAFF4D0 (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	{
		int64_t L_0;
		L_0 = Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Int64_ToString_m284E4E55662818E38654309A41C2B07CD436F36B((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int8_t Variable_1_get_ValueUXML_mBB745B2296604D89B55C8C2FC55A824D0F3379B6 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int8_t L_0;
		L_0 = Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_mD1DEC5CB1DBD4A92CEA5BA5CF96DDDCFA256CF00 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, int8_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int8_t L_0 = ___0_value;
		Variable_1_set_Value_m60AE096CCE83CBD8DB5EDE23A8CD9C6DA81AC3ED(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m3A4C31D5CA64026A2B62C6AD89496D6CAAB07C71 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mC67CB30564188256B8F85FCA89CE1C573EFF4F30 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int8_t Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int8_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m60AE096CCE83CBD8DB5EDE23A8CD9C6DA81AC3ED (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, int8_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		int8_t L_1 = __this->___m_Value;
		int8_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		int8_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m8DB2C9A817C4D6F18CAE8B25D3C317A20E283948(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_mEE11FDDDACDC843ACD68C582562F024833A9E540 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int8_t L_0;
		L_0 = Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline(__this, NULL);
		int8_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m8DB2C9A817C4D6F18CAE8B25D3C317A20E283948 (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m90D09C06734B73FAEAA863D74E23FC8EF18F26ED (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int8_t V_0 = 0x0;
	{
		int8_t L_0;
		L_0 = Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = SByte_ToString_mAA885F58F9F739E25623423A059C735017A92708((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Variable_1_get_ValueUXML_m9FAFE3C69C7B839A87DA6E897F757C7EB0F7D0C2 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0;
		L_0 = Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m5666452BCBA130499C91FD7D505D51ACA8C8E03B (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, float ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0 = ___0_value;
		Variable_1_set_Value_mE48B2FBE844526B085300D488FCED926B1DE510F(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m56140890EC1C46C723F6CDD491BC7BC113BF7F84 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m2802531716E27FC37D2EC4CBA97FF2598D284C45 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mE48B2FBE844526B085300D488FCED926B1DE510F (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, float ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_0;
		L_0 = EqualityComparer_1_get_Default_m20A1B9861324559044977270E1FAFB09BBE14234_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		float L_1 = __this->___m_Value;
		float L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, float, float >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		float L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m6BD5AD55C128B6F073D226292AD298CA1184F64A(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_mF058B451C00F71048841DB3C1DB7B0A16281B534 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0;
		L_0 = Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline(__this, NULL);
		float L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m6BD5AD55C128B6F073D226292AD298CA1184F64A (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_mF5D5F1F71E3E67728A5153EED964FB8F1CFF8769 (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	float V_0 = 0.0f;
	{
		float L_0;
		L_0 = Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Variable_1_get_ValueUXML_m52E630D7CFA335089333BEEEABF173FA12C25F20 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint16_t L_0;
		L_0 = Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m3152D71633143E85E4B7888C5576E70DE5934FD1 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, uint16_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint16_t L_0 = ___0_value;
		Variable_1_set_Value_m5AF2E2CA2E14ED72ACC65F9A7EC9667A837F3C8B(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m1604F5A0615263A11F35A8537D320344FB00B4FE (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mC31652A5F5998393385BCBBC30A29F73609FDC32 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint16_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m5AF2E2CA2E14ED72ACC65F9A7EC9667A837F3C8B (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, uint16_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0;
		L_0 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		uint16_t L_1 = __this->___m_Value;
		uint16_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		uint16_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_mE2E037FF501B8E836DC2A7E2C082BB1222A6CFA0(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m1842E9E917B87ABBB7C660D61F8BE3C9914ADF6E (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint16_t L_0;
		L_0 = Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline(__this, NULL);
		uint16_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mE2E037FF501B8E836DC2A7E2C082BB1222A6CFA0 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m3489240280A189867AFA86D7D61A1114DA150763 (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint16_t V_0 = 0;
	{
		uint16_t L_0;
		L_0 = Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = UInt16_ToString_m57629B7E74D92A54414073D5C27D6827C93A4DD5((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t Variable_1_get_ValueUXML_mAF76BBFC3C302309C7812E3B3489CF088FEA8BBB (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0;
		L_0 = Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m7844362F09B244BDF937BBBFE789F659B334C66F (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = ___0_value;
		Variable_1_set_Value_m171AA2559B7763FB08BA8D99AB9FA15993F92E2D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m0E2F937EB1EE81C5334C8DA90478F6747BF5853A (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_mC45CB6652CFBBA5F64EB8CD7DF9CF87FC90C426E (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_m171AA2559B7763FB08BA8D99AB9FA15993F92E2D (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_0;
		L_0 = EqualityComparer_1_get_Default_mF554877B669658FD6449F84AE369214855D0BC40_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		uint32_t L_1 = __this->___m_Value;
		uint32_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, uint32_t, uint32_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		uint32_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_m0980A239523AA674EDBFE4BC9E76687DBE5BE9B8(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m93A9C1A7A8D7AC0871497CFD7D07D5E3BA2968D3 (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0;
		L_0 = Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline(__this, NULL);
		uint32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m0980A239523AA674EDBFE4BC9E76687DBE5BE9B8 (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_mB37DE8BBF8E10D33F7D7C0E432501B1591C9848F (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint32_t V_0 = 0;
	{
		uint32_t L_0;
		L_0 = Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = UInt32_ToString_mB6FA6D2459C82ADCF285C55363491D9669A80154((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Variable_1_get_ValueUXML_m7F12C6BD63F5ACE78800C02F7600E811E38B1728 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint64_t L_0;
		L_0 = Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m812C98756B28B51B0C9B16C1C96CC888F6AD7B3C (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint64_t L_0 = ___0_value;
		Variable_1_set_Value_mA7FD3EF090B4E011BDAC4DB770CEC9D343450C08(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_mCC8379077153BA6DB4568CB9B4526E16AC21A88E (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m1C2B1395FF7BD1EDA649D3EF7C748073F57A6C55 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint64_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mA7FD3EF090B4E011BDAC4DB770CEC9D343450C08 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_0;
		L_0 = EqualityComparer_1_get_Default_m65C88AD76FA11C898FE9437B5D46E13B12F10B77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		uint64_t L_1 = __this->___m_Value;
		uint64_t L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, uint64_t, uint64_t >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		uint64_t L_4 = ___0_value;
		__this->___m_Value = L_4;
		Variable_1_SendValueChangedEvent_mABC4B61F172A2CC6E10FB1F617C1758EBEF7E8A6(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m451FF0659534A041A2A8EBB4E818FD46A47317BB (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint64_t L_0;
		L_0 = Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline(__this, NULL);
		uint64_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), &L_1);
		return L_2;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_mABC4B61F172A2CC6E10FB1F617C1758EBEF7E8A6 (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, __this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_mAAC234CF9BD43BC3D916D2D46E2B5FD15CA8D4BB (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint64_t V_0 = 0;
	{
		uint64_t L_0;
		L_0 = Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline(__this, NULL);
		V_0 = L_0;
		String_t* L_1;
		L_1 = UInt64_ToString_mD3AAE57EA18A6779F5A17E4F91C900A231EB0A6F((&V_0), NULL);
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Variable_1_get_ValueUXML_mB00522CC66B6A73D987F982116FDD49A34C2804D_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0;
		L_0 = Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m2AE857045AF8FFE28DCF39269458B2A821CE655D_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = ___0_value;
		Variable_1_set_Value_mAAC33DA3B7E3E3486928146EC132AAD281558C17(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m86AD5DA2B833929D386D4EC9B37E854B02E8A379_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m30A0B342FB9C8A7CACADF386140C3C335CFB6795_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A** L_5 = (Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)(&__this->___ValueChanged);
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8;
		L_8 = il2cpp_intrinsic_interlocked_compare_exchange(L_5, L_6, L_7);
		V_0 = L_8;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_10 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mAAC33DA3B7E3E3486928146EC132AAD281558C17_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_0;
		L_0 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		Il2CppSharedGenericObject* L_1 = __this->___m_Value;
		Il2CppSharedGenericObject* L_2 = ___0_value;
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_0, L_1, L_2);
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		Il2CppSharedGenericObject* L_4 = ___0_value;
		__this->___m_Value = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Value), (void*)L_4);
		Variable_1_SendValueChangedEvent_m6521249C37B924F58684E926A431A201B6E48C9A(__this, NULL);
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m583A67D7A404CFFC962B25D5F8C5DBAB1A9E44A6_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0;
		L_0 = Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_inline(__this, NULL);
		return (RuntimeObject*)L_0;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m6521249C37B924F58684E926A431A201B6E48C9A_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = __this->___ValueChanged;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, (RuntimeObject*)__this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m2D53340BDF707FAAEB047E62F71984586FC445DA_gshared (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		Il2CppSharedGenericObject* L_0;
		L_0 = Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_inline(__this, NULL);
		V_0 = L_0;
		NullCheck((RuntimeObject*)(V_0));
		String_t* L_1;
		L_1 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)(V_0));
		return L_1;
	}
}
// Method Definition Index: 78968
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 78959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_get_ValueUXML_m6B378A609CF60397A316BC6F84EE74D3CDCBDAB9_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0), __this, (Il2CppFullySharedGenericAny*)L_0);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		return;
	}
}
// Method Definition Index: 78960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_ValueUXML_m51A8094ED5B29EC7C346C6F7F9DFE57E7DD0565C_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Il2CppFullySharedGenericAny ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? ___0_value : &___0_value), SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? L_0: *(void**)L_0));
		return;
	}
}
// Method Definition Index: 78961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_add_ValueChanged_m94EC4A8CBE3278F1239A491090E7515872FA61B4_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = *(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_5 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7;
		L_7 = il2cpp_intrinsic_interlocked_compare_exchange((((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4)))), L_5, L_6);
		V_0 = L_7;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_8) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_remove_ValueChanged_m8B83D277FB4B88271AB7AA7BBF025C3F02C65E3D_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_1 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* V_2 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = *(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		V_0 = L_0;
	}

IL_0007:
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = V_0;
		V_1 = L_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_2 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)Castclass((RuntimeObject*)L_4, Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A_il2cpp_TypeInfo_var));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_5 = V_2;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_6 = V_1;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_7;
		L_7 = il2cpp_intrinsic_interlocked_compare_exchange((((Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4)))), L_5, L_6);
		V_0 = L_7;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_8 = V_0;
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_9 = V_1;
		if ((!(((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_8) == ((RuntimeObject*)(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A*)L_9))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// Method Definition Index: 78963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_get_Value_mF69B6EB8006143BFCD7289A42697F91433DD309A_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5)), SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		return;
	}
}
// Method Definition Index: 78964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_set_Value_mFC69A717AF6E7EF515A24997EAFC63AB6EE2BA1A_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, Il2CppFullySharedGenericAny ___0_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	const Il2CppFullySharedGenericAny L_4 = L_1;
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	{
		EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* L_0;
		L_0 = ((  EqualityComparer_1_t974B6EF56BCA01CA6AD3434C04A3F054C43783CC* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		il2cpp_codegen_memcpy(L_1, il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5)), SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		il2cpp_codegen_memcpy(L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? ___0_value : &___0_value), SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(8, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? L_1: *(void**)L_1), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? L_2: *(void**)L_2));
		if (!L_3)
		{
			goto IL_0014;
		}
	}
	{
		return;
	}

IL_0014:
	{
		il2cpp_codegen_memcpy(L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)) ? ___0_value : &___0_value), SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5), L_4, SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		((  void (*) (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7));
		return;
	}
}
// Method Definition Index: 78965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Variable_1_GetSourceValue_m1A30F9324597B6BD23688BD7CCB7488B781B88AA_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, RuntimeObject* ___0__, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0), __this, (Il2CppFullySharedGenericAny*)L_0);
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), L_0);
		return L_1;
	}
}
// Method Definition Index: 78966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1_SendValueChangedEvent_m50AB009AC9142CD5E4503821EBDCB38670428EFB_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B2_0 = NULL;
	Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* G_B1_0 = NULL;
	{
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_0 = *(Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		Action_1_t9E9C20173C908A2F03243A56F3CAB1EC014C628A* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000b;
		}
		G_B1_0 = L_1;
	}
	{
		return;
	}

IL_000b:
	{
		NullCheck(G_B2_0);
		Action_1_Invoke_mB0145BB0F13F81481C5369914E62600E70446C2C_inline(G_B2_0, (RuntimeObject*)__this, NULL);
		return;
	}
}
// Method Definition Index: 78967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Variable_1_ToString_m917AD7CFDF5FD0181AFDAD28A20F33845D38666F_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
	void* L_1 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1)));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	//<source_info:<no-source>:1>
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	memset(V_0, 0, SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0), __this, (Il2CppFullySharedGenericAny*)L_0);
		il2cpp_codegen_memcpy(V_0, L_0, SizeOf_T_tBBAB204E2CA9CC10B9F9E50EAC86445A7F29021C);
		Il2CppConstrainedCallData L_2;
		Il2CppMethodPointer L_3 = il2cpp_codegen_get_runtime_constrained_call_data(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8), (void*)(Il2CppFullySharedGenericAny*)V_0, &L_2, L_1);
		typedef String_t* ( *func_L_4)(void*,const RuntimeMethod*);
		String_t* L_5 = ((func_L_4)L_3)(L_2.thisPtr,L_2.method);
		return L_5;
	}
}
// Method Definition Index: 78968
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Variable_1__ctor_mB16949764E1E05CD6D2B6D1180CEE08BD24C3740_fshared (Variable_1_tC8C3DFE6422CC62833CEBBB9A05A59098CB02A02* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
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
// Method Definition Index: 31114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VectorField_1__ctor_m8F08DF879EDA1A7B020FEA890F1CBC10AB6232D7 (VectorField_1_tA0DD3460E58AEABD9D5B33110FC64F4490179B87* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__this->___incStep = (0.0250000004f);
		__this->___incStepMult = (10.0f);
		__this->___decimals = 3;
		Field_1__ctor_m7C303BA68691F2521E9EC689B23AE797B4DFBB05(__this, NULL);
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
// Method Definition Index: 31114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VectorField_1__ctor_m68A8E7C0642A1F49BB638A5059411FDDFB21E070 (VectorField_1_t922D9F74763B4AFD1C1760DE2236972042F8310D* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__this->___incStep = (0.0250000004f);
		__this->___incStepMult = (10.0f);
		__this->___decimals = 3;
		Field_1__ctor_m5E85360C971446C73E1A8E5ED7DA17D7EDC90E1B(__this, NULL);
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
// Method Definition Index: 31114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VectorField_1__ctor_mA147DDFF53B038A9BAC6EAEEBE45ED829C91DB95 (VectorField_1_t7640EEE30580F0D8ABCA05DBBAB2F6B83A4713C3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__this->___incStep = (0.0250000004f);
		__this->___incStepMult = (10.0f);
		__this->___decimals = 3;
		Field_1__ctor_m987712BF4E8BBF11473DA83B4CF70877C002430C(__this, NULL);
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
// Method Definition Index: 31114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VectorField_1__ctor_m8C9A6BE32F096BDD676D758F25D7747CBABBA6BE_fshared (VectorField_1_tA0B76D2246CE6687E43856049B2DB46975532D1F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		__this->___incStep = (0.0250000004f);
		__this->___incStepMult = (10.0f);
		__this->___decimals = 3;
		((  void (*) (Field_1_tEBDBEF6C7E8EC7F1DBE1ABC4B1EA917269E20258*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Field_1_tEBDBEF6C7E8EC7F1DBE1ABC4B1EA917269E20258*)__this, NULL);
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
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 9579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
// Method Definition Index: 9580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_1_get_Zero_mDB2680DF070B1C7F273400548848C621F96343A4 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero;
		return L_0;
	}
}
// Method Definition Index: 9581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_m43BBDDA05FDAB290038584331DB79CB33C523B83 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VectorSizeHelper_tC26CEAD1B0D88F765A24D653A74900C4C7FEBD18 V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B5_0 = 0;
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* L_0 = (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489*)(&(&V_0)->____placeholder);
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&L_0->___register);
		uint8_t* L_2 = (uint8_t*)(&L_1->___byte_0);
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_2,NULL));
		V_1 = (uint8_t*)L_3;
		uint8_t* L_4 = (uint8_t*)(&(&V_0)->____byte);
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		uint8_t* L_6 = V_1;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,uint8_t*,intptr_t,false,false>(((uint8_t*)((intptr_t)((uint8_t*)il2cpp_codegen_subtract((intptr_t)L_5, (intptr_t)L_6))/1)),NULL));
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_7,NULL));
		V_2 = (-1);
		G_B2_0 = L_8;
		goto IL_0045;
	}

IL_0045:
	{
		G_B4_0 = G_B2_0;
		goto IL_0067;
	}

IL_0067:
	{
		G_B5_0 = G_B4_0;
	}
	{
		V_2 = 2;
		G_B21_0 = G_B5_0;
		goto IL_0176;
	}

IL_0176:
	{
		int32_t L_9 = V_2;
		return ((int32_t)(G_B21_0/L_9));
	}
}
// Method Definition Index: 9582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mDA4A6115C4120BFDD773FD4D3753FD3EC2B10427 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, uint16_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int8_t* V_3 = NULL;
	int8_t* V_4 = NULL;
	int32_t V_5 = 0;
	uint16_t* V_6 = NULL;
	uint16_t* V_7 = NULL;
	int32_t V_8 = 0;
	int16_t* V_9 = NULL;
	int16_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint32_t* V_12 = NULL;
	uint32_t* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t* V_15 = NULL;
	int32_t* V_16 = NULL;
	int32_t V_17 = 0;
	uint64_t* V_18 = NULL;
	uint64_t* V_19 = NULL;
	int32_t V_20 = 0;
	int64_t* V_21 = NULL;
	int64_t* V_22 = NULL;
	int32_t V_23 = 0;
	float* V_24 = NULL;
	float* V_25 = NULL;
	int32_t V_26 = 0;
	double* V_27 = NULL;
	double* V_28 = NULL;
	int32_t V_29 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489));
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0386;
		}
	}
	{
		goto IL_005e;
	}

IL_005e:
	{
		goto IL_00b3;
	}

IL_00b3:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_2 = (uint16_t*)(&L_1->___uint16_0);
		V_7 = L_2;
		uint16_t* L_3 = V_7;
		uintptr_t L_4 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_3,NULL));
		V_6 = (uint16_t*)L_4;
		V_8 = 0;
		goto IL_00ff;
	}

IL_00e5:
	{
		uint16_t* L_5 = V_6;
		int32_t L_6 = V_8;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		uint16_t L_8 = ___0_value;
		*(((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 2)))))) = ((int16_t)L_8);
		int32_t L_9 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_00ff:
	{
		int32_t L_10 = V_8;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_00e5;
		}
	}
	{
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_7 = (uint16_t*)L_12;
		return;
	}

IL_0386:
	{
		goto IL_0505;
	}

IL_0505:
	{
		goto IL_0684;
	}

IL_0684:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_13 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_14 = ___0_value;
		L_13->___uint16_0 = L_14;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_16 = ___0_value;
		L_15->___uint16_1 = L_16;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_17 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_18 = ___0_value;
		L_17->___uint16_2 = L_18;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_19 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_20 = ___0_value;
		L_19->___uint16_3 = L_20;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_21 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_22 = ___0_value;
		L_21->___uint16_4 = L_22;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_23 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_24 = ___0_value;
		L_23->___uint16_5 = L_24;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_25 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_26 = ___0_value;
		L_25->___uint16_6 = L_26;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_27 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_28 = ___0_value;
		L_27->___uint16_7 = L_28;
		return;
	}
}
// Method Definition Index: 9583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_dataPointer;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1__ctor_m8212BCFF76673CC904541B2D9AF39E5FF124B359(__this, L_0, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4));
		return;
	}
}
// Method Definition Index: 9584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m8212BCFF76673CC904541B2D9AF39E5FF124B359 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int8_t* V_4 = NULL;
	int8_t* V_5 = NULL;
	int8_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint16_t* V_8 = NULL;
	uint16_t* V_9 = NULL;
	uint16_t* V_10 = NULL;
	int32_t V_11 = 0;
	int16_t* V_12 = NULL;
	int16_t* V_13 = NULL;
	int16_t* V_14 = NULL;
	int32_t V_15 = 0;
	uint32_t* V_16 = NULL;
	uint32_t* V_17 = NULL;
	uint32_t* V_18 = NULL;
	int32_t V_19 = 0;
	int32_t* V_20 = NULL;
	int32_t* V_21 = NULL;
	int32_t* V_22 = NULL;
	int32_t V_23 = 0;
	uint64_t* V_24 = NULL;
	uint64_t* V_25 = NULL;
	uint64_t* V_26 = NULL;
	int32_t V_27 = 0;
	int64_t* V_28 = NULL;
	int64_t* V_29 = NULL;
	int64_t* V_30 = NULL;
	int32_t V_31 = 0;
	float* V_32 = NULL;
	float* V_33 = NULL;
	float* V_34 = NULL;
	int32_t V_35 = 0;
	double* V_36 = NULL;
	double* V_37 = NULL;
	double* V_38 = NULL;
	int32_t V_39 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489));
		goto IL_0053;
	}

IL_0053:
	{
		goto IL_00ae;
	}

IL_00ae:
	{
	}
	{
		void* L_0 = ___0_dataPointer;
		V_8 = (uint16_t*)L_0;
		uint16_t* L_1 = V_8;
		int32_t L_2 = ___1_offset;
		intptr_t L_3 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_2,NULL));
		V_8 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(L_3, 2))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_4 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_5 = (uint16_t*)(&L_4->___uint16_0);
		V_10 = L_5;
		uint16_t* L_6 = V_10;
		uintptr_t L_7 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_6,NULL));
		V_9 = (uint16_t*)L_7;
		V_11 = 0;
		goto IL_0104;
	}

IL_00ec:
	{
		uint16_t* L_8 = V_9;
		int32_t L_9 = V_11;
		intptr_t L_10 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_9,NULL));
		uint16_t* L_11 = V_8;
		int32_t L_12 = V_11;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int32_t L_14 = ((int32_t)*(((uint16_t*)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 2))))));
		*(((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(L_10, 2)))))) = ((int16_t)L_14);
		int32_t L_15 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0104:
	{
		int32_t L_16 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_17;
		L_17 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_00ec;
		}
	}
	{
		uintptr_t L_18 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_10 = (uint16_t*)L_18;
		return;
	}
}
// Method Definition Index: 9585
// Method Definition Index: 9586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int8_t* V_1 = NULL;
	uint16_t* V_2 = NULL;
	int16_t* V_3 = NULL;
	uint32_t* V_4 = NULL;
	int32_t* V_5 = NULL;
	uint64_t* V_6 = NULL;
	int64_t* V_7 = NULL;
	float* V_8 = NULL;
	double* V_9 = NULL;
	{
		int32_t L_0 = ___0_index;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_2 = ___0_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}

IL_000c:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F)), L_5, NULL);
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_7 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0022:
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_0090;
	}

IL_0090:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_8 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_9 = (uint16_t*)(&L_8->___uint16_0);
		V_2 = L_9;
		uint16_t* L_10 = V_2;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_10,NULL));
		int32_t L_12 = ___0_index;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int32_t L_14 = ((int32_t)*(((uint16_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 2)))))));
		return (uint16_t)L_14;
	}
}
// Method Definition Index: 9587
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8(__this, ((*(Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29_inline(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 9588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_other, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		V_0 = 0;
		goto IL_0027;
	}

IL_000b:
	{
		int32_t L_1 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint16_t L_2;
		L_2 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27(__this, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_3 = V_0;
		uint16_t L_4;
		L_4 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27((&___0_other), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_5;
		L_5 = Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline(L_2, L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		return (bool)0;
	}

IL_0023:
	{
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0027:
	{
		int32_t L_7 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_0031:
	{
		goto IL_01f0;
	}

IL_01f0:
	{
		goto IL_03af;
	}

IL_03af:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_9 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_10 = L_9->___uint16_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_11 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_12 = L_11.___register;
		uint16_t L_13 = L_12.___uint16_0;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_13))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_14 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_15 = L_14->___uint16_1;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_16 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_17 = L_16.___register;
		uint16_t L_18 = L_17.___uint16_1;
		if ((!(((uint32_t)L_15) == ((uint32_t)L_18))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_19 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_20 = L_19->___uint16_2;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_21 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_22 = L_21.___register;
		uint16_t L_23 = L_22.___uint16_2;
		if ((!(((uint32_t)L_20) == ((uint32_t)L_23))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_24 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_25 = L_24->___uint16_3;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_26 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_27 = L_26.___register;
		uint16_t L_28 = L_27.___uint16_3;
		if ((!(((uint32_t)L_25) == ((uint32_t)L_28))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_29 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_30 = L_29->___uint16_4;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_31 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_32 = L_31.___register;
		uint16_t L_33 = L_32.___uint16_4;
		if ((!(((uint32_t)L_30) == ((uint32_t)L_33))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_34 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_35 = L_34->___uint16_5;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_36 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_37 = L_36.___register;
		uint16_t L_38 = L_37.___uint16_5;
		if ((!(((uint32_t)L_35) == ((uint32_t)L_38))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_39 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_40 = L_39->___uint16_6;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_41 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_42 = L_41.___register;
		uint16_t L_43 = L_42.___uint16_6;
		if ((!(((uint32_t)L_40) == ((uint32_t)L_43))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_44 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_45 = L_44->___uint16_7;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_46 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_47 = L_46.___register;
		uint16_t L_48 = L_47.___uint16_7;
		return (bool)((((int32_t)L_45) == ((int32_t)L_48))? 1 : 0);
	}

IL_0494:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8_AdjustorThunk (RuntimeObject* __this, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_other, const RuntimeMethod* method)
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// Method Definition Index: 9589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3C7CFE908C6BB2DC94F94F7615F2D1AF0E2777D9 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	CHECKED_LOCAL(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	int8_t V_4 = 0x0;
	int32_t V_5 = 0;
	uint16_t V_6 = 0;
	int32_t V_7 = 0;
	int16_t V_8 = 0;
	int32_t V_9 = 0;
	uint32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int64_t V_16 = 0;
	int32_t V_17 = 0;
	float V_18 = 0.0f;
	int32_t V_19 = 0;
	double V_20 = 0.0;
	{
		V_0 = 0;
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_034a;
		}
	}
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_00a7;
	}

IL_00a7:
	{
	}
	{
		V_5 = 0;
		goto IL_00ef;
	}

IL_00c7:
	{
		int32_t L_1 = V_0;
		int32_t L_2 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint16_t L_3;
		L_3 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27(__this, L_2, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		V_6 = L_3;
		int32_t L_4;
		L_4 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200((&V_6), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_5;
		L_5 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_1, L_4, NULL);
		V_0 = L_5;
		int32_t L_6 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_00ef:
	{
		int32_t L_7 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_00c7;
		}
	}
	{
		int32_t L_9 = V_0;
		return L_9;
	}

IL_034a:
	{
		goto IL_04da;
	}

IL_04da:
	{
		goto IL_066a;
	}

IL_066a:
	{
	}
	{
		int32_t L_10 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_11 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_12 = (uint16_t*)(&L_11->___uint16_0);
		int32_t L_13;
		L_13 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_12, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_14;
		L_14 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_10, L_13, NULL);
		V_0 = L_14;
		int32_t L_15 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_16 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_17 = (uint16_t*)(&L_16->___uint16_1);
		int32_t L_18;
		L_18 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_17, NULL);
		int32_t L_19;
		L_19 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_15, L_18, NULL);
		V_0 = L_19;
		int32_t L_20 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_21 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_22 = (uint16_t*)(&L_21->___uint16_2);
		int32_t L_23;
		L_23 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_22, NULL);
		int32_t L_24;
		L_24 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_20, L_23, NULL);
		V_0 = L_24;
		int32_t L_25 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_26 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_27 = (uint16_t*)(&L_26->___uint16_3);
		int32_t L_28;
		L_28 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_27, NULL);
		int32_t L_29;
		L_29 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_25, L_28, NULL);
		V_0 = L_29;
		int32_t L_30 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_31 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_32 = (uint16_t*)(&L_31->___uint16_4);
		int32_t L_33;
		L_33 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_32, NULL);
		int32_t L_34;
		L_34 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_30, L_33, NULL);
		V_0 = L_34;
		int32_t L_35 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_36 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_37 = (uint16_t*)(&L_36->___uint16_5);
		int32_t L_38;
		L_38 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_37, NULL);
		int32_t L_39;
		L_39 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_35, L_38, NULL);
		V_0 = L_39;
		int32_t L_40 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_41 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_42 = (uint16_t*)(&L_41->___uint16_6);
		int32_t L_43;
		L_43 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_42, NULL);
		int32_t L_44;
		L_44 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_40, L_43, NULL);
		V_0 = L_44;
		int32_t L_45 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_46 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_47 = (uint16_t*)(&L_46->___uint16_7);
		int32_t L_48;
		L_48 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_47, NULL);
		int32_t L_49;
		L_49 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_45, L_48, NULL);
		V_0 = L_49;
		int32_t L_50 = V_0;
		return L_50;
	}
}
IL2CPP_EXTERN_C  int32_t Vector_1_GetHashCode_m3C7CFE908C6BB2DC94F94F7615F2D1AF0E2777D9_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489>(__this);
	int32_t _returnValue;
	_returnValue = Vector_1_GetHashCode_m3C7CFE908C6BB2DC94F94F7615F2D1AF0E2777D9(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 9590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m2444D8FDCF0568D259DAE989EB7BCC77D37B2D6D (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit);
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit,(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_0;
		L_0 = CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5(NULL);
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7(__this, _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869, L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return L_1;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m2444D8FDCF0568D259DAE989EB7BCC77D37B2D6D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m2444D8FDCF0568D259DAE989EB7BCC77D37B2D6D(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 9591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		RuntimeObject* L_1 = ___1_formatProvider;
		NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* L_2;
		L_2 = NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F(L_1, NULL);
		NullCheck(L_2);
		String_t* L_3;
		L_3 = NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline(L_2, NULL);
		V_1 = L_3;
		StringBuilder_t* L_4 = V_0;
		NullCheck(L_4);
		StringBuilder_t* L_5;
		L_5 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_4, ((int32_t)60), NULL);
		V_2 = 0;
		goto IL_0053;
	}

IL_001f:
	{
		StringBuilder_t* L_6 = V_0;
		int32_t L_7 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint16_t L_8;
		L_8 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27(__this, L_7, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint16_t L_9 = L_8;
		RuntimeObject* L_10 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_9);
		String_t* L_11 = ___0_format;
		RuntimeObject* L_12 = ___1_formatProvider;
		String_t* L_13;
		L_13 = UInt16_ToString_mBD648884B6569D3E7D779669EEFCB1ED5EE4A521((uint16_t*)UnBox(L_10), L_11, L_12, NULL);
		NullCheck(L_6);
		StringBuilder_t* L_14;
		L_14 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_6, L_13, NULL);
		StringBuilder_t* L_15 = V_0;
		String_t* L_16 = V_1;
		NullCheck(L_15);
		StringBuilder_t* L_17;
		L_17 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_16, NULL);
		StringBuilder_t* L_18 = V_0;
		NullCheck(L_18);
		StringBuilder_t* L_19;
		L_19 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_18, ((int32_t)32), NULL);
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0053:
	{
		int32_t L_21 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_22;
		L_22 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_21) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_22, 1)))))
		{
			goto IL_001f;
		}
	}
	{
		StringBuilder_t* L_23 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_24;
		L_24 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uint16_t L_25;
		L_25 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27(__this, ((int32_t)il2cpp_codegen_subtract(L_24, 1)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint16_t L_26 = L_25;
		RuntimeObject* L_27 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_26);
		String_t* L_28 = ___0_format;
		RuntimeObject* L_29 = ___1_formatProvider;
		String_t* L_30;
		L_30 = UInt16_ToString_mBD648884B6569D3E7D779669EEFCB1ED5EE4A521((uint16_t*)UnBox(L_27), L_28, L_29, NULL);
		NullCheck(L_23);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_23, L_30, NULL);
		StringBuilder_t* L_32 = V_0;
		NullCheck(L_32);
		StringBuilder_t* L_33;
		L_33 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_32, ((int32_t)62), NULL);
		StringBuilder_t* L_34 = V_0;
		NullCheck(L_34);
		String_t* L_35;
		L_35 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_34);
		return L_35;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7_AdjustorThunk (RuntimeObject* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_mA9FEB41834880EF7C7688EB8C3F83286697B0BC7(_thisAdjusted, ___0_format, ___1_formatProvider, method);
	return _returnValue;
}
// Method Definition Index: 9592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mB42F3DAE52C3BC7579B302E623196C45A5DEAC6B (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
// Method Definition Index: 9593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Inequality_m32F4DFF513244591C00E23353EB6F6294E8BE9F0 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ___0_left;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_op_Equality_mB42F3DAE52C3BC7579B302E623196C45A5DEAC6B_inline(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 9594
// Method Definition Index: 9595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_1_Equals_m6F913845CB1E8A1A753B3C187A8EB840C36F5ADF (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	uint16_t* V_4 = NULL;
	int32_t V_5 = 0;
	int16_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint32_t* V_8 = NULL;
	int32_t V_9 = 0;
	int32_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint64_t* V_12 = NULL;
	int32_t V_13 = 0;
	int64_t* V_14 = NULL;
	int32_t V_15 = 0;
	float* V_16 = NULL;
	int32_t V_17 = 0;
	double* V_18 = NULL;
	int32_t V_19 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A V_20;
	memset((&V_20), 0, sizeof(V_20));
	uint16_t* G_B21_0 = NULL;
	uint16_t* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	uint16_t* G_B22_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B185_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B184_0 = NULL;
	int32_t G_B186_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B186_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B188_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B187_0 = NULL;
	int32_t G_B189_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B189_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B191_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B190_0 = NULL;
	int32_t G_B192_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B192_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B194_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B193_0 = NULL;
	int32_t G_B195_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B195_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B197_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B196_0 = NULL;
	int32_t G_B198_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B198_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B200_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B199_0 = NULL;
	int32_t G_B201_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B201_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B203_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B202_0 = NULL;
	int32_t G_B204_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B204_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B206_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B205_0 = NULL;
	int32_t G_B207_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B207_1 = NULL;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0447;
		}
	}
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_00c6;
	}

IL_00c6:
	{
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_1,NULL));
		if ((uintptr_t)L_2 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_3 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_2, 2));
		int8_t* L_4;
		if (L_3 == 0)
		{
			L_4 = NULL;
		}
		else
		{
			L_4 = (int8_t*)alloca(L_3);
			memset(L_4, 0, L_3);
		}
		V_4 = (uint16_t*)L_4;
		V_5 = 0;
		goto IL_0122;
	}

IL_00f2:
	{
		uint16_t* L_5 = V_4;
		int32_t L_6 = V_5;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint16_t L_9;
		L_9 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27((&___0_left), L_8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_10 = V_5;
		uint16_t L_11;
		L_11 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27((&___1_right), L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_12;
		L_12 = Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline(L_9, L_11, NULL);
		if (L_12)
		{
			G_B21_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 2))));
			goto IL_0116;
		}
		G_B20_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 2))));
	}
	{
		G_B22_0 = 0;
		G_B22_1 = G_B20_0;
		goto IL_011b;
	}

IL_0116:
	{
		uint16_t L_13;
		L_13 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B22_0 = ((int32_t)(L_13));
		G_B22_1 = G_B21_0;
	}

IL_011b:
	{
		*(((int16_t*)G_B22_1)) = ((int16_t)G_B22_0);
		int32_t L_14 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0122:
	{
		int32_t L_15 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_16;
		L_16 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_00f2;
		}
	}
	{
		uint16_t* L_17 = V_4;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_18;
		memset((&L_18), 0, sizeof(L_18));
		Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3((&L_18), (void*)L_17, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_18;
	}

IL_0447:
	{
		il2cpp_codegen_initobj((&V_20), sizeof(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A));
		goto IL_06e5;
	}

IL_06e5:
	{
		goto IL_097b;
	}

IL_097b:
	{
	}
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_19 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_20 = L_19.___register;
		uint16_t L_21 = L_20.___uint16_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_22 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_23 = L_22.___register;
		uint16_t L_24 = L_23.___uint16_0;
		if ((((int32_t)L_21) == ((int32_t)L_24)))
		{
			G_B185_0 = (&V_20);
			goto IL_09b6;
		}
		G_B184_0 = (&V_20);
	}
	{
		G_B186_0 = 0;
		G_B186_1 = G_B184_0;
		goto IL_09bb;
	}

IL_09b6:
	{
		uint16_t L_25;
		L_25 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B186_0 = ((int32_t)(L_25));
		G_B186_1 = G_B185_0;
	}

IL_09bb:
	{
		G_B186_1->___uint16_0 = (uint16_t)G_B186_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_26 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_27 = L_26.___register;
		uint16_t L_28 = L_27.___uint16_1;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_29 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_30 = L_29.___register;
		uint16_t L_31 = L_30.___uint16_1;
		if ((((int32_t)L_28) == ((int32_t)L_31)))
		{
			G_B188_0 = (&V_20);
			goto IL_09dd;
		}
		G_B187_0 = (&V_20);
	}
	{
		G_B189_0 = 0;
		G_B189_1 = G_B187_0;
		goto IL_09e2;
	}

IL_09dd:
	{
		uint16_t L_32;
		L_32 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B189_0 = ((int32_t)(L_32));
		G_B189_1 = G_B188_0;
	}

IL_09e2:
	{
		G_B189_1->___uint16_1 = (uint16_t)G_B189_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_33 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_34 = L_33.___register;
		uint16_t L_35 = L_34.___uint16_2;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_36 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_37 = L_36.___register;
		uint16_t L_38 = L_37.___uint16_2;
		if ((((int32_t)L_35) == ((int32_t)L_38)))
		{
			G_B191_0 = (&V_20);
			goto IL_0a04;
		}
		G_B190_0 = (&V_20);
	}
	{
		G_B192_0 = 0;
		G_B192_1 = G_B190_0;
		goto IL_0a09;
	}

IL_0a04:
	{
		uint16_t L_39;
		L_39 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B192_0 = ((int32_t)(L_39));
		G_B192_1 = G_B191_0;
	}

IL_0a09:
	{
		G_B192_1->___uint16_2 = (uint16_t)G_B192_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_40 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_41 = L_40.___register;
		uint16_t L_42 = L_41.___uint16_3;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_43 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_44 = L_43.___register;
		uint16_t L_45 = L_44.___uint16_3;
		if ((((int32_t)L_42) == ((int32_t)L_45)))
		{
			G_B194_0 = (&V_20);
			goto IL_0a2b;
		}
		G_B193_0 = (&V_20);
	}
	{
		G_B195_0 = 0;
		G_B195_1 = G_B193_0;
		goto IL_0a30;
	}

IL_0a2b:
	{
		uint16_t L_46;
		L_46 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B195_0 = ((int32_t)(L_46));
		G_B195_1 = G_B194_0;
	}

IL_0a30:
	{
		G_B195_1->___uint16_3 = (uint16_t)G_B195_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_47 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_48 = L_47.___register;
		uint16_t L_49 = L_48.___uint16_4;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_50 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_51 = L_50.___register;
		uint16_t L_52 = L_51.___uint16_4;
		if ((((int32_t)L_49) == ((int32_t)L_52)))
		{
			G_B197_0 = (&V_20);
			goto IL_0a52;
		}
		G_B196_0 = (&V_20);
	}
	{
		G_B198_0 = 0;
		G_B198_1 = G_B196_0;
		goto IL_0a57;
	}

IL_0a52:
	{
		uint16_t L_53;
		L_53 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B198_0 = ((int32_t)(L_53));
		G_B198_1 = G_B197_0;
	}

IL_0a57:
	{
		G_B198_1->___uint16_4 = (uint16_t)G_B198_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_54 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_55 = L_54.___register;
		uint16_t L_56 = L_55.___uint16_5;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_57 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_58 = L_57.___register;
		uint16_t L_59 = L_58.___uint16_5;
		if ((((int32_t)L_56) == ((int32_t)L_59)))
		{
			G_B200_0 = (&V_20);
			goto IL_0a79;
		}
		G_B199_0 = (&V_20);
	}
	{
		G_B201_0 = 0;
		G_B201_1 = G_B199_0;
		goto IL_0a7e;
	}

IL_0a79:
	{
		uint16_t L_60;
		L_60 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B201_0 = ((int32_t)(L_60));
		G_B201_1 = G_B200_0;
	}

IL_0a7e:
	{
		G_B201_1->___uint16_5 = (uint16_t)G_B201_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_61 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_62 = L_61.___register;
		uint16_t L_63 = L_62.___uint16_6;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_64 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_65 = L_64.___register;
		uint16_t L_66 = L_65.___uint16_6;
		if ((((int32_t)L_63) == ((int32_t)L_66)))
		{
			G_B203_0 = (&V_20);
			goto IL_0aa0;
		}
		G_B202_0 = (&V_20);
	}
	{
		G_B204_0 = 0;
		G_B204_1 = G_B202_0;
		goto IL_0aa5;
	}

IL_0aa0:
	{
		uint16_t L_67;
		L_67 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B204_0 = ((int32_t)(L_67));
		G_B204_1 = G_B203_0;
	}

IL_0aa5:
	{
		G_B204_1->___uint16_6 = (uint16_t)G_B204_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_68 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_69 = L_68.___register;
		uint16_t L_70 = L_69.___uint16_7;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_71 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_72 = L_71.___register;
		uint16_t L_73 = L_72.___uint16_7;
		if ((((int32_t)L_70) == ((int32_t)L_73)))
		{
			G_B206_0 = (&V_20);
			goto IL_0ac7;
		}
		G_B205_0 = (&V_20);
	}
	{
		G_B207_0 = 0;
		G_B207_1 = G_B205_0;
		goto IL_0acc;
	}

IL_0ac7:
	{
		uint16_t L_74;
		L_74 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B207_0 = ((int32_t)(L_74));
		G_B207_1 = G_B206_0;
	}

IL_0acc:
	{
		G_B207_1->___uint16_7 = (uint16_t)G_B207_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_75;
		memset((&L_75), 0, sizeof(L_75));
		Vector_1__ctor_m48CD7847B9597F3193C9C0BA97ED64E276F4340A((&L_75), (&V_20), NULL);
		return L_75;
	}
}
// Method Definition Index: 9596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
	}
	{
		uint16_t L_0 = ___0_left;
		uint16_t L_1 = ___1_right;
		return (bool)((((int32_t)L_0) == ((int32_t)L_1))? 1 : 0);
	}
}
// Method Definition Index: 9597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_GetOneValue_m7E814AFD17E4D390C12EF731DA01203D262D9953 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
	}
	{
		return (uint16_t)1;
	}
}
// Method Definition Index: 9598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_GetAllBitsSetValue_m854DE079EA89F97089D3EF29D7C31F081F420580 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
	}
	{
		uint16_t L_0;
		L_0 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 9599
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__cctor_m6764AA686DE7E188C362C5B3E96AB2F5AB09F3CA (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = Vector_1_InitializeCount_m43BBDDA05FDAB290038584331DB79CB33C523B83(NULL);
		((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count = L_0;
		il2cpp_codegen_initobj((&((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero), sizeof(Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489));
		uint16_t L_1;
		L_1 = Vector_1_GetOneValue_m7E814AFD17E4D390C12EF731DA01203D262D9953_inline(NULL);
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_2;
		memset((&L_2), 0, sizeof(L_2));
		Vector_1__ctor_mDA4A6115C4120BFDD773FD4D3753FD3EC2B10427((&L_2), L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_one = L_2;
		uint16_t L_3;
		L_3 = Vector_1_GetAllBitsSetValue_m854DE079EA89F97089D3EF29D7C31F081F420580_inline(NULL);
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector_1__ctor_mDA4A6115C4120BFDD773FD4D3753FD3EC2B10427((&L_4), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_allOnes = L_4;
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
// Method Definition Index: 9579
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
// Method Definition Index: 9580
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_get_Zero_m052680C155E15387C16A5E044176ACB59DF53359 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero;
		return L_0;
	}
}
// Method Definition Index: 9581
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VectorSizeHelper_tF54ACCE947CB8A38047BEB642392A4E7345A157D V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B8_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B13_0 = 0;
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* L_0 = (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)(&(&V_0)->____placeholder);
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&L_0->___register);
		uint8_t* L_2 = (uint8_t*)(&L_1->___byte_0);
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_2,NULL));
		V_1 = (uint8_t*)L_3;
		uint8_t* L_4 = (uint8_t*)(&(&V_0)->____byte);
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		uint8_t* L_6 = V_1;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,uint8_t*,intptr_t,false,false>(((uint8_t*)((intptr_t)((uint8_t*)il2cpp_codegen_subtract((intptr_t)L_5, (intptr_t)L_6))/1)),NULL));
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_7,NULL));
		V_2 = (-1);
		G_B2_0 = L_8;
		goto IL_0045;
	}

IL_0045:
	{
		G_B4_0 = G_B2_0;
		goto IL_0067;
	}

IL_0067:
	{
		G_B6_0 = G_B4_0;
		goto IL_0089;
	}

IL_0089:
	{
		G_B8_0 = G_B6_0;
		goto IL_00ab;
	}

IL_00ab:
	{
		G_B10_0 = G_B8_0;
		goto IL_00cd;
	}

IL_00cd:
	{
		G_B12_0 = G_B10_0;
		goto IL_00ef;
	}

IL_00ef:
	{
		G_B13_0 = G_B12_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B13_0;
		goto IL_0176;
	}

IL_0176:
	{
		int32_t L_9 = V_2;
		return ((int32_t)(G_B21_0/L_9));
	}
}
// Method Definition Index: 9582
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int8_t* V_3 = NULL;
	int8_t* V_4 = NULL;
	int32_t V_5 = 0;
	uint16_t* V_6 = NULL;
	uint16_t* V_7 = NULL;
	int32_t V_8 = 0;
	int16_t* V_9 = NULL;
	int16_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint32_t* V_12 = NULL;
	uint32_t* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t* V_15 = NULL;
	int32_t* V_16 = NULL;
	int32_t V_17 = 0;
	uint64_t* V_18 = NULL;
	uint64_t* V_19 = NULL;
	int32_t V_20 = 0;
	int64_t* V_21 = NULL;
	int64_t* V_22 = NULL;
	int32_t V_23 = 0;
	float* V_24 = NULL;
	float* V_25 = NULL;
	int32_t V_26 = 0;
	double* V_27 = NULL;
	double* V_28 = NULL;
	int32_t V_29 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0386;
		}
	}
	{
		goto IL_005e;
	}

IL_005e:
	{
		goto IL_00b3;
	}

IL_00b3:
	{
		goto IL_010d;
	}

IL_010d:
	{
		goto IL_0167;
	}

IL_0167:
	{
		goto IL_01c1;
	}

IL_01c1:
	{
		goto IL_021b;
	}

IL_021b:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_2 = (uint64_t*)(&L_1->___uint64_0);
		V_19 = L_2;
		uint64_t* L_3 = V_19;
		uintptr_t L_4 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_3,NULL));
		V_18 = (uint64_t*)L_4;
		V_20 = 0;
		goto IL_0267;
	}

IL_024d:
	{
		uint64_t* L_5 = V_18;
		int32_t L_6 = V_20;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		uint64_t L_8 = ___0_value;
		*(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8)))))) = ((int64_t)L_8);
		int32_t L_9 = V_20;
		V_20 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0267:
	{
		int32_t L_10 = V_20;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_024d;
		}
	}
	{
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_19 = (uint64_t*)L_12;
		return;
	}

IL_0386:
	{
		goto IL_0505;
	}

IL_0505:
	{
		goto IL_0684;
	}

IL_0684:
	{
		goto IL_0753;
	}

IL_0753:
	{
		goto IL_0822;
	}

IL_0822:
	{
		goto IL_0896;
	}

IL_0896:
	{
		goto IL_090a;
	}

IL_090a:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_13 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_14 = ___0_value;
		L_13->___uint64_0 = L_14;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_16 = ___0_value;
		L_15->___uint64_1 = L_16;
		return;
	}
}
// Method Definition Index: 9583
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_dataPointer;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B(__this, L_0, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4));
		return;
	}
}
// Method Definition Index: 9584
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int8_t* V_4 = NULL;
	int8_t* V_5 = NULL;
	int8_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint16_t* V_8 = NULL;
	uint16_t* V_9 = NULL;
	uint16_t* V_10 = NULL;
	int32_t V_11 = 0;
	int16_t* V_12 = NULL;
	int16_t* V_13 = NULL;
	int16_t* V_14 = NULL;
	int32_t V_15 = 0;
	uint32_t* V_16 = NULL;
	uint32_t* V_17 = NULL;
	uint32_t* V_18 = NULL;
	int32_t V_19 = 0;
	int32_t* V_20 = NULL;
	int32_t* V_21 = NULL;
	int32_t* V_22 = NULL;
	int32_t V_23 = 0;
	uint64_t* V_24 = NULL;
	uint64_t* V_25 = NULL;
	uint64_t* V_26 = NULL;
	int32_t V_27 = 0;
	int64_t* V_28 = NULL;
	int64_t* V_29 = NULL;
	int64_t* V_30 = NULL;
	int32_t V_31 = 0;
	float* V_32 = NULL;
	float* V_33 = NULL;
	float* V_34 = NULL;
	int32_t V_35 = 0;
	double* V_36 = NULL;
	double* V_37 = NULL;
	double* V_38 = NULL;
	int32_t V_39 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		goto IL_0053;
	}

IL_0053:
	{
		goto IL_00ae;
	}

IL_00ae:
	{
		goto IL_0112;
	}

IL_0112:
	{
		goto IL_0176;
	}

IL_0176:
	{
		goto IL_01da;
	}

IL_01da:
	{
		goto IL_023e;
	}

IL_023e:
	{
	}
	{
		void* L_0 = ___0_dataPointer;
		V_24 = (uint64_t*)L_0;
		uint64_t* L_1 = V_24;
		int32_t L_2 = ___1_offset;
		intptr_t L_3 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_2,NULL));
		V_24 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(L_3, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_4 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_5 = (uint64_t*)(&L_4->___uint64_0);
		V_26 = L_5;
		uint64_t* L_6 = V_26;
		uintptr_t L_7 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_6,NULL));
		V_25 = (uint64_t*)L_7;
		V_27 = 0;
		goto IL_0294;
	}

IL_027c:
	{
		uint64_t* L_8 = V_25;
		int32_t L_9 = V_27;
		intptr_t L_10 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_9,NULL));
		uint64_t* L_11 = V_24;
		int32_t L_12 = V_27;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int64_t L_14 = *(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 8))))));
		*(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(L_10, 8)))))) = L_14;
		int32_t L_15 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0294:
	{
		int32_t L_16 = V_27;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_17;
		L_17 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_027c;
		}
	}
	{
		uintptr_t L_18 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_26 = (uint64_t*)L_18;
		return;
	}
}
// Method Definition Index: 9585
// Method Definition Index: 9586
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int8_t* V_1 = NULL;
	uint16_t* V_2 = NULL;
	int16_t* V_3 = NULL;
	uint32_t* V_4 = NULL;
	int32_t* V_5 = NULL;
	uint64_t* V_6 = NULL;
	int64_t* V_7 = NULL;
	float* V_8 = NULL;
	double* V_9 = NULL;
	{
		int32_t L_0 = ___0_index;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_2 = ___0_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}

IL_000c:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F)), L_5, NULL);
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_7 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0022:
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_0090;
	}

IL_0090:
	{
		goto IL_00ca;
	}

IL_00ca:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0140;
	}

IL_0140:
	{
		goto IL_017c;
	}

IL_017c:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_8 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_9 = (uint64_t*)(&L_8->___uint64_0);
		V_6 = L_9;
		uint64_t* L_10 = V_6;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_10,NULL));
		int32_t L_12 = ___0_index;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int64_t L_14 = *(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 8))))));
		return L_14;
	}
}
// Method Definition Index: 9587
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(__this, ((*(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 9588
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		V_0 = 0;
		goto IL_0027;
	}

IL_000b:
	{
		int32_t L_1 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_2;
		L_2 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_3 = V_0;
		uint64_t L_4;
		L_4 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___0_other), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_5;
		L_5 = Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline(L_2, L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		return (bool)0;
	}

IL_0023:
	{
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0027:
	{
		int32_t L_7 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_0031:
	{
		goto IL_01f0;
	}

IL_01f0:
	{
		goto IL_03af;
	}

IL_03af:
	{
		goto IL_0496;
	}

IL_0496:
	{
		goto IL_057d;
	}

IL_057d:
	{
		goto IL_05fb;
	}

IL_05fb:
	{
		goto IL_0679;
	}

IL_0679:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_9 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_10 = L_9->___uint64_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_11 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_12 = L_11.___register;
		uint64_t L_13 = L_12.___uint64_0;
		if ((!(((uint64_t)L_10) == ((uint64_t)L_13))))
		{
			goto IL_06c5;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_14 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_15 = L_14->___uint64_1;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_16 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_17 = L_16.___register;
		uint64_t L_18 = L_17.___uint64_1;
		return (bool)((((int64_t)L_15) == ((int64_t)L_18))? 1 : 0);
	}

IL_06c5:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27_AdjustorThunk (RuntimeObject* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// Method Definition Index: 9589
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	CHECKED_LOCAL(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	int8_t V_4 = 0x0;
	int32_t V_5 = 0;
	uint16_t V_6 = 0;
	int32_t V_7 = 0;
	int16_t V_8 = 0;
	int32_t V_9 = 0;
	uint32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int64_t V_16 = 0;
	int32_t V_17 = 0;
	float V_18 = 0.0f;
	int32_t V_19 = 0;
	double V_20 = 0.0;
	{
		V_0 = 0;
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_034a;
		}
	}
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_00a7;
	}

IL_00a7:
	{
		goto IL_00fa;
	}

IL_00fa:
	{
		goto IL_014d;
	}

IL_014d:
	{
		goto IL_01a0;
	}

IL_01a0:
	{
		goto IL_01f3;
	}

IL_01f3:
	{
	}
	{
		V_13 = 0;
		goto IL_023b;
	}

IL_0213:
	{
		int32_t L_1 = V_0;
		int32_t L_2 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_3;
		L_3 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_2, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		V_14 = L_3;
		int32_t L_4;
		L_4 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_14), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_5;
		L_5 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_1, L_4, NULL);
		V_0 = L_5;
		int32_t L_6 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_023b:
	{
		int32_t L_7 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0213;
		}
	}
	{
		int32_t L_9 = V_0;
		return L_9;
	}

IL_034a:
	{
		goto IL_04da;
	}

IL_04da:
	{
		goto IL_066a;
	}

IL_066a:
	{
		goto IL_0742;
	}

IL_0742:
	{
		goto IL_081a;
	}

IL_081a:
	{
		goto IL_0893;
	}

IL_0893:
	{
		goto IL_090c;
	}

IL_090c:
	{
	}
	{
		int32_t L_10 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_11 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_12 = (uint64_t*)(&L_11->___uint64_0);
		int32_t L_13;
		L_13 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_12, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_14;
		L_14 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_10, L_13, NULL);
		V_0 = L_14;
		int32_t L_15 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_16 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_17 = (uint64_t*)(&L_16->___uint64_1);
		int32_t L_18;
		L_18 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_17, NULL);
		int32_t L_19;
		L_19 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_15, L_18, NULL);
		V_0 = L_19;
		int32_t L_20 = V_0;
		return L_20;
	}
}
IL2CPP_EXTERN_C  int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	int32_t _returnValue;
	_returnValue = Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 9590
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit);
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit,(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_0;
		L_0 = CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5(NULL);
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C(__this, _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869, L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return L_1;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 9591
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		RuntimeObject* L_1 = ___1_formatProvider;
		NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* L_2;
		L_2 = NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F(L_1, NULL);
		NullCheck(L_2);
		String_t* L_3;
		L_3 = NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline(L_2, NULL);
		V_1 = L_3;
		StringBuilder_t* L_4 = V_0;
		NullCheck(L_4);
		StringBuilder_t* L_5;
		L_5 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_4, ((int32_t)60), NULL);
		V_2 = 0;
		goto IL_0053;
	}

IL_001f:
	{
		StringBuilder_t* L_6 = V_0;
		int32_t L_7 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_8;
		L_8 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_7, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint64_t L_9 = L_8;
		RuntimeObject* L_10 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_9);
		String_t* L_11 = ___0_format;
		RuntimeObject* L_12 = ___1_formatProvider;
		String_t* L_13;
		L_13 = UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3((uint64_t*)UnBox(L_10), L_11, L_12, NULL);
		NullCheck(L_6);
		StringBuilder_t* L_14;
		L_14 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_6, L_13, NULL);
		StringBuilder_t* L_15 = V_0;
		String_t* L_16 = V_1;
		NullCheck(L_15);
		StringBuilder_t* L_17;
		L_17 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_16, NULL);
		StringBuilder_t* L_18 = V_0;
		NullCheck(L_18);
		StringBuilder_t* L_19;
		L_19 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_18, ((int32_t)32), NULL);
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0053:
	{
		int32_t L_21 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_22;
		L_22 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_21) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_22, 1)))))
		{
			goto IL_001f;
		}
	}
	{
		StringBuilder_t* L_23 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_24;
		L_24 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uint64_t L_25;
		L_25 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, ((int32_t)il2cpp_codegen_subtract(L_24, 1)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint64_t L_26 = L_25;
		RuntimeObject* L_27 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_26);
		String_t* L_28 = ___0_format;
		RuntimeObject* L_29 = ___1_formatProvider;
		String_t* L_30;
		L_30 = UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3((uint64_t*)UnBox(L_27), L_28, L_29, NULL);
		NullCheck(L_23);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_23, L_30, NULL);
		StringBuilder_t* L_32 = V_0;
		NullCheck(L_32);
		StringBuilder_t* L_33;
		L_33 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_32, ((int32_t)62), NULL);
		StringBuilder_t* L_34 = V_0;
		NullCheck(L_34);
		String_t* L_35;
		L_35 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_34);
		return L_35;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C_AdjustorThunk (RuntimeObject* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C(_thisAdjusted, ___0_format, ___1_formatProvider, method);
	return _returnValue;
}
// Method Definition Index: 9592
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
// Method Definition Index: 9593
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Inequality_m4963768CF3F7944DA5E519ADB8668431198BBC36 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___0_left;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 9594
// Method Definition Index: 9595
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_Equals_m10063846A51F9D722BC0A8999A9F6B12C37988FF (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	uint16_t* V_4 = NULL;
	int32_t V_5 = 0;
	int16_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint32_t* V_8 = NULL;
	int32_t V_9 = 0;
	int32_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint64_t* V_12 = NULL;
	int32_t V_13 = 0;
	int64_t* V_14 = NULL;
	int32_t V_15 = 0;
	float* V_16 = NULL;
	int32_t V_17 = 0;
	double* V_18 = NULL;
	int32_t V_19 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A V_20;
	memset((&V_20), 0, sizeof(V_20));
	uint64_t* G_B53_0 = NULL;
	uint64_t* G_B52_0 = NULL;
	uint64_t G_B54_0 = 0;
	uint64_t* G_B54_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B265_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B264_0 = NULL;
	uint64_t G_B266_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B266_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B268_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B267_0 = NULL;
	uint64_t G_B269_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B269_1 = NULL;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0447;
		}
	}
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_00c6;
	}

IL_00c6:
	{
		goto IL_0133;
	}

IL_0133:
	{
		goto IL_01a0;
	}

IL_01a0:
	{
		goto IL_020d;
	}

IL_020d:
	{
		goto IL_027a;
	}

IL_027a:
	{
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_1,NULL));
		if ((uintptr_t)L_2 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_3 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_2, 8));
		int8_t* L_4;
		if (L_3 == 0)
		{
			L_4 = NULL;
		}
		else
		{
			L_4 = (int8_t*)alloca(L_3);
			memset(L_4, 0, L_3);
		}
		V_12 = (uint64_t*)L_4;
		V_13 = 0;
		goto IL_02d7;
	}

IL_02a6:
	{
		uint64_t* L_5 = V_12;
		int32_t L_6 = V_13;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_9;
		L_9 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___0_left), L_8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_10 = V_13;
		uint64_t L_11;
		L_11 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___1_right), L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_12;
		L_12 = Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline(L_9, L_11, NULL);
		if (L_12)
		{
			G_B53_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8))));
			goto IL_02cb;
		}
		G_B52_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8))));
	}
	{
		int64_t L_13 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B54_0 = ((uint64_t)(L_13));
		G_B54_1 = G_B52_0;
		goto IL_02d0;
	}

IL_02cb:
	{
		uint64_t L_14;
		L_14 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B54_0 = L_14;
		G_B54_1 = G_B53_0;
	}

IL_02d0:
	{
		*(((int64_t*)G_B54_1)) = ((int64_t)G_B54_0);
		int32_t L_15 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_02d7:
	{
		int32_t L_16 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_17;
		L_17 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_02a6;
		}
	}
	{
		uint64_t* L_18 = V_12;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_19;
		memset((&L_19), 0, sizeof(L_19));
		Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA((&L_19), (void*)L_18, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_19;
	}

IL_0447:
	{
		il2cpp_codegen_initobj((&V_20), sizeof(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A));
		goto IL_06e5;
	}

IL_06e5:
	{
		goto IL_097b;
	}

IL_097b:
	{
		goto IL_0ad9;
	}

IL_0ad9:
	{
		goto IL_0c37;
	}

IL_0c37:
	{
		goto IL_0cf9;
	}

IL_0cf9:
	{
		goto IL_0dbb;
	}

IL_0dbb:
	{
	}
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_20 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_21 = L_20.___register;
		uint64_t L_22 = L_21.___uint64_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_23 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_24 = L_23.___register;
		uint64_t L_25 = L_24.___uint64_0;
		if ((((int64_t)L_22) == ((int64_t)L_25)))
		{
			G_B265_0 = (&V_20);
			goto IL_0df4;
		}
		G_B264_0 = (&V_20);
	}
	{
		int64_t L_26 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B266_0 = ((uint64_t)(L_26));
		G_B266_1 = G_B264_0;
		goto IL_0df9;
	}

IL_0df4:
	{
		uint64_t L_27;
		L_27 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B266_0 = L_27;
		G_B266_1 = G_B265_0;
	}

IL_0df9:
	{
		G_B266_1->___uint64_0 = G_B266_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_28 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_29 = L_28.___register;
		uint64_t L_30 = L_29.___uint64_1;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_31 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_32 = L_31.___register;
		uint64_t L_33 = L_32.___uint64_1;
		if ((((int64_t)L_30) == ((int64_t)L_33)))
		{
			G_B268_0 = (&V_20);
			goto IL_0e1c;
		}
		G_B267_0 = (&V_20);
	}
	{
		int64_t L_34 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B269_0 = ((uint64_t)(L_34));
		G_B269_1 = G_B267_0;
		goto IL_0e21;
	}

IL_0e1c:
	{
		uint64_t L_35;
		L_35 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B269_0 = L_35;
		G_B269_1 = G_B268_0;
	}

IL_0e21:
	{
		G_B269_1->___uint64_1 = G_B269_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_36;
		memset((&L_36), 0, sizeof(L_36));
		Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606((&L_36), (&V_20), NULL);
		return L_36;
	}
}
// Method Definition Index: 9596
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00d0;
	}

IL_00d0:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0138;
	}

IL_0138:
	{
	}
	{
		uint64_t L_0 = ___0_left;
		uint64_t L_1 = ___1_right;
		return (bool)((((int64_t)L_0) == ((int64_t)L_1))? 1 : 0);
	}
}
// Method Definition Index: 9597
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
		goto IL_0075;
	}

IL_0075:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00c3;
	}

IL_00c3:
	{
		goto IL_00ea;
	}

IL_00ea:
	{
	}
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		return L_0;
	}
}
// Method Definition Index: 9598
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0 (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
		goto IL_0081;
	}

IL_0081:
	{
		goto IL_00ac;
	}

IL_00ac:
	{
		goto IL_00d7;
	}

IL_00d7:
	{
		goto IL_0102;
	}

IL_0102:
	{
	}
	{
		uint64_t L_0;
		L_0 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 9599
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__cctor_m152F538F7C3F6DB8EA8C03902F8A68FF06A70109 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A(NULL);
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count = L_0;
		il2cpp_codegen_initobj((&((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero), sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		uint64_t L_1;
		L_1 = Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline(NULL);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_2;
		memset((&L_2), 0, sizeof(L_2));
		Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6((&L_2), L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_one = L_2;
		uint64_t L_3;
		L_3 = Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline(NULL);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6((&L_4), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_allOnes = L_4;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 10058
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		String_t* L_0 = __this->___numberGroupSeparator;
		return L_0;
	}
}
// Method Definition Index: 9571
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint16_t V_0 = 0;
	{
		V_0 = (uint16_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int16_t*)L_0)) = ((int16_t)((int32_t)65535));
		uint16_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 9575
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint64_t V_0 = 0;
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		V_0 = L_0;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		*(((int64_t*)L_1)) = L_2;
		uint64_t L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Variable_1_get_Value_mBDB4AF75424BD19560DECF91824EB8FAA2B2B2A0_inline (Variable_1_t20D0123177AF808E975D3E46C58E850428F9AE59* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* EqualityComparer_1_get_Default_mBB75BC0723DFD7850F43E72E34026DD070CF5932_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* V_0 = NULL;
	{
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_0 = ((EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m3BD7BED1F69ABEE55E320BA9CCFBB473E9F57C66(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t97160852989689D9543E2E1EA7D7196DBEA5AEE4* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 879
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mDB8F7C7381C08B4DCE4E409D2FA4073BC17F90B5_gshared_inline (Action_1_tF0E1373A391479E6E235E0D82CE1EF1DE6B6C505* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	typedef void (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t Variable_1_get_Value_mD0057B746D5431B65D5DA43FDF147338757C3F60_inline (Variable_1_tCE49D2AE2274D75BAD4044C28FB20B79C84358AE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint8_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* V_0 = NULL;
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0 = ((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Variable_1_get_Value_mCE97447059178647D92ECF616139A2C300754FB2_inline (Variable_1_t65C8CA86DB8E2333F938F15D9F7C521768A3A6E0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		double L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* EqualityComparer_1_get_Default_m12CC270D19620F4E8E3ABFE7BF8C2B1955476A04_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* V_0 = NULL;
	{
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_0 = ((EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m66568B441EE3AB73D292C4F4CE1707FBAC360F5A(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t5574F94668D24600F369D7DCE0505C0AEC9244EB* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t Variable_1_get_Value_m99E47FE45F8EED362ABAA7A5C60E1FDBC2EF16B6_inline (Variable_1_t5DAEB61508451D46FD3167E64A8C88EFD8095219* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int16_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* V_0 = NULL;
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0 = ((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Variable_1_get_Value_mB9432728880A015C5A63501CBA12FF6A1BF3B592_inline (Variable_1_t231FD2EB8107AD6E581E7C76D0E5F3C2755CAF1C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* V_0 = NULL;
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_0 = ((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t Variable_1_get_Value_mF4B538CD5F52E625F550C929D2CFFF4B6CEA3222_inline (Variable_1_t19EF8955713E0DF277D898F8519EAE4758EBB2F3* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int64_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* EqualityComparer_1_get_Default_m76691DC579907239261E159E4DFDD8B1C3C9E5FE_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* V_0 = NULL;
	{
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_0 = ((EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m8A944543377C40C1596E4EECED12E463FC3DDFC3(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tE05A9BF0932DEB0653A3BD392318FAA5123C3504* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t Variable_1_get_Value_mF9CD2A80EB3185803DED48932A7D2884BEE5EA46_inline (Variable_1_t0E7FFB9FC46FCCE4D288F1825285D6049B207FE1* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int8_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* V_0 = NULL;
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0 = ((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Variable_1_get_Value_m081AE7A04760F3A6D24B60EC302067FF249D9A19_inline (Variable_1_t147B7A0D686A39C5655E8F12A8BDCC9AC94DDA98* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		float L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* EqualityComparer_1_get_Default_m20A1B9861324559044977270E1FAFB09BBE14234_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* V_0 = NULL;
	{
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_0 = ((EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m4055D46D61B6AD80A0F2D4624577D7FE9D15B002(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t346CEF653847623862FC6F88D66F7933B0039499* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Variable_1_get_Value_m8B985ECA2D3E467519539B3D8BD55741CE062A50_inline (Variable_1_tCC9B2BC93046552945B489ADA407AB4C823D524C* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint16_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* V_0 = NULL;
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0 = ((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t Variable_1_get_Value_m51812A760E77C113E1004AEB571C5CDD183BBD0F_inline (Variable_1_t9F9B655C9C28DEC415BF272D35C98CE4FD515910* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint32_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* EqualityComparer_1_get_Default_mF554877B669658FD6449F84AE369214855D0BC40_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* V_0 = NULL;
	{
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_0 = ((EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m64D3D774E7DAF5FC0206DC26D9BA53BF70F1F93B(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tBE7039362398A2C9BD71FAAAB935B7FF9F6EA862* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Variable_1_get_Value_mCA6D6B56F4B36E36366847151FCB5612463EAAB3_inline (Variable_1_t0FC69CB3C332A3FB2C10A6A5691FE7A7C5148F19* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uint64_t L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* EqualityComparer_1_get_Default_m65C88AD76FA11C898FE9437B5D46E13B12F10B77_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* V_0 = NULL;
	{
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_0 = ((EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m73A019C274DF1E66D30647A3F24ADC27784B7114(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t7BD194EF0EF9D754203F4B95A88927DF3621DA17* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 78963
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Variable_1_get_Value_mED5E97ED3335CC47C471B44F086BC20C9705A1F9_gshared_inline (Variable_1_t09372EDD50A506E2AFAE1423957E95E4ECEFE1FE* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Il2CppSharedGenericObject* L_0 = __this->___m_Value;
		return L_0;
	}
}
// Method Definition Index: 11576
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_0 = NULL;
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_0 = ((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 9579
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
// Method Definition Index: 9587
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mD7F4E0B493DD44E2685BC17F8D6EAD92342CBC29_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8(__this, ((*(Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
// Method Definition Index: 9596
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
	}
	{
		uint16_t L_0 = ___0_left;
		uint16_t L_1 = ___1_right;
		return (bool)((((int32_t)L_0) == ((int32_t)L_1))? 1 : 0);
	}
}
// Method Definition Index: 9592
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mB42F3DAE52C3BC7579B302E623196C45A5DEAC6B_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_m729FD34A0F43A7C8A8DF285BCED9B5B31D579FE8((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
// Method Definition Index: 9597
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetOneValue_m7E814AFD17E4D390C12EF731DA01203D262D9953_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
	}
	{
		return (uint16_t)1;
	}
}
// Method Definition Index: 9598
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t Vector_1_GetAllBitsSetValue_m854DE079EA89F97089D3EF29D7C31F081F420580_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
	}
	{
		uint16_t L_0;
		L_0 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		return L_0;
	}
}
// Method Definition Index: 9579
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
// Method Definition Index: 9587
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(__this, ((*(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
// Method Definition Index: 9596
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00d0;
	}

IL_00d0:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0138;
	}

IL_0138:
	{
	}
	{
		uint64_t L_0 = ___0_left;
		uint64_t L_1 = ___1_right;
		return (bool)((((int64_t)L_0) == ((int64_t)L_1))? 1 : 0);
	}
}
// Method Definition Index: 9592
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
// Method Definition Index: 9597
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
		goto IL_0075;
	}

IL_0075:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00c3;
	}

IL_00c3:
	{
		goto IL_00ea;
	}

IL_00ea:
	{
	}
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		return L_0;
	}
}
// Method Definition Index: 9598
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
		goto IL_0081;
	}

IL_0081:
	{
		goto IL_00ac;
	}

IL_00ac:
	{
		goto IL_00d7;
	}

IL_00d7:
	{
		goto IL_0102;
	}

IL_0102:
	{
	}
	{
		uint64_t L_0;
		L_0 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		return L_0;
	}
}
