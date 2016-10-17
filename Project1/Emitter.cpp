#include "stdafx.h"
#include "Emitter.h"
#include "GameObject.h"
#include "Charmander.h"
#include "Blastoise.h"
#include "Bulbasaur.h"
#include "Pikachu.h"
#include <chrono>
#include <random>

using namespace std;

CEmitter::~CEmitter()
{
}

CEmitter::CEmitter(CPokeOrbitApp* pokeOrbitApp)
{
	mPokeOrbitApp = pokeOrbitApp;
}

void CEmitter::Emit()
{
	//mersenne twister using time as a seed to decide what type of object to emit
	mt19937_64 rand(chrono::system_clock::now().time_since_epoch().count());
	//number corresponding to the type of object we should emit
	//0 = bulbasuar, 1 = pikachu, 2 = charmander, 3 = blastoise
	int toEmit = rand() % 4;
	shared_ptr<CGameObject> object;
	switch (toEmit)
	{
	case 0:
		object = make_shared<CBulbasaur>(mPokeOrbitApp);
		break;
	case 1:
		object = make_shared<CPikachu>(mPokeOrbitApp);
		break;
	case 2:
		object = make_shared<CCharmander>(mPokeOrbitApp);
		break;
	case 3:
		object = make_shared<CBlastoise>(mPokeOrbitApp);
		break;
	}

	mPokeOrbitApp->Add(object);
}