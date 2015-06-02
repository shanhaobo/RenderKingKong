#ifndef __WHIMSY_ATTRSYSTEM_HPP__ 
#define __WHIMSY_ATTRSYSTEM_HPP__

#include "./WMSAttribute.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace AttrSystem
    {
        WMS_CLASS: public ::wms::CmpntArray::type
        {
        private:
            typedef ::wms::CmpntArray::type tSuper;

        public:
            type();
            type(::wms::Size::in);
            virtual ~type();
        };
    } /// end of namespace AttrSystem
} /// end of namespace wms

#endif /// __WHIMSY_ATTRSYSTEM_HPP__
