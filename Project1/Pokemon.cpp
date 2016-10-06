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

/// Set the non existent image file name to create the message box
const wstring filename = L"images/NoImage.png";

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
CPokemon::CPokemon(CPokeOrbitApp* pokeOrbit, wstring file, double min, double max) :
	CGameObject(pokeOrbit, min, max, filename)
{
	mMinSpeed = min; 
	mMaxSpeed = max;
}

