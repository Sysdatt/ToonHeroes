#include "Object_Tower.h"
#include "Core.h"

bool Object_Tower::init(int _tag)

{
	if (!Sprite::init()) return false;

	if (_tag == P_TOWER)
	{
		m_pTowerImage = Sprite::create("PlayerTower.png");
		m_pTowerImage->setAnchorPoint(Point(1, 0));  // �Ʊ� Ÿ���� ���ʿ� ��� �Ǳ� ������.
		m_iObjTag = PLAYER;
	}
	else if (_tag == E_TOWER)
	{
		m_pTowerImage = Sprite::create("EnemyTower.png");
		m_pTowerImage->setAnchorPoint(Point(0, 0)); // �� Ÿ���� �����ʿ� ��� �Ǳ� ������.
		m_iObjTag = ENEMY;
	}

	m_iTag = _tag;
	m_iHp = 30;
	m_bLiveFlag = true;

	this->addChild(m_pTowerImage);

	return true;
}