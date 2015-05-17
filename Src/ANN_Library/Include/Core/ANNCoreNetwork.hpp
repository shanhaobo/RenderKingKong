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

            typedef ::ann::Layer::type<tIO, tWeight>        tLayer;
            typedef tLayer &                                tLayerRef;
            typedef tLayer *                                tLayerPtr;
            typedef tLayer const * const                    tLayerPtrFC;

            typedef typename ::wms::Array<tLayerPtr>::type  tLayerList;

        public:
            /// 初始化输入层的输入数量
            type(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) : m_InputCnt(inInputCnt)
            {
                m_LayerList.Clear();

                tLayerPtr lLayerPtr = AddNewLayer(inNeuronCnt);
                if (::Wiz::IsValidPtr(lLayerPtr))
                {
                    m_LayerList.PushBack(lLayerPtr);
                }
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

        public:
            tLayerPtr AddNewLayer(::wms::I::in inNeuronCnt)
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
                    lLayerPtr = CreateLayer(inNeuronCnt, m_InputCnt);
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
                tIOListPtrC lPrevLayerIOListPtr = &inInputDatum;

                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                for (::wms::I::type i = 0; i < lLayerCnt; ++i)
                {
                    /// Travel all of layers, Output of last layer AS input of current layer.
                    lPrevLayerIOListPtr = &(m_LayerList[i].Update(*lPrevLayerIOListPtr));
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
