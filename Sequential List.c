#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElementType;
typedef struct{
	ElementType Data[MAXSIZE];
	int Last;
}List;
/*	下标i	0	1	2	...	n-1	...	MAXSIZE-1
	项数n	a1	a2	a3	...	an
	last永远是最后一项的下标，既：last = n-1(项数减一)
	项数n小于等于MAXSIZE 
*/

//List L,*PtrL;

List *MakeEmpty() {
	List *PtrL;
	PtrL = (List*)malloc(sizeof(List));
	PtrL->Last=-1;
	return PtrL;
}

int Find(ElementType X,List *PtrL) {
	int i=0;
	while(i<=PtrL->Last && PtrL->Data[i]!=X)	i++;
	if(i>PtrL->Last)	return -1;
	else return i;
}

void Insert(ElementType X,int i,List *PtrL) {
	int j;
	if(PtrL->Last=MAXSIZE-1){
		printf("顺序表已满");
		return; 
	}
	if(i<1 || i>PtrL->Last+2){
		printf("位置不合法");
		return;
	}
	for(j=PtrL->Last;j>=i-1;j--)	PtrL->Data[j+1]=PtrL->Data[j];
	PtrL->Data[i-1]=X;
	PtrL->Last++;
	return;
}

void Delete(int i,List *PtrL) {
	int j;
	if(i<1 || i>PtrL->Last+1) {
		printf("不存在第%d个元素")
		return; 
	}
	for(j=i-1;j<=PtrL->Last-1;j++)	PtrL->Data[j]=PtrL->Data[j+1];
//	for(j=i;j<=PtrL->Last;j++)	PtrL->Data[j-1]=PtrL->Data[j];
	PtrL->Last--;
	return;
}


int main()
{
	MakeEmpty();
	return 0;
}
