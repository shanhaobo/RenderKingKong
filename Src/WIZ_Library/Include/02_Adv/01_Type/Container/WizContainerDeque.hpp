#ifndef __WIZ_CONTAINER_DEQUE_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_DEQUE_HPP__SHANHAOBO_19800429__

#include "./WizContainerBase.hpp"

#include <deque>

namespace Wiz
{
    template<class ElementT, class AllocatorT = ::std::allocator<ElementT> >
    struct Deque : public ::Wiz::Container::Base< Deque<ElementT, AllocatorT>, ::std::deque<ElementT, AllocatorT> >
    {
        //////////////////////////////////////////////////////////////////////////

        typedef typename Deque<ElementT, AllocatorT>                tThis;

        typedef typename ::std::deque<ElementT, AllocatorT>         tSuper;

        typedef ::Wiz::Container::Base< tThis, tSuper >             tContainerBase;

        //////////////////////////////////////////////////////////////////////////

        typedef typename ElementT                                   tElement;
        typedef typename tElement const                             tElementConst;

        typedef typename ElementT *                                 tElementPtr;
        typedef typename ElementT const *                           tElementConstPtr;

        typedef typename tElement const &                           tElementIn;

        //////////////////////////////////////////////////////////////////////////

        typedef typename AllocatorT                                 tAllocator;

        //////////////////////////////////////////////////////////////////////////

    public:

        Deque() : tContainerBase()
        {}

        Deque(tSuper const & InSuper) : tContainerBase(InSuper)
        {}

    public:

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
            return tSuper::find(v) != End();
        }

        ///-----------------------///

        ::Wiz::Bool::Type Remove(tElementIn inELT)
        {
            tIterator FndItr;

            if (Find(inELT, FndItr))
            {
                Erase(FndItr);

                return ::Wiz::Bool::True;
            }

            return ::Wiz::Bool::False;
        }

        ::Wiz::Bool::Type Remove(tElementIn inELT, tIterator& OItr)
        {
            tIterator FndItr;

            if (Find(inELT, FndItr))
            {
                OItr = Erase(FndItr);

                return ::Wiz::Bool::True;
            }

            return ::Wiz::Bool::False;
        }

        ///-----------------------///

        ::Wiz::Void::Type PushBack(tElementIn v)
        {
            tSuper::push_back(v);
        }

        ::Wiz::Void::Type PushFront(tElementIn v)
        {
            tSuper::push_front(v);
        }

        ::Wiz::Void::Type PopBack(tElementIn v)
        {
            tSuper::pop_back(v);
        }

        ::Wiz::Void::Type PopFront(tElementIn v)
        {
            tSuper::pop_front(v);
        }

        tReference Front()
        {
            return tSuper::front();
        }

        tReference Back()
        {
            return tSuper::back();
        }
    };
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_DEQUE_HPP__SHANHAOBO_19800429__*/
