#ifndef __WIZ_ADVANCED_TYPE_SZ_HPP__SHANHAOBO_19800429__
#define __WIZ_ADVANCED_TYPE_SZ_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicTypeInt.hpp"

namespace Wiz
{
    namespace SZ
    {
        WIZ_DECLARE_SIMPLE(size_t);
    } /// end of namespace SZ

    //////////////////////////////////////////////////////////////////////////
    namespace SZ8
    {
        WIZ_DECLARE_SIMPLE(::Wiz::I8::Type);
        static ::Wiz::SZ8::TypeC Invalid      = ::Wiz::I8::Min;
        static ::Wiz::SZ8::TypeC Min          = 0;
        static ::Wiz::SZ8::TypeC Max          = ::Wiz::I8::Max;
    } /// end of namespace SZ8
    namespace SZ16
    {
        WIZ_DECLARE_SIMPLE(::Wiz::I16::Type);
        static ::Wiz::SZ16::TypeC Invalid     = ::Wiz::I16::Min;
        static ::Wiz::SZ16::TypeC Min         = 0;
        static ::Wiz::SZ16::TypeC Max         = ::Wiz::I16::Max;
    } /// end of namespace SZ16
    namespace SZ32
    {
        WIZ_DECLARE_SIMPLE(::Wiz::I32::Type);
        static ::Wiz::SZ32::TypeC Invalid     = ::Wiz::I32::Min;
        static ::Wiz::SZ32::TypeC Min         = 0;
        static ::Wiz::SZ32::TypeC Max         = ::Wiz::I32::Max;
    } /// end of namespace SZ32
    namespace SZ64
    {
        WIZ_DECLARE_SIMPLE(::Wiz::I64::Type);
        static ::Wiz::SZ64::TypeC Invalid     = ::Wiz::I64::Min;
        static ::Wiz::SZ64::TypeC Min         = 0;
        static ::Wiz::SZ64::TypeC Max         = ::Wiz::I64::Max;
    } /// end of namespace SZ64
    //////////////////////////////////////////////////////////////////////////
    namespace USZ8
    {
        WIZ_DECLARE_SIMPLE(::Wiz::U8::Type);
        static ::Wiz::USZ8::TypeC Invalid     = ::Wiz::U8::Max;
        static ::Wiz::USZ8::TypeC Min         = 0;
        static ::Wiz::USZ8::TypeC Max         = ::Wiz::U8::Max;
    } /// end of namespace SZ8
    namespace USZ16
    {
        WIZ_DECLARE_SIMPLE(::Wiz::U16::Type);
        static ::Wiz::USZ16::TypeC Invalid    = ::Wiz::U16::Max;
        static ::Wiz::USZ16::TypeC Min        = 0;
        static ::Wiz::USZ16::TypeC Max        = ::Wiz::U16::Max;
    } /// end of namespace SZ16
    namespace USZ32
    {
        WIZ_DECLARE_SIMPLE(::Wiz::U32::Type);
        static ::Wiz::USZ32::TypeC Invalid    = ::Wiz::U32::Max;
        static ::Wiz::USZ32::TypeC Min        = 0;
        static ::Wiz::USZ32::TypeC Max        = ::Wiz::U32::Max;
    } /// end of namespace SZ32
    namespace USZ64
    {
        WIZ_DECLARE_SIMPLE(::Wiz::U64::Type);
        static ::Wiz::USZ64::TypeC Invalid    = ::Wiz::U64::Max;
        static ::Wiz::USZ64::TypeC Min        = 0;
        static ::Wiz::USZ64::TypeC Max        = ::Wiz::U64::Max;
    } /// end of namespace USZ64
} /// end of namespace Wiz

#endif /*__WIZ_ADVANCED_TYPE_SZ_HPP__SHANHAOBO_19800429__*/
