/**
* \file Bulbasaur.h
*
* \author Connor Masini
*
* Class that implements a Bulbasaur
*/

#pragma once

#include "PokeOrbitApp.h"
#include "Pokemon.h"

class CBulbasaur :
	public CPokemon
{
public:
	///default constructor (disabled)
	CBulbasaur() = delete;
	/// copy constructor (disabled)
	CBulbasaur(const CBulbasaur&) = delete;
	~CBulbasaur();
	CBulbasaur(CPokeOrbitApp* pokeOrbit);

	virtual void AddPoke(CPokemonCatchVisitor *visitor);
};

