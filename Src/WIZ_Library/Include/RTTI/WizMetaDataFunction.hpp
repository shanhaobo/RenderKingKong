#ifndef __WIZ_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__

#include "./WizMetaDataStruct.hpp"

namespace Wiz
{
    namespace MetaData
    {
        namespace Function
        {
            class Type : public MetaData::Struct::Type
            {
                typedef Type                    tThis;
                typedef tThis*                  tThisPtr;

                typedef MetaData::Struct::Type  tSuper;

            public:
                WIZ_DECLARE_RTTI(Type, MetaData::Struct::Type);

            };
        } /// end of namespace Function
    } /// end of namespace MetaData
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_FUNCTION_HPP__SHANHAOBO_19800429__*/
