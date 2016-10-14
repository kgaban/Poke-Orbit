/**
* \file ChildView.cpp
*
* \author Team Transel
*/



#include "stdafx.h"
#include "Project1.h"
#include "ChildView.h"
#include "GameObject.h"
#include "PokeBall.h"
#include "DoubleBufferDC.h"

#include <cmath>
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 7;

/// Max pokeball speed
const double maxPokeBallSpeed = 530;

/// Playing area width in virtual pixels
const static double Width = 1400;

/// Playing area height in virtual pixels
const static double Height = 1100;

/// Radius of the playing read in virtual pixels
const static double Radius = 500;

// CChildView

/// Constructor
CChildView::CChildView()
{
}

/// Destructor
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView message handlers


/// Precreates the window for the display to create a buffer
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL); ///< changed to COLOR_WINDOW-3 for black background

	return TRUE;
}

/// Procedure to follow when painting to the application
void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

	CRect rect;
	GetClientRect(&rect);

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mPokeOrbitApp.Update(elapsed);

	mPokeOrbitApp.OnDraw(&graphics, rect.Width(), rect.Height());

	mPokeOrbitApp.DrawInventory(&graphics, rect.Width(), rect.Height(), mInventory.PokeBallCount()); ///< draws the inventory of pokeballs

	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

/**
* Procedure on follow on releasing the left mouse button
*/
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// Don't throw a pokeball if they just clicked on an available pokestop
	if (mPokeStopClick)
	{
		CRect rect;
		GetClientRect(&rect);

		// Determine scaling for speed
		float scaleX = float(rect.Width()) / float(Width);
		float scaleY = float(rect.Height()) / float(Height);
		float scale = min(scaleX, scaleY);

		// Calculate the distance of the click from the center of the circle
		double x = point.x - (rect.Width() / 2.0f);
		double y = point.y - (rect.Height() / 2.0f);
		double c = (sqrt(pow(x, 2) + pow(y, 2)));

		// Scale the radius
		double rad = Radius * scale;

		// If the click was within the scaled radius, calculate speed for the ball and throw it-
		if (c < rad)
		{
			double xSpeed;
			double ySpeed;

			double theta = atan((y) / (x));
			if (x < 0)
			{
				xSpeed = cos(theta) * (c / rad) * -maxPokeBallSpeed;
				ySpeed = sin(theta) * (c / rad) * -maxPokeBallSpeed;
			}
			else
			{
				xSpeed = cos(theta) * (c / rad) * maxPokeBallSpeed;
				ySpeed = sin(theta) * (c / rad) * maxPokeBallSpeed;
			}

			auto ball = make_shared<CPokeBall>(&mPokeOrbitApp, xSpeed, ySpeed);

			mInventory.ThrowBall(&mPokeOrbitApp, ball);
		}
	}
	else
	{
		mPokeStopClick = false;
	}

	Invalidate();
}


/**
*  Handle timer events
* \param nIDEvent The timer event ID
*/
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}


/**
* Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}