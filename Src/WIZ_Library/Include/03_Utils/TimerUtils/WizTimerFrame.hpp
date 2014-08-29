#ifndef __WIZ_TIMER_FRAME_HPP__SHANHAOBO_19800429__
#define __WIZ_TIMER_FRAME_HPP__SHANHAOBO_19800429__

#include "./WizTimerHighRes.hpp"

namespace Wiz
{
    namespace Timer
    {
        namespace Frame
        {
            namespace Wrapper
            {
                WIZ_CLASS
                {
                public:
                    Type(R64::Ref, R64::Ref);

                    virtual ~Type();

                    Void::Type Reset();

                    Void::Type Tick();

                    R64::RefC Now() const
                    {
                        return m_NowRef;
                    }

                    R64::RefC DeltaTime() const
                    {
                        return m_DeltaTimeRef;
                    }

                protected:
                    Timer::HighRes::Ptr m_HighResTimerPtr;

                    R64::Ref            m_NowRef;
                    R64::Ref            m_DeltaTimeRef;
                };
            }

            WIZ_CLASS : public Timer::Frame::Wrapper::Type
            {
            protected:
                typedef Timer::Frame::Wrapper::Type tSuper;

            public:
                Type();

            protected:

                R64::Type   m_Now;
                R64::Type   m_DeltaTime;
            };
        } /// end of namespace Frame
    } /// end of namespace Timer
} /// end of namespace Wiz

#endif /*__WIZ_TIMER_FRAME_HPP__SHANHAOBO_19800429__*/
