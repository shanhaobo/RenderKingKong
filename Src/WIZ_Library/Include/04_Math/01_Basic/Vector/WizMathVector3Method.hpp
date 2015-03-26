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
                WIZ_INLINE static tVector& Add(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Add(tVectorOut outVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& AddAssign(tVectorIO ioVec, tVectorIn InVec);
                WIZ_INLINE static tVector& AddAssign(tVectorIO ioVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Subtract(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Subtract(tVectorOut outVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& SubtractAssign(tVectorIO ioVec, tVectorIn InVec);
                WIZ_INLINE static tVector& SubtractAssign(tVectorIO ioVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Multiply(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Multiply(tVectorOut outVec, tVectorIn InVec, tElementIn InEle);

                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO ioVec, tVectorIn InVec);
                WIZ_INLINE static tVector& MultiplyAssign(tVectorIO ioVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tVectorIn InVec, tElementIn InEle);
                WIZ_INLINE static tVector& Divide(tVectorOut outVec, tElementIn InEle, tVectorIn InVec);

                WIZ_INLINE static tVector& DivideAssign(tVectorIO ioVec, tVectorIn InVec);
                WIZ_INLINE static tVector& DivideAssign(tVectorIO ioVec, tElementIn InEle);
                //////////////////////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tVector& Cross(tVectorOut outVec, tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tElement Dot(tVectorIn InVec1, tVectorIn InVec2);
                WIZ_INLINE static tElement AbsDot(tVectorIn InVec1, tVectorIn InVec2);
                //////////////////////////////////////////////////////////////////////////
                WIZ_INLINE static tElement Normalize(tVectorIO ioVec);
                WIZ_INLINE static tElement Normalize(tVectorOut outVec, tVectorIn InVec);
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
