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

        U32::type type::CreateModifier()
        {
            return AddModifier(WMS_NULLPTR);
        }

        U32::type type::AddModifier(Attr::Modifier::ptr inModifierPtr)
        {
            if (::wms::IsValidPtr(inModifierPtr))
            {
                inModifierPtr->m_ID = ++m_ModifierID;
                m_ModifierList.PushBack(inModifierPtr);
                return inModifierPtr->m_ID;
            }

            return 0;
        }

        Void::type type::RemoveModifier(U32::in inModifierID)
        {
            ::wms::Size::typec lLastIdx = m_ModifierList.Size() - 1;
            if (lLastIdx >= 0)
            {
                ::wms::Size::type i = 0;
                for (; i < lLastIdx; ++i)
                {
                    if (m_ModifierList[i]->m_ID == inModifierID)
                    {
                        /// ����ҵ���,�����һ��������λ��
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
