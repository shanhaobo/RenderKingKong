#ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
#define __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__

#include "RenderStateContent.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Manager
        {
            class type
            {
            public:
                type();
                ~type();

            public:
                Bool::type Update();

            public:
                Content::type           m_Content;
            protected:
                Content::Working::type  m_WorkingContent;
            };
            RKK_DECLARE(type);
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
