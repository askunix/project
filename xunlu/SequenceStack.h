/*˳��ջ����ͷ�ļ�*/

#ifndef SequenceStack_h
#define SequenceStack_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*�궨��*/

#define Stack_Init_Size 100
#define Stack_Increment 10

//
////ջ���Ͷ��������¼���������Ҫ���¶���
//#if !defined Maze_h &&\
//!defined LineEdit_h
//
//typedef int SElemType_Sq;
//
//#endif

typedef struct
{
	int x;
	int y;
} PosType;
//ͨ������Ϣ

typedef struct
{
	int ord; //ͨ�������к�
	PosType seat; //����λ��
	int di; //��һ���÷��ʵķ��� ��4 ��5 ��6 ��7
}SElemType_Sq;

//����һ��ջ�Ľṹ
typedef struct
{
	SElemType_Sq *base;
	SElemType_Sq *top;
	int stacksize;
}SqStack;

//˳��ջ�����б�
Status InitStack_Sq(SqStack *s); //�����ջ

Status DestroyStack_Sq(SqStack *s); //ɾ��һ��ջ

Status ClearStack_Sq(SqStack *s); //�ÿ�s

Status Copy_Sq(SqStack s, SqStack *newstack); //����һ��ջ

Status StackisEmpty(SqStack s); //�ж��Ƿ�Ϊ��

int StackLength_Sq(SqStack s); //����ջ��Ԫ�صĸ���

Status GetTop_Sq(SqStack s, SElemType_Sq *e); //��ȡջ����Ԫ��

Status Push_Sq(SqStack *s, SElemType_Sq e); //��ջ

Status Pop_Sq(SqStack *s, SElemType_Sq *e);//��ջ

Status StackTraverse_Sq(SqStack s, void(Visit)(SElemType_Sq)); //����ջ

#endif

