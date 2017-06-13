#define _CRT_SECURE_NO_DEPRECATE

#include "Enemy.h"
#include "content.h"
#include "Core.h"

CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}

bool CEnemy::init(int _tag)
{
	if (!Sprite::init()) return false;

	m_pEnemySprite = NULL;
	m_iState = WALK;
	m_iPrevState = WALK;
	m_fMoveSpeed = 100.0f;

	m_iTag = _tag;
	m_iObjTag = ENEMY;
	m_iHP = 0; // LiveFlag를 true로 바꿔줄 때 tag를 이용해서 해보자.
	m_iFrame = 0;
	m_fFrameDelay = 0.0f;
	m_bLiveFlag = false;
	isAttack = false;



	if (m_iTag == ENEMY_ZOMBIE_FE)
	{
		m_pEnemySprite = Sprite::create("Zombie_Fe Walk 1.png");
	}

	if (m_iTag == ENEMY_ZOMBIE_MALE)
	{
		m_pEnemySprite = Sprite::create("Zombie_Male Walk 1.png");
	}
	m_pEnemySprite->setFlipX(true);
	m_pEnemySprite->setPosition(Point(3000, 3000)); //화면 밖에 미리 만들어 놓기.
	m_pEnemySprite->setScale(0.2f);
	m_pEnemySprite->setAnchorPoint(Point(0, 0));

	this->addChild(m_pEnemySprite);

	return true;
}

void CEnemy::action(float _dt)
{
	Point pos = m_pEnemySprite->getPosition();

	m_iState = WALK;

	m_pTargetTower = Core::sharedManager()->TM.CollisionCheckAboutTower_Enemy(this);

	if (m_iState == WALK)
	{
		pos.x -= m_fMoveSpeed * _dt;
	}

	animation(_dt);

	m_pEnemySprite->setPosition(pos);
}

void CEnemy::animation(float _dt)
{
	if (m_iPrevState != m_iState)
	{
		m_iPrevState = m_iState;
		m_iFrame = 0;
		m_fFrameDelay = 0.0f;
		isAttack = false;
	}

	char szString[128] = { 0 };

	switch (m_iState)
	{
	case WALK:
	{

		if (m_iTag == ENEMY_ZOMBIE_FE)
			sprintf_s(szString, "%s%d.png", "Zombie_Fe Walk ", m_iFrame);

		else if (m_iTag == ENEMY_ZOMBIE_MALE)
			sprintf_s(szString, "%s%d.png", "Zombie_Male Walk ", m_iFrame);

		m_pEnemySprite->initWithFile(szString);
		m_pEnemySprite->setFlipX(true);

		m_fFrameDelay += _dt;

		if (m_fFrameDelay > 0.1f)
		{
			m_fFrameDelay = 0.f;
			m_iFrame++;
		}

		if (m_iTag == ENEMY_ZOMBIE_FE || m_iTag == ENEMY_ZOMBIE_MALE)
		{
			if (m_iFrame > 9)
				m_iFrame = 0;
		}
	}
	break;

	case ATTACK:
	{

		if (m_iTag == ENEMY_ZOMBIE_FE)
			sprintf_s(szString, "%s%d.png", "Zombie_Fe Attack ", m_iFrame);
		else if (m_iTag == ENEMY_ZOMBIE_MALE)
			sprintf_s(szString, "%s%d.png", "Zombie_Male Attack ", m_iFrame);

		m_pEnemySprite->initWithFile(szString);
		m_fFrameDelay += _dt;
		m_pEnemySprite->setFlipX(true);
		if (m_fFrameDelay > 0.1f)
		{
			m_fFrameDelay = 0.f;
			m_iFrame++;
		}

		if (m_iFrame == 6 && isAttack == false)
		{
			if (m_pTargetTower != NULL)
			{
				m_pTargetTower->m_iHp--;
				Core::sharedManager()->IM->subTowerHp(ENEMY);
				isAttack = true;
				if (m_pTargetTower->m_iHp == 0)
				{
					m_pTargetTower->setLiveFlag(false);
					Core::sharedManager()->TM.getPlayerTower()->m_pTowerImage->setPosition(Point(3000, 3000));
				}
			}
		}

		if (m_iFrame == 7)
			isAttack = false;

		if (m_iTag == ENEMY_ZOMBIE_FE || m_iTag == ENEMY_ZOMBIE_MALE)
		{
			if (m_iFrame > 9)
				m_iFrame = 0;
		}
	}

	break;
	}
}