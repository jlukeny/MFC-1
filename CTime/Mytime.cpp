// Mytime.cpp: implementation of the CMytime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Mytime.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMytime::CMytime()
{

}

CMytime::~CMytime()
{

}

CMytime CMytime::GetCurrentTime()
{
	CMytime mytime;
	mytime.m_time=time(NULL);
	return mytime;
}
//const ��ֹ�޸ĳ�Ա����
int CMytime::GetYear() const
{
	struct tm *p=localtime(&m_time);
	return p->tm_year+1900;
}
