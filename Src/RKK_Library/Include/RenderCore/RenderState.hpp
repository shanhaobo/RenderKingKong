#ifndef __RENDERKINGKONG_RENDERSTATE_HPP__
#define __RENDERKINGKONG_RENDERSTATE_HPP__

#include "../Core/Core.hpp"

namespace rkk
{
    namespace RenderState
    {
        RKK_CLASS
        {
        public:
            type() : m_KeepLastSetting(Bool::True)
            {

            }
            type(in inOther);
            ~type();

            Bool::type  m_KeepLastSetting;
        };
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_HPP__
