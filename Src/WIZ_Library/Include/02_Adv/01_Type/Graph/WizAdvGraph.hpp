#ifndef __WIZ_GRAPH_HPP__SHANHAOBO_19800429__
#define __WIZ_GRAPH_HPP__SHANHAOBO_19800429__

#include "./WizAdvGraphNode.hpp"
#include "./WizAdvGraphLink.hpp"

namespace Wiz
{
    namespace Graph
    {
        class Type
        {
        protected:
            typedef Set::Type<Link::Ptr> tLinkSet;
            typedef Set::Type<Node::Ptr> tNodeSet;

        public:
            Type()
            {

            }
        public:

            Bool::Type LinkNode(Link::Ptr InLinkPtr, Node::Ptr InBeginNodePtr, Node::Ptr InEndNodePtr)
            {
                if (::Wiz::IsValidPtr(InLinkPtr) && ::Wiz::IsValidPtr(InBeginNodePtr) && ::Wiz::IsValidPtr(InEndNodePtr))
                {
                    InLinkPtr->m_BeginNodePtr = InBeginNodePtr;
                    InLinkPtr->m_EndNodePtr = InEndNodePtr;

                    InBeginNodePtr->m_OutputSet.Insert(InLinkPtr);
                    InEndNodePtr->m_InputSet.Insert(InLinkPtr);

                    return Bool::True;
                }

                return Bool::False;
            }

        protected:
            tNodeSet NodeSet;
        };
    } /// end of namespace Graph
} /// end of namespace Wiz

#endif /// __WIZ_GRAPH_HPP__SHANHAOBO_19800429__
