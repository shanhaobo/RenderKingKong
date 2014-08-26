#include "../../Include/RenderFramework/Renderer.hpp"
#include "../../Include/RenderFramework/Plugin_RenderDeviceLayer.hpp"

namespace rkk
{
    namespace Renderer
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        Bool::type type::RegisterRDL(Name::in InName, Plugin::RenderDeviceLayer::ptr InRDLPluginPtr)
        {
            return m_mapRDLPlugin.InsertUnique(InName, InRDLPluginPtr);
        }

        Void::type type::UnregisterRDL(Name::in InName)
        {
            DeactiveRDL(InName);

            m_mapRDLPlugin.Remove(InName);
        }

        Bool::type type::ActiveRDL(Name::in InName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = RKK_NULLPTR;
            if (m_mapRDLPlugin.TryGet(RDLPluginPtr, InName) && ::Wiz::IsValidPtr(RDLPluginPtr))
            {
                DeactiveRDL(RDLPluginPtr);

                if (RDLPluginPtr->Active())
                {
                    m_ActivedRDLName    = InName;
                    m_ActivedRDLPtr     = RDLPluginPtr->m_RDLPtr;

                    return Bool::True;
                }
            }

            return Bool::False;
        }

        Void::type type::DeactiveRDL(Name::in InName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = RKK_NULLPTR;
            if (m_mapRDLPlugin.TryGet(RDLPluginPtr, InName) && ::Wiz::IsValidPtr(RDLPluginPtr))
            {
                DeactiveRDL(RDLPluginPtr);
            }
        }

        Void::type type::DeactiveRDL(Plugin::RenderDeviceLayer::ptr InRDLPluginPtr)
        {
            if (::Wiz::NotValidPtr(m_ActivedRDLPtr) || m_ActivedRDLName.NotValid())
            {
                return;
            }

            if ((m_ActivedRDLPtr == InRDLPluginPtr->m_RDLPtr) && (m_ActivedRDLName == InRDLPluginPtr->m_PluginName))
            {
                InRDLPluginPtr->Deactive();

                m_ActivedRDLName.Invalid();
                m_ActivedRDLPtr = WIZ_NULL;
            }
        }
    } /// namespace Renderer
} /// namespace rkk
