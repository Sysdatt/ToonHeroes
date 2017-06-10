#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class thirdMenuLayer : public Layer
{
public:
	Sprite* CampaignButton;
	Sprite* PvPButton;
	Sprite* returnToSecond;

	Label* CampaignLabel;
	Label* PvPLabel;
public:

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(thirdMenuLayer);
};