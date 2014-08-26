#include "../../Include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Root
    {

        Bool::type type::LoadPlugin(Str::in InPluginFileName, Name::in InPluginName)
        {
            if (m_mapPlugin.HasData(InPluginName))
            {
                return Bool::False;
            }

            ::rkk::Plugin::ptr LoadedPluginPtr = RKK_NULLPTR;

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
            ::rkk::Plugin::ptr FoundPluginPtr = RKK_NULLPTR;
            if (m_mapPlugin.TryGet(FoundPluginPtr, InPluginName) && ::Wiz::IsValidPtr(FoundPluginPtr))
            {
                FoundPluginPtr->Unregister();

                m_mapPlugin.Remove(InPluginName);

                /// TODO Destroy FoundPluginPtr;
            }
        }

        Bool::type type::ActivePlugin_RDL(Name::in InRDLName)
        {
            if (::Wiz::IsValidPtr(m_RendererPtr))
            {
                return m_RendererPtr->ActiveRDL(InRDLName);
            }

            return Bool::False;
        }
    } /// namespace Renderer
} /// namespace rkk
