#ifndef __WHIMSY_BHVRSYSTEM_HPP__ 
#define __WHIMSY_BHVRSYSTEM_HPP__

#include "./WMSBehavior.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace BhvrSystem
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
    } /// end of namespace BhvrSystem
} /// end of namespace wms

#endif /// __WHIMSY_BHVRSYSTEM_HPP__
