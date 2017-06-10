#pragma once
#include "Enemy.h"
#include "content.h"

#define MAX_ENEMY	100


class CEnemyManager
{
private:
	CEnemy* m_pEnemyList[MAX_ENEMY];

public:
	CEnemyManager();
	~CEnemyManager();
	
public:
	void init();	// 원점 초기화 함수
	void setScene(Layer* _curScene);	//이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
	void action(float _dt);

	void createZombie_Fe();
	void createZombie_Male();

	void dealloc();		// 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )

public:
	CEnemy* getEnemyList() { return *m_pEnemyList; }
};

/*
class CEnemyManager
{
private:
	Object_Alliance* m_pAllianceList[MAX_ENEMY];
public:
	void init();	// 원점 초기화 함수
	void setScene(Layer* _curScene);	//이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
	void action(float _dt);

	void createSwordAlliance(); // 칼든 동료 소환
	void createNinJaMaleAlliance();
	void createNinJaFemaleAlliance();

	void dealloc();		// 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )
};
*/