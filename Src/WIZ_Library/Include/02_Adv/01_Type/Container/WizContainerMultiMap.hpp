#ifndef __WIZ_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <map>

namespace Wiz
{
    template< class IndexT, class ValueT, class CompT = ::std::less<IndexT>, class AllocatorT = ::std::allocator< ::std::pair<const IndexT, ValueT> >  >
    struct MultiMap : public ::Wiz::Container::Base< MultiMap<IndexT, ValueT, CompT, AllocatorT>, ::std::multimap<IndexT, ValueT, CompT, AllocatorT> >
    {
        ////////////////////////////////////////////////////////////////////////

        typedef typename MultiMap<IndexT, ValueT, CompT, AllocatorT>            tThis;

        typedef typename ::std::multimap<IndexT, ValueT, CompT, AllocatorT>     tSuper;

        typedef typename ::Wiz::Container::Base< tThis, tSuper >                tContainerBase;

        /////////////////////////////////////////////////////////////////////////

        typedef typename IndexT                                                 tIndex;
        typedef typename tIndex const                                           tIndexConst;
        typedef typename tIndex const &                                         tIndexIn;
        typedef typename tIndex &                                               tIndexRef;
        typedef typename tIndex const &                                         tIndexRefConst;

        typedef typename ValueT                                                 tValue;
        typedef typename tValue const                                           tValueConst;
        typedef typename tValue const &                                         tValueIn;
        typedef typename tValue &                                               tValueOut;
        typedef typename tValue &                                               tValueRef;
        typedef typename tValue const &                                         tValueRefConst;

        typedef typename CompT                                                  tComp;

        typedef typename AllocatorT                                             tAllocator;

        ////////////////////////////////////////////////////////////////////////

        typedef typename tSuper::iterator                                       tSuperIterator;
        typedef typename tSuper::const_iterator                                 tSuperIteratorConst;

        ////////////////////////////////////////////////////////////////////////

        typedef typename tSuper::size_type                                      tSize;

        typedef typename ::std::pair<tIndex, tValue>                            tPair;

        ////////////////////////////////////////////////////////////////////////
        struct tIterator : public tSuperIterator
        {
            tIterator()
            {

            }
            tIterator(tSuperIterator Itr) : tSuperIterator(Itr)
            {

            }
            tIndexRefConst Index() const
            {
                return (*this)->first;
            }

            tValueRef Value() const
            {
                return (*this)->second;
            }
        };
        struct tIteratorConst : public tSuperIteratorConst
        {
            tIteratorConst()
            {

            }
            tIteratorConst(tSuperIteratorConst Itr) : tSuperIteratorConst(Itr)
            {

            }
            tIndexRefConst Index() const
            {
                return (*this)->first;
            }

            tValueRefConst Value() const
            {
                return (*this)->second;
            }
        };

        //////////////////////////////////////////////////////////////////////////

    public:
        MultiMap() : tSuper()
        {
        }

        MultiMap(tSuper const & InSuper) : tSuper(InSuper)
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

        tIterator Find(tIndexIn v)
        {
            return tSuper::find(v);
        }

        tIteratorConst Find(tIndexIn v) const
        {
            return tSuper::find(v);
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

        ::Wiz::Bool::Type Insert(tIterator& OutItr, tIndexIn f, tValueIn s)
        {
            ::std::pair<tIterator, ::Wiz::Bool::Type> Result = tSuper::insert(tPair(f, s));
            OutItr = Result.first;
            return Result.second;
        }

        ::Wiz::Bool::Type InsertUnique(tIterator& OutItr, tIndexIn Idx, tValueIn Val)
        {
            if (this->Find(Idx) == this->End())
            {
                OutItr = this->Insert(Idx, Val);
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
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_MULTIMAP_HPP__SHANHAOBO_19800429__*/
