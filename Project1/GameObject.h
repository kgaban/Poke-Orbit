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
class CPokeOrbitVisitor;

class CGameObject
{
public:
	///default constructor (disabled)
	CGameObject()=delete;
	///copy constructor (disabled)
	//CGameObject(const CGameObject&) = delete;
	~CGameObject();

	/// Function to update position of a game object
	virtual void Update(double elapsed);

	virtual void Draw(Gdiplus::Graphics *graphics);

	void SetPosition(double x, double y);

	void SetImage(const std::wstring filename);

	/// Return the object's x position
	double GetX() { return mX; }
	/// Return the object's y position
	double GetY() { return mY; }

	virtual double GetDist();

	virtual bool HitTest(double x, double y);

	/** Accept visitor
	* \param visitor The visitor being accepted
	* \param pokeOrbit The App containing everything
	* \param x The x position
	* \param y The y position
	*/
	virtual void Accept(CPokeOrbitVisitor *visitor, CPokeOrbitApp *pokeOrbit, double x, double y) {}

protected:
	CGameObject(CPokeOrbitApp *pokeOrbit, std::wstring filename);

private:
	/// The PokeOrbitApp containing the GameObject
	CPokeOrbitApp *mPokeOrbitApp;

	/// The image of the object
	std::unique_ptr<Gdiplus::Bitmap> mObjectImage;

	/// X position
	double mX = 0;

	/// Y position
	double mY = 0;
protected:
	///speed of the object
	double mSpeed;

};

