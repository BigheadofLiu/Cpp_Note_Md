#ifndef __MANAGER_H__
#define __MANAGER_H__

#include"worker.h"
//������
class Manager:public Worker
{
public:
	//���캯��
	Manager(int id,string name,int did);
	//��ȡԱ���ĸ�λ
	string getDid();
	//��ʾԱ������Ϣ
	void showInfo();
};

#endif