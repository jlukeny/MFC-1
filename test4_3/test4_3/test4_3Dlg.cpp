
// test4_3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resource.h"
#include "test4_3.h"
#include "test4_3Dlg.h"
#include "afxdialogex.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4_3Dlg �Ի���


CWnd edit;
CMyButton button,button2;
Ctest4_3Dlg::Ctest4_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest4_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest4_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest4_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest4_3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest4_3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest4_3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest4_3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest4_3Dlg::OnBnClickedButton5)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, &Ctest4_3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Ctest4_3Dlg::OnBnClickedButton7)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON8, &Ctest4_3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &Ctest4_3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Ctest4_3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &Ctest4_3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &Ctest4_3Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &Ctest4_3Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &Ctest4_3Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &Ctest4_3Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &Ctest4_3Dlg::OnBnClickedButton17)
END_MESSAGE_MAP()


// Ctest4_3Dlg ��Ϣ�������

BOOL Ctest4_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//��ñ����ڱ༭��ؼ��ľ��
	HWND hwnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	//��edit������þ����������Ϳ��Բ��ݸþ����Ӧ�Ŀؼ�
	edit.Attach(hwnd);
	//��һ�ֹ����ķ�����ͨ������button���Խ��մ�����Ϣ(MouseMove��Ϣ��)
	HWND hwnd2=::GetDlgItem(m_hWnd,IDC_BUTTON2);
	button.SubclassWindow(hwnd2);
	//�����ֹ�������������Ҫ�����ֻ��Ҫ�����ںͿؼ�id
	button2.SubclassDlgItem(IDC_BUTTON1,this);
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

void Ctest4_3Dlg::OnPaint()
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
HCURSOR Ctest4_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest4_3Dlg::OnBnClickedButton1()
{
	DestroyWindow();
}
//����һ��"syslistview32"�ؼ�
CWnd list;
void Ctest4_3Dlg::OnBnClickedButton2()
{
	if(!list)
	{
		list.Create(_T("syslistview32"),NULL,WS_CHILD|WS_VISIBLE,CRect(10,80,200,200),this,8888);//_T()��unicode��ʽ����
	}
}

//CWndת��Ϊ���
void Ctest4_3Dlg::OnBnClickedButton3()
{
	CWnd *p=GetDlgItem(IDOK);
	//if(p)
	HWND hwnd=p->GetSafeHwnd();//��ȫ�Ļ�ȡ�����ָ��Ϊ��Ҳ�������
	if(hwnd)
		p->DestroyWindow();
}

//�����ת��ΪCWnd
void Ctest4_3Dlg::OnBnClickedButton4()
{
	HWND hwnd=::GetDlgItem(m_hWnd,IDOK);
	CWnd *p=FromHandle(hwnd);
	p->SetWindowText(_T("ͨ����ʱ����Set"));
}

//��ʼ��ʱ����=�ؼ�����������
void Ctest4_3Dlg::OnBnClickedButton5()
{
	edit.SetWindowText(_T("ͨ��ȫ�ֶ���Set"));
}


void Ctest4_3Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	//�˳�֮ǰ����ȡ���������ڶ�����Attach��Ӧ
	edit.Detach();
	button.UnsubclassWindow();
}

//���ڳ�ʼ��ʱ�򽫱༭��ؼ��󶨣������������ĳ��Ϳ�
void Ctest4_3Dlg::OnBnClickedButton6()
{
	//����һ����������
	CRect rect;
	//��øÿؼ���������(��Ļ����)
	edit.GetWindowRect(rect);
	//�ǰ���Ļ����ת��Ϊ��������
	ScreenToClient(rect);
	//���γ��Ϳ�����15
	rect.InflateRect(15,15);
	edit.MoveWindow(rect);
	//ʵʱ����
	Invalidate();

}

//����һ����ʱ��������ƽ�ư󶨵�Button2
void Ctest4_3Dlg::OnBnClickedButton7()
{
	//����һ����ʱ������һ������Ϊ��ʱ��id���ڶ���Ϊʱ����
	SetTimer(1,10,NULL);
}



void Ctest4_3Dlg::OnTimer(UINT_PTR nID)
{
	if(nID==1)
	{
		//��button��Ӧ��button2����
		CRect rect;
		button.GetWindowRect(rect);
		ScreenToClient(rect);
		//�ı���ε�x���꣬���ı�y����(ƽ�ƾ���)
		rect.OffsetRect(2,0);
		//��ÿͻ����ľ�������
		CRect client;
		GetWindowRect(client);
		//�������ͻ����ұ߽�
		if(client.right<=rect.right)
		{
			rect.OffsetRect(-client.right,0);//����߿�ʼ
			//KillTimer(1);//������ʱ��
		}
		//button.MoveWindow(rect);�ƶ�����
		button.SetWindowPos(&wndTop,rect.left,rect.top,rect.Width(),rect.Height(),0);//����button��λ�ã�wndtop����z�ᣬ��ʾ�����ؼ�����֮��
		Invalidate();
		CDialogEx::OnTimer(nID);
	}
}

//ShowWindow����
void Ctest4_3Dlg::OnBnClickedButton8()
{
	CWnd *pc=GetDlgItem(IDCANCEL);
	if(pc->IsWindowVisible())//�жϴ����Ƿ�ɼ�
		pc->ShowWindow(SW_HIDE);
	else
		pc->ShowWindow(SW_SHOW);
}

//���ô����Ƿ����
void Ctest4_3Dlg::OnBnClickedButton10()
{
	CWnd *p=GetDlgItem(IDCANCEL);
	if(p->IsWindowEnabled())//�жϴ����Ƿ����
		p->EnableWindow(false);
	else
		p->EnableWindow(true);
}

//�ж�ĳһ�����ڣ�����ʹ��GitHub����Ϊ�����Ƿ�����С�������������(ISZoomed),
void Ctest4_3Dlg::OnBnClickedButton11()
{
	CWnd *p=FindWindow(_T("SysListView32"),NULL);
	if(p && p->IsIconic())
		p->ShowWindow(SW_MAXIMIZE);

}

//���ú�ȡ��ǰ����ʾ���
void Ctest4_3Dlg::OnBnClickedButton12()
{
	if(GetExStyle() & WS_EX_TOPMOST)//�����ǰ����ʾ�����ȡ��ǰ����ʾ
		SetWindowPos(&wndNoTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	else
		SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

}

//����������Ϊ��top�㣬Ҳ������ײ�
void Ctest4_3Dlg::OnBnClickedButton13()
{
	list.BringWindowToTop();
	Invalidate();
}

//�����top��Ĵ���
void Ctest4_3Dlg::OnBnClickedButton14()
{
	CWnd *p=GetTopWindow();
	CString str;
	p->GetWindowText(str);
	SetWindowText(str);
}

//�������Ƶ�ǰ̨
void Ctest4_3Dlg::OnBnClickedButton15()
{
	CWnd *p=FindWindow(NULL,_T("���� - ���±�"));
	if(p)
		p->SetForegroundWindow();//����Ϊ��ǰ̨�Ĵ���
	CString str;
	CWnd *p2=GetForegroundWindow();//�����ǰ̨�Ĵ���
	p2->GetWindowText(str);
	SetWindowText(str);
}

//����������Ϊ��˸
void Ctest4_3Dlg::OnBnClickedButton16()
{
	CWnd *p=FindWindow(NULL,_T("���� - ���±�"));
	if(p)
		p->FlashWindow(true);
}

//��ñ����ڵ������Ӵ���
void Ctest4_3Dlg::OnBnClickedButton17()
{
	CWnd *p=GetWindow(GW_CHILD);//p���Ӵ��ڼ���
	CString str;
	while(p)
	{
		p->GetWindowText(str);
		AfxMessageBox(str);
		p=p->GetWindow(GW_HWNDNEXT);//������һ������
	}
}
