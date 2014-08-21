#ifndef __RENDERKINGKONG_BASEOBJECT_HPP__
#define __RENDERKINGKONG_BASEOBJECT_HPP__

#include "../../../WIZ_Library/Include/01_Basic/05_Mem/WizBasicMem.hpp"

//////////////////////////////////////////////////////////////////////////

#define RKK_NEW                                     WIZ_NEW
#define RKK_DEL                                     WIZ_DEL

#define RKK_MALLOC(bytes, category)                 WIZ_MALLOC(bytes, category)
#define RKK_FREE(ptr, category)                     WIZ_FREE(ptr, category)
#define RKK_MALLOC_T(T, category)                   WIZ_MALLOC_T(T, category)
#define RKK_MALLOC_ARRAY_T(T, cnt, category)        WIZ_MALLOC_ARRAY_T(T, cnt, category)

#define RKK_NEW_T(T, category)                      WIZ_NEW_T(T, category)
#define RKK_DEL_T(ptr, T, category)                 WIZ_DEL_T(ptr, T, category)

#define RKK_NEW_ARRAY_T(T, cnt, category)           WIZ_NEW_ARRAY_T(T, cnt, category)
#define RKK_DEL_ARRAY_T(ptr, T, cnt, category)      WIZ_DEL_ARRAY_T(ptr, T, cnt, category)

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

    //////////////////////////////////////////////////////////////////////////

    namespace Obj
    {
        namespace Animation
        {
            RKK_DECLARE(::Wiz::MemObj::Type<Allocator::Animation::type>);
        } /// end of namespace Animation

        namespace Texture
        {
            RKK_DECLARE(::Wiz::MemObj::Type<Allocator::Resource::type>);
        } /// end of namespace Texture

        namespace RDL
        {
            RKK_DECLARE(::Wiz::MemObj::Type<Allocator::RDL::type>);
        } /// end of namespace RDL
    } /// end of namespace Obj
} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEOBJECT_HPP__*/
