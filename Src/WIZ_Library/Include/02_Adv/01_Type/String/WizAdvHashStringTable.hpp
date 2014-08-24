#ifndef __WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__

#include "../Container/WizAdvContainer.hpp"

#include "./WizAdvFixedString.hpp"
#include "./WizAdvHashStringProxy.hpp"

namespace Wiz
{
    namespace HashString
    {
        namespace Table
        {
            /// Reserved[0, ReservedNumT)
            /// NonReserved[ReservedNumT, Max)
            template<class ProxyT, int TotalNumT, int ReservedNumT, class AllocatorT>
            struct Type
            {
            public:
                typedef ProxyT                                                      tProxy;
                typedef typename tProxy::tString                                    tString;
                typedef typename tProxy::tIndex                                     tIndex;

            private:

                typedef typename Type<ProxyT, TotalNumT, ReservedNumT, AllocatorT>  tThis;

                typedef const tIndex                                                tIndexConst;
                typedef tIndex &                                                    tIndexOut;

                typedef Array::Type<tIndexConst, AllocatorT>                        tIndexArray;

            private:
                typedef tString const                                               tStringConst;
                typedef tString&                                                    tStringRef;
                typedef tStringConst&                                               tStringRefConst;
                typedef tString*                                                    tStringPtr;
                typedef tStringConst*                                               tStringPtrConst;

                typedef Array::Type<tString, AllocatorT>                            tStringArray;

            public:
                enum
                {
                    eTotalCapacity = TotalNumT,
                    eReservedNum = ReservedNumT,
                    eNonReservedIndex = ReservedNumT,
                    eInvalidHashCode = eTotalCapacity,
                };

                WIZ_DECLARE_IN_STDCLASS(tThis);

            public:
                tIndex AddString(tStringRefConst InStr, tIndex InReservedIndex = eNonReservedIndex)
                {
                    tIndexConst HashCode = CalcHashCode(InStr);

                    tIndex FndIndex;

                    if (FindString(InStr, HashCode, FndIndex))
                    {
                        return FndIndex;
                    }

                    if (InReservedIndex < eReservedNum)
                    {
                        if (AddReserved(InStr, HashCode, InReservedIndex))
                        {
                            return InReservedIndex;
                        }

                        /// Conflict
                        return ::std::numeric_limits<tIndex>::(max)();
                    }

                    return AddNonReserved(InStr, HashCode);
                }

                Bool::Type FindString(tStringRefConst InStr, tIndexOut OutIdx)
                {
                    tIndexConst HashCode = CalcHashCode(InStr);

                    if (FindString(InStr, HashCode, OutIdx))
                    {
                        return Bool::True;
                    }

                    return Bool::False;
                }


                Bool::Type TestString(tStringRefConst InStr)
                {
                    tIndex DummyIdx;

                    return TestString(InStr, DummyIdx);
                }

            public:
                tStringPtrConst GetStringPtr(tIndex InIdx) const
                {
                    if (InIdx < eReservedNum)
                    {
                        return &(m_ReservedStringTab[InIdx]);
                    }
                    else if (IsValidIndex(InIdx))
                    {
                        return &(m_StringArray[InIdx]);
                    }

                    return WIZ_NULL;
                }

            public:
                ::Wiz::Bool::Type IsValidIndex(tIndex InIdx) const
                {
                    const tIndex StrArrayLen = m_StringArray.Size();
                    return InIdx < (StrArrayLen + eReservedNum);
                }

            private:
                ::Wiz::Bool::Type IsValidHashCode(tIndex InHashCode) const
                {
                    return (InHashCode >= 0) && (InHashCode < eTotalCapacity);
                }

                tIndexConst CalcHashCode(tStringRefConst InStr) const
                {
                    const tIndex iHashCode = tProxy::CalcHashCode(InStr) % eTotalCapacity;
                    return iHashCode;
                }

            private:

                Bool::Type FindString(tStringRefConst InStr, tIndex InHashCode, tIndexOut OutIndex)
                {
                    WIZ_ASSERT(IsValidHashCode(InHashCode));

                    tIndexArray&                    HashIndexArray = m_HashTab[InHashCode];

                    tIndexArray::tIterator          Itr = HashIndexArray.Begin();
                    tIndexArray::tIteratorConst     ItrEnd = HashIndexArray.End();
                    for (; Itr != ItrEnd; ++Itr)
                    {
                        tIndex const StrIdx = *Itr;

                        if ((StrIdx < eReservedNum) && (InStr == m_ReservedStringTab[StrIdx]))
                        {
                            OutIndex = StrIdx;
                            return Bool::True;
                        }
                        else if (InStr == m_StringArray[StrIdx])
                        {
                            OutIndex = StrIdx;
                            return Bool::True;
                        }
                    }

                    return Bool::False;
                }

                Bool::Type AddReserved(tStringRefConst InStr, tIndex InHashCode, tIndex InReservedIndex)
                {
                    WIZ_ASSERT(IsValidHashCode(InHashCode) && (InReservedIndex < eReservedNum));

                    if (m_ReservedStringTab[InReservedIndex].Size() > 0)
                    {
                        /// Conflict
                        return Bool::False;
                    }

                    m_ReservedStringTab[InReservedIndex] = InStr;

                    m_HashTab[InHashCode].PushBack(InReservedIndex);

                    return Bool::True;
                }

                tIndexConst AddNonReserved(tStringRefConst InStr, tIndex InHashCode)
                {
                    WIZ_ASSERT(IsValidHashCode(InHashCode));

                    tIndex const ResultIdx = m_StringArray.Size() + eReservedNum;
                    m_StringArray.PushBack(InStr);
                    m_HashTab[InHashCode].PushBack(ResultIdx);

                    return ResultIdx;
                }

            private:
                /// m_HashTab可以通过字符串找到索引, 
                tIndexArray         m_HashTab[eTotalCapacity];
                /// m_StringArray可以通过索引立即找到字符串
                tString             m_ReservedStringTab[eReservedNum];

                tStringArray        m_StringArray;
            };
        } /// end of namespace Table
    } /// end of namespace HashString
} /// end of namespace Wiz

#endif /*__WIZ_ADV_HASHSTRINGTABLE_HPP__SHANHAOBO_19800429__*/
