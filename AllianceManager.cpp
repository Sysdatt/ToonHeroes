#include "AllianceManager.h"
#include "Core.h"

void AllianceManager::init()	// 원점 초기화 함수
{
	memset(m_pAllianceList, 0, sizeof(m_pAllianceList));
}

void AllianceManager::setScene(Layer* _curScene)	//이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
{
	this->init();

	int curType = SWORD;

	for (int i = 0; i < MAX_ALLIANCE; i++)
	{
		m_pAllianceList[i] = new Object_Alliance;

		m_pAllianceList[i]->init(curType);

		if (i == 50)
			curType = M_NINJA;
		else if (i == 100)
			curType = F_NINJA;

		_curScene->addChild(m_pAllianceList[i]);
	}
}

void AllianceManager::action(float _dt)
{
	for (int i = 0; i < MAX_ALLIANCE; i++)
	{
		if (m_pAllianceList[i]->m_bLiveFlag == true)
		{
			m_pAllianceList[i]->action(_dt);
		}
	}
}

void AllianceManager::createSwordAlliance()
{
	if (Core::sharedManager()->m_iMP >= 10.f)
	{
		for (int i = 0; i < MAX_ALLIANCE; i++)
		{
			if (m_pAllianceList[i]->m_iTag == SWORD)
			{
				if (m_pAllianceList[i]->m_bLiveFlag == false)
				{
					Core::sharedManager()->m_iMP -= 10.f;
					Core::sharedManager()->IM->PlusMp(Core::sharedManager()->m_iMP);
					m_pAllianceList[i]->m_iHP = 5;
					m_pAllianceList[i]->m_bLiveFlag = true;
					m_pAllianceList[i]->allianceSprite->setPosition(Core::sharedManager()->PlayerStartPos); //스프라이트의 위치를 변경해줘야함.
					return;
				}
			}
		}
	}
}

void AllianceManager::createNinJaMaleAlliance()
{
	if (Core::sharedManager()->m_iMP >= 20.f)
	{
		for (int i = 0; i < MAX_ALLIANCE; i++)
		{
			if (m_pAllianceList[i]->m_iTag == M_NINJA)
			{
				if (m_pAllianceList[i]->m_bLiveFlag == false)
				{
					Core::sharedManager()->m_iMP -= 20.f;
					Core::sharedManager()->IM->PlusMp(Core::sharedManager()->m_iMP);
					m_pAllianceList[i]->m_iHP = 7;
					m_pAllianceList[i]->m_bLiveFlag = true;
					m_pAllianceList[i]->allianceSprite->setPosition(Core::sharedManager()->PlayerStartPos); //스프라이트의 위치를 변경해줘야함.
					return;
				}
			}
		}
	}
}

void AllianceManager::createNinJaFemaleAlliance()
{
	if (Core::sharedManager()->m_iMP >= 30.f)
	{
		for (int i = 0; i < MAX_ALLIANCE; i++)
		{
			if (m_pAllianceList[i]->m_iTag == F_NINJA)
			{
				if (m_pAllianceList[i]->m_bLiveFlag == false)
				{
					Core::sharedManager()->m_iMP -= 30.f;
					Core::sharedManager()->IM->PlusMp(Core::sharedManager()->m_iMP);
					m_pAllianceList[i]->m_iHP = 10;
					m_pAllianceList[i]->m_bLiveFlag = true;
					m_pAllianceList[i]->allianceSprite->setPosition(Core::sharedManager()->PlayerStartPos); //스프라이트의 위치를 변경해줘야함.
					return;
				}
			}
		}
	}
}

void AllianceManager::CollisionCheckWithEnemy(Object_Alliance* _alliance)
{
	CEnemy** EnemyTemp = Core::sharedManager()->EM.getEnemyList();

	if (_alliance->m_bLiveFlag == true)
	{
		for (int j = 0; j < MAX_ENEMY; j++)
		{
			if (EnemyTemp[j]->m_bLiveFlag == false)
				continue;
			else if(EnemyTemp[j]->m_bLiveFlag == true)
			{
				if (EnemyTemp[j]->m_pEnemySprite->getPosition().x - _alliance->allianceSprite->getPosition().x < 50.f
					&& EnemyTemp[j]->m_pEnemySprite->getPosition().x - _alliance->allianceSprite->getPosition().x > -10.f)
				{
					_alliance->m_iState = ATTACK;
					if (_alliance->enemyAttack == true)
					{
						EnemyTemp[j]->Hit();
						if (EnemyTemp[j]->m_iHP == 0)
						{
							EnemyTemp[j]->m_pEnemySprite->setPosition(Point(5000, 5000));
							EnemyTemp[j]->m_bLiveFlag = false;
							EnemyTemp[j]->m_iState = WALK;
							EnemyTemp[j]->m_iPrevState = WALK;
						}
						_alliance->enemyAttack = false;
					}
				}
			}
		}
	}
	
}

void AllianceManager::dealloc()		// 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )
{
	for (int i = 0; i < MAX_ALLIANCE; i++)
	{
		delete(m_pAllianceList[i]);
	}
}