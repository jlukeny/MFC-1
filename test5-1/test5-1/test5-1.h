
// test5-1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest51App:
// �йش����ʵ�֣������ test5-1.cpp
//

class Ctest51App : public CWinApp
{
public:
	Ctest51App();
	user info;
	//ǰ��ɫ�ͱ���ɫ
	COLORREF Ctrlbk,Textbk;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest51App theApp;