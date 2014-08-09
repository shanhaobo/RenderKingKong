#ifndef __WIZ_MATH_VECTOR2_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR2_HPP__SHANHAOBO_19800429__

#include "../../Utils/WizMathUtils.hpp"
#include "./WizMathAlgebraVector2Base.hpp"
#include "./WizMathAlgebraVector2Method.hpp"

namespace Wiz
{
    namespace Vector2
    {
        template<class ElementT>
        struct Type : ::Wiz::Vector2::Base::Type<ElementT>
        {
            typedef ::Wiz::Vector2::Base::Type<tElement>        tSuper;
            typedef Type<tElement>                              tThis;
            typedef ::Wiz::Vector2::Method::Type<tThis>         tMethod;
            ////////////////////////////////////////////////////////////////
            Type()
            {}
            Type(const tElement& InX, const tElement& InY) : tSuper(InX, InY)
            {}
            Type(const tElement& InEle) : tSuper(InEle)
            {}
            Type(const tSuper& InOther) : tSuper(InOther)
            {}
            ////////////////////////////////////////////////////////////////

            WIZ_INLINE tThis& operator=(const tSuper& InVec)
            {
                this->x = InVec.x;
                this->y = InVec.y;

                return *this;
            }

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement& operator[](::Wiz::UInt::In i)
            {
                WIZ_ASSERT(i < eCount);
                return this->e[i];
            }
            WIZ_INLINE const tElement& operator[](::Wiz::UInt::In i) const
            {
                WIZ_ASSERT(i < eCount);
                return this->e[i];
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator +(tThisIn InVec1, tThisIn InVec2)
            {
                tThis OutVec;
                tMethod::Add(OutVec, InVec1, InVec2);
                return OutVec;
            }
            WIZ_INLINE friend tThis operator +(tThisIn InVec, const tElement& InEle)
            {
                tThis OutVec;

                return tMethod::Add(OutVec, InVec, InEle);
            }
            WIZ_INLINE friend tThis operator +(const tElement& InEle, tThisIn InVec)
            {
                tThis OutVec;

                return tMethod::Add(OutVec, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator +=(tThis& InOutVec, const tElement& InEle)
            {
                return tMethod::AddAssign(InOutVec, InEle);
            }
            WIZ_INLINE friend tThis& operator +=(tThis& InOutVec, tThisIn InVec)
            {
                return tMethod::AddAssign(InOutVec, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator-(tThisIn InVec1, tThisIn InVec2)
            {
                tThis OutVec;
                tMethod::Subtract(OutVec, InVec1, InVec2);

                return OutVec;
            }
            WIZ_INLINE friend tThis operator-(tThisIn InVec, const tElement& InEle)
            {
                tThis OutVec;

                return tMethod::Subtract(OutVec, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator -=(tThis& InOutVec, const tElement& InEle)
            {
                return tMethod::SubtractAssign(InOutVec, InEle);
            }
            WIZ_INLINE friend tThis& operator -=(tThis& InOutVec, tThisIn InVec)
            {
                return tMethod::SubtractAssign(InOutVec, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator*(tThisIn InVec1, tThisIn InVec2)
            {
                tThis OutVec;
                tMethod::Multiply(OutVec, InVec1, InVec2);

                return OutVec;
            }
            WIZ_INLINE friend tThis operator*(tThisIn InVec, const tElement& InEle)
            {
                tThis OutVec;
                tMethod::Multiply(OutVec, InVec, InEle);

                return OutVec;
            }
            WIZ_INLINE friend tThis operator*(const tElement& InEle, tThisIn InVec)
            {
                tThis OutVec;

                return tMethod::Multiply(OutVec, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator *=(tThis& InOutVec, const tElement& InEle)
            {
                return tMethod::MultiplyAssign(InOutVec, InEle);
            }
            WIZ_INLINE friend tThis& operator *=(tThis& InOutVec, tThisIn InVec)
            {
                return tMethod::MultiplyAssign(InOutVec, InVec);
            }
            ////////////////////////////////////////////////////////////////


            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator/(tThisIn InVec1, tThisIn InVec2)
            {
                tThis OutVec;

                return tMethod::Divide(OutVec, InVec1, InVec2);
            }
            WIZ_INLINE friend tThis operator/(tThisIn InVec, const tElement& InEle)
            {
                tThis OutVec;

                return tMethod::Divide(OutVec, InVec, InEle);
            }

            WIZ_INLINE friend tThis operator/(const tElement& InEle, tThisIn InVec)
            {
                tThis OutVec;

                return tMethod::Divide(OutVec, InEle, InVec);
            }

            WIZ_INLINE friend tThis& operator/=(tThis& InOutVec, const tElement& InEle)
            {
                return tMethod::DivideAssign(InOutVec, InEle);
            }
            WIZ_INLINE friend tThis& operator/=(tThis& InOutVec, tThisIn InVec)
            {
                return tMethod::DivideAssign(InOutVec, InVec);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Bool::Type operator==(tThisIn InVec) const
            {
                return tMethod::IsAbsoluteEqual(*this, InVec);
            }

            WIZ_INLINE ::Wiz::Bool::Type operator!=(tThisIn InVec) const
            {
                return !this->operator==(InVec);
            }

            WIZ_INLINE tThisIn operator+() const
            {
                return *this;
            }

            WIZ_INLINE tThis operator-() const
            {
                tThis OutVec;
                OutVec.x = -this->x;
                OutVec.y = -this->y;
                return OutVec;
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis& operator=(const tElement& InEle)
            {
                this->x = InEle;
                this->y = InEle;

                return *this;
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Zero()
            {
                this->x = ::Wiz::Absolute::GetZero<tElement>();
                this->y = ::Wiz::Absolute::GetZero<tElement>();
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Set(const tElement& Ex, const tElement& Ey)
            {
                this->x = Ex;
                this->y = Ey;
            }

            WIZ_INLINE ::Wiz::Void::Type Get(tElement& Ex, tElement& Ey)
            {
                Ex = this->x;
                Ey = this->y;
            }

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Dot(tThisIn InVec) const
            {
                return tMethod::Dot(*this, InVec);
            }
            WIZ_INLINE static tElement Dot(tThisIn InVec1, tThisIn InVec2)
            {
                return tMethod::Dot(InVec1, InVec2);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement AbsDot(tThisIn InVec) const
            {
                return tMethod::AbsDot(*this, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Normalize()
            {
                return tMethod::Normalize(*this);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement GetNormal(tThis& OutVec) const
            {
                return tMethod::Normalize(OutVec, *this);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis GetNormal() const
            {
                tThis OutVec;
                tMethod::Normalize(OutVec, *this);
                return OutVec;
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrLength() const
            {
                return tMethod::SqrLength(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Length() const
            {
                return tMethod::Length(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement RecipLength() const
            {
                return tMethod::RecipLength(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Distance(tThisIn InVec) const
            {
                return tMethod::Distance(*this, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrDistance(tThisIn InVec) const
            {
                return tMethod::SqrDistance(*this, InVec);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement Distance(tThisIn InVec1, tThisIn InVec2)
            {
                return tMethod::Distance(InVec1, InVec2);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement SqrDistance(tThisIn InVec1, tThisIn InVec2)
            {
                return tMethod::SqrDistance(InVec1, InVec2);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Bool::Type IsAbsoluteZero() const
            {
                return tMethod::IsAbsoluteZero(*this);
            }
            //////////////////////////////////////////////////////////////////////////
        }; /// end of struct Type
    } /// end of namespace Vector2
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR2_HPP__SHANHAOBO_19800429__*/
