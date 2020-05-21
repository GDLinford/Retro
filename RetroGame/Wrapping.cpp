#include "Scene.h"

//when anything that uses this code goes off screen it will reappear on the other 
//side directly opposite to where it went off
void Scene::ScreenWrap(float shipXpos, float shipYpos, float& newShipXpos, float& newShipYpos)
{
	newShipXpos = shipXpos;
	newShipYpos = shipYpos;

	if (shipXpos < 0.0f)
	{
		newShipXpos = shipXpos + ScreenWidth();
	}
	if (shipXpos >= ScreenWidth())
	{
		newShipXpos = shipXpos - ScreenWidth();
	}
	if (shipYpos < 0.0f)
	{
		newShipYpos = shipYpos + ScreenHeight();
	}
	if (shipYpos >= ScreenHeight())
	{
		newShipYpos = shipYpos - ScreenHeight();
	}
}