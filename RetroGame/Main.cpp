#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "Scene.h"
#include "GameInfo.h"
using namespace olc;

//typedef std::chrono::steady_clock::time_point Time;
//typedef std::chrono::high_resolution_clock HiResClock;
//typedef std::chrono::duration<float> TimeDiff;

int main()
{

	//float fElpasedTime = 0.0f;
	

	// Entry point for our game
	Scene retroGameScene; 
	if (retroGameScene.Construct(300, 240, 4, 4))
	{
		retroGameScene.Start();

	}

	return 0;
}