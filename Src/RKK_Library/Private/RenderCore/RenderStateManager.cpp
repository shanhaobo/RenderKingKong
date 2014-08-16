#include "./RenderStateManager.hpp"

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

            Bool::type type::Update(RenderState::in inNewState)
            {

                m_WorkingState = inNewState;

                return Bool::True;
            }
        } /// end of namespace Manager
    } /// namespace RenderState
} /// namespace rkk
