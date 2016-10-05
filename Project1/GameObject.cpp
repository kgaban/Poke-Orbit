#include "stdafx.h"
#include <string>
#include <memory>
#include "PokeOrbitApp.h"
#include "GameObject.h"

using namespace std;
using namespace Gdiplus;

CGameObject::~CGameObject()
{
}

/** Constructor
* \param pokeOrbit - the PokeOrbit game this object is a part of
* \param filename = name of file containing image for the object
*/
CGameObject::CGameObject(CPokeOrbitApp *pokeOrbit, wstring filename)
{
	mObjectImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mObjectImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}
