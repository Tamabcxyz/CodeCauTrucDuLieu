#include <stdio.h>
#include <conio.h>
//int hopLe(int date, int month, int year){
//	int hl=1;
//	if(month>0&&month<13&&year>0&&date>0&&date<32)
//}

int dateOfMonth(int month, int year){
	if(month==2){
		if(year%4==0&&year%100!=0||(year%400==0))printf("month have 29 date\n");
		else printf("month have 28 date\n");
	}else if(month==4||month==6||month==9||month==11){
		printf("this month have 30 date\n");	
	}else if(month==1||month==3||month==5||month==7||month==10||month==12||month==8){
		printf("this month have 31 date\n");
	}else{
		printf("error month!!@@");
	}
}

int main(){
	int date, month, year;
	printf("give me a month from 1 to 12 and year you will hava a date \n");
	scanf("%d%d",&month,&year);
	dateOfMonth(month,year);
//	printf("nhap vao ngay thang nam voi dinh dang nhu sau dd/mm/yyyy");
//	scanf("%d%d%d",&date,&month,&year);
}
