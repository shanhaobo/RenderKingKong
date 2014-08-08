#ifndef __RENDERKINGKONG_BASEMACRO_HPP__
#define __RENDERKINGKONG_BASEMACRO_HPP__

//////////////////////////////////////////////////////////////////////////

#   undef   RKK_NULLPTR
#   define  RKK_NULLPTR                         nullptr

//////////////////////////////////////////////////////////////////////////

#   undef RKK_COMBINE
#   ifndef RKK_COMBINE
///     示例:X,Y是分别是两个宏, 并且要合成"Macro"
///     #define  MacroPart_1   Ma
///     #define  MacroPart_2   cro
///     #define  RKK_COMBINE_Error(x, y)  x##y
///     解析 RKK_COMBINE_Error(MacroPart_1, MacroPart_2) => MacroPart_1MacroPart_2 （并未达到预期的Macro）
///     编译器会直接将MacroPart_1与MacroPart_2当作字符串处理
///     如果用下面正确的Combine,就会进入RKK_COMBINE_BRIDGE(Ma, cro),在这时编辑器会将MacroPart_1与MacroPart_2展开

///     这就是##操作符的优先级的问题,如果同级的[##]优先于[宏展开]那么就会出现MacroPart_1MacroPart_2的情况
///     同理#操作符也会出现此问题
#       define RKK_COMBINE(X, Y)                RKK_COMBINE_BRIDGE(X, Y)
#       define RKK_COMBINE_BRIDGE(X, Y)         RKK_COMBINE_BRIDGE_IMPL(X,Y)
#       define RKK_COMBINE_BRIDGE_IMPL(X, Y)    X##Y

#   endif /*RKK_COMBINE*/

#   define RKK_COMBINE_3(X, Y, Z)               RKK_COMBINE(RKK_COMBINE(X, Y), Z)
#   define RKK_COMBINE_4(X, Y, Z, W)            RKK_COMBINE(RKK_COMBINE_3(X, Y, Z), W)

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEMACRO_HPP__*/
