// Create_MFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "MainDlg.h"//��һ���������������ڵ�ͷ�ļ�
#include "Dialog2.h"
//��Ϣӳ�����
//����ʹ�����򵼽���һ��������������ࣨCWnd�����磺�鿴->��������->new class��Ӧһ��Dialog���
//����ʹ�������ඨ��������������û����������Ϣ���磺CMainDlg dlg;
//�ڴ����������У�ÿһ����Ϣ����һ�����Ա�����������磺void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
//��Ϣӳ�亯����ͨ�����򵼣�classWizard���������磺�鿴->��������->��Messages��ѡ��֮��add Function
class CMyApp : public CWinApp
{
	virtual BOOL InitApplication()
	{
		CMainDlg dlg;
		dlg.DoModal();
		Dialog2 dlg2;
		dlg2.DoModal();
		//AfxMessageBox("��Win32����ת�����ɵ�MFC�������");
		return TRUE;
	}
};
CMyApp theApp;

/*int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	return 0;
}*/



