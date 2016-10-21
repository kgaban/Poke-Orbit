/**
* \file Pokemon.cpp
*
* \author Connor Masini
*/

#include "stdafx.h"
#include <string>
#include <random>
#include "PokeOrbitApp.h"
#include "Pokemon.h"

using namespace std;

/**Destructor
*/
CPokemon::~CPokemon()
{
}

/** Accept a visitor
* \param visitor The visitor to the pokemon
* \param pokeOrbit the PokeOrbitApp being visited
* \param x The x position for the visit
* \param y The y position for the visit
*/
void CPokemon::Accept(CPokeOrbitVisitor * visitor, CPokeOrbitApp * pokeOrbit, double x, double y)
{
	visitor->VisitPokemon(this);
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
* \param filename - name of the file the image is contained in
* \param min - minumum speed for this type of pokemon
* \param max - maximum speed for this type of pokemon
*/
CPokemon::CPokemon(CPokeOrbitApp* pokeOrbit, std::wstring filename, double min, double max) :
	CGameObject(pokeOrbit, filename)
{
	double random = ((double)rand() / (RAND_MAX));
	SetSpeed(random * (max - min) + min);
}

