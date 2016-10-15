/**
* \file PokeStopClickVisitor.h
*
* \author Marc VandenBerg
*
* A class for visiting PokeStops on click event
*/



#pragma once

#include "PokeOrbitVisitor.h"

/// Class to visit pokestops on a click
class CPokeStopClickVisitor
	: public CPokeOrbitVisitor
{
public:
	CPokeStopClickVisitor();
	virtual ~CPokeStopClickVisitor();


	void VisitPokeStop(CPokeStop *pokeStop, CPokeOrbitApp *pokeOrbit, double x, double y) override;

	/// Pokestops clicked on
	int	mPokeStops = 0;
};

