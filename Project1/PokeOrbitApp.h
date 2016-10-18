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

	/// Radius of the playing read in virtual pixels
	const static int Radius = 500;

	/// Used to draw a pokeball
	Gdiplus::Bitmap *mPokeBall; ///< Image of a pokeball
	int mPokeBallX;  ///< X coordinate of pokeball
	int mPokeBallY;  ///< Y coordinate of pokeball

	/// Used to draw Pikachu
	Gdiplus::Bitmap *mPikachu; ///< Image of a pikachu

	/// Used to draw a Blastoise
	Gdiplus::Bitmap *mBlastoise; ///< Image of a Blastoise

	/// Used to draw a Bulbasaur
	Gdiplus::Bitmap *mBulbasaur; ///< Image of a Bulbasaur

	/// Used to draw a Charmander
	Gdiplus::Bitmap *mCharmander; ///< Image of a Charmander

	int mPokemonX;
	int mPokemonY;


	double mPokemonOffset; ///< used to draw Pokemon

	int mDrawOrder;

	bool mPikachuDrawn;
	bool mBlastoiseDrawn;
	bool mBulbasaurDrawn;
	bool mCharmanderDrawn;

	/// All of our active game objects
	std::vector<std::shared_ptr<CGameObject> > mObjects;

};

