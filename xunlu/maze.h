#ifndef Maze_h
#define Maze_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
#include "SequenceStack.h"

//�궨��
#define N 15 //�Թ��Ĵ�С
#define X 4 //�������ȡ�࣬XԽ�������Թ���ͨ�и���Խ��

#define SleepTime 2 //��������ʱ��

//�Թ���������Ͷ���
typedef enum
{
	Wall, Obstacle, Way, DeadLock, //·���ϵ�����ͬ
	East, South, West, North,
	Start, End,
} MazeNode;



typedef int MazeType; //�Թ�Ԫ������

//������
//��ٷ����㷨
Status MazePath(MazeType maze[][N], PosType start, PosType end);

//��ʼ��
void InitMaze(MazeType maze[][N], PosType *start, PosType *end);

//����Ļ�ϻ����Թ�
void PaintMaze(MazeType[][N]);

//��ʾ�Թ�
void ShowMaze(MazeType[][N]);

//�Ƚ��Ƿ�ΪΪͬһͨ����
Status EqualPosType(PosType a, PosType b);

//�ж���ͨ�����Ƿ�δ����
Status Passable(PosType seat, MazeType maze[][N]);

//���³�ʼ�㼣
void FootPrint(PosType seat, MazeType maze[][N]);

//����ͨ������Ϣ
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di);

//��ǰͨ����ĺ��
PosType NextPos(PosType seat, int di);

// �ж��Ƿ�Խ��
Status IsCross(PosType seat);

//��ǲ��ɷ���
void MarkDeadLock(PosType seat, MazeType maze[][N]);

#endif



////�Թ���ͨ�������� ע�⣺x��ʾ�����꣬y��ʾ������
//typedef struct
//{
//	int x;
//	int y;
//} PosType;
////ͨ������Ϣ
//typedef struct
//{
//	int ord; //ͨ�������к�
//	PosType seat; //����λ��
//	int di; //��һ���÷��ʵķ��� ��4 ��5 ��6 ��7
//}SElemType_Sq;