
// test12-1_SDI.h : test12-1_SDI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ctest121_SDIApp:
// �йش����ʵ�֣������ test12-1_SDI.cpp
//

class Ctest121_SDIApp : public CWinApp
{
public:
	Ctest121_SDIApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest121_SDIApp theApp;
