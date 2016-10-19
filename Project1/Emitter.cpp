/**
* \file PokeStop.h
*
* \author Connor Masini
*
* Class to implement emmisions
*/



#include "stdafx.h"
#include "Emitter.h"
#include "GameObject.h"
#include "PokeStop.h"
#include "Charmander.h"
#include "Blastoise.h"
#include "Bulbasaur.h"
#include "Pikachu.h"
#include <chrono>
#include <random>
#include <memory>

using namespace std;
using namespace Gdiplus;

/** Constructor
* \param pokeOrbit The pokeorbit app this pokestop belongs to
* \param x The x position of the pokestop
* \param y The y position of the pokestop
*/
CEmitter::CEmitter(CPokeOrbitApp * pokeOrbit, Graphics * graphics)
{
	mPokeOrbitApp = pokeOrbit;
	mGraphics = graphics;
		mTime=0;
		//mersenne twister using time as a seed to decide what type of object to emit
		mt19937_64 rand(chrono::system_clock::now().time_since_epoch().count());
		mTimeOfNextPokemonEmission=rand()%12+3;
		mTimeOfNextPokeStopEmission = 15;
}

/// Destructor
CEmitter::~CEmitter()
{
}


/** Emits a pokemon in the pokeorbitapp
 * 
 */
void CEmitter::EmitPokemon()
{
		//mersenne twister using time as a seed to decide what type of object to emit
		mt19937_64 rand(chrono::system_clock::now().time_since_epoch().count());
		//number corresponding to the type of object we should emit
		//0 = bulbasuar, 1 = pikachu, 2 = charmander, 3 = blastoise
		int toEmit = rand() % 4;
		shared_ptr<CGameObject> object;
		switch (toEmit)
		{
		case 0:
			object = make_shared<CBulbasaur>(mPokeOrbitApp);
			break;
		case 1:
			object = make_shared<CPikachu>(mPokeOrbitApp);
			break;
		case 2:
			object = make_shared<CCharmander>(mPokeOrbitApp);
			break;
		case 3:
			object = make_shared<CBlastoise>(mPokeOrbitApp);
			break;
		}
		mPokeOrbitApp->Add(object);
}

/** Emits a pokemon in the pokeorbitapp
*
*/
void CEmitter::EmitPokeStop()
{
	shared_ptr<CGameObject> object = make_shared<CPokeStop>(mPokeOrbitApp);
	mPokeOrbitApp->Add(object);
}

/** Update the emmitter
* \param elapsed The time since the last update
*/
void CEmitter::Update(double elapsed)
{
	mTime += elapsed;
	mTime += 0;
	if (mTime >= mTimeOfNextPokemonEmission)
	{
		EmitPokemon();
		mTimeOfNextPokemonEmission += rand() % 12 + 3;
	}
	if (mTime >= mTimeOfNextPokeStopEmission)
	{
		EmitPokeStop();
		mTimeOfNextPokeStopEmission += rand() % 25 + 20;
	}
}


