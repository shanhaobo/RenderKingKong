#ifndef __WIZ_BASIC_TU_TYPELIST_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_TYPELIST_HPP__SHANHAOBO_19800429__

#include "../../00_MPP/WizBasicMPP.hpp"
#include "./WizBasicTUTypeListImpl.hpp"

namespace Wiz
{
    namespace TypeList
    {
        template <class T> struct Type;
    } /// end of namespace TypeList
} /// end of namespace Wiz

/////////////////////////////////////////////////////////////////////////////////////////

/// WIZ_TYPELIST_1 ~ WIZ_TYPELIST_127
/// 为了加快编译速度，只是用了1~16个(支持1~127个)

#define WIZ_MPP_REPEAT_FILE_BEGIN   1
#define WIZ_MPP_REPEAT_FILE_END     16
#define WIZ_MPP_REPEAT_FILE_1_NAME  "./WizBasicTUTypeListTemplate.hpp"
#undef  WIZ_MPP_REPEAT_FILE_2_NAME

#include "../../00_MPP/WizBasicMPPRepeatFile.hpp"

#undef WIZ_MPP_REPEAT_FILE_BEGIN
#undef WIZ_MPP_REPEAT_FILE_END

#undef WIZ_MPP_REPEAT_FILE_1_NAME
#undef WIZ_MPP_REPEAT_FILE_2_NAME

/////////////////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_TU_TYPELIST_HPP__SHANHAOBO_19800429__*/
