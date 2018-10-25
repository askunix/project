/*顺序栈操作头文件*/

#ifndef SequenceStack_c
#define SequenceStack_c

#include "SequenceStack.h"

//顺序栈函数列表 

Status InitStack_Sq(SqStack *s)
{
	(*s).base = (SElemType_Sq *)malloc(Stack_Init_Size*sizeof(SElemType_Sq));
	if (!(*s).base)
		exit(OVERFLOW);
	(*s).top = (*s).base;
	s->stacksize = Stack_Init_Size;

	return OK;
} //构造空栈 

Status DestroyStack_Sq(SqStack *s)
{
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->stacksize = 0;

	return OK;
}//删除一个栈

Status ClearStack_Sq(SqStack *s)
{
	DestroyStack_Sq(s);
	InitStack_Sq(s);

	return OK;
} //置空s

Status Copy_Sq(SqStack s, SqStack *newstack)
{
	newstack->base = (SElemType_Sq *)malloc(s.stacksize*sizeof(SElemType_Sq));
	if (!newstack->base)
		exit(OVERFLOW);
	newstack->stacksize = s.stacksize;
	newstack->top = newstack->base;
	SElemType_Sq *fakebase = s.base;
	for (fakebase = s.base; fakebase<s.top; fakebase++){
		*(newstack->top) = *fakebase;
		newstack->top++;
	}

	return OK;

}//拷贝一个栈 

Status StackisEmpty(SqStack s)
{
	if (s.base == s.top)
		return TRUE;
	else
		return FALSE;
}//判断是否为空

int StackLength_Sq(SqStack s)
{
	return s.top - s.base;
}//返回栈内元素的个数

Status GetTop_Sq(SqStack s, SElemType_Sq *e)
{
	if (s.top == s.base)
		return ERROR;

	*e = *(s.top - 1);
	return OK;
}//获取栈顶的元素

Status Push_Sq(SqStack *s, SElemType_Sq e)
{
	if ((s->top - s->base) >= s->stacksize){
		s->base = (SElemType_Sq *)realloc(s->base, (s->stacksize + Stack_Increment)*sizeof(SElemType_Sq));

		if (!s->base)
			exit(OVERFLOW);
		s->top = s->base + s->stacksize;
		s->stacksize += Stack_Increment;
	}
	*(s->top) = e;
	s->top++;

}//进栈

Status Pop_Sq(SqStack *s, SElemType_Sq *e)
{
	if (s->base == s->top)
		return ERROR;

	(s->top)--;
	*e = *(s->top);
	return OK;
}//出栈

Status StackTraverse_Sq(SqStack s, void(Visit)(SElemType_Sq))
{
	SElemType_Sq *p = s.base;

	while (p<s.top){
		Visit(*p);
		p++;
	}

	return OK;
} //访问栈 

#endif


