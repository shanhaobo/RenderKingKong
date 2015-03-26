#include "../../include/RenderFramework/Renderer.hpp"
#include "../../include/RenderFramework/Plugin_RenderDeviceLayer.hpp"

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

        Bool::type type::RegisterRDL(Name::in inName, Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            return m_mapRDLPlugin.insertUnique(inName, inRDLPluginPtr);
        }

        Void::type type::UnregisterRDL(Name::in inName)
        {
            DeactiveRDL(inName);

            m_mapRDLPlugin.Remove(inName);
        }


        Plugin::RenderDeviceLayer::ptr type::GetRDL(Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = RKK_NULLPTR;
            m_mapRDLPlugin.TryGet(RDLPluginPtr, inName);
            return RDLPluginPtr;
        }

        Bool::type type::ActiveRDL(Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = GetRDL(inName);
            
            return ActiveRDL(RDLPluginPtr);
        }

        Bool::type type::ActiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::IsValidPtr(inRDLPluginPtr))
            {
                DeactiveRDL(inRDLPluginPtr);

                if (::Wiz::IsValidPtr(inRDLPluginPtr->m_RDLPtr))
                {
                    m_ActivedRDLName = inRDLPluginPtr->m_PluginName;
                    m_ActivedRDLPtr = inRDLPluginPtr->m_RDLPtr;

                    return Bool::True;
                }
            }

            return Bool::False;
        }

        Void::type type::DeactiveRDL(Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = GetRDL(inName);
            if (::Wiz::IsValidPtr(RDLPluginPtr))
            {
                DeactiveRDL(RDLPluginPtr);
            }
        }

        Void::type type::DeactiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::NotValidPtr(m_ActivedRDLPtr) || m_ActivedRDLName.NotValid())
            {
                return;
            }

            if ((m_ActivedRDLPtr == inRDLPluginPtr->m_RDLPtr) && (m_ActivedRDLName == inRDLPluginPtr->m_PluginName))
            {
                inRDLPluginPtr->Deactive();

                m_ActivedRDLName.invalid();
                m_ActivedRDLPtr = WIZ_NULL;
            }
        }
    } /// namespace Renderer
} /// namespace rkk
