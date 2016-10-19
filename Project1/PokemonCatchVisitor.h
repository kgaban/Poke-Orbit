/**
* \file PokemonCatchVisitor.h
*
* \author Marc VandenBerg
*
* A class for visiting Pokemon to catch them
*/




#pragma once



#include "PokeOrbitVisitor.h"


/// Class to visit and catch pokemon
class CPokemonCatchVisitor :
	public CPokeOrbitVisitor
{
public:
	CPokemonCatchVisitor();
	virtual ~CPokemonCatchVisitor();

	/// Method to visit a pokestop
	virtual void VisitPokeStop(CPokeStop *pokeStop, CPokeOrbitApp *pokeOrbit, double x, double y);

	virtual void VisitPokemon(CPokemon *pokemon);

	/// Blastoise count
	int mBlastoise = 0;

	/// Bulbasaur count
	int mBulbasaur = 0;

	/// Charmander count
	int mCharmander = 0;

	/// Pikachu count
	int mPikachu = 0;
};

