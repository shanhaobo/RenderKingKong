#include "../../Include/System/WMSAttrSystem.hpp"

namespace wms
{
    namespace Attr
    {
        type::type()
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {

        }

        ::wms::Void::type type::AddModifier(::wms::Attr::Modifier::ptr inModifierPtr)
        {
            m_ModifierList.PushBack(inModifierPtr);
        }

        ::wms::Void::type type::RemoveModifier(::wms::Attr::Modifier::ptr inModifierPtr)
        {
            ::wms::Size::typec lLastIdx = m_ModifierList.Size() - 1;
            if (lLastIdx >= 0)
            {
                ::wms::Size::type i = 0;
                for (; i < lLastIdx; ++i)
                {
                    if (m_ModifierList[i] == inModifierPtr)
                    {
                        /// 如果找到了,把最后一个换到此位置
                        m_ModifierList[i] = m_ModifierList[lLastIdx];
                        break;
                    }
                }

                if ((i < lLastIdx) || (m_ModifierList[lLastIdx] == inModifierPtr))
                {
                    m_ModifierList.PopBack();
                }
            }
        }

		::wms::Void::type type::UpdateModifier()
		{

		}
    } /// end of namespace Attr
} /// end of namespace wms
