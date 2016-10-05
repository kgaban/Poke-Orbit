/**
 * \file Bulbasaur.cpp
 *
 * \author Connor Masini
 */

#include "stdafx.h"
#include <string>
#include "PokeOrbitApp.h"
#include "Bulbasaur.h"

using namespace std;

/// Minimum speed of a Bulbasaur
const double BulbasaurMinSpeed = 1;
/// Maximum speed of a Bulbasaur
const double BulbasaurMaxSpeed = 2;
/// Pikachu filename
const wstring BulbasaurImageName(L"images/bulbasaur.png");

/**Destructor
*/
CBulbasaur::~CBulbasaur()
{
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
*/
CBulbasaur::CBulbasaur(CPokeOrbitApp* pokeOrbit) :
	CPokemon(pokeOrbit, BulbasaurImageName, BulbasaurMaxSpeed, BulbasaurMinSpeed)
{
}