#include "Object_Tower.h"
#include "Core.h"

bool Object_Tower::init(int _tag)

{
	if (!Sprite::init()) return false;

	if (_tag == P_TOWER)
	{
		m_pTowerImage = Sprite::create("PlayerTower.png");
		m_pTowerImage->setAnchorPoint(Point(1, 0));  // 아군 타워는 왼쪽에 출력 되기 때문임.
	}
	else if (_tag == E_TOWER)
	{
		m_pTowerImage = Sprite::create("EnemyTower.png");
		m_pTowerImage->setAnchorPoint(Point(0, 0)); // 적 타워는 오른쪽에 출력 되기 때문임.
	}
	
	m_iHp = 30;
	m_bLiveFlag = true;

	this->addChild(m_pTowerImage);

	return true;
}