#ifndef __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.h"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////

            class Type : public ::Wiz::MemObj::Type<Allocator::Expression::Type>
            {
            public:
                Type() : m_Final(Bool::False)
                {

                }
            public:
                WIZ_INLINE Bool::Type IsFinal()
                {
                    return m_Final;
                };
            protected:
                Bool::Type m_Final;
            };

            ////////////////////////////////////////////

            namespace Sequence
            {
                class Type : public DP::Visitable::Type<Sequence::Type, Visitor::Type>
                {
                protected:

                };
            } /// end of namespace Sequence

            namespace Alternative
            {
                class Type : public DP::Visitable::Type<Alternative::Type, Visitor::Type>
                {
                protected:

                };
            } /// end of namespace Alternative

            namespace Repeat
            {
                class Type : public DP::Visitable::Type<Repeat::Type, Visitor::Type>
                {
                protected:

                };
            } /// end of namespace Repeat

            ////////////////////////////////////////////

        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
