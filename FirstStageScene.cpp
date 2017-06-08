#include "FirstStageScene.h"
#include "InGameInterface.h"
#include "Core.h"

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
	if( !Layer::init() ) return false;

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
void FirstStageScene::tick(float _dt)
{
	 Point layerPos = this->getPosition();

	if (GetAsyncKeyState(VK_RIGHT) && Core::sharedManager()->m_fOriginX >= -1024.f)
	{
		layerPos.x -= m_fMoveSpeed * _dt;
		Core::sharedManager()->m_fOriginX -= m_fMoveSpeed * _dt;
	}

	if (GetAsyncKeyState(VK_LEFT) && Core::sharedManager()->m_fOriginX < 0.f)
	{
		layerPos.x += m_fMoveSpeed * _dt;
		Core::sharedManager()->m_fOriginX += m_fMoveSpeed * _dt;
	}

	Core::sharedManager()->AM.action(_dt);

	this->setPosition(layerPos);
}

void FirstStageScene::onMouseDown(Event* event)	// 마우스 움직임 좌표
{
	EventMouse* e = (EventMouse*)event;
	float mx = e->getCursorX();
	float my = e->getCursorY();

	if (my <= -676 && my >= -760 && mx >= 24 && mx <= 115) //가로 91 세로 84
	{
		Core::sharedManager()->AM.createSwordAlliance();
	}
	else if (my <= -676 && my >= -760 && mx >= 167 && mx <= 258)
	{
		Core::sharedManager()->AM.createNinJaMaleAlliance();
	}
	else if (my <= -676 && my >= -760 && mx >= 310 && mx <= 401)
	{
		Core::sharedManager()->AM.createNinJaFemaleAlliance();
	}
}