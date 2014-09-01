#include "./RDL_D3D11_Device.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            namespace Device
            {
                Bool::type Create()
                {
                    ID3D11Device** Direct3DDevicePtrPtr = RKK_NULLPTR;

                    Device::Init(*Direct3DDevicePtrPtr);

                    return Bool::True;
                }
            } /// end of namespace Device

            namespace Factory
            {
                Bool::type Create()
                {
                    IDXGIFactory** DXGIFactoryPtrPtr = RKK_NULLPTR;

                    ::CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)DXGIFactoryPtrPtr);

                    Factory::Init(*DXGIFactoryPtrPtr);

                    return Bool::True;
                }
            } /// end of namespace Factory
        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk
