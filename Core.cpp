#include "Core.h"

Core::Core() {
	m_iStage = 1; // 1스테이지 부터 시작
	PlayerStartPos = Point(200, 168);
	isKeyDown = false;
	IM = NULL;
}