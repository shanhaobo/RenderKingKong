#ifndef __WIZ_MATH_ALGEBRA_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__

#include "../../Utils/WizMathUtils.hpp"
#include "./WizMathAlgebraVector2Base.hpp"

namespace Wiz
{
    namespace Vector2
    {
        namespace Method
        {
            template<class VectorT>
            struct WIZ_EXPORT Type
            {
                typedef VectorT                         tVector;
                typedef typename tVector::tElement      tElement;
                typedef Type                            tThis;
                ////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Add(tVector& OutVec, const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tVector& Add(tVector& OutVec, const tVector& InVec, const tElement& InEle);

                WIZ_INLINE static tVector& AddAssign(tVector& InOutVec, const tVector& InVec);
                WIZ_INLINE static tVector& AddAssign(tVector& InOutVec, const tElement& InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Subtract(tVector& OutVec, const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tVector& Subtract(tVector& OutVec, const tVector& InVec, const tElement& InEle);

                WIZ_INLINE static tVector& SubtractAssign(tVector& InOutVec, const tVector& InVec);
                WIZ_INLINE static tVector& SubtractAssign(tVector& InOutVec, const tElement& InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Multiply(tVector& OutVec, const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tVector& Multiply(tVector& OutVec, const tVector& InVec, const tElement& InEle);

                WIZ_INLINE static tVector& MultiplyAssign(tVector& InOutVec, const tVector& InVec);
                WIZ_INLINE static tVector& MultiplyAssign(tVector& InOutVec, const tElement& InEle);
                //////////////////////////////////////////////////////////////////////////


                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Divide(tVector& OutVec, const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tVector& Divide(tVector& OutVec, const tVector& InVec, const tElement& InEle);
                WIZ_INLINE static tVector& Divide(tVector& OutVec, const tElement& InEle, const tVector& InVec);
                WIZ_INLINE static tVector& DivideAssign(tVector& InOutVec, const tVector& InVec);
                WIZ_INLINE static tVector& DivideAssign(tVector& InOutVec, const tElement& InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Dot(const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tElement AbsDot(const tVector& InVec1, const tVector& InVec2);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Normalize(tVector& InOutVec);
                WIZ_INLINE static tElement Normalize(tVector& OutVec, const tVector& InVec);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Length(const tVector& InVec);
                WIZ_INLINE static tElement SqrLength(const tVector& InVec);
                WIZ_INLINE static tElement RecipLength(const tVector& InVec);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Distance(const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static tElement SqrDistance(const tVector& InVec1, const tVector& InVec2);
                ////////////////////////////////////////////////////////////////


                ////////////////////////////////////////////////////////////////
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteEqual(const tVector& InVec1, const tVector& InVec2);
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteZero(const tVector& InVec);
                WIZ_INLINE static ::Wiz::Bool::Type IsNearlyZero(const tVector& InVec, const tElement& InTolerance);
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace Method
    } /// end of namespace Vector2
} /// end of namespace Wiz

#include "./WizMathAlgebraVector2Method.inl"

#endif /*__WIZ_MATH_ALGEBRA_VECTOR2_METHOD_HPP__SHANHAOBO_19800429__*/
