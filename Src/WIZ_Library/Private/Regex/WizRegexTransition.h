#ifndef __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.h"

namespace Wiz
{
    namespace Regex
    {
        namespace Transition
        {
            namespace Epsilon
            {
                class Type : public MemObj::type<Allocator::Transition::Type>
                {
                public:
                    Type() : m_FromPtr(WIZ_NULLPTR), m_ToPtr(WIZ_NULLPTR)
                    {

                    }
                public:

                protected:

                    State::Ptr m_FromPtr;
                    State::Ptr m_ToPtr;
                };
            } /// end of namespace Epsilon

            class Type : public Epsilon::Type
            {
            protected:
                typedef Epsilon::Type tSuper;
            public:
                Type() : tSuper()
                {

                }
            public:

            protected:
            };
        } /// end of namespace Transition
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_TRANSITION_HPP__SHANHAOBO_19800429__
