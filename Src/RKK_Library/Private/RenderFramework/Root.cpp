#include "../../Include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Root
    {
        Plugin::ptr type::GetPlugin(Name::in InPluginName)
        {
            Plugin::ptr PluginPtr = RKK_NULLPTR;
            m_mapPlugin.TryGet(PluginPtr, InPluginName);
            return PluginPtr;
        }

        Bool::type type::LoadPlugin(Str::in InPluginFileName, Name::in InPluginName)
        {
            if (m_mapPlugin.HasData(InPluginName))
            {
                return Bool::False;
            }

            Plugin::ptr LoadedPluginPtr = RKK_NULLPTR;

            /// TODO Load Plugin

            if (::Wiz::IsValidPtr(LoadedPluginPtr))
            {
                LoadedPluginPtr->Register(this, InPluginName);

                m_mapPlugin.Insert(InPluginName, LoadedPluginPtr);

                return Bool::True;
            }

            return Bool::False;
        }

        Void::type type::UnloadPlugin(Name::in InPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(InPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Unregister();

                m_mapPlugin.Remove(InPluginName);

                /// TODO Destroy FoundPluginPtr;
            }
        }

        Bool::type type::ActivePlugin(Name::in InPluginName)
        {
            Plugin::ptr FoundPluginPtr = GetPlugin(InPluginName);
            if (::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Active();

                return Bool::True;
            }

            return Bool::False;
        }
    } /// namespace Renderer
} /// namespace rkk
