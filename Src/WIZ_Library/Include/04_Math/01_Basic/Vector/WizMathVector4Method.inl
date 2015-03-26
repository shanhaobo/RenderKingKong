#ifndef __WIZ_MATH_VECTOR4_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR4_METHOD_INL__SHANHAOBO_19800429__

#include "WizMathVector4Method.hpp"

namespace Wiz
{
    namespace Vector4
    {
        namespace Method
        {
            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                outVec.e0 = InVec1.e0 + InVec2.e0;
                outVec.e1 = InVec1.e1 + InVec2.e1;
                outVec.e2 = InVec1.e2 + InVec2.e2;
                outVec.e3 = InVec1.e3 + InVec2.e3;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVectorOut outVec, tVectorIn InVec, tElementIn InEle)
            {
                outVec.e0 = InVec.e0 + InEle;
                outVec.e1 = InVec.e1 + InEle;
                outVec.e2 = InVec.e2 + InEle;
                outVec.e3 = InVec.e3 + InEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO ioVec, tVectorIn InVec)
            {
                ioVec.e0 += InVec.e0;
                ioVec.e1 += InVec.e1;
                ioVec.e2 += InVec.e2;
                ioVec.e3 += InVec.e3;

                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVectorIO ioVec, tElementIn InEle)
            {
                ioVec.e0 += InEle;
                ioVec.e1 += InEle;
                ioVec.e2 += InEle;
                ioVec.e3 += InEle;

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                outVec.e0 = InVec1.e0 - InVec2.e0;
                outVec.e1 = InVec1.e1 - InVec2.e1;
                outVec.e2 = InVec1.e2 - InVec2.e2;
                outVec.e3 = InVec1.e3 - InVec2.e3;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVectorOut outVec, tVectorIn InVec, tElementIn InEle)
            {
                outVec.e0 = InVec.e0 - InEle;
                outVec.e1 = InVec.e1 - InEle;
                outVec.e2 = InVec.e2 - InEle;
                outVec.e3 = InVec.e3 - InEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO ioVec, tVectorIn InVec)
            {
                ioVec.e0 -= InVec.e0;
                ioVec.e1 -= InVec.e1;
                ioVec.e2 -= InVec.e2;
                ioVec.e3 -= InVec.e3;

                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVectorIO ioVec, tElementIn InEle)
            {
                ioVec.e0 -= InEle;
                ioVec.e1 -= InEle;
                ioVec.e2 -= InEle;
                ioVec.e3 -= InEle;

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                outVec.e0 = InVec1.e0 * InVec2.e0;
                outVec.e1 = InVec1.e1 * InVec2.e1;
                outVec.e2 = InVec1.e2 * InVec2.e2;
                outVec.e3 = InVec1.e3 * InVec2.e3;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVectorOut outVec, tVectorIn InVec, tElementIn InEle)
            {
                outVec.e0 = InVec.e0 * InEle;
                outVec.e1 = InVec.e1 * InEle;
                outVec.e2 = InVec.e2 * InEle;
                outVec.e3 = InVec.e3 * InEle;

                return outVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO ioVec, tVectorIn InVec)
            {
                ioVec.e0 *= InVec.e0;
                ioVec.e1 *= InVec.e1;
                ioVec.e2 *= InVec.e2;
                ioVec.e3 *= InVec.e3;

                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVectorIO ioVec, tElementIn InEle)
            {
                ioVec.e0 *= InEle;
                ioVec.e1 *= InEle;
                ioVec.e2 *= InEle;
                ioVec.e3 *= InEle;

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2)
            {
                outVec.e0 = InVec1.e0 / InVec2.e0;
                outVec.e1 = InVec1.e1 / InVec2.e1;
                outVec.e2 = InVec1.e2 / InVec2.e2;
                outVec.e3 = InVec1.e3 / InVec2.e3;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tVectorIn InVec, tElementIn InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    tElement const lRecipEle = 1 / InEle;

                    outVec.e0 = InVec.e0 * lRecipEle;
                    outVec.e1 = InVec.e1 * lRecipEle;
                    outVec.e2 = InVec.e2 * lRecipEle;
                    outVec.e3 = InVec.e3 * lRecipEle;

                    return outVec;
                }
                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVectorOut outVec, tElementIn InEle, tVectorIn InVec)
            {
                outVec.e0 = InEle / InVec.e0;
                outVec.e1 = InEle / InVec.e1;
                outVec.e2 = InEle / InVec.e2;
                outVec.e3 = InEle / InVec.e3;

                return outVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO ioVec, tVectorIn InVec)
            {
                ioVec.e0 /= InVec.e0;
                ioVec.e1 /= InVec.e1;
                ioVec.e2 /= InVec.e2;
                ioVec.e3 /= InVec.e3;

                return ioVec;

            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVectorIO ioVec, tElementIn InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    tElement const lRecipEle = 1 / InEle;

                    ioVec.e0 *= lRecipEle;
                    ioVec.e1 *= lRecipEle;
                    ioVec.e2 *= lRecipEle;
                    ioVec.e3 *= lRecipEle;
                }

                return ioVec;

            }
            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Dot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return InVec1.e0 * InVec2.e0 + InVec1.e1 * InVec2.e1 + InVec1.e2 * InVec2.e2 + InVec1.e3 * InVec2.e3;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::AbsDot(tVectorIn InVec1, tVectorIn InVec2)
            {
                return ::Wiz::Abs(InVec1.e0 * InVec2.e0) + ::Wiz::Abs(InVec1.e1 * InVec2.e1) +
                    ::Wiz::Abs(InVec1.e2 * InVec2.e2) + ::Wiz::Abs(InVec1.e3 * InVec2.e3);
            }

            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorIO ioVec)

            {
                tElement const Len = Length(ioVec);


                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(Len))
                {
                    tElement const lRecipLen = 1 / Len;

                    ioVec.e0 *= lRecipLen;
                    ioVec.e1 *= lRecipLen;
                    ioVec.e2 *= lRecipLen;
                    ioVec.e3 *= lRecipLen;
                }

                return Len;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVectorOut outVec, tVectorIn InVec)
            {
                tElement const lLen = Length(InVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(lLen))
                {
                    tElement const lRecipLen = 1 / lLen;

                    outVec.e0 = InVec.e0 * lRecipLen;
                    outVec.e1 = InVec.e1 * lRecipLen;
                    outVec.e2 = InVec.e2 * lRecipLen;
                    outVec.e3 = InVec.e3 * lRecipLen;
                }
                else
                {
                    outVec.e0 = InVec.e0;
                    outVec.e1 = InVec.e1;
                    outVec.e2 = InVec.e2;
                    outVec.e3 = InVec.e3;
                }

                return lLen;
            }

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrLen(tVectorIn InVec)
            {
                return InVec.e0 * InVec.e0 + InVec.e1 * InVec.e1 + InVec.e2 * InVec.e2 + InVec.e3 * InVec.e3;
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
                tVector Vec;
                Subtract(Vec, InVec1, InVec2);
                return SqrLen(Vec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteEqual(tVectorIn InVec1, tVectorIn InVec2)
            {
                return ::Wiz::Absolute::IsEqual(InVec1.e0, InVec2.e0) && ::Wiz::Absolute::IsEqual(InVec1.e1, InVec2.e1) && ::Wiz::Absolute::IsEqual(InVec1.e2, InVec2.e2) && ::Wiz::Absolute::IsEqual(InVec1.e3, InVec2.e3);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteZero(tVectorIn InVec)
            {
                return ::Wiz::Absolute::IsZero(InVec.e0) && ::Wiz::Absolute::IsZero(InVec.e1) && ::Wiz::Absolute::IsZero(InVec.e2) && ::Wiz::Absolute::IsZero(InVec.e3);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsNearlyZero(tVectorIn InVec, tElementIn InTolerance)
            {
                WIZ_ASSERT(::Wiz::Absolute::GreaterZero(InTolerance));
                return ::Wiz::Absolute::InRange(InVec.e0, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e1, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e2, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e3, -InTolerance, InTolerance);
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Vector4
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR4_METHOD_INL__SHANHAOBO_19800429__*/
