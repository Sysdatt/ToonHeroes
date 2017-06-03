#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class InGameInterface : public Layer
{
public:
	Sprite* m_PlayerHpBar;
	Sprite* m_EnemyHpBar;

	Sprite* m_ChoiceInterface;

	Sprite* m_CurPlayerHp;
	CCProgressTimer* _progressPlayerHpBar;
	Sprite* m_CurEnemyHp;
	CCProgressTimer* _progressEnemyHpBar;
	Sprite* m_CurMp;
	CCProgressTimer* _progressMpBar;

	Sprite* m_SwordMenu;
	Sprite* m_F_NinjaMenu;
	Sprite* m_M_NinjaMenu;

	bool isFlag;


	CCProgressTimer* m_progressPlayerHpBar;
	CCProgressTimer* m_progressEnemyHpBar;

public:

	virtual bool init();
	void subTowerHp(int Tag);
	void PlusMp(float _curMp);

	// implement the "static create()" method manually
	CREATE_FUNC(InGameInterface);
};