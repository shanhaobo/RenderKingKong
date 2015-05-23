#include "../SampleBase.hpp"

struct NullANN : public ::ann::Network::type<::wms::F32::type, ::wms::F64::type>
{
    typedef ::ann::Network::type<::wms::F32::type, ::wms::F64::type> tBase;

    NullANN(tStorage inStorage) : tBase(inStorage)
    {
    }

    virtual tLayerPtr CreateLayer(tLayerStorageIn inStorage) const
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
    NullANN::tStorage lStorage({ 5, 3, 4 });

    NullANN lNetwork(lStorage);
    lNetwork.Initialize();
    lNetwork.Finalize();

    NullANN lNetwork2 = lStorage;
    lNetwork2.Initialize();
    lNetwork2.Finalize();
}

int _tmain(int argc, _TCHAR* argv[])
{
    CreateNULLANN();

    return 0;
}

