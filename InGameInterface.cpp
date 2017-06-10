#include "InGameInterface.h"
#include "Core.h"


bool InGameInterface::init()
{

	if (!Layer::init()) return false;

	m_CurPlayerHp = Sprite::create("PlayerHp.png");
	_progressPlayerHpBar = CCProgressTimer::create(m_CurPlayerHp);
	_progressPlayerHpBar->setAnchorPoint(Point(0, 0));
	_progressPlayerHpBar->setPosition(Point(3, 725));
	_progressPlayerHpBar->setMidpoint(Point(0, 0));
	_progressPlayerHpBar->setBarChangeRate(Point(1, 0));
	_progressPlayerHpBar->setType(kCCProgressTimerTypeBar);
	_progressPlayerHpBar->setPercentage(100.0f);
	this->addChild(_progressPlayerHpBar);

	m_PlayerHpBar = Sprite::create("HpBar.png");
	m_PlayerHpBar->setAnchorPoint(Point(0, 0));
	m_PlayerHpBar->setScale(1.4f);
	m_PlayerHpBar->setPosition(Point(0, 725));
	this->addChild(m_PlayerHpBar);

	m_CurEnemyHp = Sprite::create("EnemyHp.png");
	_progressEnemyHpBar = CCProgressTimer::create(m_CurEnemyHp);
	_progressEnemyHpBar->setAnchorPoint(Point(0, 0));
	_progressEnemyHpBar->setPosition(Point(581, 725));
	_progressEnemyHpBar->setMidpoint(Point(0, 0));
	_progressEnemyHpBar->setBarChangeRate(Point(1, 0));
	_progressEnemyHpBar->setType(kCCProgressTimerTypeBar);
	_progressEnemyHpBar->setPercentage(100.0f);
	this->addChild(_progressEnemyHpBar);

	m_EnemyHpBar = Sprite::create("HpBar.png");
	m_EnemyHpBar->setAnchorPoint(Point(0, 0));
	m_EnemyHpBar->setScale(1.4f);
	m_EnemyHpBar->setPosition(Point(578, 725));
	this->addChild(m_EnemyHpBar);

	m_ChoiceInterface = Sprite::create("ChoiceInterface.png");
	m_ChoiceInterface->setAnchorPoint(Point(0, 0));
	m_ChoiceInterface->setScaleX(1.29f);
	m_ChoiceInterface->setPosition(Point(0, 0));
	this->addChild(m_ChoiceInterface);

	m_CurMp = Sprite::create("Mp.png");
	_progressMpBar = CCProgressTimer::create(m_CurMp);
	_progressMpBar->setAnchorPoint(Point(0, 0));
	_progressMpBar->setPosition(Point(748,10));
	_progressMpBar->setMidpoint(Point(0, 0));
	_progressMpBar->setBarChangeRate(Point(1, 0));
	_progressMpBar->setType(kCCProgressTimerTypeBar);
	_progressMpBar->setPercentage(0.0f);
	this->addChild(_progressMpBar);


	m_SwordMenu = Sprite::create("Sword_Menu_Image.png");
	m_SwordMenu->setAnchorPoint(Point(0, 0));
	m_SwordMenu->setScale(0.2f);
	m_SwordMenu->setPosition(Point(35, 10));
	this->addChild(m_SwordMenu);

	m_M_NinjaMenu = Sprite::create("M_Ninja_MenuImage.png");
	m_M_NinjaMenu->setAnchorPoint(Point(0, 0));
	m_M_NinjaMenu->setScale(0.3f);
	m_M_NinjaMenu->setPosition(Point(178, 15));
	this->addChild(m_M_NinjaMenu);

	m_F_NinjaMenu = Sprite::create("F_Ninja_MenuImage.png");
	m_F_NinjaMenu->setAnchorPoint(Point(0, 0));
	m_F_NinjaMenu->setScale(0.3f);
	m_F_NinjaMenu->setPosition(Point(321, 15));
	this->addChild(m_F_NinjaMenu);

	isFlag = false;

	return true;
}

void InGameInterface::subTowerHp(int Tag)
{
	if (Tag == PLAYER)
	{
		float percentage = _progressEnemyHpBar->getPercentage();
		_progressEnemyHpBar->setPercentage(percentage - 3.33f);
	}
	else if (Tag == ENEMY)
	{
		float percentage = _progressPlayerHpBar->getPercentage();
		_progressPlayerHpBar->setPercentage(percentage - 3.33f);
	}
}

void InGameInterface::PlusMp(float _curMp)
{
	_progressMpBar->setPercentage(_curMp);
}