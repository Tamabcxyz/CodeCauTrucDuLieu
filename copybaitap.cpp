#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef int ElementType;
typedef struct Node{
 ElementType Element;
 struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;
/*Tao danh sach rong*/
void MakeNull_List(List &Header){
 Header=(Node*)malloc(sizeof(Node));
 Header->Next=NULL;
}
/*Kiem tra danh sach rong*/
int Empty_List(List L){
 return (L->Next==NULL);
}
/*Xen mot phan tu vao danh sach*/
void Insert_List(ElementType X, Position P, List &L){
 Position T;
 T=(Node*)malloc(sizeof(Node));
 T->Element=X;
 T->Next=P->Next;
 P->Next=T;
}
/*Tra ve gia tri cua phan tu o vi tri P*/
ElementType Retrieve(Position P, List L){
 if(P->Next!=NULL)
 return P->Next->Element;
} 
/*Xac dinh vi tri phan tu dau*/
Position First(List L){
 return L;
}
/*Xac dinh vi tri phan tu sau phan tu cuoi*/
Position EndList(List L){
 Position P;
 P=First(L);
 while(P->Next!=NULL)P=P->Next;
 return P;
}
/*Sap xep tang dan*/
void Sort(List &L){
 Position P,Q;
 ElementType temp;
 P=L->Next;
 while(P!=NULL){
 Q=P->Next;
 while(Q!=NULL){
 if(P->Element > Q->Element){
 temp=P->Element;
 P->Element=Q->Element;
 Q->Element=temp;
 }
 Q=Q->Next;
 }
 P=P->Next;
 }
}
/*Nhap danh sach*/
void Read_List(List &L){
 ElementType x;
 printf("Nhap vao 1 danh sach cac so nguyen, -1 de dung\n");
 MakeNull_List(L);
 do{
 printf("x=");scanf("%d",&x);
 if(x!=-1)
 Insert_List(x,EndList(L),L);
 }while(x!=-1);
}
/*In danh sach ra man hinh*/
void Print_List(List L){
 Position P;
 P=L->Next;
 while(P!=NULL){
 printf("%5d",P->Element);
 P=P->Next;
 }
} 
main(){
 List L;
 ElementType x;
 Position p;
 MakeNull_List(L);
 Read_List(L);
 printf("Danh sach vua nhap:");
 Print_List(L); printf("\n");
// Sort(L);
// printf("Danh sach sau khi sap xep:");
// Print_List(L); printf("\n");
// getch();
}
