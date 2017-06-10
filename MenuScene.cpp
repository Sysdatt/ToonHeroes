#include "MenuScene.h"
#include "SelectStageScene.h"

Scene* MenuScene::createScene()
{
	Scene* pScene = Scene::create();
	MenuScene* mainLayer = MenuScene::create();
	firstMenuLayer* firstLayer = firstMenuLayer::create();
	Core::sharedManager()->firstTemp = firstLayer;
	secondMenuLayer* secondLayer = secondMenuLayer::create();
	Core::sharedManager()->secondTemp = secondLayer;
	thirdMenuLayer* thirdLayer = thirdMenuLayer::create();
	Core::sharedManager()->thirdTemp = thirdLayer;

	pScene->addChild(mainLayer);
	pScene->addChild(firstLayer);
	pScene->addChild(secondLayer);
	pScene->addChild(thirdLayer);

	return pScene;
}

bool MenuScene::init()
{
	if (!Layer::init()) return false;
	m_backGroundSpr = Sprite::create("MainMenuBackGround.jpg");
	m_backGroundSpr->setAnchorPoint(Point(0, 0));
	m_backGroundSpr->setScaleX(2.56f);
	m_backGroundSpr->setScaleY(2.75f);
	m_backGroundSpr->setPosition(Point(0, 0));
	this->addChild(m_backGroundSpr);

	//마우스 이벤트 객체
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(MenuScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(MenuScene::tick));

	return true;
}

void MenuScene::tick(float dt)
{
	if (Core::sharedManager()->CurMenu == 0)
		callFirstLayer();
	else if (Core::sharedManager()->CurMenu == 1)
		callSecondLayer();
	else if (Core::sharedManager()->CurMenu == 2)
		callThirdLayer();
}

void MenuScene::callFirstLayer()
{
	Core::sharedManager()->CurMenu = 0;
	Core::sharedManager()->firstTemp->setPosition(Point(0, 0));
	Core::sharedManager()->secondTemp->setPosition(Point(10000, 10000));
	Core::sharedManager()->thirdTemp->setPosition(Point(10000, 10000));
}

void MenuScene::callSecondLayer()
{
	Core::sharedManager()->CurMenu = 1;
	Core::sharedManager()->firstTemp->setPosition(Point(10000, 10000));
	Core::sharedManager()->secondTemp->setPosition(Point(0, 0));
	Core::sharedManager()->thirdTemp->setPosition(Point(10000, 10000));
}

void MenuScene::callThirdLayer()
{
	Core::sharedManager()->CurMenu = 2;
	Core::sharedManager()->firstTemp->setPosition(Point(10000, 10000));
	Core::sharedManager()->secondTemp->setPosition(Point(10000, 10000));
	Core::sharedManager()->thirdTemp->setPosition(Point(0, 0));		
}

void MenuScene::onMouseDown(Event* event)	// 마우스 움직임 좌표
{
	EventMouse* e = (EventMouse*)event;
	float mx = e->getCursorX();
	float my = e->getCursorY();

	if (Core::sharedManager()->CurMenu == 0)
	{
		if (mx >= 391 && mx <= 664 && my <= -429 && my >= -506)
		{
			Core::sharedManager()->CurMenu = 1;
		}
		
		else if (mx >= 391 && mx <= 664 && my <= -542 && my >= -617)
		{
			Director::getInstance()->end(); // exit 버튼 누르면 프로젝트 종료
		}
	}
	else if (Core::sharedManager()->CurMenu == 1)
	{
		if (mx >= 343 && mx <= 710 && my <= -272 && my >= -449)
		{
			Core::sharedManager()->CurMenu = 2;
			// Start 눌렀을 때
		}
		else if (mx >= 948 && mx <= 1016 && my <= -10 && my >= -73)
		{
			Core::sharedManager()->CurMenu = 0;
		}
		
	}
	else if (Core::sharedManager()->CurMenu == 2)
	{
		if (mx >= 260 && mx <= 499 && my <= -184 && my >= -554)
		{
			Director::getInstance()->replaceScene(SelectStageScene::createScene());
		}
		else if (mx >= 533 && mx <= 766 && my <= -182 && my >= -548)
		{
			// pvp눌렀을 때
		}
		else if (mx >= 948 && mx <= 1016 && my <= -10 && my >= -73)
		{
			Core::sharedManager()->CurMenu = 1;
		}
	}
}