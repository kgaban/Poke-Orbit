/**
* \file PokeStop.h
*
* \author Marc VandenBerg
*
* Class to implement pokestops in our game
*/



#pragma once

#include <memory>
#include "GameObject.h"
#include "PokeOrbitApp.h"

class CPokeOrbitApp;

/** Implementation of Pokestops
*/
class CEmitter
{
public:
	CEmitter(CPokeOrbitApp * pokeOrbit, Gdiplus::Graphics *);
	virtual ~CEmitter();
	void EmitPokemon();
	void EmitPokeStop();
	void Update(double);

private:
	///pokeOrbitApp to emit in
	CPokeOrbitApp * mPokeOrbitApp;
	/// Graphics context to draw in
	Gdiplus::Graphics* mGraphics;
	
};

