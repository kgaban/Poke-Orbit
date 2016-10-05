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

class CPokemon :
	public CGameObject
{
public:
	///Default constructor (disabled)
	CPokemon()=delete;
	///Copy Constructor (disabled)
	CPokemon(const CPokemon &) = delete;
	~CPokemon();
protected:
	CPokemon(CPokeOrbitApp* pokeOrbit, std::wstring filename, double min, double max);
private:
	///minSpeed of pokemon
	double mMinSpeed;
	///maxSpeed of pokemon
	double mMaxSpeed;
};

