#ifndef __RENDERKINGKONG_BASETYPE_HPP__
#define __RENDERKINGKONG_BASETYPE_HPP__

#include "../../../WIZ_Library/Include/04_Math/00_Utils/WizMathUtils.hpp"

#include "./TypeDeclareUtils.hpp"

#undef  WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE
#define WIZ_DECLARE_HELPER_TEMPLATE_CUSTOM_DEFINE           RKK_DECLARE

#undef  WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE
#define WIZ_DECLARE_HELPER_ITERATOR_CUSTOM_DEFINE           RKK_DECLARE_ITER

#undef  WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE
#define WIZ_DECLARE_HELPER_ITERATOR_CONST_CUSTOM_DEFINE     RKK_DECLARE_ITER_CONST
#include "../../../WIZ_Library/Include/02_Adv/01_Type/Container/WizContainer.hpp"


#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE                    RKK_DECLARE
#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_SIMPLE             RKK_DECLARE_SIMPLE
#undef  WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR
#define WIZ_DECLARE_HELPER_CUSTOM_DEFINE_PTR                RKK_DECLARE_PTR
#include "../../../WIZ_Library/Include/01_Basic/01_Type/WizBasicTypeDeclareHelper.hpp"

namespace rkk
{
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

    namespace F32
    {
        WIZ_DECLARE_HELPER_R32();
    }

    namespace F64
    {
        WIZ_DECLARE_HELPER_R64();
    }

    namespace Void
    {
        typedef void type;
        WIZ_DECLARE_HELPER_VOID();
    }

    namespace Bool
    {
        WIZ_DECLARE_HELPER_BOOL();
    }


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

    template <typename T, typename A = ::std::allocator<T> > 
    struct Array
    {
        typedef typename ::Wiz::Array<T, A>::type   type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct List
    {
        typedef typename ::Wiz::List<T, A>::type    type;
    };

    template <typename I, typename V, typename A = ::std::allocator< ::std::pair<I, V> > >
    struct Map
    {
        typedef typename ::Wiz::Map<I, V, A>::type  type;
    };

    template <typename I, typename V, typename A = ::std::allocator< ::std::pair<I, V> > >
    struct MultiMap
    {
        typedef typename ::Wiz::MultiMap<I, V, A>::type     type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct Set
    {
        typedef typename ::Wiz::Set<T, A>::type     type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct Deque
    {
        typedef typename ::Wiz::Deque<T, A>::type   type;
    };

} /// namespace rkk

#endif /// __RENDERKINGKONG_BASETYPE_HPP__
