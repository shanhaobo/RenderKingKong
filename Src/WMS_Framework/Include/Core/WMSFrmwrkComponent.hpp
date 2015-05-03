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
            typedef Set<::wms::Cmpnt::ptr>::type tSet;

        public:
            tSet        m_Children;
        };

    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
