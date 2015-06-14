#ifndef __WIZ_RANDOM_CORE_HPP__SHANHAOBO_19800429__
#define __WIZ_RANDOM_CORE_HPP__SHANHAOBO_19800429__

#include "../../01_Basic/01_Type/WizBasicType.hpp"

#include "../../01_Basic/04_TU/WizBasicTU.hpp"

namespace Wiz
{
    namespace Random
    {
        namespace Core
		{
			namespace NonRange
			{
				template<class EngineT, class NumT>
				class Type
				{
					typedef NumT					tNum;
					typedef const tNum&				tNumIn;
					typedef EngineT					tEngine;
					typedef typename tEngine::tNum	tEngineNum;
					typedef const tEngine&			tEngineIn;
                public:
                    /// ����Ϊ��,��ʼ�����ܿ���,��Ϊ�����Ƿ���Union�����
					tNum Generate(tEngineIn Eng) const
					{
						return ::Wiz::Cast::Static<tNum>(Eng.Rand());
					}
				public:
					Type()
					{
					}
				};
			} /// end of namespace NonRange

			namespace Range
			{
				template<class EngineT, class NumT>
				class Type
				{
					typedef EngineT					tEngine;
                    typedef tEngine const&          tEngineIn;
					typedef typename tEngine::tNum	tEngineNum;

					typedef NumT					tNum;
					typedef const tNum&				tNumIn;
				private:
					tNum					m_Min;
					tNum					m_Max;
                    ::Wiz::R64::Type        m_RangeNormalized;
				private:
					WIZ_INLINE tNum GetMin() const
					{
						return m_Min;
					}
					WIZ_INLINE tNum GetMax() const
					{
						return m_Max;
					}
                    WIZ_INLINE ::Wiz::R64::Type GetRange() const
					{
                        return ::Wiz::Cast::Static<::Wiz::R64::Type>(GetMax() - GetMin());
					}
                private:
                    ::Wiz::R64::Type RandNormalized(tEngineIn inEng) const
                    {
                        tEngineNum const lRandVal = inEng.Rand() - inEng.GetMin();

                        return lRandVal * m_RangeNormalized;
                    }
				public:
					tNum Generate(tEngineIn inEng) const
					{

                        return ::Wiz::Cast::Static<tNum>(RandNormalized(inEng) * this->GetRange()) + this->GetMin();
					}
				public:
                    /// ����Ϊ��,��ʼ�����ܿ���,��Ϊ�����Ƿ���Union�����
					Type()
					{
					}
				public:
					::Wiz::Void::Type SetMinMax(tNumIn Min, tNumIn Max)
					{
						m_Min = Min;
						m_Max = Max;

                        m_RangeNormalized = 1 / ::Wiz::Cast::Static<::Wiz::R64::Type>(tEngine::GetRange());
					}
				};
			} /// end of namespace Range
		} /// end of namespace Core
    } /// end of namespace Random
} /// end of namespace Engine

#endif /*__WIZ_RANDOM_CORE_HPP__SHANHAOBO_19800429__*/
