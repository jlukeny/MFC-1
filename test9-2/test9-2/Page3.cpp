// Page3.cpp : 实现文件
//

#include "stdafx.h"
#include "test9-2.h"
#include "Page3.h"
#include "afxdialogex.h"


// CPage3 对话框

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


// CPage3 消息处理程序


void CPage3::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CPage3::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}
