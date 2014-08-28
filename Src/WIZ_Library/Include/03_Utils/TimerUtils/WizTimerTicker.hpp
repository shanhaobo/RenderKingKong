#ifndef __WIZ_TIMER_TICKER_HPP__SHANHAOBO_19800429__
#define __WIZ_TIMER_TICKER_HPP__SHANHAOBO_19800429__

#include "./WizTimerHighRes.hpp"

namespace Wiz
{
    namespace Timer
    {
        namespace Ticker
        {
            WIZ_CLASS
            {
            public:
                Type();

                ~Type();

                Void::Type Tick();
                Void::Type Reset();

                R64::Type Now() const
                {
                    return m_Now;
                }

                R64::Type DeltaTime() const
                {
                    return m_DeltaTime;
                }

            protected:
                Timer::HighRes::Ptr m_HighResTimerPtr;

                R64::Type   m_Now;
                R64::Type   m_DeltaTime;
            };
        } /// end of namespace Ticker
    } /// end of namespace Timer
} /// end of namespace Wiz

#endif /*__WIZ_TIMER_TICKER_HPP__SHANHAOBO_19800429__*/
