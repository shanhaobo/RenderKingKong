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

        ::wms::Void::type type::AddModfier(::wms::Attr::Modifier::ptr inModifierPtr)
        {
            m_ModfierList.PushBack(inModifierPtr);
        }

        ::wms::Void::type type::RemoveModifer(::wms::Attr::Modifier::ptr inModifierPtr)
        {
            ::wms::Size::typec lLastIdx = m_ModfierList.Size() - 1;
            if (lLastIdx >= 0)
            {
                ::wms::Size::type i = 0;
                for (; i < lLastIdx; ++i)
                {
                    if (m_ModfierList[i] == inModifierPtr)
                    {
                        /// 如果找到了,把最后一个换到此位置
                        m_ModfierList[i] = m_ModfierList[lLastIdx];
                        break;
                    }
                }

                if ((i < lLastIdx) || (m_ModfierList[lLastIdx] == inModifierPtr))
                {
                    m_ModfierList.PopBack();
                }
            }
        }

		::wms::Void::type type::UpdateModifer()
		{

		}
    } /// end of namespace Attr
} /// end of namespace wms
