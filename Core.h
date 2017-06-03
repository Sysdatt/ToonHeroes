#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#include "TowerManager.h"
#include "AllianceManager.h"
#include "InGameInterface.h"


enum TOWER_TAG {	// 타워의 태그 값
	P_TOWER, E_TOWER
};

enum OBJECT_TAG {
	PLAYER, ENEMY
};

enum OBJECT_STATE {
	IDLE, WALK , ATTACK
};
enum DIRECTION {
	LEFT, RIGHT
};

enum PLAYER_ALLIANCE {
	SWORD, F_NINJA, M_NINJA
};

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
	int m_iStage; //현재 스테이지
	bool isKeyDown;  // 현재 키가 눌렸나? ( 테스트 용 ) 객체 만들 때
	bool InterfaceIsFlag; // 인터페이스 체력바를 컨트롤 하기위한 플래그
	Point PlayerStartPos; // 플레이어 동료 객체 시작 위치
	EventListenerMouse* Mouse;
	InGameInterface* IM; //인터페이스 매니저
	float m_iMP; // 객체 생성시 사용하는 MP

	// 매니저 선언

	TowerManager TM;	// 타워 객체들 세팅 및 관리
	AllianceManager AM;	// 플레이어 동료 객체들 세팅 및 관리
};