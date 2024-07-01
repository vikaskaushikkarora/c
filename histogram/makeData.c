#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define M_PI 3.14159265358979323846
#define NUM (long) 1e2
#define MU 1.0
#define STD 0.1

int main(){
	srand(time(0));
	FILE* fptr = fopen("data","w");
	long count = 0;
	double u,v,x;
	for(long i=0;i<NUM;i++){
		u = (rand()+1.0)/(RAND_MAX+1.0);
		v = (rand()+1.0)/(RAND_MAX+1.0);
		x = STD*(sqrt(-2*log(u))*sin(2*M_PI*v))+MU;
		if(x<=0 || x>= 2){
			printf("x : %0.15lf ; u : %0.15lf ; v : %0.15lf\n",x,u,v);
			count++;
		}else{
			fprintf(fptr,"%lf\n",x);
		}
	}
	fclose(fptr);
	printf("Number of such analomous instances is %ld\n",count);
	return 0;
}
