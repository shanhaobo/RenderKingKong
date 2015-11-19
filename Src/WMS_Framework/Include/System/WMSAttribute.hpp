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
            typedef ::wms::Cmpnt::type tSuper;

        public:
            type();
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

            typedef Array<::wms::Attr::Modifier::ptr>::type tModifierArray;

            ::wms::Void::type AddModfier(::wms::Attr::Modifier::ptr inModifier);
            ::wms::Void::type RemoveModifer(::wms::Attr::Modifier::ptr inModifier);
			::wms::Void::type UpdateModifer();

        protected:
            tModifierArray        m_ModfierList;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
