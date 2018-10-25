#ifndef Maze_h
#define Maze_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
#include "SequenceStack.h"

//宏定义
#define N 15 //迷宫的大小
#define X 4 //用于随机取余，X越大生成迷宫的通行概率越大

#define SleepTime 2 //代表休眠时间

//迷宫方块的类型定义
typedef enum
{
	Wall, Obstacle, Way, DeadLock, //路径上的死胡同
	East, South, West, North,
	Start, End,
} MazeNode;



typedef int MazeType; //迷宫元素类型

//函数表
//穷举法的算法
Status MazePath(MazeType maze[][N], PosType start, PosType end);

//初始化
void InitMaze(MazeType maze[][N], PosType *start, PosType *end);

//在屏幕上画出迷宫
void PaintMaze(MazeType[][N]);

//显示迷宫
void ShowMaze(MazeType[][N]);

//比较是否为为同一通道块
Status EqualPosType(PosType a, PosType b);

//判定此通道快是否未访问
Status Passable(PosType seat, MazeType maze[][N]);

//留下初始足迹
void FootPrint(PosType seat, MazeType maze[][N]);

//更新通道快信息
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di);

//当前通道快的后继
PosType NextPos(PosType seat, int di);

// 判断是否越界
Status IsCross(PosType seat);

//标记不可访问
void MarkDeadLock(PosType seat, MazeType maze[][N]);

#endif



////迷宫的通道块坐标 注意：x表示从坐标，y表示横坐标
//typedef struct
//{
//	int x;
//	int y;
//} PosType;
////通道块信息
//typedef struct
//{
//	int ord; //通道快序列号
//	PosType seat; //坐标位置
//	int di; //下一个该访问的方向 东4 南5 西6 北7
//}SElemType_Sq;