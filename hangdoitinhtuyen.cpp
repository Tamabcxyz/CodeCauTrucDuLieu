#include <stdio.h>
#include <conio.h>
#define max 30
typedef struct{
	int data[max];
	int front,rear;
}queue;
// tao hang doi rong
void makenull(queue &q){
	q.front=-1;
	q.rear=-1;
}
// kiem tra no co rong hay ko
int empty(queue q){
	return q.front==-1;
}
// kiem tra hang day
int full(queue q){
	return q.rear-q.front+1==max;
}
// them vao cuoi hang doi
void endqueue(queue &q,int x){
	if(!full(q)){
		q.front=0;
		if(q.rear==max-1){
			for(int i=0;i<max;i++){
				q.data[q.rear-q.front]=q.data[i];// tinh tuyen
			}	q.rear=q.rear-q.front;q.front=0;// dinh nghia lai front rear
		}
		q.rear++;
		q.data[q.rear]=x;
	}else{
		printf("hang day\n");
	}
}
void read(queue &q){
	int n,k;
	printf ("nhap vao so ptu\n");
	scanf("%d",&n);
	makenull(q);
	for(int i=1;i<=n;i++){
		printf("nhap ptu %d ",i);
		scanf("%d",&k);
		endqueue(q,k);
	}
}
void dequeue(queue &q){
	if(!empty(q)){
		q.front++;
		if(q.front>q.rear)makenull(q);
	}else {
		printf("rong\n");
	}
}
void in(queue &q){
	for(;!empty(q);){
		printf("%d\t",q.data[q.front]);
		dequeue(q);
	}printf("\n");
}
int main(){
	queue q;
	read(q);
	in(q);
}
