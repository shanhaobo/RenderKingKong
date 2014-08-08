#ifndef __RENDERKINGKONG_RENDERPASS_HPP__
#define __RENDERKINGKONG_RENDERPASS_HPP__

#include "../RenderCore/RenderStateManager.hpp"

#include "../RenderCore/RenderShader_PixelShader.hpp"
#include "../RenderCore/RenderShader_VertexShader.hpp"

namespace rkk
{
    namespace RenderPass
    {
        class type
        {
        public:
            type();
            ~type();

            RenderState::Manager::type          m_RenderStageManager;

            RenderShader::VertexShader::type    m_VertexShader;
            RenderShader::PixelShader::type     m_PixelShader;
        };
        RKK_DECLARE(type);
    } /// namespace RenderPass
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERPASS_HPP__
