#include "stdafx.h"
#include "Line.h"


CLine::CLine(void)
{
	m_second.x=m_second.y=-1;
}


CLine::~CLine(void)
{
}
void CLine::ONLButtonDown(UINT flags, CPoint point)
{
	m_first=point;
}
void CLine::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_second=point;
}
//�����ߴ���
void CLine::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_first);
	pDC->LineTo(m_second);
}
void CLine::OnMouseMove(UINT nflags, CPoint point,CDC *pdc)
{
	if(!pdc)
		return;
	//�ж�����Ƿ���,������ʼ��ͼ
	if(nflags & MK_LBUTTON)
	{
		//����ǵڶ��λ���ͼ�Σ���ѵ�һ�λ��ƵĲ���
		pdc->SetROP2(R2_NOT);
		//����ڶ��λ��ƣ�������һ�λ��Ƶ�(����seirop���ٻ���һ�ξ��൱�ڲ�����)
		if(m_second.x>-1)
		{
			pdc->MoveTo(m_first);
			pdc->LineTo(m_second);
		}
		pdc->MoveTo(m_first);
		pdc->LineTo(point);
		m_second=point;
	}
}
