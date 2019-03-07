#include <stdio.h>
#include <conio.h>
#define max 30
// Hang Doi bang chuyen tinh tuyên
typedef struct{
	int data[max];
	int front,rear;
}queue;
void makenull(queue &q){
	q.front=-1;
	q.rear=-1;
}
int empty(queue q){
	return q.front==-1;
}
int full(queue q){
	return (q.rear-q.front+1)==max;
}
void endqueue(int x,queue &q){
	if(!full(q)){
		if(empty(q))
		q.front=0;
		if(q.rear==max-1){
			for(int i=0;i<=q.rear;i++){
				q.data[i-q.front]=q.data[i];
			}q.rear=max-1-q.front;q.front=0;
		}
		q.rear++;
		q.data[q.rear]=x;
	}else printf("hang day");
}
void nhap(queue &q){
	makenull(q);
	int n,k;
	printf("nhap so ptu\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("nhap tu thu %d ",i);scanf("%d",&k);
		endqueue(k,q);
	}
}
void dequeue(queue &q){
	if(!empty(q)){
		q.front++;
		if(q.front>q.rear)
		makenull(q);
	}else printf("loi hang rong\n");
}
void in(queue &q){
	for(;!empty(q);){
		printf("%d ",q.data[q.front]);
		dequeue(q);
	}printf("\n");
}
int main(){
	queue q;
	nhap(q);
	in(q);
}
