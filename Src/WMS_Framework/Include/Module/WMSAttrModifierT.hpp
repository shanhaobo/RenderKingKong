#ifndef __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrModifier.hpp"
#include "./WMSAttrMdfyRqstT.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            template<class T>
            class Type : public Modifier::type
            {
            protected:
                typedef T                               tValue;
                typedef tValue &                        tValueRef;
                typedef tValueRef                       tValueOut;
                typedef tValueRef const                 tValueIn;

                typedef Attr::MdfyRqst::Type<tValue>    tMdfyRqst;
                typedef tMdfyRqst*                      tMdfyRqstPtr;

            protected:
                virtual Bool::type CheckBreak(tValueIn inCurrValue) = 0;

            protected:
                Void::type CalcCurrLayer(tValueOut ioValue, F32::in inDeltaTime, tRequestLayerPtr inLayerPtr, tValueIn inLastBaseVal)
                {
                    if (::Wiz::IsValidPtr(inLayerPtr))
                    {
                        tRequestLayer::tSize i;
                        for (i = 0; i < inLayerPtr->Size(); ++i)
                        {
                            tMdfyRqstPtr lReqPtr = (tMdfyRqstPtr)((*inLayerPtr)[i]);
                            if (::Wiz::IsValidPtr(lReqPtr))
                            {
                                lReqPtr->Calc(ioValue, inDeltaTime, inLastBaseVal);
                                if (CheckBreak(ioValue))
                                {
                                    lReqPtr->BreakCallBack();
                                    break;
                                }
                            }
                        }
                    }
                }

            public:
                tValue Calc(F32::in inDeltaTime, tValueIn inBaseVal, tValueIn inCurrVal)
                {
                    tRequestList::tSize i;

                    tValue              lBaseVal   = inBaseVal;
                    tValue              lResultVal = inCurrVal;

                    for (i = 0; i < m_RequestList.Size(); ++i)
                    {
                        CalcCurrLayer(lResultVal, inDeltaTime, m_RequestList[i].LayerPtr, lBaseVal);

                        lBaseVal = lResultVal;
                    }

                    return lResultVal;
                }
            };
        } /// end of namespace Modifier
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MODIFIER_T_HPP__
