#include <stdio.h>
#include <conio.h>
#define max 30
// tao 1 stack bao gom 1 mang va 1 con top de quan ly mang
typedef struct{
	int data[max];
	int top;
}stack;
// tao stack rong
void makenull_stack(stack *s){
	s->top=max;
}
// kiem tra stack rong
int empty_stack(stack s){
	return s.top==max;
}
// kiem tra ngan xep day
int full_stack(stack s){
	return s.top==0;
}
// lay noi dung tai dinh ngan xep
int retrieve_top(stack &s){
	if(!empty_stack(s)){
		return s.data[s.top];
	}else printf("rong\n");
}
// them 1 ptu vao stack
void push(stack *s, int x){
	if(full_stack(*s))printf("day\n");
	else {
		s->top=(s->top)-1;
		s->data[s->top]=x;
	}
}
// xoa 1 ptu khoi ds(chi xoa dc o dau)
void pop(stack *s){
	if(empty_stack(*s))printf("rong\n");
	else s->top=(s->top)+1;
}
// doc
void read(stack &s){
	printf("nhap vao so ptu\n");
	int n,k;
	scanf("%d",&n);
	makenull_stack(&s);
	for(int i=0;i<n;i++){
		printf("nhap phan tu thu %d ",i+1);
		scanf("%d",&k);
		push(&s,k);
	}
}
// in
void in(stack &s){
	int i;
	while(!empty_stack(s)){
		printf("%d\t",s.data[s.top]);
		pop(&s);
	}
}

int main(){
	stack s;
	read(s);
	in(s);
}
