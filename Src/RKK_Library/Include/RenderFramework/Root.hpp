#ifndef __RENDERKINGKONG_ROOT_HPP__
#define __RENDERKINGKONG_ROOT_HPP__

#include "./Renderer.hpp"

namespace rkk
{
    namespace Root
    {
        RKK_CLASS
        {
        public:
            type(){}

        public:
            Bool::type LoadPlugin(Str::in InPluginFileName, Name::in InPluginName);
            Void::type UnloadPlugin(Name::in InPluginName);

        public:
            Bool::type ActivePlugin(Name::in InRDLName);

        protected:
            Plugin::ptr GetPlugin(Name::in InPluginName);

            typedef Map<Name::type, Plugin::ptr>::type tMapPlugin;
            tMapPlugin  m_mapPlugin;

        protected:
            friend class Plugin::RenderDeviceLayer::type;
            ::rkk::Renderer::ptr m_RendererPtr;
        };

        WIZ_SINGLETON_DECLARE(::rkk::Root::type);
    } /// namespace Root
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_ROOT_HPP__
