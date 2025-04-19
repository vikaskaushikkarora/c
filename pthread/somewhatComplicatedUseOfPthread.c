#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#define NTHREADS (int) 10
#define RES (long) 1e3

double f(double a){
	return a*a;
}

struct reqd{
	int th; // thread index
	long res; // resolution
	double* input; // input array
	double* output; // output array
	double (*func)(double); // integral func
};

void *routine(void *x){
	int th=((struct reqd*)x)->th;
	long res=((struct reqd*)x)->res;
	long initial=(th/NTHREADS)*res;
	long final=((th+1)/NTHREADS)*res;
	for(int i=initial;i<final;i++){
		*((((struct reqd*)x)->output)+i)=((struct reqd*)x)->func(*(((((struct reqd*)x)->input)+i)));
	}
	return NULL;
}

int main(){
	double* input = malloc(RES*sizeof(double));
	double* output = malloc(RES*sizeof(double));
	for(long i=0;i<RES;i++){
		input[i]=0.01*i;
	}
	
	// Define a reqd type structure array and pass the array and thread indices etc.
	struct reqd r[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		r[i].th=i;
		r[i].res=RES;
		r[i].input=input;
		r[i].output=output;
		r[i].func=f;
	}
	
	// Parallel Processing Code
	pthread_t threads[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		pthread_create(threads+i,NULL,&routine,&r[i]);
	}
	for(int i=0;i<NTHREADS;i++){
		pthread_join(threads[i],NULL);
	}

	for(int i=0;i<RES;i++){
		printf("%f %lf\n",input[i],output[i]);
	}
	
	return 0;
}
