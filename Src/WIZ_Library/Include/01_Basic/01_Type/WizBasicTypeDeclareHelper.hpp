#ifndef __WIZ_BASE_TYPE_DECLARE_HELPER_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_TYPE_DECLARE_HELPER_HPP__SHANHAOBO_19800429__

#include "../01_Type/WizBasicType.hpp"

/// Ê¾Àý
/// #undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE
/// #define WIZ_DECLARE_HELPER_CUSTOM_DEFINE                RKK_DECLARE
/// #undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE
/// #define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE         RKK_DECLARE_SIMPLE
/// #undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR
/// #define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR            RKK_DECLARE_PTR

#ifndef     WIZ_DECLARE_HELPER_CUSTOM_DEFINE
#   define  WIZ_DECLARE_HELPER_CUSTOM_DEFINE               WIZ_DECLARE
#endif ///  WIZ_DECLARE_HELPER_CUSTOM_DEFINE

#ifndef     WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE
#   define  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE        WIZ_DECLARE_SIMPLE
#endif ///  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE

#ifndef     WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR
#   define  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR           WIZ_DECLARE_PTR
#endif ///  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR

/////////////////////////////////////////////////////////

#define WIZ_DECLARE_HELPER_I8()                                     \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::I8::Type)        \
    static ::Wiz::I8::TypeC Min = ::Wiz::I8::Min;                   \
    static ::Wiz::I8::TypeC Max = ::Wiz::I8::Max;

#define WIZ_DECLARE_HELPER_U8()                                     \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::U8::Type)        \
    static ::Wiz::U8::TypeC Min = ::Wiz::U8::Min;                   \
    static ::Wiz::U8::TypeC Max = ::Wiz::U8::Max;

#define WIZ_DECLARE_HELPER_I16()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::I16::Type)       \
    static ::Wiz::I16::TypeC Min = ::Wiz::I16::Min;                 \
    static ::Wiz::I16::TypeC Max = ::Wiz::I16::Max;

#define WIZ_DECLARE_HELPER_U16()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::U16::Type)       \
    static ::Wiz::U16::TypeC Min = ::Wiz::U16::Min;                 \
    static ::Wiz::U16::TypeC Max = ::Wiz::U16::Max;

#define WIZ_DECLARE_HELPER_I32()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::I32::Type)       \
    static ::Wiz::I32::TypeC Min = ::Wiz::I32::Min;                 \
    static ::Wiz::I32::TypeC Max = ::Wiz::I32::Max;

#define WIZ_DECLARE_HELPER_U32()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::U32::Type)       \
    static ::Wiz::U32::TypeC Min = ::Wiz::U32::Min;                 \
    static ::Wiz::U32::TypeC Max = ::Wiz::U32::Max;

#define WIZ_DECLARE_HELPER_I64()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::I64::Type)       \
    static ::Wiz::I64::TypeC Min = ::Wiz::I64::Min;                 \
    static ::Wiz::I64::TypeC Max = ::Wiz::I64::Max;

#define WIZ_DECLARE_HELPER_U64()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::U64::Type)       \
    static ::Wiz::U64::TypeC Min = ::Wiz::U64::Min;                 \
    static ::Wiz::U64::TypeC Max = ::Wiz::U64::Max;

/////////////////////////////////////////////////////////

#define WIZ_DECLARE_HELPER_R32()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::R32::Type)       \
    static ::Wiz::R32::TypeC Epsilon    = ::Wiz::R32::Epsilon;      \
    static ::Wiz::R32::TypeC EpsilonSqr = ::Wiz::R32::EpsilonSqr;   \
    static ::Wiz::R32::TypeC Zero       = ::Wiz::R32::Zero;         \
    static ::Wiz::R32::TypeC MaxZeroEp  = ::Wiz::R32::MaxZeroEp;    \
    static ::Wiz::R32::TypeC MinZeroEp  = ::Wiz::R32::MaxZeroEp;    \
    static ::Wiz::R32::TypeC One        = ::Wiz::R32::One;          \
    static ::Wiz::R32::TypeC MaxOneEp   = ::Wiz::R32::MaxOneEp;     \
    static ::Wiz::R32::TypeC MinOneEp   = ::Wiz::R32::MinOneEp;     \
    static ::Wiz::R32::TypeC Max        = ::Wiz::R32::Max;          \
    static ::Wiz::R32::TypeC Min        = ::Wiz::R32::Min;

#define WIZ_DECLARE_HELPER_R64()                                    \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::R64::Type)       \
    static ::Wiz::R64::TypeC Epsilon    = ::Wiz::R64::Epsilon;      \
    static ::Wiz::R64::TypeC EpsilonSqr = ::Wiz::R64::EpsilonSqr;   \
    static ::Wiz::R64::TypeC Zero       = ::Wiz::R64::Zero;         \
    static ::Wiz::R64::TypeC MaxZeroEp  = ::Wiz::R64::MaxZeroEp;    \
    static ::Wiz::R64::TypeC MinZeroEp  = ::Wiz::R64::MaxZeroEp;    \
    static ::Wiz::R64::TypeC One        = ::Wiz::R64::One;          \
    static ::Wiz::R64::TypeC MaxOneEp   = ::Wiz::R64::MaxOneEp;     \
    static ::Wiz::R64::TypeC MinOneEp   = ::Wiz::R64::MinOneEp;     \
    static ::Wiz::R64::TypeC Max        = ::Wiz::R64::Max;          \
    static ::Wiz::R64::TypeC Min        = ::Wiz::R64::Min;

/////////////////////////////////////////////////////////

#define WIZ_DECLARE_HELPER_CHAR()                                   \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::Char::Type)      \
    static ::Wiz::Char::TypeC Digit_0   = ::Wiz::Char::Digit_0;     \
    static ::Wiz::Char::TypeC Digit_1   = ::Wiz::Char::Digit_1;     \
    static ::Wiz::Char::TypeC Digit_2   = ::Wiz::Char::Digit_2;     \
    static ::Wiz::Char::TypeC Digit_3   = ::Wiz::Char::Digit_3;     \
    static ::Wiz::Char::TypeC Digit_4   = ::Wiz::Char::Digit_4;     \
    static ::Wiz::Char::TypeC Digit_5   = ::Wiz::Char::Digit_5;     \
    static ::Wiz::Char::TypeC Digit_6   = ::Wiz::Char::Digit_6;     \
    static ::Wiz::Char::TypeC Digit_7   = ::Wiz::Char::Digit_7;     \
    static ::Wiz::Char::TypeC Digit_8   = ::Wiz::Char::Digit_8;     \
    static ::Wiz::Char::TypeC Digit_9   = ::Wiz::Char::Digit_9;     \
    static ::Wiz::Char::TypeC Terminator = ::Wiz::Char::Terminator;

#define WIZ_DECLARE_HELPER_WCHAR()                                  \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::WChar::Type)     \
    static ::Wiz::WChar::TypeC Digit_0  = ::Wiz::WChar::Digit_0;    \
    static ::Wiz::WChar::TypeC Digit_1  = ::Wiz::WChar::Digit_1;    \
    static ::Wiz::WChar::TypeC Digit_2  = ::Wiz::WChar::Digit_2;    \
    static ::Wiz::WChar::TypeC Digit_3  = ::Wiz::WChar::Digit_3;    \
    static ::Wiz::WChar::TypeC Digit_4  = ::Wiz::WChar::Digit_4;    \
    static ::Wiz::WChar::TypeC Digit_5  = ::Wiz::WChar::Digit_5;    \
    static ::Wiz::WChar::TypeC Digit_6  = ::Wiz::WChar::Digit_6;    \
    static ::Wiz::WChar::TypeC Digit_7  = ::Wiz::WChar::Digit_7;    \
    static ::Wiz::WChar::TypeC Digit_8  = ::Wiz::WChar::Digit_8;    \
    static ::Wiz::WChar::TypeC Digit_9  = ::Wiz::WChar::Digit_9;    \
    static ::Wiz::WChar::TypeC Terminator = ::Wiz::WChar::Terminator;

#define WIZ_DECLARE_HELPER_MBCHAR()                                 \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::MBChar::Type)     \
    static ::Wiz::MBChar::TypeC Digit_0 = ::Wiz::MBChar::Digit_0;   \
    static ::Wiz::MBChar::TypeC Digit_1 = ::Wiz::MBChar::Digit_1;   \
    static ::Wiz::MBChar::TypeC Digit_2 = ::Wiz::MBChar::Digit_2;   \
    static ::Wiz::MBChar::TypeC Digit_3 = ::Wiz::MBChar::Digit_3;   \
    static ::Wiz::MBChar::TypeC Digit_4 = ::Wiz::MBChar::Digit_4;   \
    static ::Wiz::MBChar::TypeC Digit_5 = ::Wiz::MBChar::Digit_5;   \
    static ::Wiz::MBChar::TypeC Digit_6 = ::Wiz::MBChar::Digit_6;   \
    static ::Wiz::MBChar::TypeC Digit_7 = ::Wiz::MBChar::Digit_7;   \
    static ::Wiz::MBChar::TypeC Digit_8 = ::Wiz::MBChar::Digit_8;   \
    static ::Wiz::MBChar::TypeC Digit_9 = ::Wiz::MBChar::Digit_9;   \
    static ::Wiz::MBChar::TypeC Terminator = ::Wiz::MBChar::Terminator;

/////////////////////////////////////////////////////////

#define WIZ_DECLARE_HELPER_BOOL()                                   \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE(::Wiz::Bool::Type)      \
    static ::Wiz::Bool::TypeC True = ::Wiz::Bool::True;             \
    static ::Wiz::Bool::TypeC False = ::Wiz::Bool::False;           \

/////////////////////////////////////////////////////////

#define WIZ_DECLARE_HELPER_VOID()                                   \
    WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR(::Wiz::Void::Type)

/////////////////////////////////////////////////////////

#endif /*__WIZ_BASE_TYPE_DECLARE_HELPER_HPP__SHANHAOBO_19800429__*/
