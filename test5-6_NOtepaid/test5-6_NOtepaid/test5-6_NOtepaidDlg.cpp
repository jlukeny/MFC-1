
// test5-6_NOtepaidDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test5-6_NOtepaid.h"
#include "test5-6_NOtepaidDlg.h"
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


// Ctest56_NOtepaidDlg �Ի���



Ctest56_NOtepaidDlg::Ctest56_NOtepaidDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest56_NOtepaidDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest56_NOtepaidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest56_NOtepaidDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctest56_NOtepaidDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctest56_NOtepaidDlg::OnBnClickedCancel)
	ON_COMMAND(ID_OPEN, &Ctest56_NOtepaidDlg::OnOpen)
	ON_COMMAND(IDCANCEL, &Ctest56_NOtepaidDlg::OnCancel)
	ON_COMMAND(ID_FONT, &Ctest56_NOtepaidDlg::OnFont)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// Ctest56_NOtepaidDlg ��Ϣ�������

BOOL Ctest56_NOtepaidDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_edit.SubclassDlgItem(IDC_EDIT1,this);
	GetClientRect(&m_rect);//��öԻ����������
	
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

	ShowWindow(SW_MAXIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Ctest56_NOtepaidDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ctest56_NOtepaidDlg::OnPaint()
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
HCURSOR Ctest56_NOtepaidDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest56_NOtepaidDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void Ctest56_NOtepaidDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void Ctest56_NOtepaidDlg::OnOpen()
{
	LPCSTR fileter="�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,fileter);
	//��ʾϵͳ�Ի�����ѡ���ļ�
	if(IDCANCEL==dlg.DoModal())
		return;
	//ѡ���ļ�֮��򿪸��ļ����ж�ȡ
	CFile file;
	if(!file.Open(dlg.GetPathName(),CFile::modeRead|CFile::shareDenyNone))
	{
		AfxMessageBox("�޷����ļ���");
		return;
	}
	//����ļ���״̬��Ϣ
	CFileStatus status;
	file.GetStatus(status);
	//����һ�����鱣�����
	char *data=new char[status.m_size+1];
	//��ȡ�ļ�
	int last=file.Read(data,status.m_size);
	//���ý������
	data[last]='\0';
	SetDlgItemText(IDC_EDIT1,data);
	delete []data;
	
}


void Ctest56_NOtepaidDlg::OnCancel()
{
	CDialogEx::OnCancel();
}


void Ctest56_NOtepaidDlg::OnFont()
{
	//��LOGFONT����������Ϣ
	LOGFONT lfont;
	if(m_font.GetSafeHandle())
		m_font.GetLogFont(&lfont);//��CFont���е���Ϣ����lfont
	//������������Ի���
	CFontDialog dlg(&lfont);//��ʼ��ϵͳ�Ի��򣬸�ϵͳ�Ի���򿪵�ʱ��ǰ������Ϣ�Ѿ���ѡ��
	if(IDCANCEL==dlg.DoModal())
	{
		return;
	}

	dlg.GetCurrentFont(&lfont);
	//����һ������ʵ�࣬�����ø��༭��,��������һ��ȫ�ֵı��������������ڲ���
	m_font.DeleteObject();//���ԭ����Ϣ
	m_font.CreateFontIndirect(&lfont);//ʵ����������Ϣ��LOGFONT->CFont������.GetLogFont(&lfont)�Ƿ�����(CFont->LOGFONT)
	m_edit.SetFont(&m_font);//��������

}

//�Ի����С�仯�����¼����������ı༭��Ĵ�С
void Ctest56_NOtepaidDlg::OnSize(UINT nType, int cx, int cy)
{
	
	CWnd *edit;
	edit=GetDlgItem(IDC_EDIT1);
	//�������С������ʲô������
	if(nType==SIZE_MINIMIZED)
		return;
	if(edit)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
	{
		CRect rect;
		edit->GetWindowRect(&rect);//��ÿؼ��仯ǰ�Ĵ�С
	    ScreenToClient(&rect);////���ؼ���Сת��Ϊ�ڶԻ����е���������
		//cx/m_editWidth()Ϊ����仯�ı���,��left��right�������µľ�������
		rect.left=rect.left*cx/m_rect.Width();
		rect.right=rect.right*cx/m_rect.Width();
		rect.top=rect.top*cy/m_rect.Height();
		rect.bottom=rect.bottom*cy/m_rect.Height();

		edit->MoveWindow(rect);
	}
	//���ø��ĺ�ĶԻ����С��m_rect
	GetClientRect(&m_rect);
	CDialogEx::OnSize(nType, cx, cy);
}
