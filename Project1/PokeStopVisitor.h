/**
* \file PokeStopVisitor.cpp
*
* \author Marc VandenBerg
*
* A class for visiting PokeStops
*/




#pragma once
#include "PokeOrbitVisitor.h"

class CPokeStop;
class CPokeOrbitApp;

class CPokeStopVisitor :
	public CPokeOrbitVisitor
{
public:
	CPokeStopVisitor();

	virtual ~CPokeStopVisitor();

	void VisitPokeStop(CPokeStop *pokeStop, CPokeOrbitApp *pokeOrbit, double x, double y) override;

	void VisitPokemon(CPokemon * pokemon);

};

