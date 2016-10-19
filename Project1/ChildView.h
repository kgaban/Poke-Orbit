/**
* \file ChildView.h
*
* \author Team Transel
*/


#pragma once
#include "PokeOrbitApp.h"
#include "Inventory.h"


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	/// An object that describes our app
	CPokeOrbitApp  mPokeOrbitApp;

	/// Our inventory
	CInventory mInventory;

	/// 
	CEmitter* mEmitter;
	/// Check if it's the first time drawing
	bool mFirstDraw = true;

	/// Check if the player clicked on an available pokestop
	bool mPokeStopClick = false;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

