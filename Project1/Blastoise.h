/**
* \file Blastoise.h
*
* \author Connor Masini
*
* Class that implements a Blastoise
*/

#pragma once

#include "PokeOrbitApp.h"
#include "Pokemon.h"

class CBlastoise :
	public CPokemon
{
public:
	///default constructor (disabled)
	CBlastoise() = delete;
	/// copy constructor (disabled)
	CBlastoise(const CBlastoise&) = delete;
	~CBlastoise();
	CBlastoise(CPokeOrbitApp* pokeOrbit);

	virtual void AddPoke(CPokemonCatchVisitor *visitor);
};

