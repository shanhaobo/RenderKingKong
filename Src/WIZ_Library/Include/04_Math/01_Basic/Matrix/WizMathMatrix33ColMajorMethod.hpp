#ifndef __WIZ_MATH_ALGEBRA_MATRIX33_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX33_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__

#include "../../Utils/WizMathUtils.hpp"
#include "../Matrix22/WizMathAlgebraMatrix22ColMajorMethod.hpp"
#include "../Vector3/WizMathAlgebraVector3.hpp"

namespace Wiz
{
    namespace Matrix33
    {
        namespace ColMajor
        {
            /*
            **
            **  第0行   第1行   第2行
            **   e00,    e10,    e20;      /// 第0列(Col0)
            **   e01,    e11,    e21;      /// 第1列(Col1)
            **   e02,    e12,    e22;      /// 第2列(Col2)
            **
            **/
            namespace Method
            {
                template<class MatrixT>
                struct Type
                {
                    ////////////////////////////////////////////////////////////////
                    typedef MatrixT                                             tMatrix;
                    typedef typename tMatrix::tElement                          tElement;
                    typedef Type<tMatrix>                                       tThis;
                    typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                    typedef ::Wiz::Vector3::Type<tElement>                      tVector3;
                    typedef ::Wiz::Matrix22::ColMajor::Method::Type<tMatrix>    tMatrix22;
                    ////////////////////////////////////////////////////////////////
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
                    WIZ_INLINE static tVector3& Multiply(tVector3& OutVec3, const tVector3& InVec3, const tMatrix& InMat);
                    WIZ_INLINE static tVector3& MultiplyAssign(tVector3& InOutVec3, const tMatrix& InMat)
                    {
                        return tThis::Multiply(InOutVec3, InOutVec3, InMat);
                    }
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static ::Wiz::Bool::Type IsEqual(const tMatrix& InMat1, const tMatrix& InMat2);
                    WIZ_INLINE static ::Wiz::Bool::Type NotEqual(const tMatrix& InMat1, const tMatrix& InMat2)
                    {
                        return  tMatrix::IsEqual(InMat1, InMat2) == ::Wiz::Bool::False;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE static tElement Determinant
                        (
                        const tElement& E00, const tElement& E10, const tElement& E20,
                        const tElement& E01, const tElement& E11, const tElement& E21,
                        const tElement& E02, const tElement& E12, const tElement& E22
                        );
                    WIZ_INLINE static tElement Determinant(const tMatrix& InMat)
                    {
                        return tMatrix::Determinant
                            (
                            InMat.e00, InMat.e10, InMat.e20,
                            InMat.e01, InMat.e11, InMat.e21,
                            InMat.e02, InMat.e12, InMat.e22
                            );
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
    } /// end of namespace Matrix33
} /// end of namespace Wiz

#include "./WizMathAlgebraMatrix33ColMajorMethod.inl"

#endif /*__WIZ_MATH_ALGEBRA_MATRIX33_COLMAJOR_METHOD_HPP__SHANHAOBO_19800429__*/
