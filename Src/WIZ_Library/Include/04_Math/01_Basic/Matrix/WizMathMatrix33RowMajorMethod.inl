#ifndef __WIZ_MATH_ALGEBRA_MATRIX33_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX33_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__

#include "./WizMathAlgebraMatrix33RowMajorMethod.hpp"

namespace Wiz
{
    namespace Matrix33
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
                    OutMat.e02 = InEle;

                    OutMat.e10 = InEle;
                    OutMat.e11 = InEle;
                    OutMat.e12 = InEle;

                    OutMat.e20 = InEle;
                    OutMat.e21 = InEle;
                    OutMat.e22 = InEle;

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
                    OutMat.e02 = InMat.e02;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;
                    OutMat.e12 = InMat.e12;

                    OutMat.e20 = InMat.e20;
                    OutMat.e21 = InMat.e21;
                    OutMat.e22 = InMat.e22;

                    return OutMat;
                }
                template<class MatrixT>template<class Matrix33T>
                Matrix33T& Type<MatrixT>::ToMatrix33(Matrix33T& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;
                    OutMat.e02 = InMat.e02;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;
                    OutMat.e12 = InMat.e12;

                    OutMat.e20 = InMat.e20;
                    OutMat.e21 = InMat.e21;
                    OutMat.e22 = InMat.e22;

                    return OutMat;
                }

                template<class MatrixT>template<class Matrix44T>
                MatrixT& Type<MatrixT>::FromMatrix44(tMatrix& OutMat, const Matrix44T& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;
                    OutMat.e02 = InMat.e02;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;
                    OutMat.e12 = InMat.e12;

                    OutMat.e20 = InMat.e20;
                    OutMat.e21 = InMat.e21;
                    OutMat.e22 = InMat.e22;

                    return OutMat;
                }
                template<class MatrixT>template<class Matrix44T>
                Matrix44T& Type<MatrixT>::ToMatrix44(Matrix44T& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = InMat.e00;
                    OutMat.e01 = InMat.e01;
                    OutMat.e02 = InMat.e02;

                    OutMat.e10 = InMat.e10;
                    OutMat.e11 = InMat.e11;
                    OutMat.e12 = InMat.e12;

                    OutMat.e20 = InMat.e20;
                    OutMat.e21 = InMat.e21;
                    OutMat.e22 = InMat.e22;

                    return OutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Add(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    OutMat.e00 = InMat1.e00 + InMat2.e00;
                    OutMat.e01 = InMat1.e01 + InMat2.e01;
                    OutMat.e02 = InMat1.e02 + InMat2.e02;

                    OutMat.e10 = InMat1.e10 + InMat2.e10;
                    OutMat.e11 = InMat1.e11 + InMat2.e11;
                    OutMat.e12 = InMat1.e12 + InMat2.e12;

                    OutMat.e20 = InMat1.e20 + InMat2.e20;
                    OutMat.e21 = InMat1.e21 + InMat2.e21;
                    OutMat.e22 = InMat1.e22 + InMat2.e22;

                    return OutMat;
                }

                template<class MatrixT>
                MatrixT& Type<MatrixT>::Subtract(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    OutMat.e00 = InMat1.e00 - InMat2.e00;
                    OutMat.e01 = InMat1.e01 - InMat2.e01;
                    OutMat.e02 = InMat1.e02 - InMat2.e02;

                    OutMat.e10 = InMat1.e10 - InMat2.e10;
                    OutMat.e11 = InMat1.e11 - InMat2.e11;
                    OutMat.e12 = InMat1.e12 - InMat2.e12;

                    OutMat.e20 = InMat1.e20 - InMat2.e20;
                    OutMat.e21 = InMat1.e21 - InMat2.e21;
                    OutMat.e22 = InMat1.e22 - InMat2.e22;

                    return OutMat;
                }

                template<class MatrixT>
                MatrixT& Type<MatrixT>::Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tElement& InEle)
                {
                    OutMat.e00 = InMat1.e00 * InEle;
                    OutMat.e01 = InMat1.e01 * InEle;
                    OutMat.e02 = InMat1.e02 * InEle;

                    OutMat.e10 = InMat1.e10 * InEle;
                    OutMat.e11 = InMat1.e11 * InEle;
                    OutMat.e12 = InMat1.e12 * InEle;

                    OutMat.e20 = InMat1.e20 * InEle;
                    OutMat.e21 = InMat1.e21 * InEle;
                    OutMat.e22 = InMat1.e22 * InEle;

                    return OutMat;
                }

                template<class MatrixT>
                MatrixT& Type<MatrixT>::Multiply(tMatrix& OutMat, const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    const tElement le00 = InMat1.e00 * InMat2.e00 + InMat1.e01 * InMat2.e10 + InMat1.e02 * InMat2.e20;
                    const tElement le01 = InMat1.e00 * InMat2.e01 + InMat1.e01 * InMat2.e11 + InMat1.e02 * InMat2.e21;
                    const tElement le02 = InMat1.e00 * InMat2.e02 + InMat1.e01 * InMat2.e12 + InMat1.e02 * InMat2.e22;

                    const tElement le10 = InMat1.e10 * InMat2.e00 + InMat1.e11 * InMat2.e10 + InMat1.e12 * InMat2.e20;
                    const tElement le11 = InMat1.e10 * InMat2.e01 + InMat1.e11 * InMat2.e11 + InMat1.e12 * InMat2.e21;
                    const tElement le12 = InMat1.e10 * InMat2.e02 + InMat1.e11 * InMat2.e12 + InMat1.e12 * InMat2.e22;

                    const tElement le20 = InMat1.e20 * InMat2.e00 + InMat1.e21 * InMat2.e10 + InMat1.e22 * InMat2.e20;
                    const tElement le21 = InMat1.e20 * InMat2.e01 + InMat1.e21 * InMat2.e11 + InMat1.e22 * InMat2.e21;
                    const tElement le22 = InMat1.e20 * InMat2.e02 + InMat1.e21 * InMat2.e12 + InMat1.e22 * InMat2.e22;

                    OutMat.e00 = le00;
                    OutMat.e01 = le01;
                    OutMat.e02 = le02;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;
                    OutMat.e12 = le12;

                    OutMat.e20 = le20;
                    OutMat.e21 = le21;
                    OutMat.e22 = le22;

                    return OutMat;
                }
                template<class MatrixT>
                ::Wiz::Vector3::Type<typename MatrixT::tElement>& Type<MatrixT>::Multiply(tVector3& OutVec3, const tVector3& InVec3, const tMatrix& InMat)
                {
                    const tElement lx = InVec3.x * InMat.e00 + InVec3.y * InMat.e10 + InVec3.z * InMat.e20;
                    const tElement ly = InVec3.x * InMat.e01 + InVec3.y * InMat.e11 + InVec3.z * InMat.e21;
                    const tElement lz = InVec3.x * InMat.e02 + InVec3.y * InMat.e12 + InVec3.z * InMat.e22;

                    OutVec3.x = lx;
                    OutVec3.y = ly;
                    OutVec3.z = lz;

                    return OutVec3;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                ::Wiz::Bool::Type Type<MatrixT>::IsEqual(const tMatrix& InMat1, const tMatrix& InMat2)
                {
                    return
                        ::Wiz::IsEqual(InMat1.e00, InMat2.e00) &&
                        ::Wiz::IsEqual(InMat1.e01, InMat2.e01) &&
                        ::Wiz::IsEqual(InMat1.e02, InMat2.e02) &&
                        ::Wiz::IsEqual(InMat1.e10, InMat2.e10) &&
                        ::Wiz::IsEqual(InMat1.e11, InMat2.e11) &&
                        ::Wiz::IsEqual(InMat1.e12, InMat2.e12) &&
                        ::Wiz::IsEqual(InMat1.e20, InMat2.e20) &&
                        ::Wiz::IsEqual(InMat1.e21, InMat2.e21) &&
                        ::Wiz::IsEqual(InMat1.e22, InMat2.e22);
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                typename MatrixT::tElement Type<MatrixT>::Determinant
                    (
                    const tElement& E00, const tElement& E01, const tElement& E02,
                    const tElement& E10, const tElement& E11, const tElement& E12,
                    const tElement& E20, const tElement& E21, const tElement& E22
                    )
                {
                    return
                        E00 * tMatrix22::Determinant(E11, E12, E21, E22) -
                        E01 * tMatrix22::Determinant(E10, E12, E20, E22) +
                        E02 * tMatrix22::Determinant(E10, E11, E20, E21);
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                ::Wiz::Bool::Type Type<MatrixT>::Invert(tMatrix& OutMat, const tMatrix& InMat)
                {
                    tElement t;

                    ////////////////////////////////////////////////////////////
                    tElement le00 =  tMatrix22::Determinant
                        (
                        InMat.e11, InMat.e12,
                        InMat.e21, InMat.e22
                        );
                    tElement le10 = -tMatrix22::Determinant
                        (
                        InMat.e10, InMat.e12,
                        InMat.e20, InMat.e22
                        );
                    tElement le20 =  tMatrix22::Determinant
                        (
                        InMat.e10, InMat.e11,
                        InMat.e20, InMat.e21
                        );

                    /// ÐÐÁÐÊ½
                    t = le00 * InMat.e00 + le10 * InMat.e01 + le20 * InMat.e02;
                    if (::Wiz::IsZero(t))
                    {
                        return ::Wiz::Bool::False;
                    }
                    t = 1 / t;

                    le00 *= t;
                    le10 *= t;
                    le20 *= t;

                    ////////////////////////////////////////////////////////////
                    const tElement le01 = -tMatrix22::Determinant(
                        InMat.e01, InMat.e02,
                        InMat.e21, InMat.e22
                        ) * t;
                    const tElement le11 =  tMatrix22::Determinant(
                        InMat.e00, InMat.e02,
                        InMat.e20, InMat.e22
                        ) * t;
                    const tElement le21 = -tMatrix22::Determinant(
                        InMat.e00, InMat.e01,
                        InMat.e20, InMat.e21
                        ) * t;

                    ////////////////////////////////////////////////////////////
                    const tElement le02 =  tMatrix22::Determinant(
                        InMat.e01, InMat.e02,
                        InMat.e11, InMat.e12
                        ) * t;
                    const tElement le12 = -tMatrix22::Determinant(
                        InMat.e00, InMat.e02,
                        InMat.e10, InMat.e12
                        ) * t;
                    const tElement le22 =  tMatrix22::Determinant(
                        InMat.e00, InMat.e01,
                        InMat.e10, InMat.e11
                        ) * t;

                    ////////////////////////////////////////////////////////////

                    OutMat.e00 = le00;
                    OutMat.e01 = le01;
                    OutMat.e02 = le02;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;
                    OutMat.e12 = le12;

                    OutMat.e20 = le20;
                    OutMat.e21 = le21;
                    OutMat.e22 = le22;

                    return ::Wiz::Bool::True;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Transpose(tMatrix& OutMat, const tMatrix& InMat)
                {
                    const tElement le00 = InMat.e00;
                    const tElement le01 = InMat.e10;
                    const tElement le02 = InMat.e20;

                    const tElement le10 = InMat.e01;
                    const tElement le11 = InMat.e11;
                    const tElement le12 = InMat.e21;

                    const tElement le20 = InMat.e02;
                    const tElement le21 = InMat.e12;
                    const tElement le22 = InMat.e22;

                    OutMat.e00 = le00;
                    OutMat.e01 = le01;
                    OutMat.e02 = le02;

                    OutMat.e10 = le10;
                    OutMat.e11 = le11;
                    OutMat.e12 = le12;

                    OutMat.e20 = le20;
                    OutMat.e21 = le21;
                    OutMat.e22 = le22;

                    return OutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Transpose(tMatrix& InOutMat)
                {
                    ::Wiz::Swap(InOutMat.e01, InOutMat.e10);
                    ::Wiz::Swap(InOutMat.e02, InOutMat.e20);
                    ::Wiz::Swap(InOutMat.e12, InOutMat.e21);

                    return InOutMat;
                }
                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Identity(tMatrix& InOutMat)
                {
                    InOutMat.e00 = 1; InOutMat.e01 = 0; InOutMat.e02 = 0;
                    InOutMat.e10 = 0; InOutMat.e11 = 1; InOutMat.e12 = 0;
                    InOutMat.e20 = 0; InOutMat.e21 = 0; InOutMat.e22 = 1;

                    return InOutMat;
                }
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Zero(tMatrix& InOutMat)
                {
                    InOutMat.e00 = 0; InOutMat.e01 = 0; InOutMat.e02 = 0;
                    InOutMat.e10 = 0; InOutMat.e11 = 0; InOutMat.e12 = 0;
                    InOutMat.e20 = 0; InOutMat.e21 = 0; InOutMat.e22 = 0;

                    return InOutMat;
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                template<class MatrixT>
                MatrixT& Type<MatrixT>::Negative(tMatrix& OutMat, const tMatrix& InMat)
                {
                    OutMat.e00 = -InMat.e00;
                    OutMat.e01 = -InMat.e01;
                    OutMat.e02 = -InMat.e02;

                    OutMat.e10 = -InMat.e10;
                    OutMat.e11 = -InMat.e11;
                    OutMat.e12 = -InMat.e12;

                    OutMat.e20 = -InMat.e20;
                    OutMat.e21 = -InMat.e21;
                    OutMat.e22 = -InMat.e22;

                    return OutMat;
                }
                ////////////////////////////////////////////////////////////////
            } /// end of namespace Method
        } /// end of namespace RowMajor
    } /// end of namespace Matrix33
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX33_ROWMAJOR_METHOD_INL__SHANHAOBO_19800429__*/

