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
const double PokestopMinSpeed = 200;
/// Maximum speed of a pokestop
const double PokestopMaxSpeed = 300;
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
}

/// Destructor
CPokeStop::~CPokeStop()
{
}

void CPokeStop::Update(double elapsed)
{
	mClickTime += elapsed;
	mLifespan += elapsed;
}
