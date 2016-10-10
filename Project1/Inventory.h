/**
* \file Inventory.h
*
* \author Marc VandenBerg
*
* Implementation of our CInventory class
*/




#pragma once

#include <memory>

class CPokeOrbitApp;
class CGameObject;
class CPokeBall;

/**
* Inventory class to manage tallies of pokemon and pokeballs
*/
class CInventory
{
public:

	CInventory();
	virtual ~CInventory();

	void ThrowBall(CPokeOrbitApp *pokeOrbit, std::shared_ptr<CPokeBall> object);

private:
	/// Pikachu count
	int mPikachus = 0;
	/// Blastoise count
	int mBlastoise = 0;
	/// Bulbasaur count
	int mBulbasaurs = 0;
	/// Charmander count
	int mCharmander = 0;

	/// Pokeball count
	int mPokeBalls = 3;
};

