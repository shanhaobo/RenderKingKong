#include "../../Include/Module/WMSAttrModule.hpp"

namespace wms
{
    namespace AttrModule
    {
        type::type()
        {
        }


        type::type(::wms::Size::in inSize) : tSuper(inSize)
        {

        }

        type::~type()
        {
        }


        Attr::ptr type::GetAttrByIdx(::wms::Size::in inIdx)
        {
            if ((inIdx >= 0) && (inIdx < m_Children.Size()))
            {
                return m_Children[inIdx];
            }

            return WIZ_NULLPTR;
        }
    } /// end of namespace AttrModule
} /// end of namespace wms
