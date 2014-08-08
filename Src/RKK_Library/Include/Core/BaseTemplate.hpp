#ifndef __RENDERKINGKONG_BASETEMPLATE_HPP__
#define __RENDERKINGKONG_BASETEMPLATE_HPP__

#include "BaseType.hpp"
#include "BaseMacro.hpp"

//////////////////////////////////////////////////////////////////////////

namespace rkk
{
    template<class T>
    inline Bool::type IsValidPtr(T const * const ptr)
    {
        return (ptr == RKK_NULLPTR);
    }

} /// end of namespace rkk

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASETEMPLATE_HPP__*/
