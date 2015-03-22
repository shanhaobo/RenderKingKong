#ifndef __WIZ_MATH_ALGEBRA_MATRIX33_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX33_HPP__SHANHAOBO_19800429__

#include "./WizMathAlgebraMatrix33Base.hpp"
#include "./WizMathAlgebraMatrix33ColMajorMethod.hpp"
#include "./WizMathAlgebraMatrix33RowMajorMethod.hpp"

#include "../Matrix22/WizMathAlgebraMatrix22.hpp"
#include "../Vector2/WizMathAlgebraVector2.hpp"
#include "../Vector3/WizMathAlgebraVector3.hpp"

namespace Wiz
{
    namespace Matrix33
    {
        namespace RowMajor
        {
            //////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix33::RowMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                //////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix33::RowMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix33::RowMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Matrix22::RowMajor::Type<ElementT>           tMatrix22;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef ::Wiz::Vector3::Type<tElement>                      tVector3;
                //////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    const tElement& E00, const tElement& E01, const tElement& E02,
                    const tElement& E10, const tElement& E11, const tElement& E12,
                    const tElement& E20, const tElement& E21, const tElement& E22
                    ) : tSuper(E00, E01, E02,E10, E11, E12, E20, E21, E22)
                {}
                explicit Type(const tElement& InEle) : tSuper(InEle)
                {}
                explicit Type(const tSuper& InMat) : tSuper(InMat)
                {}
                //////////////////////////////////////////////////////////

                //////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThis& OutMat) const
                {
                    return tMethod::Transpose(OutMat, *this);
                }
                WIZ_INLINE tThis& Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThis& Zero()
                {
                    return tMethod::Zero(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE tElement Determinant() const
                {
                    return tMethod::Determinant(*this);
                }
                //////////////////////////////////////////////////////////
                ::Wiz::Bool::Type Invert(tThis& OutMat) const
                {
                    return tMethod::Invert(OutMat, *this);
                }
                ::Wiz::Bool::Type Invert()
                {
                    return tMethod::Invert(*this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector3& OutVec3, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutVec3.x, OutVec3.y, OutVec3.z, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector3& OutVec3, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutVec3.x, OutVec3.y, OutVec3.z, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutX, OutY, OutZ, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutX, OutY, OutZ, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector3& InVec3)
                {
                    tSuper::SetRow(Row, InVec3.x, InVec3.y, InVec3.z);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector3& InVec3)
                {
                    tSuper::SetCol(Col, InVec3.x, InVec3.y, InVec3.z);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY, const tElement& InZ)
                {
                    tSuper::SetRow(Row, InX, InY, InZ);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY, const tElement& InZ)
                {
                    tSuper::SetCol(Col, InX, InY, InZ);
                }
                //////////////////////////////////////////////////////////
                template<class Matrix22T, int rj, int ri>
                Matrix22T& GetCofactor(Matrix22T& OutCofactor) const
                {
                    return tSuper::GetCofactor<Matrix22T, rj, ri>(OutCofactor);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis OutMat;
                    return tMethod::Add(OutMat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& InOutMat, tThisIn InMat)
                {
                    return tMethod::AddAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis OutMat;
                    return tMethod::Subtract(OutMat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& InOutMat, tThisIn InMat)
                {
                    return tMethod::SubtractAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThisInOut InOutMat, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat1, const tElement& InEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, InMat1, InEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, const tElement& InEle)
                {
                    return tMethod::MultiplyAssign(InOutMat, InEle);
                }

                WIZ_INLINE friend tVector3 operator*(const tVector3& InVec3, tThisIn InMat)
                {
                    tVector3 Vec3;
                    return tMethod::Multiply(Vec3, InVec3, InMat);
                }
                WIZ_INLINE friend tVector3& operator*=(tVector3& InOutVec3, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutVec3, InMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn InMat) const
                {
                    return tMethod::IsEqual(*this, InMat);
                }
                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn InMat) const
                {
                    return tMethod::IsEqual(*this, InMat) == ::Wiz::Bool::False;
                }

                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }
                WIZ_INLINE tThis operator-() const
                {
                    tThis OutMat;
                    return tMethod::Negative(OutMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(const tElement& InEle)
                {
                    return tMethod::FromElement(*this, InEle);
                }
                WIZ_INLINE tThis& operator=(const tMatrix22& InMat)
                {
                    return tMethod::FromMatrix22(*this, InMat);
                }
                WIZ_INLINE operator tMatrix22() const
                {
                    tMatrix22 OutMat;
                    return tMethod::ToMatrix22(OutMat, *this);
                }
                WIZ_INLINE tThis& operator=(tThisIn InMat)
                {
                    return tMethod::FromMatrix33(*this, InMat);
                }
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* OutArray) const
                {
                    OutArray[0] = this->e00;  OutArray[1] = this->e10;  OutArray[2] = this->e20;
                    OutArray[3] = this->e01;  OutArray[4] = this->e11;  OutArray[5] = this->e21;
                    OutArray[6] = this->e02;  OutArray[7] = this->e12;  OutArray[8] = this->e22;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace RowMajor

        namespace ColMajor
        {
            //////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix33::ColMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                //////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix33::ColMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix33::ColMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Matrix22::ColMajor::Type<ElementT>           tMatrix22;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                typedef ::Wiz::Vector3::Type<tElement>                      tVector3;
                //////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    const tElement& E00, const tElement& E10, const tElement& E20,
                    const tElement& E01, const tElement& E11, const tElement& E21,
                    const tElement& E02, const tElement& E12, const tElement& E22
                    ) : tSuper(E00, E10, E20, E01, E11, E21, E02, E12, E22)
                {}
                Type(const tElement& InEle) : tSuper(InEle)
                {}
                Type(const tSuper& InMat) : tSuper(InMat)
                {}
                //////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThis& OutMat) const
                {
                    return tMethod::Transpose(OutMat, *this);
                }
                WIZ_INLINE tThis& Transpose()
                {
                    return tMethod::Transpose(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Identity()
                {
                    return tMethod::Identity(*this);
                }
                WIZ_INLINE tThis& Zero()
                {
                    return tMethod::Zero(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tElement Determinant() const
                {
                    return tMethod::Determinant(*this);
                }
                ////////////////////////////////////////////////////////////////
                ::Wiz::Bool::Type Invert(tThis& OutMat) const
                {
                    return tMethod::Invert(OutMat, *this);
                }
                ::Wiz::Bool::Type Invert()
                {
                    return tMethod::Invert(*this, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector3& OutVec3, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutVec3.x, OutVec3.y, OutVec3.z, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector3& OutVec3, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutVec3.x, OutVec3.y, OutVec3.z, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutX, OutY, OutZ, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutX, OutY, OutZ, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector3& InVec3)
                {
                    tSuper::SetRow(Row, InVec3.x, InVec3.y, InVec3.z);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector3& InVec3)
                {
                    tSuper::SetCol(Col, InVec3.x, InVec3.y, InVec3.z);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY, const tElement& InZ)
                {
                    tSuper::SetRow(Row, InX, InY, InZ);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY, const tElement& InZ)
                {
                    tSuper::SetCol(Col, InX, InY, InZ);
                }
                //////////////////////////////////////////////////////////////////////////
                template<class Matrix22T, int rj, int ri>
                Matrix22T& GetCofactor(Matrix22T& OutCofactor) const
                {
                    return tSuper::GetCofactor<Matrix22T, rj, ri>(OutCofactor, *this);
                }
                //////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis OutMat;
                    return tMethod::Add(OutMat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& InOutMat, tThisIn InMat2)
                {
                    return tMethod::AddAssign(InOutMat, InMat2);
                }

                WIZ_INLINE friend tThis operator-(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis OutMat;
                    return tMethod::Subtract(OutMat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& InOutMat, tThisIn InMat2)
                {
                    return tMethod::SubtractAssign(InOutMat, InMat2);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat1, tThisIn InMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, InMat1, InMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat1, const tElement& InEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, InMat1, InEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, const tElement& InEle)
                {
                    return tMethod::MultiplyAssign(InOutMat, InEle);
                }

                WIZ_INLINE friend tVector3 operator*(tThisIn InMat, const tVector3& InVec3)
                {
                    tVector3 Vec3;
                    return tMethod::Multiply(Vec3, InVec3, InMat);
                }
                WIZ_INLINE friend tVector3& operator*=(tVector3& InOutVec3, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutVec3, InMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn InMat) const
                {
                    return tMethod::IsEqual(*this, InMat);
                }
                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn InMat) const
                {
                    return tMethod::IsEqual(*this, InMat) == ::Wiz::Bool::False;
                }
                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }
                WIZ_INLINE tThis operator-() const
                {
                    tThis OutMat;
                    return tMethod::Negative(OutMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(const tElement& InEle)
                {
                    return tMethod::FromElement(*this, InEle);
                }
                WIZ_INLINE tThis& operator=(tThisIn InMat)
                {
                    return tMethod::FromMatrix33(*this, InMat);
                }
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* OutArray) const
                {
                    OutArray[0] = this->e00; OutArray[1] = this->e01; OutArray[2] = this->e02;
                    OutArray[3] = this->e10; OutArray[4] = this->e11; OutArray[5] = this->e12;
                    OutArray[6] = this->e20; OutArray[7] = this->e21; OutArray[8] = this->e22;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace ColMajor
    } /// end of namespace Matrix33
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX33_HPP__SHANHAOBO_19800429__*/
