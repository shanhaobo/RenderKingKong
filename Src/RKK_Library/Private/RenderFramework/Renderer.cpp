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

        ::wms::Bool::type type::RegisterRDL(::wms::Name::in inName, Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            return m_mapRDLPlugin.insertUnique(inName, inRDLPluginPtr);
        }

        ::wms::Void::type type::UnregisterRDL(::wms::Name::in inName)
        {
            DeactiveRDL(inName);

            m_mapRDLPlugin.Remove(inName);
        }


        Plugin::RenderDeviceLayer::ptr type::GetRDL(::wms::Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = WMS_NULLPTR;
            m_mapRDLPlugin.TryGet(RDLPluginPtr, inName);
            return RDLPluginPtr;
        }

        ::wms::Bool::type type::ActiveRDL(::wms::Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = GetRDL(inName);
            
            return ActiveRDL(RDLPluginPtr);
        }

        ::wms::Bool::type type::ActiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::IsValidPtr(inRDLPluginPtr))
            {
                DeactiveRDL(inRDLPluginPtr);

                if (::Wiz::IsValidPtr(inRDLPluginPtr->m_RDLPtr))
                {
                    m_ActivedRDLName = inRDLPluginPtr->m_PluginName;
                    m_ActivedRDLPtr = inRDLPluginPtr->m_RDLPtr;

                    return ::wms::Bool::True;
                }
            }

            return ::wms::Bool::False;
        }

        ::wms::Void::type type::DeactiveRDL(::wms::Name::in inName)
        {
            Plugin::RenderDeviceLayer::ptr RDLPluginPtr = GetRDL(inName);
            if (::Wiz::IsValidPtr(RDLPluginPtr))
            {
                DeactiveRDL(RDLPluginPtr);
            }
        }

        ::wms::Void::type type::DeactiveRDL(Plugin::RenderDeviceLayer::ptr inRDLPluginPtr)
        {
            if (::Wiz::NotValidPtr(m_ActivedRDLPtr) || m_ActivedRDLName.NotValid())
            {
                return;
            }

            if ((m_ActivedRDLPtr == inRDLPluginPtr->m_RDLPtr) && (m_ActivedRDLName == inRDLPluginPtr->m_PluginName))
            {
                inRDLPluginPtr->Deactive();

                m_ActivedRDLName.invalid();
                m_ActivedRDLPtr = WMS_NULLPTR;
            }
        }
    } /// namespace Renderer
} /// namespace rkk
