#pragma once
#include "afxwin.h"
class CMemoryDC :
	public CDC
{
	CSize m_size;
public:
	CMemoryDC(void);
	CMemoryDC(int cx,int cy,CDC *pdc=NULL)
	{
		Create(cx,cy,pdc);
	}

	BOOL Create(int cx,int cy,CDC *pdc=NULL)
	{
		//�����հ�λͼ
		CBitmap bmp;
		if(!bmp.CreateCompatibleBitmap(pdc,cx,cy))
			return FALSE;
		m_size.cx=cx;
		m_size.cy=cy;
		CreateCompatibleDC(pdc);
		SelectObject(&bmp);
		return TRUE;
	}
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
	//����͸��ɫ��һ��Ϊ����͸����
	void BitTrans(
		int  xdest,//Ŀ�����x
		int  ydest,//Ŀ�����y
		int width,//Ŀ����
		int height,//Ŀ��߶�
		CDC *pdc,//Ŀ��dc
		int xsource,//��Դ���x
		int ysource,//��Դ���y
		COLORREF colortrans//͸��ɫ
		)
	{
		CMemoryDC dcImage;//��ʱDC
		CBitmap bmp;
		bmp.CreateBitmap(width,height,1,1,NULL);
		//������ɫ����λͼ
		CDC dcMark;//����DC
		dcMark.CreateCompatibleDC(pdc);
		dcMark.SelectObject(bmp);
		//������λͼ���ڴ�DC�е�λͼ����������ʱDC��
		dcImage.BitBlt(0,0,width,height,this,xsource,ysource,SRCCOPY);
		//������ʱDC͸��ɫ
		dcImage.SetBkColor(colortrans);
		//����DC͸������Ϊ��ɫ����Ϊ��ɫ
		dcMark.BitBlt(0,0,width,height,&dcImage,0,0,SRCCOPY);
		//��ʱ͸������Ϊ��ɫ���������򱣳ֲ���
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt(0,0,width,height,&dcMark,0,0,SRCAND);
		//Ŀ��DC͸�����ֱ�����Ļ���䣬��������Ϊ��ɫ
		pdc->SetBkColor(RGB(255,255,255));
		pdc->SetTextColor(RGB(0,0,0));
		pdc->BitBlt(xdest,ydest,width,height,&dcMark,0,0,SRCAND);
		pdc->BitBlt(xdest,ydest,width,height,&dcImage,0,0,SRCPAINT);

	}
};

