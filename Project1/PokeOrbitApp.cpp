#include "stdafx.h"
#include "PokeOrbitApp.h"


/// Playing area width in virtual pixels
const static int Width = 1400;

/// Playing area height in virtual pixels
const static int Height = 1100;

/// Radius of the playing read in virtual pixels
const static int Radius = 500;

CPokeOrbitApp::CPokeOrbitApp()
{
	mAsh = Bitmap::FromFile(L"images/ash.png");
	if (mAsh->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/ash.png");
	}
}


CPokeOrbitApp::~CPokeOrbitApp()
{
}

float CPokeOrbitApp::Radius(float scaleX, float scaleY)
{
	float radius = (float)sqrt(scaleX * scaleX + scaleY * scaleY);
	return radius;
}

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CPokeOrbitApp::OnDraw(Gdiplus::Graphics * graphics, int width, int height)
{
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	float scale = min(scaleX, scaleY);
	float radius = CPokeOrbitApp::Radius(scaleX, scaleY);

	float xOffset = width / 2.0f;
	float yOffset = height / 2.0f;

	graphics->TranslateTransform(xOffset, yOffset);
	graphics->ScaleTransform(scale, scale);

	// From here on you are drawing virtual pixels...

	//
	// And the circle so you can see how this works...
	//
	Pen pen(Color::Green);
	graphics->DrawArc(&pen, -radius, -radius, radius * 2, radius * 2, 0, 360);

	/// Sets the location of Ash
	graphics->DrawImage(mAsh, 0, 0,
		mAsh->GetWidth(), mAsh->GetHeight());
}
