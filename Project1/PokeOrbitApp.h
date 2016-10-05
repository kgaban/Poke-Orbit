#pragma once

using namespace Gdiplus;

class CPokeOrbitApp
{
public:
	CPokeOrbitApp();
	virtual ~CPokeOrbitApp();

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	float Radius(float scaleX, float scaleY); ///< Gets radius of circle

private:
	Gdiplus::Bitmap *mAsh; ///< Background image to use
};

