#pragma once


class CPokeOrbitApp
{
public:
	CPokeOrbitApp();
	virtual ~CPokeOrbitApp();

	void OnDraw(Gdiplus::Graphics * graphics);

private:
	Gdiplus::Bitmap *mAsh; ///< Background image to use
};

