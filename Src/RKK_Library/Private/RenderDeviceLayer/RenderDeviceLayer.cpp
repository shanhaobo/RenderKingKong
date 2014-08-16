#include "../../Include/RenderDeviceLayer/RenderDeviceLayer.hpp"

namespace rkk
{
    namespace RenderDeviceLayer
    {
        ptr Create()
        {
            return RKK_NULLPTR;
        }

        Void::type Destroy(ptr& RDLPtr)
        {
            RDLPtr = RKK_NULLPTR;
        }
    } /// namespace RenderDeviceLayer
} /// namespace rkk
