#pragma once;

#include<iostream>
#include<Windows.h>
#include<cstdio>
#define NAME_MAX 20
#define TEL_MAX 12
#define SEX_MAX 4
#define MAX 1000

using namespace std;

enum{ Exit, Add, Del, Search, Modify, Empty, Sort, Show};

struct Stu
{
	char Name[NAME_MAX];
	int Age;
	char Tel[TEL_MAX];
	char Sex[SEX_MAX];
	char Address[50];
};

typedef struct Stu Stu;

typedef struct Contact
{
	Stu Con[MAX];       //����
	int sz;     //����
}Contact, *pContact;


//��������

void InitContact(pContact pCon);  //��ʼ��

void AddContact(pContact pCon);   //�½�

void ShowContact(pContact pCon);  //��ӡ

void DelContact(pContact pCon);   //ɾ��

void SearchContact(pContact pCon);   //����

void ModifyContact(pContact pCon);    //�޸�

void EmptyContact(pContact pCon);    //���

void SortContact(pContact pCon);    //����
