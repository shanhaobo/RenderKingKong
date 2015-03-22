#ifndef __WIZ_MATH_ALGEBRA_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__

#include "../Vector2/WizMathAlgebraVector2.hpp"
//#include "../../Utils/WizMathUtils.hpp"

namespace Wiz
{
    namespace Matrix22
    {
        namespace ColMajor
        {
            namespace Method
            {
                template<class MatrixT>
                struct Type
                {
                    //////////////////////////////////////////////////////////////////////////
                    typedef MatrixT                                             tMatrix;
                    typedef Type<tMatrix>                                       tThis;
                    typedef typename tMatrix::tElement                          tElement;
                    typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                    //////////////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& FromElement(tMatrix& OutMat, const tElement& InEle);
                    ////////////////////////////////////////////////////////////////
                    template<class Matrix22T>
                    WIZ_INLINE static tMatrix& FromMatrix22(tMatrix& OutMat, const Matrix22T& InMat);
                    template<class Matrix22T>
                    WIZ_INLINE static Matrix22T& ToMatrix22(Matrix22T& OutMat, const tMatrix& InMat);

                    template<class Matrix33T>
                    WIZ_INLINE static tMatrix& FromMatrix33(tMatrix& OutMat, const Matrix33T& InMat);
                    template<class Matrix33T>
                    WIZ_INLINE static Matrix33T& ToMatrix33(Matrix33T& OutMat, const tMatrix& InMat);

                    template<class Matrix44T>
                    WIZ_INLINE static tMatrix& FromMatrix44(tMatrix& OutMat, const Matrix44T& InMat);
                    template<class Matrix44T>
                    WIZ_INLINE static Matrix44T& ToMatrix44(Matrix44T& OutMat, const tMatrix& InMat);
                    ////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Add(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2);
                    WIZ_INLINE static tMatrix& AddAssign(tMatrix& InOutMat, const tMatrix& InMat)
                    {
                        return tThis::Add(InOutMat, InOutMat, InMat);
                    }

                    WIZ_INLINE static tMatrix& Subtract(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2);
                    WIZ_INLINE static tMatrix& SubtractAssign(tMatrix& InOutMat, const tMatrix& InMat)
                    {
                        return tThis::Subtract(InOutMat, InOutMat, InMat);
                    }

                    WIZ_INLINE static tMatrix& Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tElement& InEle);
                    WIZ_INLINE static tMatrix& MultiplyAssign(tMatrix& InOutMat, const tElement& InEle)
                    {
                        return tThis::Multiply(InOutMat, InOutMat, InEle);
                    }

                    WIZ_INLINE static tMatrix& Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2);
                    WIZ_INLINE static tMatrix& MultiplyAssign(tMatrix& InOutMat, const tMatrix& InMat)
                    {
                        return tThis::Multiply(InOutMat, InOutMat, InMat);
                    }

                    WIZ_INLINE static tVector2& Multiply(tVector2& OutVec2, const tVector2& InVec2, const tMatrix& InMat);
                    WIZ_INLINE static tVector2& MultiplyAssign(tVector2& InOutVec2, const tMatrix& InMat)
                    {
                        return tThis::Multiply(InOutVec2, InOutVec2, InMat);
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static ::Wiz::Bool::Type IsEqual(const tMatrix& InMat1, const tMatrix& InMat2);
                    WIZ_INLINE static ::Wiz::Bool::Type NotEqual(const tMatrix& InMat1, const tMatrix& InMat2)
                    {
                        return  tMatrix::IsEqual(InMat1, InMat2) == ::Wiz::Bool::False;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tElement Determinant
                        (
                        const tElement& E00, const tElement& E10,
                        const tElement& E01, const tElement& E11
                        );
                    WIZ_INLINE static tElement Determinant(const tMatrix& InMat)
                    {
                        return tMatrix::Determinant(InMat.e00, InMat.e10, InMat.e01, InMat.e11);
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static ::Wiz::Bool::Type Invert(tMatrix& OutMat, const tMatrix& InMat);
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Transpose(tMatrix& OutMat, const tMatrix& InMat);
                    WIZ_INLINE static tMatrix& Transpose(tMatrix& InOutMat);
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Identity(tMatrix& InOutMat);
                    WIZ_INLINE static tMatrix& Zero(tMatrix& InOutMat);
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tMatrix& Negative(tMatrix& OutMat, const tMatrix& InMat);
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
            } /// end of namespace Method
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#include "./WizMathAlgebraMatrix22ColMajorMethod.inl"

#endif /*__WIZ_MATH_ALGEBRA_MATRIX22_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__*/
