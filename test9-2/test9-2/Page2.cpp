// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2::IDD, pParent)
	, m_name(_T(""))
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPage2::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPage2::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������


void CPage2::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CPage2::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
