#include"employee.h"
#include <iostream>

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

//��ȡ��λ����
string Employee::getDid()
{
	return string("Ա��");
}

//��ʾԱ����Ϣ
void Employee::showInfo()
{
	std::cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDid()
		<< "\t��λְ����ɾ�����������" << endl;
}