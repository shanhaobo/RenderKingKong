#ifndef __WIZ_MATH_ALGEBRA_VECTOR2_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_VECTOR2_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    namespace Vector2
    {
        namespace Base
        {
#       pragma pack(push, 1)
            template<typename ElementT>
            struct WIZ_EXPORT Type
            {
                typedef ElementT            tElement;
                ////////////////////////////////////////////////////////////////
                enum
                {
                    eCount = 2,
                    eSize = sizeof(tElement) * eCount,
                };
                ////////////////////////////////////////////////////////////////

                typedef tElement            tElementArray[eCount];
                ////////////////////////////////////////////////////////////////
                union
                {
                    struct
                    {
                        tElement              x, y;
                    };
                    struct
                    {
                        tElement              X, Y;
                    };
                    struct
                    {
                        tElement              e0, e1;
                    };
                    struct
                    {

                        tElement              e[eCount];
                    };
                    struct
                    {
                        tElementArray         v;
                    };
                };
                ////////////////////////////////////////////////////////////////

                Type()
                {}
                Type(const tElement& InX, const tElement& InY)
                {
                    this->x = InX;
                    this->y = InY;
                }
                Type(const tElement& InEle) 
                {
                    this->x = InEle;
                    this->y = InEle;
                }
                Type(Type const& InOther)
                {
                    this->x = InOther.x;
                    this->y = InOther.y;
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::SZ::TypeC GetSizeInByte() const
                {
                    return eSize;
                }
                WIZ_INLINE ::Wiz::SZ::TypeC GetElementCount() const
                {
                    return eCount;
                }
                WIZ_INLINE tElement* GetElementPtr()
                {
                    return this->e;
                }
                ////////////////////////////////////////////////////////////////
            };
#       pragma pack(pop)
        } /// end of namespace Base
    } /// end of namespace Vector2
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_VECTOR2_BASE_HPP__SHANHAOBO_19800429__*/
