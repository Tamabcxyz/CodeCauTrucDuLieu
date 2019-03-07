#include <stdio.h>
#include <conio.h>
#define maxlength 30
typedef int element;
typedef int position;
typedef struct {
	element elements[maxlength];
	position last;
}list;
// ham tao danh sach rong
void makenull(list &L){
	L.last=0;
}
// ham kiem tra danh sach trong
position emptylist(list L){
	return (L.last==0);
}
// ham tra ve vi tri dau tien trong danh sach
position firstlist(list L){
	return 1;	
}
// ham tra ve vi tri sau phan tu cuoi trong danh sach
position endlist(list L){
	return L.last+1;
}
// ham tra ve vi tri phan tu ke tiep p trong danh sach
position next(position p,list L){
	return p+1;
}
// ham tra ve vi tri phan tu truoc vi tri p trong danh sach
position previous(position p,list L){
	return p-1;
}
// ham tra ve noi dung phan tu tai vi tri p trong danh sach
position retrieve(position p,list L){
	return L.elements[p-1];// vi danh sach va vi tri cua no hon kem nhau 1 don vi
}
// them phan tu co noi dung x vao vi tri p trong danh sach L
void insert_list(element x,position p,list &L){
	if(L.last==maxlength)
		printf("Full list!");
	else {
		if((p<1)||(p>maxlength))//hoac L.last+1 cung dc
			printf("ERROR!");
		else{
			for(position k=L.last;k>=p;k--){
				L.elements[k]=L.elements[k-1];

			}		L.last++; L.elements[p-1]=x;
			
			
		}
	}
	
}
// xoa phan tu tai vi tri p trong danh sach L
position deletelist(position p,list &L){
	int i;
	if(emptylist(L)==true){
		printf("mang bi rong\n");
	}
	else if(p<1||p>L.last+1){
		printf("sai vi tri roi thim\n");
	}
	else{
		for(i=p;i<L.last;i=next(i,L)){
			L.elements[i-1]=L.elements[i];
		}L.last--;
	}
}
// nhap danh sach tu ban phim
void readlist(list &L){
	int i,n;
	makenull(L);
	printf("nhap vao so phan tu cua danh sach\n");
	scanf ("%d",&n);
	for(i=1;i<=n;i=next(i,L)){
		element k;
		printf("phan tu thu %d la ",i);
		scanf("%d",&k);//lam nhu v khong the tang duoc chi so danh sach
		insert_list(k,i,L);//dung ham insert de cho danh sach duoc tang tu dong khi nhap vao
	}
	
}
void printlist(list &L){
	int i;printf("\ndanh sach se la\n");
	for(i=1;i<=L.last;i=next(i,L)){// neu chon i=0 thi in L.elements[i-1] con neu chon i=1 thi dung ham retrieve
		printf("%d\t",L.elements[i-1]);//retrieve(i,L)
	}
}
void swap(position a,position b,list &L){
	element t=0;
	t=L.elements[a-1];
	L.elements[a-1]=L.elements[b-1];
	L.elements[b-1]=t;

}
void xapsep(list &L){position i,j;
	for(i=firstlist(L);i<endlist(L);i=next(i,L)){
		for(j=next(i,L);j<endlist(L);j=next(j,L)){
			if(retrieve(i,L)>retrieve(j,L)){
				swap(i,j,L);
			}
		}
	}
}
void dao(list &L){
	for(position i=L.last;i>0;i--){
		printf("%d\t",L.elements[i-1]);// hoac retrieve(i,L);
	}
}
void chentang(element x,list &L){
	position i,k;
	for(i=0;i<L.last;i++){
		if(L.elements[i]>x){
			for(k=L.last;k>i;k=previous(k,L)){
				L.elements[k]=L.elements[k-1];
			}
			L.elements[i]=x;L.last++;break;	
		}
	}
}
int main(){
	list L;
	position p;
	readlist(L);
	printlist(L);
	xapsep(L);
	printf("sau khi xap sep ta dc\n");
	printlist(L);
	//insert_list(2,3,L);
	//printlist(L);
	deletelist(1,L);
	//printlist(L);
	//dao(L);
	//chentang(5,L);
	printlist(L);
	
	
	
	
	
}
