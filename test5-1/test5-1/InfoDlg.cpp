// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// CInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfoDlg::IDD, pParent)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInfoDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CInfoDlg ��Ϣ�������


void CInfoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CInfoDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
