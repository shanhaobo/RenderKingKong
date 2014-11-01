#ifndef __WIZ_REGEX_STATE_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_STATE_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.h"

namespace Wiz
{
    namespace Regex
    {
        namespace State
        {
            class Type : public ::Wiz::MemObj::type<Allocator::State::Type>
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
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_STATE_HPP__SHANHAOBO_19800429__
