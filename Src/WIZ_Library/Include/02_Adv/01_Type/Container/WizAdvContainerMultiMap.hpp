#ifndef __WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <map>

namespace Wiz
{
    namespace MultiMap
    {
        template< class IndexT, class ValueT, class CompT = ::std::less<IndexT>, class AllocatorT = ::std::allocator< ::std::pair<const IndexT, ValueT> >  >
        class Type : public ::Wiz::Container::MapBase< IndexT, ValueT, CompT, Type<IndexT, ValueT, CompT, AllocatorT>, ::std::multimap<IndexT, ValueT, CompT, AllocatorT> >
        {
        public:
            ////////////////////////////////////////////////////////////////////////

            typedef typename Type<IndexT, ValueT, CompT, AllocatorT>                            tThis;

            typedef typename ::std::multimap<IndexT, ValueT, CompT, AllocatorT>                 tSuper;

            typedef typename ::Wiz::Container::MapBase<IndexT, ValueT, CompT, tThis, tSuper>    tContainerBase;

            /////////////////////////////////////////////////////////////////////////

            typedef typename AllocatorT                                                         tAllocator;

            ////////////////////////////////////////////////////////////////////////

        public:
            Type() : tContainerBase()
            {
            }

            Type(tSuper const & InSuper) : tContainerBase(InSuper)
            {
            }
            //////////////////////////////////////////////////////////////////////////
        public:

            ::Wiz::Bool::Type Remove(tIndexIn v)
            {
                tIterator Found = Find(v);
                if (Found == End())
                {
                    return ::Wiz::Bool::False;
                }

                Erase(Found);

                return ::Wiz::Bool::True;
            }

            tIterator Pop(tIndexIn v)
            {
                tIterator Found = Find(v);
                if (Found == End())
                {
                    return End();
                }

                return Erase(Found);
            }

            ///-----------------------///

            ::Wiz::Bool::Type HasData(tIndexIn v) const
            {
                return tSuper::find(v) != tSuper::end();
            }

            ///-----------------------///

            ::Wiz::Size::Type CountBound(tIndexIn v)
            {
                return tSuper::count(v);
            }

            tIterator LowerBound(tIndexIn v)
            {
                return tSuper::lower_bound(v);
            }

            tIterator UpperBound(tIndexIn v)
            {
                return tSuper::upper_bound(v);
            }

            ///-----------------------///

            tIterator Insert(tIndexIn f, tValueIn s)
            {
                return tSuper::insert(tPair(f, s)).first;
            }

            ::Wiz::Bool::Type Insert(tIterator& outItr, tIndexIn f, tValueIn s)
            {
                ::std::pair<tIterator, ::Wiz::Bool::Type> Result = tSuper::insert(tPair(f, s));
                outItr = Result.first;
                return Result.second;
            }

            ::Wiz::Bool::Type InsertUnique(tIterator& outItr, tIndexIn Idx, tValueIn Val)
            {
                if (this->Find(Idx) == this->End())
                {
                    outItr = this->Insert(Idx, Val);
                    return ::Wiz::Bool::True;
                }
                return ::Wiz::Bool::False;
            }

            ::Wiz::Bool::Type InsertUnique(tIndexIn Idx, tValueIn Val)
            {
                tIterator DummyItr;
                return InsertUnique(DummyItr, Idx, Val);
            }

            //////////////////////////////////////////////////////////////////////////
        };
    } /// end of namespace MultiMap
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__*/
