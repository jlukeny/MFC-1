
// test5-1Dlg.h : ͷ�ļ�
//

#pragma once


// Ctest51Dlg �Ի���
class Ctest51Dlg : public CDialogEx
{
// ����
public:
	Ctest51Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST51_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRelogin();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedInfo();
};
