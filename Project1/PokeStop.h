/**
* \file PokeStop.h
*
* \author Marc VandenBerg
*
* Class to implement pokestops in our game
*/



#pragma once


#include "GameObject.h"
#include "PokeOrbitVisitor.h"

class CPokeOrbitApp;

/** Implementation of Pokestops
*/
class CPokeStop :
	public CGameObject
{
public:
	CPokeStop(CPokeOrbitApp * pokeOrbit, int x, int y);
	virtual ~CPokeStop();

	void Update(double elapsed) override;

	void Draw(Gdiplus::Graphics * graphics);
	
	void MakeClickable();

	double GetDist() override;

	/** Accept visitor
	* \param visitor The visitor being accepted
	* \param pokeOrbit The App containing everything
	* \param x The x position
	* \param y The y position
	*/
	void Accept(CPokeOrbitVisitor *visitor, CPokeOrbitApp *pokeOrbit, double x, double y) override
	{
		visitor->VisitPokeStop(this, pokeOrbit, x, y);
	}

	void MakeNotClick();

private:
	/// boolean value stating whether or not the pokestop has available pokeballs
	bool mAvailable = true;

	/// time since last click
	double mClickTime = 0;

	/// The total lifespan of the pokestop
	double mLifespan = 0;

	/// Speed of the pokestop
	double mSpeed = 0.7;
};

