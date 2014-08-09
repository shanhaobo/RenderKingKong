#ifndef __RENDERKINGKONG_BASETYPE_HPP__
#define __RENDERKINGKONG_BASETYPE_HPP__

#include "./TypeDeclareUtils.hpp"

#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE                RKK_DECLARE
#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE         RKK_DECLARE_SIMPLE
#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR            RKK_DECLARE_PTR
#include "../../../WIZ_Library/Include/01_Base/01_Type/WizBaseTypeDeclareHelper.hpp"

namespace rkk
{
    namespace I8
    {
        WIZ_DECLARE_HELPER_I8();
    }

    namespace U8
    {
        WIZ_DECLARE_HELPER_U8();
    }

    namespace I16
    {
        WIZ_DECLARE_HELPER_I16();
    }

    namespace U16
    {
        WIZ_DECLARE_HELPER_U16();
    }

    namespace I32
    {
        WIZ_DECLARE_HELPER_I32();
    }

    namespace U32
    {
        WIZ_DECLARE_HELPER_U32();
    }

    namespace I64
    {
        WIZ_DECLARE_HELPER_I64();
    }

    namespace U64
    {
        WIZ_DECLARE_HELPER_U64();
    }

    namespace Char
    {
        WIZ_DECLARE_HELPER_CHAR();
    }

    namespace WChar
    {
        WIZ_DECLARE_HELPER_WCHAR();
    }

    namespace MBChar
    {
        WIZ_DECLARE_HELPER_MBCHAR();
    }

    namespace F32
    {
        WIZ_DECLARE_HELPER_R32();
    }

    namespace F64
    {
        WIZ_DECLARE_HELPER_R64();
    }

    namespace Void
    {
        typedef void type;
        WIZ_DECLARE_HELPER_VOID();
    }

    namespace Bool
    {
        WIZ_DECLARE_HELPER_BOOL();
    }
} /// namespace rkk

#endif /// __RENDERKINGKONG_BASETYPE_HPP__
