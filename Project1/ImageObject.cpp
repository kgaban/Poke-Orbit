/**
* \file ImageObject.cpp
*
* \author Team Transel
*
* Implementation of the game object class
*/



#include "stdafx.h"
#include "PokeOrbitApp.h"
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
* \param x either the x position or the x speed of the object
* \param y either the y position or the y speed of the object
* \param filename = name of file containing image for the object
*/
CImageObject::CImageObject(CPokeOrbitApp * pokeOrbit, wstring filename)
{
	mPokeOrbitApp = pokeOrbit;
	SetImage(filename);
	//mersenne twister using time as a seed to emit to a random location
	mt19937_64 rand(chrono::system_clock::now().time_since_epoch().count());
	mX = (double)(rand() % 300 + 50);
	mY = (double)(rand() % ((int)sqrt(250000 - mX*mX) - 200) + 20);
}



CImageObject::~CImageObject()
{
}


/** Draw a given GameObject
* \param graphics The graphics we are drawing to
*/
void CImageObject::Draw(Gdiplus::Graphics * graphics)
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
void CImageObject::SetPosition(double x, double y)
{
	mX = x;
	mY = y;
}


/** Sets the image of the game object
* \param filename The file name of the image
*/
void CImageObject::SetImage(const wstring filename)
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
double CImageObject::GetDist()
{
	double c = sqrt(pow(mX, 2) + pow(mY, 2));
	return c;
}