
// test4_3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resource.h"
#include "test4_3.h"
#include "test4_3Dlg.h"
#include "afxdialogex.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4_3Dlg �Ի���


CWnd edit;
CMyButton button,button2;
Ctest4_3Dlg::Ctest4_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest4_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest4_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest4_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest4_3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest4_3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest4_3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest4_3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest4_3Dlg::OnBnClickedButton5)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, &Ctest4_3Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Ctest4_3Dlg ��Ϣ�������

BOOL Ctest4_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//��ñ����ڱ༭��ؼ��ľ��
	HWND hwnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	//��edit������þ����������Ϳ��Բ��ݸþ����Ӧ�Ŀؼ�
	edit.Attach(hwnd);
	//��һ�ֹ����ķ�����ͨ������button���Խ��մ�����Ϣ(MouseMove��Ϣ��)
	HWND hwnd2=::GetDlgItem(m_hWnd,IDC_BUTTON2);
	button.SubclassWindow(hwnd2);
	//�����ֹ�������������Ҫ�����ֻ��Ҫ�����ںͿؼ�id
	button2.SubclassDlgItem(IDC_BUTTON1,this);
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

void Ctest4_3Dlg::OnPaint()
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
HCURSOR Ctest4_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest4_3Dlg::OnBnClickedButton1()
{
	DestroyWindow();
}

CWnd list;
void Ctest4_3Dlg::OnBnClickedButton2()
{
	if(!list)
	{
		list.Create(_T("syslistview32"),NULL,WS_CHILD|WS_VISIBLE,CRect(10,80,200,200),this,8888);//_T()��unicode��ʽ����
	}
}


void Ctest4_3Dlg::OnBnClickedButton3()
{
	CWnd *p=GetDlgItem(IDOK);
	//if(p)
	HWND hwnd=p->GetSafeHwnd();//��ȫ�Ļ�ȡ�����ָ��Ϊ��Ҳ�������
	if(hwnd)
		p->DestroyWindow();
}

//�����ת��ΪCWnd
void Ctest4_3Dlg::OnBnClickedButton4()
{
	HWND hwnd=::GetDlgItem(m_hWnd,IDOK);
	CWnd *p=FromHandle(hwnd);
	p->SetWindowText(_T("ͨ����ʱ����Set"));
}


void Ctest4_3Dlg::OnBnClickedButton5()
{
	edit.SetWindowText(_T("ͨ��ȫ�ֶ���Set"));
}


void Ctest4_3Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	//�˳�֮ǰ����ȡ���������ڶ�����Attach��Ӧ
	edit.Detach();
	button.UnsubclassWindow();
}


void Ctest4_3Dlg::OnBnClickedButton6()
{
	//����һ����������
	CRect rect;
	//��øÿؼ���������(��Ļ����)
	edit.GetWindowRect(rect);
	//�ǰ���Ļ����ת��Ϊ��������
	ScreenToClient(rect);
	edit.MoveWindow(rect);
	//ʵʱ����
	Invalidate();

}
