#ifndef __WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

namespace Wiz
{
    namespace FixedString
    {
        template< typename CharT, class TraitsT = ::std::char_traits<CharT>, class AllocatorT = ::std::allocator<CharT> >
        class Type : public ::Wiz::String::Type<CharT, TraitsT, AllocatorT>
        {
        protected:
            typedef typename Type<CharT, TraitsT, AllocatorT>                   tThis;
            typedef tThis const &                                               tThisIn;

            typedef typename ::Wiz::String::Type<CharT, TraitsT, AllocatorT>    tSuper;

        public:
            //////////////////////////////////////////////////////////////////////////
            Type() : tSuper()
            {
            }

            Type(tThisIn InThis) : tSuper(InThis)
            {
            }

            Type(tStdStringIn InStd) : tSuper(InStd)
            {
            }

            Type(tCharPtrConst InPtr) : tSuper(InPtr)
            {
            }

            Type(tCharPtrConst InPtr, tSize InCnt) : tSuper(InPtr, InCnt)
            {
            }
        };
    } /// end of namespace FixedString
} /// end of namespace Wiz

#endif /*__WIZ_ADV_FIXEDSTRING_HPP__SHANHAOBO_19800429__*/
