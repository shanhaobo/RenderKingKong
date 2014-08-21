#ifndef __WIZ_MEM_ALLOCATOR_STLBASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MEM_ALLOCATOR_STLBASE_HPP__SHANHAOBO_19800429__

#include "./WizBasicMemAllocatorBase.hpp"

#include <numeric>

/// ·ûºÏSTLBaseµÄAllocator·â×°
namespace Wiz
{
    namespace Allocator
    {
        template<typename ElementT, typename RealAllocatorT>
        class STLBase : public ::Wiz::Allocator::Base<RealAllocatorT>::Type
        {
        public:
            typedef typename ElementT                                       tElement;
            typedef typename RealAllocatorT                                 tRealAllocator;

            typedef typename ::Wiz::Allocator::Base<tRealAllocator>::Type   tSuper;

            typedef typename STLBase<tElement, tRealAllocator>              Type;

            ///////////////////////////////////////////
            /// STLBase allocator's standard types
        public:
            typedef typename ElementT                                       value_type;
            typedef typename value_type*                                    pointer;
            typedef typename value_type const *                             const_pointer;
            typedef typename value_type &                                   reference;
            typedef typename value_type const &                             const_reference;
            typedef typename ::std::size_t                                  size_type;
            typedef typename ::std::ptrdiff_t                               difference_type;

            ///////////////////////////////////////////
        public:
            /// standard rebind
            template<typename OtherElementT>
            struct rebind
            {
                typedef typename STLBase<OtherElementT, tRealAllocator>     other;
            };

            ///////////////////////////////////////////
            /// ctor
            inline explicit STLBase()
            { }

            /// dtor
            virtual ~STLBase()
            { }

            /// copy ctor - done component wise
            inline STLBase(STLBase const &)
            { }

            /// cast
            template <typename OtherElementT>
            inline STLBase(STLBase<OtherElementT, tRealAllocator> const &)
            { }

            /// cast
            template <typename OtherElementT, typename OtherRealAllocatorT>
            inline STLBase(STLBase<OtherElementT, OtherRealAllocatorT> const &)
            { }


            ///////////////////////////////////////////
            /// memory allocation (elements, used by STLBase)
            inline pointer allocate(size_type count, typename std::allocator<void>::const_pointer ptr = 0)
            {
                (void)ptr;
                // convert request to bytes
                register size_type sz = count * sizeof(value_type);
                pointer p = static_cast<pointer>(tRealAllocator::Allocate(sz));
                return p;
            }

            /// memory deallocation (elements, used by STLBase)
            inline void deallocate(pointer ptr, size_type)
            {
                // convert request to bytes, but we can't use this?
                // register size_type sz = count*sizeof( T );
                tRealAllocator::Deallocate(ptr);
            }

            pointer address(reference x) const
            {
                return &x;
            }

            const_pointer address(const_reference x) const
            {
                return &x;
            }

            size_type max_size() const throw()
            {
                // maximum size this can handle, delegate
                return ::std::numeric_limits<value_type>::(max)() / sizeof(value_type);
            }

#if __cplusplus < 201103L
            void construct(pointer p)
            {
                // call placement new
                new(static_cast<void*>(p)) value_type();
            }
#endif

            void construct(pointer p, value_type const & val)
            {
                // call placement new
                new(static_cast<void*>(p)) value_type(val);
            }

            void destroy(pointer p)
            {
                // do we have to protect against non-classes here?
                // some articles suggest yes, some no
                p->~tElement();
            }
        };
    } /// end of namespace Allocator
} /// end of namespace Wiz

#endif /*__WIZ_MEM_ALLOCATOR_STLBASE_HPP__SHANHAOBO_19800429__*/
 