#include "../../Include/RenderFramework/Plugin_RenderDeviceLayer.hpp"

#include "../../Include/RenderFramework/Root.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RenderDeviceLayer
        {
            Bool::type type::Register(Root::ptr InRootPtr, Name::in InName)
            {
                if (tSuper::Register(InRootPtr, InName))
                {
                    if (::Wiz::IsValidPtr(m_RootPtr->m_Renderer))
                    {
                        Renderer::ptrf RendererPtr = m_RootPtr->m_Renderer;
                        
                        if (RendererPtr->m_mapRDLPlugin.InsertUnique(InName, this))
                        {
                            return Bool::True;
                        }
                    }
                }

                return Bool::False;
            }

            Bool::type type::Unregister()
            {
                return Bool::False;
            }

            Bool::type type::Active()
            {
                if (::Wiz::IsValidPtr(m_RootPtr))
                {


                    return Bool::True;
                }

                return Bool::False;
            }

            Bool::type type::Deactive()
            {

                return Bool::False;
            }
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin
} /// namespace rkk
