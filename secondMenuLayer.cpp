#include "secondMenuLayer.h"

bool secondMenuLayer::init()
{

	if (!Layer::init()) return false;

	m_GameModeButton = Sprite::create("ShopButton.png");
	m_GameModeButton->setAnchorPoint(Point(0, 0));
	m_GameModeButton->setScaleX(2.f);
	m_GameModeButton->setScaleY(2.5f);
	m_GameModeButton->setPosition(Point(330, 300)); // 330, 370
	this->addChild(m_GameModeButton);

	m_shopButton = Sprite::create("ShopButton.png");
	m_shopButton->setAnchorPoint(Point(0, 0));
	m_shopButton->setScaleX(2.f);
	m_shopButton->setScaleY(1.5f);
	m_shopButton->setPosition(Point(330, 150));	//330, 150
	this->addChild(m_shopButton);

	returnToFirst = Sprite::create("returnButton.png");
	returnToFirst->setAnchorPoint(Point(0, 0));
	returnToFirst->setPosition(Point(940, 680));	//940, 680
	this->addChild(returnToFirst);

	GameModeLabel = Label::createWithTTF("GameMode", "THESusu.ttf", 34);
	GameModeLabel->setAnchorPoint(Point(0, 0));
	GameModeLabel->setScaleY(2.f);
	GameModeLabel->setScaleX(3.f);
	GameModeLabel->setPosition(Point(350, 370));	//350,370
	this->addChild(GameModeLabel);

	ShopLabel = Label::createWithTTF("Shop", "THESusu.ttf", 34);
	ShopLabel->setAnchorPoint(Point(0, 0));
	ShopLabel->setScaleY(2.f);
	ShopLabel->setScaleX(3.f);
	ShopLabel->setPosition(Point(450, 190));	//450, 190
	this->addChild(ShopLabel);

	return true;
}