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
            typedef Attr::Modifier::Type<T> tModifier;
            typedef tModifier*              tModifierPtr;

        public:
            tModifierPtr                    m_MoidifierPtr;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_T_HPP__
