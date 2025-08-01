#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

#define NTHREADS (int) 6 // Standard Value of number of threads to produce heat from, if not given manually
#define HOURS (double) 8 // Standard number of hours to use the computer as a heater, if not given manually

// Define a structure ======================================================
struct reqd{
	int nthreads;
	double hours;
};

// Routine Function =========================================================
void* routine(void* x){
	time_t t1 = clock();
	time_t t2;
	double time_elapsed;
	double total_time = (((struct reqd*)x)->nthreads)*(((struct reqd*)x)->hours)*60*60;
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
int main(int argc, char* argv[]){
	struct reqd r;
	
	if(argc==3){
		r.nthreads=atoi(argv[1]);
		sscanf(argv[2],"%lf",&r.hours);
	}else{
		r.nthreads=NTHREADS;
		r.hours=HOURS;
	}
	
	pthread_t threads[r.nthreads];
	for(int i=0;i<r.nthreads;i++){
		pthread_create(threads+i,NULL,&routine,&r);
	}
	for(int i=0;i<r.nthreads;i++){
		pthread_join(threads[i],NULL);
	}
	
	return 0;
}
