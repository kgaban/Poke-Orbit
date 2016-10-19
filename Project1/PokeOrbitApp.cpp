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


/**
 * Function to draw the inventory on the game board
 *
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 * \param numPokeBalls number of pokeballs
 * \param Pikachus number of pikachu
 * \param Blastoises number of blastoise
 * \param Bulbasaurs number of bulbasaur
 * \param Charmanders number of charmander
 */
void CPokeOrbitApp::DrawInventory(Gdiplus::Graphics * graphics,  int width, int height, int numPokeBalls, 
	int Pikachus, int Blastoises, int Bulbasaurs, int Charmanders)
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

	mPokemonOffset = 125; ///< default offset 

	/** PSEUDOCODE
	 * if first pokemon caught, display it and increment offset by image height
	 * if second pokemon caught, display it and increment offset
	 * etc..
	 * NOTE: display count along with image so may need a horizontal offset to make space for that.
	 */

	 /// Create font
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);

	/// Used to change int to const wchar_t*
	wstring converter1, converter2, converter3, converter4;
	converter1 = to_wstring(Pikachus);
	const wchar_t* numPikachus = converter1.c_str();
	converter2 = to_wstring(Blastoises);
	const wchar_t* numBlastoises = converter2.c_str();
	converter3 = to_wstring(Bulbasaurs);
	const wchar_t* numBulbasaurs = converter3.c_str();
	converter4 = to_wstring(Charmanders);
	const wchar_t* numCharmanders = converter4.c_str();
	
	mPokemonX = CPokeOrbitApp::Width / 2 - 150;
	mPokemonY = -CPokeOrbitApp::Height / 2 + 20;

	/// Set checks initially to false
	mPikachuDrawn = false;
	mBlastoiseDrawn = false;
	mBulbasaurDrawn = false;
	mCharmanderDrawn = false;

	for (mDrawOrder = 0; mDrawOrder <= 4; mDrawOrder++)
	{
		mHeightOffset = 50 + mPokemonOffset*mDrawOrder;

		if (mDrawOrder >= 0)
		{
			if (Pikachus != 0 && mPikachuDrawn == false)
			{
				graphics->DrawImage(mPikachu, mPokemonX, mPokemonY,
					mPikachu->GetWidth(), mPikachu->GetHeight());

				/// Print out number of Pikachus
				SolidBrush white(Color(255, 255, 255));
				graphics->DrawString(numPikachus, -1, &font, PointF(CPokeOrbitApp::Width / 2 - 20, 
					-CPokeOrbitApp::Height / 2 + (Gdiplus::REAL)mHeightOffset), &white);

				//mPokemonOffset += mPikachu->GetHeight();
				mPikachuDrawn = true;
			}

			else if (Blastoises != 0 && mBlastoiseDrawn == false)
			{
				graphics->DrawImage(mBlastoise, mPokemonX, mPokemonY,
					mBlastoise->GetWidth(), mBlastoise->GetHeight());

				/// Print out number of Blastoises
				SolidBrush white(Color(255, 255, 255));
				graphics->DrawString(numBlastoises, -1, &font, PointF(CPokeOrbitApp::Width / 2 - 20, 
					-CPokeOrbitApp::Height / 2 + (Gdiplus::REAL)mHeightOffset), &white);

				//mPokemonOffset += mBlastoise->GetHeight();
				mBlastoiseDrawn = true;
			}

			else if (Bulbasaurs != 0 && mBulbasaurDrawn == false)
			{
				graphics->DrawImage(mBulbasaur, mPokemonX, mPokemonY,
					mBulbasaur->GetWidth(), mBulbasaur->GetHeight());

				/// Print out number of Bulbasaurs
				SolidBrush white(Color(255, 255, 255));
				graphics->DrawString(numBulbasaurs, -1, &font, PointF(CPokeOrbitApp::Width / 2 - 20, 
					-CPokeOrbitApp::Height / 2 + (Gdiplus::REAL)mHeightOffset), &white);

				//mPokemonOffset += mBulbasaur->GetHeight();
				mBulbasaurDrawn = true;
			}
			else if (Charmanders != 0 && mCharmanderDrawn == false)
			{
				graphics->DrawImage(mCharmander, mPokemonX, mPokemonY,
					mCharmander->GetWidth(), mCharmander->GetHeight());

				/// Print out number of Charmanders
				SolidBrush white(Color(255, 255, 255));
				graphics->DrawString(numCharmanders, -1, &font, PointF(CPokeOrbitApp::Width / 2 - 20, 
					-CPokeOrbitApp::Height / 2 + (Gdiplus::REAL)mHeightOffset), &white);

				//mPokemonOffset += mCharmander->GetHeight();
				mCharmanderDrawn = true;
			}

			mPokemonY += (int)mPokemonOffset; ///< increment mPokemonY by the offset
		}
		
	} //< end for loop
}