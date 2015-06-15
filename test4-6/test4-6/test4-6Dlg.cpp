
// test4-6Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test4-6.h"
#include "test4-6Dlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest46Dlg �Ի���


Ctest46Dlg::Ctest46Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest46Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest46Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest46Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Ctest46Dlg ��Ϣ�������

BOOL Ctest46Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//��������ļ�������
	int left=theApp.GetProfileInt("WindowRect","left",-1);
	int top=theApp.GetProfileInt("WindowRect","top",-1);
	int right=theApp.GetProfileInt("WindowRect","right",-1);
	int bottom=theApp.GetProfileInt("WindowRect","bottom",-1);
	//SetWindowText(theApp.m_lpCmdLine);
	CString str;
	str.Format("m_nCmdShow=%d",theApp.m_nCmdShow);
	SetWindowText(str);
	AfxMessageBox("�����⣡");
	SetDlgItemText(IDC_APPNAME,theApp.m_pszAppName);
	SetDlgItemText(IDC_EXENAME,theApp.m_pszExeName);
	SetDlgItemText(IDC_HELPNAME,theApp.m_pszHelpFilePath);
	SetDlgItemText(IDC_REGISTNAME,theApp.m_pszRegistryKey);
	SetDlgItemText(IDC_PROFILE,theApp.m_pszProfileName);
	//���ؽ���ͼ��
	//HICON hicon=theApp.LoadIcon(IDI_ICON1);
	//����ϵͳͼ��
	//HICON hicon=::LoadIcon(NULL,IDI_HAND);
	HICON hicon=theApp.LoadStandardIcon(IDI_HAND);
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(hicon, TRUE);			// ���ô�ͼ��
	//SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest46Dlg::OnPaint()
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
HCURSOR Ctest46Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//���ù��
BOOL Ctest46Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	HCURSOR hcur=theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(hcur);
	return TRUE;
	//return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}

//����ƶ�ʱ���ù��
void Ctest46Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	HCURSOR hcur=theApp.LoadStandardCursor(IDC_IBEAM);
	SetCursor(hcur);
	CDialogEx::OnMouseMove(nFlags, point);
}


void Ctest46Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	CRect rect;
	//��ô��ڵľ���
	GetWindowRect(rect);
	//������λ��д�뵽�����ļ���
	theApp.WriteProfileInt("WindowRect","left",rect.left);
	theApp.WriteProfileInt("WindowRect","top",rect.top);
	theApp.WriteProfileInt("WindowRect","right",rect.right);
	theApp.WriteProfileInt("WindowRect","bottom",rect.bottom);

	// TODO: �ڴ˴������Ϣ����������
}
