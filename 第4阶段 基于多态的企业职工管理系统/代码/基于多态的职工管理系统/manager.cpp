#include"manager.h"
#include<iostream>
using namespace std;
//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡԱ���ĸ�λ
string Manager::getDid()
{
	return string("����");
}

//��ʾԱ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDid()
		<< "\t��λְ������ϰ彻�������񣬹���Ա��" << endl;
}