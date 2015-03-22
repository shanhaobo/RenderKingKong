#ifndef __WIZ_MATH_VECTOR2_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR2_METHOD_INL__SHANHAOBO_19800429__

#include "./WizMathVector2Method.hpp"

namespace Wiz
{
    namespace Vector2
    {
        namespace Method
        {
            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 + InVec2.e0;
                OutVec.e1 = InVec1.e1 + InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 + InEle;
                OutVec.e1 = InVec.e1 + InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 += InVec.e0;
                IOVec.e1 += InVec.e1;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 += InEle;
                IOVec.e1 += InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 - InVec2.e0;
                OutVec.e1 = InVec1.e1 - InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 - InEle;
                OutVec.e1 = InVec.e1 - InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 -= InVec.e0;
                IOVec.e1 -= InVec.e1;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 -= InEle;
                IOVec.e1 -= InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 * InVec2.e0;
                OutVec.e1 = InVec1.e1 * InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 * InEle;
                OutVec.e1 = InVec.e1 * InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 *= InVec.e0;
                IOVec.e1 *= InVec.e1;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 *= InEle;
                IOVec.e1 *= InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 / InVec2.e0;
                OutVec.e1 = InVec1.e1 / InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    tElement const lRecipEle = 1 / InEle;

                    OutVec.e0 = InVec.e0 * lRecipEle;
                    OutVec.e1 = InVec.e1 * lRecipEle;

                    return OutVec;
                }
                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut OutVec, tElementIn InEle, tVectorIn InVec)
            {
                OutVec.e0 = InEle / InVec.e0;
                OutVec.e1 = InEle / InVec.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 /= InVec.e0;
                IOVec.e1 /= InVec.e1;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO IOVec, tElementIn InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    tElement const lRecipEle = 1 / InEle;

                    IOVec.e0 *= lRecipEle;
                    IOVec.e1 *= lRecipEle;
                }

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Dot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return InVec1.e0 * InVec2.e0 + InVec1.e1 * InVec2.e1;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::AbsDot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return ::Wiz::Abs(InVec1.e0 * InVec2.e0) + ::Wiz::Abs(InVec1.e1 * InVec2.e1);
            }

            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorIO IOVec)
            {
                tElement const lLen = Length(IOVec);
                // Will also work for zero-sized Vectors, but will change nothing
                if (lLen > 0)
                {
                    tElement const lRecipLen = 1 / lLen;

                    IOVec.e0 *= lRecipLen;
                    IOVec.e1 *= lRecipLen;
                }

                return lLen;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorOut OutVec, tVectorIn InVec)
            {
                tElement const lLen = Length(InVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (lLen > 0)
                {
                    tElement const lRecipLen = 1 / lLen;

                    OutVec.e0 = InVec.e0 * lRecipLen;
                    OutVec.e1 = InVec.e1 * lRecipLen;
                }
                else
                {
                    OutVec.e0 = InVec.e0;
                    OutVec.e1 = InVec.e1;
                }

                return tLen;
            }

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrLen(tVectorIn InVec)
            {
                return InVec.e0 * InVec.e0 + InVec.e1 * InVec.e1;;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Length(tVectorIn InVec)
            {
                return ::Wiz::Sqrt(SqrLen(InVec));
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::RecipLen(tVectorIn InVec)
            {
                return ::Wiz::RecipSqrt<tElement>(SqrLen(InVec));
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Distance(tVectorIn InVec1, tVectorIn InVec2)
            {
                return ::Wiz::Sqrt(SqrDist(InVec1, InVec2));
            }
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrDist(tVectorIn InVec1, tVectorIn InVec2)
            {
                tVector lVec;
                Subtract(lVec, InVec1, InVec2);
                return SqrLen(lVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteEqual(tVectorIn InVec1, tVectorIn InVec2)
            {
                return (InVec1.e0 == InVec2.e0) && (InVec1.e1 == InVec2.e1);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteZero(tVectorIn InVec)
            {
                return (InVec.e0 == 0) && (InVec.e1 == 0);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsNearlyZero(tVectorIn InVec, tElementIn InTolerance)
            {
                WIZ_ASSERT(InTolerance > 0);
                return ::Wiz::Absolute::InRange(InVec.e0, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e1, -InTolerance, InTolerance);
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Vector2
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR2_METHOD_INL__SHANHAOBO_19800429__*/
