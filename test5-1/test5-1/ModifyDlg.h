#pragma once
#include "atlcomtime.h"


// CModifyDlg �Ի���

class CModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyDlg)

public:
	CModifyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModifyDlg();

// �Ի�������
	enum { IDD = IDD_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_bumen;
	COleDateTime m_birth;
	CString m_name;
	float m_pay;
	UINT m_id;
	afx_msg void OnBnClickedOk();
};
