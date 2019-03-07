/*
//============DANH SACH===============//
#include <stdio.h>
#include <conio.h>
#define max 30
typedef int element;
typedef int position;
typedef struct{
	element data[max];
	position last;
}list;
// tao rong
void makenull(list &L){
	L.last=0;
}
// kiem tra rong
position empty(list L){
	return L.last==0;
}
// kiem tra day
position full(list L){
	return L.last==max;
}
// vi tri dau tien
position first(list L){
	return 1;
}
// vi tri cuoi
position end(list L){
	return L.last+1;
}
// noi dung cua phan tu tai vi tri p
position retrieve(list L,position p){
	return L.data[p-1];
}
// vi tri ke tiep cua vi tri p
position next(list L,position p){
	return p+1;
}
// vi tri sau vi tri p
position revious(list L,position p){
	return p-1;
}
// vi tri cua phtu chua noi dung x
position locate(list L,element x){
	int find=0;
	position p=first(L);
	while(p!=end(L)&&find==0){
		if(retrieve(L,p)==x){
			find=1;
		}else{
			p=next(L,p);
		}
	}return p;
	
}
// chen phan tu vao ds
//void insert(list &L,element x,position p){
//	if(!full(L)){
//		if(p<0||p>max){
//			printf("sai vi tri\n");
//		}else{
//			for(position i=L.last;i>=p;i=revious(L,i)){
//				L.data[i]=L.data[i-1];
//			}L.last++;L.data[p-1]=x;
//		}
//	}else{
//		printf("ds day\n");
//	}
//}
void insert(list &L,element x,position p){
	if(full(L)){
		printf("danh sach day\n");
	}
	else{
		if(p<0||p>max){
			printf("sai vi tri\n");
		}
		else{
			for(position i=L.last;i>=p;i--){
				L.data[i]=L.data[i-1];
			}L.last++;L.data[p-1]=x;
		}
	}

}
// doc ds
void read(list &L){
	element n,k;
	printf("nhap so luong ptu\n");
	scanf("%d",&n);
	makenull(L);
	for(position i=1;i<=n;i=next(L,i)){
		printf("nhap vao ptu thu %d ",i);
		scanf("%d",&k);
		insert(L,k,i);
	}
}
// in ds
void in(list &L){
	for(position i=1;i<=L.last;i=next(L,i)){
		printf("%d\t",retrieve(L,i));
	}
}
// xoa 1 ptu trong ds
void xoa(list &L,position p){
	for(position i=p;i<=L.last;i=next(L,i)){
		L.data[i-1]=L.data[i];
	}L.last--;
}
// sap xep ds tang dan
void sapxep(list &L){
	for(position i=1;i<=L.last;i=next(L,i)){
		for(position j=next(L,i);j<=L.last;j=next(L,j)){
			if(retrieve(L,i)>retrieve(L,j)){
				element temp=0;
				temp=L.data[i-1];
				L.data[i-1]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
}
// xoa tat ca ptu trung giu lai 1
void xoatrung(list &L){
	for(position i=1;i<=L.last;i=next(L,i)){
		for(position j=next(L,i);j<=L.last;j=next(L,j)){
			if(retrieve(L,i)==retrieve(L,j)){
				xoa(L,j);
				j--;
			}
		}
	}
}
// chen 1 ptu vao dam bao mang van tang
void chentang(list &L,element x){
	if(!full(L)){
		for(position i=1;i<L.last;i=next(L,i)){
			if(L.data[i]>x){
				for(position j=L.last;j>i;j=revious(L,j)){
					L.data[j]=L.data[j-1];
				}L.last++;L.data[i]=x;break;
			}
		}
	}else{
		printf("danh sach day\n");
	}
}
// nhap vao ptu tu dong tim chen sao cho dung thu tu tang
void insert_order(list &L,element x){
	position p=1;
	while(p!=end(L)&&retrieve(L,p)<x){
		p=next(L,p);
	}insert(L,x,p);
}
// ham nhap cua insert_order
void readtimxen(list &L){
	element x=0;
	printf("nhap vao ptu va nhap -1 de dung\n");
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)
		insert_order(L,x);
	}while(x!=-1);
}
// tim xen co thu tu va ko trung nhau
void timxenkotrung(list &L,element x){
	position p=first(L);
	if(locate(L,x)==end(L)){
		while(p!=end(L)&&retrieve(L,p)<x){
			p=next(L,p);
		}insert(L,x,p);
	}
}
void readtimxenkotrung(list &L){
	element x=0;
	printf("nhap vao ptu va nhap -1 de dung\n");
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)
		timxenkotrung(L,x);
	}while(x!=-1);
}
// gop 2 ds co thu tu tang vao ds thu 3 cung co thu tu tang
void gopcothutu(list l1,list l2,list &l3){
	position p1=first(l1);
	position p2=first(l2);
	makenull(l3);
	while(p1!=end(l1)&&p2!=end(l2)){
		if(retrieve(l1,p1)<=retrieve(l2,p2)){
			insert(l3,retrieve(l1,p1),end(l3));
			p1=next(l1,p1);
		}
		else{
			insert(l3,retrieve(l2,p2),end(l3));
			p2=next(l2,p2);
		}
	}
	while(p1!=end(l1)){
		insert(l3,retrieve(l1,p1),end(l3));
		p1=next(l1,p1);
	}
	while(p2!=end(l2)){
		insert(l3,retrieve(l2,p2),end(l3));
		p2=next(l2,p2);
	}
}
//===========bai 10 xoa cac ptu la so le ra khoi ds
void xoale(list &L){
	for(position i=first(L);i<=L.last;i=next(L,i)){
		if(L.data[i-1]%2!=0){
			xoa(L,i);
		}else{
			i=next(L,i);
		}
	}
}
//===============bai 11==============
void phanloaichanle(list L1,list &L2,list &L3){
	position p=first(L1);
	makenull(L2);
	makenull(L3);
	while(p!=end(L1)){
		if(retrieve(L1,p)%2==0){
			insert(L2,retrieve(L1,p),end(L2));
		}
		else{
			insert(L3,retrieve(L1,p),end(L3));
		}
		p=next(L1,p);
	}
}
int main(){
	//list L;
	//read(L);
	//in(L);printf("\n");
	//sapxep(L);
	//in(L);
	//readtimxenkotrung(L);printf("\n");
	//in(L);
	//========bai 9===========
//	list l1,l2,l3;
//	printf("nhap vao ds 1\n");
//	read(l1);
//	sapxep(l1);
//	in(l1);
//	printf("\nnhap vao ds l2\n");
//	read(l2);
//	sapxep(l2);
//	in(l2);printf("\n");
//	gopcothutu(l1,l2,l3);
//	in(l3);
	//==========bai 10 xoa cac ptu la so le ra khoi ds
//	list L;
//	read(L);
//	in(L);
//	xoale(L);
//	printf("\n");
//	in(L);
	//=========bai 11==========
//	list L1,L2,L3;
//	printf("nhap vao danh sach 1\n");
//	read(L1);
//	in(L1);
//	printf("\nsau khi tach danh sach ta dc\n");
//	phanloaichanle(L1,L2,L3);
//	printf("\n***********\n");
//	in(L2);
//	printf("\n***********\n");
//	in(L3);
}
*/
/*
//===============NGAN XEP===============
#include <stdio.h>
#include <conio.h>
#define max 30
typedef struct{
	int data[max];
	int top;
}stack;
// tao ngan xep rong
void makenull(stack *s){
	s->top=max;
}
// kiem tra ngan xep rong
int empty(stack s){
	return s.top==max;
}
// kiem tra ngan xep day
int full(stack s){
	return s.top==0;
}
// noi dung ptu tai top
int retrieve(stack *s){
	return s->data[s->top];
}
// them ptu vao ds
void push(stack *s,int x){
	if(!full(*s)){
		s->top=(s->top)-1;
		s->data[s->top]=x;
	}else{
		printf("day\n");
	}
}
// xoa ptu ra khoi ngan xep
void pop(stack *s){
	if(!empty(*s)){
		s->top=(s->top+1);
	}else{
		printf("rong\n");
	}
}
void read(stack &s){
	printf("nhap vao sl ptu cua ngan xep\n");
	int n,k;
	scanf("%d",&n);
	makenull(&s);
	for(int i=0;i<n;i++){
		printf("ptu %d ",i+1);
		scanf("%d",&k);
		push(&s,k);
	}
}
void in(stack &s){
	for(;!empty(s);){
		printf("%d\t",retrieve(&s));
		pop(&s);
	}
}
int main(){
	stack s;
	read(s);
	in(s);
}
*/
/*
//=============HANG DOI(pp tinh tuyen)==============
#include <stdio.h>
#include <conio.h>
#define max 30
typedef struct{
	int data[max];
	int front, rear;
}queue;
// tao hang doi rong
void makenull(queue &q){
	q.front=-1;
	q.rear=-1;
}
// kiem tra hang co rong 2 ko
int empty(queue q){
	return q.rear==-1;
}
// kiem tra hang co day chua
int full(queue q){
	return (q.rear-q.front)+1==max;
}
// them ptu vao hang
void insert(queue &q,int x){
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
// doc 
void read(queue &q){
	int n,k;
	printf ("nhap vao so ptu\n");
	scanf("%d",&n);
	makenull(q);
	for(int i=1;i<=n;i++){
		printf("nhap ptu %d ",i);
		scanf("%d",&k);
		insert(q,k);
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
	}
}
int main(){
	queue q;
	read(q);
	in(q);
}
*/
//============HANG DOI(pp vong)=================
#include <stdio.h>
#include <conio.h>
#define max 30
typedef struct{
	int data[max];
	int front, rear;
}queue;
// tao hang doi rong
void makenull(queue &q){
	q.front=-1;
	q.rear=-1;
}
// kiem tra hang co rong 2 ko
int empty(queue q){
	return q.rear==-1;
}
// kiem tra hang co day chua
int full(queue q){
	return ((q.rear-q.front)+1)%max==0;
}
// them ptu vao hang
void insert(queue &q,int x){
	if(!full(q)){
		if(empty(q)) q.front=0;
		q.rear=(q.rear+1)%max;
		q.data[q.rear]=x;
	}else{
		printf("hang day\n");
	}
}
// doc 
void read(queue &q){
	int n,k;
	printf ("nhap vao so ptu\n");
	scanf("%d",&n);
	makenull(q);
	for(int i=1;i<=n;i++){
		printf("nhap ptu %d ",i);
		scanf("%d",&k);
		insert(q,k);
	}
}
void dequeue(queue &q){
	if(!empty(q)){
		if(q.front==q.rear){
			makenull(q);
		}else{
			q.front=q.front+1;
		}
	}else {
		printf("rong\n");
	}
}
void in(queue &q){
	for(;!empty(q);){
		printf("%d\t",q.data[q.front]);
		dequeue(q);
	}
}
int main(){
	queue q;
	read(q);
	in(q);
}







