#pragma once

#include "olcPixelGameEngine.h"
#include <Ship.h>

class Bullet 
{

public:
	Bullet();
	~Bullet() {}

	olc::Sprite* GetSprite() { return sprite; }

private:
	olc::Sprite* sprite;
};