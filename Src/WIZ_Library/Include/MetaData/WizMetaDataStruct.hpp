#ifndef __WIZ_METADATA_STRUCT_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_STRUCT_HPP__SHANHAOBO_19800429__

#include "./WizMetaDataField.hpp"

namespace Wiz
{
    namespace MetaData
    {
        namespace Struct
        {
            class Type : public MetaData::Field::Type
            {
                typedef Type                    tThis;
                typedef tThis*                  tThisPtr;

                typedef MetaData::Field::Type   tSuper;

            public:
                WIZ_DECLARE_RTTI(Type, MetaData::Field::Type);

            protected:
                typedef tThis                   tStruct;
                typedef tStruct*                tStructPtr;

            protected:
                tStructPtr                      m_ParentPtr;
                tFieldPtr                       m_ChildPtr;
            };
        } /// end of namespace Struct
    } /// end of namespace MetaData
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_STRUCT_HPP__SHANHAOBO_19800429__*/
