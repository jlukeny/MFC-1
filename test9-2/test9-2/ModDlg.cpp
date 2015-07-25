// ModDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "ModDlg.h"
#include "afxdialogex.h"


// CModDlg �Ի���

IMPLEMENT_DYNAMIC(CModDlg, CDialogEx)

CModDlg::CModDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModDlg::IDD, pParent)
{

}

CModDlg::~CModDlg()
{
}

void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CModDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CModDlg::OnBnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CModDlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// CModDlg ��Ϣ�������

//ȷ���޸�
void CModDlg::OnBnClickedOk()
{
	//��������µ��ڴ棨m_p1����
	m_p1.UpdateData();
	m_p2.UpdateData();
	m_p3.UpdateData();
	CDialogEx::OnOK();
}


void CModDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL CModDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_tab�в���˵���
	m_tab.InsertItem(0,"�˺�");
	m_tab.InsertItem(1,"����");
	m_tab.InsertItem(2,"�Ա�");
	//������ҳ
	m_p1.Create(IDD_DIALOG1,this);
	m_p2.Create(IDD_DIALOG2,this);
	m_p3.Create(IDD_DIALOG3,this);
	//���m_tab�ķ���λ��
	CRect rect,rt;
	m_tab.GetWindowRect(rect);
	ScreenToClient(rect);
	//��ñ�ͷ��λ��
	m_tab.GetItemRect(0,rt);
	//�����ҳλ��
	rect.top+=rt.Height();
	//�߶ȺͿ�ȶ���С3
	rect.DeflateRect(3,3);
	//��ҳ�ƶ���rectλ��
	m_p1.MoveWindow(rect,FALSE);
	m_p2.MoveWindow(rect,FALSE);
	m_p3.MoveWindow(rect,FALSE);
	m_p1.MoveWindow(rect,FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control

}

//m_tab��ͷ����ʱ����
void CModDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int sel=m_tab.GetCurSel();
	CWnd *ps[]={&m_p1,&m_p2,&m_p3};
	int i=0;
	while(i<sizeof(ps)/sizeof(ps[0]))
		ps[i++]->ShowWindow(i==sel?SW_SHOW:SW_HIDE);
	*pResult = 0;
}
