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
	return ((Q.Rear-Q.Front+1 )== Maxlength);
}

ElementType front (Queue Q)
{
	return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ)
{
	if (pQ->Front == pQ->Rear)
		makenullQueue(pQ);
	else pQ->Front++;
}

//void enQueue(ElementType X, Queue *pQ)
//{
//	if(fullQueue(*pQ))  //kiem tra ham day hay ko
//		printf("Hang day");
//	else
//	{
//		if(emptyQueue(*pQ))  //neu hang rong
//			pQ->Front=0;
//		if(pQ->Rear==Maxlength-1) //neu hang tran 
//		{
//			int i; 
//			for (i=pQ->Front;i<=pQ->Rear;i++)
//			{
//				pQ->Elements[i-pQ->Front]=pQ->Elements[i];
//			}
//			pQ->Rear=pQ->Rear-pQ->Front;
//			pQ->Front=0;
//		}
//		pQ->Rear=pQ->Rear+1;  //tang rear len 1dv (hang ko day ko tran)
//		pQ->Elements[pQ->Rear]=X;
//	}
//}

void enQueue(ElementType X,Queue *pQ){
	if (fullQueue(*pQ)) printf("hang day");
	
	else 
	{ 
		if (emptyQueue(*pQ)) (*pQ).Front = 0;
		if ((*pQ).Rear == Maxlength-1) 
		{
			int i;
			for(i = (*pQ).Front; i <= (*pQ).Rear; i++)
			(*pQ).Elements[i-(*pQ).Front]= (*pQ).Elements[i];
			(*pQ).Rear = (*pQ).Rear - (*pQ).Front;
			(*pQ).Front = 0; 
		}
		(*pQ).Rear = (*pQ).Rear + 1;
		(*pQ).Elements[(*pQ).Rear] = X;
	}
}













