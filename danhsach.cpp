#include <stdio.h>
#include <conio.h>
#define max 30
typedef int element;
typedef int position;
typedef struct{
	element data[max];
	position last;
}list;
// tao ds rong
void makenull_list(list &L){
	L.last=0;
}
// kiem tra ds rong
element empty_list(list L){
	return L.last==0;
}
// kiem tra ds day
element full_list(list L){
	return L.last==max;
} 
// vi tri tiep theo cua ptu trong ds
position next(list L, position p){
	return p+1;
}
// vi tri cua ptu sau ptu p trong ds
position revious(list L, position p){
	return p-1;
}
// vi tri dau tien
position first(list L){
	return 1;
}
// vi tri cuoi cung
position end(list L){
	return L.last+1;
}
// noi dung ptu tai vi tri p
element retrieve(list L, position p){
	return L.data[p-1];
}
// ham tim vi tri ptu trong ds 
position locate(list L, int x){
	position p=first(L);
	int found=0;
	while(p!=end(L)&&found==0){
		if(retrieve(L,p)==x)found=1;
		else p=next(L,p);
	}return p;
}
// chen 1ptu vao ds
void insert_list(list &L,int x, position p){
	if(!full_list(L)){
		if(p<0||p>max)printf("sai vi tri\n");
		else {
			for(int i=L.last;i>=p;i--){
				L.data[i]=L.data[i+1];
			}L.last++;L.data[p-1]=x;
		}
	}else printf("ds day\n");
}
// ham nhap
void read(list &L){
	int x; 
	makenull_list(L);
	do{
		printf("x= ");scanf("%d",&x);
		if(x!=-1)insert_list(L,x,end(L));
	}while(x!=-1);
}
// in ds ra
void in(list &L){
	int i;
	for(i=1;i<=L.last;i++){
		printf("%d  ",retrieve(L,i));
	}
}
// xoa
void xoa(list &L, position p){
	if(!empty_list(L)){
		if(p<0||p>max)printf("sai vi tri\n");
		else{
			int i;
			for(i=p;i<=L.last;i++){
				L.data[i-1]=L.data[i];
			}L.last--;
		}
	}else printf("ds rong\n");
}
// sap xep
void sapxep(list &L){
	int i,j,temp;
	for(i=first(L);i<=L.last;i++){
		for(j=next(L,i);j<=L.last;j++){
			if(L.data[i-1]>L.data[j-1]){
				temp=L.data[i-1];
				L.data[i-1]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
}
// chen them 1ptu vao sao cho day van tang
void chentang(list &L, int x){
	int i=0,j;
	if(!full_list(L)){
		for(i=1;i<=L.last;i++){
			if(L.data[i]>x){
				for(j=L.last;j>=i;j--){
					L.data[j]=L.data[j-1];
				}L.last++;L.data[i]=x;break;
			}
		}	
	}else printf("ds day\n");
}
// tim xoa
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
	}insert_list(L,x,p);
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
		}insert_list(L,x,p);
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
	makenull_list(L3);
	while(p1!=end(L1)&&p2!=end(L2)){
		if(retrieve(L1,p1)<=retrieve(L2,p2)){
			insert_list(L3,retrieve(L1,p1),end(L3));
			p1=next(L1,p1);
		}
		else{
			insert_list(L3,retrieve(L2,p2),end(L3));
			p2=next(L2,p2);
		}
	}
	while(p1!=end(L1)){
		insert_list(L3,retrieve(L1,p1),end(L3));
		p1=next(L1,p1);
	}
	while(p2!=end(L2)){
		insert_list(L3,retrieve(L2,p2),end(L3));
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
	makenull_list(L2);
	makenull_list(L3);
	while(p!=end(L1)){
		if(retrieve(L1,p)%2==0){
			insert_list(L2,retrieve(L1,p),end(L2));
		}
		else{
			insert_list(L3,retrieve(L1,p),end(L3));
		}
		p=next(L1,p);
	}
}
int main(){
	list L;read(L);in(L);printf("\n");sapxep(L);in(L);printf("\n");timxoa(L,3);in(L);
}
