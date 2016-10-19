
























































/**
 * \file Blastoise.cpp
 *
 * \author Connor Masini
 */

#include "stdafx.h"
#include <string>
#include "PokeOrbitApp.h"
#include "Blastoise.h"

using namespace std;

/// Minimum speed of a Blastoise
const double BlastoiseMinSpeed = .1;
/// Maximum speed of a Blastoise
const double BlastoiseMaxSpeed = .5;
/// Pikachu filename
const wstring BlastoiseImageName(L"images/blastoise.png");

/**Destructor
*/
CBlastoise::~CBlastoise()
{
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
*/
CBlastoise::CBlastoise(CPokeOrbitApp* pokeOrbit) :
	CPokemon(pokeOrbit, BlastoiseImageName, BlastoiseMaxSpeed, BlastoiseMinSpeed)
{
}