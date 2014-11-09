#ifndef __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// ::Wiz::DP::Visitable::Base::Type
            class Type : public ::Wiz::DP::Visitable::Base::Type<Visitor::Type, Expression::Ptr, ::Wiz::MemObj::Type<Allocator::Expression::Type> >
            {
            protected:
                typedef ::Wiz::DP::Visitable::Base::Type<Visitor::Type, Expression::Ptr, ::Wiz::MemObj::Type<Allocator::Expression::Type> > tSuper;

            public:
                Type() : tSuper(), m_Final(Bool::False)
                {

                }
            public:
                Void::Type Accept(Visitor::Ref inVisitorRef)
                {
                    tSuper::Accept(inVisitorRef, this);
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
            ////////////////////////////////////////////
            ////////////////////////////////////////////
            /// ::Wiz::DP::Visitable::Type
            namespace Terminal
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type()
                    {

                    }
                protected:

                };
            } /// end of namespace Terminal

            namespace Unary
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type() : m_OnlyChildPtr(WIZ_NULLPTR)
                    {

                    }
                public:
                    Expression::Ptr m_OnlyChildPtr;
                };
            } /// end of namespace Unary

            namespace Binary
            {
                template<class DerivedT>
                class Type : public ::Wiz::DP::Visitable::Type<DerivedT, Expression::Type>
                {
                protected:
                    Type() : m_LeftChildPtr(WIZ_NULLPTR), m_RightChildPtr(WIZ_NULLPTR)
                    {

                    }
                public:
                    Expression::Ptr m_LeftChildPtr;
                    Expression::Ptr m_RightChildPtr;
                };
            } /// end of namespace Binary

            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////

            namespace CharSet
            {
                class Type : public Terminal::Type<Type>
                {
                protected:
                    typedef Terminal::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace CharSet

            namespace Sequence
            {
                class Type : public Binary::Type<Type>
                {
                protected:
                    typedef Binary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Sequence

            namespace Alternative
            {
                class Type : public Binary::Type<Type>
                {
                protected:
                    typedef Binary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Alternative

            namespace Repeat
            {
                class Type : public Unary::Type<Type>
                {
                protected:
                    typedef Unary::Type<Type> tSuper;
                public:
                    Type() : tSuper()
                    {

                    }
                };
            } /// end of namespace Repeat

            ////////////////////////////////////////////
            ////////////////////////////////////////////
            ////////////////////////////////////////////
        } /// end of namespace Expression
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_EXPRESSION_HPP__SHANHAOBO_19800429__
