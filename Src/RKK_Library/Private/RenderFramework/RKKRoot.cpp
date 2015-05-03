#include "../../include/RenderFramework/RKKRoot.hpp"

namespace rkk
{
    namespace Root
    {
        Plugin::ptr type::GetPlugin(::wms::Name::in inPluginName)
        {
            Plugin::ptr PluginPtr = WMS_NULLPTR;
            m_mapPlugin.TryGet(PluginPtr, inPluginName);
            return PluginPtr;
        }

        ::wms::Bool::type type::LoadPlugin(::wms::Str::in inPluginFileName, ::wms::Name::in inPluginName)
        {
            if (m_mapPlugin.HasData(inPluginName))
            {
                return ::wms::Bool::False;
            }

            Plugin::ptr LoadedPluginPtr = WMS_NULLPTR;

            /// TODO Load Plugin

            if (::Wiz::IsValidPtr(LoadedPluginPtr))
            {
                LoadedPluginPtr->Register(this, inPluginName);

                m_mapPlugin.insert(inPluginName, LoadedPluginPtr);

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }

        ::wms::Void::type type::UnloadPlugin(::wms::Name::in inPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Unregister();

                m_mapPlugin.Remove(inPluginName);

                /// TODO Destroy FoundPluginPtr;
            }
        }

        ::wms::Bool::type type::ActivePlugin(::wms::Name::in inPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Active();

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }
    } /// namespace Renderer
} /// namespace rkk
