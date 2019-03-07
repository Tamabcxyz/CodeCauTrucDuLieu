#include <stdio.h>
#include <conio.h>
#define max 30
#define NIL -1
// cai dat hang doi
typedef struct{
	int data[max];
	int Front, Rear;
}queue;
// tao hang doi rong
void makenull_queue(queue &q){
	q.Front=-1;
	q.Rear=-1;
}
// kiem tra rong
int empty_queue(queue q){
	return q.Front==-1;
}
// kiem tra hang day
int full_queue(queue q){
	return (q.Rear-q.Front+1)%max==0;
}
// xoa 1 ptu khoi hang doi
void delete_queue(queue &q){
	if(!empty_queue(q)){
		if(q.Front==q.Rear)makenull_queue(q);
		else q.Front=(q.Front+1)%max;
	}else printf("hang doi rong\n");
}
// them phan tu vao hang doi(chi co the them vao cuoi)
void insert_queue(queue &q,int x){
	if(!full_queue(q)){
		if(empty_queue(q))q.Front=0;
		q.Rear=(q.Rear+1)%max;
		q.data[q.Rear]=x;
	}else printf("hang doi day\n");
}
// tra ve noi dung cua ptu dau hang
int datafirst(queue q){
	if(empty_queue(q))printf("hang rong\n");
	else return q.data[q.Front];
}
// khai bao cay
typedef char datatype;
typedef int node;
typedef struct{
	datatype data[max];
	node Parent[max];
	int maxnode;
}tree;
// tao cay rong
void makenull_tree(tree &T){
	T.maxnode=0;
}
// kiem tra cay rong
int empty_tree(tree T){
	return T.maxnode==0;
}
// xac dinh cha cua 1 nut
int Parentnode(tree T, int n){
	if(n>T.maxnode-1||empty_tree(T)) return NIL;
	else return T.Parent[n];
}
// xac dinh nhan cua 1 nut
int Lablenode(tree T, int n){
	if(n<max||!empty_tree(T))return T.data[n];
	else return NIL;
}
// xac dinh nut goc cua cay
int root(tree T){
	if(!empty_tree(T))return 0;
	else return NIL;
}
// xac dinh con trai nhat
int leftmostchild(tree T,int n){
	int i=n+1; int found=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&found==0){
		if(T.Parent[i]==n)found=1;
		else i++;
	}if(found==1)return i;
	else return NIL;
}
// ae ruot phai
int rightsibling(tree T, int n){
	int i=n+1; int found=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&found==0){
		if(T.Parent[i]==T.Parent[n])found=1;
		else i++;
	}if(found==1)return i;
	else return NIL;
}
// duyet cay theo muc
void level(tree T, int n){
	queue q; int i;
	makenull_queue(q);
	i=n;
	if(i!=NIL)insert_queue(q,i);
	while(!empty_queue(q)){
		i=datafirst(q);
		printf("%c",Lablenode(T,i));
		delete_queue(q);
		i=leftmostchild(T,i);
		while(i!=NIL){
			insert_queue(q,i);
			i=rightsibling(T,i);
		}
	}
}

// nhap vao cay
void read(tree &T){
	int i;
	makenull_tree(T);
	printf("nhap vao so nut cua cay\n");fflush(stdin);
	scanf("%d",&T.maxnode);
	printf("nhap vao nhan cua nut goc\n");fflush(stdin);
	scanf("%c",&T.data[0]);
	printf("nhap cac nut con lai\n");
	for(int i=1;i<T.maxnode;i++){
		printf("nhap cha cua nut %d ",i);fflush(stdin);
		scanf("%d",&T.Parent[i]);
		printf("nhap vao nhan cua nut %d ",i);fflush(stdin);
		scanf("%c",&T.data[i]);
	}
}
int main(){
	queue q;tree T;	
	read(T);
	printf("\nduyet cay theo muc\n");
	level(T,root(T));
}

