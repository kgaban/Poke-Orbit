/**
*
* \file PokeOrbitApp.cpp
*
* Implementation of our poke orbit app
*/


#include "stdafx.h"
#include "PokeOrbitApp.h"
#include "PokeBall.h"

#include <memory>
#include <vector>

using namespace Gdiplus;
using namespace std;


/// Constructor
CPokeOrbitApp::CPokeOrbitApp()
{
	mAsh = Bitmap::FromFile(L"images/ash.png");
	if (mAsh->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/ash.png");
	}

	mPokeBall = Bitmap::FromFile(L"images/pokeball.png");
	if (mPokeBall->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/pokeball.png");
	}
	
	mPikachu = Bitmap::FromFile(L"images/pikachu.png");
	if (mPikachu->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/pikachu.png");
	}

	mBlastoise = Bitmap::FromFile(L"images/blastoise.png");
	if (mBlastoise->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/blastoise.png");
	}

	mBulbasaur = Bitmap::FromFile(L"images/bulbasaur.png");
	if (mBulbasaur->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/bulbasaur.png");
	}

	mCharmander = Bitmap::FromFile(L"images/charmander.png");
	if (mCharmander->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/charmander.png");
	}
}

/// Destructor
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

	// Fill the background with black
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

	// From here on you are drawing virtual pixels...

	//
	// And the circle so you can see how this works...
	//
	Pen pen(Color::Green);
	graphics->DrawArc(&pen, -radius, -radius, radius * 2, radius * 2, 0, 360);

	/// Set the coordinate for Ash image
	mAshX = 0 - (mAsh->GetWidth()) / 2;
	mAshY = 0 - (mAsh->GetHeight()) / 2;

	/// Sets the location of Ash
	graphics->DrawImage(mAsh, mAshX, mAshY,
		mAsh->GetWidth(), mAsh->GetHeight());

	vector < shared_ptr<CGameObject> > markedForDeath;
	// Remove game objects that have left the circle
	for (auto i = mObjects.rbegin(); i != mObjects.rend(); i++)
	{
		if ((*i)->GetDist() > radius)
		{
			markedForDeath.push_back(*i);
		}
	}
	for (auto i : markedForDeath)
	{
		RemoveObject(i);
	}


	// Draw our game objects
	for (auto object : mObjects)
	{
		object->Draw(graphics);
	}
}


/**
* Update Game objects in the app
*/
void CPokeOrbitApp::Update(double elapsed)
{
	for (auto object : mObjects)
	{
		object->Update(elapsed);
	}
}


/**  Add an object to the app
* \param object New object to add
*/
void CPokeOrbitApp::Add(shared_ptr<CGameObject> object)
{
	mObjects.push_back(object);
}

/** Remove an object from the app
* \param object Object to be removed
*/
void CPokeOrbitApp::RemoveObject(shared_ptr<CGameObject> object)
{
	auto loc = find(begin(mObjects), end(mObjects), object);
	if (loc != end(mObjects))
	{
		mObjects.erase(loc);
	}
}

void CPokeOrbitApp::DrawInventory(Gdiplus::Graphics * graphics, int width, int height, int numPokeBalls, 
	int mPikachus, int mBlastoise, int mBulbasaurs, int mCharmander)
{
	/// Set the coordinates for the first PokeBall
	mPokeBallX = -CPokeOrbitApp::Width / 2;
	mPokeBallY = -CPokeOrbitApp::Height / 2 + 20;

	/// Draws pokeballs
	for (int j = 0; j < numPokeBalls; j++)
	{
		graphics->DrawImage(mPokeBall, mPokeBallX, mPokeBallY,
			mPokeBall->GetWidth(), mPokeBall->GetHeight());

		/// increment for every new PokeBall
		mPokeBallY += mPokeBall->GetWidth() + 20;
	}

	mPokemonOffset = 0; ///< default offset ** gets incremented when implemented below**

	/** PSEUDOCODE
	 * if first pokemon caught, display it and increment offset by image height
	 * if second pokemon caught, display it and increment offset
	 * etc..
	 * NOTE: display count along with image so may need a horizontal offset to make space for that.
	 */


}