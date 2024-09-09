#include"workerManager.h"
#include<iostream>
using namespace std;

//���캯��
WorkerManager::WorkerManager()
{
	//����FILENAME�Ƿ�����Լ������Ƿ�Ϊ�գ����������
	//���1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		//�ر�������
		ifs.close();
		return;
	}
	//���2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		m_Empnum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		//�ر�������
		ifs.close();
		return;
	}
	//���3���ļ����ڣ����ݲ�Ϊ��
	int num = this->getFileEmpNum();
	//cout << "�ļ������� " << num << " ��ְ��" << endl;
	this->m_Empnum = num;
	//��ʼ��ְ������
	this->m_EmpArray = new Worker*[this->m_Empnum];
	//����������ȥ
	initEmp();

	//for (int i = 0; i < this->m_Empnum; i++)
	//{
	//	cout << m_EmpArray[i]->m_Id << "\t"
	//		<< m_EmpArray[i]->m_Name << "\t"
	//		<< m_EmpArray[i]->m_Did << endl;
	//}

}

//�˵�չʾ����
void WorkerManager::showMenu()
{
	cout << "*************************" << endl
		<< "��ӭʹ��ְ������ϵͳ!" << endl
		<< "0.�˳�ϵͳ" << endl
		<< "1.����ְ����Ϣ" << endl
		<< "2.��ʾְ����Ϣ" << endl
		<< "3.ɾ����ְְ��" << endl
		<< "4.�޸�ְ����Ϣ" << endl
		<< "5.����ְ����Ϣ" << endl
		<< "6.���ձ������" << endl
		<< "7.��������ĵ�" << endl
		<< "*************************" << endl;

}

//0.�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ���´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//1.���ְ��
void WorkerManager::addEmp()
{
	cout << "��������Ҫ��ӵ�ְ��������" << endl;
	int addEmpNum = 0;
	cin >> addEmpNum;
	if (addEmpNum > 0)	
	{
		//�¿ռ��С
		int newsize = this->m_Empnum + addEmpNum;
		//�����¿ռ�
		Worker* * newSpace = new Worker*[newsize];
		//��������ְ��
		if (this->m_Empnum != 0)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�����ְ��
		for (int i = 0; i < addEmpNum; i++)
		{
			cout << "������� " << i + 1 << " ��ְ���ı�ţ�" << endl;
			int id;
			cin >> id;
			cout << "������� " << i + 1 << " ��ְ����������" << endl;
			string name;
			cin >> name;
			cout << "�� " << i + 1 << " ��ְ���Ĳ����ǣ�" << endl
				<< "1 --- ��ְͨ��" << endl
				<< "2 --- ����" << endl
				<< "3 --- �ϰ�" << endl;
			int did;
			while (true)
			{
				cin >> did;
				if (did == 1 || did == 2 || did == 3)
				{
					switch (did)
					{
					case 1:
						newSpace[this->m_Empnum + i] = new Employee(id, name, did);
						break;
					case 2:
						newSpace[this->m_Empnum + i] = new Manager(id, name, did);
						break;
					case 3:
						newSpace[this->m_Empnum + i] = new Boss(id, name, did);
						break;
					default:
						break;
					}
					break; //����whileѭ��
				}
				cout << "��������������ѡ��ְ�����ű�ţ�" << endl;
			}
			
		}
		//�ͷ�ԭ�пռ�����
		delete[] this->m_EmpArray;
		//����ָ��ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_Empnum = newsize;

		//����ɹ����
		cout << "�ɹ���� " << addEmpNum << " ����ְ����" << endl;
		this->m_FileIsEmpty = false; //��������
		this->save(); //���浽�ļ���
	}
	else
	{
		cout << "�����������������룡" << endl;
	}
}

//��������
void WorkerManager::save()
{
	//�����ļ������
	ofstream ofs;
	//������ķ�ʽ���ļ�����д�ļ�
	ofs.open(FILENAME, ios::out);
	//д�ļ�
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_Did << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��ȡ�ļ��е����ݸ���
int WorkerManager::getFileEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0; //�ļ��е�������
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//���ļ���Ϊ��ʱ�ĳ�ʼ������
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		if (did == 1)
		{
			this->m_EmpArray[index] = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			this->m_EmpArray[index] = new Manager(id, name, did);
		}
		else
		{
			this->m_EmpArray[index] = new Boss(id, name, did);
		}
		index++;
	}
	ifs.close();
}

//2.��ʾְ��
void WorkerManager::showEmp()
{
	if (m_FileIsEmpty == 1||m_Empnum == 0)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Empnum; i++)
		{
			//���ö�̬���ְ����Ϣ
			this->m_EmpArray[i]->showInfo();
		}
	}
}

//3.ɾ��ְ��
void WorkerManager::deleteEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����������ɾ����ְ����ţ�" << endl;
		int index = 0;
		cin >> index;
		if (this->empIsExist(index) == -1)
		{
			cout << "ɾ��ʧ�ܣ�û�и�ְ��" << endl;
		}
		else
		{
			for (int i = this->empIsExist(index); i + 1 < this->m_Empnum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			//ͬ�����ļ���
			this->save();
			
			cout << "ɾ���ɹ�" << endl;
		}
	}
}

//�ж�ְ������Ƿ����
int WorkerManager::empIsExist(int index)
{
	int flag = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == index)
		{
			flag = i;
		}
	}
	return flag;
}

//4.�޸�ְ��
void WorkerManager::modifyEmp()
{
	if (this->m_Empnum == 0||this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//������
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int index = 0;
		cin >> index;
		if (this->empIsExist(index) == -1)
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
			return;
		}
		else
		{
			cout << "�������µ�ְ����ţ�" << endl;
			int id;
			cin >> id;
			cout << "�������µ�ְ��������" << endl;
			string name;
			cin >> name;
			cout << "�������µ�ְ���ĸ�λ��ţ�" << endl
				<< "1 --- ��ͨԱ��" << endl
				<< "2 --- ����" << endl
				<< "3 --- �ϰ�" << endl;
			int did;
			cin >> did;
			while (did != 1 && did != 2 && did != 3)
			{
				cout << "�������������������λ���" << endl;
				cin >> did;
			}
			Worker* worker = NULL; //Ҫ��ӵ�ְ��
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}

			this->m_EmpArray[this->empIsExist(index)] = worker;
			
			cout << "ְ����Ϣ�޸ĳɹ�" << endl;
			this->save();
		}
	}
}

//5.����ְ��
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ" << endl
			<< "1 --- ���ձ�Ų���" << endl
			<< "2 --- ������������" << endl;
		int choice = 0;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "�����������������룡" << endl;
			cin >> choice;	
		}
		if (choice == 1) //���ձ��
		{
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			if (this->empIsExist(id) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ����ˣ���Ϣ���£�" << endl;
				this->m_EmpArray[this->empIsExist(id)]->showInfo();
			}
		}
		if (choice == 2) //��������
		{
			cout << "������Ҫ���ҵ�ְ������" << endl;
			string name;
			cin >> name;
			bool flag = false; //�Ƿ��ҵ�ְ��

			for (int i = 0; i < this->m_Empnum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}
		}

	}
}

//6.���ձ����������&����
void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl; 
	}
	else
	{
		cout << "��ѡ������ʽ" << endl
			<< "1 --- ����" << endl
			<< "2 --- ����" << endl;
		int select = 0;
		cin >> select;
		while (select != 1 && select != 2)
		{
			cout << "������������������" << endl;
			cin >> select;
		}
		for (int i = 0; i < this->m_Empnum; i++)
		{
			int minOrMaxIndex = i;
			for (int j = i + 1; j < this->m_Empnum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMaxIndex]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMaxIndex = j;
					}
				}
				if (select == 2) //����
				{
					if (this->m_EmpArray[minOrMaxIndex]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMaxIndex = j;
					}
				}
			}
			if (minOrMaxIndex != i)
			{
				Worker* temp = this->m_EmpArray[minOrMaxIndex];
				this->m_EmpArray[minOrMaxIndex] = this->m_EmpArray[i];
				this->m_EmpArray[i] = temp;
			}
		}
		cout << "������ɣ�" << endl;
		this->save(); //���浽�ļ���
		this->showEmp();
	}
}

//7.���ְ��
void WorkerManager::clearEmp()
{
	cout << "ȷ��Ҫ�����" << endl
		<< "1 --- ȷ��" << endl
		<< "2 --- ����" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "������������������" << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		//����ļ�����
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		//�������
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_Empnum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_Empnum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "��ճɹ�" << endl;
	}
	else
	{
		return;
	}

}

//��������
WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}