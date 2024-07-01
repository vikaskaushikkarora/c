#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
	srand(time(0));
	short int flag=0;
	int score=0;
	int level=1;
	int a=0;
	float f;
	int i;
	int sqr;
	printf("Welcome to Level 1 of the game .\nLet us play .\n");
	while(flag == 0){
		int b=pow(5*level,1.2);
		while(a<b){
			f=(float) rand()/RAND_MAX;
			i=10*level*f;
			a=a+1;
			printf("\nWhat is the square of  %d :\n",i);
			scanf("%d",&sqr);
			if( sqr != i*i ){
				printf("\nYou lose bro !\nThe square of %d is %d .\n\nYour Score is %d \nBetter luck next time .\n\n",i,i*i,score);
				flag = 1;
				break ;	
			}
			score=score+b;
			printf("Correct answer !\nYour Score is : %d\n",score);
		}
		if(flag == 0){
			printf("\n======================================================\nYou have cleared Level %d \nWelcome to Level %d\n======================================================\n",level,level+1);
			level=level+1;
		}
	}	
	return 0;
}
