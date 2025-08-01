#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// calculating score of the player
int score(int a,int b){ // a=own strategy, b=opposition's strategy
	if(a==1 && b==1){
		return 2;
	} else if(a==1 && b==-1){
		return -1;
	} else if(a==-1 && b==1){
		return 1;
	} else if(a==-1 && b==-1){
		return -2;
	} else{
		return 0;
	}
}

