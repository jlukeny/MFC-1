
// test9-1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// Ctest91Dlg �Ի���
class Ctest91Dlg : public CDialogEx
{
// ����
public:
	Ctest91Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST91_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_sp1;
	CRichEditCtrl m_richedit;
};
