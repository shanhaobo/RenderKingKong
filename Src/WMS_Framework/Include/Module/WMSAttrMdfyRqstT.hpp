#ifndef __WHIMSY_ATTRIBUTE_MDFYRQST_T_HPP__ 
#define __WHIMSY_ATTRIBUTE_MDFYRQST_T_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"

namespace wms
{
    namespace Attr
    {
        namespace MdfyRqst
        {
            template<class T>
            class Type : public Attr::MdfyRqst::type
            {
            protected:
                typedef T                               tValue;
                typedef tValue &                        tValueRef;
                typedef tValueRef                       tValueOut;
                typedef tValueRef const                 tValueIn;

            public:
                virtual Void::type Calc(tValueOut ioCurrVal, F32::in inDeltaTime, tValueIn inBaseValue) = 0;
            };
        } /// end of namespace ModfyReqst
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_MDFYRQST_T_HPP__
