/**
* \file GameObject.cpp
*
* \author Team Transel
*
* Implementation of the game object class
*/



#include "stdafx.h"
#include "PokeOrbitApp.h"
#include "GameObject.h"
#include "ImageObject.h"
#include <chrono>
#include <random>
#include <string>
#include <memory>
#include <cmath>

using namespace std;
using namespace Gdiplus;



/** Constructor
* \param pokeOrbit - the PokeOrbit game this object is a part of
* \param filename = name of file containing image for the object
*/
CGameObject::CGameObject(CPokeOrbitApp * pokeOrbit, std::wstring filename) : CImageObject(pokeOrbit, filename)
{}



CGameObject::~CGameObject()
{
}


/** Test whether or not the object has been clicked
* \param x The x position
* \param y The y position
* \return bool The true or false result of the hit test
*/
bool CGameObject::HitTest(double x, double y)
{
	double wid = (*GetImage())->GetWidth();
	double hit = (*GetImage())->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid/2;
	double testY = y - GetY() + hit/2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = (*GetImage())->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		(*GetImage())->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}

/** Send the GameObject up to see if a pokeball caught it
* (used by the PokemonCatchVisitor)
* \return bool checks if CatchTest was successful
*/
bool CGameObject::CatchTest()
{
	return GetApp()->CatchTest(this);
}

void CGameObject::Update(double elapsed)
{
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
