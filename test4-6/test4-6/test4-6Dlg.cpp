
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
END_MESSAGE_MAP()


// Ctest46Dlg ��Ϣ�������

BOOL Ctest46Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
	//����ͼ��
	HICON hicon=theApp.LoadIcon(IDI_ICON1);
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

