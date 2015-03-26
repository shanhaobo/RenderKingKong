#ifndef __WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__

#include "./WizAdvContainerBase.hpp"

#include <map>

namespace Wiz
{
    namespace Map
    {
        template< class IndexT, class ValueT, class CompT = ::std::less<IndexT>, class AllocatorT = ::std::allocator< ::std::pair<const IndexT, ValueT> > >
        class Type : public ::Wiz::Container::MapBase< IndexT, ValueT, CompT, Type<IndexT, ValueT, CompT, AllocatorT>, ::std::map<IndexT, ValueT, CompT, AllocatorT> >
        {
        public:
            ////////////////////////////////////////////////////////////////////////

            typedef typename Type<IndexT, ValueT, CompT, AllocatorT>                            tThis;

            typedef typename ::std::map<IndexT, ValueT, CompT, AllocatorT>                      tSuper;

            typedef typename ::Wiz::Container::MapBase<IndexT, ValueT, CompT, tThis, tSuper>    tContainerBase;

            //////////////////////////////////////////////////////////////////////////

            typedef typename AllocatorT                                                         tAllocator;

            //////////////////////////////////////////////////////////////////////////

        public:
            Type() : tContainerBase()
            {
            }

            Type(tSuper const & InSuper) : tContainerBase(InSuper)
            {
            }

            //////////////////////////////////////////////////////////////////////////
        public:
            ::Wiz::Bool::Type Remove(tIndexIn InIdx)
            {
                tIterator FndItr = Find(InIdx);
                if (FndItr == End())
                {
                    return ::Wiz::Bool::False;
                }

                Erase(FndItr);

                return ::Wiz::Bool::True;
            }

            tIterator Pop(tIndexIn InIdx)
            {
                tIterator FndItr = Find(InIdx);
                if (FndItr == End())
                {
                    return End();
                }

                return Erase(FndItr);
            }

            ///-----------------------///

            tIterator Find(tIndexIn InIdx)
            {
                return tSuper::find(InIdx);
            }

            tIteratorConst Find(tIndexIn InIdx) const
            {
                return tSuper::find(InIdx);
            }

            ///-----------------------///

            ::Wiz::Bool::Type HasData(tIndexIn InIdx) const
            {
                return tSuper::find(InIdx) != tSuper::end();
            }

            ///-----------------------///

            ::Wiz::Bool::Type TryGet(tValueOut outV, tIndexIn InIdx)
            {
                tIterator FndItr = Find(InIdx);
                if (FndItr == End())
                {
                    return ::Wiz::Bool::False;
                }

                outV = FndItr.Value();

                return ::Wiz::Bool::True;
            }

            ValueT* TryGetPtr(tIndexIn InIdx)
            {
                tIterator FndItr = Find(InIdx);
                if (FndItr == End())
                {
                    return WIZ_NULL;
                }

                return &(FndItr.Value());
            }

            ///-----------------------///

            tIterator Insert(tIndexIn InIdx, tValueIn InVl)
            {
                return tSuper::insert(tPair(InIdx, InVl)).first;
            }

            ::Wiz::Bool::Type Insert(tIterator& outItr, tIndexIn InIdx, tValueIn InVl)
            {
                ::std::pair<tIterator, ::Wiz::Bool::Type> Result = tSuper::insert(tPair(InIdx, InVl));
                outItr = Result.first;
                return Result.second;
            }

            ::Wiz::Bool::Type InsertUnique(tIterator& outItr, tIndexIn InIdx, tValueIn InVl)
            {
                if (Find(InIdx) == End())
                {
                    outItr = Insert(InIdx, InVl);
                    return ::Wiz::Bool::True;
                }
                return ::Wiz::Bool::False;
            }

            ::Wiz::Bool::Type InsertUnique(tIndexIn InIdx, tValueIn InVl)
            {
                tIterator DummyItr;
                return InsertUnique(DummyItr, InIdx, InVl);
            }

            //////////////////////////////////////////////////////////////////////////
        };
    } /// end of namespace Map
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_MAP_HPP__SHANHAOBO_19800429__*/
