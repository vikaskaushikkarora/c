#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//===You can define these required functions in a seperate file====
float change(float *x, float* y){
	float temp = *x;
	*x=*y;
	*y=temp;
}

struct class{
	float a;
	float b;
	float (*change)(float* ,float*);
};

int main(int argc,char* argv[]){
	struct class myClass={1.1,2.2,change};
	myClass.change(&(myClass.a),&(myClass.b));
	myClass.change(&(myClass.a),&(myClass.b));
	printf("%f\t%f\n",myClass.a,myClass.b);
	return 0;
}
