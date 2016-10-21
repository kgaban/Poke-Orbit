/**
* \file PokeBall.cpp
*
* \author Marc VandenBerg
*
* Implementation of our PokeBall class
*/




#include "stdafx.h"
#include "PokeBall.h"

#include <string>

using namespace Gdiplus;
using namespace std;

/// Set the image for the pokeball
const wstring filename = L"images/pokeball.png";
/**
* Constructor
* \param pokeOrbit The poke orbit app to add the object to
* \param x The speed in the x direction of the pokeball
* \param y The speed in the y direction of the pokeball
* \param filename The name of the file
*/
CPokeBall::CPokeBall(CPokeOrbitApp *pokeOrbit, double x, double y) : CGameObject(pokeOrbit, filename)
{
	mSpeedX = x;
	mSpeedY = y;

}

/// Destructor
CPokeBall::~CPokeBall()
{
}


/**
* Updates the current position of the pokeball
* \param elapsed The elapsed time
*/
void CPokeBall::Update(double elapsed)
{
	mX += mSpeedX * elapsed;
	mY += mSpeedY * elapsed;

	SetPosition(mX, mY);
}


