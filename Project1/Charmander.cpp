/**
 * \file Charmander.cpp
 *
 * \author Connor Masini
 */

#include "stdafx.h"
#include <string>
#include "PokeOrbitApp.h"
#include "Charmander.h"

using namespace std;

/// Minimum speed of a Charmander
const double CharmanderMinSpeed = 1;
/// Maximum speed of a Charmander
const double CharmanderMaxSpeed = 2;
/// Pikachu filename
const wstring CharmanderImageName(L"images/charmander.png");

/**Destructor
*/
CCharmander::~CCharmander()
{
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
*/
CCharmander::CCharmander(CPokeOrbitApp* pokeOrbit) :
	CPokemon(pokeOrbit, CharmanderImageName, CharmanderMaxSpeed, CharmanderMinSpeed)
{
}
