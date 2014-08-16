#ifndef __RENDERKINGKONG_RENDERER_HPP__
#define __RENDERKINGKONG_RENDERER_HPP__

#include "../RenderDeviceLayer/RenderDeviceLayer.hpp"

#include "RenderFlow.hpp"

namespace rkk
{
    namespace Renderer
    {
        RKK_CLASS
        {
        public:
            type();
            ~type();

            ::rkk::RenderDeviceLayer::ptr m_RDLPtr;
        };
    } /// namespace Renderer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERER_HPP__
