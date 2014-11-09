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
                template<class VisitorT, class IOParamT, class BaseT = ::Wiz::Null::Type>
                struct Type : public BaseT
                {
                    typedef VisitorT    tVisitor;
                    typedef IOParamT    tIOParam;
                public:
                    Type() : BaseT(){}
                    virtual ~Type(){}

                public:
                    virtual Void::Type Accept(VisitorT& VRef, tIOParam ioParam) = 0;

                protected:
                    template<class T>
                    static Void::Type StaticAcceptImpl(T* inVAPtr, VisitorT& VRef, tIOParam ioParam)
                    {
                        VRef.Visit(*inVAPtr, ioParam);
                    }
                }; /// end of struct Type
            } /// end of namespace Base

            template<class DerivedT, class BaseT>
            struct Type : public BaseT
            {
                typedef BaseT                       tSuper;

                typedef typename tSuper::tVisitor   tVisitor;
                typedef typename tSuper::tIOParam   tIOParam;
            public:
                Type() : tSuper(){}
                virtual ~Type(){}

            public:
                virtual Void::Type Accept(tVisitor& VRef, tIOParam ioParam)
                {
                    StaticAcceptImpl<DerivedT>(::Wiz::Cast::Static<DerivedT*>(this), VRef, ioParam);
                }
            }; /// end of struct Type
        } /// end of namespace Visitable
	} /// end of namespace DesignPattern
} /// end of namespace Wiz

#endif /*__WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__*/
