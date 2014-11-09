#ifndef __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
	namespace DP
    {
        /// ����Visitable
        namespace Visitable
        {
            /// ��ʹ�ù�����,�������������Visitable::Base::Type,Ȼ�������,ʹ�������Visitable::Type
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
                    virtual Void::Type Accept(VisitorT& VisitorRef, tIOParam ioParam) = 0;

                protected:
                    template<class T>
                    static Void::Type StaticAcceptImpl(T* inVisitablePtr, VisitorT& VisitorRef, tIOParam ioParam)
                    {
                        VisitorRef.Visit(*inVisitablePtr, ioParam);
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
                virtual Void::Type Accept(tVisitor& VisitorRef, tIOParam ioParam)
                {
                    StaticAcceptImpl<DerivedT>(::Wiz::Cast::Static<DerivedT*>(this), VisitorRef, ioParam);
                }
            }; /// end of struct Type
        } /// end of namespace Visitable
	} /// end of namespace DesignPattern
} /// end of namespace Wiz

#endif /*__WIZ_DESIGNPATTERN_VISITABLE_HPP__SHANHAOBO_19800429__*/
