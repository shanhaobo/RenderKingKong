#ifndef __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__
#define __CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__

#include "../../Base/Base.hpp"

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
                    ::rkk::Size16::In               Width,
                    ::rkk::Size16::In               Height,
                    ::rkk::Enum::PixelFormat::In    ColorFormat              = ::rkk::Enum::PixelFormat::eRGBA_16F_16F_16F_16F,
                    ::rkk::Enum::PixelFormat::In    DepthFormat             = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::rkk::Enum::PixelFormat::In    StencilFormat           = ::rkk::Enum::PixelFormat::eDS_24UN_8U,
                    ::rkk::U::In                    Index                   = 0,
                    ::rkk::Bool::In                 ClearColorEnable        = ::rkk::Bool::False,
                    ::rkk::Color::In                ClearColorValue         = ::rkk::Color::Black,
                    ::rkk::Bool::In                 ClearDepthEnable        = ::rkk::Bool::False,
                    ::rkk::Real::In                 ClearDepthValue         = 0,
                    ::rkk::Bool::In                 ClearStencilEnable      = ::rkk::Bool::False,
                    ::rkk::U::In                    ClearStencilValue       = 0,
                    ::rkk::Enum::MultiSample::In    MultiSample             = ::rkk::Enum::MultiSample::eNone,
                    ::rkk::U::In                    MultiSampleQuality      = 0
                    )
                    : m_Width(Width)
                    , m_Height(Height)
                    , m_ColorPixelFormat(ColorFormat)
                    , m_DepthPixelFormat(DepthFormat)
                    , m_StencilPixelFormat(StencilFormat)
                    , m_Index(Index)
                    , Clear(ClearColorEnable, ClearColorValue, ClearDepthEnable, ClearDepthValue, ClearStencilEnable, ClearStencilValue)
                    , m_MultiSample(MultiSample, MultiSampleQuality)
                {

                }

                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                ::rkk::Size16::Type                     m_Width;
                ::rkk::Size16::Type                     m_Height;

                ::rkk::Enum::PixelFormat::Type          m_ColorPixelFormat;
                ::rkk::Enum::PixelFormat::Type          m_DepthPixelFormat;
                ::rkk::Enum::PixelFormat::Type          m_StencilPixelFormat;
                ::rkk::U::Type                          m_Index;

                ::rkk::Desc::Clear::Type                Clear;

                ::rkk::Desc::MultiSample::Type          m_MultiSample;

            };
        } /// end of namespace RenderTarget
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__CORE_DESC_RENDERTARGET_HPP__SHANHAOBO_19800429__*/

