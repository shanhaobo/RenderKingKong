#ifndef __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__

namespace Wiz
{
    /// Singleton
    namespace Singleton
    {
        template <class T>
        class Type : private T
        {
            typedef Type<T> tThis;

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
                static tThis s_T;

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

#endif /*__WIZ_BASIC_TU_SINGLETON_HPP__SHANHAOBO_19800429__*/
