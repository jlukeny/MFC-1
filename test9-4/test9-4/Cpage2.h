#pragma once


// Cpage2 �Ի���

class Cpage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2();
	virtual ~Cpage2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
