
// test5-6_NOtepaidDlg.h : ͷ�ļ�
//

#pragma once


// Ctest56_NOtepaidDlg �Ի���
class Ctest56_NOtepaidDlg : public CDialogEx
{
// ����
public:
	Ctest56_NOtepaidDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CEdit m_edit;//�󶨱༭����Ϣ
    CFont m_font;//����������Ϣ
	CRect m_rect;//����Ի���仯ǰ�Ĵ�С

// �Ի�������
	enum { IDD = IDD_TEST56_NOTEPAID_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnOpen();
	afx_msg void OnCancel();
	afx_msg void OnFont();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAbout();
	afx_msg void OnCut();
	afx_msg void OnCopy();
	afx_msg void OnChexiao();
	afx_msg void OnNewfile();
};
