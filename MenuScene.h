#pragma once
#include "Core.h"

class MenuScene : public Layer
{
public:
	EventListenerMouse* Mouse;

	Sprite* m_backGroundSpr;

public:
	static Scene* createScene();

	virtual bool init();
	void onMouseDown(Event* event);
	void callFirstLayer();
	void callSecondLayer();
	void callThirdLayer();
	void tick(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);
};