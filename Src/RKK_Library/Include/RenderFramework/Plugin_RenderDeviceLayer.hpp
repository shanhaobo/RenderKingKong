#ifndef __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__
#define __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__

#include "../Base/Base.hpp"

#include "./Plugin.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            RKK_CLASS : public Plugin::type
            {
            public:
                typedef Plugin::type tSuper;

            public:
                type()
                {

                }

            public:
                virtual Bool::type Register(Root::ptr, Name::in InName);
                virtual Void::type Unregister();

            public:
                virtual Bool::type Active();
                virtual Void::type Deactive();

            protected:
                virtual ::rkk::RenderDeviceLayer::ptr CreateRDL() = 0;
                virtual Void::type DestroyRDL(::rkk::RenderDeviceLayer::ptr) = 0;

            protected:
                friend class Renderer::type;

                Renderer::ptr                   m_RendererPtr;
                ::rkk::RenderDeviceLayer::ptr   m_RDLPtr;
            };
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk

#endif /// __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__
