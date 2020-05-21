#include "Asteroid.h"
#include "Scene.h"
#include "GameInfo.h"
#include "olcPGEX_Graphics2D.h"


using namespace olc;


Asteroid::Asteroid() 
{
	asprite = new Sprite("Resources/Asteroid Big.png");
	aposition = { 100.0f, 60.0f };
	direction = { 0.0f, -1.0f };
	speed = 0.0f;
	a1x = 0;
	a1y = 0;
}


Asteroid2::Asteroid2()
{
	asprite2 = new Sprite("Resources/Asteroid small.png");
	aposition2 = { 50.0f, 50.0f };
	direction = { 0.0f, -1.0f };
	speed = 0.0f;
}

//Asteroid3::Asteroid() 
//{
//
//}

void Asteroid::UpdateA(Scene* AScene)
{

	a1x += 0.001f;
	a1y += 0.001f;

}

void Asteroid2::UpdateA(Scene* Ascene) 
{

}

void Asteroid::DrawA(Scene* AScene) 
{
	GFX2D::Transform2D AsteroidT;

	GFX2D::DrawSprite(asprite, AsteroidT);
}

void Asteroid2::DrawA(Scene* Ascene) 
{
	GFX2D::Transform2D AsteroidT;

	GFX2D::DrawSprite(asprite2, AsteroidT);
}

//bool Asteroid::isDestroyed() 
//{
//
//}