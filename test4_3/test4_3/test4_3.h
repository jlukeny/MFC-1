
// test4_3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest4_3App:
// �йش����ʵ�֣������ test4_3.cpp
//

class Ctest4_3App : public CWinApp
{
public:
	Ctest4_3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest4_3App theApp;