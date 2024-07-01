#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(int argc,char* argv[]){
	
	float number = -13.6;
	void* pointer = &number;
	//printf("%d\n",*pointer);
	//uncomment the above line and run the code to see the error !
	printf("void pointer's value : %d\nit's memory address : %d\nvalue at the memory location it points to is : %f\n\n",pointer,&pointer,*(float *)pointer);
	
	float* pointer1 = pointer+1;
	printf("float pointer's value : %d\nit's memory address : %d\nvalue at the memory location it points to is : %f\n\n",pointer1,&pointer1,*(float *)pointer1);
	// by definition the size of void pointer is 1 byte; compare the values of pointer1 and pointer
	
	// anorth void pointer
	void* pointer2 = pointer1+1;
	printf("pointer2's value : %d\nit's memory address : %d\nvalue at the memory location it points to is : %f\n\n",pointer2,&pointer2,*(float *)pointer2);
	// by definition the size of float is 4 bytes; compare the values of pointer1 and pointer2
	
	return 0;
}
