#pragma once

// CAddDlg �Ի���

class CAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddDlg();

// �Ի�������
	enum { IDD = IDD_LURU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	CString m_name;
	CString m_pay;
};
