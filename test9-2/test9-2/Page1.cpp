// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 �Ի���

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1::IDD, pParent)
	, m_id(_T(""))
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID, m_id);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPage1::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPage1::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPage1 ��Ϣ�������


void CPage1::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CPage1::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
