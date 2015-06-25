// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-1.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "insertpeople.h"
#include "ModifyDlg.h"


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
	POSITION pos=p.GetFirstSelectedItemPosition();
	if(p.GetSelectedCount()==0)
	{
		AfxMessageBox("��ѡ��һ���޸ģ�");
		return;
	}
	//�������
	int sel=p.GetNextSelectedItem(pos);
	//���޸ĶԻ����еı�����ֵ���öԻ����ʼ��ʱ��������ؼ���ֵ
	CModifyDlg dlg;
	dlg.m_id=atoi(p.GetItemText(sel,0));
	dlg.m_name=p.GetItemText(sel,1);
	dlg.m_birth.ParseDateTime(p.GetItemText(sel,2));
	dlg.m_bumen=p.GetItemText(sel,3);
	dlg.m_pay=(float)atof(p.GetItemText(sel,4));
	if(IDCANCEL==dlg.DoModal())
	{
		return;
	}
	//����ȷ����Ի���󶨵Ŀؼ��ḳֵ����������������ֵ��list�ؼ����¼���
	CString str;
	str.Format("%d",dlg.m_id);
	p.SetItemText(sel,0,str);
	p.SetItemText(sel,1,dlg.m_name);
	p.SetItemText(sel,2,dlg.m_birth.Format(VAR_DATEVALUEONLY));//����ʹ��dlg.m_birth.Format("%Y%m%d")
	p.SetItemText(sel,3,dlg.m_bumen);
	str.Format("%0.2f",dlg.m_pay);
	p.SetItemText(sel,4,str);
}

//ɾ��Ա����Ϣ
void CInfoDlg::OnBnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//���ļ���ȡԱ����Ϣ
void CInfoDlg::OnBnClickedOpen()
{
	CFileDialog dlg(TRUE);
	if(IDCANCEL==dlg.DoModal())
		return;
	//����ļ�·��
	CString filepath=dlg.GetPathName();
	//��ʼ��list�е�����д���ļ�
	CFile file;
	if(!file.Open(filepath,CFile::shareDenyNone|CFile::modeRead))
	{
		AfxMessageBox("�ļ���ʧ�ܣ�");
		return ;
	}
	//ɾ���б�����������
	p.DeleteAllItems();
	int i=0;
	info mes;
	while(file.Read(&mes,sizeof(mes))>0)
	{
		//��ȡ�ļ��е����ݵ�list��
		CString str;
		str.Format("%d",mes.nnum);
		p.InsertItem(i,str);
		p.SetItemText(i,1,mes.strname);
		p.SetItemText(i,2,mes.birth);
		p.SetItemText(i,3,mes.strdepartment);
		str.Format("%0.1f",mes.pay);
		p.SetItemText(i,4,str);
		i++;
	}
}

//��Ա����Ϣ���浽�ļ���
void CInfoDlg::OnBnClickedSave()
{
	LPCSTR filter="Ա����Ϣ(*.dat)|*.dat|�����ļ�(*.*)|*.*||";
	CFileDialog dlg(FALSE,"dat","Ա����Ϣ",OFN_OVERWRITEPROMPT,filter);//��һ������ָʾ�����Ϊ����ʽ�򿪣��ڶ�����ʾĬ�Ϻ�׺������������ʾĬ���ļ��������ĸ���ʾ��ʽ���������ʾ�������͵Ŀ�ѡ��
	if(IDCANCEL==dlg.DoModal())
		return;
	//����ļ�·��
	CString filepath=dlg.GetPathName();
	//��ʼ��list�е�����д���ļ�
	CFile file;
	if(!file.Open(filepath,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("���ݱ���ʧ�ܣ�");
		return ;
	}
	int i=0,count=p.GetItemCount();
	while(i<count)
	{
		//��list�е�����д��ṹ�壬Ȼ�󽫽ṹ��д���ļ�
		info mes;
		mes.nnum=atoi(p.GetItemText(i,0));
		p.GetItemText(i,1,mes.strname,sizeof(mes.strname));
		p.GetItemText(i,2,mes.birth,sizeof(mes.birth));
		p.GetItemText(i,3,mes.strdepartment,sizeof(mes.strdepartment));
		mes.pay=atof(p.GetItemText(i,4));
		file.Write(&mes,sizeof(mes));
		i++;
	}
	file.Close();
}
