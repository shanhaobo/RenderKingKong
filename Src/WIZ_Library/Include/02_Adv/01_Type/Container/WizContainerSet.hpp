#ifndef __WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <set>

namespace Wiz
{
    template< class ElementT, class CompT = ::std::less<ElementT>, class AllocatorT = ::std::allocator<ElementT> >
    struct Set : public ::Wiz::Container::Base< Set<ElementT, CompT, AllocatorT>, ::std::set<ElementT, CompT, AllocatorT> >
    {
        //////////////////////////////////////////////////////////////////////////

        typedef typename Set<ElementT, AllocatorT>                  tThis;

        typedef typename ::std::set<ElementT, CompT, AllocatorT>    tSuper;

        typedef typename ::Wiz::Container::Base< tThis, tSuper >    tContainerBase;

        //////////////////////////////////////////////////////////////////////////

        typedef typename ElementT                                   tElement;
        typedef typename tElement const                             tElementConst;

        typedef typename tElement *                                 tElementPtr;
        typedef typename tElement const *                           tElementConstPtr;

        typedef typename tElement const &                           tElementIn;

        typedef typename CompT                                      tComp;

        typedef typename AllocatorT                                 tAllocator;

        //////////////////////////////////////////////////////////////////////////

        typedef typename tSuper::reverse_iterator                   tReverseIterator;
        typedef typename tSuper::const_reverse_iterator             tReverseIteratorConst;

        //////////////////////////////////////////////////////////////////////////

    public:
        Set() : tContainerBase()
        {}

        Set(tSuper const & InSuper) : tContainerBase(InSuper)
        {}

    public:

        ///-----------------------///

        tReverseIterator RBegin()
        {
            return tSuper::rbegin();
        }

        tReverseIteratorConst RBegin() const
        {
            return tSuper::rbegin();
        }

        tReverseIterator REnd()
        {
            return tSuper::rend();
        }

        tReverseIteratorConst REnd() const
        {
            return tSuper::rend();
        }

        ///-----------------------///

        tIterator Find(tElementIn v)
        {
            return tSuper::find(v);
        }

        tIteratorConst Find(tElementIn v) const
        {
            return tSuper::find(v);
        }

        ::Wiz::Bool::Type Find(tElementIn v, tIterator& OItr)
        {
            OItr = Find(v);
            return OItr != End();
        }

        ::Wiz::Bool::Type Find(tElementIn v, tIteratorConst& OItr) const
        {
            OItr = Find(v);
            return OItr != End();
        }

        ///-----------------------///

        ::Wiz::Bool::Type HasData(tElementIn v) const
        {
            return tSuper::find(v) != tSuper::end();
        }

        ///-----------------------///

        ::Wiz::Bool::Type Insert(tElementIn i)
        {
            ::std::pair<tIterator, ::Wiz::Bool::Type> Result;

            Result = tSuper::insert(i);

            return Result.second;
        }

        ::Wiz::Bool::Type Insert(tElementIn i, tIterator& Itr)
        {
            ::std::pair<tIterator, ::Wiz::Bool::Type> Result;

            Result = tSuper::insert(i);
            Itr = Result.first;
            return Result.second;
        }


        ::Wiz::Bool::Type InsertUnique(tElementIn Val)
        {
            if (this->Find(Val) == this->End())
            {
                this->Insert(Val);
                return ::Wiz::Bool::True;
            }
            return ::Wiz::Bool::False;
        }

        ::Wiz::Bool::Type InsertUnique(tElementIn Val, tIterator& Itr)
        {
            if (this->Find(Val) == this->End())
            {
                Itr = this->Insert(Val);
                return ::Wiz::Bool::True;
            }
            return ::Wiz::Bool::False;
        }

        ::Wiz::Bool::Type Remove(tElementIn ELT)
        {
            tIterator Found = Find(ELT);
            if (Found == End())
            {
                return ::Wiz::Bool::False;
            }

            this->Erase(Found);
            return ::Wiz::Bool::True;
        }

        ::Wiz::Bool::Type Remove(tElementIn ELT, tIterator& Itr)
        {
            tIterator Found = Find(ELT);
            if (Found == End())
            {
                return ::Wiz::Bool::False;
            }

            Itr = this->Erase(Found);
            return ::Wiz::Bool::True;
        }

        ///-----------------------///
    };
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__*/
