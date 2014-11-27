#ifndef __WIZ_METADATA_BASIC_HPP__SHANHAOBO_19800429__
#define __WIZ_METADATA_BASIC_HPP__SHANHAOBO_19800429__

#include "../01_Basic/01_Type/WizBasicType.hpp"
#include "../01_Basic/04_TU/WizBasicTU.hpp"
#include "../01_Basic/05_Mem/WizBasicMem.hpp"

namespace Wiz
{
    namespace MetaData
    {
        enum OBJ_CAT
        {
            eOC_Field,
        };

        namespace Allocator
        {
            namespace Field
            {
                typedef ::Wiz::Allocator::Categorized<eOC_Field>::Type      Type;
            } /// end of namespace Field
        } /// end of namespace Allocator

        namespace Field
        {
            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace Field

        namespace Property
        {
            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace Property

        namespace Struct
        {
            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace Struct

        namespace Class
        {
            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace Class
    } /// end of namespace MetaData
} /// end of namespace Wiz

#endif /*__WIZ_METADATA_BASIC_HPP__SHANHAOBO_19800429__*/
