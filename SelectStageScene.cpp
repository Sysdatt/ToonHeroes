#include "SelectStageScene.h"

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

	return true;
}

void SelectStageScene::onMouseDown(Event* event)	// 마우스 움직임 좌표
{
	EventMouse* e = (EventMouse*)event;
	float mx = e->getCursorX();
	float my = e->getCursorY();

}