#ifndef __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__

#include "./WizBasicTUNoncopyable.hpp"

///////////////////////////////////////////////////////////////////////////
//////////////////////////// general singleton ////////////////////////////
///////////////////////////////////////////////////////////////////////////

namespace Wiz
{
    /// Singleton
    namespace Singleton
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
        private:
            Type()
            {

            }

            ~Type()
            {

            }

        public:
            static T & Instance()
            {
                static T s_T;

                return s_T;
            }

            static T * InstancePtr()
            {
                return &Instance();
            }
        };
    } /// end of namespace Singleton
} /// end of namespace Wiz

#define WIZ_SINGLETON_DECLARE(ManagedT)                         \
    WIZ_INLINE ManagedT & Instance()                            \
    {                                                           \
        return ::Wiz::Singleton::Type<ManagedT>::Instance();    \
    }                                                           \
    WIZ_INLINE ManagedT * InstancePtr()                         \
    {                                                           \
        return ::Wiz::Singleton::Type<ManagedT>::InstancePtr(); \
    }

///////////////////////////////////////////////////////////////////////////
//////////////////////////  singleton with init ///////////////////////////
///////////////////////////////////////////////////////////////////////////

namespace Wiz
{
    /// SingletonInit
    namespace SingletonInit
    {
        template <class T>
        class Type : private Noncopyable::Type
        {
            typedef T * tPtr;
        private:
            static tPtr& Data()
            {
                static tPtr s_Ptr = 0;
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
            static void Init(tPtr InPtr)
            {
                Data() = InPtr;
            }
        public:
            static T & Instance()
            {
                return *(Data());
            }
            static tPtr InstancePtr()
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

#endif /*__WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__*/
