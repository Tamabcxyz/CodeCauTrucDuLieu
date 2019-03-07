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
float tinhbieuthuctiento(char bttiento[]){
	// tach cac token de luu vao 1 mang token
	const char phancach[2]=" ";
	char *token;
	char *tokens[100];
	int index=0;
	token=strtok(bttiento,phancach);// lay token dau tien
	while(token !=NULL){
		tokens[index]=token;
		index++;
		// lay token ke tiep
		token=strtok(NULL,phancach);
	}	
	// in ra token theo thu tu nguoc de ktr
	for(int i=index-1;i>=0;i--)
	printf("\n%s",tokens[i]);
	printf("\n");
	// tao mot stack
	stack s;
	makenullstack(s);
	// duyet qua cac token tu phai sang trai
	for(int i=index-1;i>=0;i--){
		if(latoanhang(tokens[i]))
		Push(atof(tokens[i]),s);
		else{
			elementtype b=Top(s);Pop(s);
			elementtype a=Top(s);Pop(s);
			char pheptoan=tokens[i][0];
			switch(pheptoan){
				case '+':b+=a;break;
				case '-':b-=a;break;
				case '*':b*=a;break;
				case '/':b/=a;break;
			}Push(b,s);
		}
	}return Top(s);
}

int main(){
	elementtype x;
	char bttiento[50];
	printf("nhap vao bieu thuc tien to trong do toan hang va toan tu cach nhau khoang trang\n");
	printf("vi du: * + 6 4 5 cho (6+4)*5, gia tri la 50\n");gets(bttiento);
	printf("gia tri cua bieu thuc tien to tren la %.2f ",tinhbieuthuctiento(bttiento));	
}
