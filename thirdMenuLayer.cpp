#include "thirdMenuLayer.h"

bool thirdMenuLayer::init()
{

	if (!Layer::init()) return false;

	CampaignButton = Sprite::create("ModeChoice.png");
	CampaignButton->setAnchorPoint(Point(0, 0));
	CampaignButton->setScale(2.5f);
	CampaignButton->setPosition(Point(250, 200));
	this->addChild(CampaignButton);

	PvPButton = Sprite::create("ModeChoice.png");
	PvPButton->setAnchorPoint(Point(0, 0));
	PvPButton->setScale(2.5f);
	PvPButton->setPosition(Point(520, 200));
	this->addChild(PvPButton);

	returnToSecond = Sprite::create("returnButton.png");
	returnToSecond->setAnchorPoint(Point(0, 0));
	returnToSecond->setPosition(Point(940, 680));	//940, 680
	this->addChild(returnToSecond);

	CampaignLabel = Label::createWithTTF("Campaign", "THESusu.ttf", 34);
	CampaignLabel->setAnchorPoint(Point(0, 0));
	CampaignLabel->setScaleX(2.f);
	CampaignLabel->setScaleY(3.f);
	CampaignLabel->setPosition(Point(275, 350));
	this->addChild(CampaignLabel);

	PvPLabel = Label::createWithTTF("PvP", "THESusu.ttf", 34);
	PvPLabel->setAnchorPoint(Point(0, 0));
	PvPLabel->setScaleX(4.5f);
	PvPLabel->setScaleY(3.f);
	PvPLabel->setPosition(Point(560, 350));
	this->addChild(PvPLabel);

	return true;
}