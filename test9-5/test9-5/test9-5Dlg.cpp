
// test9-5Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-5.h"
#include "test9-5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest95Dlg �Ի���



Ctest95Dlg::Ctest95Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest95Dlg::IDD, pParent)
{
	changed=false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest95Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(Ctest95Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest95Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest95Dlg::OnBnClickedCancel)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &Ctest95Dlg::OnSelchangedTree)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest95Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest95Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Ctest95Dlg ��Ϣ�������

BOOL Ctest95Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.InsertColumn(0,"����",0,80);
	m_list.InsertColumn(1,"����",0,80);
	m_list.InsertColumn(2,"����",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	HTREEITEM treeroot=m_tree.InsertItem("�ܹ�˾");
	HTREEITEM tree1=m_tree.InsertItem("��Ϊ",treeroot);
	m_tree.InsertItem("������",tree1);
	m_tree.InsertItem("�з���",tree1);
	HTREEITEM tree2=m_tree.InsertItem("��Ѷ",treeroot);
	m_tree.InsertItem("������",tree2);
	m_tree.InsertItem("�з���",tree2);
	//չ�������
	m_tree.Expand(treeroot,TVE_EXPAND);
	m_tree.Expand(tree1,TVE_EXPAND);
	m_tree.Expand(tree2,TVE_EXPAND);
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest95Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������


		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest95Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest95Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void Ctest95Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
//���·��
CString Ctest95Dlg::GetPath(HTREEITEM item)
{
	CString str;
	while(item)
	{
		str=m_tree.GetItemText(item)+"\\"+str;
		item=m_tree.GetParentItem(item);//��ø��ڵ�

	}
	return str;
}
//������
int Ctest95Dlg::GetDepth(HTREEITEM item)
{
	int res=0;
	while(item)
	{
		item=m_tree.GetParentItem(item);
		res++;
	}
	return res;
}
//����ѡ����
void Ctest95Dlg::OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	if(changed)
	{
		if(IDYES==AfxMessageBox("�Ƿ񱣴棿",MB_YESNO))
			Save();
	}
	changed=false;
	HTREEITEM item=pNMTreeView->itemNew.hItem;//��õ�ǰ���
	CString str=GetPath(item);
	int depth=GetDepth(item);
	//�����Ҷ�ӽڵ㣬��Ӻ�ɾ����ť������Ч
	GetDlgItem(IDC_ADD)->EnableWindow(3==depth);
	GetDlgItem(IDC_DEL)->EnableWindow(3==depth);
	SetDlgItemText(IDC_TEXT,str);
	Load();
	*pResult = 0;
}

//���
void Ctest95Dlg::OnBnClickedButton1()
{
	int count=m_list.GetItemCount();
	int i=0;
	CString str;
	//��ù���
	GetDlgItemText(IDC_ID,str);
	//�жϹ����Ƿ����
	while(i<count)
	{
		if(str==m_list.GetItemText(i,0))
		{
			AfxMessageBox("�Ѿ����ڸù��ţ�");
			return ;
		}
		i++;
	}
	//������Ų����������
	m_list.InsertItem(i,str);
	GetDlgItemText(IDC_NAME,str);
	m_list.SetItemText(i,1,str);
	GetDlgItemText(IDC_PAY,str);
	m_list.SetItemText(i,2,str);
	changed=true;

}

//ɾ��
void Ctest95Dlg::OnBnClickedButton2()
{
	changed=true;
}
void Ctest95Dlg::Save()
{
	CString path;
	GetDlgItemText(IDC_TEXT,path);
	CFile file;
	if(!file.Open(path+"mem.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("�ļ�����ʧ�ܣ�");
		return ;
	}
	Info temp;
	int i=0,count=m_list.GetItemCount();
	while(i<count)
	{
		temp.id=atoi(m_list.GetItemText(i,0));
		strcpy_s(temp.name,m_list.GetItemText(i,1));
		temp.pay= atof(m_list.GetItemText(i,2));
		file.Write(&temp,sizeof(temp));
		i++;
	}
}
void Ctest95Dlg::Load()
{
	m_list.DeleteAllItems();
	CString path;
	GetDlgItemText(IDC_TEXT,path);
	CFile file;
	if(!file.Open(path+"mem.dat",CFile::modeRead))
	{
		AfxMessageBox("�ļ���ʧ�ܣ�");
		return ;
	}
	Info temp;
	CString str;
	int i=0;
	while(file.Read(&temp,sizeof(temp))   ==sizeof(temp))
	{
		str.Format("%d",temp.id);
		m_list.InsertItem(i,str);
		m_list.SetItemText(i,1,temp.name);
		str.Format("%0.2lf",temp.pay);
		m_list.SetItemText(i,2,str);
		i++;
	}

}