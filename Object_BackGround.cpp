#include "Object_BackGround.h"
#include "Core.h"

bool Object_BackGround::init()
{
	if (!Sprite::init()) return false;
	if (Core::sharedManager()->m_iStage == 1)
	{
		m_pBackImage = Sprite::create("forest_bg1.png");
	}
	m_pBackImage->setAnchorPoint(Point(0, 0));
	this->addChild(m_pBackImage);

	return true;
}