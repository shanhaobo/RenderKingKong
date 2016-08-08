#ifndef __WHIMSY_ATTRGROUP_HPP__ 
#define __WHIMSY_ATTRGROUP_HPP__

#include "./WMSAttributeT.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace AttrGroup
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
            Bool::type GetValue(T& outValue, ::wms::Size::in inIdx)
            {
                typedef Attr::Type<T>   tValidAttrType;

                Attr::ptr       lAttrPtr    = GetAttrByIdx(inIdx);
                tValidAttrType* lAttrTPtr   = ::Wiz::Cast::Static<tValidAttrType*>(lAttrPtr);
                if (::Wiz::IsValidPtr(lAttrTPtr))
                {
                    outValue = lAttrTPtr->GetCurrValue();

                    return Bool::True;
                }

                return Bool::False;
            }

        protected:
            Attr::ptr GetAttrByIdx(::wms::Size::in inIdx);
        };
    } /// end of namespace AttrGroup
} /// end of namespace wms

#endif /// __WHIMSY_ATTRGROUP_HPP__
