#undef  WIZ_TYPELIST_PARAM_COUNT
#define WIZ_TYPELIST_PARAM_COUNT        WIZ_MPP_REPEAT_FILE_COUNT

/////////////////////////////////////////////////////////////////////////////////////////
namespace Wiz
{
    namespace TypeList
    {
        template < WIZ_ENUM_PARAM_X(WIZ_TYPELIST_PARAM_COUNT, class T) >
        struct Type < Void::Type(WIZ_ENUM_PARAM_X(WIZ_TYPELIST_PARAM_COUNT, T))> : public WIZ_TYPELIST_FAST_DEFINE(WIZ_TYPELIST_PARAM_COUNT, T)
        {
        }; /// end of struct Type
    } /// end of namespace TypeList
} /// end of namespace Wiz
/////////////////////////////////////////////////////////////////////////////////////////

#undef  WIZ_TYPELIST_PARAM_COUNT
