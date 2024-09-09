#include <iostream>
#include <string>
#include "addressbook.h"
#include "functions.h"

using namespace std;

//��������

//��ʾ�˵�
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** ְ������ϵͳ *****" << endl;
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ�����У���ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6����գ����У���ϵ��" << endl;
	cout << "0���˳�ϵͳ" << endl;
	cout << "************************" << endl;
}

//1�������ϵ��
void addPerson(Addressbook &ab)
{
	cout << "���������ϵ�ˣ��밴��ʾ����������Ϣ..." << endl;
	//����
	cout << "������" << endl;
	string name;
	cin >> name;
	ab.m_Person[ab.m_Num].m_Name = name;
	//�Ա�
	cout << "�Ա�" << endl
		<< "1 --- ��" << endl
		<< "2 --- Ů" << endl;
	int sex;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			ab.m_Person[ab.m_Num].m_Sex = sex;
			break;
		}
		else
		{
			cout << "�Ա�������������������" << endl;
		}
	}
	//����
	cout << "���䣺" << endl;
	int age;
	cin >> age;
	ab.m_Person[ab.m_Num].m_Age = age;

	cout << "��ϵ����ӳɹ�" << endl;
	ab.m_Num++;
}

//2����ʾ�����У���ϵ��
void showPerson(const Addressbook &ab)
{
	if (ab.m_Num == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < ab.m_Num; i++)
		{
			cout << i + 1 << "\t"
				<< "������" << ab.m_Person[i].m_Name << "\t"
				<< "�Ա�" << (ab.m_Person[i].m_Sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" << ab.m_Person[i].m_Age << endl;
		}
	}
}

//3��ɾ����ϵ��
void deletePerson(Addressbook &ab)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //���ڸ���ϵ��
	{
		for (int i = personIndex; i + 1 < ab.m_Num; i++)
		{
			//ǰ�Ƹ���
			ab.m_Person[i] = ab.m_Person[i + 1];
		}
		ab.m_Num--;
		cout << "��ϵ��ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�ɾ����Ч��" << endl;
	}
}

//4��������ϵ��
void findPerson(const Addressbook &ab)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //���ڸ���ϵ��
	{
		cout << "������" << ab.m_Person[personIndex].m_Name << "\t"
			<< "�Ա�" << (ab.m_Person[personIndex].m_Sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺" << ab.m_Person[personIndex].m_Age << endl;
	}
	else
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}

}

//5���޸���ϵ��
void modifyPerson(Addressbook &ab)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int personIndex = isExist(ab, name);
	if (personIndex != -1) //����
	{
		//����
		cout << "������" << endl;
		string name;
		cin >> name;
		ab.m_Person[personIndex].m_Name = name;
		//�Ա�
		cout << "�Ա�" << endl
			<< "1 --- ��" << endl
			<< "2 --- Ů" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab.m_Person[personIndex].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�Ա�������������������" << endl;
			}
		}
		//����
		cout << "���䣺" << endl;
		int age;
		cin >> age;
		ab.m_Person[personIndex].m_Age = age;

		cout << "��ϵ���޸ĳɹ���" << endl;
	}
	else //������
	{
		cout << "��ϵ�˲����ڣ��޷��޸ģ�" << endl;
	}
}
//6����գ����У���ϵ��
void clearPerson(Addressbook &ab)
{
	cout << "ȷ����գ����У���ϵ����" << endl
		<< "1 === ����" << endl
		<< "0 --- ȡ��" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1)
	{
		ab.m_Num = 0;
		cout << "�����У���ϵ�������" << endl;
	}
}

//���Ӻ���
//�ж���ϵ���Ƿ����
int isExist(const Addressbook &ab,string name)
{
	for (int i = 0; i != ab.m_Num; i++)
	{
		if (ab.m_Person[i].m_Name == name)
		{
			//cout << "��ϵ�˴���" << endl;
			return i;
		}
	}
	return -1; //δ�ҵ���Ӧ��ϵ��
}
