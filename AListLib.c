#include<stdio.h>
//--------------KHAI BAO LIST SO NGUYEN-----------------
#define Maxlength 100

typedef int ElementType; //----> dinh nghia kieu phan tu cua mang
typedef int Position;

typedef struct{
	ElementType Elements[Maxlength];  //----->Mang ten la Elements co Maxlength phan tu
	Position	Last;
}List;  
//---------------------------------------------------------
//--------------CAC PHEP TOAN TREN DANH SACH-----------------

void makenullList(List *pL)
{
	pL->Last=0;
}

int emptyList(List L)
{
	return L.Last==0;
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

Position first(List L)
{
	return 1;
}

Position endList(List L)
{
	return L.Last+1;
}
ElementType retrieve(Position P, List L) //--------> ham lay gia tri phan tu tai vi tri P trong list L
{
	return L.Elements[P-1];
}
Position next(Position P, List L)
{
	return P=P+1;
}
Position previous(Position P,List L)
{
	return P=P-1;
}

void insertList(ElementType x, Position P, List *pL)
{
	int i=0;
	if(pL->Last==Maxlength) printf("Danh sach day\n");
	else 	if((P<1) || (P>pL->Last+1)) printf("Vi tri khong hop le\n");
			else
			{
				for (i=pL->Last;i>=P;i--)
				{
					pL->Elements[i]=pL->Elements[i-1];
				}
				pL->Last++;
				pL->Elements[P-1]=x;
			}
}

Position locate(ElementType x, List L)
{
	Position P;
	int found=0;
	P=1;
	while(P!=L.Last+1 && found==0)
	{
		if(retrieve(P,L)==x) found=1;
		else P++;
	}
	return P;
}

void deleteList(Position P, List *pL)
{
	if(P<1 || P>=pL->Last+1) printf("Vi tri khong hop le\n");
	else 	if (emptyList(*pL)==1) printf("Danh sach rong\n");
		 	else 
		 	{
		 		Position Q;
		 		for(Q=P;Q<pL->Last;Q++)
		 		{
		 			pL->Elements[Q-1]=pL->Elements[Q];
				}
				pL->Last--;
			}	
	
}

//------------------HAM NHAP/HAM IN DANH SACH------------------------

void readList(List *pL)
{
	int n,p;
	ElementType x;
	scanf("%d",&n);
	
	makenullList(pL);
	
	for(p=1;p<=n;p++)
	{
		scanf("%d",&x);
		insertList(x,p,pL);
	}
}

void printList(List L)
{
	Position P;
	P=1;
	while(P!=L.Last+1)
	{
		printf("%d ",retrieve(P,L));
		P++;
	}
}
//-----------------HAM MO RONG--------------
//============================
int member(ElementType x, List L)
{
	Position P;
	int found=0;
	P=1;
	while((P!=L.Last+1)&&(found==0))
	{
		if(retrieve(P,L) == x)
	  		found=1;
	  	else P++;
	}
	return found;
}
void insertSet(ElementType x, List *pL)
{
	insertList(x,pL->Last+1,pL);
}

float getAvg(List L)
{
	Position i;
	float sum=0;
	if(emptyList(L)==1) return -10000.0000;
	else
	{
		for(i=1;i<L.Last+1;i++)
		{
		sum=sum+retrieve(i,L);
		}
		return sum/(1.0*L.Last);
	}
	
}

void copyEvenNumbers(List L1, List *pL2)
{
	makenullList(pL2);
	Position i;
	
	for (i=first(L1);i<endList(L1);i++)
	{
		int q=retrieve(i,L1);
		if(q%2==0)
			insertList(q, pL2->Last+1, pL2);
	}
}

void difference(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i;
	i=1;
	for (i=1;i<L1.Last+1;i++)
	{
		if(member(retrieve(i,L1),L2)==0)
			insertSet(retrieve(i,L1),pL);
	}
}

void erase(ElementType x, List *pL)
{
	int p=locate(x,*pL);
	if(p>=1 && p<=pL->Last)
	{
        deleteList(p,pL);
    }
}

void intersection(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i;
	i=1;
	for (i=1;i<L1.Last+1;i++)
	{
		if(member(retrieve(i,L1),L2)==1)
			insertSet(retrieve(i,L1),pL);
	}
}

void normalize(List *pL)
{
	Position p=first(*pL);
	while(p!=pL->Last+1)
	{
		Position q=p+1;
		while (q!=pL->Last+1)
		{
			if(retrieve(p,*pL)==retrieve(q,*pL))
				deleteList(q,pL);
			else q=q+1;
		}
		p=p+1;
	}
}

void printOddNumbers(List L)
{
	Position i;

	for (i=first(L);i<endList(L);i++)
	{
		if(retrieve(i,L)%2!=0)
			printf("%d ",retrieve(i,L));
	}
}

void readSet(List *pL)
{
	int n;
	int i;
	ElementType x;
	Position p=1;
	makenullList(pL);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(member(x,*pL)==0)
			insertSet(x,pL);
			p++;
	}
}

void removeAll(ElementType x, List *pL)
{
	Position p;
	p=locate(x,*pL);
	while((p>=1)&&(p<=pL->Last))
	{
		deleteList(p,pL);
		p=locate(x,*pL);
	}
}

void sort(List *pL)
{
	Position p;
	Position q;
	
	for(p=1;p<pL->Last+1;p++)
	{
		for(q=p+1;q<pL->Last+1;q++)
		{
			if(retrieve(p,*pL)>retrieve(q,*pL))
			{
				int temp=0;
				temp=retrieve(p,*pL);
				pL->Elements[p-1]=pL->Elements[q-1];
				pL->Elements[q-1]=temp;
			}
		}
	}
}

void unionSet(List L1, List L2, List *pL)
{
	makenullList(pL);
	Position i,j;
	i=1;
	j=1;
	for(i=1;i<L1.Last+1;i++)
	{
		retrieve(i,L1);
		insertSet(retrieve(i,L1),pL);
	}
	for(j=1;j<L2.Last+1;j++)
	{
		if(member(retrieve(j,L2),*pL)==0)
			insertSet(retrieve(j,L2),pL);
	}
	
}
//----------------mot so ham lam them----------
int countList(ElementType X, List L)
{
	int cnt=0;
	Position P=1;
	for(P=1; P<L.Last+1; P++)
	{
		if(retrieve(P,L)==X)
			cnt++;
	}
	return cnt;
}

ElementType minList(List L)
{
	Position P;
	int min=retrieve(first(L),L);
	for(P=1;P<L.Last+1;P++)
	{
		if(retrieve(P,L)<min)
		min=retrieve(P,L);
	}
	return min;
}

ElementType maxList(List L)
{
	Position P;
	int max=retrieve(first(L),L);
	for(P=1;P<L.Last+1;P++) //chu y: P<L.Last+1
	{
		if(retrieve(P,L)>max)
		max=retrieve(P,L);
	}
	return max;
}

int sumList(List L)
{
	Position P=1;
	int S=0;
	for(P=1;P<L.Last+1;P++)
	{
		S=S+retrieve(P,L);
	}
	return S;
}













