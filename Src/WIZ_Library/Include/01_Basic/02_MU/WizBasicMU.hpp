#ifndef __WIZ_BASIC_MU_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MU_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"
#include "../00_MPP/WizBasicMPP.hpp"

//////////////////////////////////////////////////////////////////////////

#define WIZ_SAFE_MACRO_BEGIN        do {
#define WIZ_SAFE_MACRO_END          } while(0)

#define WIZ_SAFE_MACRO(x)           WIZ_SAFE_MACRO_BEGIN x WIZ_SAFE_MACRO_END

//////////////////////////////////////////////////////////////////////////
#define WIZ_NULL                    0

#if (WIZ_CFG_CPP_NULLPTR == WIZ_CFG_TRUE)
#   define WIZ_NULLPTR              nullptr
#else
#   define WIZ_NULLPTR              WIZ_NULL
#endif /// (WIZ_CFG_CPP_NULLPTR == WIZ_CFG_TRUE)

///=================================///
#define WIZ_BITS_DEF(n)             (1 << n)
///=================================///
#define WIZ_ARRAY_SIZE(a)           ((sizeof(a))/(sizeof(a[0])))
///=================================///
/// the twice power of x
///=================================///
/// char:8 int16:16
#define WIZ_BITS_COUNT(t)           (sizeof(t) << 3)
/// char:10000000   int16:1000000000000000
#define WIZ_TYPE_SET_HIGHEST_1(t)   ((t)1 << (WIZ_BITS_COUNT(t) - 1))
///=================================///

#if (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_MSVC)
#   define WIZ_STRUCT_OFFSET(st, mb)	    ((ptrdiff_t)&((st*)NULL)->mb)
#elif (WIZ_CFG_COMPILER == WIZ_CFG_COMPILER_GNUC)
#   define WIZ_STRUCT_OFFSET(st, mb)	    (((ptrdiff_t)&((st*)0x10)->mb) - 0x10)
#else
#   define WIZ_STRUCT_OFFSET(st, mb)	    (((ptrdiff_t)&((st*)0x10)->mb) - 0x10)
#endif /*#if (WIZ_COMPILER == WIZ_COMPILER_MSVC)*/

#define WIZ_BASECLASS_OFFSET(thisclass, baseclass)  ((ptrdiff_t)((baseclass*)((thisclass*)0x10)) - 0x10)

///=================================///
#define WIZ_UNUSED(x)
///=================================///

#define WIZ_ISPOWEROFTWO(x)         ((x & (x - 1)) == 0)

//////////////////////////////////////////////////////////////////////////
/// 这是枚举函数参数的帮助宏
#define WIZ_COMMA   ,
#define WIZ_SPACE

#define WIZ_COMMA_IF(C)                 WIZ_MPP_IF(C, WIZ_COMMA, WIZ_SPACE)

/// WIZ_ENUM_PARAM_M_X(总循环次数， 当前循环次数， 参数) 在此例中，总循环次数无用
/// X0, X1, X2
#define WIZ_ENUM_PARAM_M_X(S, C, P)     WIZ_COMMA_IF(C) WIZ_MPP_COMBINE(P, C)
#define WIZ_ENUM_PARAM_X(S, X)          WIZ_MPP_LOOP(S, WIZ_ENUM_PARAM_M_X, X)

/// WIZ_ENUM_PARAM_M_XY(总循环次数， 当前循环次数， 参数) 在此例中，总循环次数无用
/// T0 X0, T1 X1
#define WIZ_ENUM_PARAM_M_XY(S, C, P)    WIZ_COMMA_IF(C) WIZ_MPP_COMBINE(WIZ_MPP_TUPLE_ELEM(2, 0, P), C) WIZ_MPP_COMBINE(WIZ_MPP_TUPLE_ELEM(2, 1, P), C)
#define WIZ_ENUM_PARAM_XY(S, X, Y)      WIZ_MPP_LOOP(S, WIZ_ENUM_PARAM_M_XY, (X, Y))
//////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASIC_MU_HPP__SHANHAOBO_19800429__*/
