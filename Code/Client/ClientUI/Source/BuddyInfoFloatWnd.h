﻿/** 
 * 用户信息浮动窗口，BuddyInfoFloatWnd.h
 * zhangyl 2017.09.30
 */

/**
 * @file BuddyInfoFloatWnd.h
 * @author DennisMi (https://www.dennisthink.com/)
 * @brief 用户信息浮动窗口
 * @version 0.1
 * @date 2019-08-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _DENNIS_THINK_C_BUDDY_INFO_FLOAT_WND_H_
#define _DENNIS_THINK_C_BUDDY_INFO_FLOAT_WND_H_
#include "SkinLib/SkinLib.h"

class CBuddyInfoFloatWnd : public CWindowImpl<CBuddyInfoFloatWnd, CWindow>
{
public:
    CBuddyInfoFloatWnd(void);
    ~CBuddyInfoFloatWnd(void);

    DECLARE_WND_CLASS(_T("__FlamingoBuddyInfoFloatWnd__"))

    BEGIN_MSG_MAP_EX(CBuddyInfoFloatWnd)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_ERASEBKGND(OnEraseBkgnd)
		MSG_WM_PAINT(OnPaint)
		MSG_WM_LBUTTONDBLCLK(OnLButtonDblClk)
		MSG_WM_LBUTTONDOWN(OnLButtonDown)
		MSG_WM_LBUTTONUP(OnLButtonUp)
		MSG_WM_RBUTTONUP(OnRButtonUp)
		MSG_WM_MOUSEMOVE(OnMouseMove)
		MSG_WM_MOUSELEAVE(OnMouseLeave)
		MSG_WM_TIMER(OnTimer)
		//MSG_WM_VSCROLL(OnVScroll)
		//MSG_WM_MOUSEWHEEL(OnMouseWheel)
		MSG_WM_KEYDOWN(OnKeyDown)
		MSG_WM_SIZE(OnSize)
		MSG_WM_GETDLGCODE(OnGetDlgCode)
		MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST, WM_MOUSELAST, OnMouseMessage)
		MSG_WM_DESTROY(OnDestroy)
	END_MSG_MAP()

public:
	BOOL SetBgPic(LPCTSTR lpszFileName);
    BOOL SetHeadImg(LPCTSTR lpszFileName);
	
    void SetDataText(LPCTSTR pszNickName, LPCTSTR pszSignature, LPCTSTR pszMail, LPCTSTR pszAddress);

	void SetTransparent(BOOL bTransparent, HDC hBgDC);

private:
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnEraseBkgnd(CDCHandle dc);
	void OnPaint(CDCHandle dc);
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnRButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnMouseLeave();
	void OnTimer(UINT_PTR nIDEvent);
	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar pScrollBar);
	BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnSize(UINT nType, CSize size);
	UINT OnGetDlgCode(LPMSG lpMsg);
	LRESULT OnMouseMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnDestroy();

	void DrawParentWndBg(HDC hDC);

	BOOL StartTrackMouseLeave();
	void CalcCenterRect(CRect& rcDest, int cx, int cy, CRect& rcCenter);
	void HitTest(POINT pt, int& nTeamIndex, int& nIndex);


private:
	CToolTipCtrl			m_ToolTipCtrl;
	CSkinScrollBar			m_VScrollBar;//滚动条

	CImageEx*				m_lpBgImg;//背景图片
    CImageEx*               m_lpHeadImg;            //头像
	
	BOOL					m_bTransparent;

    BOOL                    m_bMouseTracking;//是否追踪鼠标


    CString                 m_strNickName;//用户昵称
    CString                 m_strSignature;//用户签名
    CString                 m_strMail;//用户邮箱
    CString                 m_strAddress;//用户地址
};
#endif