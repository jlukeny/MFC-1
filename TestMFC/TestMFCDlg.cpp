// TestMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg dialog

CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CTestMFCDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDMONI, OnMoni)
	ON_BN_CLICKED(IDCLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}



void CTestMFCDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if(MK_CONTROL & nFlags)
		str+="������Control����";
	if(MK_SHIFT & nFlags)
		str+="������Shift����";
	if(MK_LBUTTON & nFlags)
		str+="�����������";
	if(MK_RBUTTON & nFlags)
		str+="�������Ҽ���";
	SetWindowText(str);
	CDialog::OnMouseMove(nFlags, point);
	
	CDialog::OnMouseMove(nFlags, point);
}

void CTestMFCDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if(MK_CONTROL & nFlags)
		str+="������Control����";
	if(MK_SHIFT & nFlags)
		str+="������Shift����";
	AfxMessageBox(str);
	
	CDialog::OnLButtonDown(nFlags, point);
}

//ģ��OnLButtonDown�¼�
void CTestMFCDlg::OnMoni() 
{
	//α��Ϣ�������ֱ�Ϊ��Ϣ����Ϣ�Ĳ�������Ϣ�ĸ��Ӳ�����11=16+1,0xΪ16���ƣ�
	SendMessage(WM_LBUTTONDOWN,MK_LBUTTON|MK_CONTROL,0x00110011);
	//ʹ��PostMessageҲ��
}

void CTestMFCDlg::OnClose() 
{
	//��ô���ָ��
	CWnd *p=FindWindow(NULL,"���� - ���±�");
	if(p)
		p->PostMessage(WM_CLOSE);
}
