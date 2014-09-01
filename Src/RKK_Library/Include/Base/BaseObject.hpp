#ifndef __RENDERKINGKONG_BASEOBJECT_HPP__
#define __RENDERKINGKONG_BASEOBJECT_HPP__

#include "../../../WIZ_Library/Include/01_Basic/05_Mem/WizBasicMemObj.hpp"

#include "./BaseAllocator.hpp"

#include "./BaseType.hpp"

//////////////////////////////////////////////////////////////////////////

#define RKK_NEW                                         WIZ_NEW
#define RKK_DEL                                         WIZ_DEL

#define RKK_MALLOC(SizeInByte, InCat)                   WIZ_MALLOC_CAT(SizeInByte, InCat)
#define RKK_FREE(MemPtr, InCat)                         WIZ_FREE_CAT(MemPtr, InCat)
#define RKK_MALLOC_T(InType, InCat)                     WIZ_MALLOC_T_CAT(InType, InCat)
#define RKK_MALLOC_ARRAY_T(InType, InCnt, InCat)        WIZ_MALLOC_ARRAY_T_CAT(InType, InCnt, InCat)

#define RKK_NEW_T(InType, InCat)                        WIZ_NEW_T_CAT(InType, InCat)
#define RKK_DEL_T(MemPtr, InType, InCat)                WIZ_DEL_T_CAT(MemPtr, InType, InCat)

#define RKK_NEW_ARRAY_T(InType, InCnt, InCat)           WIZ_NEW_ARRAY_T_CAT(InType, InCnt, InCat)
#define RKK_DEL_ARRAY_T(MemPtr, InType, InCnt, InCat)   WIZ_DEL_ARRAY_T_CAT(MemPtr, InType, InCnt, InCat)

//////////////////////////////////////////////////////////////////////////

namespace rkk
{
    //////////////////////////////////////////////////////////////////////////

    namespace Obj
    {

        template <class AllocatorT>
        class WIZ_EXPORT type : public ::Wiz::MemObj::Type<AllocatorT>
        {
        public:
            explicit type()
            { }

            ~type()
            { }

        protected:
            Name::type m_ObjName;
        };

        namespace Animation
        {
            RKK_DECLARE(::rkk::Obj::type<Allocator::Animation::type>);
        } /// end of namespace Animation

        namespace Texture
        {
            RKK_DECLARE(::rkk::Obj::type<Allocator::Resource::type>);
        } /// end of namespace Texture

        namespace Plugin
        {
            RKK_DECLARE(::rkk::Obj::type<Allocator::General::type>);
        } /// end of namespace Plugin

        namespace RDL
        {
            RKK_DECLARE(::rkk::Obj::type<Allocator::RDL::type>);
        } /// end of namespace RDL
    } /// end of namespace Obj

    //////////////////////////////////////////////////////////////////////////

} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEOBJECT_HPP__*/
