#include "../../Include/RenderFramework/Renderer.hpp"

namespace rkk
{
    namespace Renderer
    {
        type::type()
        {
            m_RDLPtr = RenderDeviceLayer::Create();

            m_RDLList.PushBack(m_RDLPtr);
        }

        type::~type()
        {
            if (IsValidPtr(m_RDLPtr))
            {
                RenderDeviceLayer::Destroy(m_RDLPtr);
            }
        }
    } /// namespace Renderer
} /// namespace rkk
