#ifndef __WORKER_H__
#define __WORKER_H__
#include<string>
using namespace std;

//Ա��������
class Worker
{
public:
	//��ȡԱ���ĸ�λ
	virtual string getDid() = 0;
	//��ʾԱ������Ϣ
	virtual void showInfo() = 0;

public:
	//Ա�����
	int m_Id;
	//Ա������
	string m_Name;
	//Ա����λ���
	int m_Did;
};

#endif