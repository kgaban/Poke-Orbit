/**
* \file Pokemon.cpp
*
* \author Connor Masini
*/

#include "stdafx.h"
#include <string>
#include "PokeOrbitApp.h"
#include "Pokemon.h"

using namespace std;

/**Destructor
*/
CPokemon::~CPokemon()
{
}

/**
* Constructor
* \param pokeOrbit - the PokeOrbit game this pokemon is a part of
* \param filename - name of the file the image is contained in
* \param min - minumum speed for this type of pokemon
* \param max - maximum speed for this type of pokemon
*/
CPokemon::CPokemon(CPokeOrbitApp* pokeOrbit, wstring filename, double min, double max) :
	CGameObject(pokeOrbit, filename)
{
	mMinSpeed = min; 
	mMaxSpeed = max;
}

