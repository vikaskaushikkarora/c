#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void sum(int N,void *x,void *y,void* z){
	for(short i=0;i<N;i++){
		(*((int *)z+i))=(*((int *)x+i))+(*((int *)y+i));
	}
}

int main(int argc,char* argv[]){
	int N=10;
	int* a=malloc(N*sizeof(int));
	int* b=malloc(N*sizeof(int));
	int* c=malloc(N*sizeof(int));
	
	for(short i=0;i<N;i++){
		*(a+i)=i;
		*(b+i)=i*i;
	}
	sum(N,a,b,c);
	for(short i=0;i<N;i++){
		printf("%d\t%d\t%d\n",*(a+i),*(b+i),*(c+i));
	}
	return 0;
}
