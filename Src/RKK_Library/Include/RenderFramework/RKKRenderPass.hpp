#ifndef __RENDERKINGKONG_RENDERPASS_HPP__
#define __RENDERKINGKONG_RENDERPASS_HPP__

#include "../RenderCore/RKKRenderState.hpp"

#include "../RenderCore/RKKRenderShader_PixelShader.hpp"
#include "../RenderCore/RKKRenderShader_VertexShader.hpp"

namespace rkk
{
    namespace RenderPass
    {
        WMS_CLASS
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
