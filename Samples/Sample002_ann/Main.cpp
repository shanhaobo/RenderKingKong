#include "../SampleBase.hpp"

struct NullANN : public ::ann::Network::type<::wms::F32::type, ::wms::F64::type>
{
    typedef ::ann::Network::type<::wms::F32::type, ::wms::F64::type> tBase;

    NullANN(tInitList inInitList) : tBase(inInitList)
    {
    }

    virtual tLayerPtr CreateLayer(::wms::I::in inNeuronCnt, ::wms::I::in inInputCnt) const
    {
        return WIZ_NULL;
    }
    virtual ::wms::Void::type DestroyLayer(tLayerPtr inLayerPtr) const
    {
        WIZ_DEL inLayerPtr;
    }
};

void CreateNULLANN()
{
    NullANN lNetwork({ 5, 3, 4 });
    lNetwork.Initialize();
    lNetwork.Finalize();

    NullANN lNetwork2 = { 5, 3, 4 };
    lNetwork2.Initialize();
    lNetwork2.Finalize();
}

int _tmain(int argc, _TCHAR* argv[])
{
    CreateNULLANN();

    return 0;
}

