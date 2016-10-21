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

	// Function to update position of an image object
	virtual void Update(double elapsed)=0;

	// Function to draw an image object (can be overwritten)
	virtual void Draw(Gdiplus::Graphics *graphics);

	virtual void SetPosition(double x, double y);

	virtual void SetImage(const std::wstring filename);

	/**
	* Getter for mX
	* \return mX X coordinate of object
	*/
	virtual double GetX() { return mX; }
	/**
	* Getter for mY
	* \return mY Y coordinate of object
	*/
	virtual double GetY() { return mY; }
	/**
	* Getter for mObjectImage
	* \return &mObjectImage pointer to mObjectImage
	*/
	virtual std::unique_ptr<Gdiplus::Bitmap>* GetImage() { return &mObjectImage; }
	/**
	* Getter for mPokeOrbitApp
	* \return mPokeOrbitApp pointer to app we are playing in
	*/
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
