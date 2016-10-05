/**
* \file Pikachu.h
*
* \author Connor Masini
*
* Class that implements a Pikachu
*/

#pragma once

#include "PokeOrbitApp.h"
#include "Pokemon.h"

class CPikachu :
	public CPokemon
{
public:
	///default constructor (disabled)
	CPikachu() = delete;
	/// copy constructor (disabled)
	CPikachu(const CPikachu&) = delete;
	~CPikachu();
	CPikachu(CPokeOrbitApp* pokeOrbit);
};

