#include "Object_Alliance.h"
#include "Core.h"

bool Object_Alliance::init(int _tag)
{

	if (!Sprite::init()) return false;

	m_iState		= WALK;
	m_iPrevState	= WALK;
	m_fMoveSpeed	= 100.0f;
	m_pTargetTower	= NULL;
	
	m_iTag			= _tag;
	m_iObjTag		= PLAYER;
	m_iHP			= 0; // LiveFlag를 true로 바꿔줄 때 tag를 이용해서 해보자.
	m_iFrame		= 0;
	m_fFrameDelay	= 0.0f;
	m_bLiveFlag		= false;
	isAttack		= false;
	enemyAttack		= false;

	if (m_iTag == SWORD)
	{
		allianceSprite = Sprite::create("sword_walk_0.png");
		allianceSprite->setScale(0.2f);
	}

	else if (m_iTag == M_NINJA)
	{
		allianceSprite = Sprite::create("m_ninja_walk_0.png");
		allianceSprite->setScale(0.28f);
	}
	else if (m_iTag == F_NINJA)
	{
		allianceSprite = Sprite::create("f_ninja_walk_0.png");
		allianceSprite->setScale(0.25f);
	}

	allianceSprite->setPosition(Point(3000, 3000)); //화면 밖에 미리 만들어 놓기.
	allianceSprite->setAnchorPoint(Point(0, 0));
	this->addChild(allianceSprite);

	return true;
}

void Object_Alliance::action(float _dt)
{
	Point pos = allianceSprite->getPosition();

	m_iState = WALK;
	
	m_pTargetTower = Core::sharedManager()->TM.CollisionCheckAboutTower(this);
	Core::sharedManager()->AM.CollisionCheckWithEnemy(this);

	animation(_dt);

	if (m_iState == WALK)
	{
		pos.x += m_fMoveSpeed * _dt;
	}

	allianceSprite->setPosition(pos);

}

void Object_Alliance::animation(float _dt)
{
	if (m_iPrevState != m_iState)
	{
		m_iPrevState = m_iState;
		m_iFrame = 0;
		m_fFrameDelay = 0.0f;
		isAttack = false;
		enemyAttack = false;
	}

	char szString[128] = { 0 };

	switch (m_iState)
	{
	case WALK:

		if (m_iTag == SWORD) //칼든 동료가 걸을 때 애니메이션
			sprintf_s(szString, "%s%d.png", "sword_walk_", m_iFrame);
		else if (m_iTag == M_NINJA)
			sprintf_s(szString, "%s%d.png", "m_ninja_walk_", m_iFrame);
		else if (m_iTag == F_NINJA)
			sprintf_s(szString, "%s%d.png", "f_ninja_walk_", m_iFrame);


		allianceSprite->initWithFile(szString);

		m_fFrameDelay += _dt;

		if (m_fFrameDelay > 0.1f)
		{
			m_fFrameDelay = 0.f;
			m_iFrame++;
		}

		if (m_iTag == SWORD || m_iTag == M_NINJA || m_iTag == F_NINJA)
		{
			if (m_iFrame > 9)
				m_iFrame = 0;
		}

		break;

	case ATTACK:
		if (m_iTag == SWORD)
			sprintf_s(szString, "%s%d.png", "sword_attack_", m_iFrame);
		else if (m_iTag == M_NINJA)
			sprintf_s(szString, "%s%d.png", "m_ninja_attack_", m_iFrame);
		else if (m_iTag == F_NINJA)
			sprintf_s(szString, "%s%d.png", "f_ninja_attack_", m_iFrame);

		allianceSprite->initWithFile(szString);
		m_fFrameDelay += _dt;

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
				Core::sharedManager()->IM->subTowerHp(PLAYER); // 인터페이스에서 체력을 깍자
				isAttack = true;
				if (m_pTargetTower->m_iHp == 0)
				{
					m_pTargetTower->setLiveFlag(false);
					Core::sharedManager()->TM.getEnemyTower()->m_pTowerImage->setPosition(Point(3000, 3000)); // 라이브플래그가 False일 경우(죽었을 경우) 안보이는 위치로 사진을 보내버림.
					Core::sharedManager()->m_iMaxStage++;
					if (Core::sharedManager()->m_iMaxStage == 4)
						Core::sharedManager()->m_iMaxStage = 3;
					Director::getInstance()->replaceScene(SelectStageScene::createScene());
				}
			}
			else
			{
				isAttack = true;
				enemyAttack = true;
			}
		}

		if (m_iFrame == 7)
		{
			isAttack = false;
		}

		if (m_iTag == SWORD || m_iTag == M_NINJA || m_iTag == F_NINJA)
		{
			if (m_iFrame > 9)
				m_iFrame = 0;
		}

		break;
	}
}

void	Object_Alliance::Hit()
{
	m_iHP--;
}