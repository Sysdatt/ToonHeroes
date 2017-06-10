#pragma once
#include "Object_Tower.h"
#include "Object_Alliance.h"
#include "Enemy.h"
#define MAX_TOWER		2 // 적 , 플레이어

class TowerManager
{
private:
	Object_Tower* m_pTowerList[MAX_TOWER];
public:
	void init();	// 원점 초기화 함수
	void setScene(Layer* _curScene);	//이미지 설정 , 기준점 변경, 좌표 설정, 레이어에 add
	void dealloc();		// 동적 할당 풀기 ( 종료 시 or 스테이지 이동 시 시행 )
	Object_Tower* getPlayerTower() { return m_pTowerList[0]; }
	Object_Tower* getEnemyTower() { return m_pTowerList[1]; }

	Object_Tower* CollisionCheckAboutTower(Object_Alliance* _alliance);
	Object_Tower* CollisionCheckAboutTower_Enemy(CEnemy* _enemy);
};