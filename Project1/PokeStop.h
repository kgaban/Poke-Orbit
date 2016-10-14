/**
* \file PokeStop.h
*
* \author Marc VandenBerg
*
* Class to implement pokestops in our game
*/



#pragma once


#include "GameObject.h"


/** Implementation of Pokestops
*/
class CPokeStop :
	public CGameObject
{
public:
	CPokeStop(CPokeOrbitApp * pokeOrbit, int x, int y);
	virtual ~CPokeStop();

	void Update(double elapsed) override;

private:
	/// boolean value stating whether or not the pokestop has available pokeballs
	bool mAvailable = true;

	/// time since last click
	double mClickTime = 0;

	/// The total lifespan of the pokestop
	double mLifespan = 0;
};

