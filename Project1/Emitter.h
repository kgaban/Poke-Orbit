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
	CEmitter(CPokeOrbitApp * pokeOrbit);
	virtual ~CEmitter();
	void EmitPokemon();
	void EmitPokeStop();
	void Update(double);

private:
	///pokeOrbitApp to emit in
	CPokeOrbitApp * mPokeOrbitApp;
	///Time since pokemon emission
	double mPokemonTime;
	///Time since pokestop emission
	double mPokeStopTime;
	///time of next pokemon emission
	double mTimeOfNextPokemonEmission;
	///time of next pokestop emission
	double mTimeOfNextPokeStopEmission;
};

