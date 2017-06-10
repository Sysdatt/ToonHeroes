#pragma once
#include "cocos2d.h"
#include "Object_Tower.h"

using namespace cocos2d;

class CEnemy :
	public Sprite
{
public:
	CEnemy();
	~CEnemy();

public:
	Sprite* m_pEnemySprite;
	Object_Tower* m_pTargetTower;
	Point		m_pos;
	float		m_fMoveSpeed;
	int			m_iTag;			//객체 태그
	int			m_iObjTag;		//플레이어 인가? 적인가? 충돌체크 용
	bool		m_bLiveFlag;
	int			m_iHP;

	int			m_iState;
	int			m_iPrevState;
	int			m_iDirection;
	int			m_iFrame;
	float		m_fFrameDelay;
	bool		isAttack;
	Point		m_EnemyPos;


public:
	void		setHp(int EnemyHp)				{ m_iHP = EnemyHp; }
	void		setLiveFlag(bool EnemyLiveFlag)	{ m_bLiveFlag = EnemyLiveFlag; }
	void		setState(int State)				{ m_iState = State; }

public:
	bool		getLiveFlag()		{ return m_bLiveFlag; }
	int			getTag()			{ return m_iTag; }
	Sprite*		getEnemySprite()	{ return m_pEnemySprite; }
	int			getObjTag()			{ return m_iObjTag; }
	int			getState()			{ return m_iState; }
	
public:
	virtual bool init(int _tag);
	virtual void action(float _dt);
	virtual void animation(float _dt);
	virtual void setSpeed(float _speed) { m_fMoveSpeed = _speed; }
};

