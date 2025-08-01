#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define sizeArr 2e8

int main(int argc,char* argv[]){
	double time = clock();
	
	// Block of Code ==================================================
	int *arr = malloc(sizeArr*sizeof(int));
	for(int i=0;i<sizeArr;i++){
		arr[i]=i;
	}
	//=================================================================
	
	time -= clock();
	time /= -CLOCKS_PER_SEC;
	printf("Time taken for execution : %lf seconds\n",time);
	return 0;
}
