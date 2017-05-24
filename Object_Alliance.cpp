#include "Object_Alliance.h"
#include "Core.h"

bool Object_Alliance::init(int _tag)
{

	if (!Sprite::init()) return false;

	m_iState		= WALK;
	m_iPrevState	= WALK;
	m_iDirection	= RIGHT;
	m_fMoveSpeed	= 100.0f;
	m_iTag			= _tag;
	m_iHP			= 0; // LiveFlag를 true로 바꿔줄 때 tag를 이용해서 해보자.
	m_iFrame		= 0;
	m_fFrameDelay	= 0.0f;
	m_bLiveFlag		= false;

	if (m_iTag == SWORD)
	{
		allianceSprite = Sprite::create("sword_walk_0.png");
	}

	allianceSprite->setPosition(Point(3000, 3000)); //화면 밖에 미리 만들어 놓기.
	allianceSprite->setScale(0.2f);
	allianceSprite->setAnchorPoint(Point(0, 0));
	this->addChild(allianceSprite);

	return true;
}

void Object_Alliance::action(float _dt)
{
	Point pos = allianceSprite->getPosition();

	m_iState = WALK;
	
	// 충돌체크 함수

	if (m_iState == WALK)
	{
		pos.x += m_fMoveSpeed * _dt;
	}

	animation(_dt);

	allianceSprite->setPosition(pos);

}

void Object_Alliance::animation(float _dt)
{
	if (m_iPrevState != m_iState)
	{
		m_iPrevState = m_iState;
		m_iFrame = 0;
		m_fFrameDelay = 0.0f;
	}

	char szString[128] = { 0 };

	switch (m_iState)
	{
	case WALK:

		if (m_iTag == SWORD) //칼든 동료가 걸을 때 애니메이션
		{
			sprintf_s(szString, "%s%d.png", "sword_walk_", m_iFrame);
		}

		allianceSprite->initWithFile(szString);

		m_fFrameDelay += _dt;

		if (m_fFrameDelay > 0.1f)
		{
			m_fFrameDelay = 0.f;
			m_iFrame++;
		}

		if (m_iTag == SWORD)
		{
			if (m_iFrame > 9)
				m_iFrame = 0;
		}

		break;
	}
}
