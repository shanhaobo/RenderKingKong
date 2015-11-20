#ifndef __WHIMSY_ATTRIBUTE_HPP__ 
#define __WHIMSY_ATTRIBUTE_HPP__

#include "../Core/WMSFrmwrkComponent.hpp"
#include "./WMSAttrModifier.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        WMS_CLASS : public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type                  tSuper;

            typedef Array<Attr::Modifier::ptr>::type    tModifierArray;

        public:
            type();
            virtual ~type();
            virtual Void::type  Tick(F32::in inDeltaTime);

            Void::type          RemoveModifier(U32::in inModifierID);
            Void::type          UpdateModifier();

            virtual U32::type   CreateModifier() = 0;

        protected:
            U32::type           AddModifier(::wms::Attr::Modifier::ptr inModifier);

        protected:
            tModifierArray      m_ModifierList;

            U32::type           m_ModifierID;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
