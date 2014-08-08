#ifndef __RENDERKINGKONG_RENDERDEVICELAYER_HPP__
#define __RENDERKINGKONG_RENDERDEVICELAYER_HPP__

#include "../Core/Core.hpp"
#include "../RenderCore/RenderCore.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        ///////////////////////////
        ///////////////////////////

        class type
        {
        public:
            type();
            virtual ~type();

        public:
#           undef RKK_RDL_METHOD
#           define RKK_RDL_METHOD(MPName, MPRet, MPParam)     virtual MPRet MPName MPParam = 0
#               include "RenderDeviceLayerMethod.hpp"
#           undef RKK_RDL_METHOD
        };
        RKK_DECLARE_PTR(type);

        ///////////////////////////
        ///////////////////////////

        ptr Create();

        Void::type Destroy(ptr);

        ///////////////////////////
        ///////////////////////////
    } /// namespace RenderDeviceLayer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERDEVICELAYER_HPP__
