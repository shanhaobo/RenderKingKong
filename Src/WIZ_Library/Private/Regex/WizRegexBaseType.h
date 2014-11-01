#ifndef __WIZ_REGEX_BASETYPE_HPP__SHANHAOBO_19800429__
#define __WIZ_REGEX_BASETYPE_HPP__SHANHAOBO_19800429__

#include "../../../Include/01_Basic/01_Type/WizBasicType.hpp"
#include "../../../Include/01_Basic/05_Mem/WizBasicMem.hpp"

namespace Wiz
{
    namespace Regex
    {
        enum OBJ_CAT
        {
            eOC_State,
            eOC_Transition,
            eOC_Automaton,
        };

        namespace Allocator
        {
            namespace State
            {
                typedef ::Wiz::Allocator::Categorized<eOC_State>::Type      Type;
            } /// end of namespace State

            namespace Transition
            {
                typedef ::Wiz::Allocator::Categorized<eOC_Transition>::Type Type;
            } /// end of namespace Transition

            namespace Automaton
            {
                typedef ::Wiz::Allocator::Categorized<eOC_Automaton>::Type  Type;
            } /// end of namespace Automaton
        } /// end of namespace Allocator

        namespace State
        {
            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace State

        namespace Transition
        {
            namespace Epsilon
            {
                WIZ_FORWARD_DECLARE_CLASS;
            } /// end of namespace Epsilon

            WIZ_FORWARD_DECLARE_CLASS;
        } /// end of namespace Transition

        namespace Automaton
        {
            WIZ_FORWARD_DECLARE_CLASS
        } /// end of namespace Automaton
    } /// end of namespace Regex
} /// end of namespace Wiz

#endif /// __WIZ_REGEX_BASETYPE_HPP__SHANHAOBO_19800429__
