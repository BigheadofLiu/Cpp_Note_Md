#include"boss.h"
#include<iostream>
using namespace std;
//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡԱ���ĸ�λ
string Boss::getDid()
{
	return string("�ϰ�");
}

//��ʾԱ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDid()
		<< "\t��λְ�𣺹���˾��������" << endl;
}