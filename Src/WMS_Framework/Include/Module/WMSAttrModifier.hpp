#ifndef __WHIMSY_ATTRIBUTE_MODIFIER_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODIFIER_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrMdfyRqst.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            WMS_CLASS
            {
            protected:
                typedef Array<Attr::MdfyRqst::ptr>::type    tRequestArray;
                typedef tRequestArray*                      tRequestArrayPtr;

                struct tRequestListItem
                {
                    U32::type           LayerID;
                    tRequestArrayPtr    ArrayPtr;

                    tRequestListItem(U32::in inLayerID, tRequestArrayPtr inArrayPtr) : LayerID(inLayerID), ArrayPtr(inArrayPtr)
                    {

                    }
                };
                typedef Array<tRequestListItem>::type       tRequestList;

            public:
                ::wms::Void::type ReceiveRequest(Attr::MdfyRqst::ptr);

            protected:
                tRequestArrayPtr FindOrCreateRequestArray(U32::in inID);

            public:
                virtual ::wms::Bool::type operator==(in inOther) const = 0;

                WIZ_INLINE ::wms::Bool::type operator!=(in inOther) const
                {
                    return operator==(inOther) == false;
                }

            protected:
                tRequestList                m_RequestList;

                ID32::type                  m_RequestID;
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_HPP__
