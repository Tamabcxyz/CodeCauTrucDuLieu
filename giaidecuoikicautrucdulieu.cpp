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
	int x; printf("nhap -1 de ket thuc\n");
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
	}else	printf("ds rong\n");
		
}
void phanloaichanle(list L1,list &L2,list &L3){
	position p=first(L1);int dem1=0,dem2=0;
	makenull_list(L2);
	makenull_list(L3);
	while(p!=end(L1)){
		if(retrieve(L1,p)%2==0){
			insert_list(L2,retrieve(L1,p),end(L2));
			dem1++;
		}
		else{
			insert_list(L3,retrieve(L1,p),end(L3));
			dem2++;
		}
		p=next(L1,p);
	}printf("\nco %d so chan\n",dem1);printf("co %d so le",dem2);
}
// ham xoa cac so chia het cho 5
void xoasochiahetcho5(list &L){
	position p=first(L);
	while(p!=end(L)){
		if(retrieve(L,p)%5==0){
			xoa(L,p);
		}else p=next(L,p);
	}
}
// ham tinh tong cua ds l
int tong(list L){
	int dem=0,i;
	for(i=0;i<L.last;i++){
		dem=dem+L.data[i];
	}
	return dem;
}
int main(){
	list L,L1,L2;
	read(L);printf("ds vua nhap la\t\n");in(L);printf("\ntong cua ds la: %d ",tong(L));
	xoasochiahetcho5(L);printf("\nsau khi xoa so chia het cho 5 ds con la\t");in(L);
	phanloaichanle(L,L1,L2);
	printf("\nds so chan la\t");in(L1);
	printf("\nds so le la\t");in(L2);
}
