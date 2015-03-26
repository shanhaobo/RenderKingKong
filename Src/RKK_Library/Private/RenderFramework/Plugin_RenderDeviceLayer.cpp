#include "../../include/RenderFramework/Plugin_RenderDeviceLayer.hpp"

#include "../../include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            Bool::type type::Register(Root::ptr inRootPtr, Name::in inName)
            {
                if (tSuper::Register(inRootPtr, inName))
                {
                    m_RendererPtr = m_RootPtr->m_RendererPtr;
                    if (::Wiz::IsValidPtr(m_RendererPtr))
                    {
                        if (m_RendererPtr->RegisterRDL(inName, this))
                        {
                            return Bool::True;
                        }
                    }
                }

                return Bool::False;
            }

            Void::type type::Unregister()
            {
                if (::Wiz::IsValidPtr(m_RendererPtr))
                {
                    m_RendererPtr->UnregisterRDL(m_PluginName);
                }

                if (::Wiz::IsValidPtr(m_RDLPtr))
                {
                    DestroyRDL(m_RDLPtr);

                    m_RDLPtr = WIZ_NULL;
                }

                tSuper::Unregister();
            }

            Bool::type type::Active()
            {
                if (tSuper::Active() && ::Wiz::IsValidPtr(m_RendererPtr))
                {
                    if (::Wiz::NotValidPtr(m_RDLPtr))
                    {
                        m_RDLPtr = CreateRDL();
                    }

                    if (::Wiz::IsValidPtr(m_RDLPtr))
                    {
                        return m_RendererPtr->ActiveRDL(m_PluginName);
                    }
                }

                return Bool::False;
            }

            Void::type type::Deactive()
            {
                tSuper::Deactive();
            }
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk
