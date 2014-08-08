#ifndef __RENDERKINGKONG_RENDERER_HPP__
#define __RENDERKINGKONG_RENDERER_HPP__

#include "../RenderDeviceLayer/RenderDeviceLayer.hpp"

#include "RenderFlow.hpp"

namespace rkk
{
    namespace Renderer
    {
        class type
        {
        public:
            type();
            ~type();

            ::rkk::RenderDeviceLayer::ptr m_RDLPtr;
        };
        RKK_DECLARE(type);
    } /// namespace Renderer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERER_HPP__
