// MFC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include "stdio.h"
/*class CMyApp : public CWinApp
{
	virtual BOOL InitApplication()
	{
		AfxMessageBox("��Win32����ת�����ɵ�MFC�������");
		return TRUE;
	}
};
CMyApp theApp;*/
BOOL CALLBACK theProc(
HWND hwndDlg,
UINT UMsg,
WPARAM wParam,
LPARAM lParam
)
{
	switch(UMsg)
	{
		//�����ʼ����Ϣ
	case WM_INITDIALOG:
		//���ô���λ��
		MoveWindow(hwndDlg,100,80,400,300,FALSE);
		//���ô������
		SetWindowText(hwndDlg,"����");
		return TRUE;

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			return TRUE;
		case IDCANCEL:
			EndDialog(hwndDlg,IDCANCEL);
			return TRUE;
		}
		break;
		//�����Ϣ
		case WM_LBUTTONDOWN:
			{
				int x=LOWORD(lParam);
				int y=HIWORD(lParam);
				char s[200];
				sprintf(s,"x=%d,y=%d",x,y);
				MessageBox(hwndDlg,s,"����",0);
			}
			return TRUE;
		//����ƶ���Ϣ
		case WM_MOUSEMOVE:
			{
				int x=LOWORD(lParam);
				int y=HIWORD(lParam);
				char s[200];
				sprintf(s,"x=%d,y=%d",x,y);
				::SetWindowText(hwndDlg,s);
			}
			return TRUE;
			//��ͼ��Ϣ,Ҳ�д���ˢ����Ϣ
		case WM_PAINT:
			OutputDebugString("��ͼ��Ϣ����\n");
			//������ͼ�����Ľṹ��
			PAINTSTRUCT ps;
			//��ͼ���HDC
			HDC hdc=::BeginPaint(hwndDlg,&ps);
			::Ellipse(hdc,0,0,300,200);
			::EndPaint(hwndDlg,&ps);

			return TRUE;
	}
	return FALSE;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance,(LPCTSTR)IDD_MAIN,NULL,theProc);
	return 0;
}



