#ifndef __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__
#define __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__

#include "../RenderDeviceLayer/RenderDeviceLayer.hpp"

#include "./Plugin.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            WMS_CLASS : public Plugin::type
            {
            public:
                typedef Plugin::type tSuper;

            public:
                type() : tSuper()
                {

                }

            public:
                virtual ::wms::Bool::type Register(Root::ptr, ::wms::Name::in inName);
                virtual ::wms::Void::type Unregister();

            public:
                virtual ::wms::Bool::type Active();
                virtual ::wms::Void::type Deactive();

            protected:
                virtual ::rkk::RenderDeviceLayer::ptr CreateRDL() = 0;
                virtual ::wms::Void::type DestroyRDL(::rkk::RenderDeviceLayer::ptr) = 0;

            protected:
                friend class Renderer::type;

                Renderer::ptr                   m_RendererPtr;
                ::rkk::RenderDeviceLayer::ptr   m_RDLPtr;
            };
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk

#endif /// __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__
