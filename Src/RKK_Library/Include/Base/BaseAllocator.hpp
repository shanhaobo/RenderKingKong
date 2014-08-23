#ifndef __RENDERKINGKONG_BASEALLOCATOR_HPP__
#define __RENDERKINGKONG_BASEALLOCATOR_HPP__

#include "../../../WIZ_Library/Include/01_Basic/05_Mem/WizBasicMemAllocator.hpp"

//////////////////////////////////////////////////////////////////////////

namespace rkk
{
    enum ERKK_OBJ_CAT
    {
        eROC_General,
        eROC_Geometry,
        eROC_Animation,
        eROC_Resource,
        eROC_RDL,
    };

    namespace Allocator
    {
        namespace General
        {
            typedef ::Wiz::Allocator::Categorized<eROC_General>::Type     type;
        } /// end of namespace General

        namespace Geometry
        {
            typedef ::Wiz::Allocator::Categorized<eROC_Geometry>::Type    type;
        } /// end of namespace Geometry

        namespace Animation
        {
            typedef ::Wiz::Allocator::Categorized<eROC_Animation>::Type   type;
        } /// end of namespace Animation

        namespace Resource
        {
            typedef ::Wiz::Allocator::Categorized<eROC_Resource>::Type    type;
        } /// end of namespace Texture

        namespace RDL
        {
            typedef ::Wiz::Allocator::Categorized<eROC_RDL>::Type         type;
        } /// end of namespace RDL
    } /// end of namespace Allocator
} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEALLOCATOR_HPP__*/
