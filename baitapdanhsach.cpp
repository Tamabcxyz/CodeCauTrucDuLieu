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
int empty(list L){
	return L.last==0;
}
// full list
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
// cuoi
position end(list L){
	return L.last+1;
}
// dau
position first(list L){
	return 1;
}
// noi dung tai vi tri p
element retrieve(list L,position p){
	return L.data[p-1];
}
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
// doc
void read(list &L){
	printf("nhap vao so ptu\n");
	int n,k;
	scanf("%d",&n);
	makenull(L);
	for(position i=1;i<=n;i++){
		printf("nhap phan tu thu %d ",i);
		scanf("%d",&k);
		insert(L,k,i);
	}
}
// in
void in(list &L){
	for(position i=1;i<=L.last;i++){
		printf("%d\t",retrieve(L,i));
	}
}
// xoa
void xoa(list &L,position p){
	if(empty(L)){
		printf("danh sach rong\n");
	}
	else{
		if(p<0||p>max){
			printf("sai vi tri\n");
		}
		else{
			for(position i=p;i<=L.last;i++){
				L.data[i-1]=L.data[i];
			}L.last--;
		}
	}
}
// sapxep
void swap(list &L,position a,position b){
	element temp=0;
	temp=L.data[a-1];
	L.data[a-1]=L.data[b-1];
	L.data[b-1]=temp;
}
void sapxep(list &L){
	for(position i=1;i<=L.last;i++){
		for(position j=i+1;j<=L.last;j++){
			if(L.data[i-1]>L.data[j-1]){
				//swap(L,i,j);
				element temp=0;
				temp=L.data[i-1];
				L.data[i-1]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
}
// chen tang
void chentang(list &L,element x){
	for(position i=1;i<=L.last;i++){
		if(L.data[i-1]>x){
			for(position j=L.last;j>=i;j--){
				L.data[j]=L.data[j-1];
			}L.last++;L.data[i-1]=x;break;
		}
	}
}
// tim va xoa
void timxoa(list &L,element x){
	for(position i=1;i<=L.last;i++){
		if(L.data[i-1]==x){
			xoa(L,i);
			i--;
		}
	}
}
// nhap vao day so va tim cho xen vao sao cho day van tang
void timvaxen(list &L,element x){
	position p=first(L);
	while(p!=end(L)&&retrieve(L,p)<x){
		p=next(L,p);
	}insert(L,x,p);
}
void readtimxen(list &L){
	int x;
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)timvaxen(L,x);printf("\n");
	}while(x!=-1);
}
// tim va xoa phan tu trung nhau chi du lai dung 1 phan tu
void xoatrung(list &L){
	for(position i=1;i<=L.last;i++){
		for(position j=i+1;j<=L.last;j++){
			if(retrieve(L,j)==retrieve(L,i)){
				xoa(L,j);
				j--;
			}
		}
	}
}
// nhap vao phan tu va tim vi tri chen vao va xem no co trong ds chua neu chua thi chen neu co roi thi thoi
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
void merge_twolist(list L1,list L2,list &L3){
	position p1,p2;
	p1=first(L1);
	p2=first(L2);
	makenull(L3);
	while(p1!=end(L1)&&p2!=end(L2)){
		if(retrieve(L1,p1)<=retrieve(L2,p2)){
			insert(L3,retrieve(L1,p1),end(L3));
			p1=next(L1,p1);
		}
		else{
			insert(L3,retrieve(L2,p2),end(L3));
			p2=next(L2,p2);
		}
	}
	while(p1!=end(L1)){
		insert(L3,retrieve(L1,p1),end(L3));
		p1=next(L1,p1);
	}
	while(p2!=end(L2)){
		insert(L3,retrieve(L2,p2),end(L3));
		p2=next(L2,p2);
	}
}
// =============bai 10 xoa cac phan tu la so le=============
void xoale(list &L){
	for(position i=1;i<=L.last;i++){
		if(L.data[i-1]%2!=0){
			xoa(L,i);
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
	list L;read(L);in(L);
	xoa(L,2);printf("\n sau khi xoa danh sach con lai la\n");in(L);
	sapxep(L);printf("\nsau khi sap xep danh sach la\n");in(L);
	timxoa(L,3);printf("\n sau khi tim xoa danh sach la\n");in(L);
//	readtimxen(L);in(L);
//	printf("\n sau khi xoa trung danh sach la\n");
//	xoatrung(L);in(L);
//	doctimxenkotrung(L);
//	printf("\n sau khi tim va xen thi ds la\n");in(L);
/*===============bai so 9================
	list L1,L2,L3;
	printf("nhap vao danh sach 1\n");
	read(L1);
	sapxep(L1);
	in(L1);
	printf("\nnhap vao danh sach 2\n");
	read(L2);
	sapxep(L2);
	in(L2);
	merge_twolist(L1,L2,L3);
	printf("\nsau khi chon ta dc ds la\n");
	in(L3);
*/
/*	=============bai 10 xoa cac so le ra khoi danh sach lien ket==========
	list L;
	read(L);
	xoale(L);
	in(L);
*/
/*=============bai 11============
	list L1,L2,L3;
	printf("nhap vao danh sach 1\n");
	read(L1);
	in(L1);
	printf("\nsau khi tach danh sach ta dc\n");
	phanloaichanle(L1,L2,L3);
	printf("\n***********\n");
	in(L2);
	printf("\n***********\n");
	in(L3);
*/
}
