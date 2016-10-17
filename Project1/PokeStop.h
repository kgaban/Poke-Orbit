#pragma once
#include "GameObject.h"
#include "PokeOrbitApp.h"
class CPokeStop :
	public CGameObject
{
public:
	//CPokeStop(CPokeOrbitApp* app);
	virtual ~CPokeStop();
private:
	CPokeOrbitApp* mPokeOrbitApp;
};

