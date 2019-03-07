#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef struct node{
	int data;
	struct node *next;
};
typedef node* position;
typedef position list;
// tao ds rong
void makenull_list(list &header){
	header=(node*)malloc(sizeof(node));
	header->next=NULL;
}
// kiem tra ds rong
int empty_list(list L){
	return L->next==NULL;
}
// them 1ptu vao ds
void insert_list(list &L,int x, position p){
	position t;
	t=(node*)malloc(sizeof(node));
	t->data=x;
	t->next=p->next;
	p->next=t;
}
// xoa 1ptu khoi ds
void xoa(list &L, position p){
	position t;
	if(p->next!=NULL){
		t=p->next;
		p->next=t->next;
		free(t);
	}
}
// tim vi tri cua 1ptu tai vi tri
position locate(list L, int x){
	position p;int found=0;
	p=L;
	while(p->next!=NULL&&found==0){
		if(p->next->data==x)found=1;
		else p=p->next;
	}return p;
}
// tra ve gia tri cua 1ptu tai vi tri p
int retrieve(list L, position p){
	if(p->next!=NULL){
		return p->next->data;
	}
}
// vi tri ptu dau
position first(list L){
	return L;
}
// vi tri ptu cuoi
position end(list L){
	position p;
	p=first(L);
	while(p->next!=NULL){
		p=p->next;
	}return p;
}
// sap xep
void sort(list &L){
	position p,q;int temp;
	p=L->next;
	while(p!=NULL){
		q=p->next;
		while(q!=NULL){
			if(p->data>q->data){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
}
// doc ds
void read(list &L){
	int x;
	printf("nhap vao ds, nhap -1 de ket thuc nhap\n");
	makenull_list(L);
	do{
		printf("x= ");scanf("%d",&x);
		if(x!=-1)insert_list(L,x,end(L));
	}while(x!=-1);
}
// in
void in(list L){
	position p;
	p=L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
int main(){
	list L;
	position p;
	read(L);in(L);
	int x;
	printf("nhap vao so can xoa\n");
	scanf("%d",&x);
	p=locate(L,x);
	if(p->next!=NULL)xoa(L,p);in(L);
	sort(L);in(L);
}
