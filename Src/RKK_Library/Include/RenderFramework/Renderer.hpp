#ifndef __RENDERKINGKONG_RENDERER_HPP__
#define __RENDERKINGKONG_RENDERER_HPP__

#include "../RenderDeviceLayer/RenderDeviceLayer.hpp"

#include "./Plugin_RenderDeviceLayer.hpp"

#include "./RenderFlow.hpp"

namespace rkk
{
    namespace Renderer
    {
        RKK_CLASS
        {
        public:
            type();
            ~type();


            typedef Map<Name::type, Plugin::RenderDeviceLayer::ptr>::type tMapRDLPlugin;
            tMapRDLPlugin           m_mapRDLPlugin;

            RenderDeviceLayer::ptr m_RDLPtr;
        };
    } /// namespace Renderer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERER_HPP__
