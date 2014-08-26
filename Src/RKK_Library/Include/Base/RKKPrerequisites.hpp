#ifndef __RENDERKINGKONG_PREREQUISITES_HPP__
#define __RENDERKINGKONG_PREREQUISITES_HPP__

#include "./TypeDeclareUtils.hpp"

#undef  WIZ_CUSTOM_DECLARE_HELPER
#define WIZ_CUSTOM_DECLARE_HELPER                    RKK_DECLARE
#undef  WIZ_CUSTOM_DECLARE_HELPER_SIMPLE
#define WIZ_CUSTOM_DECLARE_HELPER_SIMPLE             RKK_DECLARE_SIMPLE
#undef  WIZ_CUSTOM_DECLARE_HELPER_PTR
#define WIZ_CUSTOM_DECLARE_HELPER_PTR                RKK_DECLARE_PTR

#undef  WIZ_CUSTOM_DECLARE_HELPER_CONTAINER
#define WIZ_CUSTOM_DECLARE_HELPER_CONTAINER          RKK_DECLARE
#undef  WIZ_CUSTOM_DECLARE_HELPER_ITERATOR
#define WIZ_CUSTOM_DECLARE_HELPER_ITERATOR           RKK_DECLARE_ITER
#undef  WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST
#define WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST     RKK_DECLARE_ITER_CONST

#include "../../../WIZ_Library/Include/WizCustomDeclareHelper.hpp"


namespace rkk
{
    namespace Root
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace Root;

    ////////////////////////////////////////////

    namespace RenderShader
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderShader

    namespace RenderState
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderState

    namespace RenderTarget
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderTarget

    ////////////////////////////////////////////

    namespace RenderDeviceLayer
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderDeviceLayer

    ////////////////////////////////////////////

    namespace Renderer
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace Renderer;

    namespace RenderPass
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderPass;

    namespace RenderFlow
    {
        RKK_FORWARD_DECLARE_CLASS;
    } /// end of namespace RenderFlow;

    ////////////////////////////////////////////

    namespace Plugin
    {
        RKK_FORWARD_DECLARE_CLASS;

        namespace RenderDeviceLayer
        {
            RKK_FORWARD_DECLARE_CLASS;
        } /// end of namespace RenderDeviceLayer

    } /// end of namespace Plugin

    ////////////////////////////////////////////

} /// end of namespace rkk


#endif /// __RENDERKINGKONG_PREREQUISITES_HPP__
