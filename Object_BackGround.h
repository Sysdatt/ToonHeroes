#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Object_BackGround : public Sprite
{
private:

	Sprite* m_pBackImage;
public:
	virtual bool init();
};