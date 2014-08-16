#ifndef __RENDERKINGKONG_RENDERPASS_HPP__
#define __RENDERKINGKONG_RENDERPASS_HPP__

#include "../RenderCore/RenderState.hpp"

#include "../RenderCore/RenderShader_PixelShader.hpp"
#include "../RenderCore/RenderShader_VertexShader.hpp"

namespace rkk
{
    namespace RenderPass
    {
        RKK_CLASS
        {
        public:
            type();
            ~type();

        public:
            RenderState::type                   m_RenderStage;

            RenderShader::VertexShader::type    m_VertexShader;
            RenderShader::PixelShader::type     m_PixelShader;
        };
    } /// namespace RenderPass
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERPASS_HPP__
