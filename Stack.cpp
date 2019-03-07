#include <stdio.h>
#include <conio.h>
#define max 30
// tao ngan xep
typedef struct{
	int data[max];
	int top;// giu vi tri dinh cua ngan xep
}stack;
int makenull(stack &s){
	return s.top=max;
}
int empty(stack s){
	return s.top==max;
}
int length(stack s){
	return s.top;
}
void push(stack &s,int x){
	s.top=s.top-1;
	s.data[s.top]=x;
}
void pop(stack &s){
	if(!empty(s))s.top=s.top+1;
}
int retrieve_top(stack s){
	return s.data[s.top];
}
void read(stack &s){
	int x;
	makenull(s);
	do{
		printf("x= ");scanf("%d",&x);
		if(x!=-1) push(s,x);
	}while(x!=-1);
}
void in(stack s){
	while(!empty(s)){
		printf("%d  ",retrieve_top(s));
		pop(s);
	}
}


int main(){
	stack s;
	read(s);printf("ds vua nhap la:\t");in(s);

}
