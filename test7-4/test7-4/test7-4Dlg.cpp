
// test7-4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test7-4.h"
#include "test7-4Dlg.h"
#include "afxdialogex.h"
#include "MemDC.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest74Dlg �Ի���



Ctest74Dlg::Ctest74Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest74Dlg::IDD, pParent)
{
	m_back.LoadmyBitmap("C:\\Users\\liuzhenwei\\Desktop\\ͼ��\\back.bmp");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest74Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest74Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Ctest74Dlg ��Ϣ�������

BOOL Ctest74Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);
	SetTimer(0,200,NULL);
	//��ȡ��Ļ�Ŀ�Ⱥ͸߶�
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(0,0,cx,cy,FALSE);
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest74Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest74Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��˸���⣺��������г���һ�����ϵ�����������ص����Խ���������Խ�࣬��˸Խ���أ����������������
//��������������еĴ�ӡ����ӡ���ڴ��У�Ȼ���ٴ�ӡ����Ļ��
void Ctest74Dlg::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	//����һ���ڴ������ȴ�ӡ���ڴ���
	CMemoryDC mdc(rect.Width(),rect.Height(),&dc);
	mdc.FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(0,255,0));
	mdc.BitBlt(0,0,m_back.GetWidth(),m_back.GetHeight(),&m_back,0,0,SRCCOPY);
	//���ڿ�ʼ��ӡ����Ļ��
	dc.BitBlt(0,0,mdc.GetWidth(),mdc.GetHeight(),&mdc,0,0,SRCCOPY);
	CDialogEx::OnTimer(nIDEvent);
}
