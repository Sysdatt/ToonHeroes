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
	void init();	// ���� �ʱ�ȭ �Լ�
	void setScene(Layer* _curScene);	//�̹��� ���� , ������ ����, ��ǥ ����, ���̾ add
	void action(float _dt);

	void createZombie_Fe();
	void createZombie_Male();

	void CollisionCheckWithAlliance(CEnemy* _enemy);

	void dealloc();		// ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )

public:
	CEnemy** getEnemyList() { return m_pEnemyList; }
};