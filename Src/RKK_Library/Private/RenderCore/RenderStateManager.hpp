#ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
#define __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__

#include "../../Include/RenderCore/RenderState.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Manager
        {
            RKK_CLASS
            {
            public:
                type();
                ~type();

            public:
                Bool::type Update(RenderState::in inNewState);

            protected:
                RenderState::type           m_WorkingState;
            };
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_MANAGER_HPP__
