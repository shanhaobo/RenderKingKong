#include "../../../Include/03_Utils/TimerUtils/WizTimerFrame.hpp"

#include "../../../Include/01_Basic/04_TU/WizBasicTU.hpp"


namespace Wiz
{
    namespace Timer
    {
        namespace Frame
        {
            namespace Wrapper
            {
                Type::Type(R64::Ref InNowRef, R64::Ref InDeltaTimeRef) : m_NowRef(InNowRef), m_DeltaTimeRef(InDeltaTimeRef)
                {
                    m_HighResTimerPtr = ::Wiz::Timer::HighRes::Create();
                }

                Type::~Type()
                {
                    ::Wiz::Timer::HighRes::Destroy(m_HighResTimerPtr);
                }

                Void::Type Type::Reset()
                {
                    if (::Wiz::IsValidPtr(m_HighResTimerPtr))
                    {
                        m_HighResTimerPtr->Reset();
                    }
                }

                Void::Type Type::Tick()
                {
                    if (::Wiz::IsValidPtr(m_HighResTimerPtr))
                    {
                        R64::TypeC NowSec = m_HighResTimerPtr->Now_Second();

                        m_DeltaTimeRef = NowSec - m_NowRef;

                        m_NowRef = NowSec;
                    }
                }
            } /// end of namespace Wrapper


            Type::Type() : tSuper(m_Now, m_DeltaTime)
            {
            }

        } /// end of namespace Frame
    } /// end of namespace Timer
} /// end of namespace Wiz
