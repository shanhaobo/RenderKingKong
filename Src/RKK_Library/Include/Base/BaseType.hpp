#ifndef __RENDERKINGKONG_BASETYPE_HPP__
#define __RENDERKINGKONG_BASETYPE_HPP__

#include "./RKKPrerequisites.hpp"

#include "../../../WIZ_Library/include/Wiz.hpp"

#include "./BaseAllocator.hpp"

namespace rkk
{
    /////////////////////////////////////////////////////////////

    namespace I
    {
        WIZ_DECLARE_HELPER_I();
    }

    namespace U
    {
        WIZ_DECLARE_HELPER_U();
    }

    namespace I8
    {
        WIZ_DECLARE_HELPER_I8();
    }

    namespace U8
    {
        WIZ_DECLARE_HELPER_U8();
    }

    namespace I16
    {
        WIZ_DECLARE_HELPER_I16();
    }

    namespace U16
    {
        WIZ_DECLARE_HELPER_U16();
    }

    namespace I32
    {
        WIZ_DECLARE_HELPER_I32();
    }

    namespace U32
    {
        WIZ_DECLARE_HELPER_U32();
    }

    namespace I64
    {
        WIZ_DECLARE_HELPER_I64();
    }

    namespace U64
    {
        WIZ_DECLARE_HELPER_U64();
    }

    /////////////////////////////////////////////////////////////

    namespace Char
    {
        WIZ_DECLARE_HELPER_CHAR();
    }

    namespace WChar
    {
        WIZ_DECLARE_HELPER_WCHAR();
    }

    namespace MBChar
    {
        WIZ_DECLARE_HELPER_MBCHAR();
    }

    /////////////////////////////////////////////////////////////

    namespace F32
    {
        WIZ_DECLARE_HELPER_R32();
    }

    namespace F64
    {
        WIZ_DECLARE_HELPER_R64();
    }

    /////////////////////////////////////////////////////////////

    namespace Void
    {
        typedef void type;
        WIZ_DECLARE_HELPER_VOID();
    }

    namespace Bool
    {
        WIZ_DECLARE_HELPER_BOOL();
    }

    /////////////////////////////////////////////////////////////

    namespace Size
    {
        WIZ_DECLARE_HELPER_SIZE();
    }

    namespace Size8
    {
        WIZ_DECLARE_HELPER_SIZE8();
    }

    namespace Size16
    {
        WIZ_DECLARE_HELPER_SIZE16();
    }

    namespace Size32
    {
        WIZ_DECLARE_HELPER_SIZE32();
    }

    namespace Size64
    {
        WIZ_DECLARE_HELPER_SIZE64();
    }

    /////////////////////////////////////////////////////////////

    template <typename T, typename A = ::std::allocator<T> > 
    struct Array
    {
        typedef typename ::Wiz::Array::Type<T, A>           type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct List
    {
        typedef typename ::Wiz::List::Type<T, A>            type;
    };

    template <typename I, typename V, class C = ::std::less<I>, typename A = ::std::allocator< ::std::pair<I, V> > >
    struct Map
    {
        typedef typename ::Wiz::Map::Type<I, V, C, A>       type;
    };

    template <typename I, typename V, class C = ::std::less<I>, typename A = ::std::allocator< ::std::pair<I, V> > >
    struct MultiMap
    {
        typedef typename ::Wiz::MultiMap::Type<I, V, C, A>  type;
    };

    template <typename T, class C = ::std::less<I>, typename A = ::std::allocator<T> >
    struct Set
    {
        typedef typename ::Wiz::Set::Type<T, C, A>          type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct Deque
    {
        typedef typename ::Wiz::Deque::Type<T, A>           type;
    };

    /////////////////////////////////////////////////////////////

    namespace Str
    {
        typedef ::Wiz::String::Type<::rkk::Char::type>      type;
        RKK_DECLARE(type);
    }

    namespace WStr
    {
        typedef ::Wiz::String::Type<::rkk::WChar::type>     type;
        RKK_DECLARE(type);
    }

    /////////////////////////////////////////////////////////////

    namespace Name
    {
        typedef ::Wiz::HashString::Type< ::rkk::Str::type, ::Wiz::HashString::Proxy::Category::eSDBM, true, 64, 65536, 1024, ::std::allocator<::rkk::Char::type> >   type;

        RKK_DECLARE(type);
    }

    /////////////////////////////////////////////////////////////

} /// namespace rkk

#endif /// __RENDERKINGKONG_BASETYPE_HPP__
