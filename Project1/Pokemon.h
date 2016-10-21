/**
* \file Pokemon.h
*
* \author Connor Masini
*
* Class that holds Pokemon that can 
* orbit around ash and be caught
*/

#pragma once
#include <string>
#include "GameObject.h"
#include "PokemonCatchVisitor.h"

/// class to implement pokemon
class CPokemon :
	public CGameObject
{
public:
	///Default constructor (disabled)
	CPokemon()=delete;
	///Copy Constructor (disabled)
	CPokemon(const CPokemon &) = delete;
	~CPokemon();

	virtual void Accept(CPokeOrbitVisitor *visitor, CPokeOrbitApp *pokeOrbit, double x, double y);

	/** Method to allow the pokemon catcher to get a tally of pokemon caught
	* \param visitor The visiting pokemon catcher
	*/
	virtual void AddPoke(CPokemonCatchVisitor *visitor) {}

protected:
	CPokemon(CPokeOrbitApp* pokeOrbit, std::wstring file, double min, double max);
};

