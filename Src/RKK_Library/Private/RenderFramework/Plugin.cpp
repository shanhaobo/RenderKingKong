#include "../../Include/RenderFramework/Plugin.hpp"

namespace rkk
{
    namespace Plugin
    {
        Bool::type type::Register(Root::ptr InRootPtr, Name::in InName)
        {
            if (::Wiz::IsValidPtr(InRootPtr) && InName.IsValid())
            {
                m_RootPtr = InRootPtr;

                return Bool::True;
            }

            return Bool::False;
        }
    } /// end of namespace Plugin
} /// namespace rkk
