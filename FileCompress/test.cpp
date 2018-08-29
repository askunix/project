#include "FileCompress.h"



void menu()
{
	printf("*************************************************************\n");
	printf("***************  欢迎使用huffman文件压缩工具 ****************\n");
	printf("***************  0.退出   1.压缩      2.解压 ****************\n");
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
			  printf("请输入文件所在路径和文件全名：（如：D:\\test\\filename.txt）\n");
			  char filename[100] = { 0 };
			  scanf("%s", filename);
			  TestCompress(filename);
	}
		break;
	case 2:
	{
			  printf("请输入文件所在路径和文件全名：（如：D:\\test\\filename.huffman）\n");
			  char filename[100] = { 0 };
			  scanf("%s", filename);
			  TestUnCompress(filename);
	}
		break;
	case 0:
		exit(0);
		break;

	default:
		cout << "输入有误！！！"<<endl;
		break;
	}
}




int main()
{
	test();
	return 0;
}



//236