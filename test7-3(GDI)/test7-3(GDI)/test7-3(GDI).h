
// test7-3(GDI).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest73GDIApp:
// �йش����ʵ�֣������ test7-3(GDI).cpp
//

class Ctest73GDIApp : public CWinApp
{
public:
	Ctest73GDIApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest73GDIApp theApp;