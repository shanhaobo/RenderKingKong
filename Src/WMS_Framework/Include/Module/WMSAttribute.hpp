#ifndef __WHIMSY_ATTRIBUTE_HPP__ 
#define __WHIMSY_ATTRIBUTE_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
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


        public:
            type();
            virtual ~type();
            virtual Void::type  Tick(F32::in inDeltaTime);

        protected:
            Attr::Modifier::ptr m_MoidifierPtr;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
