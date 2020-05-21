// Includes
#include <string>
#include <iostream>
#include "Scene.h"
#include "Ship.h"
#include "GameInfo.h"
#include "Vector3D.h"
#include "Asteroid.h"

#include "Vector3D.h"


using namespace std;


float fElpasedTime = 0.0f;


Scene::Scene()
{
	sAppName = "Asteroids";
}

// Called once at the start, so create things here
bool Scene::OnUserCreate()
{

	//DrawString(2, 2, "SCORE: ");

	// Create a new instance of the ship/Asteroids
	playerShip = new Ship();
	aster = new Asteroid();
	aster2 = new Asteroid2();



	return true;
}



// Called once per frame
bool Scene::OnUserUpdate(float fElapsedTime)
{	
	//ClearScreen
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(0, 0, 0));
	// UPDATE
	/////////////////////////////

	// Should we quit?
	if (GetKey(olc::Key::ESCAPE).bPressed)
	{
		return false;
	}

	if (GetKey(olc::Key::DEL).bPressed) 
	{
		ResetGame();
	}

	//if (Ship::Dead) 
	//{
	//	ResetGame();
	//}

	///////////////////// SCREEN WRAPS//////////////////

	//Ship Screen Wrap
	Vector2D currentPos = playerShip->GetPosition();
	float newX;
	float newY;

	//gets the current position and changes it to the new position
	//when the object, the ship in this case, goes out of the bounds
	//of the screenHeight and Width
	ScreenWrap(currentPos.GetX(), currentPos.GetY(), newX, newY);

	Vector2D newPos(newX, newY);
	playerShip->SetPosition(newPos);
	//Ship Screen Wrap End

	//Asteroird 1 screenWrap
	Vector2D currentA1Pos = aster->GetPosition();
	float newAX;
	float newAY;

	ScreenWrap(currentA1Pos.GetX(), currentA1Pos.GetY(), newAX, newAY);

	Vector2D newAPos(newAX, newAY);
	aster->SetPosition(newAPos);
	//Asteroid 1 Screen Wrap End

	//////////////////// SCREEN WRAPS END ///////////////////////

	// Update our player ship
	playerShip->Update(this);
	aster->UpdateA(this);
	aster2->UpdateA(this);
	
	if (aster && aster2 )


	// DRAW
	/////////////////////////////

	// Clear the previous frame
	Clear(olc::Pixel());

	// Enables alpha blending
	SetPixelMode(olc::Pixel::ALPHA);

	// Draw our player ship
	playerShip->Draw(this);
	aster->DrawA(this);
	aster2->DrawA(this);

	return true;
}




void Scene::ResetGame() 
{
	//playerShip = new Ship();

	//points = false;

	//make sure the angle is reset

	//clear the bullets and asteroids

}
