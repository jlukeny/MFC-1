// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

	CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedOk()
{
	CString strName,strPassword;
	GetDlgItemText(IDC_LOGIN,strName);
	GetDlgItemText(IDC_PASSWORD,strPassword);
	if(strName=="admin" && strPassword=="1")
		CDialogEx::OnOK();
	else
	{
		AfxMessageBox("�û��������������");
		SetDlgItemText(IDC_LOGIN,"");
		SetDlgItemText(IDC_PASSWORD,"");
		//���ý���
		GetDlgItem(IDC_LOGIN)->SetFocus();
	}
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
