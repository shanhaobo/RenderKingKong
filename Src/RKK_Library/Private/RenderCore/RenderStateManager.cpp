#include "../../Include/RenderCore/RenderStateManager.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Manager
        {
            type::type()
            {
            }

            type::~type()
            {
            }

            Bool::type type::Update()
            {
                return m_WorkingContent.Update(m_Content);
            }
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk
