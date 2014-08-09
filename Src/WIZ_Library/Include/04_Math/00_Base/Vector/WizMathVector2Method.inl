#ifndef __WIZ_MATH_ALGEBRA_VECTOR2_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_VECTOR2_METHOD_INL__SHANHAOBO_19800429__

#include "./WizMathAlgebraVector2Method.hpp"

namespace Wiz
{
    namespace Vector2
    {
        namespace Method
        {
            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVector& OutVec, const tVector& InVec1, const tVector& InVec2)
            {
                OutVec.e0 = InVec1.e0 + InVec2.e0;
                OutVec.e1 = InVec1.e1 + InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Add(tVector& OutVec, const tVector& InVec, const tElement& InEle)
            {
                OutVec.e0 = InVec.e0 + InEle;
                OutVec.e1 = InVec.e1 + InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVector& InOutVec, const tVector& InVec)
            {
                InOutVec.e0 += InVec.e0;
                InOutVec.e1 += InVec.e1;

                return InOutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::AddAssign(tVector& InOutVec, const tElement& InEle)
            {
                InOutVec.e0 += InEle;
                InOutVec.e1 += InEle;

                return InOutVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVector& OutVec, const tVector& InVec1, const tVector& InVec2)
            {
                OutVec.e0 = InVec1.e0 - InVec2.e0;
                OutVec.e1 = InVec1.e1 - InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Subtract(tVector& OutVec, const tVector& InVec, const tElement& InEle)
            {
                OutVec.e0 = InVec.e0 - InEle;
                OutVec.e1 = InVec.e1 - InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVector& InOutVec, const tVector& InVec)
            {
                InOutVec.e0 -= InVec.e0;
                InOutVec.e1 -= InVec.e1;

                return InOutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::SubtractAssign(tVector& InOutVec, const tElement& InEle)
            {
                InOutVec.e0 -= InEle;
                InOutVec.e1 -= InEle;

                return InOutVec;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVector& OutVec, const tVector& InVec1, const tVector& InVec2)
            {
                OutVec.e0 = InVec1.e0 * InVec2.e0;
                OutVec.e1 = InVec1.e1 * InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Multiply(tVector& OutVec, const tVector& InVec, const tElement& InEle)
            {
                OutVec.e0 = InVec.e0 * InEle;
                OutVec.e1 = InVec.e1 * InEle;

                return OutVec;
            }

            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVector& InOutVec, const tVector& InVec)
            {
                InOutVec.e0 *= InVec.e0;
                InOutVec.e1 *= InVec.e1;

                return InOutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::MultiplyAssign(tVector& InOutVec, const tElement& InEle)
            {
                InOutVec.e0 *= InEle;
                InOutVec.e1 *= InEle;

                return InOutVec;
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVector& OutVec, const tVector& InVec1, const tVector& InVec2)
            {
                OutVec.e0 = InVec1.e0 / InVec2.e0;
                OutVec.e1 = InVec1.e1 / InVec2.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVector& OutVec, const tVector& InVec, const tElement& InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    const tElement RecipEle = 1 / InEle;

                    OutVec.e0 = InVec.e0 * RecipEle;
                    OutVec.e1 = InVec.e1 * RecipEle;

                    return OutVec;
                }
                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::Divide(tVector& OutVec, const tElement& InEle, const tVector& InVec)
            {
                OutVec.e0 = InEle / InVec.e0;
                OutVec.e1 = InEle / InVec.e1;

                return OutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVector& InOutVec, const tVector& InVec)
            {
                InOutVec.e0 /= InVec.e0;
                InOutVec.e1 /= InVec.e1;

                return InOutVec;
            }
            template<class VectorT>
            VectorT& Type<VectorT>::DivideAssign(tVector& InOutVec, const tElement& InEle)
            {
                if (::Wiz::Nearly::GreaterZero(InEle))
                {
                    const tElement RecipEle = 1 / InEle;

                    InOutVec.e0 *= RecipEle;
                    InOutVec.e1 *= RecipEle;
                }

                return InOutVec;
            }
            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Dot(const tVector& InVec1, const tVector& InVec2)
            {
                return InVec1.e0 * InVec2.e0 + InVec1.e1 * InVec2.e1;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::AbsDot(const tVector& InVec1, const tVector& InVec2)
            {
                return ::Wiz::Abs(InVec1.e0 * InVec2.e0) + ::Wiz::Abs(InVec1.e1 * InVec2.e1);
            }

            //////////////////////////////////////////////////////////////////////////

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVector& InOutVec)
            {
                const tElement Len = Length(InOutVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(Len))
                {
                    const tElement RecipLen = 1 / Len;

                    InOutVec.e0 *= RecipLen;
                    InOutVec.e1 *= RecipLen;
                }

                return Len;
            }

            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Normalize(tVector& OutVec, const tVector& InVec)
            {
                const tElement Len = Length(InVec);

                // Will also work for zero-sized Vectors, but will change nothing
                if (::Wiz::Nearly::GreaterZero(Len))
                {
                    const tElement RecipLen = 1 / Len;

                    OutVec.e0 = InVec.e0 * RecipLen;
                    OutVec.e1 = InVec.e1 * RecipLen;
                }
                else
                {
                    OutVec.e0 = InVec.e0;
                    OutVec.e1 = InVec.e1;
                }

                return Len;
            }

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrLength(const tVector& InVec)
            {
                return InVec.e0 * InVec.e0 + InVec.e1 * InVec.e1;;
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Length(const tVector& InVec)
            {
                return ::Wiz::Sqrt(SqrLength(InVec));
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::RecipLength(const tVector& InVec)
            {
                return ::Wiz::RecipSqrt<tElement>(SqrLength(InVec));
            }
            //////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////////////////////
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::Distance(const tVector& InVec1, const tVector& InVec2)
            {
                tVector Vec;
                Subtract(Vec, InVec1, InVec2);
                return Length(Vec);
            }
            template<class VectorT>
            typename VectorT::tElement Type<VectorT>::SqrDistance(const tVector& InVec1, const tVector& InVec2)
            {
                tVector Vec;
                Subtract(Vec, InVec1, InVec2);
                return SqrLength(Vec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteEqual(const tVector& InVec1, const tVector& InVec2)
            {
                return ::Wiz::Absolute::IsEqual(InVec1.e0, InVec2.e0) && ::Wiz::Absolute::IsEqual(InVec1.e1, InVec2.e1);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsAbsoluteZero(const tVector& InVec)
            {
                return ::Wiz::Absolute::IsZero(InVec.e0) && ::Wiz::Absolute::IsZero(InVec.e1);
            }

            template<class VectorT>
            ::Wiz::Bool::Type Type<VectorT>::IsNearlyZero(const tVector& InVec, const tElement& InTolerance)
            {
                WIZ_ASSERT(::Wiz::Absolute::GreaterZero(InTolerance));
                return ::Wiz::Absolute::InRange(InVec.e0, -InTolerance, InTolerance) && ::Wiz::Absolute::InRange(InVec.e1, -InTolerance, InTolerance);
            }
            ////////////////////////////////////////////////////////////////
        } /// end of namespace Method
    } /// end of namespace Vector2
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_VECTOR2_METHOD_INL__SHANHAOBO_19800429__*/
