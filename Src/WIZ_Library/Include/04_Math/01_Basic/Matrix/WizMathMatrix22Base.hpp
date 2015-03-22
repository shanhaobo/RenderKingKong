#ifndef __WIZ_MATH_ALGEBRA_MATRIX22_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX22_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix22
    {
        namespace RowMajor
        {
            namespace Base
            {
#       pragma pack(push, 1)
                template<typename ElementT>
                struct Type
                {
                    typedef ElementT                tElement;
                    ////////////////////////////////////////////////////////////////
                    enum
                    {
                        eRowCnt = 2,
                        eColCnt = 2,
                        eCount = eRowCnt * eColCnt,
                        eSize = sizeof(tElement) * eCount
                    };
                    ////////////////////////////////////////////////////////////////
                    typedef tElement                tElementArray[eCount];
                    ////////////////////////////////////////////////////////////////
                    union
                    {
                        ////////////////////////////////////////////////////////////
                        struct 
                        {
                            tElementArray           eAll;
                        };
                        ////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////
                        struct
                        {
                            tElement                e00, e01;
                            tElement                e10, e11;
                        };
                        struct
                        {
                            tElement                e[eColCnt][eRowCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        const tElement& E00, const tElement& E01,
                        const tElement& E10, const tElement& E11
                        )
                    {
                        this->e00 = E00; this->e01 = E01;
                        this->e10 = E10; this->e11 = E11;
                    }
                    Type(const tElement& InEle)
                    {
                        this->e00 = InEle; this->e01 = InEle;
                        this->e10 = InEle; this->e11 = InEle;
                    }
                    Type(const Type& InMat)
                    {
                        this->e00 = InMat.e00; this->e01 = InMat.e01;
                        this->e10 = InMat.e10; this->e11 = InMat.e11;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(::Wiz::Int::In Row, ::Wiz::Int::In Col)
                    {
                        return this->e[Col][Row];
                    }
                    template<::Wiz::Int::Type Row, ::Wiz::Int::Type Col>
                    tElement& GetElement()
                    {
                        return this->e[Col][Row];
                    }
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        OutX = this->GetElement(Row, 0);
                        OutY = this->GetElement(Row, 1);
                    }
                    ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        OutX = this->GetElement(0, Col);
                        OutY = this->GetElement(1, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = InX;
                        this->GetElement(Row, 1) = InY;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = InX;
                        this->GetElement(1, Col) = InY;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE ::Wiz::Size::TypeConst GetSizeInByte() const
                    {
                        return eSize;
                    }
                    WIZ_INLINE ::Wiz::Size::TypeConst GetElementCount() const
                    {
                        return eCount;
                    }
                    WIZ_INLINE tElement* GetElementPtr()
                    {
                        return this->e;
                    }
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
#       pragma pack(pop)
            } /// end of namespace Base
        } /// end of namespace RowMajor

        namespace ColMajor
        {
            namespace Base
            {
#       pragma pack(push, 1)
                template<typename ElementT>
                struct Type
                {
                    typedef ElementT                tElement;
                    ////////////////////////////////////////////////////////////////
                    enum
                    {
                        eRowCnt = 2,
                        eColCnt = 2,
                        eCount = eRowCnt * eColCnt,
                        eSize = sizeof(tElement) * eCount
                    };
                    ////////////////////////////////////////////////////////////////
                    typedef tElement                tElementArray[eCount];
                    ////////////////////////////////////////////////////////////////
                    union
                    {
                        ////////////////////////////////////////////////////////////
                        struct 
                        {
                            tElementArray           eAll;
                        };
                        ////////////////////////////////////////////////////////////

                        ////////////////////////////////////////////////////////////
                        struct
                        {
                            tElement                e00, e10;
                            tElement                e01, e11;
                        };
                        struct
                        {
                            tElement                e[eRowCnt][eColCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        const tElement& E00, const tElement& E10,
                        const tElement& E01, const tElement& E11
                        )
                    {
                        this->e00 = E00; this->e10 = E10;
                        this->e01 = E01; this->e11 = E11;
                    }
                    Type(const tElement& InEle)
                    {
                        this->e00 = InEle; this->e10 = InEle;
                        this->e01 = InEle; this->e11 = InEle;
                    }
                    Type(const Type& InMat)
                    {
                        this->e00 = InMat.e00; this->e10 = InMat.e10;
                        this->e01 = InMat.e01; this->e11 = InMat.e11;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(::Wiz::Int::In Row, ::Wiz::Int::In Col)
                    {
                        return this->e[Row][Col];
                    }
                    template<::Wiz::Int::Type Row, ::Wiz::Int::Type Col>
                    tElement& GetElement()
                    {
                        return this->e[Row][Col];
                    }
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        OutX = this->GetElement(Row, 0);
                        OutY = this->GetElement(Row, 1);
                    }
                    ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, ::Wiz::UInt::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        OutX = this->GetElement(0, Col);
                        OutY = this->GetElement(1, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = InX;
                        this->GetElement(Row, 1) = InY;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = InX;
                        this->GetElement(1, Col) = InY;
                    }
                    ////////////////////////////////////////////////////////////////
                    WIZ_INLINE ::Wiz::Size::TypeConst GetSizeInByte() const
                    {
                        return eSize;
                    }
                    WIZ_INLINE ::Wiz::Size::TypeConst GetElementCount() const
                    {
                        return eCount;
                    }
                    WIZ_INLINE tElement* GetElementPtr()
                    {
                        return this->e;
                    }
                    ////////////////////////////////////////////////////////////////
                }; /// end of struct Type
#       pragma pack(pop)
            } /// end of namespace Base
        } /// end of namespace ColMajor
    } /// end of namespace Matrix22
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX22_BASE_HPP__SHANHAOBO_19800429__*/
