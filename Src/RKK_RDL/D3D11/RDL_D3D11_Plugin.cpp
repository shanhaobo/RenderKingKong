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
                RKK_CLASS : public ::rkk::Plugin::RenderDeviceLayer::type
                {
                public:
                    typedef ::rkk::Plugin::type tSuper;
                public:
                    type()
                    {

                    }
                public:

                    virtual RenderDeviceLayer::ptr CreateRDL()
                    {
                        /// TODO Create RDL;

                        return m_D3D11RDLPtr;
                    }

                    virtual Void::type DestroyRDL(RenderDeviceLayer::ptr InRDLPtr)
                    {
                        if (InRDLPtr == m_D3D11RDLPtr)
                        {
                            /// TODO Destroy RDL
                        }
                    }

                    ::rkk::RenderDeviceLayer::D3D11::ptr  m_D3D11RDLPtr;
                };
            } /// end of namespace D3D11
        } /// namespace RenderDeviceLayer
    } /// end of namespace Plugin

} /// namespace rkk