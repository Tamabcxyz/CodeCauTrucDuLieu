#include <stdio.h>
#include <conio.h>
typedef int keytype;
typedef float otherkey;
typedef struct{
	keytype key;
	otherkey otherfields;
}recordtype;
// doc file
void readFile(recordtype a[], int *n){
	FILE *f;
	f=fopen("D:/NewTextDocument.txt","r");
	if(f==NULL){
		printf("file rong\n");
	}
	fscanf(f,"%d",n);
	for(int i=1;i<=*n;i++){
		fscanf(f,"%d%f",&a[i-1].key,&a[i-1].otherfields);
	}fclose(f);
}
void inFile(recordtype a[], int *n){
	for(int i=0; i<*n;i++){
		printf("%d\t%.2f\n",a[i].key,a[i].otherfields);
	}
}
// tao mot file moi
void addFile(){
	FILE *addfile;
	addfile=fopen("taofile.txt","w");
	fprintf(addfile,"chao m t hien tai khong biet gi dau\n");
	fclose(addfile);
}
int main(){
	recordtype a[20];int n;
	readFile(a,&n);
	inFile(a,&n);
	addFile();
}
