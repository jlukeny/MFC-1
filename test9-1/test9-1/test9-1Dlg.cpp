
// test9-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test9-1.h"
#include "test9-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest91Dlg �Ի���



Ctest91Dlg::Ctest91Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest91Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest91Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_sp1);
	DDX_Control(pDX, IDC_RICHEDIT21, m_richedit);
}

BEGIN_MESSAGE_MAP(Ctest91Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Ctest91Dlg ��Ϣ�������

BOOL Ctest91Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sp1.SetBuddy(GetDlgItem(IDC_EDIT2));//���ù����ؼ�
	m_sp1.SetRange32(0,100);//���÷�Χ
	CHARFORMAT cf={sizeof(cf)};//����Ľṹ��
	cf.dwMask=CFM_COLOR|CFM_SIZE;//����������Ϊ��ɫ�������С
	cf.crTextColor=RGB(0,255,0);//ָ����ɫΪ��ɫ
	cf.yHeight=300;
	m_richedit.SetDefaultCharFormat(cf);//������ṹ���ʼ���ؼ�
	m_richedit.SetWindowText("HELLO\r\n");

	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_BOLD|CFM_UNDERLINE|CFM_SIZE;//�ֱ�����ɫ�����壬�Ӵ֣��»��ߣ���С
	//�򿪿��غ�������ò�����Ч
	cf.crTextColor=RGB(255,0,0);
	//��Ϊ����
	strcpy_s(cf.szFaceName,"����");
	//��Ϊ������»���
	cf.dwEffects=CFE_BOLD|CFE_UNDERLINE;

	//�����ֽ�β�滻��ָ���ַ���
	int len=m_richedit.GetWindowTextLength();
	//���ù��λ��
	m_richedit.SetSel(len,-1);
	m_richedit.ReplaceSel("����ʾ�� ��������");
	m_richedit.SetSel(len-1,-1);
	//ȥ��ѡ��״̬
	m_richedit.SetSel(-1,-1);
	//�����������������óɸղŶ������ʽ,����ѡ������
	m_richedit.SetWordCharFormat(cf);
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest91Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest91Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

