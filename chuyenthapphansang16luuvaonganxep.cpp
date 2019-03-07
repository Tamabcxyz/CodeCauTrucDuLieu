#include <stdio.h>
#include <conio.h>
// doi so thap phan sang thap luc phan va luu vao ngan xep
#define max 30
typedef struct{
	char data[max];
	int top;
}stack;
// tao ngan xep rong
void makenull(stack *s){
	s->top=max;
}
// kiem tra ngan xep rong
int empty(stack s){
	return s.top==max;
}
// kiem tra ngan xep day
int full(stack s){
	return s.top==0;
}
// noi dung ptu tai top
char retrieve(stack *s){
	return s->data[s->top];
}
// them ptu vao ds
void push(stack *s,char x){
	if(!full(*s)){
		s->top=(s->top)-1;
		s->data[s->top]=x;
	}else{
		printf("day\n");
	}
}
// xoa ptu ra khoi ngan xep
void pop(stack *s){
	if(!empty(*s)){
		s->top=(s->top+1);
	}else{
		printf("rong\n");
	}
}
//ham chuyen doi
char chuyen(int so){
	int du;
	int i=0;
	for(;so>0;){
		du=so%16;
		switch(du){
			case 1:{
			return '1';
			break;
		}
		case 2:{
			return '2';
			break;
		}
		case 3:{
			return '3';
			break;
		}
		case 4:{
			return '4';
			break;
		}
		case 5:{
			return '5';
			break;
		}
		case 6:{
			return '6';
			break;
		}
		case 7:{
			return '7';
			break;
		}
		case 8:{
			return '8';
			break;
		}
		case 9:{
			return '9';
			break;
		}
		case 10:{
			return 'A';
			break;
		}
		case 11:{
			return 'B';
			break;
		}
		case 12:{
			return 'C';
			break;
		}
		case 13:{
			return 'D';
			break;
		}
		case 14:{
			return 'E';
			break;
		}
		case 15:{
			return 'F';
			break;
		}
		}
		so=so/16;
	}
}
void read(stack &s){
	int so;
	printf("nhap vao so thap phan\n");
	scanf("%d",&so);
	makenull(&s);
	push(&s,chuyen(so));
}
void in(stack &s){
	while(!empty(s)){
		printf("%c ",s.data[s.top]);
		pop(&s);
	}
}
int main(){
	stack s;
	int so;
	read(s);
	in(s);
}

