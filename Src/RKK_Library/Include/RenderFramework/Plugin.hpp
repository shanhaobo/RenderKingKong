#ifndef __RENDERKINGKONG_PLUGIN_HPP__
#define __RENDERKINGKONG_PLUGIN_HPP__

#include "../Base/Base.hpp"

namespace rkk
{
    namespace Plugin
    {
        RKK_CLASS : public Obj::Plugin::type
        {
        public:
            type()
            {
            }

        public:
            virtual Bool::type Register(Root::ptr, Name::in);
            virtual Void::type Unregister() = 0;

        public:
            virtual Bool::type Active() = 0;
            virtual Void::type Deactive() = 0;

        protected:
            Root::ptr   m_RootPtr;

            Name::type  m_PluginName;
        };
    } /// namespace Plugin
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_PLUGIN_HPP__
