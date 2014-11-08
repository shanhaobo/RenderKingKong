#ifndef __WIZ_DESIGNPATTERN_VISITOR_IMPL_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITOR_IMPL_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/04_TU/WizBasicTUTypeList.hpp"

namespace Wiz
{
	namespace DP
	{
		namespace Visitor
		{
			namespace Impl
			{
				template <class VisitableT, class ReturnT>
				class Type
				{
                protected:
                    typedef VisitableT                          tVisitable;
				protected:
					Type(){}
				public:
					virtual ~Type(){}
				public:
                    virtual ReturnT Visit(tVisitable&) = 0;
				}; /// end of class Type

                template <class HeadT, class TailT, class ReturnT>
                class Type< ::Wiz::TypeList::Type<HeadT, TailT>, ReturnT > : public Type<HeadT, ReturnT>, public Type<TailT, ReturnT>
				{
				protected:
					Type(){}
				public:
				}; /// end of class Type

                template <class HeadT, class ReturnT>
                class Type< ::Wiz::TypeList::Type<HeadT, ::Wiz::Null::Type>, ReturnT > : public Type<HeadT, ReturnT>
				{
				protected:
					Type(){}
				public:
				}; /// end of class Type
			} /// end of namespace Impl
		} /// end of namespace Visitor
	} /// end of namespace DesignPattern
} /// end of namespace Wiz

#endif /*__WIZ_DESIGNPATTERN_VISITOR_IMPL_HPP__SHANHAOBO_19800429__*/
