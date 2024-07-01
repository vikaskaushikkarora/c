#include<stdio.h>

void swap(float* a, float* b){
	//printf("%f\t%f\n",*a,*b);
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
	//printf("%f\t%f\n",*a,*b);
}

int main(){
	float x=1,y=1.5;
	printf("%f\t%f\n",x,y);
	swap(&x,&y);
	printf("%f\t%f\n",x,y);
	return 0;
}
