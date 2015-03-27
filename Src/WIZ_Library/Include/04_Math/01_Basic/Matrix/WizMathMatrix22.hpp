#ifndef __WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__

#include "./WizMathMatrix22Base.hpp"
#include "./WizMathMatrix22RowMajorMethod.hpp"
#include "./WizMathMatrix22ColMajorMethod.hpp"

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
                Type(tElementIn E00, tElementIn E01, tElementIn E10, tElementIn E11) : tSuper(E00, E01, E10, E11)
                {}
                Type(tElementIn inEle) : tSuper(inEle)
                {}
                Type(const tSuper& inMat) : tSuper(inMat)
                {}
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThis& outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
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
                ::Wiz::Bool::Type invert(tThis& outMat) const
                {
                    return tMethod::invert(outMat, *this);
                }
                ::Wiz::Bool::Type invert()
                {
                    return tMethod::invert(*this, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2& outVec2, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(outVec2.x, outVec2.y, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector2& outVec2, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(outVec2.x, outVec2.y, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(outX, outY, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(outX, outY, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector2& inVec2)
                {
                    tSuper::SetRow(Row, inVec2.x, inVec2.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector2& inVec2)
                {
                    tSuper::SetCol(Col, inVec2.x, inVec2.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetRow(Row, inX, inY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetCol(Col, inX, inY);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Add(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::AddAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Subtract(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::SubtractAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat, tElementIn inEle)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector2 operator*(const tVector2& inVec, tThisIn inMat)
                {
                    tVector2 Vec;
                    return tMethod::Multiply(Vec, inVec, inMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& ioVec, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec, inMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat) == ::Wiz::Bool::False;
                }

                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }

                WIZ_INLINE tThis operator-() const
                {
                    tThis outMat;
                    return tMethod::Negative(outMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }

                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix22(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00;  outArray[1] = this->e10;
                    outArray[2] = this->e01;  outArray[3] = this->e11;
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
                    tElementIn E00, tElementIn E10,
                    tElementIn E01, tElementIn E11
                    ) : tSuper(E00, E10, E01, E11)
                {}
                Type(tElementIn inEle) : tSuper(inEle)
                {}
                Type(const tSuper& inMat) : tSuper(inMat)
                {}
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& Transpose(tThis& outMat) const
                {
                    return tMethod::Transpose(outMat, *this);
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
                ::Wiz::Bool::Type invert(tThis& outMat) const
                {
                    return tMethod::invert(outMat, *this);
                }
                ::Wiz::Bool::Type invert()
                {
                    return tMethod::invert(*this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetRow(tVector2& outVec, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(outVec.x, outVec.y, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tVector2& outVec, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(outVec.x, outVec.y, Col);
                }

                WIZ_INLINE ::Wiz::Void::Type GetRow(tElement& outX, tElement& outY, ::Wiz::UInt::In Row) const
                {
                    tSuper::GetRow(outX, outY, Row);
                }
                WIZ_INLINE ::Wiz::Void::Type GetCol(tElement& outX, tElement& outY, ::Wiz::UInt::In Col) const
                {
                    tSuper::GetCol(outX, outY, Col);
                }

                /**/
                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tVector2& inVec)
                {
                    tSuper::SetRow(Row, inVec.x, inVec.y);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tVector2& inVec)
                {
                    tSuper::SetCol(Col, inVec.x, inVec.y);
                }

                WIZ_INLINE ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetRow(Row, inX, inY);
                }
                WIZ_INLINE ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, tElementIn inX, tElementIn inY)
                {
                    tSuper::SetCol(Col, inX, inY);
                }

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE friend tThis operator+(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Add(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator+=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::AddAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator-(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis outMat;
                    return tMethod::Subtract(outMat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator-=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::SubtractAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat1, tThisIn inMat2)
                {
                    tThis Mat;
                    return tMethod::Multiply(Mat, inMat1, inMat2);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioMat, inMat);
                }

                WIZ_INLINE friend tThis operator*(tThisIn inMat, tElementIn inEle)
                {
                    tThis outMat;
                    return tMethod::Multiply(outMat, inMat, inEle);
                }
                WIZ_INLINE friend tThis& operator*=(tThis& ioMat, tElementIn inEle)
                {
                    return tMethod::MultiplyAssign(ioMat, inEle);
                }

                WIZ_INLINE friend tVector2 operator*(tThisIn inMat, const tVector2& inVec)
                {
                    tVector2 outVec;
                    return tMethod::Multiply(outVec, inVec, inMat);
                }
                WIZ_INLINE friend tVector2& operator*=(tVector2& ioVec, tThisIn inMat)
                {
                    return tMethod::MultiplyAssign(ioVec, inMat);
                }
                ////////////////////////////////////////////////////////////////

                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat);
                }

                WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn inMat) const
                {
                    return tMethod::IsEqual(*this, inMat) == ::Wiz::Bool::False;
                }
                WIZ_INLINE tThisIn operator+() const
                {
                    return *this;
                }
                WIZ_INLINE tThis operator-() const
                {
                    tThis outMat;
                    return tMethod::Negative(outMat, *this);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE tThis& operator=(tElementIn inEle)
                {
                    return tMethod::FromElement(*this, inEle);
                }

                WIZ_INLINE tThis& operator=(tThisIn inMat)
                {
                    return tMethod::FromMatrix22(*this, inMat);
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Void::Type GetTransposeArray(float* outArray) const
                {
                    outArray[0] = this->e00; outArray[1] = this->e01;
                    outArray[2] = this->e10; outArray[3] = this->e11;
                }
                ////////////////////////////////////////////////////////////////
            }; /// end of struct Type
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_MATRIX22_HPP__SHANHAOBO_19800429__*/
