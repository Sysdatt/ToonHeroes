#include "EnemyManager.h"
#include "Core.h"



CEnemyManager::CEnemyManager()
{
}


CEnemyManager::~CEnemyManager()
{
}



void CEnemyManager::init()
{
	memset(m_pEnemyList, 0, sizeof(m_pEnemyList));
}

void CEnemyManager::setScene(Layer * _curScene)
{
	this->init();

	int curType = ENEMY_ZOMBIE_FE;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		m_pEnemyList[i] = new CEnemy;

		m_pEnemyList[i]->init(curType);

		if (i == 50)
			curType = ENEMY_ZOMBIE_MALE;

		_curScene->addChild(m_pEnemyList[i]);
	}
}

void CEnemyManager::action(float _dt)
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (m_pEnemyList[i]->getLiveFlag() == true)
		{
			m_pEnemyList[i]->action(_dt);
		}
	}
}

void CEnemyManager::createZombie_Fe()
{

	for (int i = 0; i < MAX_ENEMY; i++)
	{

		if (m_pEnemyList[i]->m_iTag == ENEMY_ZOMBIE_FE)
		{
			if (m_pEnemyList[i]->m_bLiveFlag == false)
			{
				m_pEnemyList[i]->m_iHP = 5;
				m_pEnemyList[i]->m_bLiveFlag = true;
				m_pEnemyList[i]->getEnemySprite()->setPosition(Core::sharedManager()->EnemyStartPos); //스프라이트의 위치를 변경해줘야함.
				return;
			}
		}
	}


}

void CEnemyManager::createZombie_Male()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (m_pEnemyList[i]->getTag() == ENEMY_ZOMBIE_MALE)
		{
			if (m_pEnemyList[i]->getLiveFlag() == false)
			{
				m_pEnemyList[i]->setHp(5);
				m_pEnemyList[i]->setLiveFlag(true);
				m_pEnemyList[i]->getEnemySprite()->setPosition(Core::sharedManager()->EnemyStartPos); //스프라이트의 위치를 변경해줘야함.
				return;
			}
		}
	}
}

void CEnemyManager::CollisionCheckWithAlliance(CEnemy* _enemy)
{
	Object_Alliance** AllianceTemp = Core::sharedManager()->AM.getAllianceList();

	if (_enemy->m_bLiveFlag == true)
	{
		for (int j = 0; j < MAX_ALLIANCE; j++)
		{
			if (AllianceTemp[j]->m_bLiveFlag == false)
				continue;
			else
			{
				if (AllianceTemp[j]->allianceSprite->getPosition().x - _enemy->m_pEnemySprite->getPosition().x < 50.f
					&& AllianceTemp[j]->allianceSprite->getPosition().x - _enemy->m_pEnemySprite->getPosition().x > -50.f)
				{
					_enemy->m_iState = ATTACK;
					if (_enemy->AllianceAttack == true)
					{
						AllianceTemp[j]->Hit();
						if (AllianceTemp[j]->m_iHP == 0)
						{
							AllianceTemp[j]->allianceSprite->setPosition(Point(3000, 3000));
							AllianceTemp[j]->m_bLiveFlag = false;
							AllianceTemp[j]->m_iState = WALK;
							AllianceTemp[j]->m_iPrevState = WALK;
						}
						_enemy->AllianceAttack = false;
					}
				}
			}
		}
	}
}

void CEnemyManager::dealloc()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		delete(m_pEnemyList[i]);
	}
}
