#include "../../Include/Core/WMSFrmwrkComponent.hpp"

namespace wms
{
    namespace Cmpnt
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {
            auto const lItrEnd = m_Children.End();
            for (auto lItr = m_Children.Begin(); lItr != lItrEnd; ++lItr)
            {
                auto lChildPtr = (*lItr);
                if (::Wiz::IsValidPtr(lChildPtr))
                {
                    lChildPtr->Tick(inDeltaTime);
                }
            }
        }
    } /// end of namespace Cmpnt
} /// end of namespace wms
