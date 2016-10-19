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

	/// Returns the count of pokeballs
	int PokeBallCount() { return mPokeBalls; }
	/// Returns the count of pikachus
	int PikachuCount() { return mPikachus; }
	/// Returns the count of blastoise
	int BlastoiseCount() { return mBlastoise; }
	/// Returns the count of bulbasaurs
	int BulbasaurCount() { return mBulbasaurs; }
	/// Returns the count of charmanders
	int CharmanderCount() { return mCharmander; }

	void AddPokeBalls(int numPokeBalls);

	/** Add to pikachu tally
	* \param count Number to add */
	void AddPikachu(int count) { mPikachus += count; }
	/** Add to blastoise tally
	* \param count Number to add */
	void AddBlastoise(int count) { mBlastoise += count; }
	/** Add to bulbasaur tally
	* \param count Number to add */
	void AddBulbasaur(int count) { mBulbasaurs += count; }
	/** Add to charmander tally
	* \param count Number to add */
	void AddCharmander(int count) { mCharmander += count; }

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

