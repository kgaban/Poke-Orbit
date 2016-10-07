/**
* \file GameObject.cpp
*
* \author Team Transel
*
* Implementation of the game object class
*/



#include "stdafx.h"
#include <string>
#include <memory>
#include "PokeOrbitApp.h"
#include "GameObject.h"

using namespace std;
using namespace Gdiplus;

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
void CGameObject::SetPosition(int x, int y)
{
	mX = x;
	mY = y;
}



/** Constructor
* \param pokeOrbit - the PokeOrbit game this object is a part of
* \param x either the x position or the x speed of the object
* \param y either the y position or the y speed of the object
* \param filename = name of file containing image for the object
*/
CGameObject::CGameObject(CPokeOrbitApp * pokeOrbit, int x, int y, wstring filename)
{
	mObjectImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mObjectImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}
