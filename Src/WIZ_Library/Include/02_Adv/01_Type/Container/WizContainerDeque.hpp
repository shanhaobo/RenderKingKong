#ifndef __WIZ_CONTAINER_DEQUE_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_DEQUE_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <deque>

namespace Wiz
{
    template<class T>
    struct Deque : private ::std::deque<T>
    {
        //////////////////////////////////////////////////////////////////////////

        typedef typename Deque<T>                               Type;

        //////////////////////////////////////////////////////////////////////////
        typedef typename ::std::deque<T>                        tSuper;

        typedef typename tSuper::iterator                       tIterator;
        typedef typename tSuper::const_iterator                 tIteratorConst;
        typedef typename tSuper::iterator::value_type           tValue;
        typedef typename tSuper::const_iterator::value_type     tValueConst;
        typedef typename tSuper::reference                      tReference;
        typedef typename tSuper::const_reference                tReferenceConst;
        //////////////////////////////////////////////////////////////////////////
    public:
        Deque() : tSuper(){}
        Deque(const tSuper& InSuper) : tSuper(InSuper){}
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

        ::Wiz::Size::Type Size() const
        {
            return ::Wiz::Cast::Static<::Wiz::Size::Type>(tSuper::size());
        }

        ::Wiz::Void::Type Clear()
        {
            tSuper::clear();
        }

        tIterator Erase(tIterator itr)
        {
            return tSuper::erase(itr);
        }

        ///-----------------------///

        template<class FuncT>
        ::Wiz::Void::Type FindIf(FuncT Func)
        {
            ::std::find_if(tSuper::begin(), tSuper::end(), Func);
        }

        template<class FuncT>
        ::Wiz::Void::Type RemoveIf(FuncT Func)
        {
            tSuper::iterator newend = ::std::remove_if(tSuper::begin(), tSuper::end(), Func);
            tSuper::erase(newend, tSuper::end());
        }

        ///-----------------------///


        ::Wiz::Void::Type PushBack(const T& v)
        {
            tSuper::push_back(v);
        }

        ::Wiz::Void::Type PushFront(const T& v)
        {
            tSuper::push_front(v);
        }

        ::Wiz::Void::Type PopBack(const T& v)
        {
            tSuper::pop_back(v);
        }

        ::Wiz::Void::Type PopFront(const T& v)
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
