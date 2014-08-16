#ifndef __WIZ_BASIC_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicType.hpp"

namespace Wiz
{
    /////////////////////////

    namespace Absolute
    {
        template<class T>
        WIZ_INLINE T GetZero()
        {
            return T(0);
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type IsZero(const T& InVal)
        {
            return ::Wiz::Absolute::GetZero<T>() == InVal;
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotZero(const T& InVal)
        {
            return ::Wiz::Absolute::GetZero<T>() != InVal;
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessZero(const T& InVal)
        {
            return InVal < ::Wiz::Absolute::GetZero<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterZero(const T& InVal)
        {
            return InVal > ::Wiz::Absolute::GetZero<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(const T& InVal)
        {
            return InVal <= ::Wiz::Absolute::GetZero<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(const T& InVal)
        {
            return InVal >= ::Wiz::Absolute::GetZero<T>();
        }
    } /// end of namespace Absolute

    /////////////////////////

    template<class T>
    WIZ_INLINE T GetZero()
    {
        return ::Wiz::Absolute::GetZero<T>();
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsZero(const T& InVal)
    {
        return ::Wiz::Absolute::IsZero<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotZero(const T& InVal)
    {
        return ::Wiz::Absolute::NotZero<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type LessZero(const T& InVal)
    {
        return ::Wiz::Absolute::LessZero<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type GreaterZero(const T& InVal)
    {
        return ::Wiz::Absolute::GreaterZero<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(const T& InVal)
    {
        return ::Wiz::Absolute::LessEqualZero<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(const T& InVal)
    {
        return ::Wiz::Absolute::GreaterEqualZero<T>(InVal);
    }

    /////////////////////////

    namespace Nearly
    {
        /// IsZero
        template<class T>
        WIZ_INLINE::Wiz::Bool::Type IsZero(T const & InVal)
        {
            return ::Wiz::Absolute::IsZero(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type IsZero(::Wiz::R32::Type const & InVal)
        {
            return (InVal >= ::Wiz::R32::MinZeroEp) && (InVal <= ::Wiz::R32::MaxZeroEp);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type IsZero(::Wiz::R64::Type const & InVal)
        {
            return (InVal >= ::Wiz::R64::MinZeroEp) && (InVal <= ::Wiz::R64::MaxZeroEp);
        }

        /// NotZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotZero(const T& InVal)
        {
            return ::Wiz::Absolute::NotZero(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type NotZero(::Wiz::R32::Type const & InVal)
        {
            return (InVal < ::Wiz::R32::MinZeroEp) || (InVal > ::Wiz::R32::MaxZeroEp);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type NotZero(::Wiz::R64::Type const & InVal)
        {
            return (InVal < ::Wiz::R64::MinZeroEp) || (InVal > ::Wiz::R64::MaxZeroEp);
        }

        /// LessZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessZero(const T& InVal)
        {
            return ::Wiz::Absolute::LessZero<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessZero(::Wiz::R32::Type const & InVal)
        {
            return InVal < ::Wiz::R32::MinZeroEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessZero(::Wiz::R64::Type const & InVal)
        {
            return InVal < ::Wiz::R64::MinZeroEp;
        }

        /// GreaterZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterZero(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterZero<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterZero(::Wiz::R32::Type const & InVal)
        {
            return InVal > ::Wiz::R32::MaxZeroEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterZero(::Wiz::R64::Type const & InVal)
        {
            return InVal > ::Wiz::R64::MaxZeroEp;
        }

        /// LessEqualZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(const T& InVal)
        {
            return ::Wiz::Absolute::LessEqualZero<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessEqualZero(::Wiz::R32::Type const & InVal)
        {
            return InVal <= ::Wiz::R32::MaxZeroEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessEqualZero(::Wiz::R64::Type const & InVal)
        {
            return InVal <= ::Wiz::R64::MaxZeroEp;
        }

        /// GreaterEqualZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterEqualZero<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterEqualZero(::Wiz::R32::Type const & InVal)
        {
            return InVal >= ::Wiz::R32::MinZeroEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterEqualZero(::Wiz::R64::Type const & InVal)
        {
            return InVal >= ::Wiz::R64::MinZeroEp;
        }
    } /// end of namespace Nearly
    /////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__*/
