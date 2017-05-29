#pragma once
#include "Core.h"

class InGameInterface : public Layer
{
public:
	Sprite* m_PlayerHpBar;
	Sprite* m_EnemyHpBar;
	Sprite* m_ChoiceInterface;

	Sprite* m_CurPlayerHp;
	Sprite* m_CurEnemyHp;

	Sprite* m_SwordMenu;
	Sprite* m_F_NinjaMenu;
	Sprite* m_M_NinjaMenu;

public:

	virtual bool init();
	void tick(float _dt);

	// implement the "static create()" method manually
	CREATE_FUNC(InGameInterface);
};