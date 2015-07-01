#pragma once
#include "afxwin.h"
class CMemoryDC :
	public CDC
{
	CSize m_size;
public:
	CMemoryDC(void);
	~CMemoryDC(void);
	BOOL LoadmyBitmap(LPCSTR file, CDC * pdc=NULL)
	{
		//���������λͼ
		HBITMAP hbitmap=(HBITMAP)LoadImage(NULL,file,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);//��һ������Ϊ���̾�����ڶ���Ϊ�ļ�·����3Ϊ���ص����ͣ�Bitmap��Icon��ICursur��45Ϊλͼ��Ⱥ͸߶ȣ����һ����ʾ���ļ��м���
		if(!hbitmap)
			return FALSE;
		//bitmap�Ľṹ�壬����λͼ��Ϣ
		BITMAP bitmap;
		GetObject(hbitmap,sizeof(bitmap),&bitmap);//���λͼ��Ϣ
		//����Ⱥ͸߶ȸ�ֵ��˽�б���
		m_size.cx=bitmap.bmWidth;
		m_size.cy=bitmap.bmHeight;
		//�����ڴ�����
		CreateCompatibleDC(pdc);
		//�ڴ��������λͼ
		SelectObject(hbitmap);
		return TRUE;
	}
	int GetWidth(){return m_size.cx;}
	int GetHeight(){return m_size.cy;}
};

