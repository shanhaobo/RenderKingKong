#ifndef __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorDefault.hpp"

#include "./WizBasicMemAllocatorSTLBase.hpp"

namespace Wiz
{
    namespace Allocator
    {
        /// 这里选择使用哪个Allocator
        typedef Allocator::Default::Type                         Type;

        //////////////////////////////////////////////////////////////////////////

        /// 基本使用
        WIZ_INLINE::Wiz::Void::Ptr AllocateWithDebugInfo(size_t InSZInByte, char const * InFileName, int InLine, char const * InFuncName)
        {
            return Allocator::Type::AllocateWithDebugInfo(InSZInByte, InFileName, InLine, InFuncName);
        }

        WIZ_INLINE::Wiz::Void::Type DeallocateWithDebugInfo(void* ptr)
        {
            Allocator::Type::DeallocateWithDebugInfo(ptr, WIZ_NULLPTR, 0, WIZ_NULLPTR);
        }

        WIZ_INLINE::Wiz::Void::Ptr Allocate(size_t sz)
        {
            return Allocator::Type::Allocate(sz);
        }

        WIZ_INLINE::Wiz::Void::Type Deallocate(void* ptr)
        {
            Allocator::Type::Deallocate(ptr);
        }

        //////////////////////////////////////////////////////////////////////////

        /// STL的Allocator
        template<class ElementT>
        struct STL : public Allocator::STLBase::Type<ElementT, Allocator::Type>
        {
            typedef typename Allocator::STL<ElementT>            Type;
        };

        /// 有分类功能的Allocator
        template<int ICat>
        struct Categorized : public Allocator::Type
        {
            typedef typename Allocator::Categorized<ICat>        Type;
        };

        /// 有分类功能的STL的Allocator
        template<class ElementT, int ICat>
        struct STLCategorized : public Allocator::STL<ElementT>::Type
        {
            typedef typename Allocator::STLCategorized<ElementT, ICat>   Type;
        };

        //////////////////////////////////////////////////////////////////////////

        /// 临时工具
        template<typename T>
        T* ConstructN(T* basePtr, size_t count)
        {
            for (size_t i = 0; i < count; ++i)
            {
                new ((void*)(basePtr + i)) T();
            }

            return basePtr;
        }

    } /// end of namespace Allocator
} /// end of namespace Wiz

//////////////////////////////////////////////////////////////////////////
/// New & Del
//////////////////////////////////////////////////////////////////////////
#   define  WIZ_NEW                                             new (WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_DEL                                             delete

//////////////////////////////////////////////////////////////////////////
/// General
//////////////////////////////////////////////////////////////////////////
#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC(InSZInByte)                              ::Wiz::Allocator::AllocateWithDebugInfo(InSZInByte, WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_FREE(MemPtr)                                    ::Wiz::Allocator::DeallocateWithDebugInfo((void*)MemPtr)
#else
#   define  WIZ_MALLOC(InSZInByte)                              ::Wiz::Allocator::Allocate(InSZInByte)
#   define  WIZ_FREE(MemPtr)                                    ::Wiz::Allocator::Deallocate((void*)MemPtr)
#endif

#   define  WIZ_MALLOC_T(InType)                                static_cast<InType*>(WIZ_MALLOC(sizeof(InType)))
#   define  WIZ_MALLOC_ARRAY_T(InType, InCnt)                   static_cast<InType*>(WIZ_MALLOC(sizeof(InType) * InCnt))

#   define  WIZ_NEW_T(InType)                                   new (WIZ_MALLOC(sizeof(InType))) InType
#   define  WIZ_DEL_T(MemPtr, InType)                           if (MemPtr) {(MemPtr)->~InType(); WIZ_FREE(MemPtr);}

#   define  WIZ_NEW_ARRAY_T(InType, InCnt)                      ::Wiz::Allocator::ConstructN<InType(WIZ_MALLOC_ARRAY_T(InType, InCnt), InCnt);
#   define  WIZ_DEL_ARRAY_T(MemPtr, InType, InCnt)              if(MemPtr) {for (size_t i = 0; i < InCnt; ++i){MemPtr[i].~InType();} WIZ_FREE(MemPtr);}

//////////////////////////////////////////////////////////////////////////
/// With_Cat
//////////////////////////////////////////////////////////////////////////
#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC_CAT(InSZInByte, InCat)                   ::Wiz::Allocator::Categorized<InCat>::AllocateWithDebugInfo(InSZInByte, WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_FREE_CAT(MemPtr, InCat)                         ::Wiz::Allocator::Categorized<InCat>::DeallocateWithDebugInfo((void*)MemPtr)
#else
#   define  WIZ_MALLOC_CAT(InSZInByte, InCat)                   ::Wiz::Allocator::Categorized<InCat>::Allocate(InSZInByte)
#   define  WIZ_FREE_CAT(MemPtr, InCat)                         ::Wiz::Allocator::Categorized<InCat>::Deallocate((void*)MemPtr)
#endif

#   define  WIZ_MALLOC_T_CAT(InType, InCat)                     static_cast<InType*>(WIZ_MALLOC_CAT(sizeof(InType), InCat))
#   define  WIZ_MALLOC_ARRAY_T_CAT(InType, InCnt, InCat)        static_cast<InType*>(WIZ_MALLOC_CAT(sizeof(InType) * InCnt, InCat))

#   define  WIZ_NEW_T_CAT(InType, InCat)                        new (WIZ_MALLOC_CAT(sizeof(InType), InCat)) InType
#   define  WIZ_DEL_T_CAT(MemPtr, InType, InCat)                if(MemPtr) {(MemPtr)->~InType(); WIZ_FREE_CAT(MemPtr, InCat);}

#   define  WIZ_NEW_ARRAY_T_CAT(InType, InCnt, InCat)           ::Wiz::Allocator::ConstructN<InType>(WIZ_MALLOC_ARRAY_T_CAT(InType, InCnt, InCat), InCnt);
#   define  WIZ_DEL_ARRAY_T_CAT(MemPtr, InType, InCnt, InCat)   if(MemPtr) {for (size_t i = 0; i < InCnt; ++i){MemPtr[i].~InType();} WIZ_FREE_CAT(MemPtr, InCat);}

#endif /*__WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__*/
