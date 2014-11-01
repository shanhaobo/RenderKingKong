#undef  WIZ_TYPELIST_PARAM_COUNT
#define WIZ_TYPELIST_PARAM_COUNT        WIZ_MPP_REPEAT_FILE_COUNT
#define WIZ_TYPELIST_TEMP_WEPX          (WIZ_ENUM_PARAM_X(WIZ_TYPELIST_PARAM_COUNT, T))

/////////////////////////////////////////////////////////////////////////////////////////
namespace Wiz
{
    namespace TypeList
    {
        template < WIZ_ENUM_PARAM_X(WIZ_TYPELIST_PARAM_COUNT, class T) >
        struct Type < void(WIZ_ENUM_PARAM_X(WIZ_TYPELIST_PARAM_COUNT, T))> : public WIZ_MPP_COMBINE(WIZ_MPP_COMBINE(WIZ_TYPELIST_, WIZ_TYPELIST_PARAM_COUNT), WIZ_TYPELIST_TEMP_WEPX)
        {
        }; /// end of struct Type
    } /// end of namespace TypeList
} /// end of namespace Wiz
/////////////////////////////////////////////////////////////////////////////////////////

#undef WIZ_TYPELIST_TEMP_WEPX
#undef WIZ_TYPELIST_PARAM_COUNT
