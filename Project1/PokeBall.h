/**
* \file PokeBall.h
*
* \author Marc VandenBerg
*
* Implementation of our PokeBall class
*/



#pragma once

#include <string>

#include "PokeOrbitApp.h"
#include "GameObject.h"
#include "Inventory.h"


/// Class to manage behavior of thrown pokeballs
class CPokeBall : public CImageObject
{
public:

	/// Default constructor, disabled
	CPokeBall() = delete;

	/// Copy constructor, disabled
	CPokeBall(const CPokeBall&) = delete;

	CPokeBall(CPokeOrbitApp *pokeOrbit, double x, double y);

	virtual ~CPokeBall();

	void Update(double elapsed) override;

private:

	/// Pokeball X speed
	double mSpeedX = 0;

	/// Pokeball Y speed
	double mSpeedY = 0;
};

