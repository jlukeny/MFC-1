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
	ON_BN_CLICKED(IDOK, &CInsertPeople::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertPeople ��Ϣ�������

//���һ��Ա����Ϣ
void CInsertPeople::OnBnClickedOk()
{
	//����list�ؼ���infodlg->p��������
	CListCtrl &list=infodlg->p;
	//���Ҫ�����id
	CString id;
	GetDlgItemText(IDC_EDIT1,id);
	//����list���Ƿ��У�û�������
	int i=0,count=list.GetItemCount();
	while(i<count)
	{
		if(id==list.GetItemText(i,0))
		{
			CString str;
			str.Format("����%s�Ѿ�����",id);
			AfxMessageBox(str);
			return ;
		}
		i++;
	}
	if(IDNO==AfxMessageBox("ȷ����Ӹü�¼ô��",MB_YESNO))
		return;
	//����һ��
	list.InsertItem(i,id);
	//�������������
	GetDlgItemText(IDC_EDIT2,id);
	list.SetItemText(i,1,id);
	//������䲢����
	GetDlgItemText(IDC_DATETIMEPICKER1,id);
	list.SetItemText(i,2,id);
	//������䲢����
	GetDlgItemText(IDC_COMBOBUMEN,id);
	list.SetItemText(i,3,id);
	//��ù��ʲ�����
	GetDlgItemText(IDC_EDIT5,id);
	list.SetItemText(i,4,id);
	//����б�ؼ������ý���
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,"");
	SetDlgItemText(IDC_DATETIMEPICKER1,"");
	SetDlgItemText(IDC_COMBOBUMEN,"");
	SetDlgItemText(IDC_EDIT5,"");
	//���ý���
	GetDlgItem(IDC_EDIT1)->SetFocus();

}

//����Ա��֮ǰ���пؼ��ĳ�ʼ��
BOOL CInsertPeople::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//��ʼ���ؼ��е���ֵ
	//SetDlgItemText(IDC_DATETIMEPICKER1,"1994/5/12");�����������ʼ������
	CDateTimeCtrl *ptime=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER1);
	CTime time(1994,5,12,0,0,0);
	ptime->SetTime(&time);
	SetDlgItemText(IDC_COMBOBUMEN,"������");
	return TRUE;
}
