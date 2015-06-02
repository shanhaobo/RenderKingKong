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


        ::wms::Void::type type::AddModfier(::wms::Attr::Modifier::in inModifier)
        {
            m_ModfierList.PushBack(inModifier);
        }

        ::wms::Void::type type::RemoveModifer(::wms::Attr::Modifier::in inModifier)
        {
            ::wms::Size::typec lLastIdx = m_ModfierList.Size() - 1;
            if (lLastIdx >= 0)
            {
                ::wms::Size::type i = 0;
                for (; i < lLastIdx; ++i)
                {
                    if (m_ModfierList[i] == inModifier)
                    {
                        /// 如果找到了,把最后一个换到此位置
                        m_ModfierList[i] = m_ModfierList[lLastIdx];
                        break;
                    }
                }

                if ((i < lLastIdx) || (m_ModfierList[lLastIdx] == inModifier))
                {
                    m_ModfierList.PopBack();
                }
            }
        }
    } /// end of namespace Cmpnt
} /// end of namespace wms
