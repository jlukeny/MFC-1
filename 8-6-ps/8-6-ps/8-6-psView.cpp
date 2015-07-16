
// 8-6-psView.cpp : CMy86psView ���ʵ��
//

#include "stdafx.h"
#include "Elli.h"
#include "Line.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "8-6-ps.h"
#endif

#include "8-6-psDoc.h"
#include "8-6-psView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy86psView

IMPLEMENT_DYNCREATE(CMy86psView, CView)

BEGIN_MESSAGE_MAP(CMy86psView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_MOVE, &CMy86psView::OnDrawMove)
	ON_UPDATE_COMMAND_UI(ID_DRAW_MOVE, &CMy86psView::OnUpdateDrawMove)
	ON_COMMAND(ID_LINE, &CMy86psView::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMy86psView::OnUpdateLine)
	ON_COMMAND(ID_ELLI, &CMy86psView::OnElli)
	ON_UPDATE_COMMAND_UI(ID_ELLI, &CMy86psView::OnUpdateElli)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy86psView ����/����

CMy86psView::CMy86psView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy86psView::~CMy86psView()
{
}

BOOL CMy86psView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy86psView ����

void CMy86psView::OnDraw(CDC* pDC)
{
	select=0;
	CMy86psDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//����ͼ��
	int i=0,count=m_list.GetCount();
	CLayer *layer=NULL;
	//ѭ������lisi�е�ͼ��
	while(i<count)
	{
		layer=m_list[i++];
		//�������ondraw����
		layer->OnDraw(pDC);
	}
}

void CMy86psView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy86psView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy86psView ���

#ifdef _DEBUG
void CMy86psView::AssertValid() const
{
	CView::AssertValid();
}

void CMy86psView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy86psDoc* CMy86psView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy86psDoc)));
	return (CMy86psDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy86psView ��Ϣ�������


void CMy86psView::OnDrawMove()
{
	// TODO: �ڴ���������������
}


void CMy86psView::OnUpdateDrawMove(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


void CMy86psView::OnLine()
{
	select=ID_LINE;
}


void CMy86psView::OnUpdateLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetRadio(select==ID_LINE);
}


void CMy86psView::OnElli()
{
	select=ID_ELLI;
}


void CMy86psView::OnUpdateElli(CCmdUI *pCmdUI)
{
	pCmdUI->SetRadio(select==ID_ELLI);//Ϊtrue'��ð�ťΪѡ��״̬
}


void CMy86psView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//�ж�ѡ�������ֻ�ͼ��
	CLayer *layer=NULL;
	switch(select)
	{
	case ID_LINE:
		layer=new CLine();
		break;
	case ID_ELLI:
		layer=new CElli();
		break;
	}
	//����л�ͼ�࣬�������m_list��
	if(layer)
	{
		//��ʼ����
		layer->ONLButtonDown(nFlags,point);
		//�����ͼ�༯��
		m_list.Add(layer);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy86psView::OnLButtonUp(UINT nFlags, CPoint point)
{
	int count=m_list.GetCount();
	if(!count)
		return;
	//�ҵ�list�е����Ļ�ͼ��
	CLayer *layer=m_list[count-1];
	//��������
	layer->OnLButtonUp(nFlags, point);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMy86psView::OnMouseMove(UINT nFlags, CPoint point)
{
	int count=m_list.GetCount();
	if(!count)
		return;
	//��ʱ��ͼ����dc
	CClientDC dc(this);
	CLayer *layer=m_list[count-1];
	layer->OnMouseMove(nFlags,point,&dc);

	CView::OnMouseMove(nFlags, point);
}
//���ѡ��״̬��ֱ���жϵ㵽ֱ�ߵľ��룬�����ж�ÿһ����͵�ǰ����point�Ƿ���ȣ���Բ�ж�point�Ƿ��ڸ���Բ��