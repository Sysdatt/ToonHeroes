#pragma once
#include "Core.h"

class SelectStageScene : public Layer
{
public:
	EventListenerMouse* Mouse;

	Sprite* m_stageBackGround;

	Label* StageSelectLabel;

	Sprite* StageSprite1;
	Label* StageLabel1;
	Sprite* StageSprite2;
	Label* StageLabel2;
	Sprite* StageSprite3;
	Label* StageLabel3;


	Sprite* returnToThird;



public:
	static Scene* createScene();

	virtual bool init();
	void onMouseDown(Event* event);

	// implement the "static create()" method manually
	CREATE_FUNC(SelectStageScene);
};