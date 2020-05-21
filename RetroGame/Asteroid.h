#ifndef ASTEROID_H
#define ASTEROID_H

#include "olcPixelGameEngine.h"
#include "Vector2D.h"
#include "Ship.h"

class Scene;

class Asteroid
{
public:
	Asteroid();
	~Asteroid() {};

	// Getters / Setters
	olc::Sprite* GetSprite() { return asprite; }
	Vector2D& GetPosition() { return aposition; }
	void SetSprite(olc::Sprite* as_sprite) { asprite = as_sprite; }
	void SetPosition(Vector2D as_position) { aposition = as_position; }

	void UpdateA(Scene* AScene);
	void DrawA(Scene* AScene);

	//Asteroid X and Y
	float a1x;
	float a1y;

	//bool isDestroyed();

private:
	// Variables

	//Sprites
	olc::Sprite* asprite;
	
	//Vector 2Ds
	Vector2D aposition;
	Vector2D direction;

	float speed;
};

///////// MAKE A NEW ASTEROID CLASS AND HAVE IT USE THE CURRENT ATEROID CLASS
///////// CLASS ASTEROID 

class Asteroid2 : Asteroid {

public:
	Asteroid2();
	~Asteroid2() {};

	olc::Sprite* GetSpite2() { return asprite2; }
	Vector2D& GetPosition2() { return aposition2; }
	void SetSprite2(olc::Sprite* as_sprite2) { asprite2 = as_sprite2; }
	void SetPosition2(Vector2D as_position2) { aposition2 = as_position2; }

	void UpdateA(Scene* AScene);
	void DrawA(Scene* AScene);

private :

	olc::Sprite* asprite2;
	Vector2D aposition2;
	Vector2D direction;
	float speed;

};

#endif // !ASTEROID_H