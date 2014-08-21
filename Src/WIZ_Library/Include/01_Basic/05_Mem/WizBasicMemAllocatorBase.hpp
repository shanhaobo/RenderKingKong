#ifndef __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemRecorder.hpp"

namespace Wiz
{
    namespace Allocator
    {
        template<class DerivedT>
        class Base
        {
        public:
            typedef typename DerivedT       tDerived;

            typedef typename Base<tDerived> Type;

        public:
            ///////////////////////////////////////////
            /// With Debug Info
            static ::Wiz::Void::Ptr AllocateWithDebugInfo(size_t sz, const char* file, int line, const char* func)
            {
                ::Wiz::Void::Ptr MemPtr = tDerived::Allocate(sz);
                if (::Wiz::IsValidPtr(MemPtr))
                {
                    ::Wiz::MemRecorder::Alloc(MemPtr, sz, file, ln, func);

                    return MemPtr;
                }
                return WIZ_NULL;
            }

            /// With Debug Info
            static ::Wiz::Void::Type DeallocateWithDebugInfo(void* ptr, const char*, int, const char*)
            {
                if (::Wiz::IsValidPtr(ptr))
                {
                    tDerived::Deallocate(ptr);

                    ::Wiz::MemRecorder::Dealloc(ptr);
                }
            }
            ///////////////////////////////////////////
        }; /// end of namespace Base
    } /// end of namespace Allocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__*/
