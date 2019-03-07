#include <stdio.h>
#include <conio.h>
#define MAX 30
#define NIL -1
typedef char datatype;
typedef int node;
typedef struct{
	node parent[MAX];// luu tru nut cha 
	int maxnode;// quan ly so luong nut that su cua cay
	datatype data[MAX];// luu tru nhan(giu lieu trong o)
}tree;
// tao cay rong ko co meo j het
void makenull(tree &T){
	T.maxnode=0;
}
// kiem tra xem cay co meo j chua
int empty(tree T){
	return T.maxnode==0;
}
// xac dinh nut cha cua nut tren cay
node parent(tree T, node n){
	if(empty(T)||n>T.maxnode-1)return NIL;
	else return T.parent[n];
}
// xac dinh nhan cua nut n
datatype lable_node(tree T, node n){
	if(!empty(T)&&n<=T.maxnode-1)return T.data[n];
	else printf("ko co nhan\n");
}
// ham mac dinh nut goc trong cay
int root(tree T){
	if(!empty(T))return 0;
	else return NIL;
}
// ham xac dinh con trai nhat cua 1 nut
node leftmost_child(tree T,node n){
	node i=n+1; int find=0;
	if(n<0)return NIL;
	while(i<=T.maxnode-1&&find==0){
		if(T.parent[i]==n) find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;
}
// ham xac dinh ae ruot phai cua 1 nut
node right_sibling(tree T, node n){
	node i=n+1; int find=0;
	if(n<0)return NIL;
	while(i<=T.maxnode-1&&find==0){
		if(T.parent[i]==T.parent[n]) find=1;
		else i++;
	}if(find==1)return i;
	else return NIL;
}
// duyet tien tu
void preorder(tree T, node n){
	node i;
	printf("%c",lable_node(T,n));
	i=leftmost_child(T,n);
	while(i!=NIL){
		preorder(T,i);
		i=right_sibling(T,i);
	}
}
// duyet trung tu
void inorder(tree T, node n){
	node i;
	i=leftmost_child(T,n);
	if(i!=NIL)inorder(T,i);
	printf("%c",lable_node(T,n));
	i=right_sibling(T,i);
	while(i!=NIL){
		inorder(T,i);
		i=right_sibling(T,i);
	}
}
// duyet hau tu
void postorder(tree T, node n){
	node i;
	i=leftmost_child(T,n);
	while(i!=NIL){
		postorder(T,i);
		i=right_sibling(T,i);
	}
	printf("%c",lable_node(T,n));
}
void readtree(tree &T){
	makenull(T);
	node n;
	do{
		printf("co bao nhieu phan tu\n");
		scanf("%d",&T.maxnode);
	}while(T.maxnode<1||T.maxnode>MAX);
	printf("nhap nhan(gia tri cua nut 0)\n");fflush(stdin);
	scanf("%c",&T.data[0]);
	T.parent[0]=NIL;
	printf("\nnhap cac phan tu con lai\n");
	for(int i=1;i<T.maxnode;i++){
		printf("cha cua nut %d la ",i);fflush(stdin);
		scanf("%d",&T.parent[i]);
		printf("\n nhan cua nut la ");fflush(stdin);
		scanf("%c",&T.data[i]);
	}
}
int main(){
	tree T;
	readtree(T);
	printf("duyet tien tu\n");							
	preorder(T,root(T));
	printf("\nduyet trung tu\n");
	inorder(T,root(T));
	printf("\nduyet hau tu\n");
	postorder(T,root(T));
}

