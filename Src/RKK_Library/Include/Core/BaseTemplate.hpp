#ifndef __RENDERKINGKONG_BASETEMPLATE_HPP__
#define __RENDERKINGKONG_BASETEMPLATE_HPP__

#include "../../../WIZ_Library/Include/01_Basic/03_TU/WizBasicTU.hpp"

//////////////////////////////////////////////////////////////////////////

namespace rkk
{
    template<class T>
    inline Bool::type IsValidPtr(T const * const ptr)
    {
        return ::Wiz::IsValidPtr(ptr);
    }

} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASETEMPLATE_HPP__*/
