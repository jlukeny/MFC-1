
// test12-1_SDI.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "test12-1_SDI.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest121_SDIApp

BEGIN_MESSAGE_MAP(Ctest121_SDIApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Ctest121_SDIApp::OnAppAbout)
END_MESSAGE_MAP()


// Ctest121_SDIApp ����

Ctest121_SDIApp::Ctest121_SDIApp()
{
	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("test12-1_SDI.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� Ctest121_SDIApp ����

Ctest121_SDIApp theApp;


// Ctest121_SDIApp ��ʼ��

BOOL Ctest121_SDIApp::InitInstance()
{


	// ��Ҫ���������ڣ��˴��뽫�����µĿ�ܴ���
	// ����Ȼ��������ΪӦ�ó���������ڶ���
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ���������ؿ�ܼ�����Դ
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	//�Լ��������
	//HICON icon=LoadIcon(IDR_MAINFRAME);
	////ע�ᴰ��
	//LPCSTR szclass=AfxRegisterWndClass(CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW,NULL,NULL,icon);
	////ʹ�ñ���ܴ�������
	//pFrame->Create(szclass,"Ա����Ϣ����",WS_OVERLAPPEDWINDOW,CFrameWnd::rectDefault,NULL,MAKEINTRESOURCE(IDR_MAINFRAME));
	//pFrame->SendMessageToDescendants(WM_INITIALUPDATE,0,0,TRUE,TRUE);
	//pFrame->SetIcon(icon,FALSE);



	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int Ctest121_SDIApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	return CWinApp::ExitInstance();
}

// Ctest121_SDIApp ��Ϣ�������


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

// �������жԻ����Ӧ�ó�������
void Ctest121_SDIApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Ctest121_SDIApp ��Ϣ�������



