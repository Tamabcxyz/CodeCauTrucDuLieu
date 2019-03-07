#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
// cai dat ngan xep duyet cay hau to
typedef float elementtype;
typedef struct{
	elementtype elements[MAX];
	int top;
}stack;
// khoi tao ngan xep rong
void makenullstack(stack &s){
	s.top=MAX;
}
// kiem tra xem ngan xep co rong ko
int emptystack(stack s){
	return s.top==MAX;
}
// kiem tra xem ngan xep co day ko
int fullstack(stack s){
	return s.top==0;
}
// ham tra ve noi dung cua ptu tren dinh
elementtype Top(stack s){
	if(!emptystack(s))return s.elements[s.top];
	else printf("ngan xep rong\n");
}
// xoa 1ptu khoi ngan xep
void Pop(stack &s){
	if(!emptystack(s)) s.top++;
	else printf("ngan xep rong\n");
}
// day 1ptu len ngan xep
void Push(elementtype x,stack &s){
	if(fullstack(s))printf("ngan xep rong\n");
	else{
		s.top--;
		s.elements[s.top]=x;
	}
}
int latoanhang(char so[]){
	int dem=0;
	for(int i=0;i<strlen(so);i++)
	if(so[i]>='0'&&so[i]<='9')dem++;
	if(dem==strlen(so))return 1;
	else return 0;
}
float tinhbieuthuchauto(char bthauto[]){
	const char phancach[2]=" ";
	char *token;
	stack s;
	makenullstack(s);// tao stack rong
	// duyet qua cac token tu trai sang phai
	token=strtok(bthauto,phancach);// lay token dau tien
	while(token !=NULL){
		if(latoanhang(token))
		Push(atof(token),s);
		else{
			elementtype a=Top(s);Pop(s);
			elementtype b=Top(s);Pop(s);
			char pheptoan=token[0];
			switch(pheptoan){
				case '+': b+=a;break;
				case '-': b-=a;break;
				case '*': b*=a;break;
				case '/': b/=a;break;
			}
			Push(b,s);
		}
		// lay token ke tiep
		token=strtok(NULL,phancach);
	}
	return Top(s);
}
int main(){
	elementtype x;
	char bthauto[50];
	printf("Nhap vao 1 bieu thu hau to, trong do toan hang va toan tu cach nhau 1 khoang trang.\n"); 
	printf("(vi du: 6 4 5 + * cho 6*(4+5), gia tri la 54):"); gets(bthauto); 
	printf("Gia tri cua bieu thu hau to tren la: %.2f", tinhbieuthuchauto(bthauto)); 
}
