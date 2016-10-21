/**
* \file ImageObject.h
*
* \author Team Transel
*
* Implementation of the image object class (used to draw pokeballs and gameobjects
*/


#pragma once
#include <string>
#include <memory>

class CPokeOrbitApp;
class CPokeOrbitVisitor;

class CImageObject
{
public:
	///default constructor (disabled)
	CImageObject() = delete;
	///copy constructor (disabled)
	CImageObject(const CImageObject&) = delete;
	~CImageObject();

	// Function to update position of a game object
	virtual void Update(double elapsed)=0;

	// Function to draw a game object (can be overwritten)
	virtual void Draw(Gdiplus::Graphics *graphics);

	virtual void SetPosition(double x, double y);

	virtual void SetImage(const std::wstring filename);

	/// Return the object's x position
	virtual double GetX() { return mX; }
	/// Return the object's y position
	virtual double GetY() { return mY; }
	/// Sets the objects y position
	virtual void SetY(double y) { mY = y; }
	/// Sets the objects y position
	virtual void SetX(double x) { mX = x; }
	/// Gets the image of the object
	virtual std::unique_ptr<Gdiplus::Bitmap>* GetImage() { return &mObjectImage; }
	/// Gets the pokeOrbitApp of the image
	CPokeOrbitApp* GetApp() { return mPokeOrbitApp; }

	virtual double GetDist();

protected:
	CImageObject(CPokeOrbitApp *pokeOrbit, std::wstring filename);

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
