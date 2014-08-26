#include "../../Include/RenderFramework/Plugin_RenderDeviceLayer.hpp"

#include "../../Include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            Bool::type type::Register(Root::ptr InRootPtr, Name::in InName)
            {
                if (tSuper::Register(InRootPtr, InName))
                {
                    m_RendererPtr = m_RootPtr->m_RendererPtr;
                    if (::Wiz::IsValidPtr(m_RendererPtr))
                    {
                        if (m_RendererPtr->RegisterRDL(InName, this))
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
                if (tSuper::Active())
                {
                    if (::Wiz::NotValidPtr(m_RDLPtr))
                    {
                        m_RDLPtr = CreateRDL();
                    }

                    return ::Wiz::IsValidPtr(m_RDLPtr);
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
