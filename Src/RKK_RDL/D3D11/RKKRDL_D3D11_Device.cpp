#include "./RKKRDL_D3D11_Device.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            namespace Factory
            {
                ::wms::Bool::type Create()
                {
                    IDXGIFactory* DXGIFactoryPtr = WMS_NULLPTR;

                    ::CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&DXGIFactoryPtr);

                    Factory::init(DXGIFactoryPtr);

                    return ::wms::Bool::True;
                }
            } /// end of namespace Factory

            namespace Device
            {
                IDXGIAdapter* EnumAdapter(DXGI_ADAPTER_DESC& outAdapterDesc)
                {
                    IDXGIAdapter* EnumAdapterPtr = WMS_NULLPTR;
                    ::wms::U32::type CurrentAdapter = 0;
                    while (Factory::instance().EnumAdapters(CurrentAdapter, &EnumAdapterPtr) != DXGI_ERROR_NOT_FOUND)
                    {
                        if (::Wiz::IsValidPtr(EnumAdapterPtr))
                        {
                            if (SUCCEEDED(EnumAdapterPtr->GetDesc(&outAdapterDesc)))
                            {
                                return EnumAdapterPtr;
                            }
                        }
                    }

                    return WMS_NULLPTR;
                }

                ::wms::Bool::type Create()
                {
                    ID3D11Device* Direct3DDevicePtr = WMS_NULLPTR;

                    DXGI_ADAPTER_DESC AdapterDesc = {0};

                    ID3D11DeviceContext* ContextPtr = WMS_NULLPTR;

                    IDXGIAdapter* EnumAdapterPtr = EnumAdapter(AdapterDesc);
                    if (::Wiz::IsValidPtr(EnumAdapterPtr))
                    {
                        D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_UNKNOWN;

                        UINT DeviceFlags = 0;

                        D3D_FEATURE_LEVEL ActualFeatureLevel = (D3D_FEATURE_LEVEL)0;
                        D3D_FEATURE_LEVEL LevelsWanted[] = { D3D_FEATURE_LEVEL_11_0 };

                        ::D3D11CreateDevice(
                            EnumAdapterPtr,
                            DriverType,
                            NULL,
                            DeviceFlags,
                            LevelsWanted,
                            1,
                            D3D11_SDK_VERSION,
                            &Direct3DDevicePtr,
                            &ActualFeatureLevel,
                            &ContextPtr
                        );

                        Device::init(Direct3DDevicePtr);

                        return ::wms::Bool::True;
                    }
                    return ::wms::Bool::False;
                }
            } /// end of namespace Device

        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk
