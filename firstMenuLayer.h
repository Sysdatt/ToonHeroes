#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class firstMenuLayer : public Layer
{
public:
	Sprite* m_StartButton;
	Sprite* m_ExitButton;

	Label* StartLabel;
	Label* ExitLabel;
	Label* ToonHeroesLabel;
public:

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(firstMenuLayer);
};