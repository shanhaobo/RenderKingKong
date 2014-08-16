#ifndef __WIZ_BASIC_TEMPLATE_ONE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TEMPLATE_ONE_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicType.hpp"

namespace Wiz
{
    namespace Absolute
    {
        template<class T>
        WIZ_INLINE T GetOne()
        {
            return T(1);
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type IsOne(const T& InVal)
        {
            return ::Wiz::Absolute::GetOne<T>() == InVal;
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotOne(const T& InVal)
        {
            return ::Wiz::Absolute::GetOne<T>() != InVal;
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessOne(const T& InVal)
        {
            return InVal < ::Wiz::Absolute::GetOne<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterOne(const T& InVal)
        {
            return InVal > ::Wiz::Absolute::GetOne<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualOne(const T& InVal)
        {
            return InVal <= ::Wiz::Absolute::GetOne<T>();
        }

        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualOne(const T& InVal)
        {
            return InVal >= ::Wiz::Absolute::GetOne<T>();
        }
    } /// end of namespace Absolute

    /////////////////////////

    template<class T>
    WIZ_INLINE T GetOne()
    {
        return ::Wiz::Absolute::GetOne<T>();
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type IsOne(const T& InVal)
    {
        return ::Wiz::Absolute::IsOne<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type NotOne(const T& InVal)
    {
        return ::Wiz::Absolute::NotOne<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type LessOne(const T& InVal)
    {
        return ::Wiz::Absolute::LessOne<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type GreaterOne(const T& InVal)
    {
        return ::Wiz::Absolute::GreaterOne<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type LessEqualOne(const T& InVal)
    {
        return ::Wiz::Absolute::LessEqualOne<T>(InVal);
    }

    template<class T>
    WIZ_INLINE ::Wiz::Bool::Type GreaterEqualOne(const T& InVal)
    {
        return ::Wiz::Absolute::GreaterEqualOne<T>(InVal);
    }

    /////////////////////////

    namespace Nearly
    {
        /// IsOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type IsOne(const T& InVal)
        {
            return ::Wiz::Absolute::IsOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type IsOne(::Wiz::R32::Type const & InVal)
        {
            return (InVal >= ::Wiz::R32::MinOneEp) && (InVal <= ::Wiz::R32::MaxOneEp);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type IsOne(::Wiz::R64::Type const & InVal)
        {
            return (InVal >= ::Wiz::R64::MinOneEp) && (InVal <= ::Wiz::R64::MaxOneEp);
        }

        /// NotOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type NotOne(const T& InVal)
        {
            return ::Wiz::Absolute::NotOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type NotOne(::Wiz::R32::Type const & InVal)
        {
            return (InVal < ::Wiz::R32::MinOneEp) || (InVal > ::Wiz::R32::MaxOneEp);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type NotOne(::Wiz::R64::Type const & InVal)
        {
            return (InVal < ::Wiz::R64::MinOneEp) || (InVal > ::Wiz::R64::MaxOneEp);
        }

        /// LessOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessOne(const T& InVal)
        {
            return ::Wiz::Absolute::LessOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessOne(::Wiz::R32::Type const & InVal)
        {
            return InVal < ::Wiz::R32::MinOneEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessOne(::Wiz::R64::Type const & InVal)
        {
            return InVal < ::Wiz::R64::MinOneEp;
        }

        /// GreaterOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterOne(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterOne(::Wiz::R32::Type const & InVal)
        {
            return InVal > ::Wiz::R32::MaxOneEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterOne(::Wiz::R64::Type const & InVal)
        {
            return InVal > ::Wiz::R64::MaxOneEp;
        }

        /// LessEqualOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type LessEqualOne(const T& InVal)
        {
            return ::Wiz::Absolute::LessEqualOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessEqualOne(::Wiz::R32::Type const & InVal)
        {
            return InVal <= ::Wiz::R32::MaxOneEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type LessEqualOne(::Wiz::R64::Type const & InVal)
        {
            return InVal <= ::Wiz::R64::MaxOneEp;
        }

        /// GreaterEqualOne
        template<class T>
        WIZ_INLINE ::Wiz::Bool::Type GreaterEqualOne(const T& InVal)
        {
            return ::Wiz::Absolute::GreaterEqualOne<T>(InVal);
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterEqualOne(::Wiz::R32::Type const & InVal)
        {
            return InVal >= ::Wiz::R32::MinOneEp;
        }

        template<>
        WIZ_INLINE::Wiz::Bool::Type GreaterEqualOne(::Wiz::R64::Type const & InVal)
        {
            return InVal >= ::Wiz::R64::MinOneEp;
        }
    } /// end of namespace Nearly

} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TEMPLATE_ONE_HPP__SHANHAOBO_19800429__*/
