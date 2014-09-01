#ifndef __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemRecorder.hpp"

namespace Wiz
{
    namespace Allocator
    {
        namespace Base
        {
            template<class DerivedT>
            class Type
            {
            public:
                typedef typename DerivedT       tDerived;

                typedef typename Type<tDerived> tThis;

                WIZ_DECLARE_IN_STDCLASS(tThis);

            public:
                ///////////////////////////////////////////
                /// With Debug Info
                static ::Wiz::Void::Ptr AllocateWithDebugInfo(size_t InSZInByte, char const * InFileName, int InLine, char const * InFuncName)
                {
                    ::Wiz::Void::Ptr MemPtr = tDerived::Allocate(InSZInByte);
                    if (::Wiz::IsValidPtr(MemPtr))
                    {
                        ::Wiz::MemRecorder::Alloc(MemPtr, InSZInByte, InFileName, InLine, InFuncName);

                        return MemPtr;
                    }
                    return WIZ_NULL;
                }

                /// With Debug Info
                static ::Wiz::Void::Type DeallocateWithDebugInfo(void* MemPtr, const char*, int, const char*)
                {
                    if (::Wiz::IsValidPtr(MemPtr))
                    {
                        tDerived::Deallocate(MemPtr);

                        ::Wiz::MemRecorder::Dealloc(MemPtr);
                    }
                }
                ///////////////////////////////////////////
            }; /// end of class Type
        }  /// end of namespace Base
    } /// end of namespace Allocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_BASE_HPP__SHANHAOBO_19800429__*/
