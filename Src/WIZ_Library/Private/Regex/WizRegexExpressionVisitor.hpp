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
                struct Type : public ::Wiz::DP::Visitor::Type<TypeWrapper(CharSet::Type, Sequence::Type, Alternative::Type, Repeat::Type)>
                {
                    virtual I32::Type Visit(CharSet::Ref       ioExpRef, U32::Type) = 0;
                    virtual I32::Type Visit(Sequence::Ref      ioExpRef, U32::Type) = 0;
                    virtual I32::Type Visit(Alternative::Ref   ioExpRef, U32::Type) = 0;
                    virtual I32::Type Visit(Repeat::Ref        ioExpRef, U32::Type) = 0;
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

                    virtual I32::Type Visit(CharSet::Ref       ioExpRef, U32::Type)
                    {
                        return 0;
                    }
                    virtual I32::Type Visit(Sequence::Ref      ioExpRef, U32::Type)
                    {
//                         ioExpRef.m_LeftPtr->RequestAccept(*this);
                        //                         ioExpRef.m_RightPtr->RequestAccept(*this);
                        return 0;
                    }
                    virtual I32::Type Visit(Alternative::Ref   ioExpRef, U32::Type)
                    {

                        return 0;
                    }
                    virtual I32::Type Visit(Repeat::Ref        ioExpRef, U32::Type)
                    {

                        return 0;
                    }
                };
            } /// end of namespace ThompsonConstruction
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_VISITOR_HPP__SHANHAOBO_19800429__
