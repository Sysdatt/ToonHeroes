
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


enum TOWER_TAG {	// Ÿ���� �±� ��
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

public: // �̱��� ��� ����
	float m_fOriginX;  //Ⱦ��ũ�� ����� �� ���� ����. ����ó���� �� ��
					   // �������� �ٲ� �� ���� 0 ���� �ʱ�ȭ
	int m_iStage; //���� �������� (���������� �����ϸ� �� ���������� �����Ǿ� �� )
	int m_iMaxStage; // ���� ������ �ִ� �ƽ� ��������
	int CurMenu;
	bool isKeyDown;  // ���� Ű�� ���ȳ�? ( �׽�Ʈ �� ) ��ü ���� ��
	bool InterfaceIsFlag; // �������̽� ü�¹ٸ� ��Ʈ�� �ϱ����� �÷���
	Point PlayerStartPos; // �÷��̾� ���� ��ü ���� ��ġ
	Point EnemyStartPos;
	EventListenerMouse* Mouse;
	InGameInterface* IM; //�������̽� �Ŵ���
	firstMenuLayer* firstTemp;
	secondMenuLayer* secondTemp;
	thirdMenuLayer* thirdTemp;
	float m_iMP; // ��ü ������ ����ϴ� MP

				 // �Ŵ��� ����
	CEnemyManager EM;
	TowerManager TM;	// Ÿ�� ��ü�� ���� �� ����
	AllianceManager AM;	// �÷��̾� ���� ��ü�� ���� �� ����

};

