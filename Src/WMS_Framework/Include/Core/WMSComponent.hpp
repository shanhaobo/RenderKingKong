#ifndef __WHIMSY_FRAMEWORK_COMPONENT_HPP__ 
#define __WHIMSY_FRAMEWORK_COMPONENT_HPP__

namespace wms
{
    namespace Cmpnt
    {
        WMS_CLASS
        {
        public:
            type(){}

        public:
            typedef Set<::wms::Cmpnt::ptr>::type tSet;

        public:
            tSet        m_Children;
        };

    } /// end of namespace Cmpnt
} /// end of namespace wms

#endif /// __WHIMSY_FRAMEWORK_COMPONENT_HPP__
