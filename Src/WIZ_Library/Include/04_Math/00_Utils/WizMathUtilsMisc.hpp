#ifndef __WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__

#include <math.h>

#include "../../Base/Type/WizBaseType.hpp"

namespace Wiz
{
    ////////////////////////////////////////////////////////////////////////
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsPowerOfTwo(const T& Val)
    {
        return WIZ_ISPOWEROFTWO(Val);
    }

    template<int n>
    WIZ_INLINE ::Wiz::Bool::Type IsPowerOfTwo()
    {
        return WIZ_ISPOWEROFTWO(n);
    }
    //////////////////////////////////////////////////////////////////////////
    WIZ_INLINE ::Wiz::Int32::Type NextPowerOfTwo(::Wiz::Int32::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::UInt32::Type NextPowerOfTwo(::Wiz::UInt32::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::Int64::Type NextPowerOfTwo(::Wiz::Int64::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    WIZ_INLINE ::Wiz::UInt64::Type NextPowerOfTwo(::Wiz::UInt64::Type x)
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    template<::Wiz::Int32::Type x>
    WIZ_INLINE ::Wiz::Int32::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    template<::Wiz::UInt32::Type x>
    WIZ_INLINE ::Wiz::UInt32::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x + 1;
    }

    template<::Wiz::Int64::Type x>
    WIZ_INLINE ::Wiz::Int64::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    template<::Wiz::UInt64::Type x>
    WIZ_INLINE ::Wiz::UInt64::Type NextPowerOfTwo()
    {
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        x |= (x >> 32);
        return x + 1;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ABS
    template<class T>
    WIZ_INLINE T AbsDiff(const T& t1, const T& t2)
    {
        return t1 >= t2 ? t1 - t2 : t2 - t1;
    }

    //////////////////////////////////////////////////////////////////////////

    template<class T>
    WIZ_INLINE T Abs(const T& t)
    {
        return t < 0 ? -t : t;
    }

    template<class T>
    WIZ_INLINE T Sign(const T& v)
    {
        return v < 0 ? -1 : v > 0 ? 1 : 0;
    }

    //////////////////////////////////////////////////////////////////////////
    /// CLAMP
    template<class T>
    WIZ_INLINE T Clamp(const T& v, const T& Min_v, const T& Max_v)
    {
        return v < Min_v ? Min_v : v > Max_v ? Max_v : v;
    }

    template<class T>
    WIZ_INLINE T Saturate(const T& v)
    {
        return ::Wiz::Clamp<T>(v, 0, 1);
    }

    template<class T>
    WIZ_INLINE T ConvertRange(const T& t, const T& From1, const T& From2, const T& To1, const T& To2) 
    {
        return (t - From1) * (To2 - To1) / (From2 - From1) + To1;           /// (t - From1) / (From2 - From1) = (x - To1) / (To2 - To1)
    }
    //////////////////////////////////////////////////////////////////////////
    template<typename T>
    WIZ_INLINE T Sqr(const T& r)
    {
        return r * r;
    }

    template<typename T>
    WIZ_INLINE T Sqrt(const T& v)
    {
        return ::Wiz::Cast::Static<T>(::sqrt(::Wiz::Cast::Static<double>(v)));
    }
    WIZ_INLINE ::Wiz::Real32::Type SqrtFast(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::sqrt(::Wiz::Cast::Static<double>(v)));
    }
    WIZ_INLINE ::Wiz::Real64::Type SqrtFast(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::sqrt(v));
    }

    template<typename T>
    WIZ_INLINE T RecipSqrt(const T& v)
    {
        return 1 / ::Wiz::Sqrt(v);
    }
    WIZ_INLINE ::Wiz::Real32::Type RecipSqrtFast(::Wiz::Real32::In v)
    {
        return 1 / ::sqrt(v);
    }
    WIZ_INLINE ::Wiz::Real64::Type RecipSqrtFast(::Wiz::Real64::In v)
    {
        return 1 / ::sqrt(v);
    }

    //////////////////////////////////////////////////////////////////////////

    WIZ_INLINE ::Wiz::Real32::Type Abs(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::abs(v));
    }

    WIZ_INLINE ::Wiz::Real32::Type Exp(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::exp(v));
    }

    /// Not A Number
    WIZ_INLINE ::Wiz::Bool::Type IsNAN(::Wiz::Real32::In v)
    {
        return ::_isnan(v) != 0;
    }

    /// -INF << v << INF
    WIZ_INLINE ::Wiz::Bool::Type IsFinite(::Wiz::Real32::In v)
    {
        return ::_finite(v) != 0;
    }

    /// returns the largest integer that is not greater than the argument
    WIZ_INLINE ::Wiz::Real32::Type FloorF(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::floor(v));
    }

    /// 四舍五入
    WIZ_INLINE ::Wiz::Int32::Type Round(::Wiz::Real32::In v)
    {
        return _mm_cvt_ss2si(_mm_set_ss(v + v + 0.5f)) >> 1;
    }

    /// Returns the largest integer that is not greater than the argument.
    WIZ_INLINE ::Wiz::Int32::Type Floor(::Wiz::Real32::In v)
    {
        return _mm_cvt_ss2si(_mm_set_ss(v + v - 0.5f)) >> 1;
    }

    /// Returns the smallest integer that is not less than the argument.
    WIZ_INLINE ::Wiz::Int32::Type Ceil(::Wiz::Real32::In v)
    {
        return -(_mm_cvt_ss2si(_mm_set_ss(0.5f - (v + v))) >> 1);
    }

    /// Calculates the floating-point remainder.
    WIZ_INLINE ::Wiz::Real32::Type Fmod(::Wiz::Real32::In numerator, ::Wiz::Real32::In denominator)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::fmod(numerator, denominator));
    }

    WIZ_INLINE ::Wiz::Real32::Type Log2(::Wiz::Real32::In v)
    {
        /*
        ** NOTE: log_base_2(x) = log(x) / log(2)
        ** NOTE: 1.442695 = 1/log(2).
        */
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::log(v) * 1.442695f);
    }

    WIZ_INLINE ::Wiz::Real32::Type LogE(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::log(v));
    }

    WIZ_INLINE ::Wiz::Real32::Type Log10(::Wiz::Real32::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::log10(v));
    }

    WIZ_INLINE ::Wiz::Real32::Type Pow(::Wiz::Real32::In base, ::Wiz::Real32::In exponent)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::pow(base, exponent));
    }

    WIZ_INLINE ::Wiz::Int32::Type Trunc(::Wiz::Real32::In r)
    {
        return _mm_cvt_ss2si(_mm_set_ss(r));
    }

    WIZ_INLINE ::Wiz::Real32::Type TruncF(::Wiz::Real32::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::Real32::Type>(::Wiz::Trunc(r));
    }

    WIZ_INLINE ::Wiz::Real32::Type Fract(::Wiz::Real32::In r)
    {
        return r - ::Wiz::TruncF(r);
    }

    WIZ_INLINE ::Wiz::Int::Type QuadraticEquationRoots(::Wiz::Real32::Out Root1, ::Wiz::Real32::Out Root2, ::Wiz::Real32::In A, ::Wiz::Real32::In B, ::Wiz::Real32::In C)
    {
        if (A == 0)
        {
            if (B == 0)
            {
                return 0;
            }
            Root1 = -C / B;
            return 1;
        }

        ::Wiz::Real32::TypeConst t = B * B - 4 * A * C;
        if (t < 0)
        {
            return 0;
        }

        ::Wiz::Real32::TypeConst TempRoot = -B / (2 * A);
        if (t == 0)
        {
            Root1 = TempRoot;
            return 1;
        }

        ::Wiz::Real32::TypeConst TempDiff = ::Wiz::Sqrt(t) / (2 * A);

        Root1 = TempRoot + TempDiff;
        Root2 = TempRoot - TempDiff;
        return 2;
    }

    //////////////////////////////////////////////////////////////////////////

    WIZ_INLINE ::Wiz::Real64::Type Abs(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::abs(v));
    }

    WIZ_INLINE ::Wiz::Real64::Type Exp(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::exp(v));
    }

    WIZ_INLINE ::Wiz::Real64::Type Floor(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::floor(v));
    }

    /// Calculates the floating-point remainder.
    WIZ_INLINE ::Wiz::Real64::Type Fmod(::Wiz::Real64::In numerator, ::Wiz::Real64::In denominator)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::fmod(numerator, denominator));
    }

    WIZ_INLINE ::Wiz::Real64::Type Log2(::Wiz::Real64::In v)
    {
        /*
        * NOTE: log_base_2(x) = log(x) / log(2)
        * NOTE: 1.442695 = 1/log(2).
        */
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::log(v) * 1.442695f);
    }


    WIZ_INLINE ::Wiz::Real64::Type LogE(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::log(v));
    }

    WIZ_INLINE ::Wiz::Real64::Type Log10(::Wiz::Real64::In v)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::log10(v));
    }

    WIZ_INLINE ::Wiz::Real64::Type Pow(::Wiz::Real64::In base, ::Wiz::Real64::In exponent)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::pow(base, exponent));
    }

    WIZ_INLINE ::Wiz::Int64::Type Trunc(::Wiz::Real64::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::Int64::Type>(r);
    }

    WIZ_INLINE ::Wiz::Real64::Type TruncF(::Wiz::Real64::In r)
    {
        return ::Wiz::Cast::Static<::Wiz::Real64::Type>(::Wiz::Trunc(r));
    }

    WIZ_INLINE ::Wiz::Real64::Type Fract(::Wiz::Real64::In r)
    {
        return r - ::Wiz::Cast::Static<::Wiz::Real64::Type>(::Wiz::Trunc(r));
    }

    /// Quadratic 二次方程
    WIZ_INLINE ::Wiz::Int::Type QuadraticEquationRoots(::Wiz::Real64::Out Root1, ::Wiz::Real64::Out Root2, ::Wiz::Real64::In A, ::Wiz::Real64::In B, ::Wiz::Real64::In C)
    {
        if (A == 0)
        {
            if (B == 0)
            {
                return 0;
            }
            Root1 = -C / B;
            return 1;
        }

        ::Wiz::Real64::TypeConst t = B * B - 4 * A * C;
        if (t < 0)
        {
            return 0;
        }

        ::Wiz::Real64::TypeConst TempRoot = -B / (2 * A);

        if (t == 0)
        {
            Root1 = TempRoot;
            return 1;
        }
        ::Wiz::Real64::TypeConst TempDiff = ::Wiz::Sqrt(t) / (2 * A);

        Root1 = TempRoot + TempDiff;
        Root2 = TempRoot - TempDiff;
        return 2;
    }
} /// end of namespace Wiz


#endif /*__WIZ_MATH_UTILS_MISC_HPP__SHANHAOBO_19800429__*/
