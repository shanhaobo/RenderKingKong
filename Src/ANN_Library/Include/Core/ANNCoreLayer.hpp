#ifndef __ANN_CORE_LAYER_HPP__ 
#define __ANN_CORE_LAYER_HPP__

#include "ANNCoreNeuron.hpp"

namespace ann
{
    namespace Layer
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::wms::Obj::ANN::type
        {
        protected:
            typedef IOT                                     tIO;

            typedef typename ::wms::Array<tIO>::type        tIOList;
            typedef tIOList &                               tIOListRef;
            typedef tIOListRef const                        tIOListRefC;
            typedef tIOListRef const                        tIOListIn;
            typedef tIOListRef                              tIOListOut;
            typedef tIOListRef const                        tIOListOutC;

            typedef WeightT                                 tWeight;

            typedef ::ann::Neuron::type<tIO, tWeight>       tNeuron;
            typedef tNeuron &                               tNeuronRef;
            typedef tNeuron *                               tNeuronPtr;
            typedef tNeuronPtr const                        tNeuronPtrF;

            typedef typename ::wms::Array<tNeuronPtr>::type tNeuronList;

        public:
            type(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) : m_NeuronList(inNeuronCnt), m_OutputList(inNeuronCnt)
            {
                for (::wms::I::type i = 0; i < inNeuronCnt; ++i)
                {
                    m_NeuronList[i] = CreateNeuron(inInputCnt);
                }
            }
            virtual ~type()
            {
                ::wms::I::typec lNeuronCnt = m_NeuronList.Size();

                for (::wms::I::type i = 0; i < lNeuronCnt; ++i)
                {
                    DestroyNeuron(m_NeuronList[i]);
                }

                m_NeuronList.Clear();
            }

        public:

            virtual tIOListRefC Update(tIOListIn inInputList)
            {
                ::wms::I::typec lNeuronCnt = m_NeuronList.Size();

                for (::wms::I::type i = 0; i < lNeuronCnt; ++i)
                {
                    tNeuronPtrF lNeuronPtr = m_NeuronList[i];
                    if (::Wiz::IsValidPtr(lNeuronPtr))
                    {
                        lNeuronPtr->Update(m_OutputList[i], inInputList);
                    }
                }

                return m_OutputList;
            }

            ::wms::Size::typec NeuronCnt() const
            {
                return m_NeuronList.Size();
            }

        public:
            virtual tNeuronPtr CreateNeuron(::wms::I::in inInputCnt) const = WIZ_NULL;
            virtual ::wms::Void::type DestroyNeuron(tNeuronPtr inNeuronPtr) const = WIZ_NULL;

        protected:
            type() : m_NeuronList(0)
            {
            }

            tNeuronList         m_NeuronList;

            tIOList             m_OutputList;
        };
    } /// end of namespace Layer
} /// end of namespace ann

#endif /// __ANN_CORE_LAYER_HPP__
