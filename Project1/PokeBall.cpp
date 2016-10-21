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
const wstring Filename = L"images/pokeball.png";
///Initial position of pokeball
const double InitialPos = 0;
/**
* Constructor
* \param pokeOrbit The poke orbit app to add the object to
* \param x The speed in the x direction of the pokeball
* \param y The speed in the y direction of the pokeball
* \param filename The name of the file
*/
CPokeBall::CPokeBall(CPokeOrbitApp *pokeOrbit, double x, double y) : CImageObject(pokeOrbit, Filename)
{
	SetPosition(InitialPos,InitialPos);
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
	SetPosition(GetX() + mSpeedX * elapsed, GetY() + mSpeedY * elapsed);
}


