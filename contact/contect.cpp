#define _CRT_SECURE_NO_WARNINGS 1
#include"contect.h"



void InitContact(pContact pCon)
{
	pCon->sz = 0;
	memset(pCon->Con, 0, MAX * sizeof(Stu));
}



void AddContact(pContact pCon)
{
	cout<<"��������ϵ��������";
	cin >> pCon->Con[pCon->sz].Name;
	cout << "��������ϵ�����䣺";
	cin >> pCon->Con[pCon->sz].Age; 
	cout << "��������ϵ�˵绰��";
	cin >> pCon->Con[pCon->sz].Tel;
	cout << "��������ϵ���Ա�";
	cin >> pCon->Con[pCon->sz].Sex;
	cout << "��������ϵ�˵�ַ��";
	cin >> pCon->Con[pCon->sz].Address;
	cout << "�T�T�T�T�T��ϵ�� " << pCon->Con[pCon->sz].Name << " ����Ϣ����ɹ��T�T�T�T" << endl << endl;
	pCon->sz++;
	
}



void ShowContact(pContact pCon)
{
	cout << endl; 
	cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	printf("%3s\t%6s\t%2s%16s%8s%20s\n","�U���","����","����","�绰","�Ա�","��ַ�U");
		for (int i = 0; i < pCon->sz; i++)
		{
			
			printf("%3d\t%6s\t%2d%16s%8s%20s\n", 
				i + 1, 
				pCon->Con[i].Name,
				pCon->Con[i].Age, 
				pCon->Con[i].Tel, 
				pCon->Con[i].Sex,
				pCon->Con[i].Address);


			
			//printf("\n�U-------------------------------------------------------------�U\n");
		}
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		cout << "��ܰ��ʾ�������ɣ�����" << endl << endl;
}


int FindInContact(pContact pCon, char *ch)
{
	for (int i = 0; i < pCon->sz; i++)
	{
		if (strcmp(pCon->Con[i].Name,ch) == 0)
		{
			return i;
		}
		
	}
	return -1;
}


void DelContact(pContact pCon)
{
	char ch[20];
	ShowContact(pCon);
	cout << "����������ͨѶ¼��Ҫɾ����ϵ�˵�������";
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);
	if (NULL == -1)
	{
		printf("ͨѶ¼��û�и���ϵ�ˣ�����");
	}
	if (NUM <= pCon->sz && NUM != -1)
	{
		for (int j = NUM; j <= pCon->sz-1; j++)
		{
			pCon->sz--;
			pCon->Con[j] = pCon->Con[j + 1];
			printf("ɾ���ɹ�������\n");
		}
	}
	
}



void SearchContact(pContact pCon)
{
	char ch[20];
	printf("�������Ҫ������ϵ�˵�������");
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);
	if (NUM != -1)
	{
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		printf("%3s\t%6s\t%2s%16s%8s%20s\n", "�U���", "����", "����", "�绰", "�Ա�", "��ַ�U");
		printf("%3d\t%6s\t%2d%16s%8s%20s\n",
			NUM + 1,
			pCon->Con[NUM].Name,
			pCon->Con[NUM].Age,
			pCon->Con[NUM].Tel,
			pCon->Con[NUM].Sex,
			pCon->Con[NUM].Address);
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;

	}
	else
		printf("��Ҫ�ҵ���ϵ�˲�����\n");
}




void ModifyContact(pContact pCon)
{
	char ch[NAME_MAX];

	printf("������Ҫ�޸ĵ���ϵ�˵�������");
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);

	if (NUM != -1)
	{
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		printf("%3s\t%6s\t%2s%16s%8s%20s\n", "�U���", "����", "����", "�绰", "�Ա�", "��ַ�U");
		printf("%3d\t%6s\t%2d%16s%8s%20s\n",
			NUM,
			pCon->Con[NUM].Name,
			pCon->Con[NUM].Age,
			pCon->Con[NUM].Tel,
			pCon->Con[NUM].Sex,
			pCon->Con[NUM].Address);

		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;


		printf("��������޸ĳɣ�");
		scanf("%s", pCon->Con[NUM].Name);

		printf("��������޸ĳɣ�");
		scanf("%d", &pCon->Con[NUM].Age);

		printf("��ѵ绰�޸ĳɣ�");
		scanf("%s", pCon->Con[NUM].Tel);

		printf("����Ա��޸ĳɣ�");
		scanf("%s", pCon->Con[NUM].Sex);

		printf("��ѵ�ַ�޸ĳɣ�");
		scanf("%s", pCon->Con[NUM].Address);

	
	}
}
		

			
				
			





void EmptyContact(pContact pCon)
{
	pCon->sz = 0;
	printf("��ճɹ�������\n\n");
}




void SortContact(pContact pCon)
{
	for (int i = 0; i < pCon->sz; i++)
	{
		for (int j = 0; j < pCon->sz-i-1; j++)
		{
			if (strcmp(pCon->Con[j].Name, pCon->Con[j + 1].Name)>0)
			{
				Stu temp;
				temp = pCon->Con[j];
				pCon->Con[j] = pCon->Con[j + 1];
				pCon->Con[j + 1] = temp;
			}
		}
	}
}