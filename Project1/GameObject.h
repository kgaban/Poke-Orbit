/**
* \file GameObject.h
*
* \author Team Transel
* 
* Implementation of the game object class
*/


#pragma once
#include <string>
#include <memory>

class CPokeOrbitApp;

class CGameObject
{
public:
	///default constructor (disabled)
	CGameObject()=delete;
	///copy constructor (disabled)
	//CGameObject(const CGameObject&) = delete;
	~CGameObject();

	/// Function to update position of a game object
	virtual void Update(double elapsed) {}

	virtual void Draw(Gdiplus::Graphics *graphics);

	void SetPosition(int x, int y);

	/// Return the object's x position
	double GetX() { return mX; }
	/// Return the object's y position
	double GetY() { return mY; }

	double GetDist();

protected:
	CGameObject(CPokeOrbitApp *pokeOrbit, int x, int y, std::wstring filename);

private:
	/// The PokeOrbitApp containing the GameObject
	CPokeOrbitApp *mPokeOrbitApp;

	/// The image of the object
	std::unique_ptr<Gdiplus::Bitmap> mObjectImage;

	/// X position
	double mX = 0;

	/// Y position
	double mY = 0;

};

