#ifndef __HEADER_H__
#define __HEADER_H__

#include"person.h"
#define MAX 1000 //ͨѶ¼��������


//�ࡪ��ͨѶ¼
class Addressbook
{
public:
	//ͨѶ¼�е�������ϵ��
	Person m_Person[MAX];

	//ͨѶ¼��������ϵ�˵�����
	int m_Num;
};

#endif

