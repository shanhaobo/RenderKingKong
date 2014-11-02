#include "./WizRegexAutomaton.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Automaton
        {
            Transition::Ptr Type::StateTransition(State::Ptr InBeginStatePtr, State::Ptr InEndStatePtr)
            {
                Transition::Ptr TransPtr = WIZ_NEW Transition::Type;
                if (::Wiz::IsValidPtr(TransPtr))
                {
                    if (LinkNode(TransPtr, InBeginStatePtr, InEndStatePtr))
                    {
                        InsetLink(TransPtr);
                        return TransPtr;
                    }

                    WIZ_DEL TransPtr;
                    TransPtr = WIZ_NULL;
                }

                return WIZ_NULL;
            }


            Transition::Epsilon::Ptr Type::EpsilonTransition(State::Ptr InBeginStatePtr, State::Ptr InEndStatePtr)
            {
                Transition::Epsilon::Ptr EpsilonPtr = WIZ_NEW Transition::Epsilon::Type;
                if (::Wiz::IsValidPtr(EpsilonPtr))
                {
                    if (LinkNode(EpsilonPtr, InBeginStatePtr, InEndStatePtr))
                    {
                        InsetLink(EpsilonPtr);
                        return EpsilonPtr;
                    }

                    WIZ_DEL EpsilonPtr;
                    EpsilonPtr = WIZ_NULL;
                }

                return WIZ_NULL;
            }
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

