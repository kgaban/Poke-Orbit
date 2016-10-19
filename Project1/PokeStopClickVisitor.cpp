/**
* \file PokeStopClickVisitor.cpp
*
* \author Marc VandenBerg
*
* A class for visiting PokeStops on click event
*/



#include "stdafx.h"
#include "PokeStopClickVisitor.h"
#include "PokeOrbitApp.h"
#include "PokeStop.h"




/// Constructor
CPokeStopClickVisitor::CPokeStopClickVisitor() : CPokeOrbitVisitor()
{
}

/// Destructor
CPokeStopClickVisitor::~CPokeStopClickVisitor()
{
}



/**
* Visit a PokeStop
* \param pokeStop The pokestop we're visiting
* \param pokeOrbit The Poke Orbit App the pokestop is in
*/
void CPokeStopClickVisitor::VisitPokeStop(CPokeStop * pokeStop, CPokeOrbitApp * pokeOrbit, double x, double y)
{
	bool check = pokeStop->HitTest(x, y);
	if (check && !mPokeStop && pokeStop->Available())
	{
		mPokeStop = true;
		pokeStop->MakeNotClick();
	}
}
