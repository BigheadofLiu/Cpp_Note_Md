//ְ������ϵͳ

#include <iostream>
#include <string>
#include "functions.h"
#include "person.h"
#include "addressbook.h"

using namespace std;

int main()
{
	Addressbook ab;
	ab.m_Num = 0; //��ʼ��ͨѶ¼����

	while (true)
	{
		//��ʾ�˵�
		showMenu();

		int flag;
		cin >> flag;
		switch (flag)
		{
		case 1:
			//1�������ϵ��
			addPerson(ab);
			break;
		case 2:
			//2����ʾ�����У���ϵ��
			showPerson(ab);
			break;
		case 3:
			//3��ɾ����ϵ��
			deletePerson(ab);
			break;
		case 4:
			//4��������ϵ��
			findPerson(ab);
			break;
		case 5:
			//5���޸���ϵ��
			modifyPerson(ab);
			break;
		case 6:
			//6����գ����У���ϵ��
			clearPerson(ab);
			break;
		case 0:
			//0���˳�ϵͳ
			cout << "��ӭ���´�ʹ��" << endl;
			system("pause");
			return 0; //�˳�main����
			break;
		default:
			cout << "������������������" << endl;
			break;
		}	
	
		system("pause");
		system("cls");
	}
	


	system("pause");
	return 0;
}