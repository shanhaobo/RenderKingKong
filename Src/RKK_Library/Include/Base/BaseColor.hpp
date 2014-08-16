#ifndef __RENDERKINGKONG_COLOR_HPP__SHANHAOBO_19800429__
#define __RENDERKINGKONG_COLOR_HPP__SHANHAOBO_19800429__

#include "BaseColorU32.hpp"

namespace rkk
{
    //////////////////////////////////////////////////////////////////////////
    namespace Color
    {
        RKK_CLASS
        {
        public:
            F32::type r, g, b, a;
        public:
            type();
            type(
                F32::in red,
                F32::in green,
                F32::in blue,
                F32::in alpha = 1
                );
            //////////////////////////////////////////////////////////////////////////
        public:
            Void::type Saturate();
        public:
            Void::type From(
                U8::in    red,
                U8::in    green,
                U8::in    blue,
                U8::in    alpha
                );
            Void::type FromRGBA(U32::in color);
            Void::type FromARGB(U32::in color);
            Void::type FromABGR(U32::in color);
            Void::type FromBGRA(U32::in color);

            ////////////////////////////////////////////////////////////////////
            /// TO
            Void::type To(
                U8::out    red,
                U8::out    green,
                U8::out    blue,
                U8::out    alpha
                ) const;
            U32::type ToRGBA() const;
            U32::type ToARGB() const;
            U32::type ToABGR() const;
            U32::type ToBGRA() const;

            //////////////////////////////////////////////////////////////////////////

            friend WIZ_INLINE ref operator+= (out Out1, in In2)
            {
                Out1.r += In2.r; 
                Out1.g += In2.g; 
                Out1.b += In2.b; 
                Out1.a += In2.a; 
                Out1.Saturate();
                return Out1;
            }
            friend WIZ_INLINE ref operator-= (out Out1, in In2)
            {
                Out1.r -= In2.r; 
                Out1.g -= In2.g; 
                Out1.b -= In2.b; 
                Out1.a -= In2.a; 
                Out1.Saturate();
                return Out1;
            }
            friend WIZ_INLINE ref operator*= (out Out1, F32::in InT)
            {
                Out1.r *= InT; 
                Out1.g *= InT; 
                Out1.b *= InT; 
                Out1.a *= InT; 
                Out1.Saturate();
                return Out1;
            }

            friend WIZ_INLINE type operator+ (in In1, in In2)
            {
                type Temp = In1;
                return Temp += In2;
            }
            friend WIZ_INLINE type operator- (in In1, in In2)
            {
                type Temp = In1;
                return Temp -= In2;
            }
            friend WIZ_INLINE type operator* (in In1, F32::in InT)
            {
                type Temp = In1;
                return Temp *= InT;
            }

            WIZ_INLINE ref operator+()
            {
                return *this;
            }

            WIZ_INLINE refc operator+() const
            {
                return *this;
            }

            WIZ_INLINE type operator-() const
            {
                type Temp(-r, -g, -b, -a);
                return Temp;
            }

            WIZ_INLINE Bool::type operator== (in In1) const
            {
                return (r == In1.r) && (g == In1.g) && (b == In1.b) && (a == In1.a);
            }
            WIZ_INLINE Bool::type operator!= (in In1) const
            {
                return !operator==(In1);
            }
        };

        static const type Zero  = type(0, 0, 0, 0);
        static const type Black = type(0, 0, 0);
        static const type White = type(1, 1, 1);
        static const type Red   = type(1, 0, 0);
        static const type Green = type(0, 1, 0);
        static const type Blue  = type(0, 0, 1);
    } /// end of namespace color
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace rkk

#endif /*__RENDERKINGKONG_COLOR_HPP__SHANHAOBO_19800429__*/
