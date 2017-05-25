#include "TowerManager.h"
#include "Core.h"

void TowerManager::init() // 원점 초기화 함수
{
	memset(m_pTowerList, NULL, sizeof(m_pTowerList));
}

void TowerManager::setScene(Layer* _curScene) //이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
{
	this->init();

	for (int i = 0; i < MAX_TOWER; i++)
	{
		m_pTowerList[i] = new Object_Tower;
		if (i == 0)
		{
			m_pTowerList[i]->init(P_TOWER);
			m_pTowerList[i]->setPosition(Point(155, 100));
		}
		else if (i == 1)
		{
			m_pTowerList[i]->init(E_TOWER);
			m_pTowerList[i]->setPosition(Point(1900, 100));
		}

		m_pTowerList[i]->setScale(0.7f);

		_curScene->addChild(m_pTowerList[i]);
	}
}

void TowerManager::dealloc() // 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )
{
	for (int i = 0; i < MAX_TOWER; i++)
	{
		delete(m_pTowerList[i]);
	}
}

Object_Tower* TowerManager::CollisionCheckAboutTower(Object_Alliance* _alliance)
{
	for (int i = 0; i < MAX_TOWER; i++)
	{
		if (m_pTowerList[i] == NULL) continue;
		if (m_pTowerList[i]->getLiveFlag() == false) continue;

		if (m_pTowerList[i]->getTag() == E_TOWER)
		{
			if (_alliance->m_iObjTag == PLAYER)
			{
				float x = m_pTowerList[i]->getPosition().x;
				float x2 = _alliance->getPosition().x;
				if (m_pTowerList[i]->getPosition().x - _alliance->allianceSprite->getPosition().x < 50.0f)
				{
					_alliance->m_iState = ATTACK;
					return m_pTowerList[i];
				}
			}
		}
	}

	return NULL;
}