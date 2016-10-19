/**
* \file PokemonCatchVisitor.cpp
*
* \author Marc VandenBerg
*
* A class for visiting Pokemon to catch them
*/




#include "stdafx.h"
#include "PokemonCatchVisitor.h"
#include "Pokemon.h"

CPokemonCatchVisitor::CPokemonCatchVisitor()
{
}


CPokemonCatchVisitor::~CPokemonCatchVisitor()
{
}

/**
* Visit a PokeStop
* \param pokeStop The pokestop we're visiting
* \param pokeOrbit The Poke Orbit App the pokestop is in
* \param x The x position to test
* \param y The y position to test
*/
void CPokemonCatchVisitor::VisitPokeStop(CPokeStop * pokeStop, CPokeOrbitApp * pokeOrbit, double x, double y)
{
}


/**
* Visit a Pokemon
* \param pokemon The pokemon being visited
*/
void CPokemonCatchVisitor::VisitPokemon(CPokemon * pokemon)
{
	if (pokemon->CatchTest())
	{
		pokemon->AddPoke(this);
	}
}
