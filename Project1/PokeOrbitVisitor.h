/**
* \file PokeOrbitVisitor.h
*
* \author Marc VandenBerg
*
* A base class for visitors in our PokeOrbit App
*/




#pragma once

class CPokeStop;
class CPokeOrbitApp;

/// Class to visit poke orbit classes
class CPokeOrbitVisitor
{
public:
	CPokeOrbitVisitor();
	virtual ~CPokeOrbitVisitor();

	/// Base function to visit a PokeStop
	virtual void VisitPokeStop(CPokeStop *pokeStop, CPokeOrbitApp *pokeOrbit, double x, double y) = 0;
};

