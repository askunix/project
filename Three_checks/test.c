#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
#include<time.h>


menu()
{
	printf("**********************************************\n");
	printf("*****************   ����������   *************\n");
	printf("***************** 1.play  2.exit *************\n");
	printf("**********************************************\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = {0};

	InitBoard(board, ROW, COL);
	Display(board, ROW, COL);

	while(1)
	{
		printf("����ߣ�\n");
		PlayerMove(board, ROW, COL);
		Display(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret!=' ')
		{
			break;
		}


		printf("�����ߣ�\n");
		ComputerMove(board,ROW,COL);
		Display(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		
		
	}
	if (ret == 'X')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '0')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}


void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			   game();
				break;
			case 2:
				break;
			default:
				printf("����������");
				break;
		}
	} while (input);

}


int main()
{
	
	test();
	system("pause");
	return 0;
}