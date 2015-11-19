#ifndef __WHIMSY_ATTRIBUTE_MODIFIER_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODIFIER_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            WMS_CLASS
            {
            public:
                virtual ::wms::Bool::type operator==(in inOther) const = 0;

                WIZ_INLINE ::wms::Bool::type operator!=(in inOther) const
                {
                    return operator==(inOther) == false;
                }
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_HPP__
