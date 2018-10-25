/*˳��ջ����ͷ�ļ�*/

#ifndef SequenceStack_c
#define SequenceStack_c

#include "SequenceStack.h"

//˳��ջ�����б� 

Status InitStack_Sq(SqStack *s)
{
	(*s).base = (SElemType_Sq *)malloc(Stack_Init_Size*sizeof(SElemType_Sq));
	if (!(*s).base)
		exit(OVERFLOW);
	(*s).top = (*s).base;
	s->stacksize = Stack_Init_Size;

	return OK;
} //�����ջ 

Status DestroyStack_Sq(SqStack *s)
{
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->stacksize = 0;

	return OK;
}//ɾ��һ��ջ

Status ClearStack_Sq(SqStack *s)
{
	DestroyStack_Sq(s);
	InitStack_Sq(s);

	return OK;
} //�ÿ�s

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

}//����һ��ջ 

Status StackisEmpty(SqStack s)
{
	if (s.base == s.top)
		return TRUE;
	else
		return FALSE;
}//�ж��Ƿ�Ϊ��

int StackLength_Sq(SqStack s)
{
	return s.top - s.base;
}//����ջ��Ԫ�صĸ���

Status GetTop_Sq(SqStack s, SElemType_Sq *e)
{
	if (s.top == s.base)
		return ERROR;

	*e = *(s.top - 1);
	return OK;
}//��ȡջ����Ԫ��

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

}//��ջ

Status Pop_Sq(SqStack *s, SElemType_Sq *e)
{
	if (s->base == s->top)
		return ERROR;

	(s->top)--;
	*e = *(s->top);
	return OK;
}//��ջ

Status StackTraverse_Sq(SqStack s, void(Visit)(SElemType_Sq))
{
	SElemType_Sq *p = s.base;

	while (p<s.top){
		Visit(*p);
		p++;
	}

	return OK;
} //����ջ 

#endif


