#ifndef __WHIMSY_ATTRMODULE_HPP__ 
#define __WHIMSY_ATTRMODULE_HPP__

#include "./WMSAttribute.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace AttrModule
    {
        WMS_CLASS: public ::wms::CmpntArray::type
        {
        private:
            typedef ::wms::CmpntArray::type tSuper;

        public:
            type();
            type(::wms::Size::in);
            virtual ~type();

        public:
            Attr::ptr GetAttrByIdx(::wms::Size::in inIdx);
        };
    } /// end of namespace AttrModule
} /// end of namespace wms

#endif /// __WHIMSY_ATTRMODULE_HPP__
