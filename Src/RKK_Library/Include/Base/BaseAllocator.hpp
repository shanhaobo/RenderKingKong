#ifndef __RENDERKINGKONG_BASEALLOCATOR_HPP__
#define __RENDERKINGKONG_BASEALLOCATOR_HPP__

#include "../../../WIZ_Library/Include/01_Basic/05_Mem/WizBasicMemAllocator.hpp"

//////////////////////////////////////////////////////////////////////////

namespace rkk
{
    namespace ERKK_OBJ_CAT
    {
        enum eROC_General
        {
        };
        enum eROC_Geometry
        {
        };
        enum eROC_Animation
        {
        };
        enum eROC_Resource
        {
        };
        enum eROC_RDL
        {
        };
    } /// end of namespace ERKK_OBJ_CAT
    

    namespace Allocator
    {
        namespace General
        {
            typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::eROC_General>::Type     type;
        } /// end of namespace General

        namespace Geometry
        {
            typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::eROC_Geometry>::Type    type;
        } /// end of namespace Geometry

        namespace Animation
        {
            typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::eROC_Animation>::Type   type;
        } /// end of namespace Animation

        namespace Resource
        {
            typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::eROC_Resource>::Type    type;
        } /// end of namespace Texture

        namespace RDL
        {
            typedef ::Wiz::Allocator::Categorized<ERKK_OBJ_CAT::eROC_RDL>::Type         type;
        } /// end of namespace RDL
    } /// end of namespace Allocator
} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEALLOCATOR_HPP__*/
