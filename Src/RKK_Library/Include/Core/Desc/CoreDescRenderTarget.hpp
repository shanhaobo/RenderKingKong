#ifndef __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__
#define __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__

#include "../../Base/Base.hpp"

#include "./CoreDescRenderTarget.hpp"
#include "./CoreDescClear.hpp"

namespace rkk
{
    namespace Desc
    {
        namespace RenderTarget
        {
            RKK_STRUCT
            {
                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                type(
                    ::rkk::Size16::in               Width,
                    ::rkk::Size16::in               Height,
                    ::rkk::Enum::PixelFormat::in    ColorFormat             = ::rkk::Enum::PixelFormat::eRGBA_16F_16F_16F_16F,
                    ::rkk::Enum::PixelFormat::in    DepthFormat             = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::rkk::Enum::PixelFormat::in    StencilFormat           = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::rkk::U::in                    index                   = 0,
                    ::rkk::Bool::in                 ClearColorEnable        = ::rkk::Bool::False,
                    ::rkk::Color::in                ClearColorValue         = ::rkk::Color::Black,
                    ::rkk::Bool::in                 ClearDepthEnable        = ::rkk::Bool::False,
                    ::rkk::F32::in                  ClearDepthValue         = 0,
                    ::rkk::Bool::in                 ClearStencilEnable      = ::rkk::Bool::False,
                    ::rkk::U::in                    ClearStencilValue       = 0,
                    ::rkk::Enum::MultiSample::in    MultiSample             = ::rkk::Enum::MultiSample::eNone,
                    ::rkk::U::in                    MultiSampleQuality      = 0
                    )
                    : m_Width(Width)
                    , m_Height(Height)
                    , m_ColorPixelFormat(ColorFormat)
                    , m_DepthPixelFormat(DepthFormat)
                    , m_StencilPixelFormat(StencilFormat)
                    , m_Index(index)
                    , Clear(ClearColorEnable, ClearColorValue, ClearDepthEnable, ClearDepthValue, ClearStencilEnable, ClearStencilValue)
                    , m_MultiSample(MultiSample, MultiSampleQuality)
                {

                }

                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                ::rkk::Size16::type                     m_Width;
                ::rkk::Size16::type                     m_Height;

                ::rkk::Enum::PixelFormat::type          m_ColorPixelFormat;
                ::rkk::Enum::PixelFormat::type          m_DepthPixelFormat;
                ::rkk::Enum::PixelFormat::type          m_StencilPixelFormat;
                ::rkk::U::type                          m_Index;

                ::rkk::Desc::Clear::type                Clear;

                ::rkk::Desc::MultiSample::type          m_MultiSample;

            };
        } /// end of namespace RenderTarget
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__*/

