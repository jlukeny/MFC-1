
// test9-5Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

struct Info
{
	int id;
	char name[20];
	double pay;
};
// Ctest95Dlg �Ի���
class Ctest95Dlg : public CDialogEx
{
// ����
public:
	Ctest95Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST95_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	CListCtrl m_list;
	CTreeCtrl m_tree;

	bool changed;//���ŵ�Ա����Ϣ�Ƿ��޸�
	afx_msg void OnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	CString GetPath(HTREEITEM item);
	int GetDepth(HTREEITEM item);
	void Save();
	void Load();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
