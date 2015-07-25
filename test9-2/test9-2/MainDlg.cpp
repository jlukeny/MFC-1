// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "test9-2Dlg.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "ModDlg.h"


// CMainDlg �Ի���

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMainDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMainDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDADD, &CMainDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDADD2, &CMainDlg::OnBnClickedAdd2)
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������


void CMainDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMainDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"�˺�",0,80);
	m_list.InsertColumn(1,"����",0,80);
	m_list.InsertColumn(2,"�Ա�",0,80);
	return TRUE;
}

//��Ӱ�ť
void CMainDlg::OnBnClickedAdd()
{
	Ctest92Dlg dlg;
	if(IDCANCEL==dlg.DoModal())
		return;
	int i=m_list.GetItemCount();
	m_list.InsertItem(i,dlg.m_p1.m_id);
	m_list.SetItemText(i,1,dlg.m_p2.m_name);
	m_list.SetItemText(i,2,dlg.m_p3.m_sex);
}

//�޸��û���Ϣ
void CMainDlg::OnBnClickedAdd2()
{
	if(!m_list.GetSelectedCount())
	{
		AfxMessageBox("��ѡ��һ��!");
		return;
	}
	int select=m_list.GetSelectionMark();
	CModDlg dlg;
	dlg.m_p1.m_id=m_list.GetItemText(select,0);
	dlg.m_p2.m_name=m_list.GetItemText(select,1);
	dlg.m_p3.m_sex=m_list.GetItemText(select,2);
	if(IDCANCEL==dlg.DoModal())
		return;
	m_list.SetItemText(select,0,dlg.m_p1.m_id);
	m_list.SetItemText(select,1,dlg.m_p2.m_name);
	m_list.SetItemText(select,2,dlg.m_p3.m_sex);
}
