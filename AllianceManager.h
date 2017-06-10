#pragma once
#include "Object_Alliance.h"


#define MAX_ALLIANCE	150

class AllianceManager
{
private:
	Object_Alliance* m_pAllianceList[MAX_ALLIANCE];
public:
	void init();	// ���� �ʱ�ȭ �Լ�
	void setScene(Layer* _curScene);	//�̹��� ���� , ������ ����, ��ǥ ����, ���̾ add
	void action(float _dt);

	void createSwordAlliance(); // Į�� ���� ��ȯ
	void createNinJaMaleAlliance();
	void createNinJaFemaleAlliance();

	void dealloc();		// ���� �Ҵ� Ǯ�� ( ���� �� or �������� �̵� �� ���� )
};