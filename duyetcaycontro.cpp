#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define NIL -1
typedef char keytype;
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
	printf("%c",T->data);
	if(leftmostchild(T)!=NULL)preorder(leftmostchild(T));
	if(rightsibling(T)!=NULL)preorder(rightsibling(T));
}
// duyet trung tu
void inorder(tree T){
	if(leftmostchild(T)!=NULL)inorder(leftmostchild(T));
	printf("%c",T->data);
	if(rightsibling(T)!=NULL)inorder(rightsibling(T));
}
// duyet hau tu
void postorder(tree T){
	if(leftmostchild(T)!=NULL)postorder(leftmostchild(T));
	if(rightsibling(T)!=NULL)postorder(rightsibling(T));
	printf("%c",T->data);
}
// xac dinh so nut trong cay
int countnode(tree T){
	if(empty(T))return 0;
	else return 1+(countnode(leftmostchild(T)))+(countnode(rightsibling(T)));
}
// ham tao 1 node
tree create(char v,tree l,tree r){
	tree n;
	n=(node*)malloc(sizeof(node));
	n->data=v;
	n->left=l;
	n->right=r;
	printf("%c",n->data);
	//return n;
}
// tim tren cay nhi phan
tree search(tree T,char x){
	if(T==NULL)return NULL;
	else if(T->data==x)return T;
	else if(T->data<x)search(T->right,x);
	else if(T->data>x)search(T->left,x);
}
// chen tem ptu

int main(){
	tree T;
	tree t1=create('D',NULL,NULL);
	tree t2=create('E',NULL,NULL);
	tree t3=create('C',NULL,NULL);
	tree t4=create('B',t1,t2);
	tree t5=create('A',t4,t3);
	
	
}
