#include "../../../Include/03_Utils/TimerUtils/WizTimerHighRes.hpp"

#include <algorithm>

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
#   include <windows.h>
#elif (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
#   include <sys/time.h>
#endif /// (WIZ_CFG_PLATFORM)

namespace Wiz
{
    namespace Timer
    {
        namespace HighRes
        {
            namespace Impl
            {
                template<class DerivedT>
                class Type : public Timer::HighRes::Type
                {
                public:
                    typedef DerivedT tDerived;

                public:
                    tDerived* GetDerivedPtr()
                    {
                        return static_cast<tDerived*>(this);
                    }
                public:
                    virtual R64::Type Now_Second()             /// Ãë
                    {
                        return GetDerivedPtr()->Now<1>();
                    }

                    virtual R64::Type Now_MilliSecond()        /// ºÁÃë
                    {
                        return GetDerivedPtr()->Now<1000>();
                    }

                    virtual R64::Type Now_MicroSecond()        /// Î¢Ãë
                    {
                        return GetDerivedPtr()->Now<1000000>();
                    }
                }; /// class Type
            } /// end of namespace Impl

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)
            namespace Windows
            {
                class Type : public Timer::HighRes::Impl::Type<Type>
                {
                public:
                    Type() : mTimerMask(0)
                    {
                        Reset();
                    }

                    virtual ~Type()
                    {

                    }

                public:
                    virtual Void::Type Reset()
                    {
                        // Get the current process core mask
                        DWORD_PTR procMask;
                        DWORD_PTR sysMask;
                        GetProcessAffinityMask(GetCurrentProcess(), &procMask, &sysMask);

                        // If procMask is 0, consider there is only one core available
                        // (using 0 as procMask will cause an infinite loop below)
                        if (procMask == 0)
                        {
                            procMask = 1;
                        }

                        // Find the lowest core that this process uses
                        if (mTimerMask == 0)
                        {
                            mTimerMask = 1;
                            while ((mTimerMask & procMask) == 0)
                            {
                                mTimerMask <<= 1;
                            }
                        }

                        HANDLE thread = GetCurrentThread();

                        // Set affinity to the first core
                        DWORD_PTR oldMask = SetThreadAffinityMask(thread, mTimerMask);

                        // Get the constant frequency
                        QueryPerformanceFrequency(&mFrequency);

                        // Query the timer
                        QueryPerformanceCounter(&mStartTime);

                        mStartTick = GetTickCount();

                        // Reset affinity
                        SetThreadAffinityMask(thread, oldMask);

                        mLastTime = 0;

                        m_R64Frequency = R64::Type(mFrequency.QuadPart);
                    }

                    template<int iMultiTime>
                    R64::Type Now()
                    {
                        LARGE_INTEGER curTime;

                        HANDLE thread = GetCurrentThread();

                        // Set affinity to the first core
                        DWORD_PTR oldMask = SetThreadAffinityMask(thread, mTimerMask);

                        // Query the timer
                        QueryPerformanceCounter(&curTime);

                        // Reset affinity
                        SetThreadAffinityMask(thread, oldMask);

                        LONGLONG newTime = curTime.QuadPart - mStartTime.QuadPart;

                        // scale by 1000 for milliseconds
                        R64::Type NowTicks = static_cast<R64::Type>((iMultiTime * newTime) / m_R64Frequency);

                        // detect and compensate for performance counter leaps
                        // (surprisingly common, see Microsoft KB: Q274323)
                        unsigned long check = GetTickCount() - mStartTick;
                        signed long msecOff = (signed long)(NowTicks - check);
                        if (msecOff < -100 || msecOff > 100)
                        {
                            // We must keep the timer running forward :)
                            LONGLONG adjust = (::std::min)(msecOff * mFrequency.QuadPart / iMultiTime, newTime - mLastTime);
                            mStartTime.QuadPart += adjust;
                            newTime -= adjust;

                            // Re-calculate milliseconds
                            NowTicks = static_cast<R64::Type>((iMultiTime * newTime) / m_R64Frequency);
                        }

                        // Record last time for adjust
                        mLastTime = newTime;

                        return NowTicks;
                    }

                protected:
                    LARGE_INTEGER   mStartTime;
                    LARGE_INTEGER   mFrequency;
                    R64::Type       m_R64Frequency;

                    DWORD           mStartTick;
                    LONGLONG        mLastTime;

                    DWORD_PTR       mTimerMask;
                };
            } /// end of namespace Windows
#endif /// (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_WINDOWS)

#if (WIZ_CFG_PLATFORM == WIZ_CFG_PLATFORM_LINUX)
            namespace Linux
            {
                class Type : public Timer::HighRes::Impl::Type<Type>
                {
                public:
                    Type()
                    {
                        Reset();
                    }

                    virtual ~Type()
                    {

                    }

                public:
                    virtual Void::Type Reset()
                    {
                        gettimeofday(&start, NULL);
                    }

                    template<int iMultiTime>
                    R64::Type Now()
                    {
                        struct timeval now;
                        gettimeofday(&now, NULL);

                        return R64::Type(now.tv_sec - start.tv_sec) * iMultiTime + R64::Type(now.tv_usec - start.tv_usec) * iMultiTime / 1000000;
                    }

                private:
                    struct timeval start;
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


