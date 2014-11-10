#ifndef __WIZ_ADV_FUNCTION_HPP__SHANHAOBO_19800429__
#define __WIZ_ADV_FUNCTION_HPP__SHANHAOBO_19800429__


namespace Wiz
{
    namespace Function
    {
        template <class Param>
        class Type
        {
        };

        namespace MemFunc
        {
            namespace Storage
            {
                struct Type
                {
                    Type() : m_ClassInstPtr(WIZ_NULL), m_MemFuncPtr(WIZ_NULL)
                    {
                    }
                    Type(::Wiz::Void::Ptr InstPtr, ::Wiz::Void::Ptr MemFPtr) : m_ClassInstPtr(InstPtr), m_MemFuncPtr(MemFPtr)
                    {
                    }
                    ::Wiz::Void::Ptr m_ClassInstPtr;
                    ::Wiz::Void::Ptr m_MemFuncPtr;
                };
                WIZ_DECLARE(Type);
            } /// end of namespace Storage

            template <class ClassT, class ParamT> class Type;
        } /// end of namespace MemFunc
    } /// end of namespace Function
} /// end of namespace Wiz


#define WIZ_MPP_REPEAT_FILE_BEGIN   0
#define WIZ_MPP_REPEAT_FILE_END     32
#define WIZ_MPP_REPEAT_FILE_1_NAME  "./WizAdvFunctionMemFunc.hpp"
#define WIZ_MPP_REPEAT_FILE_2_NAME  "./WizAdvFunctionInvoker.hpp"
#define WIZ_MPP_REPEAT_FILE_3_NAME  "./WizAdvFunctionTemplate.hpp"

#include "../../01_Basic/00_MPP/WizBasicMPPRepeatFile.hpp"

#undef WIZ_MPP_REPEAT_FILE_BEGIN
#undef WIZ_MPP_REPEAT_FILE_END

#undef WIZ_MPP_REPEAT_FILE_1_NAME
#undef WIZ_MPP_REPEAT_FILE_2_NAME
#undef WIZ_MPP_REPEAT_FILE_3_NAME

#endif /// #define __WIZ_ADV_FUNCTION_HPP__SHANHAOBO_19800429__

