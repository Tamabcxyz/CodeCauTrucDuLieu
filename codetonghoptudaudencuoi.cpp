//=========CAI DAT DANH SACH CHUA SO NGUYEN========
#include <stdio.h>
#include <conio.h>
#define MAX 30
typedef int datatype;
typedef int position;
typedef struct{
	datatype data[MAX];
	position last;
}list;
// tao ds rong
void makenull(list &L){
	L.last=0;
}
// kiem tra rong
datatype empty(list L){
	return L.last==0;
}
// kiem tra ds day
datatype full(list L){
	return L.last==MAX;
}
// vi tri dau
position first(list L){
	return 1;
}
// vi tri cuoi
position end(list L){
	return L.last+1;
}
// noi dung ptu tai vi tri p
datatype retrieve(list L, position p){
	return L.data[p-1];
}
// vi tri ke tiep
position next(list L,position p){
	return p+1;
}
// vi tri sau
position revious(list L,position p){
	return p-1;
}
// ham xac dinh vi tri cua phtu x
position locate(list L,datatype x){
	position p=first(L);
	int find=0;
	while(p!=end(L)&&find==0){
		if(retrieve(L,p)==x)find=1;
		else p=next(L,p);
	}return p;
}
// chen ptu vao ds
void insert(list &L,datatype x,position p){
	if(full(L))printf("ds day\n");
	else{
		if(p<1||p>MAX)printf("sai vi tri\n");
		else{
			for(position i=L.last;i>=p;i--){
				L.data[i]=L.data[i-1];
			}L.last++;L.data[p-1]=x;
		}
	}
}
// doc ds
void read(list &L){
	printf("nhap vao so ptu\n");
	int n,k;
	scanf("%d",&n);
	makenull(L);
	for(position i=1;i<=n;i=next(L,i)){
		printf("ptu thu %d ",i);
		scanf("%d",&k);
		insert(L,k,i);
	}
}
// in ds
void in(list L){
	for(position i=0;i<L.last;i=next(L,i)){
		printf("%d  ",L.data[i]);
	}
}
// xoa 1 ptu tai vi tri p trong ds
void xoa(list &L,position p){
	if(empty(L))printf("ds rong\n");
	else{
		if(p<1||p>=L.last)printf("sai vi tri\n");
		else{
			for(position i=p;i<L.last;i=next(L,i)){
				L.data[i]=L.data[i+1];
			}L.last--;
		}
	}
}
// xapsep
void sort(list &L){
	for(position i=first(L);i<=end(L);i=next(L,i)){
		for(position j=next(L,i);j<=L.last;j=next(L,j)){
			if(retrieve(L,i)>retrieve(L,j)){
				int temp=0;
				temp=L.data[i-1];
				L.data[i-1]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
}
// chen tang
void chentang(list &L,datatype x){
	if(full(L))printf("ds day\n");
	else{
	for(position i=1;i<=L.last;i=next(L,i)){
		if(L.data[i-1]>x){
			for(position j=L.last;j>=i;j=revious(L,j)){
				L.data[j]=L.data[j-1];
			}L.last++;L.data[i-1]=x;break;
		}
	}
}
}
// tim kiem va xoa 1 ptu trong ds
void timxoa(list &L,datatype x){
	for(position i=first(L);i<L.last;i=next(L,i)){
		if(L.data[i]==x){
			xoa(L,i);
		}
	}
}
void xoatrung(list &L){
	for(position i=first(L);i<L.last;i=next(L,i)){
		for(position j=next(L,i);j<L.last;j=next(L,j)){
			if(L.data[i]==L.data[j]){
				xoa(L,j);
				j--;
			}
		}
	}
}
// tim chen sau cho co thu tu
void timxencothutu(list &L,datatype x){
	position p=first(L);
	while(p!=end(L)&&retrieve(L,p)<x){
		p=next(L,p);
	}	insert(L,x,p);
}
// ham nhap cua tim chen co thu tu
void readtimxencothutu(list &L){
	printf("\nnhap -1 de ket thu\n");
	int x;
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)timxencothutu(L,x);
	}while(x!=-1);
}
// xem co x trong ds chua neu chua tim cho chen vao neu roi thi ko chen ta phai viet ham tim vi tri cua x truoc 
void xencodk(list &L,datatype x){
	position p=first(L);
	if(locate(L,x)==end(L)){
		while(p!=end(L)&&retrieve(L,p)<x){
			p=next(L,p);
		}insert(L,x,p);
	}
}
void doc(list &L){
	printf("nhap -1 de ket thuc\n");
	int x;
	makenull(L);
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)xencodk(L,x);
	}while(x!=-1);
}
void inluon(list L){
	for(position i=0;i<L.last;i++){
		printf("%d ",L.data[i]);
	}
}
// tron 2 ds tang sao cho kq van tang
void trontang(list l1,list l2,list &l3){
	position p1=first(l1);
	position p2=first(l2);
	makenull(l3);
	while(p1!=end(l1)&&p2!=end(l2)){
		if(retrieve(l1,p1)<retrieve(l2,p2)){
			insert(l3,retrieve(l1,p1),end(l3));
			p1=next(l1,p1);
		}else{
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
int main(){
	list L;
	read(L);printf("ds vua nhap la\n");
	in(L);
	xoa(L,4);printf("\nds sau khi xoa la\n");
	in(L);
	sort(L);printf("\nds sau khi sap xep\n");
	in(L);
	chentang(L,5);printf("\nsau khi chen tang\n");
	in(L);
//	timxoa(L,5);printf("sau khi tim xoa ta dc\n");
//	in(L);
//	doc(L);inluon(L);
//	xoatrung(L);printf("\nds sau khi xoa trung la\n");
//	inluon(L);
//	doc(L);printf("\nds tim xen co thu tu la\n");
//	inluon(L);
 //tron 2 ds tang sao cho van tang
//	list l1,l2,l3;
//	printf("nhap l1\n");
//	read(l1);printf("\nds sau sap xep la\n");sort(l1);
//	in(l1);
//	printf("\nnhap l2\n");
//	read(l2);printf("\nds sau sap xep la\n");sort(l2);
//	in(l2);
//	trontang(l1,l2,l3);printf("\nsau khi chon ds la\n");
//	in(l3);
}
//========tao mot ds lien ket==========
//#include <stdio.h>
//#include <conio.h>
//#include <malloc.h>
//typedef struct node{
//	int data;
//	struct node *next;
//};
//typedef node *position;
//typedef position list;
//// tao ds rong
//void makenull(list &header){
//	header=(node*)malloc(sizeof(node));
//	header->next=NULL;
//}
//// kiem tra rong
//int empty(list L){
//	return L->next==NULL;
//}
//// tra ve vi tri cua ptu dau
//position first(list L){
//	return L;
//}
//// tra ve vi tri cua ptu cuoi
//position end(list L){
//	position p=first(L);
//	while(p->next!=NULL){
//		p=p->next;
//	}return p;
//}
//// noi dung ptu tai vi tri p
//int retrieve(list L,position p){
//	
//	if(p->next!=NULL){
//		return p->next->data;
//	}
//}
//// chen 1 ptu vao ds
//void insert(list &L, int x, position p){
//	position t=(node*)malloc(sizeof(node));
//	t->data=x;
//	t->next=p->next;
//	p->next=t;
//}
//// doc ds
//void read(list &L){
//	printf("nhap -1 de ket thuc\n");
//	int x;
//	makenull(L);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=-1)insert(L,x,end(L));
//	}while(x!=-1);
//}
//void in(list &L){
//	position p=L->next;
//	while(p!=NULL){
//		printf("%d  ",p->data);
//		p=p->next;
//	}
//}
//// xoa ptu co vi tri p ra khoi ds nhung ham nay ko the goi truc tiep vi position la kieu con tro
//void xoa(list &L,position p){
//	position t;
//	if(p->next!=NULL){
//		t=p->next;
//		p->next=t->next;
//		free(t);
//	}
//}
//void xoa1ptu(list &L,int x){
//	position p=L;
//	while(p->next!=NULL&&p->next->data<x){
//		p=p->next;
//	}
//	if(p->next!=NULL&&p->next->data==x){
//		xoa(L,p);
//	}
//}
//// sap xep
//void sort(list &L){
//	position p=L->next;
//	while(p!=NULL){
//		position q=p->next;
//		while(q!=NULL){
//			if(p->data>q->data){
//				int temp=0;
//				temp=p->data;
//				p->data=q->data;
//				q->data=temp;
//			}
//			q=q->next;
//		}
//		p=p->next;
//	}
//}
//// truong trinh xoa bo cac so nguyen le ra khoi ds
//void xoasole(list &L){
//	position p=L;
//	while(p->next!=end(L)){
//		if((p->next->data)%2!=0){
//			xoa(L,p);
//		}else p=p->next;
//	}
//}
//// nhap vao so nguyen va tim cho xen vao sao cho day tang
//void xencothutu(list &L,int x){
//	position p=L;
//	while(p->next!=NULL&&p->next->data<x){
//		p=p->next;
//	}insert(L,x,p);
//}
//void doc(list &L){
//	printf("nhap -1 de ket thuc\n");
//	int x;
//	makenull(L);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=-1)xencothutu(L,x);
//	}while(x!=-1);
//}
//// xoa cac ptu trung chi giu lai 1
//void xoatrung(list &L){
//	position p=L;
//	while(p->next!=NULL){
//		position q=p->next;
//		while(q->next!=NULL){
//			if(p->next->data==q->next->data){
//				xoa(L,q);
//			}
//			else q=q->next;
//		}
//		p=p->next;
//	}
//}
//// nhap vao so tim xen co thu tu va ko trung nhau
//// ta phai viet ham tim vi tri cua 1ptu truoc
//position locate(list L,int x){
//	position p=L;int find=0;
//	while(p->next!=NULL&& find==0){
//		if(p->next->data==x)find=1;
//		else p=p->next;
//	}return p;
//}
//void xencothutukotrung(list &L,int x){
//	if(locate(L,x)==end(L)){
//		position p=L;
//		while(p->next!=NULL&&p->next->data<x){
//			p=p->next;
//		}insert(L,x,p);
//	}
//}
//void doc1(list &L){
//	printf("nhap -1 de ket thuc\n");
//	int x;
//	makenull(L);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=-1)xencothutukotrung(L,x);
//	}while(x!=-1);
//}
//// tron 2 ds
//void tron2ds(list l1,list l2,list &l3){
//	position p1=l1->next;
//	position p2=l2->next;
//	makenull(l3);
//	while(p1!=NULL&&p2!=NULL){
//		if(p1->data<p2->data){
//			insert(l3,p1->data,end(l3));
//			p1=p1->next;
//		}else{
//			insert(l3,p2->data,end(l3));
//			p2=p2->next;
//		}
//	}
//	while(p1!=NULL){
//		insert(l3,p1->data,end(l3));
//		p1=p1->next;
//	}
//	while(p2!=NULL){
//		insert(l3,p2->data,end(l3));
//		p2=p2->next;
//	}
//}
//// tach ds thanh 2 ds 1 chua so chan 1 chua so le
//void tachchanle(list l1,list &l2,list &l3){
//	position p1=l1;
//	makenull(l2);makenull(l3);
//	while(p1->next!=end(l1)){
//		if((p1->next->data)%2==0){
//			insert(l2,p1->next->data,end(l2));
//		}else{
//			insert(l3,p1->next->data,end(l3));
//		}
//		p1=p1->next;
//	}
//}
//int main(){
//	list L;
//	read(L);xoasole(L);
//	in(L);
//	xoa1ptu(L,2);printf("\nds sau xoa la\n");in(L);
//	sort(L);printf("\nds sau sap xep la\n");in(L);
//	doc(L);printf("\nnhap vao tim chen co thu tu\n");
//	in(L);
//	xoatrung(L);printf("\nxoa trung\n");in(L);
//	doc1(L);printf("\nxen co thu tu ko trung\n");in(L);
//	list l1,l2,l3;
//	printf("nhap vao l1\n");
//	read(l1);sort(l1);in(l1);
//	printf("\nnhap vao l2\n");
//	read(l2);sort(l2);in(l2);
//	tron2ds(l1,l2,l3);printf("\nsau khi tron ds la\n");in(l3);
//	list l1,l2,l3;
//	read(l1);printf("ds vua nhap la \n");in(l1);
//	tachchanle(l1,l2,l3);
//	printf("\nds l1\n");in(l2);
//	printf("\nds l2\n");in(l3);
//}
//==========TAO NGAN XEP============
//#include <stdio.h>
//#include <conio.h>
//#define MAX 30
//typedef struct{
//	int data[MAX];
//	int top;
//}stack;
//// tao rong
//void makenull(stack *s){
//	s->top=MAX;
//}
//// kiem tra ngan xep rong
//int empty(stack s){
//	return s.top==MAX;
//}
//// kiem tra ngan xep day
//int full(stack s){
//	return s.top==0;
//}
//// lay noi dung ptu tai dinh ngan xep
//int retrieve(stack *s){
//	if(!empty(*s)){
//		return s->data[s->top];
//	}else printf("stack rong\n");
//}
//// them ptu vao ngan xep
//void push(stack *s, int x){
//	if(full(*s))printf("stack day\n");
//	else{
//		s->top=(s->top)-1;
//		s->data[s->top]=x;
//	}
//}
//// xoa ptu ra khoi ds
//void pop(stack *s){
//	if(!empty(*s)){
//		s->top=s->top+1;
//	}else printf("stack rong\n");
//}
//// nhap stack
//void read(stack &s){
//	printf("nhap -1 de ket thuc\n");
//	int x;
//	makenull(&s);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=-1)push(&s,x);
//	}while(x!=-1);
//}
//// ham in ra
//void in(stack &s){
//	for(int i=s.top;i!=MAX;i++){
//		printf("%d",retrieve(&s));
//		pop(&s);
//	}
//}
//int main(){
//	stack s;
//	read(s);printf("\nstack la\n");in(s);
//}
//===========TAO HANG DOI BANG PP TINH TIEN===========
//#include <stdio.h>
//#include <conio.h>
//#define MAX 30
//typedef struct{
//	int data[MAX];
//	int front, rear;
//}queue;
//// tao hang doi rong
//void makenull(queue &q){
//	q.front=-1;
//	q.rear=-1;
//}
//// kiem tra hang doi rong
//int empty(queue q){
//	return q.front==-1;
//}
//// kiem tra day
//int full(queue q){
//	return (q.rear-q.front)+1==MAX;
//}
//// xoa 1ptu ra khoi hang xoa la chi co xoa o dau thoi(front)
//void xoa(queue &q){
//	if(!empty(q)){
//		q.front++;
//		if(q.front>q.rear)makenull(q);
//	}else {
//		printf("rong\n");
//	}
//}
//// them ptu vao hang neu them la chi co the them vao cuoi ma thoi(rear)
//void them(queue &q,int x){
//	if(!full(q)){
//	 q.front=0;
//	if(q.rear==MAX-1){
//			for(int i=0;i<MAX;i++){
//				q.data[q.rear-q.front]=q.data[i];// tinh tuyen
//			}	q.rear=q.rear-q.front;q.front=0;// dinh nghia lai front rear
//		}
//		q.rear++;
//		q.data[q.rear]=x;
//	}else printf("hang day\n");
//}
//void read(queue &q){
//	int n,k;
//	printf ("nhap vao so ptu\n");
//	scanf("%d",&n);
//	makenull(q);
//	for(int i=1;i<=n;i++){
//		printf("nhap ptu %d ",i);
//		scanf("%d",&k);
//		them(q,k);
//	}
//}
//void in(queue &q){
//	for(;!empty(q);){
//		printf("%d\t",q.data[q.front]);
//		xoa(q);
//	}printf("\n");
//}
//int main(){
//	queue q;
//	read(q);
//	in(q);
//}
//=========TAO HANG DOI MANG XOAY VONG=========
//#include <stdio.h>
//#include <conio.h>
//#define MAX 30
//typedef struct{
//	int data[MAX];
//	int front,rear;
//}queue;
//// tao hang doi rong
//void makenull(queue &q){
//	q.front=-1;
//	q.rear=-1;
//}
//// kiem tra rong
//int empty(queue q){
//	return q.front==-1;
//}
//// kiem tra hang day
//int full(queue q){
//	return (q.rear-q.front)+1%MAX==0;
//}
//// xoa 1 ptu ra khoi hang
//void xoa(queue &q){
//	if(!empty(q)){
//		if(q.front==q.rear)makenull(q);// hang chi chua 1 ptu nen ta khoi tao lai mang
//		else q.front=(q.front+1)%MAX;//
//	}else printf("hang rong\n");
//}
//void them(queue &q,int x){
//	if(!full(q)){
//		if(empty(q)) q.front=0;
//		q.rear=(q.rear+1)%MAX;
//		q.data[q.rear]=x;
//	}else printf("loi hang day\n");
//}
//void read(queue &q){
//	printf("nhap -1 de ket thuc\n");
//	int x;
//	makenull(q);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=1)them(q,x);
//	}while(x!=-1);
//}
//void in(queue q){
//	for(int i=q.front;i<q.rear;i++){
//		printf("%d  ",q.data[q.front]);
//		xoa(q);
//	}
//}
//int main(){
//	queue q;
//	read(q);
//	in(q);
//}
// =======TAO CAY BANG MANG=========
//#include <stdio.h>
//#include <conio.h>
//#define MAX 30
//#define NIL -1
//typedef char datatype;
//typedef int node;
//typedef struct{
//	datatype Lable[MAX];
//	node Parent[MAX];
//	int maxnode;
//}tree;
//// tao mot cay rong
//void makenull(tree &T){
//	T.maxnode=0;
//}
//// kiem tra coi cay co rong chua
//int empty(tree T){
//	return T.maxnode==0;
//}
//// tim cha cua 1 nut tren cay
//int parent(tree T,int n){
//	if(empty(T)||n>T.maxnode-1)return NIL;
//	else return T.Parent[n];
//}
//// xac dinh nhan cua nut n
//int lable(tree T,int n){
//	if(!empty(T)&&n<=T.maxnode-1) return T.Lable[n];
//	else printf("ko co nhan\n");
//}
//// xac dinh nut goc cua cay
//int root(tree T){
//	if(!empty(T))return 0;
//	else return NIL;
//}
//// ham xac dinh con trai nhat cua 1 nut
//int leftmostchild(tree T,int n){
//	int i=n+1; int find=0;
//	if(n<0)return NIL;
//	while(i<T.maxnode&&find==0){
//		if(T.Parent[i]==n)find=1;
//		else i++;
//	}if(find==1)return i;
//	else return NIL;
//}
//// ham xac dinh ae ruot phai cua 1 nut
//int rightsibling(tree T, int n){
//	int i=n+1; int find=0;
//	if(n<0)return NIL;
//	while(i<T.maxnode&&find==0){
//		if(T.Parent[i]==T.Parent[n])find=1;
//		else i++;
//	}if(find==1)return i;
//	else return NIL;
//}
//// duyet cay tien tu
//void preorder(tree T,int n){
//	int i=0;
//	printf("%c",lable(T,n));
//	i=leftmostchild(T,n);
//	while(i!=NIL){
//		preorder(T,i);
//		i=rightsibling(T,i);
//	}
//}
//// duyet trung tu
//void inorder(tree T,int n){
//	int i=0;
//	i=leftmostchild(T,n);
//	if(i!=NIL)inorder(T,i);
//	printf("%c",lable(T,n));
//	i=rightsibling(T,i);
//	while(i!=NIL){
//		inorder(T,i);
//		i=rightsibling(T,i);
//	}
//}
//// duyet hau tu
//void postorder(tree T,int n){
//	int i=0;
//	i=leftmostchild(T,n);
//	while(i!=NIL){
//		postorder(T,i);
//		i=rightsibling(T,i);
//	}printf("%c",lable(T,n));	
//}
//// doc
//void read(tree &T){
//	makenull(T);
//	do{
//	printf("nhap so ptu\n");
//	scanf("%d",&T.maxnode);	
//	}while(T.maxnode<1||T.maxnode>MAX);
//	printf("nhap nhan cua goc\n");fflush(stdin);
//	scanf("%c",&T.Lable[0]);
//	T.Parent[0]=NIL;
//	printf("nhap cac ptu con lai\n");
//	for(int i=1;i<T.maxnode;i++){
//		printf("nhap nhan thu %d",i);fflush(stdin);
//		scanf("%c",&T.Lable[i]);
//		printf("nhap cha cua ptu thu %d",i);fflush(stdin);
//		scanf("%d",&T.Parent[i]);
//	}
//}
//int main(){
//	tree T;
//	read(T);
//	printf("duyet tien tu\n");							
//	preorder(T,root(T));
//	printf("\nduyet trung tu\n");
//	inorder(T,root(T));
//	printf("\nduyet hau tu\n");
//	postorder(T,root(T));
//	
//}
// =========DUYET CAY NHI PHAN============
//#include <stdio.h>
//#include <conio.h>
//#include <malloc.h>
//#define NIL -1
//typedef int datatype;
//typedef struct node{
//	datatype data;
//	node *left;
//	node *right;
//};
//typedef node *tree;
//// tao cay rong
//void makenull(tree &T){
//	T=NULL;
//}
//// kiem tra rong
//int empty(tree T){
//	return T==NULL;
//}
//// tim con trai nhat
//tree leftmostchild(tree T){
//	if(!empty(T))return T->left;
//	else return NULL;
//}
//// tim con benh phai
//tree rightsibling(tree T){
//	if(!empty(T))return T->right;
//	else return NULL;
//}
//// kiem tra 1 nut co phai la la hay ko
//int isleaf(tree T){
//	if(!empty(T))return T->left==NULL&&T->right==NULL;
//	else return 0;
//}
//// duyet tien tu
//void preorder(tree T){
//	printf("%d  ",T->data);
//	if(leftmostchild(T)!=NULL)preorder(leftmostchild(T));
//	if(rightsibling(T)!=NULL)preorder(rightsibling(T));
//}
//// duyet trung tu
//void inorder(tree T){
//	if(leftmostchild(T)!=NULL)inorder(leftmostchild(T));
//	printf("%d  ",T->data);
//	if(rightsibling(T)!=NULL)inorder(rightsibling(T));
//}
//// duyet hau tu
//void postorder(tree T){
//	if(leftmostchild(T)!=NULL)postorder(leftmostchild(T));
//	if(rightsibling(T)!=NULL)postorder(rightsibling(T));
//	printf("%d  ",T->data);
//}
//// dem so nut co tren cay
//int countnode(tree T){
//	if(empty(T))return 0;
//	else return 1+countnode(leftmostchild(T))+countnode(rightsibling(T));
//}
//// tim kiem tren cay nhi phan
//tree search(tree Root,int x){
//	if(Root==NULL)return NULL;
//	else if(Root->data==x)return Root;
//	else if(Root->data<x)search(Root->right,x);
//	else if(Root->data>x)search(Root->left,x);
//}
//// chen them 1ptu
//void insertnode(tree &T,int x){// cho nay
//	if(empty(T)){
//		T=(node*)malloc(sizeof(node));
//		T->data=x;
//		T->left=NULL;
//		T->right=NULL;
//	}else if(T->data<x)insertnode(T->right,x);
//	else if(T->data>x)insertnode(T->left,x);
//}
//// tra ve khoa cua nut cuc trai
//int deletemin(tree &t){
//	int k;
//	if(t->left==NULL){
//		k=t->data;
//		t=t->right;
//		return k;
//	}else deletemin(t->left);
//}
//void deletenode(tree &T,int x){
//	if(T!=NULL)
//	if(x<T->data)deletenode(T->left,x);
//	else if(x>T->data)deletenode(T->right,x);
//	else if(T->left==NULL&&T->right==NULL)T=NULL;
//	else if(T->left==NULL)T=T->right;
//	else if(T->right==NULL)T=T->left;
//	else T->data=deletemin(T->right);
//}
//// doc danh sach
//void readtree(tree &T){
//	int x;
//	printf("nhap vao cac so nguyen cho cay\n");
//	makenull(T);
//	do{
//		printf("x= ");
//		scanf("%d",&x);
//		if(x!=-1)insertnode(T,x);
//	}while(x!=-1);
//}
//// tim max
//int max(int a,int b){
//	if(a>b)return a;
//	else return b;
//}
//// do chieu cao cua cay
//int height(tree T){
//	if(T==NULL||leftmostchild(T)==NULL&&rightsibling(T)==NULL)return 0;
//	else return 1+max(height(leftmostchild(T)),height(rightsibling(T)));
//}
//// dem so nut 1 con
//int sonut1con(tree T){
//	if(T==NULL)return 0;
//	else if(T->left!=NULL&&T->right==NULL)return 1+sonut1con(T->left);
//	else if(T->left==NULL&&T->right!=NULL)return 1+sonut1con(T->right);
//	else return sonut1con(T->left)+sonut1con(T->right);
//}
//int main(){
//	tree T;
//	readtree(T);
////	printf("\nduyet tien tu\n");
////	preorder(T);
////	printf("\nduyet trung tu\n");
////	inorder(T);
////	printf("\nduyet hau tu\n");
////	postorder(T);
////	deletenode(T,5);
////	printf("\nduyet tien tu\n");
////	preorder(T);
////	printf("%d",height(T));
//	printf("%d",sonut1con(T));
//}





