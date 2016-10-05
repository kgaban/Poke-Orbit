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
	CGameObject(const CGameObject&) = delete;
	~CGameObject();
protected:
	CGameObject(CPokeOrbitApp *pokeOrbit, const std::wstring filename);
private:
	std::wstring mFilename;
	std::unique_ptr<Gdiplus::Bitmap> mObjectImage;
};

