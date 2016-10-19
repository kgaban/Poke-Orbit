/**
* \file PokeStopVisitor.cpp
*
* \author Marc VandenBerg
*
* A class for visiting PokeStops
*/



#include "stdafx.h"
#include "PokeStopVisitor.h"
#include "PokeOrbitApp.h"
#include "PokeStop.h"

/// Constructor
CPokeStopVisitor::CPokeStopVisitor() : CPokeOrbitVisitor()
{
}

/// Destructor
CPokeStopVisitor::~CPokeStopVisitor()
{
}


/**
* Visit a PokeStop
* \param pokeStop The pokestop we're visiting
* \param pokeOrbit The Poke Orbit App the pokestop is in
*/
void CPokeStopVisitor::VisitPokeStop(CPokeStop *pokeStop, CPokeOrbitApp *pokeOrbit, double x, double y)
{
	pokeStop->MakeClickable();
}
