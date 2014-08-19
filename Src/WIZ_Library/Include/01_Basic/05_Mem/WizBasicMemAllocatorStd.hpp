#ifndef __WIZ_MEM_ALLOCATOR_STD_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_STD_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorBase.hpp"

#include <memory>

namespace Wiz
{
    namespace MemAllocator
    {
        namespace Std
        {
            WIZ_CLASS : public Base::Type<Type>
            {
            public:
                ///////////////////////////////////////////

                static WIZ_INLINE ::Wiz::Void::Ptr Allocate(size_t sz)
                {
                    return ::malloc(sz);
                }

                static WIZ_INLINE::Wiz::Void::Type Deallocate(void* ptr)
                {
                    ::free(ptr);
                }
                ///////////////////////////////////////////
            };
        } /// end of namespace Base
    } /// end of namespace MemAllocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_STD_HPP__SHANHAOBO_19800429__*/
