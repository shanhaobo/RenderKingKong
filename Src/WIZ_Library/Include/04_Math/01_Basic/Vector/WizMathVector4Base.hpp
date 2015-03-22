#ifndef __WIZ_MATH_VECTOR4_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_VECTOR4_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    namespace Vector4
    {
        namespace Base
        {
#       pragma pack(push, 1)
            template<typename ElementT>
            struct Type
            {
                ////////////////////////////////////////////////////////////////

                typedef ElementT            tElement;

                typedef tElement const &    tElementIn;
                typedef tElement &          tElementOut;
                typedef tElementOut         tElementIO;

                typedef Type<tElement>      tThis;
                typedef tThis const &       tThisIn;
                typedef tThis &             tThisOut;

                ////////////////////////////////////////////////////////////////
                enum
                {
                    eCount = 4,
                    eSize = sizeof(tElement) * eCount,
                };
                ////////////////////////////////////////////////////////////////
                typedef tElement            tElementArray[eCount];
                ////////////////////////////////////////////////////////////////
                union
                {
                    struct
                    {
                        tElement              x, y, z, w;
                    };
                    struct
                    {
                        tElement              X, Y, Z, W;
                    };
                    struct
                    {
                        tElement              e0, e1, e2, e3;
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
                Type(tElementIn InX, tElementIn InY, tElementIn InZ, tElementIn InW)
                {
                    this->x = InX;
                    this->y = InY;
                    this->z = InZ;
                    this->w = InW;
                }
                Type(tElementIn InEle) 
                {
                    this->x = InEle;
                    this->y = InEle;
                    this->z = InEle;
                    this->w = InEle;
                }
                Type(tThisIn InOther)
                {
                    this->x = InOther.x;
                    this->y = InOther.y;
                    this->z = InOther.z;
                    this->w = InOther.w;
                }
                ////////////////////////////////////////////////////////////////
                WIZ_INLINE ::Wiz::Size::TypeC GetSizeInByte() const
                {
                    return eSize;
                }
                WIZ_INLINE ::Wiz::Size::TypeC GetElementCount() const
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
    } /// end of namespace Vector4
} /// end of namespace Wiz

#endif /*__WIZ_MATH_VECTOR4_BASE_HPP__SHANHAOBO_19800429__*/
