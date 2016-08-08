#ifndef __WHIMSY_ATTRMODULE_HPP__ 
#define __WHIMSY_ATTRMODULE_HPP__

#include "./WMSAttrGroup.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        namespace Module
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
                T GetValue(::wms::ID32::in inIdx)
                {
                    typedef Attr::Type<T>   tValidAttrType;
                    Attr::ptr lAttrPtr = GetAttrByIdx(inIdx);
                    if (::Wiz::IsValidPtr(lAttrPtr))
                    {
                        tValidAttrType* lAttrTPtr = ::Wiz::Cast::Static<tValidAttrType*>(lAttrPtr);
                        return lAttrTPtr->GetCurrValue();
                    }

                    return T(0);
                }

            protected:
                Attr::ptr GetAttrByIdx(::wms::ID32::in inIdx);
            };
        } /// end of namesapce Module
    } /// end of namespace AttrModule
} /// end of namespace wms

#endif /// __WHIMSY_ATTRMODULE_HPP__
