/**
* \file GameObject.h
*
* \author Team Transel
* 
* Implementation of the game object class
*/


#pragma once
#include "ImageObject.h"
#include <string>
#include <memory>

class CPokeOrbitApp;
class CPokeOrbitVisitor;


/**
 * Class to implement gameobjects(pokestops and pokemon)
 */
class CGameObject : CImageObject
{
public:
	///default constructor (disabled)
	CGameObject()=delete;
	///copy constructor (disabled)
	CGameObject(const CGameObject&) = delete;
	~CGameObject();

	/**
	* Function to update position of a game object
	* \param elapsed time since last function call
	*/

	virtual void Update(double elapsed) override;

	///Setter for mSpeed
	void SetSpeed(double speed) { mSpeed = speed; }

	virtual bool HitTest(double x, double y);

	/// Setter for position
	void SetPosition(double x, double y) { CImageObject::SetPosition(x, y); }

	/// Setter for image
	void SetImage(const std::wstring filename) { CImageObject::SetImage(filename); }

	/// Return the object's x position
	virtual double GetX() { return CImageObject::GetX(); }
	/// Return the object's y position
	virtual double GetY() { return CImageObject::GetY(); }
	/// Sets the objects y position
	virtual std::unique_ptr<Gdiplus::Bitmap>* GetImage() { return CImageObject::GetImage(); }
	/// Gets the pokeOrbitApp of the image
	CPokeOrbitApp* GetApp() { return CImageObject::GetApp(); }
	///Inhereted draw function from ImageObject]
	virtual void Draw(Gdiplus::Graphics *graphics) { CImageObject::Draw(graphics); }
	///Draw function inhereted from imageobject
	virtual double GetDist() { return CImageObject::GetDist(); }
	bool CatchTest();

	/** Accept visitor
	* \param visitor The visitor being accepted
	* \param pokeOrbit The App containing everything
	* \param x The x position
	* \param y The y position
	*/
	virtual void Accept(CPokeOrbitVisitor *visitor, CPokeOrbitApp *pokeOrbit, double x, double y) {}

protected:
	///Constructor - uses CImage object to construct
	CGameObject(CPokeOrbitApp *pokeOrbit, std::wstring filename);

private:
	///speed of the object
	double mSpeed=0;

};

