#ifndef __WHIMSY_ATTRMODULE_HPP__ 
#define __WHIMSY_ATTRMODULE_HPP__

#include "./WMSAttrGroup.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace AttrModule
    {
        WMS_CLASS: public ::wms::CmpntArray::type
        {
        private:
            typedef ::wms::CmpntArray::type tSuper;

        public:
            type();
            type(::wms::Size::in);
            virtual ~type();

        public:
            template<class T>
            T GetValue(::wms::Size::in inIdx)
            {
                ::wms::Size::type   i;
                T                   lResult(0), lTemp;
                for (i = 0; i < m_Children.Size(); ++i)
                {
                    AttrGroup::ptr lPtr = ::Wiz::Cast::Static<AttrGroup::ptr>(m_Children[i]);
                    if (::Wiz::IsValidPtr(lPtr) && lPtr->GetValue(lTemp, inIdx))
                    {
                        lResult += lTemp;
                    }
                }
                return lResult;
            }

        protected:
        };
    } /// end of namespace AttrModule
} /// end of namespace wms

#endif /// __WHIMSY_ATTRMODULE_HPP__
