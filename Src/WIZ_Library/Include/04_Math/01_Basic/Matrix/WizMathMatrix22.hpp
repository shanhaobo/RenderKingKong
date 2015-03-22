#ifndef __WIZ_MATH_ALGEBRA_MATRIX22_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX22_HPP__SHANHAOBO_19800429__

#include "./WizMathAlgebraMatrix22Base.hpp"
#include "./WizMathAlgebraMatrix22RowMajorMethod.hpp"
#include "./WizMathAlgebraMatrix22ColMajorMethod.hpp"

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace RowMajor
        {
            //////////////////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix22::RowMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                ////////////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix22::RowMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix22::RowMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                ////////////////////////////////////////////////////////////////
                Type()
                {}
                Type(const tElement& E00, const tElement& E01, const tElement& E10, const tElement& E11) : tSuper(E00, E01, E10, E11)
                {}
                Type(const tElement& InEle) : tSuper(InEle)
                {}
                Type(const tSuper& InMat) : tSuper(InMat)
                {}
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
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2& OutVec2, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutVec2.x, OutVec2.y, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector2& OutVec2, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutVec2.x, OutVec2.y, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutX, OutY, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutX, OutY, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector2& InVec2)
                {
                    tSuper::SetRow(Row, InVec2.x, InVec2.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector2& InVec2)
                {
                    tSuper::SetCol(Col, InVec2.x, InVec2.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY)
                {
                    tSuper::SetRow(Row, InX, InY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY)
                {
                    tSuper::SetCol(Col, InX, InY);
                }
                ////////////////////////////////////////////////////////////////
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
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat, const tElement& InEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, InMat, InEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, const tElement& InEle)
                {
                    return tMethod::MultiplyAssign(InOutMat, InEle);
                }

                WIZ_INLINE friend tVector2 operator*(const tVector2& InVec, tThisIn InMat)
                {
                    tVector2 Vec;
                    return tMethod::Multiply(Vec, InVec, InMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& InOutVec, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutVec, InMat);
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
                    return tMethod::FromMatrix22(*this, InMat);
                }

                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* OutArray) const
                {
                    OutArray[0] = this->e00;  OutArray[1] = this->e10;
                    OutArray[2] = this->e01;  OutArray[3] = this->e11;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace Matrix22
    } /// end of namespace RowMajor
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace ColMajor
        {
            //////////////////////////////////////////////////////////////////////////
            template<typename ElementT>
            struct Type : public ::Wiz::Matrix22::ColMajor::Base::Type<ElementT>
            {
                WIZ_DECLARE_CLASS_THIS(Type);
                ////////////////////////////////////////////////////////////////
                typedef tThis                                               tCore;
                typedef ::Wiz::Matrix22::ColMajor::Base::Type<tElement>     tSuper;
                typedef ::Wiz::Matrix22::ColMajor::Method::Type<tThis>      tMethod;
                typedef ::Wiz::Vector2::Type<tElement>                      tVector2;
                ////////////////////////////////////////////////////////////////
                Type()
                {}
                Type(
                    const tElement& E00, const tElement& E10,
                    const tElement& E01, const tElement& E11
                    ) : tSuper(E00, E10, E01, E11)
                {}
                Type(const tElement& InEle) : tSuper(InEle)
                {}
                Type(const tSuper& InMat) : tSuper(InMat)
                {}
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
                    return tMethod::Invert(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2& OutVec, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutVec.x, OutVec.y, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector2& OutVec, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutVec.x, OutVec.y, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(OutX, OutY, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(OutX, OutY, Col);
                }

                /**/
                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector2& InVec)
                {
                    tSuper::SetRow(Row, InVec.x, InVec.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector2& InVec)
                {
                    tSuper::SetCol(Col, InVec.x, InVec.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY)
                {
                    tSuper::SetRow(Row, InX, InY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY)
                {
                    tSuper::SetCol(Col, InX, InY);
                }

                ////////////////////////////////////////////////////////////////
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
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutMat, InMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn InMat, const tElement& InEle)
                {
                    tThis OutMat;
                    return tMethod::Multiply(OutMat, InMat, InEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& InOutMat, const tElement& InEle)
                {
                    return tMethod::MultiplyAssign(InOutMat, InEle);
                }

                WIZ_INLINE friend tVector2 operator*(tThisIn InMat, const tVector2& InVec)
                {
                    tVector2 OutVec;
                    return tMethod::Multiply(OutVec, InVec, InMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& InOutVec, tThisIn InMat)
                {
                    return tMethod::MultiplyAssign(InOutVec, InMat);
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
                    return tMethod::FromMatrix22(*this, InMat);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* OutArray) const
                {
                    OutArray[0] = this->e00; OutArray[1] = this->e01;
                    OutArray[2] = this->e10; OutArray[3] = this->e11;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX22_HPP__SHANHAOBO_19800429__*/
