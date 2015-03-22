#ifndef __WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__

#include "WizMathVector3Method.hpp"

namespace Wiz
{
    namespace Vector3
    {
        namespace Method
        {
            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 + InVec2.e0;
                OutVec.e1 = InVec1.e1 + InVec2.e1;
                OutVec.e2 = InVec1.e2 + InVec2.e2;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 + InEle;
                OutVec.e1 = InVec.e1 + InEle;
                OutVec.e2 = InVec.e2 + InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 += InVec.e0;
                IOVec.e1 += InVec.e1;
                IOVec.e2 += InVec.e2;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 += InEle;
                IOVec.e1 += InEle;
                IOVec.e2 += InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 - InVec2.e0;
                OutVec.e1 = InVec1.e1 - InVec2.e1;
                OutVec.e2 = InVec1.e2 - InVec2.e2;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 - InEle;
                OutVec.e1 = InVec.e1 - InEle;
                OutVec.e2 = InVec.e2 - InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 -= InVec.e0;
                IOVec.e1 -= InVec.e1;
                IOVec.e2 -= InVec.e2;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 -= InEle;
                IOVec.e1 -= InEle;
                IOVec.e2 -= InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 * InVec2.e0;
                OutVec.e1 = InVec1.e1 * InVec2.e1;
                OutVec.e2 = InVec1.e2 * InVec2.e2;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle)
            {
                OutVec.e0 = InVec.e0 * InEle;
                OutVec.e1 = InVec.e1 * InEle;
                OutVec.e2 = InVec.e2 * InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 *= InVec.e0;
                IOVec.e1 *= InVec.e1;
                IOVec.e2 *= InVec.e2;

                return IOVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO IOVec, tElementIn InEle)
            {
                IOVec.e0 *= InEle;
                IOVec.e1 *= InEle;
                IOVec.e2 *= InEle;

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.e0 = InVec1.e0 / InVec2.e0;
                OutVec.e1 = InVec1.e1 / InVec2.e1;
                OutVec.e2 = InVec1.e2 / InVec2.e2;

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
                    OutVec.e2 = InVec.e2 * lRecipEle;

                    return OutVec;
                }
                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut OutVec, tElementIn InEle, tVectorIn InVec)
            {
                OutVec.e0 = InEle / InVec.e0;
                OutVec.e1 = InEle / InVec.e1;
                OutVec.e2 = InEle / InVec.e2;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO IOVec, tVectorIn InVec)
            {
                IOVec.e0 /= InVec.e0;
                IOVec.e1 /= InVec.e1;
                IOVec.e2 /= InVec.e2;

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
                    IOVec.e2 *= lRecipEle;
                }

                return IOVec;
            }
            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            VectorT& Type<VectorT>::Cross(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                OutVec.x = InVec1.y * InVec2.z - InVec1.z * InVec2.y;
                OutVec.y = InVec1.z * InVec2.x - InVec1.x * InVec2.z;
                OutVec.z = InVec1.x * InVec2.y - InVec1.y * InVec2.x;
                return OutVec;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Dot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return InVec1.e0 * InVec2.e0 + InVec1.e1 * InVec2.e1 + InVec1.e2 * InVec2.e2;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::AbsDot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return ::Wiz::Abs(InVec1.e0 * InVec2.e0) + ::Wiz::Abs(InVec1.e1 * InVec2.e1) + ::Wiz::Abs(InVec1.e2 * InVec2.e2);
            }

            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorIO IOVec)
            {
                tElement const lLen = Length(IOVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(lLen))
                {
                    tElement const lRecipLen = 1 / lLen;

                    IOVec.e0 *= lRecipLen;
                    IOVec.e1 *= lRecipLen;
                    IOVec.e2 *= lRecipLen;
                }

                return lLen;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorOut OutVec, tVectorIn InVec)
            {
                tElement const lLen = Length(InVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(lLen))
                {
                    tElement const lRecipLen = 1 / lLen;

                    OutVec.e0 = InVec.e0 * lRecipLen;
                    OutVec.e1 = InVec.e1 * lRecipLen;
                    OutVec.e2 = InVec.e2 * lRecipLen;
                }
                else
                {
                    OutVec.e0 = InVec.e0;
                    OutVec.e1 = InVec.e1;
                    OutVec.e2 = InVec.e2;
                }

                return lLen;
            }

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrLen(tVectorIn InVec)
            {
                return InVec.e0 * InVec.e0 + InVec.e1 * InVec.e1 + InVec.e2 * InVec.e2;
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
                return ::Wiz::RecipSqrt(SqrLen(InVec));
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
                return ::Wiz::Absolute::IsEqual(InVec1.e0, InVec2.e0) && ::Wiz::Absolute::IsEqual(InVec1.e1, InVec2.e1) && ::Wiz::Absolute::IsEqual(InVec1.e2, InVec2.e2);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteZero(tVectorIn InVec)
            {
                return ::Wiz::Absolute::IsZero(InVec.e0) && ::Wiz::Absolute::IsZero(InVec.e1) && ::Wiz::Absolute::IsZero(InVec.e2);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsNearlyZero(tVectorIn InVec, tElementIn InTolerance)
            {
                WIZ_ASSERT(::Wiz::Absolute::GreaterZero(InTolerance));
                return ::Wiz::Absolute::InRange(InVec.e0, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e1, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e2, -InTolerance, InTolerance);
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Vector3
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR3_METHOD_INL__SHANHAOBO_19800429__*/
