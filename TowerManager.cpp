#include "TowerManager.h"
#include "Core.h"

void TowerManager::init() // ���� �ʱ�ȭ �Լ�
{
	memset(m_pTowerList, NULL, sizeof(m_pTowerList));
}

void TowerManager::setScene(Layer* _curScene) //�̹��� ���� , ������ ����, ��ǥ ����, ���̾ add
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

void TowerManager::dealloc() // ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )
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

Object_Tower * TowerManager::CollisionCheckAboutTower_Enemy(CEnemy * _enemy)
{
	for (int i = 0; i < MAX_TOWER; i++)
	{
		if (m_pTowerList[i] == NULL) continue;
		if (m_pTowerList[i]->getLiveFlag() == false) continue;

		if (m_pTowerList[i]->getTag() == P_TOWER)
		{
			if (_enemy->m_iObjTag == ENEMY)
			{
				float x = m_pTowerList[i]->getPosition().x;
				float x2 = _enemy->getPosition().x;
				if (m_pTowerList[i]->getPosition().x - _enemy->getEnemySprite()->getPosition().x > 10.0f)
				{
					_enemy->setState(ATTACK);
					return m_pTowerList[i];
				}
			}
		}
	}

	return NULL;
}
