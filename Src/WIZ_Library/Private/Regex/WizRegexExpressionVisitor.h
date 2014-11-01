#ifndef __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__

#include "./WizRegexExpression.h"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            namespace Visitor
            {
                struct Type : public ::Wiz::DP::Visitor::Type<Expression::Type(Sequence::Type, Alternative::Type, Repeat::Type)>
                {
                    virtual Void::Type Visit(Sequence::Ref ioExpRef) = 0;
                    virtual Void::Type Visit(Alternative::Ref ioExpRef) = 0;
                    virtual Void::Type Visit(Repeat::Ref ioExpRef) = 0;
                };
            } /// end of namespace Visitor
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
