#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include"worker.h"
using namespace std;

//��ͨԱ����
class Employee:public Worker
{
public:
	//���캯��
	Employee(int id,string name,int did);
	//��ȡԱ���ĸ�λ����д���ി�麯��
	string getDid();
	//��ʾԱ����Ϣ����д���ി�麯��
	void showInfo();
};

#endif