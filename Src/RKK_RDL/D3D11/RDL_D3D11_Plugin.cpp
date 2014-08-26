#include "../../RKK_Library/Include/RenderFramework/Plugin.hpp"

#include "./RDL_D3D11.hpp"

namespace rkk
{
    namespace Plugin
    {
        namespace RDL
        {
            namespace D3D11
            {
                RKK_CLASS : public ::rkk::Plugin::type
                {
                public:
                    typedef ::rkk::Plugin::type tSuper;
                public:
                    type()
                    {

                    }
                public:

                    virtual Bool::type Register(Root::ptr InRootPtr)
                    {
                        m_RootPtr = InRootPtr;

                    }

                    virtual Bool::type Unregister()
                    {

                    }

                public:
                    virtual Bool::type Active()
                    {
                    }
                    virtual Bool::type Deactive()
                    {

                    }

                    ::rkk::RenderDeviceLayer::D3D11::ptr  m_RDLPtr;
                };
            } /// end of namespace D3D11
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin

} /// namespace rkk
