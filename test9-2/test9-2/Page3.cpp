// Page3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page3.h"
#include "afxdialogex.h"


// CPage3 �Ի���

IMPLEMENT_DYNAMIC(CPage3, CDialogEx)

CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage3::IDD, pParent)
	, m_sex(_T(""))
{

}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEX, m_sex);
}


BEGIN_MESSAGE_MAP(CPage3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPage3::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPage3::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPage3 ��Ϣ�������


void CPage3::OnBnClickedOk()
{
	//�س��൱�ڵ�������ڵ����
	GetParent()->PostMessage(WM_COMMAND,IDOK);
	//CDialogEx::OnOK();
}


void CPage3::OnBnClickedCancel()
{
	// ��Esc�൱�ڵ�������ڵ�ȡ����ť���ڴ�֮ǰ�Ӵ��ڱ����ý���
	GetParent()->PostMessage(WM_COMMAND,IDCANCEL);
	//CDialogEx::OnCancel();
}
