
// test5-6_NOtepaid.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest56_NOtepaidApp:
// �йش����ʵ�֣������ test5-6_NOtepaid.cpp
//

class Ctest56_NOtepaidApp : public CWinApp
{
public:
	Ctest56_NOtepaidApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest56_NOtepaidApp theApp;