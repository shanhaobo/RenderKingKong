#ifndef __WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__

#include "./WizMetaDataBasic.hpp"

namespace Wiz
{
    namespace MetaData
    {
        namespace Field
        {
            class Type : public ::Wiz::MemObj::Type<Allocator::Field::Type>
            {
                typedef Type    tThis;
                typedef tThis*  tThisPtr;

            public:

            protected:
                tThisPtr        NextPtr;
            };
        } /// end of namespace Field
    } /// end of namespace MetaData
} /// end of namespace Wiz


#endif /*__WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__*/
