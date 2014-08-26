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

        public:
            Bool::type RegisterRDL(Name::in, Plugin::RenderDeviceLayer::ptr);
            Void::type UnregisterRDL(Name::in);

            Bool::type ActiveRDL(Name::in);
            Void::type DeactiveRDL(Name::in);
            Void::type DeactiveRDL(Plugin::RenderDeviceLayer::ptr);

            /// RDL
        protected:
            typedef Map<Name::type, Plugin::RenderDeviceLayer::ptr>::type tMapRDLPlugin;
            tMapRDLPlugin           m_mapRDLPlugin;

            Name::type                      m_ActivedRDLName;
            RenderDeviceLayer::ptr          m_ActivedRDLPtr;
        };
    } /// namespace Renderer
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERER_HPP__
