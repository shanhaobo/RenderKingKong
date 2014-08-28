#include "../../../Include/03_Utils/TimerUtils/WizTimerTicker.hpp"

#include "../../../Include/01_Basic/04_TU/WizBasicTU.hpp"


namespace Wiz
{
    namespace Timer
    {
        namespace Ticker
        {
            Type::Type()
            {
                m_HighResTimerPtr = ::Wiz::Timer::HighRes::Create();
            }

            Type::~Type()
            {
                ::Wiz::Timer::HighRes::Destroy(m_HighResTimerPtr);

                m_HighResTimerPtr = WIZ_NULLPTR;
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
                    R64::TypeC NowSec   = m_HighResTimerPtr->Now_Second();

                    m_DeltaTime         = NowSec - m_Now;

                    m_Now               = NowSec;
                }
            }
        } /// end of namespace Ticker
    } /// end of namespace Timer
} /// end of namespace Wiz
