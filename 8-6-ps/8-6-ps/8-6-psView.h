
// 8-6-psView.h : CMy86psView ��Ľӿ�
//

#pragma once
#include "Layer.h"

class CMy86psView : public CView
{
protected: // �������л�����
	int select;
	CArray<CLayer*,CLayer*> m_list;
	CMy86psView();
	DECLARE_DYNCREATE(CMy86psView)

// ����
public:
	CMy86psDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy86psView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawMove();
	afx_msg void OnUpdateDrawMove(CCmdUI *pCmdUI);
	afx_msg void OnLine();
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnElli();
	afx_msg void OnUpdateElli(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 8-6-psView.cpp �еĵ��԰汾
inline CMy86psDoc* CMy86psView::GetDocument() const
   { return reinterpret_cast<CMy86psDoc*>(m_pDocument); }
#endif

