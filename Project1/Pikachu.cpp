/**
 * \file Pikachu.cpp
 *
 * \author Connor Masini
 */

#include "stdafx.h"
#include <string>
#include "PokeOrbitApp.h"
#include "Pikachu.h"

using namespace std;

/// Minimum speed of a pikachu
const double PikachuMinSpeed = 1.5;
/// Maximum speed of a pikachu
const double PikachuMaxSpeed = 2;
/// Pikachu filename
const wstring PikachuImageName(L"images/pikachu.png");

/**Destructor
*/
CPikachu::~CPikachu()
{
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
*/
CPikachu::CPikachu(CPokeOrbitApp* pokeOrbit) :
	CPokemon(pokeOrbit, PikachuImageName, PikachuMaxSpeed, PikachuMinSpeed)
{
}

/** Add to the pokemon tally
* \param visitor The visiting pokemon catcher
*/
void CPikachu::AddPoke(CPokemonCatchVisitor * visitor)
{
	visitor->mPikachu++;
}