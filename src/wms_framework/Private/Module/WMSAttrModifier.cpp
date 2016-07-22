#include "../../Include/Module/WMSAttrModifier.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            type::tRequestArrayPtr type::FindOrCreateRequestArray(U32::in inLayerID)
            {
                tRequestArray::tSize i;

                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    if (m_RequestList[i].LayerID == inLayerID)
                    {
                        return m_RequestList[i].ArrayPtr;
                    }
                }

                ///未找到
                tRequestArrayPtr tResultPtr = WMS_NEW_T(tRequestArray, EWMS_OBJ_CAT::eWOC_General);
                if (::Wiz::IsValidPtr(tResultPtr))
                {
                    m_RequestList.PushBack(tRequestListItem(inLayerID, tResultPtr));
                    if (m_RequestList.Size() >= 2)
                    {
                        tRequestArray::tSize const tLastIdx = m_RequestList.Size() - 1;

                        /// 从倒数第二个开始查找,与倒数第一个(inLayerID, tResultPtr)比较
                        for (i = tLastIdx - 1; i >= 0; ++i)
                        {
                            if (m_RequestList[i].LayerID > inLayerID)
                            {
                                m_RequestList[i + 1].LayerID  = m_RequestList[i].LayerID;
                                m_RequestList[i + 1].ArrayPtr = m_RequestList[i].ArrayPtr;

                                m_RequestList[i].LayerID      = inLayerID;
                                m_RequestList[i].ArrayPtr     = tResultPtr;
                            }
                        }
                    }
                }

                return tResultPtr;
            }

            ::wms::Void::type type::ReceiveRequest(Attr::MdfyRqst::ptr inNewReqPtr)
            {
                tRequestArrayPtr tArrayPtr = FindOrCreateRequestArray(inNewReqPtr->m_LayerID);
                if (::Wiz::IsValidPtr(tArrayPtr))
                {
                    tArrayPtr->PushBack(inNewReqPtr);
                    inNewReqPtr->m_ID = m_RequestID++;
                }
            }
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms
