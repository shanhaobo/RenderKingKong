#ifndef __WIZ_MATH_ALGEBRA_MATRIX22_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX22_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__

#include "./WizMathAlgebraMatrix22RowMajorMethod.hpp"

namespace Wiz
{
    namespace Matrix22
    {
        namespace RowMajor
        {
            namespace Method
            {
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::FromElement(tMatrix& OutMat, const tElement& InEle)
                {
                    OutMat.e00 = InEle;
                    OutMat.e01 = InEle;

                    OutMat.e10 = InEle;
                    OutMat.e11 = InEle;

                    return OutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>template<class Matrix22T>
                MatrixT& Type<MatrixT>::FromMatrix22(tMatrix& OutMat, const Matrix22T& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }
                template<class MatrixT>template<class Matrix22T>
                Matrix22T& Type<MatrixT>::ToMatrix22(Matrix22T& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }

                template<class MatrixT>template<class Matrix33T>
                MatrixT& Type<MatrixT>::FromMatrix33(tMatrix& OutMat, const Matrix33T& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }
                template<class MatrixT>template<class Matrix33T>
                Matrix33T& Type<MatrixT>::ToMatrix33(Matrix33T& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }

                template<class MatrixT>template<class Matrix44T>
                MatrixT& Type<MatrixT>::FromMatrix44(tMatrix& OutMat, const Matrix44T& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }
                template<class MatrixT>template<class Matrix44T>
                Matrix44T& Type<MatrixT>::ToMatrix44(Matrix44T& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;

                    return OutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Add(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    OutMat.e00 = InMat1.e00 + InMat2.e00;
                    OutMat.e01 = InMat1.e01 + InMat2.e01;

                    OutMat.e10 = InMat1.e10 + InMat2.e10;
                    OutMat.e11 = InMat1.e11 + InMat2.e11;

                    return OutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Subtract(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    OutMat.e00 = InMat1.e00 - InMat2.e00;
                    OutMat.e01 = InMat1.e01 - InMat2.e01;

                    OutMat.e10 = InMat1.e10 - InMat2.e10;
                    OutMat.e11 = InMat1.e11 - InMat2.e11;

                    return OutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tElement& InEle)
                {
                    OutMat.e00 = InMat1.e00 * InEle;
                    OutMat.e01 = InMat1.e01 * InEle;

                    OutMat.e10 = InMat1.e10 * InEle;
                    OutMat.e11 = InMat1.e11 * InEle;

                    return OutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    const tElement le00 = InMat1.e00 * InMat2.e00 + InMat1.e01 * InMat2.e10;
                    const tElement le01 = InMat1.e00 * InMat2.e01 + InMat1.e01 * InMat2.e11;
                    const tElement le10 = InMat1.e10 * InMat2.e00 + InMat1.e11 * InMat2.e10;
                    const tElement le11 = InMat1.e10 * InMat2.e01 + InMat1.e11 * InMat2.e11;

                    /// 
                    OutMat.e00 = le00;
                    OutMat.e01 = le01;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;

                    return OutMat;
                }
                template<class MatrixT>
                ::Wiz::Vector2::Type<typename MatrixT::tElement>& Type<MatrixT>::Multiply(tVector2& OutVec2, const tVector2& InVec2, const tMatrix& InMat)
                {
                    /// Row vector /// D3D
                    const tElement lx = InVec2.x * InMat.e00 + InVec2.y * InMat.e10;
                    const tElement ly = InVec2.x * InMat.e01 + InVec2.y * InMat.e11;

                    OutVec2.x = lx;
                    OutVec2.y = ly;

                    return OutVec2;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                ::Wiz::Bool::Type Type<MatrixT>::IsEqual(const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    return
                        ::Wiz::IsEqual(InMat1.e00, InMat2.e00) &&
                        ::Wiz::IsEqual(InMat1.e01, InMat2.e01) &&
                        ::Wiz::IsEqual(InMat1.e10, InMat2.e10) &&
                        ::Wiz::IsEqual(InMat1.e11, InMat2.e11);
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                typename MatrixT::tElement Type<MatrixT>::Determinant
                    (
                    const tElement& E00, const tElement& E01,
                    const tElement& E10, const tElement& E11
                    )
                {
                    return E00 * E11 - E01 * E10;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                ::Wiz::Bool::Type Type<MatrixT>::Invert(tMatrix& OutMat, const tMatrix& InMat)
                {
                    MatrixT t = Type<MatrixT>::Determinant(InMat);
                    if (::Wiz::IsZero(t))
                    {
                        return ::Wiz::Bool::False;
                    }
                    t = 1 / t;

                    const tElement le00 =  InMat.e11 * t;
                    const tElement le01 = -InMat.e10 * t;
                    const tElement le10 = -InMat.e01 * t;
                    const tElement le11 =  InMat.e00 * t;

                    /// 
                    OutMat.e00 = le00;
                    OutMat.e01 = le01;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;

                    return ::Wiz::Bool::True;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Transpose(tMatrix& OutMat, const tMatrix& InMat)
                {
                    const tElement le00 = InMat.e00;
                    const tElement le01 = InMat.e10;
                    const tElement le10 = InMat.e01;
                    const tElement le11 = InMat.e11;

                    /// 
                    OutMat.e00 = le00;
                    OutMat.e01 = le01;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;

                    return OutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Transpose(tMatrix& InOutMat)
                {
                    ::Wiz::Swap(InOutMat.e01, InOutMat.e10);

                    return InOutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Identity(tMatrix& InOutMat)
                {
                    InOutMat.e00 = 1; InOutMat.e01 = 0;
                    InOutMat.e10 = 0; InOutMat.e11 = 1;

                    return InOutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Zero(tMatrix& InOutMat)
                {
                    InOutMat.e00 = 0; InOutMat.e01 = 0;
                    InOutMat.e10 = 0; InOutMat.e11 = 0;

                    return InOutMat;
                }
                ////////////////////////////////////////////////////////////////
            } /// end of namespace Method
        } /// end of namespace RowMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX22_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__*/
