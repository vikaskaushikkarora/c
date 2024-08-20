#include<pthread.h>
#define NUM (long) 1e9 // 1e10 takes half minute approximately ...
#define NTHREADS (int) 8

void* routine(void* x){
	int a = 0;
	// Uncomment the while loop for infinte time
	/*
	while(1<2){
		a += 1;	
	}
	*/
	for(long i=0;i<NUM;i++){
		a += 1;
	}
	return NULL;
}

int main(){
	pthread_t threads[NTHREADS];
	for(int i=0;i<NTHREADS;i++){
		pthread_create(threads+i,NULL,&routine,NULL);
	}
	for(int i=0;i<NTHREADS;i++){
		pthread_join(threads[i],NULL);
	}
	return 0;
}
