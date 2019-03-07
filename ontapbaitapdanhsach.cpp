#include <stdio.h>
#include <conio.h>
#define max 30
typedef int element;
typedef int position;
typedef struct{
	element data[max];
	position last;
}list;
// tao danh sach rong
void makenull(list &L){
	L.last=0;
}
// kiem tra co rong chua
position empty(list L){
	return L.last==0;
}
// full ds
position full(list L){
	return L.last==max;
}
// next
position next(list L,position p){
	return p+1;
}
// revious
position revious(list L,position p){
	return p-1;
}
// dau
position first(list L){
	return 1;
}
// cuoi
position end(list L){
	return L.last+1;
}
// noi dung tai vi tri p
element retrieve(list L,position p){
	return L.data[p-1];
}
// vi tri cua ptu x trong ds
position locate(list L,element x){
	position p=first(L);
	position find=0;
	while(p!=end(L)&&find==0){
		if(retrieve(L,p)==x)find=1;
		else p=next(L,p);
	}
	return p;
}
// chen
void insert(list &L,element x,position p){
	if(full(L)){
		printf("ds day\n");
	}
	else{
		if(p<0||p>max){
			printf("sai vi tri\n");
		}
		else{
			for(position i=L.last;i>=p;i=revious(L,i)){
				L.data[i]=L.data[i-1];
			}L.last++;L.data[p-1]=x;
		}
	}
}
// nhap
void read(list &L){
	element n,k;
	printf("nhap vao so luong ptu\n");
	scanf("%d",&n);
	makenull(L);
	for(position i=1;i<=n;i=next(L,i)){
		printf("nhap phan tu thu %d ",i);
		scanf("%d",&k);
		insert(L,k,i);
	}
}
// in
void in(list &L){
	for(position i=1;i<=L.last;i=next(L,i)){
		printf("%d\t",L.data[i-1]);
	}
}
// xoa 1ptu
void xoa(list &L,position p){
	for(position i=p;i<=L.last;i=next(L,i)){
		L.data[i-1]=L.data[i];
	}		L.last--;
}
// sap xep
void sapxep(list &L){
	for(position i=1;i<=L.last;i=next(L,i)){
		for(position j=next(L,i);j<=L.last+1;j=next(L,j)){
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
void chentang(list &L,element x){
	for(position i=1;i<=L.last;i=next(L,i)){
		if(retrieve(L,i)>x){
			for(position j=end(L);j>=i;j=revious(L,j)){
				L.data[j]=L.data[j-1];
			}L.last++;L.data[i-1]=x;break;
		}
	}
}
// tim kiem va xoa
void timxoa(list &L,element x){
	for(position i=1;i<=L.last;i=next(L,i)){
		if(retrieve(L,i)==x){
			xoa(L,i);
		}
	}
}

// ==============bai 6============nhap vao tim cho xen vao cho dung thu tu
void timxen(list &L,element x){
	position p=first(L);
	while(p!=end(L)&&retrieve(L,p)<x){
		p=next(L,p);
	}insert(L,x,p);
}
void read_timxen(list &L){
	element x;
	printf("nhap -1 de ket thuc\n");
	do{
		printf("x= ");
		scanf("%d",&x);	
		if(x!=-1)timxen(L,x);
	}while(x!=-1);
}
//=========bai 7=========== tim va xoa chi chua lai 1 ptu sao cho ds ko co ptu trung
void xoatrung(list &L){
	for(position i=first(L);i<=L.last;i=next(L,i)){
		for(position j=next(L,i);j<=L.last;j=next(L,j)){
			if(retrieve(L,i)==retrieve(L,j)){
				xoa(L,j);
				j--;
			}
		}
	}
}
//=======bai8=======nhap vao ds tim va xen sao cho ko co ptu trung nhau
void timxenkotrung(list &L,element x){
	position p=first(L);
	if(locate(L,x)==end(L)){
		while(p!=end(L)&&retrieve(L,p)<x){
			p=next(L,p);	
		}insert(L,x,p);
	}
}
void doctimxenkotrung(list &L){
	int x=0;
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)timxenkotrung(L,x);
	}while(x!=-1);
}
/*=============bai 9===========*/
// nhap vao 2 danh sach co thu tu roi chon lai sao cho ds van co thu tu
void gop2danhsach(list l1,list l2,list &l3){
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
int main(){
	list L;
//	read(L);
//	in(L);
	
//	doctimxenkotrung(L);printf("\n");
//	in(L);
/*=============bai 9===========*/
list l1,l2,l3;
printf("nhap vao ds l1\n");
read(l1);
sapxep(l1);
in(l1);
printf("nhap vao ds l2\n");
read(l2);
sapxep(l2);
in(l2);
gop2danhsach(l1,l2,l3);printf("\n");
in(l3);
	
}
