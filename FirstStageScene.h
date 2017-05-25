#pragma once
#include "Core.h"
#include "Object_BackGround.h"

class FirstStageScene : public Layer
{
public:
	float m_fMoveSpeed; // 횡스크롤 시, 사용되는 변수.   레이어 움직임 스피드


	// 객체
	Object_BackGround* m_pBackGround;

public:
	static Scene* createScene();

	virtual bool init();
	void tick(float _dt);

	// implement the "static create()" method manually
	CREATE_FUNC(FirstStageScene);
};