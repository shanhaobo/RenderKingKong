#ifndef __WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__

#include "./WizBasicTypeDeclareUtils.hpp"

#include <string>

namespace Wiz
{
    namespace Std
    {
        namespace String
        {
            typedef ::std::string                                       Type;

            namespace Char
            {
                typedef String::Type::value_type                        Type;

                namespace Traits
                {
                    typedef String::Type::traits_type                   Type;
                } /// end of namespace Traits
            } /// end of namespace Char

            namespace Allocator
            {
                typedef String::Type::allocator_type                    Type;
            } /// end of namespace Allocator

            namespace Stream
            {
                typedef ::std::basic_stringstream<String::Char::Type, String::Char::Traits::Type, String::Allocator::Type> Type;
            } /// end of namespace      Stream;
        } /// end of namespace String

        namespace WString
        {
            typedef ::std::wstring                                      Type;

            namespace Char
            {
                typedef WString::Type::value_type                       Type;

                namespace Traits
                {
                    typedef WString::Type::traits_type                  Type;
                } /// end of namespace Traits
            } /// end of namespace Char

            namespace Allocator
            {
                typedef WString::Type::allocator_type                   Type;
            } /// end of namespace Allocator

            namespace Stream
            {
                typedef ::std::basic_stringstream<WString::Char::Type, WString::Char::Traits::Type, WString::Allocator::Type> Type;
            } /// end of namespace      Stream;
        } /// end of namespace WString
    } /// end of namespace Std

    //////////////////////////////////////////////////////////////////////////////////

    template< class CharT, class TraitsT = ::std::char_traits<CharT>, class AllocatorT = ::std::allocator<CharT> >
    class TString : public ::std::basic_string<CharT, TraitsT, AllocatorT>
    {
    protected:
        typedef typename TString<CharT, TraitsT, AllocatorT>                    tThis;

        typedef typename tThis &                                                tThisRef;
        typedef typename tThis const &                                          tThisConstRef;

        typedef typename tThis const &                                          tThisIn;
        typedef typename tThis &                                                tThisOut;

        typedef typename ::std::basic_string<CharT, TraitsT, AllocatorT>        tSuper;

        typedef typename tSuper const &                                         tSuperIn;
        typedef typename tSuper const &                                         tSuperConstRef;

    public:
        //////////////////////////////////////////////////////////////////////////

        typedef typename tSuper::traits_type                                    tTraits;
        typedef typename tSuper::allocator_type                                 tAllocator;
        typedef typename tSuper::value_type                                     tChar;

        typedef typename tSuper::iterator                                       tIterator;
        typedef typename tSuper::const_iterator                                 tIteratorConst;

        typedef tChar const * const                                             tCharPtrFixedConst;
        typedef tChar const *                                                   tCharPtrConst;
        typedef tChar *                                                         tCharPtr;

        typedef tChar const * const                                             tStrFixedConst;
        typedef tChar const *                                                   tStrConst;
        typedef tChar *                                                         tStr;

        typedef typename tSuper::size_type                                      tSize;

        WIZ_DECLARE(tThis);

    public:
        //////////////////////////////////////////////////////////////////////////
        TString() : tSuper()
        {
        }

        TString(tCharPtrConst InPtr) : tSuper(InPtr)
        {
        }

        TString(tSuperIn InSuper) : tSuper(InSuper)
        {
        }

        TString(tThisIn InThis) : tSuper(InThis)
        {
        }

        TString(tThisIn InThis, tSize InOffSZ, tSize InCnt = npos) : tSuper(InThis, InOffSZ, InCnt)
        {
        }

        TString(tCharPtrConst InPtr, tSize InCnt) : tSuper(InPtr, InCnt)
        {
        }

        template<class ItrT>
        TString(ItrT InFirst, ItrT InLast) : tSuper(InFirst, InLast)
        {
        }

    public:
        //////////////////////////////////////////////////////////////////////////
        Bool::Type operator==(tThisIn InOther) const
        {
            return tSuper::compare(InOther) == 0;
        }

        Bool::Type operator!=(tThisIn InOther) const
        {
            return tSuper::compare(InOther) != 0;
        }

        Bool::Type operator==(tCharPtrConst InPtr) const
        {
            return tSuper::compare(InPtr) == 0;
        }

        Bool::Type operator!=(tCharPtrConst InPtr) const
        {
            return tSuper::compare(InPtr) != 0;
        }

        /// operator=
        tThisRef operator=(tCharPtrConst InPtr)
        {
            tSuper::operator=(InPtr);
            return *this;
        }
        tThisRef operator=(tThisIn InOther)
        {
            tSuper::operator=(InOther);
            return *this;
        }
        tThisRef operator=(tSuperIn InOther)
        {
            tSuper::operator=(InOther);
            return *this;
        }

        /// operator+=
        tThisRef operator+=(tCharPtrConst InPtr)
        {
            tSuper::operator+=(InPtr);
            return *this;
        }
        tThisRef operator+=(tChar const InCh)
        {
            tSuper::operator+=(InCh);
            return *this;
        }
        tThisRef operator+=(tThisIn InOther)
        {
            tSuper::operator+=(InOther);
            return *this;
        }

        /// operator+
        tThis operator+(tCharPtrConst InPtr)
        {
            tThis TmpStr = *this;
            return (TmpStr += InPtr);
        }
        tThis operator+(tThisIn InOther)
        {
            tThis TmpStr = *this;
            return (TmpStr += InOther);
        }

    public:
        //////////////////////////////////////////////////////////////////////////
        Void::Type Resize(tSize InNewSize)
        {
            tSuper::resize(InNewSize);
        }

        tSize Size() const
        {
            return stSuper::size();
        }

        tSize Capacity() const
        {
            return tSuper::capacity();
        }

        Bool::Type IsEmpty() const
        {
            return tSuper::empty();
        }

        Void::Type Clear()
        {
            tSuper::clear();
        }

        WIZ_INLINE static Bool::Type IsValidPos(tSize InNewSize)
        {
            return InNewSize == tSuper::npos;
        }
    public:
        //////////////////////////////////////////////////////////////////////////
        WIZ_INLINE tCharPtrConst GetBufferConst() const
        {
            return tSuper::c_str();
        }

        WIZ_INLINE tCharPtr GetBuffer() const
        {
            return const_cast<tCharPtr>(GetBufferConst());
        }

    public:
        operator tCharPtrConst() const
        {
            return GetBufferConst();
        }

    public:
        //////////////////////////////////////////////////////////////////////////
        tSize Find(tChar C, tSize Offset = 0) const
        {
            return tSuper::find(C, Offset);
        }
        tSize Find(tStrConst SubStrPtr, tSize Offset = 0) const
        {
            return tSuper::find(SubStrPtr, Offset);
        }

        /// [OffBegin, OffEnd)
        tSize Find(tChar C, tSize OffBegin, tSize OffEnd = 0) const
        {
            tStrFixedConst  StrBeginPtr = tSuper::c_str();
            tStrConst       CurrPtr     = StrBeginPtr + OffBegin;
            tStrFixedConst  EndPtr      = StrBeginPtr + (OffEnd == 0 ? Size() : OffEnd);
            for (; CurrPtr < EndPtr; CurrPtr++)
            {
                if (*CurrPtr == C)
                {
                    return CurrPtr - StrBeginPtr;
                }
            }

            return tSuper::npos;
        }

        /// [OffBegin, OffEnd)
        tSize Find(tStrConst, tSize SubLen, tSize OffBegin, tSize OffEnd = 0) const
        {
            tStrFixedConst StrBeginPtr = tSuper::c_str();

            tStrConst CurrPtr = StrBeginPtr + OffBegin;

            tStrFixedConst EndPtr = StrBeginPtr + (OffEnd == 0 ? Size() : OffEnd);
            for (; CurrPtr < EndPtr; CurrPtr++)
            {
                if (::memcmp(CurrPtr, SubStrPtr, SubLen) == 0)
                {
                    return CurrPtr - StrBeginPtr;
                }
            }

            return tSuper::npos;
        }

    public:
        //////////////////////////////////////////////////////////////////////////
        /// [OffBegin, OffEnd)
        I::Type FindCount(tChar C, tSize OffBegin = 0, tSize OffEnd = 0) const
        {
            tSize Temp(OffBegin);
            I::Type Cnt = -1;
            do
            {
                Temp = Find(C, Temp, OffEnd);
                Cnt++;
            } while (Temp != tSuper::npos);

            return Cnt;
        }

        /// [OffBegin, OffEnd)
        I::Type FindCount(tCharPtrConst SubStrPtr, tSize SubLen, tSize OffBegin = 0, tSize OffEnd = 0) const
        {
            tSize Temp(OffBegin);
            I::Type Cnt = -1;
            do
            {
                Temp = Find(SubStrPtr, SubLen, Temp + SubLen, OffEnd);
                Cnt++;
            } while (Temp != tSuper::npos);

            return Cnt;
        }

    public:
        //////////////////////////////////////////////////////////////////////////
        typedef typename std::basic_string<tChar, std::char_traits<tChar>, std::allocator<tChar> >  tStdString;
        typedef tStdString const &                                                                  tStdStringIn;

        WIZ_INLINE friend Bool::Type operator <(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
        }
        WIZ_INLINE friend Bool::Type operator <(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) < 0;
        }
        WIZ_INLINE friend Bool::Type operator <=(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
        }
        WIZ_INLINE friend Bool::Type operator <=(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) <= 0;
        }
        WIZ_INLINE friend Bool::Type operator >(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
        }
        WIZ_INLINE friend Bool::Type operator >(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) > 0;
        }
        WIZ_INLINE friend Bool::Type operator >=(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
        }
        WIZ_INLINE friend Bool::Type operator >=(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) >= 0;
        }

        WIZ_INLINE friend Bool::Type operator ==(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
        }
        WIZ_INLINE friend Bool::Type operator ==(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) == 0;
        }

        WIZ_INLINE friend Bool::Type operator !=(tThisIn l, tStdStringIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
        }
        WIZ_INLINE friend Bool::Type operator !=(tStdStringIn l, tThisIn o)
        {
            return l.compare(0, l.length(), o.c_str(), o.length()) != 0;
        }

        WIZ_INLINE friend tThis operator +=(tThisIn l, tStdStringIn o)
        {
            return tThis(l) += o.c_str();
        }
        WIZ_INLINE friend tThis operator +=(tStdStringIn l, tThisIn o)
        {
            return tThis(l.c_str()) += o.c_str();
        }

        WIZ_INLINE friend tThis operator +(tThisIn l, tStdStringIn o)
        {
            return tThis(l) += o.c_str();
        }
        WIZ_INLINE friend tThis operator +(tStdStringIn l, tThisIn o)
        {
            return tThis(l.c_str()) += o.c_str();
        }

        template<typename T>
        WIZ_INLINE friend tThis operator +(const T* l, tThisIn o)
        {
            return tThis(l) += o;
        }

    }; /// end of namespace TString

    //////////////////////////////////////////////////////////////////////////////////

} /// end of namespace Wiz

#endif /*__WIZ_BASIC_TYPE_STRING_HPP__SHANHAOBO_19800429__*/
