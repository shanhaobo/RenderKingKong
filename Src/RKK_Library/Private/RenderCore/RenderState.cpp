#include "../../include/RenderCore/RenderState.hpp"

namespace rkk
{
    namespace RenderState
    {
        type::type(in inOther)
        {
            m_KeepLastSetting = inOther.m_KeepLastSetting;
        }

        type::~type()
        {
        }
    } /// namespace RenderState
} /// namespace rkk
