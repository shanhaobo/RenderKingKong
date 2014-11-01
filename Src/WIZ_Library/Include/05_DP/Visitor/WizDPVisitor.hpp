#ifndef __WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__

#include "./WizDPVisitorImpl.hpp"

namespace Wiz
{
    namespace DP
    {
        /// 声明Visitor
        namespace Visitor
        {
            template<class ParamT> struct Type;
        } /// end of namespace Visitor

        /// 声明Visitable
        namespace Visitable
        {
            namespace Base
            {
                template<class VisitorT>
                struct Type : public VisitorT::tVisitableBase
                {
                    typedef typename VisitorT::tVisitableBase tSuper;

                    Type() : tSuper()
                    {}

                    template<class T>
                    static ::Wiz::Void::Type AcceptImpl(T* VAPtr, VisitorT& VRef)
                    {
                        return VRef.Visit(*VAPtr);
                    }
                }; /// end of struct Type
            } /// end of namespace Base

            template<class DerivedT, class VisitorT>
            struct Type : public ::Wiz::DP::Visitable::Base::Type<VisitorT>
            {
                typedef ::Wiz::DP::Visitable::Base::Type<VisitorT> tSuper;

                Type() : tSuper()
                {}

                typedef ::Wiz::DP::Visitable::Base::Type<VisitorT> tSuper;

                ::Wiz::Void::Type Accept(VisitorT& VRef)
                {
                    tSuper::AcceptImpl<DerivedT>(::Wiz::Cast::Static<DerivedT*>(this), VRef);
                }
            }; /// end of struct Type
        } /// end of namespace Visitable
    } /// end of namespace DesignPattern
} /// end of namespace Wiz

/////////////////////////////////////////////////////////////////////////////////////////

/// WIZ_TYPELIST_1 ~ WIZ_TYPELIST_127
/// 为了加快编译速度，只是用了1~32个(支持1~127个)

#define WIZ_MPP_REPEAT_FILE_BEGIN   1
#define WIZ_MPP_REPEAT_FILE_END     32
#define WIZ_MPP_REPEAT_FILE_1_NAME  "./WizDPVisitorTemplate.hpp"
#undef  WIZ_MPP_REPEAT_FILE_2_NAME

#include "../../01_Basic/00_MPP/WizBasicMPPRepeatFile.hpp"

#undef WIZ_MPP_REPEAT_FILE_BEGIN
#undef WIZ_MPP_REPEAT_FILE_END

#undef WIZ_MPP_REPEAT_FILE_1_NAME
#undef WIZ_MPP_REPEAT_FILE_2_NAME

/////////////////////////////////////////////////////////////////////////////////////////


#endif /*__WIZ_DESIGNPATTERN_VISITOR_HPP__SHANHAOBO_19800429__*/

