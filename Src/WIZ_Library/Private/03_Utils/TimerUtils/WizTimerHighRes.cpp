#include "../../../Include/03_Utils/TimerUtils/WizTimerHighRes.hpp"


namespace Wiz
{
    namespace Timer
    {
        namespace HighRes
        {
#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
            namespace Windows
            {
                class Type : public Timer::HighRes::Type
                {
                public:
                    Type()
                    {
                    }

                    virtual ~Type()
                    {

                    }

                public:
                    virtual Void::Type Reset() = 0;

                    virtual R64::Type Now_Second() = 0;             /// √Î

                    virtual R64::Type Now_MilliSecond() = 0;        /// ∫¡√Î

                    virtual R64::Type Now_MicroSecond() = 0;        /// Œ¢√Î
                };
            } /// end of namespace Windows
#endif /// (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)


#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
            namespace Linux
            {
                class Type : public Timer::HighRes::Type
                {
                public:
                    Type()
                    {
                    }

                    virtual ~Type()
                    {

                    }

                public:
                    virtual Void::Type Reset() = 0;

                    virtual R64::Type Now_Second() = 0;             /// √Î

                    virtual R64::Type Now_MilliSecond() = 0;        /// ∫¡√Î

                    virtual R64::Type Now_MicroSecond() = 0;        /// Œ¢√Î
                };
            } /// end of namespace Linux
#endif /// (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)



            Ptr Create()
            {
                return WIZ_NULLPTR;
            }

            Void::Type Destroy(Ptr& InPtr)
            {

                InPtr = WIZ_NULLPTR;
            }
        } /// end of namespace HighRes
    } /// end of namespace Timer
} /// end of namespace rkk


