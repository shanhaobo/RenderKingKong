#ifndef __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__

#include "./WizRegexExpression.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            namespace Traverse
            {
                struct Type : Expression::Visitor::Type
                {
                    Type() : m_AutomatonPtr(WIZ_NULLPTR)
                    {
                    }

                    Automaton::Ptr m_AutomatonPtr;

                    virtual Void::Type Visit(CharSet::Ref       ioExpRef)
                    {
                    }
                    virtual Void::Type Visit(Sequence::Ref      ioExpRef)
                    {
//                         ioExpRef.m_LeftPtr->RequestAccept(*this);
//                         ioExpRef.m_RightPtr->RequestAccept(*this);
                    }
                    virtual Void::Type Visit(Alternative::Ref   ioExpRef)
                    {

                    }
                    virtual Void::Type Visit(Repeat::Ref        ioExpRef)
                    {

                    }
                };
            } /// end of namespace ThompsonConstruction
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
