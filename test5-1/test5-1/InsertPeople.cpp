// InsertPeople.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "InsertPeople.h"
#include "afxdialogex.h"


// CInsertPeople �Ի���

IMPLEMENT_DYNAMIC(CInsertPeople, CDialogEx)

CInsertPeople::CInsertPeople(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertPeople::IDD, pParent)
{

}

CInsertPeople::~CInsertPeople()
{
}

void CInsertPeople::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInsertPeople, CDialogEx)
END_MESSAGE_MAP()


// CInsertPeople ��Ϣ�������
