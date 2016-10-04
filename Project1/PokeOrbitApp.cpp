#include "stdafx.h"
#include "PokeOrbitApp.h"

using namespace Gdiplus;

CPokeOrbitApp::CPokeOrbitApp()
{
	mAsh = Bitmap::FromFile(L"images/ash.png");
	if (mAsh->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/ash.png");
	}
}


CPokeOrbitApp::~CPokeOrbitApp()
{
}

void CPokeOrbitApp::OnDraw(Gdiplus::Graphics * graphics)
{
}
