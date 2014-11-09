#include "./WizRegexExpressionVisitor.hpp"

namespace Wiz
{
    namespace Regex
    {
        namespace Expression
        {
            namespace Traverse
            {
                Void::Type Type::Visit(CharSet::Ref       ioExpRef, Expression::Ptr)
                {
                }
                Void::Type Type::Visit(Sequence::Ref      ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_LeftChildPtr))
                    {
                        ioExpRef.m_LeftChildPtr->Accept(*this);
                    }
                    if (::Wiz::IsValidPtr(ioExpRef.m_RightChildPtr))
                    {
                        ioExpRef.m_RightChildPtr->Accept(*this);
                    }
                }
                Void::Type Type::Visit(Alternative::Ref   ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_LeftChildPtr))
                    {
                        ioExpRef.m_LeftChildPtr->Accept(*this);
                    }
                    if (::Wiz::IsValidPtr(ioExpRef.m_RightChildPtr))
                    {
                        ioExpRef.m_RightChildPtr->Accept(*this);
                    }
                }
                Void::Type Type::Visit(Repeat::Ref        ioExpRef, Expression::Ptr inParentPtr)
                {
                    if (::Wiz::IsValidPtr(ioExpRef.m_OnlyChildPtr))
                    {
                        ioExpRef.m_OnlyChildPtr->Accept(*this);
                    }
                }
            } /// end of namespace ThompsonConstruction
        } /// end of namespace State
    } /// end of namespace Regex
} /// end of namespace Wiz
