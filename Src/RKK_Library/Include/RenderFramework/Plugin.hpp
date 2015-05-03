#ifndef __RENDERKINGKONG_PLUGIN_HPP__
#define __RENDERKINGKONG_PLUGIN_HPP__

#include "RKKFrameworkFwdDclr.hpp"

namespace rkk
{
    namespace Plugin
    {
        WMS_CLASS : public ::wms::Obj::Plugin::type
        {
        public:
            type()
            {
            }

        public:
            virtual ::wms::Bool::type Register(Root::ptr, ::wms::Name::in);
            virtual ::wms::Void::type Unregister() = 0;

        public:
            virtual ::wms::Bool::type Active() = 0;
            virtual ::wms::Void::type Deactive() = 0;

        protected:
            Root::ptr           m_RootPtr;

            ::wms::Name::type   m_PluginName;
        };
    } /// namespace Plugin
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_PLUGIN_HPP__
