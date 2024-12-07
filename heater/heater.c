#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

#define NTHREADS (int) 5 // Number of threads to produce heat from
#define HOURS (double) 0.001 // Number of hours to use the computer as a heater

// Routine Function =========================================================
void* routine(void* x){
	time_t t1 = clock();
	time_t t2;
	double time_elapsed;
	double total_time = NTHREADS*HOURS*60*60;
	int variable = 0;
	while(variable == 0){
		t2 = clock();
		time_elapsed = (t2 - t1)*pow(CLOCKS_PER_SEC,-1);
		if(time_elapsed >= total_time){
			variable = 1;
		}
	}
	return NULL;
}

// Main Function ===========================================================
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
