#ifndef __WIZ_BASE_TEMPLATE_COMPARE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_TEMPLATE_COMPARE_HPP__SHANHAOBO_19800429__

#include "./WizBaseTemplateZero.hpp"

namespace Wiz
{
    /////////////////////////

    namespace Absolute
    {
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type IsEqual(const T& v1, const T& v2)
        {
            return v1 == v2;
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotEqual(const T& v1, const T& v2)
        {
            return v1 != v2;
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type Less(const T& v1, const T& v2)
        {
            return v1 < v2;
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type Greater(const T& v1, const T& v2)
        {
            return v1 > v2;
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqual(const T& v1, const T& v2)
        {
            return v1 <= v2;
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqual(const T& v1, const T& v2)
        {
            return v1 >= v2;
        }
        /// [Min, Max] Close
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type InRange(const T& v, const T& Min, const T& Max)
        {
            return (Min <= v) && (v <= Max);
        }
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type OutRange(const T& v, const T& Min, const T& Max)
        {
            return (Min > v) || (v > Max);
        }
    } /// end of namespace Absolute

    /////////////////////////

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsEqual(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::IsEqual<T>(v1, v2);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotEqual(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::NotEqual<T>(v1, v2);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type Less(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::Less<T>(v1, v2);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type Greater(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::Greater<T>(v1, v2);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type LessEqual(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::LessEqual<T>(v1, v2);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type GreaterEqual(const T& v1, const T& v2)
    {
        return ::Wiz::Absolute::GreaterEqual<T>(v1, v2);
    }
    /// [Min, Max] Close
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type InRange(const T& v, const T& Min, const T& Max)
    {
        return ::Wiz::Absolute::InRange<T>(v, Min, Max);
    }
    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type OutRange(const T& v, const T& Min, const T& Max)
    {
        return ::Wiz::Absolute::OutRange<T>(v, Min, Max);
    }
    /////////////////////////

    namespace Nearly
    {
        /// IsEqual
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type IsEqual(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::IsEqual<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type IsEqual(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::IsZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type IsEqual(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::IsZero(v1 - v2);
        }

        /// NotEqual
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotEqual(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::NotEqual<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type NotEqual(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::NotZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type NotEqual(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::NotZero(v1 - v2);
        }

        /// Less
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type Less(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::Less<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type Less(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::LessZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type Less(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::LessZero(v1 - v2);
        }

        /// Greater
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type Greater(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::Greater<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type Greater(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::GreaterZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type Greater(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::GreaterZero(v1 - v2);
        }

        /// LessEqual
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqual(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::LessEqual<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessEqual(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::LessEqualZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessEqual(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::LessEqualZero(v1 - v2);
        }

        /// GreaterEqual
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqual(const T& v1, const T& v2)
        {
            return ::Wiz::Absolute::GreaterEqual<T>(v1, v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqual(::Wiz::Real32::In v1, ::Wiz::Real32::In v2)
        {
            return ::Wiz::Nearly::GreaterEqualZero(v1 - v2);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqual(::Wiz::Real64::In v1, ::Wiz::Real64::In v2)
        {
            return ::Wiz::Nearly::GreaterEqualZero(v1 - v2);
        }

        /// InRange [Min, Max] Close
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type InRange(const T& v, const T& Min, const T& Max)
        {
            return ::Wiz::Absolute::InRange<T>(v, Min, Max);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type InRange(::Wiz::Real32::In v, ::Wiz::Real32::In Min, ::Wiz::Real32::In Max)
        {
            return (v >= (Min - ::Wiz::Real32::Epsilon)) && (v <= (Max + ::Wiz::Real32::Epsilon));
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type InRange(::Wiz::Real64::In v, ::Wiz::Real64::In Min, ::Wiz::Real64::In Max)
        {
            return (v >= (Min - ::Wiz::Real64::Epsilon)) && (v <= (Max + ::Wiz::Real64::Epsilon));
        }

        /// OutRange
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type OutRange(const T& v, const T& Min, const T& Max)
        {
            return ::Wiz::Absolute::OutRange<T>(v, Min, Max);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type OutRange(::Wiz::Real32::In v, ::Wiz::Real32::In Min, ::Wiz::Real32::In Max)
        {
            return (v < (Min - ::Wiz::Real32::Epsilon)) || (v > (Max + ::Wiz::Real32::Epsilon));
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type OutRange(::Wiz::Real64::In v, ::Wiz::Real64::In Min, ::Wiz::Real64::In Max)
        {
            return (v < (Min - ::Wiz::Real64::Epsilon)) || (v > (Max + ::Wiz::Real64::Epsilon));
        }

    } /// end of namespace Nearly
    /////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASE_TEMPLATE_COMPARE_HPP__SHANHAOBO_19800429__*/
