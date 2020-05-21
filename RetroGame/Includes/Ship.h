#ifndef SHIP_H
#define SHIP_H

// Includes
#include "olcPixelGameEngine.h"
#include "Vector2D.h"
#include "Matrix3x3.h"


// Forward declarations
class Scene;


class Ship 
{
public:
	// Constructor / Destructor
	Ship();
	~Ship() {}

	// Functions
	void Update(Scene* pScene);
	void Draw(Scene* pScene);

	// Getters / Setters
	olc::Sprite* GetSprite() { return sprIte; }
	Vector2D& GetPosition() { return position; }
	void SetSprite(olc::Sprite* a_sprite) { sprIte = a_sprite; }
	void SetPosition(Vector2D a_position) { position = a_position; }

	bool Dead = false;
	

private:
	// Variables
	olc::Sprite* sprIte;
	Vector2D position;
	Vector2D forward;
	float rotation;
	float acceleration;

	
	
};


#endif //!SHIP_H
