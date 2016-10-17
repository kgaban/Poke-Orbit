#pragma once
#include "PokeOrbitApp.h"
#include "GameObject.h"
#include <memory>

class CEmission
{
public:
	CEmission() = delete;
	virtual ~CEmission();
	CEmission(CPokeOrbitApp* app, std::shared_ptr<CGameObject> object, double speed)
	{
		mPokeOrbitApp = app;
		mObject = object;
		mSpeed = speed;
	}
private:
	CPokeOrbitApp* mPokeOrbitApp;
	std::shared_ptr<CGameObject> mObject;
	double mSpeed;
};

