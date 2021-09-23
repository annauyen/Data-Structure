#include<stdio.h>
#include<malloc.h>
#include<string.h>
//-----------khai bao----------------
typedef struct {
	char ID[10];
	char Name[50];
	float R1, R2, R3;
}Student;

struct Node{
	Student Element;
	struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;
//--------------------------------
//------------------CAC PHEP TOAN---------------------
List getList()
{
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}

Student retrieve(Position P, List L)
{
	return P->Next->Element;
}

struct Node* first(List L)
{
	return L;
}

struct Node* endList(List L)
{
	struct Node* P=L;
	while (P->Next != NULL)
		P=P->Next;
	return P;
}

struct Node* locate(char x[10], List L)
{
	struct Node* P=L;
	int found=0;
	while (P->Next!=NULL && !found)
	{
		Student s=P->Next->Element;
		int kq=strcmp(s.ID,x);
		if(kq==0)
			found = 1;
		else P=P->Next;
	}
	return P;
}
//int member(char x[10], List L)
//{
//	struct Node* P=L;
//	int found=0;
//	while (P->Next!=NULL && !found)
//	{
//		Student s=P->Next->Element;
//		int kq=strcmp(s.ID,x);
//		if(kq==0)
//			found = 1;
//		else P=P->Next;
//	}
//	return found;
//}


void insertList(Student X, Position P, List *L)
{ 
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node)); 		/* 1 */
	T->Element=X; 										/* 2 */
	T->Next=P->Next; 									/* 3 */
	P->Next=T; 											/* 4 */
}

//int append(Student s,List *pL) //-------->DANG GAP VAN DE(fixed)
//{
////	struct Node* P=first(*pL);
//	struct Node* E= endList(*pL);
//	struct Node* F=locate(s.ID,*pL);
//	if(F==E)
//	{
//		insertList(s,endList(*pL),pL);
////		printf("ok\n");	
//	}
//	else
//	{
//		return 0;
//	}
//	return 1;	
//}

int append(Student s, List *pL)
{
	struct Node* P = locate(s.ID,*pL);
	if(P->Next!=NULL) return 0;
	
	struct Node* T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=s;
	T->Next=P->Next; //T->Next = NULL cung duoc (do append o cuoi ds)
	P->Next=T;
	
	return 1;
}
List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList();
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		if(locate(s.ID,L)==endList(L))
		{
		    append(s,&L);
		}
		else
		{
		    printf("%s exists\n",s.ID);
		}  
	}
	return L;
}    

void printList(List L)
{
	Student X;
	float tong=0, trb=0;
	int stt=0;
	struct Node* P=L;
	while (P->Next!=NULL)
	{
		X=P->Next->Element;
		tong=X.R1+X.R2+X.R3;
		trb=tong/3.0;
		stt++;
		printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",stt,X.ID,X.Name,X.R1,X.R2,X.R3,trb);
		P=P->Next;
	}
}
void showPassedList(List L)
{
	Student X;
	float tong=0, trb=0;
	int temp=0,stt=0;
	struct Node* P=L;
//	Position E=endList(L);
	while (P->Next!=NULL)
	{
		X=P->Next->Element;
		tong=X.R1+X.R2+X.R3;
		trb=tong/3.0;
		stt++;
		if(trb>=4.0)
		{
			printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",stt,X.ID,X.Name,X.R1,X.R2,X.R3,trb);
			temp++;
		}
		P=P->Next;
	}
	printf("%d students in total\n",temp);
}	
	
List getFailedList(List L)
{
	List KQ;
	KQ=getList();
	Student X;
	float tong=0, trb=0;
	int stt=0;
	struct Node* P=L;
	while (P->Next!=NULL)
	{
		X=P->Next->Element;
		tong=X.R1+X.R2+X.R3;
		trb=tong/3.0;
		stt++;
		if(trb<4.0)
		{
			append(X,&KQ);
		}
		P=P->Next;
	}
	printList(KQ);
	return KQ;
}










