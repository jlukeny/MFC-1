// MyButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test4_3.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CWnd)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CWnd)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CMyButton ��Ϣ�������



//����Ƶ���һ����ڶ���Button�ϴ���
void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CWnd::OnMouseMove(nFlags, point);
}
