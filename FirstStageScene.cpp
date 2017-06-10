#include "FirstStageScene.h"
#include "InGameInterface.h"
#include "Core.h"
#include <time.h>
#include <stdio.h>
#include <windows.h>

//#define ONE_SECOND 5000
float timer = 0;
int sex=0;

Scene* FirstStageScene::createScene()
{
	Scene* pScene = Scene::create();
	FirstStageScene* mainLayer = FirstStageScene::create();
	InGameInterface* InterfaceLayer = InGameInterface::create();
	Core::sharedManager()->IM = InterfaceLayer; // 인터페이스 매니저에 생성한 인터페이스 포인터 전달
	pScene->addChild(mainLayer);
	pScene->addChild(InterfaceLayer);

	return pScene;
}

bool FirstStageScene::init()
{
	if (!Layer::init()) return false;

	m_fMoveSpeed = 300.0f;
	Core::sharedManager()->m_iMP = 0.f;
	Core::sharedManager()->m_fOriginX = 0.f; // 스크롤 기준 좌표
											 //마우스 이벤트 객체
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(FirstStageScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// 뒷 배경
	m_pBackGround = new Object_BackGround;
	m_pBackGround->init();
	m_pBackGround->setPosition(Point(0, 0));
	this->addChild(m_pBackGround);

	// 타워
	Core::sharedManager()->TM.setScene(this);

	// 동료 객체
	Core::sharedManager()->AM.setScene(this);
	// 적 객체
	Core::sharedManager()->EM.setScene(this);

	this->schedule(schedule_selector(FirstStageScene::tick));
	this->schedule(schedule_selector(FirstStageScene::PlusTickMp), 0.5f); // 0.5초마다 실행 시킴

	return true;
}

void FirstStageScene::PlusTickMp(float _dt)
{
	Core::sharedManager()->m_iMP += 1.f;
	if (Core::sharedManager()->m_iMP >= 100.0f)
		Core::sharedManager()->m_iMP = 100.0f;
	Core::sharedManager()->IM->PlusMp(Core::sharedManager()->m_iMP);
}

void FirstStageScene::delayTime(float _dt) {

	timer += _dt;
	if (timer>_dt*900) {
		if (sex == 1) {
			Core::sharedManager()->EM.createZombie_Fe();
			sex = 0;
		}
		else {
			Core::sharedManager()->EM.createZombie_Male();
			sex = 1;
		}
		timer = 0;
	}
}


void FirstStageScene::tick(float _dt)
{
	Point layerPos = this->getPosition();

	float delay = _dt;
	/*
	delay = delay + 1;
	if (delay > 1) {
		Core::sharedManager()->EM.createZombie_Fe();
		delay = 0;
	}*/
	delayTime(_dt);
	
	if (GetAsyncKeyState(VK_RIGHT) && Core::sharedManager()->m_fOriginX >= -1024.f)
	{
		layerPos.x -= m_fMoveSpeed * _dt;
		Core::sharedManager()->m_fOriginX -= m_fMoveSpeed * _dt;
//		delayTime();
	}

	if (GetAsyncKeyState(VK_LEFT) && Core::sharedManager()->m_fOriginX < 0.f)
	{
		layerPos.x += m_fMoveSpeed * _dt;
		Core::sharedManager()->m_fOriginX += m_fMoveSpeed * _dt;
	}
	

	Core::sharedManager()->AM.action(_dt);
	Core::sharedManager()->EM.action(_dt);
	this->setPosition(layerPos);
}
/*
void delayTime()
{
	int sex = 0;
	time = time + 10;
	if (time>=50) {
		Core::sharedManager()->EM.createZombie_Fe();
	}
}
*/
void FirstStageScene::onMouseDown(Event* event)	// 마우스 움직임 좌표
{
	EventMouse* e = (EventMouse*)event;
	float mx = e->getCursorX();
	float my = e->getCursorY();

	if (my <= -676 && my >= -760 && mx >= 24 && mx <= 115) //가로 91 세로 84
	{
		Core::sharedManager()->AM.createSwordAlliance();

		//Core::sharedManager()->EM.createZombie_Fe();

	}
	else if (my <= -676 && my >= -760 && mx >= 167 && mx <= 258)
	{
		Core::sharedManager()->AM.createNinJaMaleAlliance();

		//Core::sharedManager()->
	}
	else if (my <= -676 && my >= -760 && mx >= 310 && mx <= 401)
	{
		Core::sharedManager()->AM.createNinJaFemaleAlliance();
	}
}