#pragma once
#include "afxwin.h"


// CPage1 �Ի���

class CPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage1)

public:
	CPage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
//	CString m_id;
//	CString m_id;
//	long m_id;
//	CEdit m_id;
//	CString m_id;
//	CString m_id;
	virtual void DoDataExchange(CDataExchange* pDX);
	CString m_id;
};
