#ifndef __RENDERKINGKONG_PLUGIN_HPP__
#define __RENDERKINGKONG_PLUGIN_HPP__


#include "../Base/RKKPrerequisites.hpp"

#include "../Base/BaseType.hpp"


namespace rkk
{
    namespace Plugin
    {
        class type
        {
        public:
            type()
            {
            }

        public:
            virtual Bool::type Register(Root::ptr, Name::in);
            virtual Bool::type Unregister() = 0;

        public:
            virtual Bool::type Active() = 0;
            virtual Bool::type Deactive() = 0;

        protected:
            Root::ptr    m_RootPtr;
        };
    } /// namespace Plugin
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_PLUGIN_HPP__
