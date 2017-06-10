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

	void dealloc();		// ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )

public:
	CEnemy* getEnemyList() { return *m_pEnemyList; }
};

/*
class CEnemyManager
{
private:
	Object_Alliance* m_pAllianceList[MAX_ENEMY];
public:
	void init();	// ���� �ʱ�ȭ �Լ�
	void setScene(Layer* _curScene);	//�̹��� ���� , ������ ����, ��ǥ ����, ���̾ add
	void action(float _dt);

	void createSwordAlliance(); // Į�� ���� ��ȯ
	void createNinJaMaleAlliance();
	void createNinJaFemaleAlliance();

	void dealloc();		// ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )
};
*/