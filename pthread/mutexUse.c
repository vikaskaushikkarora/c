#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

#define NTHREADS 10
pthread_mutex_t lock;
long int count=0;

void *routine(void *x){
	int index = (*((int *)x));
	printf("%d\n",index);
	pthread_mutex_lock(&lock);
	for(int j=0;j<index;j++){
		count++;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(){
	pthread_t threads[NTHREADS];
	pthread_mutex_init(&lock, NULL);
	int arr[NTHREADS];
	
	for(int i=0;i<NTHREADS;i++){
		arr[i]=100000000;
		pthread_create(threads+i,NULL,routine,&arr[i]);
	}
	
	for(short i=0;i<NTHREADS;i++){
		pthread_join(threads[i],NULL);
	}
	pthread_mutex_destroy(&lock);
	printf("The value of count is : %ld\n",count);
	
	return 0;
}
