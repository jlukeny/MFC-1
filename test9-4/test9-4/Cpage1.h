#pragma once


// Cpage1 �Ի���

class Cpage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1();
	virtual ~Cpage1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	CString m_id;
};
