
// test9-2Dlg.h : ͷ�ļ�
//
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"


#pragma once


// Ctest92Dlg �Ի���
class Ctest92Dlg : public CDialogEx
{
// ����

public:
	Ctest92Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	void SelectPage();
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;
	int m_sel;
// �Ի�������
	enum { IDD = IDD_TEST92_DIALOG };

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBefor();
};
