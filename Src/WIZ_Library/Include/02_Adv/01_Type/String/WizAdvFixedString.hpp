#ifndef __WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

namespace Wiz
{
    template< typename CharT, class TraitsT = ::std::char_traits<CharT>, class AllocatorT = ::std::allocator<CharT> >
    class FixedString : private ::Wiz::String<CharT, TraitsT, AllocatorT>::Type
    {
    protected:
        typedef FixedString<CharT, TraitsT, AllocatorT>             tThis;

        typedef ::Wiz::String<CharT, TraitsT, AllocatorT>::Type    tSuper;

    public:
        WIZ_DECLARE(tThis);

    public:
        //////////////////////////////////////////////////////////////////////////
        FixedString() : tSuper()
        {
        }

        FixedString(tThisIn InThis) : tSuper(InThis)
        {
        }

        FixedString(tStdStringIn InStd) : tSuper(InStd)
        {
        }

        FixedString(tCharPtrConst InPtr) : tSuper(InPtr)
        {
        }

        FixedString(tCharPtrConst InPtr, tSize InCnt) : tSuper(InPtr, InCnt)
        {
        }
    };

} /// end of namespace Wiz

#endif /*__WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__*/
