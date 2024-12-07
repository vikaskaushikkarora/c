#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM (long) 1e2

int main(){
	double a,b;
	FILE* fptr = fopen("data","w");
	for(long i=1;i<=NUM;i++){
		a=0.01*i;
		b=a*a;
		fprintf(fptr,"%lf %lf\n",a,b);
	}
	fclose(fptr);
	return 0;
}
