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

#include <string>
#include <memory>
#include <cmath>

using namespace std;
using namespace Gdiplus;



/** Constructor
* \param pokeOrbit - the PokeOrbit game this object is a part of
* \param x either the x position or the x speed of the object
* \param y either the y position or the y speed of the object
* \param filename = name of file containing image for the object
*/
CGameObject::CGameObject(CPokeOrbitApp * pokeOrbit, double x, double y, wstring filename)
{
	mPokeOrbitApp = pokeOrbit;
	SetImage(filename);
}



CGameObject::~CGameObject()
{
}


/** Draw a given GameObject
* \param graphics The graphics we are drawing to
*/
void CGameObject::Draw(Gdiplus::Graphics * graphics)
{
	if (mObjectImage != nullptr)
	{
		double xOffset = (mObjectImage->GetWidth()) / 2;
		double yOffset = (mObjectImage->GetHeight()) / 2;
		double xPos = mX - xOffset;
		double yPos = mY - xOffset;
		graphics->DrawImage(mObjectImage.get(), (int)xPos, (int)yPos);
	}
}


/** Sets the position of the game object
* \param x The x position
* \param y The y position
*/
void CGameObject::SetPosition(double x, double y)
{
	mX = x;
	mY = y;
}


/** Sets the image of the game object
* \param filename The file name of the image
*/
void CGameObject::SetImage(const wstring filename)
{
	mObjectImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mObjectImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}



/** Return the absolute distance from the center of the circle
* \return c The distance from the center
*/
double CGameObject::GetDist()
{
	double c = sqrt(pow(mX, 2) + pow(mY, 2) );
	return c;
}


/** Test whether or not the object has been clicked
* \param x The x position
* \param y The y position
* \return bool The true or false result of the hit test
*/
bool CGameObject::HitTest(double x, double y)
{
	double wid = mObjectImage->GetWidth();
	double hit = mObjectImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mObjectImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mObjectImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}

