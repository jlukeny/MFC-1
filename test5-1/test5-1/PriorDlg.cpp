// PriorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "PriorDlg.h"
#include "afxdialogex.h"


// CPriorDlg �Ի���

IMPLEMENT_DYNAMIC(CPriorDlg, CDialogEx)

CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPriorDlg::IDD, pParent)
{

}

CPriorDlg::~CPriorDlg()
{
}

void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPriorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPriorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &CPriorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CPriorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_MODIFY, &CPriorDlg::OnBnClickedModify)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPriorDlg::OnCbnSelchangeCombo1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CPriorDlg ��Ϣ�������


void CPriorDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CPriorDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

//����˻�
void CPriorDlg::OnBnClickedAdd()
{
	user u;
	//����˺���
	GetDlgItemText(IDC_EDIT1,u.name,sizeof(u.name));//c���Ժ������ռ�����
	GetDlgItemText(IDC_EDIT2,u.pass,sizeof(u.pass));
	//c�����бȽ������ַ�����strcmp��������==
	if(!strcmp(u.name,"")||!strcmp(u.pass,""))
	{
		AfxMessageBox("�˺ź����벻����Ϊ�գ�");
		return ;
	}
	//���list�ؼ�
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//list�е��˺���
	int count=p->GetItemCount(),i=0;
	//����list�е��˺�
	while(i<count)
	{
		//������и��˺������
		if(p->GetItemText(i,0)==u.name)
		{
			AfxMessageBox("�Ѿ����и��˺ţ�");
			return;
		}
		i++;
	}
	//û�и��˺���������,��list�����һ�У���insertitem(�кţ�ֵ),��setItemtext���кţ��кţ�ֵ��
	p->InsertItem(count,u.name);
	
	p->SetItemText(count,1,u.pass);
	//���combobox�ؼ�����������ֵ����������
	CComboBox * combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
	u.prior=combo->GetCurSel();
	if(u.prior==0)
		p->SetItemText(count,2,"��ͨ");
	else if(u.prior==1)
		p->SetItemText(count,2,"����Ա");

}

//ɾ���˻�
void CPriorDlg::OnBnClickedDel()
{
	//����б�ؼ�
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//���ɾ�����к�
	//int index=p->GetSelectionMark();
	//���ɾ�������ͷ���
	POSITION pos=p->GetFirstSelectedItemPosition();
	//���ɾ�����к�
	int index=p->GetNextSelectedItem(pos);
	//�ж��Ƿ���ѡ�е�
	if(index<0)
	{
		AfxMessageBox("��ѡ��һ�");
	}
	//�ж�ѡ�е��Ƿ���admin
	else if(p->GetItemText(index,0)=="admin")
		AfxMessageBox("������ɾ��admin");
	else
	{
		CString str;
		str.Format("ȷ��Ҫɾ��%sô��",p->GetItemText(index,0));
		if(IDYES==AfxMessageBox(str,MB_YESNO))
			p->DeleteItem(index);
	}
}

//�޸��˻���Ϣ
void CPriorDlg::OnBnClickedModify()
{
	//����б�ؼ�
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	//���ɾ�����к�
	//int index=p->GetSelectionMark();
	//���ɾ�������ͷ���
	POSITION pos=p->GetFirstSelectedItemPosition();
	//���ɾ�����к�
	int index=p->GetNextSelectedItem(pos);
	//�ж��Ƿ���ѡ�е�
	if(index<0)
	{
		AfxMessageBox("��ѡ��һ�");
	}
	//�ж�ѡ�е��Ƿ���admin
	else if(p->GetItemText(index,0)=="admin")
		AfxMessageBox("�������޸�admin");
	else
	{
		CString str;
		str.Format("ȷ��Ҫ�޸�%sô��",p->GetItemText(index,0));
		//ȷ���޸�
		if(IDYES==AfxMessageBox(str,MB_YESNO))
		{
			//�����������
			CString pass;
			GetDlgItemText(IDC_EDIT2,pass);
			//���������޸�
			p->SetItemText(index,1,pass);
			//���Ȩ������
			CComboBox *combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
			int prior=combo->GetCurSel();
			p->SetItemText(index,2,prior?"����Ա":"��ͨ");
		}
	}
}
//���ļ���Ϣ�����б�
void CPriorDlg::Readuesr(CListCtrl * p)
{
	CFile file;
	if(!file.Open("./users.dat",CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("��ȡ��Ϣʧ�ܣ�");
		return ;
	}
	p->DeleteAllItems();
	user u;
	int i=0;
	//��ȡ���ݲ��뵽list��
	while(file.Read(&u,sizeof(u))>0)
	{
		p->InsertItem(i,u.name);
		p->SetItemText(i,1,u.pass);
		p->SetItemText(i,2,u.prior?"����Ա":"��ͨ");
		i++;
	}
	file.Close();
}
BOOL CPriorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	p->InsertColumn(0,"�˺�",0,150);//����������Ϊ�������ã�0Ϊ�����
	p->InsertColumn(1,"����",0,150);
	p->InsertColumn(2,"Ȩ��",0,150);
	Readuesr(p);
	CComboBox *combo=(CComboBox *)GetDlgItem(IDC_COMBO1);
	combo->AddString("��ͨ");
	combo->AddString("����Ա");
	combo->SetCurSel(0);
	Invalidate();
	return TRUE;
}


void CPriorDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPriorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	CFile file;
	if(!file.Open("./users.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("д���ļ�����");
		return;
	}
	user u;
	CListCtrl *p=(CListCtrl *)GetDlgItem(IDC_LIST1);
	int count=p->GetItemCount(),i=0;
	while(i<count)
	{
		p->GetItemText(i,0,u.name,sizeof(u.name));
		p->GetItemText(i,1,u.pass,sizeof(u.pass));
		u.prior=(p->GetItemText(i,2)=="����Ա");
		file.Write(&u,sizeof(u));
		i++;
	}
	file.Close();
}



