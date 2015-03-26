#ifndef __RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__
#define __RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__

#include "../../Base/BaseColor.hpp"

namespace rkk
{
    namespace Desc
    {
        namespace Clear
        {
            RKK_STRUCT
            {
                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                struct tColorDesc
                {
                public:
                    tColorDesc(
                        Bool::in    Enable      = Bool::False,
                        Color::in   Value       = Color::Black
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    Void::type Set(
                        Bool::in    Enable      = Bool::False,
                        Color::in   Value       = Color::Black
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    Void::type Set(
                        tColorDesc const &  inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    Bool::type      m_Enable;
                    Color::type     m_Value;
                };

                struct tDepthDesc
                {
                public:
                    tDepthDesc(
                        Bool::in    Enable      = Bool::False,
                        F32::in    Value       = 0
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    Void::type Set(
                        Bool::in    Enable      = Bool::False,
                        F32::in    Value       = 0
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    Void::type Set(
                        tDepthDesc const &  inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    Bool::type      m_Enable;
                    F32::type       m_Value;
                };

                struct tStencilDesc
                {
                public:
                    tStencilDesc(
                        Bool::in    Enable  = Bool::False,
                        U::in    Value   = 0
                        )
                        : m_Enable(Enable)
                        , m_Value(Value)
                    {

                    }
                    Void::type Set(
                        Bool::in    Enable  = Bool::False,
                        U::in    Value   = 0
                        )
                    {
                        m_Enable        = Enable;
                        m_Value         = Value;
                    }

                    Void::type Set(
                        tStencilDesc const &    inDesc
                        )
                    {
                        m_Enable        = inDesc.m_Enable;
                        m_Value         = inDesc.m_Value;
                    }
                public:
                    Bool::type      m_Enable;
                    U::type         m_Value;
                };

                //////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////

                type(
                    Bool::in    ColorEnable      = Bool::False,
                    Color::in   ColorValue       = Color::Black,
                    Bool::in    DepthEnable      = Bool::False,
                    F32::in     DepthValue       = 0,
                    Bool::in    StencilEnable    = Bool::False,
                    U::in       StencilValue     = 0
                    )
                    : Color(ColorEnable, ColorValue)
                    , Depth(DepthEnable, DepthValue)
                    , Stencil(StencilEnable, StencilValue)
                {

                }

                tColorDesc              Color;
                tDepthDesc              Depth;
                tStencilDesc            Stencil;
            };
        } /// end of namespace Clear
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__RENDERKINGKONG_DES_CLEAR_HPP__SHANHAOBO_19800429__*/

