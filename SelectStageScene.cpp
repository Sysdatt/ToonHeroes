#include "SelectStageScene.h"
#include "MenuScene.h"
#include "FirstStageScene.h"

Scene* SelectStageScene::createScene()
{
	Scene* pScene = Scene::create();
	SelectStageScene* mainLayer = SelectStageScene::create();
	pScene->addChild(mainLayer);

	return pScene;
}

bool SelectStageScene::init()
{
	if (!Layer::init()) return false;


	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(SelectStageScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	m_stageBackGround = Sprite::create("MainMenuBackGround.jpg");
	m_stageBackGround->setAnchorPoint(Point(0, 0));
	m_stageBackGround->setScaleX(2.56f);
	m_stageBackGround->setScaleY(2.75f);
	m_stageBackGround->setPosition(Point(0, 0));
	this->addChild(m_stageBackGround);

	returnToThird = Sprite::create("returnButton.png");
	returnToThird->setAnchorPoint(Point(0, 0));
	returnToThird->setPosition(Point(940, 680));	//940, 680
	this->addChild(returnToThird);

	StageSelectLabel = Label::createWithTTF("Stage Select","THESusu.ttf",34);
	StageSelectLabel->setAnchorPoint(Point(0, 0));
	StageSelectLabel->setScale(4.f);
	StageSelectLabel->setColor(Color3B(0, 0, 255));
	StageSelectLabel->setPosition(250, 640);
	this->addChild(StageSelectLabel);

	if (Core::sharedManager()->m_iMaxStage == 1)
	{
		StageSprite1 = Sprite::create("StageButton.png");
		StageLabel1 = Label::createWithTTF("1", "THESusu.ttf", 34);
		StageSprite2 = Sprite::create("BlockStage.png");
		StageLabel2 = NULL;
		StageSprite3 = Sprite::create("BlockStage.png");
		StageLabel3 = NULL;
	}

	else if (Core::sharedManager()->m_iMaxStage == 2)
	{
		StageSprite1 = Sprite::create("StageButton.png");
		StageLabel1 = Label::createWithTTF("1", "THESusu.ttf", 34);
		StageSprite2 = Sprite::create("StageButton.png");
		StageLabel2 = Label::createWithTTF("2", "THESusu.ttf", 34);
		StageSprite3 = Sprite::create("BlockStage.png");
		StageLabel3 = NULL;
	}

	else if (Core::sharedManager()->m_iMaxStage == 3)
	{
		StageSprite1 = Sprite::create("StageButton.png");
		StageLabel1 = Label::createWithTTF("1", "THESusu.ttf", 34);
		StageSprite2 = Sprite::create("StageButton.png");
		StageLabel2 = Label::createWithTTF("2", "THESusu.ttf", 34);
		StageSprite3 = Sprite::create("StageButton.png");
		StageLabel3 = Label::createWithTTF("3", "THESusu.ttf", 34);
	}

	StageSprite1->setAnchorPoint(Point(0, 0));
	StageSprite1->setPosition(Point(300, 500));
	this->addChild(StageSprite1);

	StageSprite2->setAnchorPoint(Point(0, 0));
	StageSprite2->setPosition(Point(500, 500));
	this->addChild(StageSprite2);

	StageSprite3->setAnchorPoint(Point(0, 0));
	StageSprite3->setPosition(Point(700, 500));
	this->addChild(StageSprite3);

	StageLabel1->setScale(2.f);
	StageLabel1->setAnchorPoint(Point(0, 0));
	StageLabel1->setPosition(Point(35, 10));
	StageSprite1->addChild(StageLabel1);



	if (StageLabel2 != NULL)
	{
		StageLabel2->setScale(2.f);
		StageLabel2->setAnchorPoint(Point(0, 0));
		StageLabel2->setPosition(Point(25, 10));
		StageSprite2->addChild(StageLabel2);
	}
	if (StageLabel3 != NULL)
	{
		StageLabel3->setScale(2.f);
		StageLabel3->setAnchorPoint(Point(0, 0));
		StageLabel3->setPosition(Point(25, 10));
		StageSprite3->addChild(StageLabel3);
	}

	return true;
}

void SelectStageScene::onMouseDown(Event* event)	// 마우스 움직임 좌표
{
	EventMouse* e = (EventMouse*)event;
	float mx = e->getCursorX();
	float my = e->getCursorY();


	if (mx >= 307 && mx <= 376 && my <= -195 && my >= -255)
	{
		Director::getInstance()->replaceScene(FirstStageScene::createScene());
	}

	else if (mx >= 507 && mx <= 576 && my <= -195 && my >= -255 && StageLabel2 != NULL)
	{
		// 스테이지 씬 2로 넘기기
	}

	else if (mx >= 707 && mx <= 776 && my <= -195 && my >= -255 && StageLabel3 != NULL)
	{
		// 스테이지 씬3로 넘기기
	}

	else if (mx >= 948 && mx <= 1016 && my <= -10 && my >= -73)
	{
		Core::sharedManager()->CurMenu = 1;
		Director::getInstance()->replaceScene(MenuScene::createScene());
	}
}