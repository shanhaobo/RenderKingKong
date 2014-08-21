#ifndef __WIZ_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <vector>

#ifndef     WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE
#   define  WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE           WIZ_DECLARE
#endif ///  WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE

#ifndef     WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE
#   define  WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE           WIZ_DECLARE_ITER
#endif ///  WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE

#ifndef     WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE
#   define  WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE     WIZ_DECLARE_ITER_CONST
#endif ///  WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE

namespace Wiz
{
    template< class ElementT, class AllocatorT = ::std::allocator<ElementT> >
    struct Array : private ::std::vector<ElementT, AllocatorT>
    {
        typedef typename ElementT                               tElement;
        typedef typename ElementT const                         tElementConst;
        typedef typename ElementT *                             tElementPtr;
        typedef typename ElementT const *                       tElementConstPtr;

        typedef typename AllocatorT                             tAllocator;

        ///-----------------------///

        typedef typename Array<tElement, tAllocator>            tThis;

        typedef typename ::std::vector<tElement, tAllocator>    tSuper;

        ///-----------------------///

        typedef typename tSuper::iterator                       tIterator;
        typedef typename tSuper::const_iterator                 tIteratorConst;

        ///-----------------------///

        typedef typename tSuper::iterator::value_type           tValue;
        typedef typename tSuper::const_iterator::value_type     tValueConst;

        typedef typename tSuper::reference                      tReference;
        typedef typename tSuper::const_reference                tReferenceConst;

        typedef typename tSuper::reverse_iterator               tReverseIterator;
        typedef typename tSuper::const_reverse_iterator         tReverseIteratorConst;

        typedef typename tSuper::size_type                      tSize;

        //////////////////////////////////////////////////////////////////////////
        WIZ_DECLARE(tThis);
        WIZ_DECLARE_ITER(tIterator);
        WIZ_DECLARE_ITER_CONST(tIteratorConst);

#ifdef  WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE
        WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE(tThis);
#endif  /// WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE

#ifdef  WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE
        WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE(tIterator);
#endif /// WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE

#ifdef  WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE
        WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE(tIteratorConst);
#endif /// WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE
        //////////////////////////////////////////////////////////////////////////
    public:
        Array() : tSuper(){}
        Array(tSuper const & InSuper) : tSuper(InSuper){}

        Array(tSize Reserved) : tSuper(Reserved){}
        Array(tSize Reserved, tElementConst Ele) : tSuper(Reserved, Ele){}

    public:
        ///-----------------------///

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

        tSize Size() const
        {
            return tSuper::size();
        }

        ::Wiz::Void::Type Resize(::Wiz::Size::In NewSZ)
        {
            return tSuper::resize(NewSZ);
        }

        ::Wiz::Void::Type Clear()
        {
            tSuper::clear();
        }

        tIterator Erase(tIterator itr)
        {
            return tSuper::erase(itr);
        }


        ::Wiz::Void::Type Remove(ElementT const & v)
        {
            struct tRemoveInnerStruct
            {
                const ElementT m_Ele;
                tRemoveInnerStruct(const ElementT& InEle) : m_Ele(InEle){}

                bool operator() (const ElementT& InEle)
                {
                    return m_Ele == InEle;
                }
            };

            tRemoveInnerStruct RIS(v);

            RemoveIf(RIS);
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
            tSuper::iterator NewEnd = ::std::remove_if(tSuper::begin(), tSuper::end(), Func);

            tSuper::erase(NewEnd, tSuper::end());
        }

        ///-----------------------///

        ::Wiz::Void::Type PushBack(ElementT const & v)
        {
            tSuper::push_back(v);
        }

        ::Wiz::Void::Type PopBack()
        {
            tSuper::pop_back();
        }

        ///-----------------------///

        tReferenceConst Front() const
        {
            return tSuper::front();
        }

        tReference Front()
        {
            return tSuper::front();
        }

        tReferenceConst Back() const
        {
            return tSuper::back();
        }

        tReference Back()
        {
            return tSuper::back();
        }

        ///-----------------------///

        ::Wiz::Size::Type Capacity()
        {
            return tSuper::capacity();
        }

        ::Wiz::Void::Type Reserve(tSize SZ)
        {
            tSuper::reserve(SZ);
        }

        ///-----------------------///

        tReference operator[](tSize Pos)
        {
            return tSuper::operator [](Pos);
        }

        tReferenceConst operator[](tSize Pos) const
        {
            return tSuper::operator [](Pos);
        }

    public:
        tElementPtr GetBuffer()
        {
            return &(tSuper::operator [](0));
        }

        tElementConstPtr GetBuffer() const
        {
            return &(tSuper::operator [](0));
        }
    };
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_ARRAY_HPP__SHANHAOBO_19800429__*/
