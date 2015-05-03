#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_HPP__

#include "../Core/RKKCore.hpp"
#include "../RenderCore/RKKRenderCore.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        ///////////////////////////
        ///////////////////////////

        class type : public ::wms::Obj::RDL::type
        {
        public:
            type();
            virtual ~type();

        public:
#           undef RKK_RDL_METHOD
#           define RKK_RDL_METHOD(MPRet, MPName, MPParam)     virtual MPRet MPName MPParam = 0
#               include "RKKRenderDeviceLayerMethod.hpp"
#           undef RKK_RDL_METHOD
        };
        WMS_DECLARE_PTR(type);

        ///////////////////////////
        ///////////////////////////

    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_HPP__
