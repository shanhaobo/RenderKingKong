#include "../../Include/System/WMSAttrSystem.hpp"

namespace wms
{
    namespace Attr
    {
        type::type() : m_ModifierID(0)
        {
        }

        type::~type()
        {
        }

        Void::type type::Tick(F32::in inDeltaTime)
        {

        }

        ID32::type type::CreateModifier()
        {
            return AddModifier(WMS_NULLPTR);
        }

        ID32::type type::AddModifier(Attr::Modifier::ptr inModifierPtr)
        {
            if (::wms::IsValidPtr(inModifierPtr))
            {
                inModifierPtr->m_ID = m_ModifierID++;
                m_ModifierList.PushBack(inModifierPtr);
                return inModifierPtr->m_ID;
            }

            return ID32::Invalid;
        }

        Void::type type::RemoveModifier(ID32::in inModifierID)
        {
            ::wms::Size::typec lLastIdx = m_ModifierList.Size() - 1;
            if (lLastIdx >= 0)
            {
                ::wms::Size::type i = 0;
                for (; i < lLastIdx; ++i)
                {
                    if (m_ModifierList[i]->m_ID == inModifierID)
                    {
                        /// 如果找到了,把最后一个换到此位置
                        m_ModifierList[i] = m_ModifierList[lLastIdx];
                        break;
                    }
                }

                if ((i < lLastIdx) || (m_ModifierList[lLastIdx]->m_ID == inModifierID))
                {
                    m_ModifierList.PopBack();
                }
            }
        }

		Void::type type::UpdateModifier()
		{

		}
    } /// end of namespace Attr
} /// end of namespace wms
