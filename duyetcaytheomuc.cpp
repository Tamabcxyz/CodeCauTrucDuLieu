#include <stdio.h>
#include <conio.h>
#define MAX 30
#define NIL -1
// cai dat hang doi
typedef int elementtype;
typedef struct{
	elementtype elements[MAX];
	int front, rear;
}queue;
// khoi tao hang doi rong
void makenullqueue(queue &q){
	q.front=-1;
	q.rear=-1;	
}
// kiem tra xem hang doi co rong hay chua
int emptyqueue(queue q){
	return q.front==-1;
}
// kiem tra xem hang doi co day hay chua
int fullqueue(queue q){
	return (q.rear-q.front+1)%MAX==0;
}
// xoa bo 1 ptu khoi hang doi
void dequeue(queue &q){
	if(!emptyqueue(q)){
		if(q.front==q.rear)makenullqueue(q);
		else q.front=(q.front+1)%MAX;
	}else printf("loi hang rong\n");
}
// them 1 ptu vao hang doi
void enqueue(queue &q,int x){
	if(!fullqueue(q)){
		if(emptyqueue(q)) q.front=0;
		q.rear=(q.rear+1)%MAX;
		q.elements[q.rear]=x;	
	}else printf("hang day\n");
}
// tra ve ptu dau hang
int Front(queue q){
	if(emptyqueue(q)){
		printf("hang rong\n");
	}else return q.elements[q.front];
}
// cai dat cay
typedef char datatype;
typedef int node;
typedef struct{
	datatype Lable[MAX];
	node Parent[MAX];
	int maxnode;
}tree;
// khoi tao cay rong
void makenulltree(tree &T){
	T.maxnode=0;
}
// kiem tra cay co rong hay ko
int emptytree(tree T){
	return T.maxnode==0;
}
// xac dinh cha cua 1 nut
node parent(tree T,node n){
	if(emptytree(T)||n>T.maxnode-1)return NIL;
	else return T.Parent[n];
}
// tra ve nhan cua 1 nut
node lable(tree T,node n){
	if(!emptytree(T)||n<MAX)return T.Lable[n];
	else return NIL;
}
// xac dinh nut goc cua cay
node root(tree T){
	if(!emptytree(T))return 0;
	else return NIL;
}
// xac dinh con trai nha
node leftmostchild(tree T,node n){
	int i=n+1;int find=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&find==0){
		if(T.Parent[i]==n)find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;	
}
// xac dinh ae ruot phai
node rightsibling(tree T,node n){
	int i=n+1; int find=0;
	if(n<0)return NIL;
	while(i<T.maxnode&&find==0){
		if(T.Parent[i]==T.Parent[n])find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;
}
// duyet cay theo muc
void levelorder(tree T,node n){
	queue q;int i;
	makenullqueue(q);
	i=n;
	if(i!=NIL)enqueue(q,i);
	while(!emptyqueue(q)){
		// in ra nut i
		i=Front(q);
		printf("%c",lable(T,i));
		dequeue(q);
		// dua cac con cua nut i tu trai sang phai vao hang doi
		i=leftmostchild(T,i);
		while(i!=NIL){
			enqueue(q,i);
			i=rightsibling(T,i);
		}
	}
}
// nhap vao cay
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
queue q;tree T;	
read(T);
printf("\nduyet cay theo muc\n");
levelorder(T,root(T));
}
