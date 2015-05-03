#ifndef __WHIMSY_ALLOCATOR_HPP__
#define __WHIMSY_ALLOCATOR_HPP__

#include "../../WIZ_Library/include/01_Basic/05_Mem/WizBasicMemAllocator.hpp"

//////////////////////////////////////////////////////////////////////////

namespace wms
{
    namespace EWMS_OBJ_CAT
    {
        WIZ_ACD(eROC_General);
        WIZ_ACD(eROC_Geometry);
        WIZ_ACD(eROC_Animation);
        WIZ_ACD(eROC_Resource);
        WIZ_ACD(eROC_RDL);
    } /// end of namespace EWMS_OBJ_CAT

    namespace Allocator
    {
        namespace General
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eROC_General>::Type     type;
        } /// end of namespace General

        namespace Geometry
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eROC_Geometry>::Type    type;
        } /// end of namespace Geometry

        namespace Animation
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eROC_Animation>::Type   type;
        } /// end of namespace Animation

        namespace Resource
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eROC_Resource>::Type    type;
        } /// end of namespace Texture

        namespace RDL
        {
            typedef ::Wiz::Allocator::Categorized<EWMS_OBJ_CAT::eROC_RDL>::Type         type;
        } /// end of namespace RDL
    } /// end of namespace Allocator
} /// end of namespace wms

//////////////////////////////////////////////////////////////////////////

#endif /*__WHIMSY_ALLOCATOR_HPP__*/
