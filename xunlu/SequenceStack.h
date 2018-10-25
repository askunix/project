/*顺序栈操作头文件*/

#ifndef SequenceStack_h
#define SequenceStack_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*宏定义*/

#define Stack_Init_Size 100
#define Stack_Increment 10

//
////栈类型定义在如下几个问题需要重新定义
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
//通道块信息

typedef struct
{
	int ord; //通道快序列号
	PosType seat; //坐标位置
	int di; //下一个该访问的方向 东4 南5 西6 北7
}SElemType_Sq;

//定义一个栈的结构
typedef struct
{
	SElemType_Sq *base;
	SElemType_Sq *top;
	int stacksize;
}SqStack;

//顺序栈函数列表
Status InitStack_Sq(SqStack *s); //构造空栈

Status DestroyStack_Sq(SqStack *s); //删除一个栈

Status ClearStack_Sq(SqStack *s); //置空s

Status Copy_Sq(SqStack s, SqStack *newstack); //拷贝一个栈

Status StackisEmpty(SqStack s); //判断是否为空

int StackLength_Sq(SqStack s); //返回栈内元素的个数

Status GetTop_Sq(SqStack s, SElemType_Sq *e); //获取栈顶的元素

Status Push_Sq(SqStack *s, SElemType_Sq e); //进栈

Status Pop_Sq(SqStack *s, SElemType_Sq *e);//出栈

Status StackTraverse_Sq(SqStack s, void(Visit)(SElemType_Sq)); //访问栈

#endif

