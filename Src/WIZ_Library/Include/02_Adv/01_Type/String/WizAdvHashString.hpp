#ifndef __WIZ_ADV_HASHSTRING_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_HASHSTRING_HPP__SHANHAOBO_19800429__

#include "./WizAdvHashStringTable.hpp"
#include "./WizAdvHashStringProxy.hpp"

namespace Wiz
{
    namespace HashString
    {
        /// Reserved[0, ReservedNumT)
        /// NonReserved[ReservedNumT, Max)
        template< class StringT, Proxy::Category::Type CatT = Proxy::Category::eSDBM, bool CaseSensitiveT = true, int MaxIterationsT = 128, int TotalNumT = 65536, int ReservedNumT = 1024, class AllocatorT = ::std::allocator<StringT::tChar> >
        class Type
        {
        public:
            typedef typename StringT                                                        tString;
            typedef typename tString::tChar                                                 tChar;

            typedef Proxy::Type<tChar, CatT, CaseSensitiveT, MaxIterationsT>                tProxy;
            typedef typename tProxy::tIndex                                                 tIndex;

            typedef tIndex const                                                            tIndexConst;
            typedef tIndex &                                                                tIndexOut;

        private:
            typedef tString const                                                           tStringConst;
            typedef tString&                                                                tStringRef;
            typedef tStringConst&                                                           tStringRefConst;
            typedef tString*                                                                tStringPtr;
            typedef tStringConst*                                                           tStringPtrConst;

            typedef HashString::Table::Type<tProxy, TotalNumT, ReservedNumT, AllocatorT>    tHashTab;

            typedef Type<StringT, CatT, CaseSensitiveT, MaxIterationsT, TotalNumT, ReservedNumT, AllocatorT>    tThis;

            typedef tThis const &                                                           tThisIn;

        public:
            enum
            {
                eTotalCapacity      = TotalNumT,
                eReservedNum        = ReservedNumT,
                eNonReservedIndex   = ReservedNumT,
                eInvalidHashCode    = eTotalCapacity,
            };

        public:
            Type() : m_Index(::std::numeric_limits<tIndex>::(max)())
            {
            }
            explicit Type(tStringRefConst Str)
            {
                Set(Str);
            }
            explicit Type(tIndex InIdx)
            {
                if (GetHashTab().IsValidIndex(InIdx))
                {
                    m_Index = InIdx;
                }
                else
                {
                    m_Index = ::std::numeric_limits<tIndex>::(max)();
                }
            }
            Type(tThisIn Nm) : m_Index(Nm.m_Index)
            {
            }
        public:
            Void::Type Set(tStringRefConst InStr, tIndexConst InReservedIndex = eReservedNum)
            {
                m_Index = GetHashTab().AddString(InStr);
            }
        public:
            Bool::Type IsValid() const
            {
                return GetHashTab().IsValidIndex(m_Index);
            }
            Bool::Type NotValid() const
            {
                return GetHashTab().IsValidIndex(m_Index) == Bool::False;
            }
        public:
            friend Bool::Type operator==(tThisIn A, tThisIn B)
            {
                return A.m_Index == B.m_Index;
            }
            friend Bool::Type operator==(tThisIn A, tIndex B)
            {
                return A.m_Index == B;
            }
            friend Bool::Type operator==(tThisIn A, tStringRefConst B)
            {
                tStringPtrConst StrPtr = GetStringPtr(A.m_Index);
                if (IsValidPtr(StrPtr))
                {
                    return *StrPtr == B;
                }
                return false;
            }
        public:
            friend Bool::Type operator<(tThisIn A, tThisIn B)
            {
                return A.m_Index < B.m_Index;
            }
            friend Bool::Type operator<(tThisIn A, tIndex B)
            {
                return A.m_Index < B;
            }
            friend Bool::Type operator<(tThisIn A, tStringRefConst B)
            {
                tStringPtrConst StrPtr = GetStringPtr(A.m_Index);
                if (IsValidPtr(StrPtr))
                {
                    return *StrPtr < B;
                }
                return false;
            }
        public:
            Bool::Type GetStr(tStringRef OutStr) const
            {
                return GetString(OutStr, m_Index);
            }
        protected:
            static tHashTab& GetHashTab()
            {
                static tHashTab s_HashTab;
                return s_HashTab;
            }
            static WIZ_INLINE tStringPtrConst GetStringPtr(tIndex InIdx)
            {
                return GetHashTab().GetStringPtr(InIdx);
            }
            static WIZ_INLINE Bool::Type GetString(tStringRef OutStr, tIndex InIdx)
            {
                tStringPtrConst StrPtr = GetStringPtr(InIdx);
                if (IsValidPtr(StrPtr))
                {
                    OutStr = *StrPtr;
                    return Bool::True;
                }

                return Bool::False;
            }
        };
    } /// end of namespace HashString
} /// end of namespace Wiz

#endif /*__WIZ_ADV_HASHSTRING_HPP__SHANHAOBO_19800429__*/
