
// test9-5Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-5.h"
#include "test9-5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest95Dlg �Ի���



Ctest95Dlg::Ctest95Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest95Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest95Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(Ctest95Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest95Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest95Dlg::OnBnClickedCancel)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &Ctest95Dlg::OnSelchangedTree)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest95Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest95Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Ctest95Dlg ��Ϣ�������

BOOL Ctest95Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"����",0,80);
	m_list.InsertColumn(1,"����",0,80);
	m_list.InsertColumn(2,"����",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	HTREEITEM treeroot=m_tree.InsertItem("�ܹ�˾");
	HTREEITEM tree1=m_tree.InsertItem("��Ϊ",treeroot);
	m_tree.InsertItem("������",tree1);
	m_tree.InsertItem("�з���",tree1);
	HTREEITEM tree2=m_tree.InsertItem("��Ѷ",treeroot);
	m_tree.InsertItem("������",tree2);
	m_tree.InsertItem("�з���",tree2);
	//չ�������
	m_tree.Expand(treeroot,TVE_EXPAND);
	m_tree.Expand(tree1,TVE_EXPAND);
	m_tree.Expand(tree2,TVE_EXPAND);
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

void Ctest95Dlg::OnPaint()
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
HCURSOR Ctest95Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest95Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void Ctest95Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
//���·��
CString Ctest95Dlg::GetPath(HTREEITEM item)
{
	CString str;
	while(item)
	{
		str=m_tree.GetItemText(item)+"\\"+str;
		item=m_tree.GetParentItem(item);//��ø��ڵ�

	}
	return str;
}
//����ѡ����
void Ctest95Dlg::OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	HTREEITEM item=pNMTreeView->itemNew.hItem;//��õ�ǰ���
	CString str=GetPath(item);
	SetDlgItemText(IDC_TEXT,str);
	*pResult = 0;
}

//���
void Ctest95Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//ɾ��
void Ctest95Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
