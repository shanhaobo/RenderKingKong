#ifndef __WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__

#include "./WizMetaDataBasic.hpp"

namespace Wiz
{
    namespace MetaData
    {
        namespace Field
        {
            class Type : public MetaData::Object::Type
            {
            public:
                WIZ_DECLARE_RTTI_BASE(Type);

                typedef Type        tThis;
                typedef tThis*      tThisPtr;

            protected:
                typedef tThis       tField;
                typedef tThisPtr    tFieldPtr;

            public:

            protected:
                tFieldPtr                           m_SiblingPtr;
            };

            namespace Iterator
            {
                template <class T>
                class Type
                {
                    MetaData::Struct::PtrC  StructPtr;
                    MetaData::Field::PtrC   FieldPtr;

                protected:
//                     inline void IterateToNext()
//                     {
//                         MetaData::Field::PtrC  CurrentField = FieldPtr;
//                         MetaData::Struct::PtrC CurrentStruct = StructPtr;
// 
//                         while (CurrentStruct)
//                         {
//                             while (CurrentField)
//                             {
//                                 MetaData::Class::PtrC FieldClass = CurrentField->GetClass();
// 
//                                 if (FieldClass->HasAllCastFlags(T::StaticClassCastFlags()) &&
//                                     (
//                                     bIncludeDeprecated
//                                     || !FieldClass->HasAllCastFlags(CASTCLASS_UProperty)
//                                     || !((UProperty*)CurrentField)->HasAllPropertyFlags(CPF_Deprecated)
//                                     )
//                                     )
//                                 {
//                                     Struct = CurrentStruct;
//                                     Field = CurrentField;
//                                     return;
//                                 }
// 
//                                 CurrentField = CurrentField->Next;
//                             }
// 
//                             if (bIncludeInterface)
//                             {
//                                 // We shouldn't be able to get here for non-classes
//                                 UClass* CurrentClass = (UClass*)CurrentStruct;
//                                 ++InterfaceIndex;
//                                 if (InterfaceIndex < CurrentClass->Interfaces.Num())
//                                 {
//                                     FImplementedInterface& Interface = CurrentClass->Interfaces[InterfaceIndex];
//                                     CurrentField = Interface.Class->Children;
//                                     continue;
//                                 }
//                             }
// 
//                             if (bIncludeSuper)
//                             {
//                                 CurrentStruct = CurrentStruct->GetInheritanceSuper();
//                                 if (CurrentStruct)
//                                 {
//                                     CurrentField = CurrentStruct->Children;
//                                     InterfaceIndex = -1;
//                                     continue;
//                                 }
//                             }
// 
//                             break;
//                         }
// 
//                         Struct = CurrentStruct;
//                         Field = CurrentField;
//                     }
                };
            } /// end of namespace Iterator
        } /// end of namespace Field
    } /// end of namespace MetaData
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_FIELD_HPP__SHANHAOBO_19800429__*/
