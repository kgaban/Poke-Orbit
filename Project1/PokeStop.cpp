/**
* \file PokeStop.h
*
* \author Marc VandenBerg
*
* Class to implement pokestops in our game
*/



#include "stdafx.h"
#include "PokeStop.h"

#include <string>

using namespace std;

/// Minimum speed of a pokestop
const double PokestopMinSpeed = 0.3;
/// Maximum speed of a pokestop
const double PokestopMaxSpeed = 0.7;
/// Pokestop filename
const wstring PokestopImageName(L"images/pokestop.png");
/// Used pokestop filename
const wstring UsedPokestopImageName(L"images/pokestop-used.png");


/** Constructor
* \param pokeOrbit The pokeorbit app this pokestop belongs to
* \param x The x position of the pokestop
* \param y The y position of the pokestop
*/
CPokeStop::CPokeStop(CPokeOrbitApp * pokeOrbit, int x, int y)
	: CGameObject(pokeOrbit, x, y, PokestopImageName)
{
	SetPosition(x, y);
	double factor = (double)rand() / RAND_MAX;
	mSpeed = PokestopMinSpeed + factor*(PokestopMaxSpeed - PokestopMinSpeed);
}

/// Destructor
CPokeStop::~CPokeStop()
{
}


/** Update the pokestop
* \param elapsed The time since the last update
*/
void CPokeStop::Update(double elapsed)
{
	mClickTime += elapsed;
	mLifespan += elapsed;

	double x = GetX();
	double y = GetY();

	double theta = atan(y / x);
	double c = (sqrt(pow(x, 2) + pow(y, 2)));
	theta -= mSpeed*elapsed;

	if (x < 0)
	{
		x = cos(theta) * -c;
		y = sin(theta) * -c;
	}
	else
	{
		x = cos(theta) * c;
		y = sin(theta) * c;
	}

	SetPosition(x, y);
}



/**
* Method to draw the pokeball on the game board
* \param graphics The drawing board
*/
void CPokeStop::Draw(Gdiplus::Graphics * graphics)
{
	CGameObject::Draw(graphics);
}


/// Update the clickable status of the pokestop
void CPokeStop::MakeClickable()
{
	if (!mAvailable && (mClickTime >= 15))
	{
		SetImage(PokestopImageName);
		mAvailable = true;
		mClickTime = 0;
	}
}

/** Return a value to either get the pokestop destroyed
* or keep it alive depending on its timer
* \return double The result to determine destruction
*/
double CPokeStop::GetDist()
{
	if (mLifespan > 60)
	{
		return 1000;
	}
	return 1;
}


/** Makes it so the pokestop has been used
*/
void CPokeStop::MakeNotClick()
{
	mAvailable = false;
	mClickTime = 0;
	SetImage(UsedPokestopImageName);
}

