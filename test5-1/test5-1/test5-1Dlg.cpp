
// test5-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "test5-1Dlg.h"
#include "afxdialogex.h"
#include "logindlg.h"
#include "Priordlg.h"
#include "InfoDlg.h"
//extern Ctest51App theApp;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest51Dlg �Ի���



Ctest51Dlg::Ctest51Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest51Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//�������ļ���ȡǰ��ɫ�ͱ���ɫ
	//Ctrlbk=theApp.GetProfileInt("Settings","CtrlColor",RGB(0,0,0));
}

void Ctest51Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest51Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Ctest51Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDRELOGIN, &Ctest51Dlg::OnBnClickedRelogin)
	ON_BN_CLICKED(IDSEARCH, &Ctest51Dlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDINFO, &Ctest51Dlg::OnBnClickedInfo)
	ON_BN_CLICKED(IDCOLOR, &Ctest51Dlg::OnBnClickedColor)
	//	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDCOLOR2, &Ctest51Dlg::OnBnClickedColor2)
END_MESSAGE_MAP()


// Ctest51Dlg ��Ϣ�������

BOOL Ctest51Dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	CString title=theApp.info.name;
	SetWindowText(title);
	GetDlgItem(IDSEARCH)->EnableWindow(theApp.info.prior);//��ͨ�û��޷�����˻�
	//����ǰ��ɫ�ͱ���ɫ
	theApp.Ctrlbk=GetProfileInt("Settings","CtrlColor",RGB(128,128,128));
	theApp.Textbk=GetProfileInt("Settings","TextColor",RGB(155,0,0));
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest51Dlg::OnPaint()
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
HCURSOR Ctest51Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest51Dlg::OnBnClickedCancel()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnCancel();
}

//���µ�¼
void Ctest51Dlg::OnBnClickedRelogin()
{
	ShowWindow(SW_HIDE);
	CLoginDlg login;
	int result=login.DoModal();
	if(IDCANCEL==result)
		OnCancel();
	else
	{
		CString title=theApp.info.name;
		SetWindowText(title);
		GetDlgItem(IDSEARCH)->EnableWindow(theApp.info.prior);//��ͨ�û��޷�����˻�
		ShowWindow(SW_SHOW);
	}
}

//�����˻�
void Ctest51Dlg::OnBnClickedSearch()
{
	ShowWindow(SW_HIDE);
	CPriorDlg prior;
	prior.DoModal();
	ShowWindow(SW_SHOW);
}

//Ա����Ϣ����ɾ�Ĳ�
void Ctest51Dlg::OnBnClickedInfo()
{
	ShowWindow(SW_HIDE);
	CInfoDlg info;
	info.DoModal();
	ShowWindow(SW_SHOW);
}

//���ñ���ɫ�ķ���
void Ctest51Dlg::OnBnClickedColor()
{
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return ;
	COLORREF col=dlg.GetColor();
	theApp.Ctrlbk=col;
	//ʵʱ����
	Invalidate();
}

//����������ɫ�ķ���
void Ctest51Dlg::OnBnClickedColor2()
{
	CColorDialog dlg;
	if(IDCANCEL==dlg.DoModal())
		return ;
	COLORREF col=dlg.GetColor();
	theApp.Textbk=col;
	//ʵʱ����
	Invalidate();
}

//���ñ���ɫ����ʵ�� �ο���  http://www.cnblogs.com/staring-hxs/archive/2013/01/09/2853126.html
HBRUSH Ctest51Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//OnCtlColor�ܸı�Static���ӿؼ�����ɫ������Button��������������Owner DrawΪTrue,���ܸı�Button��ť����ɫ��CButton �ı���������ɫ������ͨ��SetBkColor���ı䣬��Ҫ�Լ��ػ�CButton����DrawItem�н���ʵ�֡�
	if(nCtlColor==CTLCOLOR_DLG)
	{
		pDC->SetBkColor(theApp.Ctrlbk);
		HBRUSH b=CreateSolidBrush(theApp.Ctrlbk);
		//�������õ���ɫ
		return b;
	}
	else if(nCtlColor==CTLCOLOR_BTN)
	{
		pDC->SetTextColor(theApp.Textbk);
	}

	//if(pWnd->GetDlgCtrlID()==IDC_ADD)
	//
	//{
	//	pDC->SetTextColor(theApp.Textbk);
	//}
	return hbr;
}


