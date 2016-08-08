#include "../../Include/Module/WMSAttrProvider.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {
            type::type() : m_AttrModulePtr(WIZ_NULLPTR)
            {
            }

            type::~type()
            {

            }

            Bool::type type::Attach(Attr::Module::ptr inAttrModulePtr)
            {
                if (::Wiz::IsValidPtr(inAttrModulePtr))
                {
                    m_AttrModulePtr = inAttrModulePtr;

                    tRequestList::tSize i;
                    for (i = 0; i < m_RequestList.Size(); ++i)
                    {

                    }
                }

                return Bool::True;
            }

            Void::type type::Detach()
            {

            }
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms
