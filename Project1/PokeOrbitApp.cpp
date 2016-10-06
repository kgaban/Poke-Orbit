/**
 * \file PokeOrbitApp.cpp
 *
 * \author Kevin Gaban
 */

#include "stdafx.h"
#include "PokeOrbitApp.h"

using namespace Gdiplus;



/**
 * Constructor
 */
CPokeOrbitApp::CPokeOrbitApp()
{
	mAsh = Bitmap::FromFile(L"images/ash.png");
	if (mAsh->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/ash.png");
	}
}


/**
 * Destructor
 */
CPokeOrbitApp::~CPokeOrbitApp()
{
}


/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CPokeOrbitApp::OnDraw(Gdiplus::Graphics * graphics, int width, int height)
{
	/// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	float scale = min(scaleX, scaleY);
	float radius = CPokeOrbitApp::Radius;

	float xOffset = width / 2.0f;
	float yOffset = height / 2.0f;

	graphics->TranslateTransform(xOffset, yOffset);
	graphics->ScaleTransform(scale, scale);

	/// Sets a pen color and draws a circle
	Pen pen(Color::Green);
	graphics->DrawArc(&pen, -radius, -radius, radius * 2, radius * 2, 0, 360);

	/// Set the coordinate for Ash image
	mAshX = 0 - (mAsh->GetWidth()) / 2;
	mAshY = 0 - (mAsh->GetHeight()) / 2;

	/// Sets the location of Ash
	graphics->DrawImage(mAsh, mAshX, mAshY,
		mAsh->GetWidth(), mAsh->GetHeight());
}
