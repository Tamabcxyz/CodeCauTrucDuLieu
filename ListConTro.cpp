#include <stdio.h>
#include <conio.h>
typedef int element;
// tao mot danh sach lien ket don la tap hop nhieu node lk voi nhau
// ta dinh nghia struct node node luon chua 2 thanh phan la data va next con tro
struct node{
	element data;// data co kieu int
	struct node *pnext;// con tro next co kieu node
};
typedef struct node NODE;// hien tai toan bo struct node co ten la NODE
// khai bao mot struct danh sach rom co 2 con tro
struct list{
	NODE *phead;
	NODE *ptail;
};
typedef struct list List;// hien tai toan bo struct list co ten la List
// khoi tao danh sach ban dau la rong
void makenull(List &L){
	L.phead=NULL;// con tro dau cua danh sach co gia tri null
	L.ptail=NULL;// con tro cuoi bang con tro dau cung null luon
}
NODE *taoNODE(element x){
	NODE *p=new NODE;
	p->data=x;// gan cho truong data cua p =x
	p->pnext=NULL;// gan cho truong next cua p la null
	//return p;
}
// them mot NODE vao dau danh sach
void addfirst(List &L,NODE *p){
	if(L.phead==NULL){
		L.phead=L.ptail=p;// dau bang cuoi bang p
	}
	else{
		p->pnext=L.phead;
		L.phead=p;// cap nhap lai vi tri dau cua phead
	}
}
void addlast(List &L,NODE *p){
	if(L.phead==NULL){
		L.phead=L.ptail=p;
	}
	else{
		L.ptail->pnext=p;
		L.ptail=p;// cap nhap lai vi tri cuoi cua ptail
	}
}
void nhap(List &L){
	makenull(L);
	int n;
	printf("nhap vao so phan tu \n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("nhap phan tu %d ",i);
		int x;
		scanf("%d",&x);
		NODE *p=taoNODE(x);// khoi tao 1 so nguyen ne
		addlast(L,p);
	}
}
void xuat(List L){
	for(NODE *k=L.phead;k!=NULL;k=k->pnext){
		printf("%d\t",k->data);
	}
}
void sapxep(List &L){
	for(NODE *i=L.phead;i!=NULL;i=i->pnext){
		for(NODE *j=i->pnext;j!=NULL;j=j->pnext){
			if(i->data<j->data){
				int p;
				p=i->data;
				i->data=j->data;
				j->data=p;	
			}
		}
	}
}
int main(){
	List L;
	nhap(L);
	xuat(L);printf("\n");
//	sapxep(L);
//	xuat(L);
}

