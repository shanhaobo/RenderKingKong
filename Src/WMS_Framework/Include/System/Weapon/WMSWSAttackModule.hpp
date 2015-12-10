#ifndef __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__ 
#define __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__

#include "../../Core/WMSFrmwrkComponent.hpp"

/// CBD  Component-Based Development

namespace wms
{
    namespace WeapSys
    {
        namespace AttMdl
        {
            WMS_CLASS: public ::wms::CmpntArray::type
            {
            private:
                typedef ::wms::CmpntArray::type tSuper;

            public:
                type();
                virtual ~type();

            protected:
                virtual Void::type Tick(F32::in inDeltaTime);

            protected:

                /// µ¯µÀ(É¢Éä)
                /// ÉËº¦Ä£¿é(ÉËº¦,Ë¥¼õ,´©Í¸)
                /// ¼ä¸ô
                /// Á÷³Ì
                /// Ìù»¨
                /// ¶¯»­
                /// Muzzle & Shell ÌØÐ§
                /// ÔØµ¯
            };
        } /// end of namespace AttMdl
    } /// end of namespace WS
} /// end of namespace wms

#endif /// __WHIMSY_WEAPON_SYSTEM_ATTACK_MODULE_HPP__
