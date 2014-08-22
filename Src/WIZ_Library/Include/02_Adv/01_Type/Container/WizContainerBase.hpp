#ifndef __WIZ_CONTAINER_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_BASE_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <set>

namespace Wiz
{
    namespace Container
    {
        template<class DerivedT, class BaseT>
        struct Base : public BaseT
        {
            //////////////////////////////////////////////////////////////////////////

            typedef typename DerivedT                                   tDerived;

            //////////////////////////////////////////////////////////////////////////

            typedef typename BaseT                                      tSuper;

            typedef typename tSuper::iterator                           tIterator;
            typedef typename tSuper::const_iterator                     tIteratorConst;

            typedef typename tSuper::iterator::value_type               tValue;
            typedef typename tSuper::const_iterator::value_type         tValueConst;

            typedef typename tSuper::reference                          tReference;
            typedef typename tSuper::const_reference                    tReferenceConst;

            //////////////////////////////////////////////////////////////////////////

            typedef typename tSuper::size_type                          tSize;

            //////////////////////////////////////////////////////////////////////////

            WIZ_DECLARE(tDerived);
            WIZ_DECLARE_ITER(tIterator);
            WIZ_DECLARE_ITER_CONST(tIteratorConst);

#ifdef  WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE
            WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE(tDerived);
#endif  /// WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE

#ifdef  WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE
            WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE(tIterator);
#endif /// WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE

#ifdef  WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE
            WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE(tIteratorConst);
#endif /// WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE

            //////////////////////////////////////////////////////////////////////////
        public:
            Base() : tSuper()
            {}
            Base(tSuper const & InSuper) : tSuper(InSuper)
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
                return ::std::find_if(Begin(), End(), Func);
            }

            template<class FuncT>
            ::Wiz::Void::Type RemoveIf(FuncT Func)
            {
                tSuper::iterator NewEnd = ::std::remove_if(Begin(), End(), Func);

                tSuper::erase(NewEnd, End());
            }

            ///-----------------------///
        };
    } /// end of namespace Container
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_BASE_HPP__SHANHAOBO_19800429__*/
