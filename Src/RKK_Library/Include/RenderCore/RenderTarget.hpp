#ifndef __RENDERKINGKONG_RENDERTARGET_HPP__
#define __RENDERKINGKONG_RENDERTARGET_HPP__

#include "../Core/Core.hpp"

namespace rkk
{
    namespace RenderTarget
    {
        RKK_CLASS
        {
        public:
            type(Desc::RenderTarget::in inDesc);
            ~type();

            Desc::RenderTarget::type m_Description;
        };
    } /// namespace RenderTarget
} /// namespace rkk

#endif /// __RENDERKINGKONG_RENDERTARGET_HPP__
