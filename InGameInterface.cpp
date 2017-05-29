#include "InGameInterface.h"
#include "Core.h"


bool InGameInterface::init()
{

	if (!Layer::init()) return false;

	m_CurPlayerHp = Sprite::create("PlayerHp.png");
	m_CurPlayerHp->setAnchorPoint(Point(0, 0));
	m_CurPlayerHp->setPosition(Point(3, 725));
	this->addChild(m_CurPlayerHp);

	m_PlayerHpBar = Sprite::create("HpBar.png");
	m_PlayerHpBar->setAnchorPoint(Point(0, 0));
	m_PlayerHpBar->setScale(1.4f);
	m_PlayerHpBar->setPosition(Point(0, 725));
	this->addChild(m_PlayerHpBar);

	m_CurEnemyHp = Sprite::create("EnemyHp.png");
	m_CurEnemyHp->setAnchorPoint(Point(0, 0));
	m_CurEnemyHp->setPosition(Point(581, 725));
	this->addChild(m_CurEnemyHp);

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

	this->schedule(schedule_selector(InGameInterface::tick));

	return true;
}

void InGameInterface::tick(float _dt)
{
	//for(int i = 0 ; i < Core::sharedManager()->플레이어 타워의 체력;i++)
	//{
	// 파란색 스프라이트 출력 (풀로 출력했을땐 HP바가 가득 차게
	//}
	//for(int i = 0 ; i < Core::sharedManager()->적 타워의 체력; i++)
	//{
	// 빨간색 스프라이트 출력 (풀로 출력했을땐 HP바가 가득 차게
	//}
}