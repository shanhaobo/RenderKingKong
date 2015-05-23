#include "../../Include/Core/ANNCoreLayer.hpp"

#include "../../Include/Core/ANNCoreNetwork.hpp"

namespace ann
{
    namespace Layer
    {
        void CreateNULLANN()
        {
            struct NullANN : public ::ann::Network::type<::wms::F32::type, ::wms::F64::type>
            {
                typedef ::ann::Network::type<::wms::F32::type, ::wms::F64::type> tBase;

                NullANN(tInitList inInitList) : tBase(inInitList){}

                virtual tLayerPtr CreateLayer(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) const{ return WIZ_NULL; }
                virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const{ }
            };

            NullANN lNetwork({ 5, 3, 4 });

            NullANN lNetwork2 = { 5, 3, 4 };
        }
    } /// end of namespace Layer
} /// end of namespace ann
