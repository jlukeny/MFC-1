// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
extern Ctest51App theApp;//���������û���Ϣ


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
	if(CheckUser(strName,strPassword))
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


bool CLoginDlg::CheckUser(CString name, CString pass)
{
	//CString strName,strPassword;
	CFile file;
	if(!file.Open("./users.dat",CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("��¼ʧ�ܣ��˺Ų�����");
		return FALSE ;
	}
	user u;
	while(file.Read(&u,sizeof(u)))
	{
		if(u.name==name && u.pass==pass)
		{
			theApp.info=u;
			return TRUE;
		}
	}
	return FALSE;
}
