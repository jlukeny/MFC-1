#pragma once


// CInsertPeople �Ի���

class CInsertPeople : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertPeople)

public:
	CInsertPeople(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertPeople();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
