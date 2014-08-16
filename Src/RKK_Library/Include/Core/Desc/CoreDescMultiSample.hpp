#ifndef __RENDERKINGKONG_DESC_MULTISAMPLE_HPP__SHANHAOBO_19800429__
#define __RENDERKINGKONG_DESC_MULTISAMPLE_HPP__SHANHAOBO_19800429__

#include "../../Base/BaseType.hpp"

#include "../Enum/CoreEnumMultiSample.hpp"

namespace rkk
{
    namespace Desc
    {
        /// Multi-Sampling
        namespace MultiSample
        {
            RKK_STRUCT
            {
                type(
                    Enum::MultiSample::in   Count   = Enum::MultiSample::eNone,
                    U8::in                  Quality = 0
                    )
                    : m_Count(Count)
                    , m_Quality(Quality)
                {
                }

                Enum::MultiSample::type     m_Count;
                U8::type                    m_Quality;
            };
        } /// end of namespace MultiSample
    } /// end of namespace Desc
} /// end of namespace rkk

#endif /*__RENDERKINGKONG_DESC_MULTISAMPLE_HPP__SHANHAOBO_19800429__*/
