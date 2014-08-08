#ifndef __RENDERKINGKONG_RENDERSHADER_PIXELSHADER_HPP__
#define __RENDERKINGKONG_RENDERSHADER_PIXELSHADER_HPP__

#include "RenderShader.hpp"

namespace rkk
{
    namespace RenderShader
    {
        namespace PixelShader
        {
            class type : public RenderShader::type
            {
            public:
                type();
                ~type();
            };

            RKK_DECLARE(type);
        } /// namespace PixelShader
    } /// namespace RenderShader
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSHADER_PIXELSHADER_HPP__
