#pragma once


// CInfoDlg �Ի���

class CInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoDlg)

public:
	CInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInfoDlg();
	CListCtrl p;

// �Ի�������
	enum { IDD = IDD_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedSave();
};
