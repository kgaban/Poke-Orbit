/**
* \file Inventory.cpp
*
* \author Marc VandenBerg
*
* Implementation of our CInventory class
*/


#include "stdafx.h"
#include "Inventory.h"
#include "PokeOrbitApp.h"
#include "PokeBall.h"

/// Constructor
CInventory::CInventory()
{
}

/// Destructor
CInventory::~CInventory()
{
}

/**
* Throws a pokeball
* \param pokeOrbit The pokeorbit app we're throwing in
* \param object The game pokeball we're throwing
*/
void CInventory::ThrowBall(CPokeOrbitApp * pokeOrbit, std::shared_ptr<CPokeBall> object)
{	
	if (mPokeBalls > 0)
	{
		pokeOrbit->AddBall(object);
		mPokeBalls--;
	}
}

void CInventory::AddPokeBalls(int numPokeBalls)
{
	mPokeBalls += numPokeBalls;
	if (mPokeBalls > 13)
	{
		mPokeBalls = 13;
	}
}


