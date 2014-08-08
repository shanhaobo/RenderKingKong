#ifndef __RENDERKINGKONG_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__
#define __RENDERKINGKONG_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__

////////////////////////////////////////////////////////////////////////////

#   define RKK_DECLARE_TYPE(t)          \
    typedef t           type;           \
    typedef t const     typec;

#   define RKK_DECLARE_PTR(t)           \
    typedef t *         ptr;            \
    typedef t const *   ptrc;           \
    typedef t * const   ptrf;           \
    typedef t * const * ptrfc;

#   define RKK_DECLARE_REF(t)           \
    typedef t &         ref;            \
    typedef t const &   refc;

#   define RKK_DECLARE_PARAM(t)         \
    typedef t const &   in;             \
    typedef t &         out;            \
    typedef t &         io;

#   define RKK_DECLARE_PARAM_SIMPLE(t)  \
    typedef t const     in;             \
    typedef t &         out;            \
    typedef t &         io;

////////////////////////////////////////////////////////////////////////////

#   define RKK_DECLARE_BASE(t)          \
    RKK_DECLARE_TYPE(t)                 \
    RKK_DECLARE_PTR(t)                  \
    RKK_DECLARE_REF(t)

#   define RKK_DECLARE(t)               \
    RKK_DECLARE_BASE(t)                 \
    RKK_DECLARE_PARAM(t)

#   define RKK_DECLARE_SIMPLE(t)        \
    RKK_DECLARE_BASE(t)                 \
    RKK_DECLARE_PARAM_SIMPLE(t)

////////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_TYPEDECLAREUTILS_HPP__SHANHAOBO_19800429__*/
