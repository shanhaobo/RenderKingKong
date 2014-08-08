#ifndef __RENDERKINGKONG_RENDERSHADER_VERTEXSHADER_HPP__
#define __RENDERKINGKONG_RENDERSHADER_VERTEXSHADER_HPP__

#include "RenderShader.hpp"

namespace rkk
{
    namespace RenderShader
    {
        namespace VertexShader
        {
            class type : public RenderShader::type
            {
            public:
                type();
                ~type();
            };

            RKK_DECLARE(type);
        } /// namespace VertexShader
    } /// namespace RenderShader
}

#endif /// #ifndef __RENDERKINGKONG_RENDERSHADER_VERTEXSHADER_HPP__
