
// test9-2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-2.h"
#include "test9-2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest92Dlg �Ի���



Ctest92Dlg::Ctest92Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest92Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//void Ctest92Dlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}

BEGIN_MESSAGE_MAP(Ctest92Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest92Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDNEXT, &Ctest92Dlg::OnBnClickedNext)
	ON_BN_CLICKED(IDCANCEL, &Ctest92Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDBEFOR, &Ctest92Dlg::OnBnClickedBefor)
END_MESSAGE_MAP()


// Ctest92Dlg ��Ϣ�������

BOOL Ctest92Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sel=0;//��ǰҳΪPage1
	m_p1.Create(IDD_DIALOG1,this);
	m_p2.Create(IDD_DIALOG2,this);
	m_p3.Create(IDD_DIALOG3,this);
	CRect rect,rt;
	//��ÿͻ���
	GetClientRect(rect);
	//���OK��ť������
	GetDlgItem(IDOK)->GetWindowRect(rt);//���������GetWindowRect������GEtClientRect
	//���ͻ�����ĵײ�����ΪIDOK�Ķ���
	ScreenToClient(rt);
	rect.bottom=rt.top;
	//��һ���Ի����Ƶ�������
	m_p1.MoveWindow(rect);//����m_p1��visibleΪtrue����һ��ʼ��ʾm_p1
	m_p2.MoveWindow(rect);
	m_p3.MoveWindow(rect);
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

void Ctest92Dlg::OnPaint()
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
HCURSOR Ctest92Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest92Dlg::OnBnClickedOk()
{
	m_p1.UpdateData();
	m_p2.UpdateData();
	m_p3.UpdateData();
	EndDialog(IDOK);
	//CDialogEx::OnOK();
}

//��һ��
void Ctest92Dlg::OnBnClickedNext()
{
	m_sel++;
	SelectPage();
}


void Ctest92Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

//��һ��
void Ctest92Dlg::OnBnClickedBefor()
{
	m_sel--;
	SelectPage();
}
void Ctest92Dlg::SelectPage()
{
	CWnd *ps[]={&m_p1,&m_p2,&m_p3};
	int i=0;
	while(i<(sizeof(ps)/sizeof(ps[0])))
		ps[i++]->ShowWindow(m_sel==i?SW_SHOW:SW_HIDE);//�����ǰ���ں�ѡ��ѡ�еĴ���һ������ʾ����������
	//������һ������һ����ť�Ŀɼ���
	GetDlgItem(IDBEFOR)->EnableWindow(m_sel!=0);//��һ����0�����أ���������ʾ
	GetDlgItem(IDNEXT)->EnableWindow(m_sel!=2);//��һ����2�����أ���������ʾ
}


void Ctest92Dlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::DoDataExchange(pDX);
}
