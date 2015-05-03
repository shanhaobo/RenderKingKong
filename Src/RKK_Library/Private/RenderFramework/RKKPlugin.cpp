#include "../../include/RenderFramework/RKKPlugin.hpp"

namespace rkk
{
    namespace Plugin
    {
        ::wms::Bool::type type::Register(Root::ptr inRootPtr, ::wms::Name::in inName)
        {
            if (::Wiz::IsValidPtr(inRootPtr) && inName.IsValid())
            {
                m_RootPtr = inRootPtr;

                m_PluginName = inName;

                return ::wms::Bool::True;
            }

            return ::wms::Bool::False;
        }
    } /// end of namespace Plugin
} /// namespace rkk
