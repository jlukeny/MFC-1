// Cpage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-4.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 �Ի���

IMPLEMENT_DYNAMIC(Cpage3, CPropertyPage)

Cpage3::Cpage3()
	: CPropertyPage(Cpage3::IDD)
	, m_sex(_T(""))
{

}

Cpage3::~Cpage3()
{
}

void Cpage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEX, m_sex);
}


BEGIN_MESSAGE_MAP(Cpage3, CPropertyPage)
END_MESSAGE_MAP()


// Cpage3 ��Ϣ�������


BOOL Cpage3::OnSetActive()
{
	//���һҳ������ɰ�ť�ͷ��ذ�ť
	CPropertySheet *sheet=(CPropertySheet *)GetParent();
	sheet->SetWizardButtons(1|4);

	return CPropertyPage::OnSetActive();
}
