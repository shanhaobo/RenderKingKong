#ifndef __WIZ_MATH_VECTOR3_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR3_METHOD_HPP__SHANHAOBO_19800429__

#include "../../Utils/WizMathUtils.hpp"

namespace Wiz
{
    namespace Vector3
    {
        namespace Method
        {
            template<class VectorT>
            struct WIZ_EXPORT Type
            {
                typedef VectorT                         tVector;
                typedef typename tVector::tElement      tElement;
                typedef Type                            tThis;

                typedef tElement const &                tElementIn;
                typedef tElement &                      tElementOut;

                typedef tVector const &                 tVectorIn;
                typedef tVector &                       tVectorOut;
                typedef tVector &                       tVectorIO;
                ////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Add(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Add(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& AddAssign(tVectorIO IOVec, tVectorIn InVec);
                WIZ_INLINE static tVector& AddAssign(tVectorIO IOVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Subtract(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Subtract(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& SubtractAssign(tVectorIO IOVec, tVectorIn InVec);
                WIZ_INLINE static tVector& SubtractAssign(tVectorIO IOVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Multiply(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Multiply(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO IOVec, tVectorIn InVec);
                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO IOVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Divide(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Divide(tVectorOut OutVec, tVectorIn InVec, tElementIn InEle);
                WIZ_INLINE static tVector& Divide(tVectorOut OutVec, tElementIn InEle, tVectorIn InVec);

                WIZ_INLINE static tVector& DivideAssign(tVectorIO IOVec, tVectorIn InVec);
                WIZ_INLINE static tVector& DivideAssign(tVectorIO IOVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Cross(tVectorOut OutVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tElement Dot(tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tElement AbsDot(tVectorIn InVec1, tVectorIn InVec2);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Normalize(tVectorIO IOVec);
                WIZ_INLINE static tElement Normalize(tVectorOut OutVec, tVectorIn InVec);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement SqrLen(tVectorIn InVec);
                WIZ_INLINE static tElement Length(tVectorIn InVec);
                WIZ_INLINE static tElement RecipLen(tVectorIn InVec);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Distance(tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tElement SqrDist(tVectorIn InVec1, tVectorIn InVec2);
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteEqual(tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static ::Wiz::Bool::Type IsAbsoluteZero(tVectorIn InVec);
                WIZ_INLINE static ::Wiz::Bool::Type IsNearlyZero(tVectorIn InVec, tElementIn InTolerance);
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace Method
    } /// end of namespace Vector3
} /// end of namespace Wiz

#include "./WizMathVector3Method.inl"

#endif /*__WIZ_MATH_VECTOR3_METHOD_HPP__SHANHAOBO_19800429__*/
