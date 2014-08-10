#ifndef __WIZ_BASE_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__

#include "../../Config/WizConfig.hpp"
#include "../Core/WizBaseCoreTypeBool.hpp"
#include "../Core/WizBaseCoreTypeReal.hpp"

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
        WIZ_INLINE ::Wiz::Bool::Type IsZero(const T& InVal)
        {
            return ::Wiz::Absolute::IsZero(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type IsZero(::Wiz::Real32::In InVal)
        {
            return (InVal >= ::Wiz::Real32::MinZeroEp) && (InVal <= ::Wiz::Real32::MaxZeroEp);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type IsZero(::Wiz::Real64::In InVal)
        {
            return (InVal >= ::Wiz::Real64::MinZeroEp) && (InVal <= ::Wiz::Real64::MaxZeroEp);
        }

        /// NotZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotZero(const T& InVal)
        {
            return ::Wiz::Absolute::NotZero(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type NotZero(::Wiz::Real32::In InVal)
        {
            return (InVal < ::Wiz::Real32::MinZeroEp) || (InVal > ::Wiz::Real32::MaxZeroEp);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type NotZero(::Wiz::Real64::In InVal)
        {
            return (InVal < ::Wiz::Real64::MinZeroEp) || (InVal > ::Wiz::Real64::MaxZeroEp);
        }

        /// LessZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessZero(const T& InVal)
        {
            return ::Wiz::Absolute::LessZero<T>(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessZero(::Wiz::Real32::In InVal)
        {
            return InVal < ::Wiz::Real32::MinZeroEp;
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessZero(::Wiz::Real64::In InVal)
        {
            return InVal < ::Wiz::Real64::MinZeroEp;
        }

        /// GreaterZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterZero(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterZero<T>(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterZero(::Wiz::Real32::In InVal)
        {
            return InVal > ::Wiz::Real32::MaxZeroEp;
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterZero(::Wiz::Real64::In InVal)
        {
            return InVal > ::Wiz::Real64::MaxZeroEp;
        }

        /// LessEqualZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(const T& InVal)
        {
            return ::Wiz::Absolute::LessEqualZero<T>(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(::Wiz::Real32::In InVal)
        {
            return InVal <= ::Wiz::Real32::MaxZeroEp;
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualZero(::Wiz::Real64::In InVal)
        {
            return InVal <= ::Wiz::Real64::MaxZeroEp;
        }

        /// GreaterEqualZero
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterEqualZero<T>(InVal);
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(::Wiz::Real32::In InVal)
        {
            return InVal >= ::Wiz::Real32::MinZeroEp;
        }

        template<>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualZero(::Wiz::Real64::In InVal)
        {
            return InVal >= ::Wiz::Real64::MinZeroEp;
        }
    } /// end of namespace Nearly
    /////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_BASE_TEMPLATE_ZERO_HPP__SHANHAOBO_19800429__*/
