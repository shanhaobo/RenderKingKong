#ifndef __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorStd.hpp"

namespace Wiz
{
    namespace MemAllocator
    {
        template<int Cat>
        class Type : public Std::Type {}



        template<typename T>
        T* ConstructN(T* basePtr, size_t count)
        {
            for (size_t i = 0; i < count; ++i)
            {
                new ((void*)(basePtr + i)) T();
            }

            return basePtr;
        }

    } /// end of namespace MemAllocator
} /// end of namespace Wiz

#if  (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define  WIZ_MALLOC(bytes, category)             ::Wiz::MemAllocator::Type<category>::AllocateWithDebugInfo(bytes, __FILE__, __LINE__, __FUNCTION__)
#   define  WIZ_FREE(ptr, category)                 ::Wiz::MemAllocator::Type<category>::DeallocateWithDebugInfo((void*)ptr)
#else
#   define  WIZ_MALLOC(bytes, category)             ::Wiz::MemAllocator::Type<category>::Allocate(bytes)
#   define  WIZ_FREE(ptr, category)                 ::Wiz::MemAllocator::Type<category>::Deallocate((void*)ptr)
#endif

#   define  WIZ_MALLOC_T(T, category)               static_cast<T*>(WIZ_MALLOC(sizeof(T), category))
#   define  WIZ_MALLOC_ARRAY_T(T, cnt, category)    static_cast<T*>(WIZ_MALLOC(sizeof(T) * cnt, category))

#   define  WIZ_NEW_T(T, category)                  new (WIZ_MALLOC(sizeof(T), category)) T
#   define  WIZ_DEL_T(ptr, T, category)             if(ptr) {(ptr)->~T(); WIZ_FREE(ptr, category);}

#   define  WIZ_NEW_ARRAY_T(T, cnt, category)       ::Wiz::MemAllocator::ConstructN<T>(WIZ_MALLOC_ARRAY_T(T, cnt, category), cnt);
#   define  WIZ_DEL_ARRAY_T(ptr, T, cnt, category)  if(ptr) {for (size_t i = 0; i < cnt; ++i){ptr[i].~T();} WIZ_FREE(ptr, category);}

#   define  WIZ_NEW new (__FILE__, __LINE__, __FUNCTION__)
#   define  WIZ_DELETE delete

#endif /*__WIZ_MEM_ALLOCATOR_HPP__SHANHAOBO_19800429__*/
