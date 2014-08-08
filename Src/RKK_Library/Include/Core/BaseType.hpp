#ifndef __RENDERKINGKONG_BASETYPE_HPP__
#define __RENDERKINGKONG_BASETYPE_HPP__

#include "./TypeDeclareUtils.hpp"

namespace rkk
{
    namespace I8
    {
        RKK_DECLARE_SIMPLE(__int8);
    }

    namespace U8
    {
        RKK_DECLARE_SIMPLE(unsigned __int8);
    }

    namespace I16
    {
        RKK_DECLARE_SIMPLE(__int16);
    }

    namespace U16
    {
        RKK_DECLARE_SIMPLE(unsigned __int16);
    }

    namespace I32
    {
        RKK_DECLARE_SIMPLE(__int32);
    }

    namespace U32
    {
        RKK_DECLARE_SIMPLE(unsigned __int32);
    }

    namespace I64
    {
        RKK_DECLARE_SIMPLE(__int64);
    }

    namespace U64
    {
        RKK_DECLARE_SIMPLE(unsigned __int64);
    }

    namespace F32
    {
        RKK_DECLARE_SIMPLE(float);
    }

    namespace F64
    {

        RKK_DECLARE_SIMPLE(double);
    }

    namespace Void
    {
        typedef void   type;

        RKK_DECLARE_PTR(void)
    }

    namespace Bool
    {
        RKK_DECLARE_SIMPLE(bool);

        static typec   True = true;
        static typec   False = false;
    }
} /// namespace rkk

#endif /// __RENDERKINGKONG_BASETYPE_HPP__
