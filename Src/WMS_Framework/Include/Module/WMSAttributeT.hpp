#ifndef __WHIMSY_ATTRIBUTE_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrModifierT.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        template<class T>
        class Type : public Attr::type
        {
        protected:
            typedef T                               tValue;
            typedef tValue &                        tValueRef;
            typedef tValueRef                       tValueOut;
            typedef tValueRef const                 tValueIn;

            typedef Attr::Modifier::Type<T>         tModifier;
            typedef tModifier*                      tModifierPtr;

            tValue                  BaseValue;
        public:
            virtual Void::type Calc(F32::in inDeltaTime)
            {
                tModifierPtr lMoidifierPtr = (tModifierPtr)(m_MoidifierPtr);
                if (::Wiz::IsValidPtr(lMoidifierPtr))
                {
                    lMoidifierPtr->Calc(inDeltaTime, BaseValue, BaseValue);
                }
            }
        };

        template<class T>
        class Type2 : public Attr::Type<T>
        {
        protected:
            tValue                  CurrValue;

        public:
            virtual Void::type Calc(F32::in inDeltaTime)
            {
                tModifierPtr lMoidifierPtr = (tModifierPtr)(m_MoidifierPtr);
                if (::Wiz::IsValidPtr(lMoidifierPtr))
                {
                    lMoidifierPtr->Calc(inDeltaTime, BaseValue, CurrValue);
                }
            }
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_T_HPP__
