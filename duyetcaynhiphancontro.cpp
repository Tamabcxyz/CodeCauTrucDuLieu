#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define NIL -1
typedef int keytype;
typedef struct node{
	keytype data;
	node *left;
	node *right;
};
typedef node *tree;
// tao cay rong
void makenull(tree &T){
	T=NULL;
}
// kiem tra rong
int empty(tree T){
	return T==NULL;
}
// con trai nhat
tree leftmostchild(tree T){// dang dung kieu tra ve la node theo dung thi dung kieu tree
	if(T!=NULL)return T->left;
	else return NULL;
}
// ae ruot phai
tree rightsibling(tree T){// dang dung kieu tra ve la node theo dung thi dung kieu tree
	if(T!=NULL)return T->right;
	else return NULL;
}
// kiem tra xem 1 nut co phai la hay ko
int isleaf(tree T){
	if(T!=NULL)return leftmostchild(T)==NULL&& rightsibling(T)==NULL;
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
// duyet hau tu
void postorder(tree T){
	if(leftmostchild(T)!=NULL)postorder(leftmostchild(T));
	if(rightsibling(T)!=NULL)postorder(rightsibling(T));
	printf("%d  ",T->data);
}



// xac dinh so nut trong cay
int countnode(tree T){
	if(empty(T))return 0;
	else return 1+(countnode(leftmostchild(T)))+(countnode(rightsibling(T)));
}
// tim tren cay nhi phan
tree search(tree Root,int x){
	if(Root==NULL)return NULL;
	else if(Root->data==x)return Root;
	else if(Root->data<x)search(Root->right,x);
	else if(Root->data>x)search(Root->left,x);
}
// chen them ptu
void insertnode(int x,tree &T){
	if(T==NULL){
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}else if(x<T->data)insertnode(x,T->left);
	else if(x>T->data)insertnode(x,T->right);
}
// xoa ptu lon nhat cua nhanh trai
char deletemin(tree &Root){
	char k;
	if(Root->left==NULL){
		k=Root->data;
		Root=Root->right;
		return k;
	}else deletemin(Root->left);
}
// xoa 1 ptu
void deletenode(int x,tree &Root){
	if(Root!=NULL)
	if(x<Root->data)deletenode(x,Root->left);
	else if(x>Root->data)deletenode(x,Root->right);
	else if(Root->left==NULL&&Root->right==NULL)Root=NULL;
	else if(Root->left==NULL)Root=Root->right;
	else if(Root->right==NULL)Root=Root->left;
	else Root->data=deletemin(Root->right);
}
// doc danh sach
void readtree(tree &T){
	int x;
	printf("nhap vao cac so nguyen cho cay\n");
	makenull(T);
	do{
		printf("x= ");
		scanf("%d",&x);
		if(x!=-1)insertnode(x,T);
		
	}while(x!=-1);
}
// tim max
int MAX(int a,int b){
	if(a>b)return a;
	else return b;
}
// chieu cao cua cay
int height(tree T){
	// neu cay rong hoac cay chi co 1 nut chieu cao la 0
	if(T==NULL||leftmostchild(T)==NULL&&rightsibling(T)==NULL)return 0;
	else return 1+MAX(height(leftmostchild(T)),height(rightsibling(T)));
}
// dem so nut 1 con
int sonut1con(tree T){
	if(T==NULL)return 0;
	else if(T->left!=NULL&&T->right==NULL)return 1+sonut1con(T->left);
	else if(T->left==NULL&&T->right!=NULL)return 1+sonut1con(T->right);
	else return sonut1con(T->left)+sonut1con(T->right);
}
int main(){
	tree T;
	readtree(T);
	printf("\nduyet tien tu\n");
	preorder(T);
//	printf("\nduyet trung tu\n");
//	inorder(T);
//	printf("\nduyet hau tu\n");
//	postorder(T);
//	deletenode(25,T);
//	printf("\nduyet tien tu\n");
//	preorder(T);
//	printf("%d",sonut1con(T));
	
}// I'm FINISHED
