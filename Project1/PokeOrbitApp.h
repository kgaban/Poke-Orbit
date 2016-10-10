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

private:
	Gdiplus::Bitmap *mAsh; ///< Image of ash

	/// Playing area width in virtual pixels
	const static int Width = 1400;

	/// Playing area height in virtual pixels
	const static int Height = 1100;

	/// Radius of the playing read in virtual pixels
	const static int Radius = 500;

	int mAshX;  ///< X coordinate of Ash
	int mAshY;  ///< Y coordinate of Ash

	/// All of our active game objects
	std::vector<std::shared_ptr<CGameObject> > mObjects;
};

