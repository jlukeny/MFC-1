#pragma once


// CInsertPeople �Ի���
#include "InfoDlg.h"
class CInsertPeople : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertPeople)

public:
	CInfoDlg* infodlg;
	CInsertPeople(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertPeople();
	//CInfoDlg *infodlg;
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
