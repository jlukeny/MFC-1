
// test9-4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-4.h"
#include "test9-4Dlg.h"
#include "afxdialogex.h"
#include "Cpage1.h"
#include "Cpage2.h"
#include "Cpage3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest94Dlg �Ի���



Ctest94Dlg::Ctest94Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest94Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest94Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(Ctest94Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDADD, &Ctest94Dlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// Ctest94Dlg ��Ϣ�������

BOOL Ctest94Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"�˺�",0,80);
	m_list.InsertColumn(1,"����",0,80);
	m_list.InsertColumn(2,"�Ա�",0,80);
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

void Ctest94Dlg::OnPaint()
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
HCURSOR Ctest94Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ӣ�ʹ�÷�ҳ��
void Ctest94Dlg::OnBnClickedAdd()
{
	CPropertySheet sheet("�û�����ע��");
	Cpage1 p1;
	Cpage2 p2;
	Cpage3 p3;
	sheet.AddPage(&p1);
	sheet.AddPage(&p2);
	sheet.AddPage(&p3);
	sheet.SetWizardMode();
	sheet.DoModal();
	

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
