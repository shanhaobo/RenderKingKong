#include "../../include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Root
    {
        Plugin::ptr type::GetPlugin(Name::in inPluginName)
        {
            Plugin::ptr PluginPtr = RKK_NULLPTR;
            m_mapPlugin.TryGet(PluginPtr, inPluginName);
            return PluginPtr;
        }

        Bool::type type::LoadPlugin(Str::in inPluginFileName, Name::in inPluginName)
        {
            if (m_mapPlugin.HasData(inPluginName))
            {
                return Bool::False;
            }

            Plugin::ptr LoadedPluginPtr = RKK_NULLPTR;

            /// TODO Load Plugin

            if (::Wiz::IsValidPtr(LoadedPluginPtr))
            {
                LoadedPluginPtr->Register(this, inPluginName);

                m_mapPlugin.insert(inPluginName, LoadedPluginPtr);

                return Bool::True;
            }

            return Bool::False;
        }

        Void::type type::UnloadPlugin(Name::in inPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Unregister();

                m_mapPlugin.Remove(inPluginName);

                /// TODO Destroy FoundPluginPtr;
            }
        }

        Bool::type type::ActivePlugin(Name::in inPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(inPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Active();

                return Bool::True;
            }

            return Bool::False;
        }
    } /// namespace Renderer
} /// namespace rkk
