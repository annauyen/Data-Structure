#include<stdio.h>
#include<malloc.h>
//--------------KHAI BAO LIST SO NGUYEN-----------------
//typedef int ElementType;
//struct Node{
//	 ElementType 	Element;
//	 Node*			Next;
//};
//typedef Node*    Position;
//typedef Position List;

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node*       Next;
};
typedef struct Node*	Position;
typedef Position    	List;

//============CAC PHEP TOAN TREN DS================
void makenullList(List *pL)
{
    (*pL)=          (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=    NULL;
}

int emptyList(List L)
{
	return (L->Next==NULL);
}

Position first(List L)
{
	return L;
}

Position endList(List L)
{
	Position P=first(L);
	while (P->Next != NULL)
		P=P->Next;
	return P;
}

Position previous(Position P, List L)
{
	Position Q = first(L);
	while (Q->Next !=P) Q = Q->Next;
	return Q; 
}

Position next(Position P, List L)
{
	return P->Next;
}
ElementType retrieve(Position P, List L) 
{
	return P->Next->Element;
}

Position locate(ElementType X, List L)
{
	Position P = first(L), E=endList(L);
	int Found = 0;
	while ((P != E) && (!Found))
	{
		if (retrieve(P,L) == X) Found = 1;
		else P = next(P, L);
	}
	return P;
}

void insertList(ElementType X, Position P, List *L)
{ 
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node)); 		/* 1 */
	T->Element=X; 						/* 2 */
	T->Next=P->Next; 					/* 3 */
	P->Next=T; 							/* 4 */
}

void deleteList(Position P, List *L) 
{
	Position Temp;
	Temp=P->Next; 						/* 1 */
	P->Next=Temp->Next; 				/* 2 */
	free(Temp); 						/* 3 */
}

//=============NHAP VA IN DS=========

void  readList(List *L)
{
	int n, i;
	ElementType X;
	scanf("%d",&n);
	makenullList(L);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &X);
		insertList(X, endList(*L),L);
	}
}

void printList(List L)
{
	Position P=first(L), E=endList(L);
	while (P!=E) 
	{
		printf("%d ", retrieve(P,L));
		P=next(P,L);
	}
}
//-----------------------------------------------------
//------------------CAC HAM MO RONG--------------------------

void append(ElementType X, List *pL) //-------> THEM NODE CUOI DS
{
	insertList(X,endList(*pL),pL);
}

void addFirst(ElementType X, List *pL)//------->THEM NODE DAU DS
{
	insertList(X,first(*pL),pL);
}

int member(ElementType x, List L)//------->KIEM TRA P.TU THUOC DS
{
	Position P;
	int found=0;
	P=first(L);
	while((P->Next!=NULL)&&(found==0))
	{
		if(retrieve(P,L) == x)
	  		found=1;
	  	else P=next(P,L);
	}
	return found;
}

void erase(ElementType x, List *pL)//------->XOA PTU X DAU TIEN
{
	Position P=first(*pL);
	P=locate(x,*pL);
	if(P->Next!=NULL)
	{
		deleteList(P,pL);
	}
	 else printf("Not found %d\n",x);
}

List difference(List L1, List L2)//------->HIEU 2 TAP HOP
{
	List L3;
	makenullList(&L3);
	Position P1;
	P1=first(L1);
	while (P1->Next!=NULL)
	{
		if(member(retrieve(P1,L1),L2)==0)
		append(retrieve(P1,L1),&L3);
		P1=next(P1,L1);
	}
	return L3;
}

List readSet()//------->NHAP VAO TAP HOP
{
	List L;
	ElementType x;
	makenullList(&L);
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(member(x,L)==0)
			addFirst(x,&L);
	}
	return L;
}

List intersection(List L1, List L2)//------->GIAO 2 T/H
{
	List L3;
	makenullList(&L3);
	Position P1;
	P1=first(L1);
	while (P1->Next!=NULL)
	{
		if(member(retrieve(P1,L1),L2)==1)
		append(retrieve(P1,L1),&L3);
		P1=next(P1,L1);
	}
	return L3;
}

List unionSet(List L1, List L2)//-------> HOP 2 T/H
{
	List L3;
	makenullList(&L3);
	Position P1,P2;
	P1=first(L1);
	P2=first(L2);
	while (P1->Next!=NULL)
	{
		append(retrieve(P1,L1),&L3);
		P1=next(P1,L1);
	}
	while (P2->Next!=NULL)
	{
		if(member(retrieve(P2,L2),L3)==0)
			append(retrieve(P2,L2),&L3);
		P2=next(P2,L2);
	}
	return L3;
}

void sort(List *pL)//------->SAP XEP
{
	Position P=first(*pL);
	Position Q;
	while(next(P,*pL)!=NULL)
	{
		Q=next(P,*pL);
		while(next(Q,*pL)!=NULL)
		{
			ElementType temp;
			if(retrieve(P,*pL)>retrieve(Q,*pL))
			{
				temp=retrieve(P,*pL);
				P->Next->Element=retrieve(Q,*pL);
				Q->Next->Element=temp;
			}
			Q=next(Q,*pL);
		}
		P=next(P,*pL);
	}
}

void removeAll(ElementType x, List *pL)//------->XOA HET PTU X
{
	Position P=first(*pL);
	P=locate(x,*pL);
	while(P->Next!=NULL)
	{
		deleteList(P,pL);
		P=locate(x,*pL);
	}
}

void printOddNumbers(List L)
{
	Position P=first(L);
	while(P->Next!=NULL)
	{
		if(retrieve(P,L)%2!=0)
			printf("%d ",retrieve(P,L));
		P=next(P,L);
	}
}

void normalize(List *pL)//------->CHUAN HOA
{
	Position P=first(*pL);
	while(P->Next!=NULL)
	{
		Position Q=next(P,*pL);
		while(Q->Next!=NULL)
		{
			if(retrieve(P,*pL)==retrieve(Q,*pL))
				deleteList(Q,pL);
			else Q=next(Q,*pL);
		}
		P=next(P,*pL);
	}
}

void copyEvenNumbers(List L1, List *pL2)
{
	makenullList(pL2);
	Position P=first(L1);
	while(P->Next!=NULL)
	{
		if(retrieve(P,L1)%2==0)
			append(retrieve(P,L1),pL2);
		P=next(P,L1);
	}
}

float getAvg(List L)
{
	Position P=first(L), E=endList(L);
	float sum=0;
	int temp=0;
	if(emptyList(L)==1) return -10000.0f;
	while (P!=E) 
	{
		sum=sum+retrieve(P,L);
		P=next(P,L);
		temp++;
	}
	return sum/(1.0*temp);
}







