// Programme to change array contents using pthreads

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#define NTHREADS 10

// Define a structure required for passing arguments to pthread_create 
struct reqd{
	int th; // thread index
	int N; // array size
	int *pa; // pointer to the array
};

// Define a function which performs the task
void *routine(void *x){
	int th=((struct reqd*)x)->th;
	int N=(((struct reqd*)x)->N)/NTHREADS;
	int j;
	for(int k=0;k<N;k++){
		j=k*NTHREADS+th;
		*((((struct reqd*)x)->pa)+j)=j*j;
	}
	return NULL;
}

int main(){
	int N=100,*arr=malloc(N*sizeof(int)); // define the array
	
	// Define a reqd type structure array and pass the array and thread indices etc.
	struct reqd r[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		r[i].th=i;
		r[i].N=N;
		r[i].pa=arr;
	}
	
	// Parallel Processing Code
	pthread_t threads[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		pthread_create(threads+i,NULL,&routine,&r[i]);
	}
	for(int i=0;i<NTHREADS;i++){
		pthread_join(threads[i],NULL);
	}

	// Print the array contents
	for(int i=0;i<N;i++){
		printf("%d\n",*(arr+i));
	}
	
	return 0;
}
