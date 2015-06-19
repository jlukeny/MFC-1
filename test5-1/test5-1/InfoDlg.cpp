// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "insertpeople.h"


// CInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfoDlg::IDD, pParent)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInfoDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &CInfoDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_QUIT, &CInfoDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_MODIFY, &CInfoDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_DEL, &CInfoDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_OPEN, &CInfoDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CInfoDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CInfoDlg ��Ϣ�������


void CInfoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CInfoDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}


BOOL CInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	p.SubclassDlgItem(IDC_LIST1,this);
	p.InsertColumn(0,"����",0,60);
	p.InsertColumn(1,"����",0,60);
	p.InsertColumn(2,"����",0,100);
	p.InsertColumn(3,"����",0,100);
	p.InsertColumn(4,"����",0,100);
	return TRUE;
}

//��ӳ�Ա
void CInfoDlg::OnBnClickedAdd()
{
	CInsertPeople dlg;
	//����InsertPeople�Ի����infodlgָ�루ָ��CInfoDlg����������InsertPeople�Ի����оͿ��Ը�CInfoDlg�е��б�ؼ���ֵ��
	dlg.infodlg=this;
	dlg.DoModal();
}

//�˳�
void CInfoDlg::OnBnClickedQuit()
{
	CDialogEx::OnCancel();
}

//�޸�Ա����Ϣ
void CInfoDlg::OnBnClickedModify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//ɾ��Ա����Ϣ
void CInfoDlg::OnBnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//���ļ���ȡԱ����Ϣ
void CInfoDlg::OnBnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//��Ա����Ϣ���浽�ļ���
void CInfoDlg::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
