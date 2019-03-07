#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef int element;
typedef struct node{
	int data;
	struct node *next;
};
typedef node *position;
typedef position list;
// tao rong
void makenull(list &header){
	header=(node*)malloc(sizeof(node));
	header->next=NULL;
}
// kiem tra rong
int empty(list L){
	return (L->next==NULL);
}
// xen 1 ptu vao
void insert(list &L,int x,position p){
	position t;
	t=(node*)malloc(sizeof(node));
	t->data=x;
	t->next=p->next;
	p->next=t;
}
// tra ve gia tri cua phan tu p
int retrieve(list L,position p){
	if(p->next!=NULL){
		return p->next->data;//
	}	
}
// tra ve vi tri dau tien
position first(list L){
	return L;
}
// vi tri phan tu cuoi
position end(list L){
	position p;
	p=first(L);
	while(p->next!=NULL){
		p=p->next;
	}
	return p;
}
// vi tri cua ptu co noi dung x
position locate(list L,element x){
	position p=L;
	int find=0;
	while(p->next!=NULL&&find==0){
		if(p->next->data==x)find=1;
		else p=p->next;
	}
	return p;
}
// sap xep
void sapxep(list &L){
	position i=L->next;
	while(i->next!=NULL){
		position j=i->next;
		while(j->next!=NULL){
			if(i->data>j->data){
				int temp=0;
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
			j=j->next;
		}
		i=i->next;
	}	
}
// doc
void read(list &L){
	int x;
	printf("nhap vao ptu,nhap -1 de ket thuc nhap\n");
	makenull(L);// loi sai nghiem trong trong lich su loai nguoi
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)insert(L,x,end(L));
	}while(x!=-1);
}
// in
void in(list &L){
	position p=L->next;
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->next;
	}
}
// chen them 1ptu vao sao cho van dam bao tang
void chentang(list &L,int x){
	position p=L;
	while(p->next!=NULL&&p->next->data<x){
		p=p->next;
	}insert(L,x,p);
}
void xoa(list &L,position p){
	position t;
	if(p->next!=NULL){
		t=p->next;
		t->next=p->next;
		free(t);	
	}
}
// dinh vi va chen vao sao cho co thu tu tang
void timxencothutu(list &L,int x){
	position p=L;
	while(p->next!=NULL&&p->next->data<x){
		p=p->next;
	}insert(L,x,p);
}
void doccothutu(list &L){
	int x;
	printf("nhap -1 de ket thuc\n");
	makenull(L);
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)timxencothutu(L,x);	
	}while(x!=-1);
}
void xoatrung(list &L){
	position p=L;
	while(p->next!=NULL){
		position q=p->next;
		while(q->next!=NULL){
			if(retrieve(L,p)==retrieve(L,q)){
				xoa(L,q);
			}
			q=q->next;
		}
		p=p->next;
	}
}
// tim va xen vao ptu dc ko phep trung va ds tang
void timxenkotrungcothutu(list &L,element x){
	position p=L;
	if(locate(L,x)==end(L)){
		while(p->next!=NULL&&p->next->data<x){
			p=p->next;
		}insert(L,x,p);
	}
}
// ham doc cua timxenkotrungcothutu
void readtimxenkotrungcothutu(list &L){
	printf("nhap vao so va nhap  -1 de dung\n");
	makenull(L);
	int x;
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)timxenkotrungcothutu(L,x);
	}while(x!=-1);
}
int main(){
	list L;
//	read(L);
//	in(L);
	readtimxenkotrungcothutu(L);printf("\nds la\n");in(L);
	
 	
}
