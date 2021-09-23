#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define Maxlength 40

//----KHAI BAO DS SINH VIEN------------------
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef int Position;

typedef struct{
	struct SinhVien A[Maxlength];
	Position n;
}DanhSach;
//================================
//==============CAC PHEP TOAN TREN DANH SACH============
DanhSach dsRong()
{
	DanhSach L;
	L.n=0;
	return L;
}

int ktDay(DanhSach L)
{
	return L.n==Maxlength;
}

int ktRong(DanhSach L)
{
	return L.n==0;
	
}
Position first(DanhSach L)
{
	return 1;
}

Position endDanhSach(DanhSach L)
{
	return L.n+1;
}

struct SinhVien retrieve(Position P,DanhSach L)
{
	return L.A[P-1];
}

Position next(Position P, DanhSach L)
{
	return P=P+1;
}

Position previous(Position P, DanhSach L)
{
	return P=P-1;
}

void chenCuoi(struct SinhVien s, DanhSach *pL)
{
	if(ktDay(*pL))
		printf("Loi! Danh sach day");
	else
	{
		pL->A[pL->n]=s;
		pL->n++;
	}
}

void printDanhSach(DanhSach L)
{
	struct SinhVien X;
	Position P=first(L);
	Position E=endDanhSach(L);
	while (P!=E)
	{
		X=retrieve(P,L);
		printf("%s - %s - %.2f - %.2f - %.2f\n",X.MSSV,X.HoTen,X.DiemLT,X.DiemTH1,X.DiemTH2);
		P=next(P,L);
	}
	
}

int xoaTai(int p, DanhSach *pL)
{
	if(p<1||p>pL->n+1)
		return 0;
	else{
		int i;
		for(i=p;i<=pL->n;i++)
		{
			pL->A[i-1] = pL->A[i];
		}
		pL->n--;
		return 1;
	}
}

DanhSach chepKhongDat(DanhSach L)
{
	DanhSach KQ;
	KQ=dsRong();
	float tong=0;
	struct SinhVien X;
	int P=1,E=L.n+1;
	while(P!=E)
	{
		X=L.A[P-1];
		tong=X.DiemLT + X.DiemTH1 + X.DiemTH2;
		if(tong<4.0)
			chenCuoi(X,&KQ);
		P=P+1;
	}
	return KQ;
}

void hienthiDat(DanhSach L)
{
	float tong=0;
	struct SinhVien X;
	int P=1, E=L.n+1;
	while (P!=E)
	{
		X=L.A[P-1];
		tong=X.DiemLT + X.DiemTH1 + X.DiemTH2;
		if(tong>=4.0)
		{
			printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",X.MSSV,X.HoTen,X.DiemLT,X.DiemTH1,X.DiemTH2,tong);
		}
		P=P+1;
	}
}

int tim(char x[10], DanhSach L )
{
	int P=1;
	
	struct SinhVien s;
	int found = 0;
	while (P!=L.n+1 && !found)
	{
		s=retrieve(P,L);
		int kq=strcmp(s.MSSV,x);
		if(kq==0)
			found=1;
		else P=P+1;
	}
	return P;
}

void xoaSinhVien(char x[], DanhSach *pL) //-----> ham dung
{
	int p=tim(x,*pL);
	if(p!=pL->n+1)
	{
		xoaTai(p,pL);
	}
	else p++;
}

void hienthi(DanhSach L)
{
	struct SinhVien X;
	float tong=0;
	Position P=1;
	Position E=L.n+1;
	while (P!=E)
	{
		X=L.A[P-1];
		tong=X.DiemLT + X.DiemTH1 + X.DiemTH2;
		printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",X.MSSV,X.HoTen,X.DiemLT,X.DiemTH1,X.DiemTH2,tong);
		P=next(P,L);
	}
	
}

int member(char x[10], DanhSach L )
{
	int P=1;
	
	struct SinhVien s;
	int found = 0;
	while (P!=L.n+1 && !found)
	{
		s=retrieve(P,L);
		int kq=strcmp(s.MSSV,x);
		if(kq==0)
			found=1;
		else P=P+1;
	}
	return found;
} 

DanhSach nhap()
{
	DanhSach L;
	struct SinhVien X;
	L=dsRong();
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" ");
		fgets(X.MSSV,sizeof(X.MSSV),stdin);
		int l=strlen(X.MSSV);
		if(X.MSSV[l-1]=='\n')
		{
			X.MSSV[l-1]='\0';
		}
		fgets(X.HoTen,sizeof(X.HoTen),stdin);
		l=strlen(X.HoTen);
		if(X.HoTen[l-1]=='\n')
		{
			X.HoTen[l-1]='\0';
		}
		scanf("%f%f%f",&X.DiemLT,&X.DiemTH1,&X.DiemTH2);
		
		if(tim(X.MSSV,L)==L.n+1)
		{
			chenCuoi(X,&L);
		}
	}
	return L;
}

//--------------SORT DANH SACH SV--------------
//void replace(struct SinhVien X, Position P, List *pL)
//{
//	insertList(X,P,pL);
//	deleteList(next(P,*pL),L);
//}
//void swap(Position P, Position Q, List *pL)
//{
//	struct SinhVien X = retrieve(P,*pL);
//	struct SinhVien Y = retrieve(Q,*pL);
//	replace(X,Q,L);
//	replace(Y,Q,L);
//}
//
//void sort(DanhSach *pL)
//{
//	Position P=first(*pL), E=endList(*pL);
//	Position Q;
//	while (P!=E)
//	{
//		Q=next(P,*pL);
//		while(Q!=E)
//		{
//			if(retrieve(P,*pL).MSSV>retrieve(Q,*pL).MSSV)
////				swap(P,Q,pL);
//			{
//				struct SinhVien t;
//				t=pL->A[P-1];
//				pL->A[P-1]=pL->A[Q-1];
//				pL->A[Q-1]=t;
//			}
//			Q=next(Q,*pL);
//		}
//		P=next(P,*pL);
//	}
//}














