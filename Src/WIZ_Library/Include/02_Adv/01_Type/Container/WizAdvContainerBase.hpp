#ifndef __WIZ_ADV_CONTAINER_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_CONTAINER_BASE_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicTypeDeclareUtils.hpp"

namespace Wiz
{
    namespace Container
    {
        template<class DerivedT, class BaseT>
        class Base : protected BaseT
        {
        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename DerivedT                                   tDerived;

            typedef typename BaseT                                      tSuper;

            //////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::size_type                          tSize;

            //////////////////////////////////////////////////////////////////////////

            WIZ_DECLARE_IN_STDCLASS(tDerived);

#   ifdef   WIZ_CUSTOM_DECLARE_HELPER_CONTAINER
            WIZ_CUSTOM_DECLARE_HELPER_CONTAINER(tDerived);
#   endif   /// WIZ_CUSTOM_DECLARE_HELPER_CONTAINER

            //////////////////////////////////////////////////////////////////////////
        public:
            Base() : tSuper()
            {}
            Base(tSuper const & InSuper) : tSuper(InSuper)
            {}
        public:

            ///-----------------------///

            tSize Size() const
            {
                return tSuper::size();
            }

            ::Wiz::Void::Type Clear()
            {
                tSuper::clear();
            }

            ///-----------------------///
        };

        template<class DerivedT, class BaseT>
        class SimpleBase : public Base<DerivedT, BaseT>
        {
        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename Base<DerivedT, BaseT>                      tContainerSuper;

            //////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::reference                          tReference;
            typedef typename tSuper::const_reference                    tReferenceConst;

            typedef typename tSuper::iterator                           tIterator;
            typedef typename tSuper::const_iterator                     tIteratorConst;

            //////////////////////////////////////////////////////////////////////////

            WIZ_DECLARE_ITER(tIterator);
            WIZ_DECLARE_ITER_CONST(tIteratorConst);

#   ifdef   WIZ_CUSTOM_DECLARE_HELPER_ITERATOR
            WIZ_CUSTOM_DECLARE_HELPER_ITERATOR(tIterator);
#   endif   /// WIZ_CUSTOM_DECLARE_HELPER_ITERATOR

#   ifdef   WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST
            WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST(tIteratorConst);
#   endif  /// WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST

            //////////////////////////////////////////////////////////////////////////
        public:
            SimpleBase() : tContainerSuper()
            {}
            SimpleBase(tSuper const & InSuper) : tContainerSuper(InSuper)
            {}
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

            tIterator Erase(tIterator itr)
            {
                return tSuper::erase(itr);
            }

            ///-----------------------///

            template<class FuncT>
            tIterator FindIf(FuncT Func)
            {
                return ::std::find_if(Begin(), End(), Func);
            }

            template<class FuncT>
            ::Wiz::Void::Type RemoveIf(FuncT Func)
            {
                tIterator ItrNewEnd = ::std::remove_if(Begin(), End(), Func);

                tSuper::erase(ItrNewEnd, End());
            }

            ///-----------------------///
        };

        template<class IndexT, class ValueT, class CompT, class DerivedT, class BaseT>
        class MapBase : public Base<DerivedT, BaseT>
        {
        public:
            //////////////////////////////////////////////////////////////////////////

            typedef typename Base<DerivedT, BaseT>                  tContainerSuper;

            /////////////////////////////////////////////////////////////////////////

            typedef typename IndexT                                 tIndex;
            typedef typename tIndex const                           tIndexConst;
            typedef typename tIndex const &                         tIndexIn;
            typedef typename tIndex &                               tIndexRef;
            typedef typename tIndex const &                         tIndexRefConst;

            typedef typename ValueT                                 tValue;
            typedef typename tValue const                           tValueConst;
            typedef typename tValue const &                         tValueIn;
            typedef typename tValue &                               tValueOut;
            typedef typename tValue &                               tValueRef;
            typedef typename tValue const &                         tValueRefConst;

            typedef typename CompT                                  tComp;

            ////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::iterator                       tSuperIterator;
            typedef typename tSuper::const_iterator                 tSuperIteratorConst;

            //////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::size_type                      tSize;

            ////////////////////////////////////////////////////////////////////////

            typedef typename ::std::pair<tIndex, tValue>            tPair;

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

            WIZ_DECLARE_ITER(tIterator);
            WIZ_DECLARE_ITER_CONST(tIteratorConst);

#   ifdef   WIZ_CUSTOM_DECLARE_HELPER_ITERATOR
            WIZ_CUSTOM_DECLARE_HELPER_ITERATOR(tIterator);
#   endif   /// WIZ_CUSTOM_DECLARE_HELPER_ITERATOR

#   ifdef   WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST
            WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST(tIteratorConst);
#   endif  /// WIZ_CUSTOM_DECLARE_HELPER_ITERATOR_CONST

            ////////////////////////////////////////////////////////////////////////
        public:
            MapBase() : tContainerSuper()
            {}
            MapBase(tSuper const & InSuper) : tContainerSuper(InSuper)
            {}
        public:
            ////////////////////////////////////////////////////////////////////////

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

            tIterator Erase(tIterator itr)
            {
                return tSuper::erase(itr);
            }

            ///-----------------------///

            template<class FuncT>
            tIterator FindIf(FuncT Func)
            {
                return ::std::find_if(Begin(), End(), Func);
            }

            template<class FuncT>
            ::Wiz::Void::Type RemoveIf(FuncT Func)
            {
                tIterator ItrNewEnd = ::std::remove_if(Begin(), End(), Func);

                tSuper::erase(ItrNewEnd, End());
            }

            ///-----------------------///

            tIterator Find(tIndexIn InIndex)
            {
                return tSuper::find(InIndex);
            }

            tIteratorConst Find(tIndexIn InIndex) const
            {
                return tSuper::find(InIndex);
            }

            ///-----------------------///

        };
    } /// end of namespace Container
} /// end of namespace Wiz

#endif /*__WIZ_ADV_CONTAINER_BASE_HPP__SHANHAOBO_19800429__*/
