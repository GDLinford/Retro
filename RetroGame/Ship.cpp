#define OLC_PGEX_GRAPHICS2D
#define _USE_MATH_DEFINES

// This file's header
#include "Ship.h"

// Includes
#include "Includes/Scene.h"
#include "olcPGEX_Graphics2D.h"
#include "GameInfo.h"
#include <math.h>
#include "Bullet.h"
// Namespaces
using namespace olc;

Ship::Ship()
{
	// Load our sprite

	//13/03/20 redo sprite so its a bit smaller
	sprIte = new Sprite("Resources/Asteroids ship2.png");

	// Set the position vector
	position = { 100.0f, 100.0f };
	rotation = 0.0f;
	forward = { 0.0f, -1.0f };
	acceleration = 0.0f;
	
}

Bullet::Bullet() 
{
	sprite = new  Sprite("Resources/Bullet.png");
}

void Ship::Update(Scene* pScene)
{  

	// Handle input

	//Go Forward
	if (pScene->GetKey(Key::W).bHeld)
	{
		acceleration += 0.001f;
	}

	else if (acceleration > 0.0001f) 
	{
		acceleration -= 0.01f;
	}

	//ROtation
	if (pScene->GetKey(Key::A).bHeld)
	{
		rotation += 0.01f;
	}

	else if (pScene->GetKey(Key::D).bHeld)
	{
		rotation -= 0.01f;
	}

	//if (pScene->GetKey(Key::S).bHeld)
	//{
	//	position.SetY(position.GetY() + 1.0f);
	//}

	if (pScene->GetKey(Key::SPACE).bHeld || pScene->GetKey(Key::SPACE).bPressed) 
	{
		//Fire Bullet

	}

}

void Ship::Draw(Scene* pScene)
{
	//Create a 2D Transform
	//Create a 2D Transform
	GFX2D::Transform2D playerTransform;

	//use Transform to create a rotation
	playerTransform.Translate(-(sprIte->width * 0.5f), -(sprIte->height * 0.5f));
	playerTransform.Rotate(rotation);

	//calculate forward
	float offSetRotation = rotation + (M_PI / 2);
	forward.SetX(cos(-offSetRotation));
	forward.SetY(sin(-offSetRotation));


	//Apply the forward and acceleration to our position
	position += (forward * acceleration);

	//perform translation
	playerTransform.Translate(position.GetX(), position.GetY());

	//Draw the sprite with our transform
	GFX2D::DrawSprite(sprIte, playerTransform);
}

