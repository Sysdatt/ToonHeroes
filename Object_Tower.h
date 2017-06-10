#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Object_Tower : public Sprite
{
public:
	int		m_iHp;
	int		m_iTag;			// P_TOWER? E_TOWER?
	int		m_iObjTag;		// Player? enemy?
	bool	m_bLiveFlag;
	Sprite* m_pTowerImage;
public:
	bool init(int _tag);	//타워 하나의 객체 초기화 기능
	bool getLiveFlag() { return m_bLiveFlag; }
	void setLiveFlag(bool _Flag) { m_bLiveFlag = _Flag; }
	int getTag() { return m_iTag; }
	void setTag(int _tag) { m_iTag = _tag; }
};