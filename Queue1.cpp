#include<stdio.h>
//#include<malloc.h>

#include "E:\STUDY\CT177_CTDL\ELSE\QUEUE\AQUEUELIB.cpp" 

void readQueue(Queue *pQ, int n)
{
	int i;
	makenullQueue(pQ);
	int X;
//	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&X);
		enQueue (X,pQ);
	}
}

void printQueue(Queue Q)
{
	while(!emptyQueue(Q))
	{
		printf("%d ",front(Q));
		deQueue(&Q);
	}
}

int thuchien(Queue Q1, Queue Q2)
{
	int count = 0;
	int X;
	while(!emptyQueue(Q2))
	{
		X=front(Q1);
		deQueue(&Q1);
		if(X==front(Q2))
		{
			deQueue(&Q2);
		}
		else
		{
			enQueue(X,&Q1);
		}
		count ++;
	}
	return count;
}

int main()
{
	Queue Q1,Q2;
	int n;
	scanf("%d",&n);
	readQueue(&Q1,n);
	readQueue(&Q2,n);
//	printQueue(Q1);
//	printf("\n");
//	printQueue(Q2);
	printf("%d",thuchien(Q1,Q2));
	
	return 0;
}









