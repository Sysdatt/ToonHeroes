#pragma once
#include "Object_Alliance.h"


#define MAX_ALLIANCE	150

class AllianceManager
{
private:
	Object_Alliance* m_pAllianceList[MAX_ALLIANCE];
public:
	void init();	// 원점 초기화 함수
	void setScene(Layer* _curScene);	//이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
	void action(float _dt);

	void createSwordAlliance(); // 칼든 동료 소환
	void createNinJaMaleAlliance();
	void createNinJaFemaleAlliance();

	Object_Alliance** getAllianceList() { return m_pAllianceList; }
	void CollisionCheckWithEnemy(Object_Alliance* _alliance);

	void dealloc();		// 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )
};