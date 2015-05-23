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
            type(tInitList inInitList) : m_InputCnt(0), m_InitList(inInitList)
            {
                m_LayerList.Clear();
            }

            virtual ~type()
            {
            }

        public:
            ::wms::Bool::type Initialize()
            {
                InitLayers(m_InitList);

                return ::wms::Bool::True;
            }

            ::wms::Void::type Finalize()
            {
                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
                for (::wms::U::type i = 0; i < lLayerCnt; ++i)
                {
                    tLayerPtr lLayerPtr = m_LayerList[i];
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        lLayerPtr->Finalize();
                        DestroyLayer(m_LayerList[i]);
                    }
                }

                m_LayerList.Clear();
            }

        protected:
            ::wms::Void::type InitLayers(tInitList inInitList)
            {
                for (tInitListItr tItr = inInitList.begin(); tItr != inInitList.end(); ++tItr)
                {
                    tLayerPtr lLayerPtr = AppendNewLayer(*tItr);
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        lLayerPtr->Initialize();
                    }
                }
            }

            tLayerPtr AppendNewLayer(::wms::U::in inNeuronCnt)
            {
                if (inNeuronCnt == 0)
                {
                    return WMS_NULLPTR;
                }

                tLayerPtr lLayerPtr = WMS_NULLPTR;

                ::wms::Size::typec lLayerCnt = m_LayerList.Size();
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
                    if (m_InputCnt == 0)
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
                    tLayerPtr lLayerPtr = m_LayerList[i];
                    if (::Wiz::IsValidPtr(lLayerPtr))
                    {
                        /// Travel all of layers, The last layer's output  AS current layer's input.
                        lPrevLayerIOListPtr = &(lLayerPtr->Update(*lPrevLayerIOListPtr));
                    }
                }
            }

        public:
            virtual tLayerPtr CreateLayer(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) const = WIZ_NULL;
            virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const = WIZ_NULL;

        protected:
            ::wms::U::type      m_InputCnt;

            tLayerList          m_LayerList;

            tInitList           m_InitList;
        };
    } /// end of namespace Network
} /// end of namespace ann

#endif /// __ANN_CORE_NETWORK_HPP__
