#ifndef __WHIMSY_FRAMEWORK_ACTOR_HPP__ 
#define __WHIMSY_FRAMEWORK_ACTOR_HPP__

#include "./WMSFrmwrkComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Actor
    {
        WMS_CLASS : public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type tSuper;

        public:
            type();
            virtual ~type();

        public:
            virtual Void::type Tick(F32::in inDeltaTime);
        };
    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
