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
CPokeBall::CPokeBall(CPokeOrbitApp *pokeOrbit, double x, double y, wstring file) : CGameObject(pokeOrbit, x, y, filename)
{
	mSpeedX = x;
	mSpeedY = y;
}

/// Destructor
CPokeBall::~CPokeBall()
{
}

/**
* Method to draw the pokeball on the game board
* \param graphics The drawing board
* \param width The width of the board
* \param height The height of the board
*/
void CPokeBall::Draw(Gdiplus::Graphics * graphics)
{
	CGameObject::Draw(graphics);
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
