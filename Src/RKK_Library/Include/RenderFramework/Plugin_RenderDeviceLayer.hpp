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
                virtual Bool::type Unregister();

            public:
                virtual Bool::type Active();
                virtual Bool::type Deactive();

            protected:
                virtual RenderDeviceLayer::ptr CreateRDL() = 0;
                virtual Bool::type DestroyRDL() = 0;

            protected:
                RenderDeviceLayer::ptr m_RDLPtr;
            };
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk

#endif /// __RENDERKINGKONG_PLUGIN_RENDERDEVICELAYER_HPP__
