#include "Core.h"

Core::Core() {
	m_iStage = 1; // 1�������� ���� ����
	m_iMaxStage = 1;
	CurMenu = 0; // ���θ޴� �ʱ� Start,Exit
	PlayerStartPos = Point(200, 168);
	EnemyStartPos = Point(1600, 168);
	isKeyDown = false;
	IM = NULL;
	firstTemp = NULL;
	secondTemp = NULL;
	thirdTemp = NULL;
}