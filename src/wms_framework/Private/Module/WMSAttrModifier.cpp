#include "../../Include/Module/WMSAttrModifier.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            /// 创建LAYER
            type::tRequestLayerPtr type::FindOrCreateRequestLayer(ID32::in inLayerID)
            {
                tRequestList::tSize i;

                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    if (m_RequestList[i].LayerID == inLayerID)
                    {
                        return m_RequestList[i].LayerPtr;
                    }
                }

                ///未找到
                tRequestLayerPtr tResultPtr = WMS_NEW_T(tRequestLayer, EWMS_OBJ_CAT::eWOC_General);
                if (::Wiz::IsValidPtr(tResultPtr))
                {
                    m_RequestList.PushBack(tRequestLayerItem(inLayerID, tResultPtr));
                    if (m_RequestList.Size() >= 2)
                    {
                        tRequestLayer::tSize const tLastIdx = m_RequestList.Size() - 1;

                        /// 从倒数第二个开始查找,与倒数第一个(inLayerID, tResultPtr)比较
                        for (i = tLastIdx - 1; i >= 0; ++i)
                        {
                            if (m_RequestList[i].LayerID > inLayerID)
                            {
                                m_RequestList[i + 1].LayerID  = m_RequestList[i].LayerID;
                                m_RequestList[i + 1].LayerPtr = m_RequestList[i].LayerPtr;

                                m_RequestList[i].LayerID      = inLayerID;
                                m_RequestList[i].LayerPtr     = tResultPtr;
                            }
                        }
                    }
                }

                return tResultPtr;
            }

            ID32::type type::ReceiveRequest(Attr::MdfyRqst::ptr inNewReqPtr)
            {
                tRequestLayerPtr tArrayPtr = FindOrCreateRequestLayer(inNewReqPtr->m_LayerID);
                if (::Wiz::IsValidPtr(tArrayPtr))
                {
                    tArrayPtr->PushBack(inNewReqPtr);
                    inNewReqPtr->m_ID = m_RequestID++;
                    return inNewReqPtr->m_ID;
                }

                return ID32::Invalid;
            }


            Void::type type::RemoveRequest(ID32::in inReqID)
            {
                tRequestList::tSize     i, j;
                tRequestLayerPtr        tLayerPtr;

                for (i = 0; i < m_RequestList.Size(); ++i)
                {
                    tLayerPtr = m_RequestList[i].LayerPtr;
                    if (::Wiz::IsValidPtr(tLayerPtr))
                    {
                        for (j = 0; j < tLayerPtr->Size(); ++j)
                        {
                            Attr::MdfyRqst::ptr tReqPtr = (*tLayerPtr)[j];
                            if (::Wiz::IsValidPtr(tReqPtr) && (tReqPtr->m_ID == inReqID))
                            {
                                tRequestLayer::tSize const tReqLastIdx = tLayerPtr->Size() - 1;
                                if (tReqLastIdx == 0)
                                {
                                    tLayerPtr->Clear();
                                }
                                else
                                {
                                    if (j < tReqLastIdx)
                                    {
                                        (*tLayerPtr)[j] = (*tLayerPtr)[tReqLastIdx];
                                    }

                                    tLayerPtr->PopBack();
                                }
                                return;
                            }
                        }
                    }
                }
            }

            Void::type type::RemoveRequest(tRequestLayerPtr inLayerPtr, Attr::MdfyRqst::ptr inReqPtr)
            {
                if (inLayerPtr->Size() >= 1)
                {
                    tRequestLayer::tSize const tReqLastIdx  = inLayerPtr->Size() - 1;

                    tRequestLayer::tSize tIdx = 0;
                    for (; tIdx < tReqLastIdx; ++tIdx)
                    {
                        Attr::MdfyRqst::ptr tReqPtr = (*inLayerPtr)[tIdx];
                        if (inReqPtr == tReqPtr)
                        {
                            (*inLayerPtr)[tIdx] = (*inLayerPtr)[tReqLastIdx];
                            break;
                        }
                    }

                    if ((tIdx < tReqLastIdx) || (inReqPtr == (*inLayerPtr)[tReqLastIdx]))
                    {
                        inLayerPtr->PopBack();
                    }
                }
            }
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms
