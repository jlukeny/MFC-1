// Cpage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage1.h"
#include "afxdialogex.h"


// Cpage1 �Ի���

IMPLEMENT_DYNAMIC(Cpage1, CPropertyPage)

Cpage1::Cpage1()
	: CPropertyPage(Cpage1::IDD)
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage1, CPropertyPage)
END_MESSAGE_MAP()


// Cpage1 ��Ϣ�������


BOOL Cpage1::OnSetActive()
{		
	//��һҳ������һ����ť�����ذ�ť����
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(2);

	return CPropertyPage::OnSetActive();
}
