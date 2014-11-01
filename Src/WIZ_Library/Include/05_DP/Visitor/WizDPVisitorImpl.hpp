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
				template <class VisitableT>
				class Type
				{
                protected:
                    typedef VisitableT tVisitable;
				protected:
					Type(){}
				public:
					virtual ~Type(){}
				public:
                    virtual ::Wiz::Void::Type Visit(tVisitable&) = 0;
				}; /// end of class Type

				template <class Head, class Tail>
				class Type< ::Wiz::TypeList::Type<Head, Tail> > : public Type<Head>, public Type<Tail>
				{
				protected:
					Type(){}
				public:
				}; /// end of class Type

				template <class Head>
				class Type< ::Wiz::TypeList::Type<Head, ::Wiz::Null::Type> > : public Type<Head>
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
