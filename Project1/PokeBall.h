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


/// Class to manage behavior of thrown pokeballs
class CPokeBall : public CGameObject
{
public:

	/// Default constructor, disabled
	CPokeBall() = delete;

	/// Copy constructor, disabled
	//CPokeBall(const CPokeBall&) = delete;

	CPokeBall(CPokeOrbitApp *pokeOrbit, double x, double y, std::wstring file);

	virtual ~CPokeBall();

	void Draw(Gdiplus::Graphics * graphics) override;

	void Update(double elapsed) override;

private:
	/// X position of the pokeball
	double mX = 0;

	/// Y position of the pokeball
	double mY = 0;

	/// Pokeball X speed
	double mSpeedX = 0;

	/// Pokeball Y speed
	double mSpeedY = 0;
};

