#pragma once


// CPriorDlg �Ի���

class CPriorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPriorDlg)

public:
	CPriorDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPriorDlg();

// �Ի�������
	enum { IDD = IDD_PRIOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedModify();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnDestroy();
	void Readuesr(CListCtrl * p);
};
