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
const int FrameDuration = 20;

/// An empty file name to use for instantiation
const wstring filename = L"images/nofilehere.png";

/// Max pokeball speed
const double maxPokeBallSpeed = 400;

// CChildView

CChildView::CChildView()
{
}

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

void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

	CRect rect;
	GetClientRect(&rect);
	/*
	Pen pen(Color(0, 128, 0), 3); ///< gets a green pen
	graphics.DrawEllipse(&pen, 160, 10, 650, 650); ///< draws a circle
	*/

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

	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CRect rect;
	GetClientRect(&rect);

	double x = point.x - (rect.Width()/2.0f);
	double y = point.y - (rect.Height()/2.0f);
	double c = sqrt(pow(x,2) + pow(y,2));

	double xSpeed;
	double ySpeed;

	double theta = atan((y) / (x));
	if (x < 0)
	{
		xSpeed = cos(theta) * (c / 500) * -maxPokeBallSpeed;
		ySpeed = sin(theta) * (c / 500) * -maxPokeBallSpeed;
	}
	else
	{
		xSpeed = cos(theta) * (c / 500) * maxPokeBallSpeed;
		ySpeed = sin(theta) * (c / 500) * maxPokeBallSpeed;
	}

	auto ball = make_shared<CPokeBall>(&mPokeOrbitApp, xSpeed, ySpeed, filename);

	mPokeOrbitApp.Add(ball);

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