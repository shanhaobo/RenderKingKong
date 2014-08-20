#ifndef __WIZ_CONTAINER_MAP_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_MAP_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <map>

namespace Wiz
{
    template< class IndexT, class ValueT, class CompT = ::std::less<IndexT> >
    struct Map : private ::std::map<IndexT, ValueT, CompT>
    {
        typedef typename Map<IndexT, ValueT, CompT>         Type;

        /////////////////////////////////////////////////////////////////////////
        typedef typename IndexT                             tIndex;
        typedef typename tIndex const                       tIndexConst;
        typedef typename tIndex const &                     tIndexIn;
        typedef typename tIndex &                           tIndexRef;
        typedef typename tIndex const &                     tIndexRefConst;

        typedef typename ValueT                             tValue;
        typedef typename tValue const                       tValueConst;
        typedef typename tValue const &                     tValueIn;
        typedef typename tValue &                           tValueOut;
        typedef typename tValue &                           tValueRef;
        typedef typename tValue const &                     tValueRefConst;

        typedef typename CompT                              tComp;

        typedef typename ::std::map<tIndex, tValue, tComp>  tSuper;

        ////////////////////////////////////////////////////////////////////////
        typedef typename tSuper::iterator                   tSuperIterator;
        typedef typename tSuper::const_iterator             tSuperIteratorConst;
        ////////////////////////////////////////////////////////////////////////

        typedef typename tSuper::size_type                  tSize;

        typedef typename ::std::pair<tIndex, tValue>        tPair;

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
        Map() : tSuper()
        {
        }
        Map(tSuper const & InSuper) : tSuper(InSuper)
        {
        }
        //////////////////////////////////////////////////////////////////////////
    public:
        tIterator Begin()
        {
            return tSuper::begin();
        }

        tIteratorConst Begin() const
        {
            return tSuper::begin();
        }

        tIterator End()
        {
            return tSuper::end();
        }

        tIteratorConst End() const
        {
            return tSuper::end();
        }

        ///-----------------------///

        tSize Size() const
        {
            return tSuper::size();
        }

        ::Wiz::Void::Type Clear()
        {
            tSuper::clear();
        }

        tIterator Erase(tIterator itr)
        {
            return tSuper::erase(itr);
        }

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

        template<class FuncT>
        tIterator FindIf(FuncT Func)
        {
            return ::std::find_if(tSuper::begin(), tSuper::end(), Func);
        }

        template<class FuncT>
        ::Wiz::Void::Type RemoveIf(FuncT Func)
        {
            tSuper::iterator NewEndItr = ::std::remove_if(tSuper::begin(), tSuper::end(), Func);

            tSuper::erase(NewEndItr, tSuper::end());
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

        ::Wiz::Bool::Type TryGet(tValueOut OutV, tIndexIn v)
        {
            tIterator Want = Find(v);
            if (Want == End())
            {
                return ::Wiz::Bool::False;
            }

            OutV = Want.GetValue();
            return ::Wiz::Bool::True;
        }

        ValueT* TryGetPtr(tIndexIn v)
        {
            tIterator Want = Find(v);
            if (Want == End())
            {
                return WIZ_NULL;
            }

            return &(Want.GetValue());
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

#endif /*__WIZ_CONTAINER_MAP_HPP__SHANHAOBO_19800429__*/
