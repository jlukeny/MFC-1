#pragma once
#include "afxcmn.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"


// CModDlg �Ի���

class CModDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModDlg)

public:
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;
	CModDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModDlg();

// �Ի�������
	enum { IDD = IDD_MOD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
