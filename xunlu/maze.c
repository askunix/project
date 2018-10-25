

#ifndef Maze_c
#define Maze_c
#include "Maze.h"

Status MazePath(MazeType maze[][N], PosType start, PosType end)
{
	SqStack S; //���벽����ջģ��
	SElemType_Sq node; //ջ���Թ����ӵĴ洢��λ
	PosType curPos; //���ڵ�����
	int curStep; //

	InitStack_Sq(&S);
	curPos = start;
	curStep = 1;
	//�����·������ջ��
	do {
		if (Passable(curPos, maze))
		{ //�������ͨ����
			if (EqualPosType(curPos, end))
			{ //�Ƿ��ߵ��˾�ͷ
				FootPrint(curPos, maze);
				ShowMaze(maze);
				int total = StackLength_Sq(S);
				printf("\n  It takes %d steps to make it.", total);
				return OK;
			}
			FootPrint(curPos, maze); //�����������
			ShowMaze(maze);//ˢ�»�һ��
			SetSElemType(&node, curStep, curPos, East); //����ѹ��ջ�Ķ���
			Push_Sq(&S, node);//ѹ��ȥ
			curPos = NextPos(curPos, East); //̽����һ�� Ĭ����
			curStep++; //����ϲ��1
		}
		else{
			//����������ˣ�������ǽ���ϰ�����������
			if (!StackisEmpty(S)){
				//�ó�����һ���������
				Pop_Sq(&S, &node);

				//���̽�������ҵ����Ժ��Ǹ����������������ľ�����һ������
				while (node.di == North && !StackisEmpty(S)){
					MarkDeadLock(node.seat, maze);
					//���֮���ٻ�һ��
					ShowMaze(maze);
					Pop_Sq(&S, &node);
				}
				//�ı䷽��̽��һ��
				if (node.di<North){
					maze[node.seat.x][node.seat.y] = (++node.di);
					ShowMaze(maze);
					//�ı䷽�������ѹ��
					Push_Sq(&S, node);
					curPos = NextPos(node.seat, node.di);
				}
			}
		}

	} while (!StackisEmpty(S));
	printf("Total Step: %d", curStep);
	return ERROR;
}

//��ʼ��
void InitMaze(MazeType maze[][N], PosType *start, PosType *end)
{
	int i, j;
	int temp;
	srand((unsigned)time(NULL)); //Ѱ�������ʹ�ã���rand()����
	for (i = 0; i<N; i++){
		for (j = 0; j<N; j++)
		{
			if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
			{
				//�����Թ���ǽ
				maze[i][j] = Wall;
				//���ɳ��ں����

			}
			else 
			{
				temp = rand() % X; //�ķ�֮һ�ĸ��������ϰ�
				if (!temp)
				{
					maze[i][j] = Obstacle;
				}
				else 
				{
					maze[i][j] = Way;
				}
			}
		}
	}
	//���������յ������
	maze[1][0] = Way;
	maze[N - 2][N - 1] = Way;
	start->x = 1;
	start->y = 0;
	end->x = N - 2;
	end->y = N - 1;
}

//����Ļ�ϻ����Թ�
void PaintMaze(MazeType maze[][N])
{
	int i, j;
	for (i = 0; i<N; i++){
		for (j = 0; j<N; j++){
			if (maze[i][j] == Wall){
				printf("��");
			}
			else if (maze[i][j] == Obstacle){
				printf("��");
			}
			else if (maze[i][j] == East){
				printf("��");
			}
			else if (maze[i][j] == South){
				printf("��");
			}
			else if (maze[i][j] == West){
				printf("��");
			}
			else if (maze[i][j] == North){
				printf("��");
			}
			else if (maze[i][j] == DeadLock){
				printf("��");
			}
			else {
				printf("  ");
			}
			if (j == N - 1){
				printf("\n");
			}
		}
	}
}

//��ʾ�Թ� ˢ��
void ShowMaze(MazeType maze[][N])
{
	Wait(SleepTime);
	system("cls");
	PaintMaze(maze);
}

//�Ƚ��Ƿ�ΪΪͬһͨ����
Status EqualPosType(PosType a, PosType b)
{
	if (a.x == b.x&&a.y == b.y){
		return TRUE;
	}
	else {
		return ERROR;
	}
}

//�ж���ͨ���Ƿ���Ա�����
Status Passable(PosType seat, MazeType maze[][N])
{
	if (!IsCross(seat) && maze[seat.x][seat.y] == Way){
		return TRUE;
	}
	else {
		return ERROR;
	}
}

//���³�ʼ�㼣��������һ�η��ʷ��򣬳�ʼֵ��̽��
void FootPrint(PosType seat, MazeType maze[][N])
{
	maze[seat.x][seat.y] = East;
}

//����ͨ������Ϣ
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di)
{
	e->ord = ord;
	e->seat = seat;
	e->di = di;
}

//��ǰͨ����ĺ�� ע��y��ʾ������ x��ʾ������
PosType NextPos(PosType seat, int di)
{
	PosType temp = seat;
	switch (di){
	case East: temp.y++; break;
	case South: temp.x++; break;
	case West: temp.y--; break;
	case North: temp.x--; break;
	}
	return temp;
}

// �ж��Ƿ�Խ��,Խ�緵��true������false
Status IsCross(PosType seat)
{
	if (seat.x<0 || seat.y<0 || seat.x>N - 1 || seat.y>N - 1){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//��ǲ��ɷ���
void MarkDeadLock(PosType seat, MazeType maze[][N])
{
	maze[seat.x][seat.y] = DeadLock;
}

#endif
