
#pragma once
#include "Core.h"
#include "Object_BackGround.h"

class FirstStageScene : public Layer
{
public:
	float m_fMoveSpeed; // Ⱦ��ũ�� ��, ���Ǵ� ����.   ���̾� ������ ���ǵ�

						// ��ü
	Object_BackGround* m_pBackGround;
	EventListenerMouse* Mouse;

public:
	static Scene* createScene();

	virtual bool init();
	void tick(float _dt);
	void PlusTickMp(float _dt);
	void onMouseDown(Event* event);
	void delayTime(float _dt);

	// implement the "static create()" method manually
	CREATE_FUNC(FirstStageScene);
};