/**
* \file Inventory.cpp
*
* \author Marc VandenBerg
*
* Implementation of our CInventory class
*/


#include "stdafx.h"
#include "Inventory.h"
#include "PokeOrbitApp.h"

CInventory::CInventory()
{
}


CInventory::~CInventory()
{
}

void CInventory::ThrowBall(CPokeOrbitApp * pokeOrbit, std::shared_ptr<CGameObject> object)
{	
	if (mPokeBalls > 0)
	{
		pokeOrbit->Add(object);
		mPokeBalls--;
	}
}
