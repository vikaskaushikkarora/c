#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH (long) 1e7

// Function for checking a palindrome =====================================================================================================================
long checkForPalindrome(char* name){
	long c,val=0,lenName = strlen(name);

	if((lenName%2) == 0){
		c=lenName/2;
		for(long i=0;i<c;i++){
			if(name[c+i] != name[c-i-1]){
				printf("%ld th letter is different than %ld th letter.\n",c+i,c-i-1);
				val=1;
				break;
			}
		}
	}else{
		c = (lenName-1)/2;
		for(long i=1;i<c+1;i++){
			if(name[c+i] != name[c-i]){
				printf("%ld th letter is different than %ld th letter.\n",c+i,c-i);
				val=1;
				break;
			}
		}
	}	
	return val;
}

// ========================================================================================================================================================
int main(){
	char* name = malloc(MAXLENGTH*sizeof(char));
	printf("Enter the word (all small or all capital letters): ");
	scanf("%s",name);
	//sprintf(name,"madam");
	
	long val = checkForPalindrome(name);
	if(val == 0){
		printf("Yes, \"%s\" is a palindrome.",name);
	}else{
		printf("\"%s\" is not a palindrome.",name);
	}
	
	free(name);
	return 0;
}
