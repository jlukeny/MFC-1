
// test7-3(GDI)Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test7-3(GDI).h"
#include "test7-3(GDI)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest73GDIDlg �Ի���



Ctest73GDIDlg::Ctest73GDIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest73GDIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest73GDIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest73GDIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCPAINT()
END_MESSAGE_MAP()


// Ctest73GDIDlg ��Ϣ�������

BOOL Ctest73GDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Ctest73GDIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest73GDIDlg::OnPaint()
{
	//if (IsIconic())
	//{
	//���ƿͻ�������ͼ��
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		//int cxIcon = GetSystemMetrics(SM_CXICON);
		//int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		//int x = (rect.Width() - cxIcon + 1) / 2;
		//int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		//dc.DrawIcon(x, y, m_hIcon);
		dc.Ellipse(rect);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest73GDIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest73GDIDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//���ƿͻ�����ʱͼ��
	CClientDC cdc(this);
	cdc.Rectangle(point.x-10,point.y-10,point.x+10,point.y+10);

	CDialogEx::OnLButtonDown(nFlags, point);
}

//���Ʒǿͻ���
void Ctest73GDIDlg::OnNcPaint()
{
	//��OnNcPaint()��CWindowDC��ͼ������Ч����������Ϣ��ֻ����ʱ��
	CWindowDC cdc(this);
	CRect rect;
	GetWindowRect(rect);
	//ת��Ϊ�ǿͻ�������ϵ
	rect.OffsetRect(-rect.left,-rect.top);//�����ƶ���Ļ����ϵ��x�������ƶ���Ļ����ϵ��yֵ
	rect.top-=20;
	cdc.FillSolidRect(rect,RGB(255,0,0));//��������ɫΪ��ɫ
	//cdc.Rectangle(rect);
	//����ʹ�����·���ת��Ϊ�ǿͻ�������ϵ
	//cdc.Rectangle(0,0,rect.Width(),rect.Height());
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnNcPaint()
}
