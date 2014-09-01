#ifndef __WIZ_BASIC_TU_SINGLETON_INIT_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_SINGLETON_INIT_HPP__SHANHAOBO_19800429__

#include "./WizBasicTUNoncopyable.hpp"

namespace Wiz
{
    /// SingletonInit
    namespace SingletonInit
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
            typedef T * PTR;
        private:
            static PTR& Data()
            {
                static PTR s_Ptr = 0;
                return s_Ptr;
            }
        private:
            Type()
            {
            }
            ~Type()
            {
            }
        public:
            static void Init(PTR InPtr)
            {
                Data() = InPtr;
            }
        public:
            static T & Instance()
            {
                return *(Data());
            }
            static PTR InstancePtr()
            {
                return Data();
            }
        };
    } /// end of namespace SingletonInit
} /// end of namespace Wiz

#define WIZ_SINGLETONINIT_DECLARE(ManagedT)                             \
    WIZ_INLINE void Init(ManagedT* InMngPtr)                            \
    {                                                                   \
        ::Wiz::SingletonInit::Type<ManagedT>::Init(InMngPtr);           \
    }                                                                   \
    WIZ_INLINE ManagedT & Instance()                                    \
    {                                                                   \
        return ::Wiz::SingletonInit::Type<ManagedT>::Instance();        \
    }                                                                   \
    WIZ_INLINE ManagedT * InstancePtr()                                 \
    {                                                                   \
        return ::Wiz::SingletonInit::Type<ManagedT>::InstancePtr();     \
    }

#endif /*__WIZ_BASIC_TU_SINGLETON_INIT_HPP__SHANHAOBO_19800429__*/
