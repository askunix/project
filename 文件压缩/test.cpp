#include "FileCompress.h"



void menu()
{
	printf("*************************************************************\n");
	printf("***************  ��ӭʹ��huffman�ļ�ѹ������ ****************\n");
	printf("***************  0.�˳�   1.ѹ��      2.��ѹ ****************\n");
	printf("*************************************************************\n");
}

void test()
{
	menu();
	int select = 0;
	scanf("%d", &select);

	switch (select)
	{
	case 1:
	{
			  printf("�������ļ�����·�����ļ�ȫ�������磺D:\\test\\filename.txt��\n");
			  char filename[100] = { 0 };
			  scanf("%s", filename);
			  TestCompress(filename);
	}
		break;
	case 2:
	{
			  printf("�������ļ�����·�����ļ�ȫ�������磺D:\\test\\filename.huffman��\n");
			  char filename[100] = { 0 };
			  scanf("%s", filename);
			  TestUnCompress(filename);
	}
		break;
	case 0:
		exit(0);
		break;

	default:
		cout << "�������󣡣���"<<endl;
		break;
	}
}




int main()
{
	test();
	return 0;
}



//236