#ifndef __WIZ_MATH_ALGEBRA_MATRIX33_BASE_HPP__SHANHAOBO_19800429__
#define __WIZ_MATH_ALGEBRA_MATRIX33_BASE_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    //////////////////////////////////////////////////////////////////////////
    namespace Matrix33
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
                        eRowCnt = 3,
                        eColCnt = 3,
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
                            tElement                e00, e01, e02;
                            tElement                e10, e11, e12;
                            tElement                e20, e21, e22;
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
                        const tElement& E00, const tElement& E01, const tElement& E02,
                        const tElement& E10, const tElement& E11, const tElement& E12,
                        const tElement& E20, const tElement& E21, const tElement& E22
                        )
                    {
                        this->e00 = E00; this->e01 = E01; this->e02 = E02; 
                        this->e10 = E10; this->e11 = E11; this->e12 = E12;
                        this->e20 = E20; this->e21 = E21; this->e22 = E22;
                    }
                    Type(const tElement& InEle)
                    {
                        this->e00 = InEle; this->e01 = InEle; this->e02 = InEle;
                        this->e10 = InEle; this->e11 = InEle; this->e12 = InEle;
                        this->e20 = InEle; this->e21 = InEle; this->e22 = InEle;
                    }
                    Type(const Type& InMat)
                    {
                        this->e00 = InMat.e00; this->e01 = InMat.e01; this->e02 = InMat.e02;
                        this->e10 = InMat.e10; this->e11 = InMat.e11; this->e12 = InMat.e12;
                        this->e20 = InMat.e20; this->e21 = InMat.e21; this->e22 = InMat.e22;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(::Wiz::Int::In Row, ::Wiz::Int::In Col)
                    {
                        return this->e[Row][Col];
                    }
                    template<::Wiz::Int::In Row, ::Wiz::Int::In Col>
                    tElement& GetElement()
                    {
                        return this->e[Row][Col];
                    }
                    ////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        OutX = this->GetElement(Row, 0);
                        OutY = this->GetElement(Row, 1);
                        OutZ = this->GetElement(Row, 2);
                    }
                    ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        OutX = this->GetElement(0, Col);
                        OutY = this->GetElement(1, Col);
                        OutZ = this->GetElement(2, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY, const tElement& InZ)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = InX;
                        this->GetElement(Row, 1) = InY;
                        this->GetElement(Row, 2) = InZ;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY, const tElement& InZ)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = InX;
                        this->GetElement(1, Col) = InY;
                        this->GetElement(2, Col) = InZ;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    template<class Matrix22T, ::Wiz::Int::Type rj, ::Wiz::Int::Type ri>
                    WIZ_INLINE Matrix22T& GetCofactor(Matrix22T& OutMat) const
                    {
                        ::Wiz::Size::Type i, j, ci, cj;
                        for (j = 0, cj = 0; j < eRowCnt; j++)
                        {
                            if (j != rj)
                            {
                                for (i = 0, ci = 0; i < eColCnt; i++)
                                {
                                    if (i != ri)
                                    {
                                        OutMat.GetElement(cj, ci) = this->GetElement(j, i);
                                        ci++;
                                    }
                                }
                                cj++;
                            }
                        }

                        return OutMat;
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
                        eRowCnt = 3,
                        eColCnt = 3,
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
                            tElement                e00, e10, e20;
                            tElement                e01, e11, e21;
                            tElement                e02, e12, e22;
                        };
                        struct
                        {
                            tElement                e[eColCnt][eRowCnt];
                        };
                        ////////////////////////////////////////////////////////////
                    };
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    Type()
                    {}
                    Type(
                        const tElement& E00, const tElement& E10, const tElement& E20,
                        const tElement& E01, const tElement& E11, const tElement& E21,
                        const tElement& E02, const tElement& E12, const tElement& E22
                        )
                    {
                        this->e00 = E00; this->e10 = E10; this->e20 = E20;
                        this->e01 = E01; this->e11 = E11; this->e21 = E21;
                        this->e02 = E02; this->e12 = E12; this->e22 = E22;
                    }
                    Type(const tElement& InEle)
                    {
                        this->e00 = InEle; this->e10 = InEle; this->e20 = InEle;
                        this->e01 = InEle; this->e11 = InEle; this->e21 = InEle;
                        this->e02 = InEle; this->e12 = InEle; this->e22 = InEle;
                    }
                    Type(const Type& InMat)
                    {
                        this->e00 = InMat.e00; this->e10 = InMat.e10; this->e20 = InMat.e20;
                        this->e01 = InMat.e01; this->e11 = InMat.e11; this->e21 = InMat.e21;
                        this->e02 = InMat.e02; this->e12 = InMat.e12; this->e22 = InMat.e22;
                    }
                    ////////////////////////////////////////////////////////////////
                    tElement& GetElement(::Wiz::Int::In Row, ::Wiz::Int::In Col)
                    {
                        return this->e[Col][Row];
                    }
                    template<::Wiz::Int::In Row, ::Wiz::Int::In Col>
                    tElement& GetElement()
                    {
                        return this->e[Col][Row];
                    }
                    ////////////////////////////////////////////////////////////////

                    ////////////////////////////////////////////////////////////////
                    ::Wiz::Void::Type GetRow(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Row)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        OutX = this->GetElement(Row, 0);
                        OutY = this->GetElement(Row, 1);
                        OutZ = this->GetElement(Row, 2);
                    }
                    ::Wiz::Void::Type GetCol(tElement& OutX, tElement& OutY, tElement& OutZ, ::Wiz::UInt::In Col)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        OutX = this->GetElement(0, Col);
                        OutY = this->GetElement(1, Col);
                        OutZ = this->GetElement(2, Col);
                    }

                    ::Wiz::Void::Type SetRow(::Wiz::UInt::In Row, const tElement& InX, const tElement& InY, const tElement& InZ)
                    {
                        WIZ_ASSERT(Row < eRowCnt);
                        this->GetElement(Row, 0) = InX;
                        this->GetElement(Row, 1) = InY;
                        this->GetElement(Row, 2) = InZ;
                    }
                    ::Wiz::Void::Type SetCol(::Wiz::UInt::In Col, const tElement& InX, const tElement& InY, const tElement& InZ)
                    {
                        WIZ_ASSERT(Col < eColCnt);
                        this->GetElement(0, Col) = InX;
                        this->GetElement(1, Col) = InY;
                        this->GetElement(2, Col) = InZ;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    template<class Matrix22T, ::Wiz::Int::Type rj, ::Wiz::Int::Type ri>
                    WIZ_INLINE Matrix22T& GetCofactor(Matrix22T& OutMat)
                    {
                        ::Wiz::Size::Type i, j, ci, cj;
                        for (i = 0, ci = 0; i < eColCnt; i++)
                        {
                            if (i != ri)
                            {
                                for (j = 0, cj = 0; j < eRowCnt; j++)
                                {
                                    if (j != rj)
                                    {
                                        OutMat.GetElement(cj, ci) = this->GetElement(j, i);
                                        cj++;
                                    }
                                }
                                ci++;
                            }
                        }

                        return OutMat;
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
    } /// end of namespace Matrix33
    //////////////////////////////////////////////////////////////////////////
} /// end of namespace Wiz

#endif /*__WIZ_MATH_ALGEBRA_MATRIX33_BASE_HPP__SHANHAOBO_19800429__*/
