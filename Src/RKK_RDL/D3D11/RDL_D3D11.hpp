#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__

#include "../../RKK_Library/include/RenderDeviceLayer/RenderDeviceLayer.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            ///////////////////////////
            ///////////////////////////
            WMS_CLASS : public RenderDeviceLayer::type
            {
            public:
                type();
                virtual ~type();

            public:
#               undef RKK_RDL_METHOD
#               define RKK_RDL_METHOD(MPRet, MPName, MPParam)          virtual MPRet MPName MPParam
#                   include "../../RKK_Library/include/RenderDeviceLayer/RenderDeviceLayerMethod.hpp"
#               undef RKK_RDL_METHOD
            };
            ///////////////////////////
            ///////////////////////////
        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__
