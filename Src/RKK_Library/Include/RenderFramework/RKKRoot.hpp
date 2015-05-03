#ifndef __RENDERKINGKONG_ROOT_HPP__
#define __RENDERKINGKONG_ROOT_HPP__

#include "./RKKRenderer.hpp"

namespace rkk
{
    namespace Root
    {
        class type
        {
        public:
            type(){}

        public:
            ::wms::Bool::type LoadPlugin(::wms::Str::in inPluginFileName, ::wms::Name::in inPluginName);
            ::wms::Void::type UnloadPlugin(::wms::Name::in inPluginName);

        public:
            ::wms::Bool::type ActivePlugin(::wms::Name::in inRDLName);

        protected:
            Plugin::ptr GetPlugin(::wms::Name::in inPluginName);

            typedef ::wms::Map<::wms::Name::type, Plugin::ptr>::type tMapPlugin;
            tMapPlugin  m_mapPlugin;

        protected:
            friend class Plugin::RenderDeviceLayer::type;
            ::rkk::Renderer::ptr m_RendererPtr;
        };

        WIZ_SINGLETON_DECLARE(::rkk::Root::type);
    } /// namespace Root
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_ROOT_HPP__
