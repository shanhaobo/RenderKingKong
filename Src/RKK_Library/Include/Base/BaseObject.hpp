#ifndef __RENDERKINGKONG_BASEOBJECT_HPP__
#define __RENDERKINGKONG_BASEOBJECT_HPP__

#include "../../../WIZ_Library/Include/01_Basic/05_Mem/WizBasicMemObj.hpp"

#include "./BaseAllocator.hpp"

#include "./BaseType.hpp"

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

        namespace RDL
        {
            RKK_DECLARE(::rkk::Obj::type<Allocator::RDL::type>);
        } /// end of namespace RDL
    } /// end of namespace Obj

    //////////////////////////////////////////////////////////////////////////

} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEOBJECT_HPP__*/
