#ifndef __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__

#include "./WizRegexExpression.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// Visitor

            namespace Visitor
            {
                struct Type : public ::Wiz::DP::Visitor::Type<EnumParamWrapper(CharSet::Type, Sequence::Type, Alternative::Type, Repeat::Type)>
                {
                    virtual Void::Type Visit(CharSet::Ref       ioExpRef, I32::Type) = 0;
                    virtual Void::Type Visit(Sequence::Ref      ioExpRef, I32::Type) = 0;
                    virtual Void::Type Visit(Alternative::Ref   ioExpRef, I32::Type) = 0;
                    virtual Void::Type Visit(Repeat::Ref        ioExpRef, I32::Type) = 0;
                };
            } /// end of namespace Visitor

            namespace Traverse
            {
                struct Type : Expression::Visitor::Type
                {
                    Type() : m_AutomatonPtr(WIZ_NULLPTR)
                    {
                    }

                    Automaton::Ptr m_AutomatonPtr;

                    virtual Void::Type Visit(CharSet::Ref       ioExpRef, I32::Type)
                    {
                    }
                    virtual Void::Type Visit(Sequence::Ref      ioExpRef, I32::Type)
                    {
                        ioExpRef.m_LeftPtr->Accept(*this, 0);
                        ioExpRef.m_RightPtr->Accept(*this, 0);
                    }
                    virtual Void::Type Visit(Alternative::Ref   ioExpRef, I32::Type)
                    {
                    }
                    virtual Void::Type Visit(Repeat::Ref        ioExpRef, I32::Type)
                    {
                    }
                };
            } /// end of namespace ThompsonConstruction
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
