// CAY NHI PHAN CON TRO
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef struct node{
	int data;
	node *left;
	node *right;
};
typedef node* tree;
// tao cay rong
void makenulltree(tree &T){
	T=NULL;
}
// kiem tra rong
int emptytree(tree T){
	return T==NULL;
}
// con trai nhat cua cay la
tree leftmostchild(tree T){
	if(T!=NULL)return T->left;
	else return NULL;	
}
// ae ruot phai
tree rightsibling(tree T){
	if(T!=NULL)return T->right;
	else return NULL;
}
// kiem tra 1 nut xem no co phai la la hay ko
int isleaf(tree T){
	if(T!=NULL)return leftmostchild(T)==NULL&&rightsibling(T)==NULL;
	else return NULL;
}
// duyet tien tu
void preorder(tree T){
	printf("%d  ",T->data);
	if(leftmostchild(T)!=NULL)preorder(leftmostchild(T));
	if(rightsibling(T)!=NULL)preorder(rightsibling(T));
}
// duyet trung tu
void inorder(tree T){
	if(leftmostchild(T)!=NULL)inorder(leftmostchild(T));
	printf("%d  ",T->data);
	if(rightsibling(T)!=NULL)inorder(rightsibling(T));
}
// duyet cay hau tu
void postorder(tree T){
	if(leftmostchild(T)!=NULL)postorder(leftmostchild(T));
	if(rightsibling(T)!=NULL)postorder(rightsibling(T));
	printf("%d  ",T->data);
}
// ham them ptu vao cay
void insertnode(tree &T,int x){
	if(T==NULL){
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}else if(x<T->data)insertnode(T->left,x);
	else if(x>T->data)insertnode(T->right,x);
}
// ham doc
void read(tree &T){
	int x;
	makenulltree(T);
	printf("nhap vao cay nhi phan, nhap -1 de ket thuc\n");
	do{
		printf("x= ");scanf("%d",&x);
		if(x!=-1)insertnode(T,x);
	}while(x!=-1);
}
// tong so nut cua cay nhi phan
int countnode(tree T){
	if(emptytree(T))return 0;
	else return 1+(countnode(leftmostchild(T))+countnode(rightsibling(T)));
}
// tim kiem tre  cay nhi phan
tree search(tree T,int x){
	if(T==NULL)return NULL;
	else if(T->data==x)return T;
	else if(T->data<x)search(T->right,x);
	else if(T->data>x)search(T->left,x);
}
// xoa ptu lon nhat tai nhanh benh trai
int deletemin(tree &T){
	int k;
	if(T->left==NULL){
		k=T->data;
		T=T->right;
		return k;
	}else deletemin(T->left);
}
// xoa 1ptu trong cay
void deletenode(tree &T,int x){
	if(T!=NULL)
	if(T->data<x)deletenode(T->right,x);
	else if(T->data>x)deletenode(T->left,x);
	else if(T->left==NULL&&T->right==NULL)T=NULL;
	else if(T->left==NULL)T=T->right;
	else if(T->right==NULL)T=T->left;
	else T->data=deletemin(T->right);
}
// tim max
int MAX(int a,int b){
	if(a>b)return a;
	else return b;
}
// chieu cao cua cay
int height(tree T){
	if(T==NULL||leftmostchild(T)==NULL&&rightsibling(T)==NULL)return 0;
	else return 1+MAX(height(leftmostchild(T)),height(rightsibling(T)));
}
// dem so nut 1 con
int sonut1con(tree T){
	if(T==NULL)return 0;
	else if(T->left==NULL&&T->right!=NULL)return 1+sonut1con(T->right);
	else if(T->left!=NULL&&T->right==NULL)return 1+sonut1con(T->left);
	else return sonut1con(T->left)+sonut1con(T->right);
}
int main(){
	tree T;
	read(T);
	printf("\nduyet cay tien tu\n");
	preorder(T);
//	printf("\nduyet cay trung tu\n");
//	inorder(T);
//	printf("\nduyet cay hau tu\n");
//	postorder(T);
//	printf("%d",countnode(T));
//	printf("%d",search(T,12));
//	deletenode(T,12);preorder(T);
//	printf("%d",height(T));
//	printf("%d",sonut1con(T));
}
