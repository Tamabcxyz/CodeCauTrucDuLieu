#include <stdio.h>
#include <conio.h>
#define Max 30
#define NIL -1
// hang doi
typedef struct{
	int data[Max];
	int front,rear;
}queue;
void makenullqueue(queue &q){
	q.front=-1;
	q.rear=-1;
}
int emptyqueue(queue q){
	return q.front==-1;
}
int fullqueue(queue q){
	return ((q.rear-q.rear)+1)%Max==0;
}
void insertqueue(queue &q, int x){
	if(!fullqueue(q)){
		if(emptyqueue(q)) q.front=0;
		q.rear=(q.rear+1)%Max;
		q.data[q.rear]=x;
	}else printf("hang day\n");
}
void xoa(queue &q){
	if(!emptyqueue(q)){
		q.front=(q.front+1)%Max;
		if(q.front==q.rear)makenullqueue(q);
	}else printf("hang rong\n");
}
int Front(queue q){
	if(!emptyqueue(q))return q.data[q.front];
	else return NIL;
}
// cai dat cay
typedef char datatype;
typedef int node;
typedef struct{
	datatype Lable[Max];
	node Parent[Max];
	int maxnode;
}tree;
void makenulltree(tree &T){
	T.maxnode=0;
}
int emptytree(tree T){
	return T.maxnode==0;
}
node parent(tree T,node n){
	if(emptytree(T)||n>T.maxnode-1)return NIL;
	else return T.Parent[n];
}
node lable(tree T,node n){
	if(!emptytree(T)||n<Max)return T.Lable[n];
	else return NIL;
}
node root(tree T){
	if(!emptytree(T))return 0;
	else return NIL;
}
node leftmostchild(tree T,node n){
	int i=n+1;int find=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&find==0){
		if(T.Parent[i]==n)find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;	
}
node rightsibling(tree T,node n){
	int i=n+1; int find=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&find==0){
		if(T.Parent[i]==T.Parent[n])find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;
}
void levelorder(tree T,node n){
	queue q;int i;
	makenullqueue(q);
	i=n;
	if(i!=NIL)insertqueue(q,i);
	while(!emptyqueue(q)){
		// in ra nut i
		i=Front(q);
		printf("%c  ",lable(T,i));
		xoa(q);
		// dua cac con cut nut i tu trai sang phai vao hang doi
		i=leftmostchild(T,i);
		while(i!=NIL){
			insertqueue(q,i);
			i=rightsibling(T,i);
		}
	}
}
void read(tree &T){
	int i;
	makenulltree(T);
	printf("nhap vao so nut cua cay\n");fflush(stdin);
	scanf("%d",&T.maxnode);
	printf("nhap vao nhan cua nut goc\n");fflush(stdin);
	scanf("%c",&T.Lable[0]);
	printf("nhap cac nut con lai\n");
	for(int i=1;i<T.maxnode;i++){
		printf("nhap cha cua nut %d ",i);fflush(stdin);
		scanf("%d",&T.Parent[i]);
		printf("nhap vao nhan cua nut %d ",i);fflush(stdin);
		scanf("%c",&T.Lable[i]);
	}
}
int main(){
	tree T;
	read(T);
	printf("duyet cay theo muc\n");
	levelorder(T,root(T));
}
