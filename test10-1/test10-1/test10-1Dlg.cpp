
// test10-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test10-1.h"
#include "test10-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest101Dlg �Ի���



Ctest101Dlg::Ctest101Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest101Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest101Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO, m_com);
}

BEGIN_MESSAGE_MAP(Ctest101Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Ctest101Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &Ctest101Dlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// Ctest101Dlg ��Ϣ�������

BOOL Ctest101Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"����",0,300);
	m_list.InsertColumn(1,"����",0,300);
	images.Create(24,24,ILC_COLOR32|ILC_MASK,0,4);
	//images.Create(IDB_BITMAP1,20,5,RGB(255,255,255));
	int i=0;
	while(i<5)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1+(i++));
		images.Add(&bitmap,RGB(0,0,0));
	}
	m_list.SetImageList(&images,LVSIL_SMALL);
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

void Ctest101Dlg::OnPaint()
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
HCURSOR Ctest101Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest101Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

//���
void Ctest101Dlg::OnBnClickedAdd()
{
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	int i=m_list.GetItemCount();
	m_list.InsertItem(i,str,m_com.GetCurSel());
	m_com.GetWindowText(str);
	m_list.SetItemText(i,1,str);
	//����ͼ�����ʹ��SetItem������ΪLVITEM�ṹ�壩
}
