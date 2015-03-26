#include "../../include/RenderFramework/Plugin.hpp"

namespace rkk
{
    namespace Plugin
    {
        Bool::type type::Register(Root::ptr inRootPtr, Name::in inName)
        {
            if (::Wiz::IsValidPtr(inRootPtr) && inName.IsValid())
            {
                m_RootPtr = inRootPtr;

                m_PluginName = inName;

                return Bool::True;
            }

            return Bool::False;
        }
    } /// end of namespace Plugin
} /// namespace rkk
