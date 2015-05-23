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
            type(::wms::U::in inNeuronCnt, ::wms::U::in inInputCnt) : m_NeuronList(inNeuronCnt), m_OutputList(inNeuronCnt), m_InputCnt(inInputCnt)
            {
            }
            virtual ~type()
            {
            }
        public:
            ::wms::Bool::type Initialize()
            {
                ::wms::Size::type lNeuronCnt = m_NeuronList.Size();
                for (::wms::U::type i = 0; i < lNeuronCnt; ++i)
                {
                    m_NeuronList[i] = CreateNeuron(m_InputCnt);
                }

                return ::wms::Bool::True;
            }

            ::wms::Void::type Finalize()
            {
                ::wms::Size::typec lNeuronCnt = m_NeuronList.Size();

                for (::wms::U::type i = 0; i < lNeuronCnt; ++i)
                {
                    DestroyNeuron(m_NeuronList[i]);
                }

                m_NeuronList.Clear();
            }
        public:

            virtual tIOListRefC Update(tIOListIn inInputList)
            {
                ::wms::U::typec lNeuronCnt = m_NeuronList.Size();

                for (::wms::U::type i = 0; i < lNeuronCnt; ++i)
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
            type() : m_NeuronList(0), m_InputCnt(0)
            {
            }

            tNeuronList         m_NeuronList;

            tIOList             m_OutputList;

            ::wms::U::type      m_InputCnt;
        };
    } /// end of namespace Layer
} /// end of namespace ann

#endif /// __ANN_CORE_LAYER_HPP__
