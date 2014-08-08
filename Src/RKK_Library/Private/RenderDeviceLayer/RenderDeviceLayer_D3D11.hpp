#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__

#include "../../Include/RenderDeviceLayer/RenderDeviceLayer.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        namespace D3D11
        {
            ///////////////////////////
            ///////////////////////////

            class type : public RenderDeviceLayer::type
            {
            public:
                type();
                virtual ~type();

            public:
#               undef RKK_RDL_METHOD
#               define RKK_RDL_METHOD(MPName, MPRet, MPParam)          virtual MPRet MPName MPParam
#                   include "../../Include/RenderDeviceLayer/RenderDeviceLayerMethod.hpp"
#               undef RKK_RDL_METHOD
            };
            RKK_DECLARE(type);

            ///////////////////////////
            ///////////////////////////
        } /// end of namespace D3D11
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_D3D11_HPP__
