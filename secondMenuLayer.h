#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class secondMenuLayer : public Layer
{
public:
	Sprite* m_GameModeButton;
	Sprite* m_shopButton;
	Sprite* returnToFirst;

	Label* GameModeLabel;
	Label* ShopLabel;
public:

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(secondMenuLayer);
};