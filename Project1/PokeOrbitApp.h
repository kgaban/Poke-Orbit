/**
* \file PokeOrbitApp.h
*
* \author Team Transel
*
* Implementation of our PokeOrbit app
*/



#pragma once

#include <vector>
#include <memory>
#include "Emitter.h"
#include "GameObject.h"
#include "PokeBall.h"
#include "Inventory.h"
#include "PokeOrbitVisitor.h"

/// PokeOrbit app implementation
class CPokeOrbitApp
{
public:
	CPokeOrbitApp();
	virtual ~CPokeOrbitApp();

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	void Update(double elapsed);

	void Add(std::shared_ptr<CGameObject> object);

	void RemoveObject(std::shared_ptr<CGameObject> object);

	void DrawInventory(Gdiplus::Graphics * graphics, int width, int height, int mNumPokeballs, int Pikachus, 
		int Blastoises, int Bulbasaurs, int Charmanders);


	/** Accept visitor
	* \param visitor The visitor being accepted
	* \param x The x position
	* \param y The y position
	*/
	void Accept(CPokeOrbitVisitor *visitor, double x, double y)
	{
		for (auto object : mObjects)
		{
			object->Accept(visitor, this, x, y);
		}
	}

private:
	Gdiplus::Bitmap *mAsh; ///< Image of ash
	int mAshX;  ///< X coordinate of Ash
	int mAshY;  ///< Y coordinate of Ash

	/// Playing area width in virtual pixels
	const static int Width = 1400;

	/// Playing area height in virtual pixels
	const static int Height = 1100;

	/// Radius of the playing feild in virtual pixels
	const static int Radius = 500;

	/// Used to draw a pokeball
	Gdiplus::Bitmap *mPokeBall; ///< Image of a pokeball
	int mPokeBallX;  ///< X coordinate of pokeball
	int mPokeBallY;  ///< Y coordinate of pokeball

	Gdiplus::Bitmap *mPikachu; ///< Image of a pikachu
	Gdiplus::Bitmap *mBlastoise; ///< Image of a Blastoise
	Gdiplus::Bitmap *mBulbasaur; ///< Image of a Bulbasaur
	Gdiplus::Bitmap *mCharmander; ///< Image of a Charmander

	/// Coordinatees to draw the pokemon for the inventory
	int mPokemonX;
	int mPokemonY;


	const double mPokemonOffset = 125;  ///< offset for 

	int mDrawOrder;						///< draw order counter
	double mHeightOffset;				///< offset for the counter height

	bool mPikachuDrawn;					///< checks if a pikachu has been drawn
	bool mBlastoiseDrawn;				///< checks if a blastoise has been drawn
	bool mBulbasaurDrawn;				///< checks if a bulbasaur has been drawn
	bool mCharmanderDrawn;				///< checks if a charmander has been drawn

	/// All of our active game objects
	std::vector<std::shared_ptr<CGameObject> > mObjects;
};

