#pragma once


// Cpage3 �Ի���

class Cpage3 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3();
	virtual ~Cpage3();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
