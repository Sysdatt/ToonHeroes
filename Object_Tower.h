#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Object_Tower : public Sprite
{
private:
	int		m_iHp;
	int		m_iTag;
	bool	m_bLiveFlag;
	Sprite* m_pTowerImage;
public:
	bool init(int _tag);	//타워 하나의 객체 초기화 기능
};