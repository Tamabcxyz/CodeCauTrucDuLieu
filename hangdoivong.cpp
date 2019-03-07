#include <stdio.h>
#include <conio.h>
#define max 30
// khai bao hang doi
typedef struct{
	int data[max];
	int Rear, Front;
}queue;
// tao hang doi rong
void makenull_queue(queue &q){
	q.Front=-1;
	q.Rear=-1;
}
// kiem tra xem hang doi co rong hay ko
int empty_queue(queue q){
	return q.Front==-1;
}
// kiem tra hang doi day
int full_queue(queue q){
	return (q.Rear-q.Front+1)%max==0;
}
// them ptu vao hang doi (chi co the them vao cuoi)
void add_queue(queue &q, int x){
	if(!full_queue(q)){
		if(empty_queue(q)){
			q.Front=0;
		}
		q.Rear=(q.Rear+1)%max;
		q.data[q.Rear]=x;
	}else printf("day\n");
}
void delete_queue(queue &q){
	if(!empty_queue(q)){
		if(q.Rear==q.Front)makenull_queue(q);
		else q.Front=(q.Front+1)%max;
	}else printf("rong\n");
}
void read(queue &q){
	int n, k;
	printf("nhap vao so luong ptu\n");
	scanf("%d",&n);
	makenull_queue(q);
	for(int i=1;i<=n;i++){
		printf("nhap ptu %d\n",i);
		scanf("%d",&k);
		add_queue(q,k);
	}
}
void in(queue &q){
	while(!empty_queue(q)){
		printf("%d  ",q.data[q.Front]);
		delete_queue(q);
	}
}
int main(){
	queue q;
	read(q);
	in(q);
}
