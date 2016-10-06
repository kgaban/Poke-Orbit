/**
 * \file PokeOrbitApp.h
 *
 * \author Kevin Gaban
 *
 * Class that creates our background
 */

#pragma once

/// Class that creates our backgruond
class CPokeOrbitApp
{
public:
	CPokeOrbitApp();
	virtual ~CPokeOrbitApp();

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);


	

private:
	Gdiplus::Bitmap *mAsh; ///< Image of ash

	/// Playing area width in virtual pixels
	const static int Width = 1400;

	/// Playing area height in virtual pixels
	const static int Height = 1100;

	/// Radius of the playing read in virtual pixels
	const static int Radius = 500;

	int mAshX;  ///< X coordinate of Ash
	int mAshY;  ///< Y coordinate of Ash
};

