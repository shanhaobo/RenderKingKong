#ifndef __WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__

#include "../../00_Config/WizConfig.hpp"

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_STDNAME_TYPE                 Type

#   define WIZ_DECLARE_TYPE_STDNAME(t)                              \
    typedef t                                       WIZ_DECLARE_STDNAME_TYPE;

#   define WIZ_DECLARE_TYPE_CONST                                   \
    typedef WIZ_DECLARE_STDNAME_TYPE const          TypeC;

#   define WIZ_DECLARE_PTR                                          \
    typedef WIZ_DECLARE_STDNAME_TYPE *              Ptr;            \
    typedef WIZ_DECLARE_STDNAME_TYPE const *        PtrC;           \
    typedef WIZ_DECLARE_STDNAME_TYPE * const        PtrF;           \
    typedef WIZ_DECLARE_STDNAME_TYPE const * const  PtrFC;

#   define WIZ_DECLARE_REF                                          \
    typedef WIZ_DECLARE_STDNAME_TYPE &              Ref;            \
    typedef WIZ_DECLARE_STDNAME_TYPE const &        RefC;

#   define WIZ_DECLARE_PARAM                                        \
    typedef WIZ_DECLARE_STDNAME_TYPE const &        In;             \
    typedef WIZ_DECLARE_STDNAME_TYPE &              Out;            \
    typedef WIZ_DECLARE_STDNAME_TYPE &              IO;

#   define WIZ_DECLARE_PARAM_SIMPLE                                 \
    typedef WIZ_DECLARE_STDNAME_TYPE const          In;             \
    typedef WIZ_DECLARE_STDNAME_TYPE &              Out;            \
    typedef WIZ_DECLARE_STDNAME_TYPE &              IO;

////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_TYPE(t)                      \
    WIZ_DECLARE_TYPE_STDNAME(t);                    \
    WIZ_DECLARE_TYPE_CONST

#   define WIZ_DECLARE_BASE(t)                      \
    WIZ_DECLARE_TYPE(t)                             \
    WIZ_DECLARE_PTR                                 \
    WIZ_DECLARE_REF

#   define WIZ_DECLARE(t)                           \
    WIZ_DECLARE_BASE(t)                             \
    WIZ_DECLARE_PARAM

#   define WIZ_DECLARE_SIMPLE(t)                    \
    WIZ_DECLARE_BASE(t)                             \
    WIZ_DECLARE_PARAM_SIMPLE

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

#   define WIZ_FORWARD_DECLARE                      \
    WIZ_DECLARE_TYPE_CONST                          \
    WIZ_DECLARE_PTR                                 \
    WIZ_DECLARE_REF                                 \
    WIZ_DECLARE_PARAM

#   define WIZ_FORWARD_DECLARE_CLASS                \
    class WIZ_DECLARE_STDNAME_TYPE;                 \
    WIZ_FORWARD_DECLARE

#   define WIZ_FORWARD_DECLARE_STRUCT               \
    struct WIZ_DECLARE_STDNAME_TYPE;                \
    WIZ_FORWARD_DECLARE

////////////////////////////////////////////////////////////////////////////

#   define WIZ_CLASS                                \
    class WIZ_DECLARE_STDNAME_TYPE;                 \
    WIZ_FORWARD_DECLARE                             \
    class WIZ_DECLARE_STDNAME_TYPE

#   define WIZ_STRUCT                               \
    struct WIZ_DECLARE_STDNAME_TYPE;                \
    WIZ_FORWARD_DECLARE                             \
    struct WIZ_DECLARE_STDNAME_TYPE

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

#   define WIZ_DECLARE_ITER(itr)                    \
    typedef itr                                     Iterator;

#   define WIZ_DECLARE_ITER_CONST(itr)              \
    typedef itr                                     IteratorC;

#endif /*__WIZ_BASIC_CORE_DECLARE_HPP__SHANHAOBO_19800429__*/
