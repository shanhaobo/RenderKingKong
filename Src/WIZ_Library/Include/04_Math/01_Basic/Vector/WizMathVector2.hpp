#ifndef __WIZ_MATH_VECTOR2_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR2_HPP__SHANHAOBO_19800429__

#include "../../00_Utils/WizMathUtils.hpp"
#include "./WizMathVector2Base.hpp"
#include "./WizMathVector2Method.hpp"

namespace Wiz
{
    namespace Vector2
    {
        template<class ElementT>
        struct Type : ::Wiz::Vector2::Base::Type<ElementT>
        {
            ////////////////////////////////////////////////////////////////
            typedef ::Wiz::Vector2::Base::Type<tElement>    tSuper;
            typedef tSuper const &                          tSuperIn;

            typedef Type                                    tThis;
            typedef tThis const &                           tThisIn;

            typedef ::Wiz::Vector2::Method::Type<tThis>     tMethod;
            ////////////////////////////////////////////////////////////////
            Type()
            {}
            Type(tElementIn InX, tElementIn InY) : tSuper(InX, InY)
            {}
            Type(tElementIn InEle) : tSuper(InEle)
            {}
            Type(tSuperIn InOther) : tSuper(InOther)
            {}
            ////////////////////////////////////////////////////////////////

            WIZ_INLINE tThis& operator=(tSuperIn InVec)
            {
                x = InVec.x;
                y = InVec.y;

                return *this;
            }

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement& operator[](::Wiz::U::In i)
            {
                WIZ_ASSERT(i < eCount);
                return e[i];
            }
            WIZ_INLINE tElementIn operator[](::Wiz::U::In i) const
            {
                WIZ_ASSERT(i < eCount);
                return e[i];
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator +(tThisIn InVec1, tThisIn InVec2)
            {
                tThis lResult;
                tMethod::Add(lResult, InVec1, InVec2);
                return lResult;
            }
            WIZ_INLINE friend tThis operator +(tThisIn InVec, tElementIn InEle)
            {
                tThis lResult;

                return tMethod::Add(lResult, InVec, InEle);
            }
            WIZ_INLINE friend tThis operator +(tElementIn InEle, tThisIn InVec)
            {
                tThis lResult;

                return tMethod::Add(lResult, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tElementIn InEle)
            {
                return tMethod::AddAssign(ioVec, InEle);
            }
            WIZ_INLINE friend tThis& operator +=(tThisIO ioVec, tThisIn InVec)
            {
                return tMethod::AddAssign(ioVec, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator-(tThisIn InVec1, tThisIn InVec2)
            {
                tThis lResult;
                tMethod::Subtract(lResult, InVec1, InVec2);

                return lResult;
            }
            WIZ_INLINE friend tThis operator-(tThisIn InVec, tElementIn InEle)
            {
                tThis lResult;
                return tMethod::Subtract(lResult, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tElementIn InEle)
            {
                return tMethod::SubtractAssign(ioVec, InEle);
            }
            WIZ_INLINE friend tThis& operator -=(tThisIO ioVec, tThisIn InVec)
            {
                return tMethod::SubtractAssign(ioVec, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator*(tThisIn InVec1, tThisIn InVec2)
            {
                tThis lResult;
                tMethod::Multiply(lResult, InVec1, InVec2);

                return lResult;
            }
            WIZ_INLINE friend tThis operator*(tThisIn InVec, tElementIn InEle)
            {
                tThis lResult;
                tMethod::Multiply(lResult, InVec, InEle);

                return lResult;
            }
            WIZ_INLINE friend tThis operator*(tElementIn InEle, tThisIn InVec)
            {
                tThis lResult;

                return tMethod::Multiply(lResult, InVec, InEle);
            }

            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tElementIn InEle)
            {
                return tMethod::MultiplyAssign(ioVec, InEle);
            }
            WIZ_INLINE friend tThis& operator *=(tThisIO ioVec, tThisIn InVec)
            {
                return tMethod::MultiplyAssign(ioVec, InVec);
            }
            ////////////////////////////////////////////////////////////////


            ////////////////////////////////////////////////////////////////
            WIZ_INLINE friend tThis operator/(tThisIn InVec1, tThisIn InVec2)
            {
                tThis lResult;

                return tMethod::Divide(lResult, InVec1, InVec2);
            }
            WIZ_INLINE friend tThis operator/(tThisIn InVec, tElementIn InEle)
            {
                tThis lResult;

                return tMethod::Divide(lResult, InVec, InEle);
            }

            WIZ_INLINE friend tThis operator/(tElementIn InEle, tThisIn InVec)
            {
                tThis lResult;

                return tMethod::Divide(lResult, InEle, InVec);
            }

            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tElementIn InEle)
            {
                return tMethod::DivideAssign(ioVec, InEle);
            }
            WIZ_INLINE friend tThis& operator/=(tThisIO ioVec, tThisIn InVec)
            {
                return tMethod::DivideAssign(ioVec, InVec);
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
                return tThis(-x, -y);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis& operator=(tElementIn InEle)
            {
                x = InEle;
                y = InEle;

                return *this;
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Zero()
            {
                x = ::Wiz::Absolute::GetZero<tElement>();
                y = ::Wiz::Absolute::GetZero<tElement>();
            }
            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE ::Wiz::Void::Type Set(tElementIn InX, tElementIn InY)
            {
                this->x = InX;
                this->y = InY;
            }

            WIZ_INLINE ::Wiz::Void::Type Get(tElementOut outX, tElementOut outY)
            {
                outX = this->x;
                outY = this->y;
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
            WIZ_INLINE tElement GetNormal(tThisOut outVec) const
            {
                return tMethod::Normalize(outVec, *this);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tThis GetNormal() const
            {
                tThis lResult;
                tMethod::Normalize(lResult, *this);
                return lResult;
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrLen() const
            {
                return tMethod::SqrLen(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Length() const
            {
                return tMethod::Length(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement RecipLen() const
            {
                return tMethod::RecipLen(*this);
            }
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement Distance(tThisIn InVec) const
            {
                return tMethod::Distance(*this, InVec);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE tElement SqrDist(tThisIn InVec) const
            {
                return tMethod::SqrDist(*this, InVec);
            }
            ////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement Distance(tThisIn InVec1, tThisIn InVec2)
            {
                return tMethod::Distance(InVec1, InVec2);
            }
            ////////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////////
            WIZ_INLINE static tElement SqrDist(tThisIn InVec1, tThisIn InVec2)
            {
                return tMethod::SqrDist(InVec1, InVec2);
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
