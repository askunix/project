

#ifndef Maze_c
#define Maze_c
#include "Maze.h"

Status MazePath(MazeType maze[][N], PosType start, PosType end)
{
	SqStack S; //存入步数的栈模型
	SElemType_Sq node; //栈内迷宫格子的存储单位
	PosType curPos; //现在的坐标
	int curStep; //

	InitStack_Sq(&S);
	curPos = start;
	curStep = 1;
	//求得线路即放入栈中
	do {
		if (Passable(curPos, maze))
		{ //如果可以通过则
			if (EqualPosType(curPos, end))
			{ //是否走到了尽头
				FootPrint(curPos, maze);
				ShowMaze(maze);
				int total = StackLength_Sq(S);
				printf("\n  It takes %d steps to make it.", total);
				return OK;
			}
			FootPrint(curPos, maze); //标记往东走着
			ShowMaze(maze);//刷新画一遍
			SetSElemType(&node, curStep, curPos, East); //创造压入栈的对象
			Push_Sq(&S, node);//压进去
			curPos = NextPos(curPos, East); //探索下一步 默认向东
			curStep++; //步数喜加1
		}
		else{
			//如果不能走了，包括：墙，障碍，死锁方块
			if (!StackisEmpty(S)){
				//拿出来上一个看看情况
				Pop_Sq(&S, &node);

				//如果探索完了且弹出以后标记个死锁，还有其他的就再来一个试试
				while (node.di == North && !StackisEmpty(S)){
					MarkDeadLock(node.seat, maze);
					//标记之后再画一次
					ShowMaze(maze);
					Pop_Sq(&S, &node);
				}
				//改变方向探索一次
				if (node.di<North){
					maze[node.seat.x][node.seat.y] = (++node.di);
					ShowMaze(maze);
					//改变方向后重新压入
					Push_Sq(&S, node);
					curPos = NextPos(node.seat, node.di);
				}
			}
		}

	} while (!StackisEmpty(S));
	printf("Total Step: %d", curStep);
	return ERROR;
}

//初始化
void InitMaze(MazeType maze[][N], PosType *start, PosType *end)
{
	int i, j;
	int temp;
	srand((unsigned)time(NULL)); //寻找随机数使用，与rand()搭配
	for (i = 0; i<N; i++){
		for (j = 0; j<N; j++)
		{
			if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
			{
				//生成迷宫外墙
				maze[i][j] = Wall;
				//生成出口和入口

			}
			else 
			{
				temp = rand() % X; //四分之一的概率生成障碍
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
	//设置起点和终点的坐标
	maze[1][0] = Way;
	maze[N - 2][N - 1] = Way;
	start->x = 1;
	start->y = 0;
	end->x = N - 2;
	end->y = N - 1;
}

//在屏幕上画出迷宫
void PaintMaze(MazeType maze[][N])
{
	int i, j;
	for (i = 0; i<N; i++){
		for (j = 0; j<N; j++){
			if (maze[i][j] == Wall){
				printf("■");
			}
			else if (maze[i][j] == Obstacle){
				printf("■");
			}
			else if (maze[i][j] == East){
				printf("→");
			}
			else if (maze[i][j] == South){
				printf("↓");
			}
			else if (maze[i][j] == West){
				printf("←");
			}
			else if (maze[i][j] == North){
				printf("↑");
			}
			else if (maze[i][j] == DeadLock){
				printf("×");
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

//显示迷宫 刷新
void ShowMaze(MazeType maze[][N])
{
	Wait(SleepTime);
	system("cls");
	PaintMaze(maze);
}

//比较是否为为同一通道块
Status EqualPosType(PosType a, PosType b)
{
	if (a.x == b.x&&a.y == b.y){
		return TRUE;
	}
	else {
		return ERROR;
	}
}

//判定此通道是否可以被访问
Status Passable(PosType seat, MazeType maze[][N])
{
	if (!IsCross(seat) && maze[seat.x][seat.y] == Way){
		return TRUE;
	}
	else {
		return ERROR;
	}
}

//留下初始足迹，设置下一次访问方向，初始值向东探索
void FootPrint(PosType seat, MazeType maze[][N])
{
	maze[seat.x][seat.y] = East;
}

//更新通道快信息
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di)
{
	e->ord = ord;
	e->seat = seat;
	e->di = di;
}

//当前通道快的后继 注意y表示横坐标 x表示纵坐标
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

// 判断是否越界,越界返回true，否则false
Status IsCross(PosType seat)
{
	if (seat.x<0 || seat.y<0 || seat.x>N - 1 || seat.y>N - 1){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//标记不可访问
void MarkDeadLock(PosType seat, MazeType maze[][N])
{
	maze[seat.x][seat.y] = DeadLock;
}

#endif
