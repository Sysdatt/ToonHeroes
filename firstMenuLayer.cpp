#include "firstMenuLayer.h"

bool firstMenuLayer::init()
{

	if (!Layer::init()) return false;

	ToonHeroesLabel = Label::createWithTTF("Toon Heroes", "THESusu.ttf", 34);
	ToonHeroesLabel->setColor(Color3B(255, 178, 245));
	ToonHeroesLabel->setAnchorPoint(Point(0, 0));
	ToonHeroesLabel->setScale(5.f);
	ToonHeroesLabel->setPosition(Point(180, 450)); // 180,450
	this->addChild(ToonHeroesLabel);

	m_StartButton = Sprite::create("StartButton.png");
	m_StartButton->setAnchorPoint(Point(0, 0));
	m_StartButton->setScale(1.2f);
	m_StartButton->setScaleX(1.5f);
	m_StartButton->setPosition(Point(380, 250)); // 380,250
	this->addChild(m_StartButton);

	StartLabel = Label::createWithTTF("Start", "THESusu.ttf", 34);
	StartLabel->setScale(1.5f);
	StartLabel->setScaleX(3.f);
	StartLabel->setPosition(Point(525, 305)); // 525,305
	this->addChild(StartLabel);

	m_ExitButton = Sprite::create("ExitButton.png");
	m_ExitButton->setAnchorPoint(Point(0, 0));
	m_ExitButton->setScale(1.2f);
	m_ExitButton->setScaleX(1.5f);
	m_ExitButton->setPosition(Point(380, 135)); // 380,135
	this->addChild(m_ExitButton);


	ExitLabel = Label::createWithTTF("Exit", "THESusu.ttf", 34);
	ExitLabel->setScale(1.5f);
	ExitLabel->setScaleX(3.f);
	ExitLabel->setPosition(Point(525, 190)); // 525,190
	this->addChild(ExitLabel);

	return true;
}