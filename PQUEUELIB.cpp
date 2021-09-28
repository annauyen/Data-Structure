#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef struct {
	Position Front, Rear;
}Queue;

void makenullQueue(Queue *pQ)
{
	Position Header;
	Header=(struct Node*)malloc(sizeof(struct Node));
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
}

int emptyQueue(Queue Q)
{
	return (Q.Front==Q.Rear);
}

ElementType front(Queue Q)
{
	return Q.Front->Next->Element;
}

void enQueue(ElementType X, Queue *pQ)
{
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=X;
	T->Next=NULL;
	pQ->Rear->Next=T;
	pQ->Rear=T;
}

void deQueue(Queue *pQ)
{
	Position T;
	pQ->Front=T;
	pQ->Front=T->Next;
	free(T);
}









