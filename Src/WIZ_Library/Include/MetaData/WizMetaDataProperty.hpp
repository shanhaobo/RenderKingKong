#ifndef __WIZ_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__

#include "./WizMetaDataField.hpp"

namespace Wiz
{
    namespace MetaData
    {
        namespace Property
        {
            class Type : public MetaData::Field::Type
            {
                typedef Type                    tThis;
                typedef tThis*                  tThisPtr;

                typedef MetaData::Field::Type   tSuper;
            };
        } /// end of namespace Property
    } /// end of namespace MetaData
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_PROPERTY_HPP__SHANHAOBO_19800429__*/
