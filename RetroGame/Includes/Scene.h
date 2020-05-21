#pragma once
#ifndef SCENE_H
#define SCENE_H

// Includes
#include "olcPixelGameEngine.h"


// Forward declarations
class Ship;
class Bullet;
class Asteroid;
class Asteroid2;

class Scene : public olc::PixelGameEngine
{
public:
	Scene();

	void ResetGame();

	bool OnUserCreate() override;
	//this function is called every frame so all our update logic for the game goes in here
	bool OnUserUpdate(float fElapsedTime) override;

	void ScreenWrap(float shipXpos, float shipYpos, float& newShipXpos, float& newShipYpos);
	

private:
	Ship* playerShip;
	Asteroid* aster;
	Asteroid2* aster2;

	int points = 0;
	
};

#endif //!SCENE_H
