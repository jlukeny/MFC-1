// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 �Ի���

IMPLEMENT_DYNAMIC(Cpage2, CPropertyPage)

Cpage2::Cpage2()
	: CPropertyPage(Cpage2::IDD)
	, m_name(_T(""))
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
}


BEGIN_MESSAGE_MAP(Cpage2, CPropertyPage)
END_MESSAGE_MAP()


// Cpage2 ��Ϣ�������


BOOL Cpage2::OnSetActive()
{
		//�ڶ�ҳ������һ����ť�ͷ��ذ�ť
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(1|2);

	return CPropertyPage::OnSetActive();
}
