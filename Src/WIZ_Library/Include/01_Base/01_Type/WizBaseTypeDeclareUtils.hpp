#ifndef __WIZ_BASE_CORE_DECLARE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_CORE_DECLARE_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_TYPE(t)          \
    typedef t           Type;           \
    typedef t const     TypeC;

#   define WIZ_DECLARE_PTR(t)           \
    typedef t *         Ptr;            \
    typedef t const *   PtrC;           \
    typedef t * const   PtrF;           \
    typedef t * const * PtrFC;

#   define WIZ_DECLARE_REF(t)           \
    typedef t &         Ref;            \
    typedef t const &   RefC;

#   define WIZ_DECLARE_PARAM(t)         \
    typedef t const &   In;             \
    typedef t &         Out;            \
    typedef t &         IO;

#   define WIZ_DECLARE_PARAM_SIMPLE(t)  \
    typedef t const     In;             \
    typedef t &         Out;            \
    typedef t &         IO;

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_BASE(t)          \
    WIZ_DECLARE_TYPE(t)                 \
    WIZ_DECLARE_PTR(t)                  \
    WIZ_DECLARE_REF(t)

#   define WIZ_DECLARE(t)               \
    WIZ_DECLARE_BASE(t)                 \
    WIZ_DECLARE_PARAM(t)

#   define WIZ_DECLARE_SIMPLE(t)        \
    WIZ_DECLARE_BASE(t)                 \
    WIZ_DECLARE_PARAM_SIMPLE(t)

////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASE_CORE_DECLARE_HPP__SHANHAOBO_19800429__*/
