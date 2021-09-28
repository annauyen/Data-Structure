#include<stdio.h>
#include "E:\STUDY\CT177_CTDL\AListLib.c"

typedef List Queue;

void makenullQueue(Queue *pQ)
{
	makenullList(pQ);
}

int emptyQueue(Queue Q)
{
	return emptyList(Q);
}

void enQueue(ElementType X, Queue *pQ)
{
	insertList(X,endList(*pQ),pQ);
}

void deQueue(Queue *pQ)
{
	deleteList(first(*pQ),pQ);
}

ElementType front(Queue Q)
{
	return retrieve(first(Q),Q);
}
