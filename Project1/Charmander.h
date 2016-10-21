/**
* \file Charmander.h
*
* \author Connor Masini
*
* Class that implements a Charmander
*/


#pragma once

#include "PokeOrbitApp.h"
#include "Pokemon.h"

/// Class to implement a charmander
class CCharmander :
	public CPokemon
{
public:
	///default constructor (disabled)
	CCharmander() = delete;
	/// copy constructor (disabled)
	CCharmander(const CCharmander&) = delete;
	~CCharmander();
	CCharmander(CPokeOrbitApp* pokeOrbit);

	virtual void AddPoke(CPokemonCatchVisitor *visitor);
};

