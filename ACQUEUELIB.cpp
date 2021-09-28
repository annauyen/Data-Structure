#include<stdio.h>
#define Maxlength 100

typedef int ElementType;

typedef struct {
	ElementType Elements[Maxlength];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ)
{
	pQ->Front=-1;
	pQ->Rear=-1;
}

int emptyQueue(Queue Q)
{
	return (Q.Front==-1);
}

int fullQueue(Queue Q)
{
	return (Q.Rear-Q.Front+1)%Maxlength==0;
}

ElementType front (Queue Q)
{
	return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ)
{
	if(pQ->Front==pQ->Rear) //neu hang co 1 phan tu
	{
		makenullQueue(pQ);
	}
	else 
	{
		pQ->Front=(pQ->Front+1)%Maxlength;
	}
}

void enQueue(ElementType X,Queue *pQ)
{
	if(fullQueue(*pQ)) printf("Hang day");
	else 
	{
		if(emptyQueue(*pQ))
			pQ->Front=0;
		pQ->Rear=(pQ->Rear+1)%Maxlength;
		pQ->Elements[pQ->Rear]=X;
	}
}


