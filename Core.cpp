#include "Core.h"

Core::Core() {
	m_iStage = 1; // 1스테이지 부터 시작
	m_iMaxStage = 1;
	CurMenu = 0; // 메인메뉴 초기 Start,Exit
	PlayerStartPos = Point(200, 168);
	EnemyStartPos = Point(1870, 168);
	isKeyDown = false;
	IM = NULL;
	firstTemp = NULL;
	secondTemp = NULL;
	thirdTemp = NULL;
}