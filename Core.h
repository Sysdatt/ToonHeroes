
#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#include "TowerManager.h"
#include "AllianceManager.h"
#include "InGameInterface.h"

#include "EnemyManager.h"
#include "Enemy.h"
#include "firstMenuLayer.h"
#include "secondMenuLayer.h"
#include "thirdMenuLayer.h"
#include "SelectStageScene.h"

#define MAX_ENEMY	100


enum TOWER_TAG {	// 타워의 태그 값
	P_TOWER, E_TOWER
};

enum OBJECT_TAG {
	PLAYER, ENEMY
};

enum OBJECT_STATE {
	IDLE, WALK, ATTACK, DEAD
};
enum DIRECTION {
	LEFT, RIGHT
};

enum PLAYER_ALLIANCE {
	SWORD, F_NINJA, M_NINJA
};
/*
enum ENEMY_TAG {
	MALE, FEMALE
};
*/
class Core
{
private:
	Core();
	~Core() { delete instance; }

public:
	static Core* instance;
	static Core* sharedManager()
	{
		if (instance == NULL) instance = new Core;
		return instance;
	}

public: // 싱글톤 멤버 선언
	float m_fOriginX;  //횡스크롤 사용할 때 기존 영점. 예외처리할 때 씀
					   // 스테이지 바뀔 때 마다 0 으로 초기화
	int m_iStage; //현재 스테이지 (스테이지를 선택하면 그 스테이지로 설정되야 함 )
	int m_iMaxStage; // 내가 가지고 있는 맥스 스테이지
	int CurMenu;
	bool isKeyDown;  // 현재 키가 눌렸나? ( 테스트 용 ) 객체 만들 때
	bool InterfaceIsFlag; // 인터페이스 체력바를 컨트롤 하기위한 플래그
	Point PlayerStartPos; // 플레이어 동료 객체 시작 위치
	Point EnemyStartPos;
	EventListenerMouse* Mouse;
	InGameInterface* IM; //인터페이스 매니저
	firstMenuLayer* firstTemp;
	secondMenuLayer* secondTemp;
	thirdMenuLayer* thirdTemp;
	float m_iMP; // 객체 생성시 사용하는 MP

				 // 매니저 선언
	CEnemyManager EM;
	TowerManager TM;	// 타워 객체들 세팅 및 관리
	AllianceManager AM;	// 플레이어 동료 객체들 세팅 및 관리

};

