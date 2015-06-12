#ifndef __WHIMSY_ATTRIBUTE_HPP__ 
#define __WHIMSY_ATTRIBUTE_HPP__

#include "../Core/WMSFrmwrkComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace Attr
    {
        namespace Modifier
        {
            WMS_STRUCT
            {
				::wms::I32::type    AttrType;
                ::wms::I32::type    BasePct;
                ::wms::I32::type    AbsValue;
                ::wms::I32::type    FinalPct;

                WIZ_INLINE ::wms::Bool::type operator==(in inOther) const
                {
					return (AttrType == inOther.AttrType) && (BasePct == inOther.BasePct) && (AbsValue == inOther.AbsValue) && (FinalPct == inOther.FinalPct);
                }

                WIZ_INLINE ::wms::Bool::type operator!=(in inOther) const
                {
                    return operator==(inOther) == false;
                }
            };
        } /// end of namespace Modifier

        WMS_CLASS : public ::wms::Cmpnt::type
        {
        private:
            typedef ::wms::Cmpnt::type tSuper;

        public:
            type();
            virtual ~type();
            virtual Void::type Tick(F32::in inDeltaTime);

            typedef Array<::wms::Attr::Modifier::type>::type tModifierArray;


            ::wms::Void::type AddModfier(::wms::Attr::Modifier::in inModifier);
            ::wms::Void::type RemoveModifer(::wms::Attr::Modifier::in inModifier);
			::wms::Void::type UpdateModifer();

        protected:
            tModifierArray        m_ModfierList;
        };
    } /// end of namespace Attribute
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_HPP__
