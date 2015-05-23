#ifndef __ANN_CORE_NEURON_HPP__ 
#define __ANN_CORE_NEURON_HPP__

#include "./ANNCoreFwdDclr.hpp"

namespace ann
{
    namespace Neuron
    {
        template <class IOT, class WeightT = ::wms::F64::type>
        class type : public ::wms::Obj::ANN::type
        {
        protected:
            typedef IOT                                     tIO;
            typedef tIO &                                   tIORef;
            typedef tIORef                                  tOut;

            typedef typename ::wms::Array<tIO>::type        tInputList;
            typedef tInputList &                            tInputListRef;
            typedef tInputListRef const                     tInputListIn;

            typedef WeightT                                 tWeight;
            typedef typename ::wms::Array<tWeight>::type    tWeightList;

        public:
            type(::wms::I::in inInputNum) : m_WeightList(inInputNum)
            {
            }

            virtual ~type()
            {
            }

        public:
            virtual ::wms::Void::type Update(tOut outOutput, tInputListIn inInputList) = WIZ_NULL;

        protected:
            type() : m_WeightList(0)
            {
            }

            tWeightList         m_WeightList;
        };
    } /// end of namespace Neuron
} /// end of namespace ann

#endif /// __ANN_CORE_NEURON_HPP__
