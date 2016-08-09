#include "../../Include/Module/WMSAttrProvider.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {
            type::type()
            {
            }

            type::~type()
            {

            }

            Bool::type type::IsAttached(Attr::Manager::ptr inAttrManagerPtr) const
            {
                if (::Wiz::IsValidPtr(inAttrManagerPtr) && (m_RequestInstantList.Size() > 0))
                {
                    tRequestInstantList::tIteratorConst tIter;
                    for (tIter = m_RequestInstantList.Begin(); tIter != m_RequestInstantList.End(); ++tIter)
                    {
                        if (tIter->m_AttrManagerPtr == inAttrManagerPtr)
                        {
                            return Bool::True;
                        }
                    }
                }

                return Bool::False;
            }

            Bool::type type::Attach(Attr::Manager::ptr inAttrManagerPtr)
            {
                if (::Wiz::IsValidPtr(inAttrManagerPtr) && (m_RequestList.Size() > 0))
                {
                    if (IsAttached(inAttrManagerPtr))
                    {
                        return Bool::True;
                    }

                    m_RequestInstantList.PushBack(tRequestInstantItem());

                    tRequestInstantItem& tItem = m_RequestInstantList.Back();
                }

                return Bool::False;
            }

            Void::type type::Detach(Attr::Manager::ptr inAttrManagerPtr)
            {
                if (IsAttached(inAttrManagerPtr))
                {

                }
            }

            Void::type type::DetachAll()
            {

            }
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms
