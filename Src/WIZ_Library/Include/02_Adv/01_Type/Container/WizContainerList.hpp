#ifndef __WIZ_CONTAINER_LIST_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_LIST_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <list>

namespace Wiz
{
    template<class T>
    struct List : private ::std::list<T>
    {
        typedef typename List<T>                                Type;
        //////////////////////////////////////////////////////////////////////////
        typedef typename ::std::list<T>                         tSuper;
        typedef typename tSuper::iterator                       tIterator;
        typedef typename tSuper::const_iterator                 tIteratorConst;
        typedef typename tSuper::iterator::value_type           tValue;
        typedef typename tSuper::const_iterator::value_type     tValueConst;
        typedef typename tSuper::reference                      tReference;
        typedef typename tSuper::const_reference                tReferenceConst;
        typedef typename tSuper::size_type                      tSize;
        //////////////////////////////////////////////////////////////////////////
    public:
        List() : tSuper(){}
        List(const tSuper& InSuper) : tSuper(InSuper){}

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

        ///-----------------------///

        template<class FuncT>
        tIterator FindIf(FuncT Func)
        {
            return ::std::find_if(tSuper::begin(), tSuper::end(), Func);
        }

        template<class FuncT>
        ::Wiz::Void::Type RemoveIf(FuncT Func)
        {
            tSuper::remove_if(Func);
        }

        ///-----------------------///

        ::Wiz::Void::Type Remove(const T& v)
        {
            tSuper::remove(v);
        }

        ::Wiz::Void::Type PushBack(const T& v)
        {
            tSuper::push_back(v);
        }

        ::Wiz::Void::Type PopBack()
        {
            tSuper::pop_back();
        }

        ::Wiz::Void::Type PushFront(const T& v)
        {
            tSuper::push_front(v);
        }

        ::Wiz::Void::Type PopFront()
        {
            tSuper::pop_front();
        }

        ::Wiz::Void::Type Sort()
        {
            tSuper::sort();
        }

        ///-----------------------///

        tReference Front()
        {
            return tSuper::front();
        }

        tReference Back()
        {
            return tSuper::back();
        }

        tReferenceConst Front() const
        {
            return tSuper::front();
        }

        tReferenceConst Back() const
        {
            return tSuper::back();
        }
    };
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_LIST_HPP__SHANHAOBO_19800429__*/
