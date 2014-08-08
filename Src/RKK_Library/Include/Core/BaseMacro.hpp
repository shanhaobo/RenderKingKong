#ifndef __RENDERKINGKONG_BASEMACRO_HPP__
#define __RENDERKINGKONG_BASEMACRO_HPP__

//////////////////////////////////////////////////////////////////////////

#   undef   RKK_NULLPTR
#   define  RKK_NULLPTR                         nullptr

//////////////////////////////////////////////////////////////////////////

#   undef RKK_COMBINE
#   ifndef RKK_COMBINE
///     ʾ��:X,Y�Ƿֱ���������, ����Ҫ�ϳ�"Macro"
///     #define  MacroPart_1   Ma
///     #define  MacroPart_2   cro
///     #define  RKK_COMBINE_Error(x, y)  x##y
///     ���� RKK_COMBINE_Error(MacroPart_1, MacroPart_2) => MacroPart_1MacroPart_2 ����δ�ﵽԤ�ڵ�Macro��
///     ��������ֱ�ӽ�MacroPart_1��MacroPart_2�����ַ�������
///     �����������ȷ��Combine,�ͻ����RKK_COMBINE_BRIDGE(Ma, cro),����ʱ�༭���ὫMacroPart_1��MacroPart_2չ��

///     �����##�����������ȼ�������,���ͬ����[##]������[��չ��]��ô�ͻ����MacroPart_1MacroPart_2�����
///     ͬ��#������Ҳ����ִ�����
#       define RKK_COMBINE(X, Y)                RKK_COMBINE_BRIDGE(X, Y)
#       define RKK_COMBINE_BRIDGE(X, Y)         RKK_COMBINE_BRIDGE_IMPL(X,Y)
#       define RKK_COMBINE_BRIDGE_IMPL(X, Y)    X##Y

#   endif /*RKK_COMBINE*/

#   define RKK_COMBINE_3(X, Y, Z)               RKK_COMBINE(RKK_COMBINE(X, Y), Z)
#   define RKK_COMBINE_4(X, Y, Z, W)            RKK_COMBINE(RKK_COMBINE_3(X, Y, Z), W)

//////////////////////////////////////////////////////////////////////////

#endif /*__RENDERKINGKONG_BASEMACRO_HPP__*/
