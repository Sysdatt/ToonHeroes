#pragma once
#include "Object_Tower.h"
#include "Object_Alliance.h"
<<<<<<< HEAD
#include "Enemy.h"
=======

>>>>>>> origin/master
#define MAX_TOWER		2 // �� , �÷��̾�

class TowerManager
{
private:
	Object_Tower* m_pTowerList[MAX_TOWER];
public:
	void init();	// ���� �ʱ�ȭ �Լ�
	void setScene(Layer* _curScene);	//�̹��� ���� , ������ ����, ��ǥ ����, ���̾ add
	void dealloc();		// ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )
	Object_Tower* getPlayerTower() { return m_pTowerList[0]; }
	Object_Tower* getEnemyTower() { return m_pTowerList[1]; }

	Object_Tower* CollisionCheckAboutTower(Object_Alliance* _alliance);
<<<<<<< HEAD
	Object_Tower* CollisionCheckAboutTower_Enemy(CEnemy* _enemy);
=======
>>>>>>> origin/master
};