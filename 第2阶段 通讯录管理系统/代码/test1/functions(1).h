#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "addressbook.h"

//��ʾ�˵�
void showMenu();
//1�������ϵ��
void addPerson(Addressbook &ab);
//2����ʾ�����У���ϵ��
void showPerson(const Addressbook &ab);
//3��ɾ����ϵ��
void deletePerson(Addressbook &ab);
//4��������ϵ��
void findPerson(const Addressbook &ab);
//5���޸���ϵ��
void modifyPerson(Addressbook &ab);
//6����գ����У���ϵ��
void clearPerson(Addressbook &ab);

int isExist(const Addressbook &ab, string name); //�ж���ϵ���Ƿ����
#endif