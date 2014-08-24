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

        /// STL的Allocator
        template<class ElementT>
        struct STL : public Allocator::STLBase<ElementT, Allocator::Type>::Type
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

#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC(bytes, category)             ::Wiz::Allocator::Categorized<category>::AllocateWithDebugInfo(bytes, WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_FREE(ptr, category)                 ::Wiz::Allocator::Categorized<category>::DeallocateWithDebugInfo((void*)ptr)
#else
#   define  WIZ_MALLOC(bytes, category)             ::Wiz::Allocator::Categorized<category>::Allocate(bytes)
#   define  WIZ_FREE(ptr, category)                 ::Wiz::Allocator::Categorized<category>::Deallocate((void*)ptr)
#endif

#   define  WIZ_MALLOC_T(T, category)               static_cast<T*>(WIZ_MALLOC(sizeof(T), category))
#   define  WIZ_MALLOC_ARRAY_T(T, cnt, category)    static_cast<T*>(WIZ_MALLOC(sizeof(T) * cnt, category))

#   define  WIZ_NEW_T(T, category)                  new (WIZ_MALLOC(sizeof(T), category)) T
#   define  WIZ_DEL_T(ptr, T, category)             if(ptr) {(ptr)->~T(); WIZ_FREE(ptr, category);}

#   define  WIZ_NEW_ARRAY_T(T, cnt, category)       ::Wiz::Allocator::ConstructN<T>(WIZ_MALLOC_ARRAY_T(T, cnt, category), cnt);
#   define  WIZ_DEL_ARRAY_T(ptr, T, cnt, category)  if(ptr) {for (size_t i = 0; i < cnt; ++i){ptr[i].~T();} WIZ_FREE(ptr, category);}

#   define  WIZ_NEW                                 new (WIZ_FILE, WIZ_LINE, WIZ_FUNC)
#   define  WIZ_DEL                                 delete

#endif /*__WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__*/
