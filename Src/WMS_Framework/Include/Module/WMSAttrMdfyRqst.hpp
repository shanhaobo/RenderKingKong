#ifndef __WHIMSY_ATTRIBUTE_MDFYRQST_HPP__ 
#define __WHIMSY_ATTRIBUTE_MDFYRQST_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

namespace wms
{
    namespace Attr
    {
        namespace MdfyRqst
        {
            WMS_CLASS
            {
            public:
                ID32::type      m_ID;
                ID32::type      m_LayerID;

            public:
                virtual ::wms::Bool::type Begin() = 0;
                virtual ::wms::Void::type End() = 0;
                virtual ::wms::Bool::type Update(F32::in inDeltaTime) = 0;

            public:
                virtual ::wms::Bool::type operator==(in inOther) const = 0;

                WIZ_INLINE ::wms::Bool::type operator!=(in inOther) const
                {
                    return operator==(inOther) == false;
                }
            };
        } /// end of namespace ModfyReqst
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MDFYRQST_HPP__
