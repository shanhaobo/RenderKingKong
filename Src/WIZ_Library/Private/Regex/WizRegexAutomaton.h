#ifndef __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__

#include "./WizRegexBaseType.h"

#include "./WizRegexState.h"
#include "./WizRegexTransition.h"

namespace Wiz
{
    namespace Regex
    {
        namespace Automaton
        {
            class Type : public ::Wiz::MemObj::type<Allocator::Automaton::Type>
            {
            protected:
                typedef List::Type<State::Ptr>  tStateList;
            public:
                Type()
                {

                }
            public:



            protected:
                tStateList  m_StateList;

                State::Ptr  m_StartState;
            };
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_AUTOMATON_HPP__SHANHAOBO_19800429__
