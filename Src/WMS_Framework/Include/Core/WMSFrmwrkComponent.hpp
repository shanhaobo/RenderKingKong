#ifndef __WHIMSY_FRAMEWORK_COMPONENT_HPP__ 
#define __WHIMSY_FRAMEWORK_COMPONENT_HPP__

#include "./WMSFrmwrkFwdDclr.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Cmpnt
    {
        WMS_CLASS : public ::wms::Obj::Cmpnt::type
        {
        public:
            type();
            virtual ~type();

        public:
            virtual Void::type Tick(F32::in inDeltaTime);

        public:
            typedef Map<::wms::Name::type, ::wms::Cmpnt::ptr>::type tMap;

        public:
            tMap        m_Children;
        };

    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
