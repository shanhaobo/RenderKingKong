#ifndef __RENDERKINGKONG_BASEOBJECT_HPP__
#define __RENDERKINGKONG_BASEOBJECT_HPP__

#include "../../../WIZ_Library/include/01_Basic/05_Mem/WizBasicMemObj.hpp"

#include "./BaseAllocator.hpp"

#include "./BaseType.hpp"

//////////////////////////////////////////////////////////////////////////

#define RKK_NEW                                         WIZ_NEW
#define RKK_DEL                                         WIZ_DEL

#define RKK_MALLOC(SizeInByte, inCat)                   WIZ_MALLOC_CAT(SizeInByte, inCat)
#define RKK_FREE(MemPtr, inCat)                         WIZ_FREE_CAT(MemPtr, inCat)
#define RKK_MALLOC_T(inType, inCat)                     WIZ_MALLOC_T_CAT(inType, inCat)
#define RKK_MALLOC_ARRAY_T(inType, inCnt, inCat)        WIZ_MALLOC_ARRAY_T_CAT(inType, inCnt, inCat)

#define RKK_NEW_T(inType, inCat)                        WIZ_NEW_T_CAT(inType, inCat)
#define RKK_DEL_T(MemPtr, inType, inCat)                WIZ_DEL_T_CAT(MemPtr, inType, inCat)

#define RKK_NEW_ARRAY_T(inType, inCnt, inCat)           WIZ_NEW_ARRAY_T_CAT(inType, inCnt, inCat)
#define RKK_DEL_ARRAY_T(MemPtr, inType, inCnt, inCat)   WIZ_DEL_ARRAY_T_CAT(MemPtr, inType, inCnt, inCat)

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
