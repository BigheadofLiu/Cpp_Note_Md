#ifndef __BOSS_H__
#define __BOSS_H__

#include"worker.h"
//������
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);
	//��ȡԱ���ĸ�λ
	string getDid();
	//��ʾԱ������Ϣ
	void showInfo();
};

#endif