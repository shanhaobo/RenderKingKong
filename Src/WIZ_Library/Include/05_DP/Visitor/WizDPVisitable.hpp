#ifndef __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
	namespace DP
    {
        /// ÉùÃ÷Visitable
        namespace Visitable
        {
            namespace Base
            {
                template<class VisitorT, class ReturnT, class ParamT, class BaseT = ::Wiz::Null::Type>
                struct Type : public BaseT
                {
                    typedef VisitorT    tVisitor;
                    typedef ReturnT     tReturn;
                    typedef ParamT      tParam;
                public:
                    Type(){}
                    virtual ~Type(){}

                public:
                    virtual tReturn Accept(VisitorT& VRef, tParam InParam) = 0;

                protected:
                    template<class T>
                    static tReturn StaticAcceptImpl(T* VAPtr, VisitorT& VRef, tParam InParam)
                    {
                        return VRef.Visit(*VAPtr, InParam);
                    }
                }; /// end of struct Type
            } /// end of namespace Base

            template<class DerivedT, class BaseT>
            struct Type : public BaseT
            {
                typedef BaseT                       tSuper;

                typedef typename tSuper::tVisitor   tVisitor;
                typedef typename tSuper::tReturn    tReturn;
                typedef typename tSuper::tParam     tParam;
            public:
                Type() : tSuper()
                {}

            public:
                virtual tReturn Accept(tVisitor& VRef, tParam InParam)
                {
                    return StaticAcceptImpl<DerivedT>(::Wiz::Cast::Static<DerivedT*>(this), VRef, InParam);
                }
            }; /// end of struct Type
        } /// end of namespace Visitable
	} /// end of namespace DesignPattern
} /// end of namespace Wiz

#endif /*__WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__*/
