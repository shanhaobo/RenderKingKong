#ifndef __WIZ_ADV_ENUM_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_ENUM_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicTypeInt.hpp"

namespace Wiz
{
    namespace Enum
    {
        template<class EnumT, class StorageT>
        class Type
        {
        public:
            typedef EnumT       tEnum;
            typedef StorageT    tStorage;
        public:
            Type()
            {
            }
            Type(tEnum e) : m_Value(::Wiz::Cast::Static<tStorage>(e))
            {
            }
            operator tEnum() const
            {
                return this->Get();
            }
            tStorage operator=(tEnum e)
            {
                return this->m_Value = ::Wiz::Cast::Static<tStorage>(e);
            }
            ::Wiz::Bool::Type operator==(tEnum e) const
            {
                return this->m_Value == ::Wiz::Cast::Static<tStorage>(e);
            }
            ::Wiz::Bool::Type operator!=(tEnum e) const
            {
                return !this->operator==(e);
            }
            tEnum Get() const
            {
                return ::Wiz::Cast::Static<tEnum>(this->m_Value);;
            }
            //////////////////////////////////////////////////////////////////////////
            tStorage GetStorage() const
            {
                return m_Value;
            }
            ::Wiz::Void::Type SetStorage(const tStorage& InV)
            {
                m_Value = InV;
            }
        protected:
            tStorage m_Value;
        };
    } /// end of namespace Enum

    namespace Enum8
    {
        template<class EnumT>
        class Type : public ::Wiz::Enum::Type<EnumT, ::Wiz::U8::Type>
        {
            typedef EnumT       tEnum;
            typedef ::Wiz::Enum::Type<tEnum, ::Wiz::U8::Type> tSuper;
        public:
            Type()
            {}
            Type(tEnum t) : tSuper(t)
            {
            }
        }; /// end of namespace Enum8
    } /// end of namespace Enum8

    namespace Enum16
    {
        template<class EnumT>
        class Type : public ::Wiz::Enum::Type<EnumT, ::Wiz::U16::Type>
        {
            typedef EnumT       tEnum;
            typedef ::Wiz::Enum::Type<tEnum, ::Wiz::U16::Type> tSuper;
        public:
            Type()
            {}
            Type(tEnum t) : tSuper(t)
            {
            }
        }; /// end of namespace Enum16
    } /// end of namespace Enum16

    namespace Enum32
    {
        template<class EnumT>
        class Type : public ::Wiz::Enum::Type<EnumT, ::Wiz::U32::Type>
        {
            typedef EnumT       tEnum;
            typedef ::Wiz::Enum::Type<tEnum, ::Wiz::U32::Type> tSuper;
        public:
            Type()
            {}
            Type(tEnum t) : tSuper(t)
            {
            }
        }; /// end of namespace Enum32
    } /// end of namespace Enum32

    namespace Enum64
    {
        template<class EnumT>
        class Type : public ::Wiz::Enum::Type<EnumT, ::Wiz::U64::Type>
        {
            typedef EnumT       tEnum;
            typedef ::Wiz::Enum::Type<tEnum, ::Wiz::U64::Type> tSuper;
        public:
            Type()
            {}
            Type(tEnum t) : tSuper(t)
            {
            }
        }; /// end of namespace Enum64
    } /// end of namespace Enum64

} /// end of namespace Wiz

#endif /*__WIZ_ADV_ENUM_HPP__SHANHAOBO_19800429__*/
