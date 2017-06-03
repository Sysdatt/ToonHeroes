#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#include "Object_Tower.h"

class Object_Alliance : public Sprite
{
public:
	Sprite*		allianceSprite;
	Object_Tower* m_pTargetTower;
	float		m_fMoveSpeed;
	int			m_iTag;			//객체 태그
	int			m_iObjTag;		//플레이어 인가? 적인가? 충돌체크 용
	bool		m_bLiveFlag;
	int			m_iHP;

	int			m_iState;
	int			m_iPrevState;
	int			m_iFrame;
	float		m_fFrameDelay;
	bool		isAttack;
	
public:
	virtual bool init(int _tag);
	void action(float _dt);
	void animation(float _dt);
};