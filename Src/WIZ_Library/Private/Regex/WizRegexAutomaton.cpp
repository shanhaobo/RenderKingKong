#include "./WizRegexAutomaton.h"


namespace Wiz
{
    namespace Regex
    {
        namespace Automaton
        {
            Transition::Ptr Type::LinkNode(State::Ptr InBeginStatePtr, State::Ptr InEndStatePtr)
            {
                Transition::Ptr TransPtr = WIZ_NEW Transition::Type;
                if (::Wiz::IsValidPtr(TransPtr))
                {
                    if (tSuper::LinkNode(TransPtr, InBeginStatePtr, InEndStatePtr))
                    {
                        return TransPtr;
                    }

                    WIZ_DEL TransPtr;
                }

                return WIZ_NULL;
            }
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

