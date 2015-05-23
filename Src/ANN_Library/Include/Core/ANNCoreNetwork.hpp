#ifndef __ANN_CORE_NETWORK_HPP__ 
#define __ANN_CORE_NETWORK_HPP__

#include "ANNCoreNeuron.hpp"

namespace ann
{
    namespace Network
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::wms::Obj::ANN::type
        {
        protected:
            typedef IOT                                     tIO;
            typedef typename ::wms::Array<tIO>::type        tIOList;
            typedef tIOList &                               tIOListRef;
            typedef tIOListRef const                        tIOListIn;
            typedef tIOList *                               tIOListPtr;
            typedef tIOList const *                         tIOListPtrC;

            typedef WeightT                                 tWeight;

            typedef ::wms::InitList<::wms::U::type>::type   tInitList;
            typedef typename tInitList::iterator            tInitListItr;

            typedef ::ann::Layer::type<tIO, tWeight>        tLayer;
            typedef tLayer &                                tLayerRef;
            typedef tLayer *                                tLayerPtr;
            typedef tLayer const * const                    tLayerPtrFC;

            typedef typename ::wms::Array<tLayerPtr>::type  tLayerList;

        public:
            /// 初始化输入层的输入数量
            type(tInitList inInitList) : m_InputCnt(-1)
            {
                m_LayerList.Clear();

                AppendLayers(inInitList);
            }

            virtual ~type()
            {
                ::wms::I::typec lLayerCnt = m_LayerList.Size();

                for (::wms::I::type i = 0; i < lLayerCnt; ++i)
                {
                    DestroyLayer(m_LayerList[i]);
                }

                m_LayerList.Clear();
            }

        protected:
            ::wms::Void::type AppendLayers(tInitList inInitList)
            {
                for (tInitListItr tItr = inInitList.begin(); tItr != inInitList.end(); ++tItr)
                {
                    AppendNewLayer(*tItr);
                }
            }

        public:
            tLayerPtr AppendNewLayer(::wms::U::in inNeuronCnt)
            {
                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                
                tLayerPtr lLayerPtr = WMS_NULLPTR;
                if (lLayerCnt > 0)
                {
                    tLayerPtrFC lPrevLayerPtr = m_LayerList[lLayerCnt - 1];
                    if (::Wiz::IsValidPtr(lPrevLayerPtr))
                    {
                        lLayerPtr = CreateLayer(inNeuronCnt, lPrevLayerPtr->NeuronCnt());
                    }
                }
                else if (lLayerCnt == 0)
                {
                    if (m_InputCnt < 0)
                    {
                        m_InputCnt = inNeuronCnt;
                    }
                    else
                    {
                        lLayerPtr = CreateLayer(inNeuronCnt, m_InputCnt);
                    }
                }

                if (::Wiz::IsValidPtr(lLayerPtr))
                {
                    m_LayerList.PushBack(lLayerPtr);

                    return lLayerPtr;
                }

                return WMS_NULLPTR;
            }

        public:
            virtual ::wms::Void::type Update(tIOListIn inInputDatum)
            {
                tIOListPtr lPrevLayerIOListPtr = &inInputDatum;

                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                for (::wms::U::type i = 0; i < lLayerCnt; ++i)
                {
                    /// Travel all of layers, The last layer's output  AS current layer's input.
                    lPrevLayerIOListPtr = &(m_LayerList[i]->Update(*lPrevLayerIOListPtr));
                }
            }

        public:
            virtual tLayerPtr CreateLayer(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) const = WIZ_NULL;
            virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const = WIZ_NULL;

        protected:
            ::wms::I::type      m_InputCnt;

            tLayerList          m_LayerList;
        };
    } /// end of namespace Network
} /// end of namespace ann

#endif /// __ANN_CORE_NETWORK_HPP__
