#ifndef __WIZ_BASE_MACRO_ASSERT_HPP__SHANHAOBO_19800429__
#define __WIZ_BASE_MACRO_ASSERT_HPP__SHANHAOBO_19800429__

#include <assert.h>

#include "../../00_Config/WizConfig.hpp"

#if (WIZ_DEBUG_MODE == WIZ_CFG_TRUE)
#   define WIZ_ASSERT(b)                assert(b)
#   define WIZ_ASSERT_COMMENT(a, c)     assert(((a) && (c)))
#   define WIZ_ASSERT_ERROR(c)          assert((::Wiz::Bool::False && (c)))
#else
#   define WIZ_ASSERT(b)
#   define WIZ_ASSERT_COMMENT(a, c)
#   define WIZ_ASSERT_ERROR(c)
#endif /*WIZ_ASSERT*/

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif /*__WIZ_BASE_MACRO_ASSERT_HPP__SHANHAOBO_19800429__*/
