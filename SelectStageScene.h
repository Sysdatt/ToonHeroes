#pragma once
#include "Core.h"

class SelectStageScene : public Layer
{
public:
	EventListenerMouse* Mouse;

public:
	static Scene* createScene();

	virtual bool init();
	void onMouseDown(Event* event);


	// implement the "static create()" method manually
	CREATE_FUNC(SelectStageScene);
};