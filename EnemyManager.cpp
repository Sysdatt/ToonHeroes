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
				m_pEnemyList[i]->m_iHP = 30;
				m_pEnemyList[i]->m_bLiveFlag = true;
				m_pEnemyList[i]->getEnemySprite()->setPosition(Core::sharedManager()->PlayerStartPos); //스프라이트의 위치를 변경해줘야함.
				return;
			}
		}
	}


}

/*
void AllianceManager::createSwordAlliance()
{
if (Core::sharedManager()->m_iMP >= 20.f)
{
for (int i = 0; i < MAX_ALLIANCE; i++)
{
if (m_pAllianceList[i]->m_iTag == SWORD)
{
if (m_pAllianceList[i]->m_bLiveFlag == false)
{
Core::sharedManager()->m_iMP -= 20.f;
Core::sharedManager()->IM->PlusMp(Core::sharedManager()->m_iMP);
m_pAllianceList[i]->m_iHP = 5;
m_pAllianceList[i]->m_bLiveFlag = true;
m_pAllianceList[i]->allianceSprite->setPosition(Core::sharedManager()->PlayerStartPos); //스프라이트의 위치를 변경해줘야함.
return;
}
}
}
}
}*/



void CEnemyManager::createZombie_Male()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (m_pEnemyList[i]->getTag() == ENEMY_ZOMBIE_MALE)
		{
			if (m_pEnemyList[i]->getLiveFlag() == false)
			{
				m_pEnemyList[i]->setHp(30);
				m_pEnemyList[i]->setLiveFlag(true);
				m_pEnemyList[i]->getEnemySprite()->setPosition(Core::sharedManager()->EnemyStartPos); //스프라이트의 위치를 변경해줘야함.
				return;
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
