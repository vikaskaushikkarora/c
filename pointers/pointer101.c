#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(int argc,char* argv[]){
	// Easiest way to define a pointer
	int integer;
	integer = 10;
	int* pointer;
	pointer = &integer;
	int* pointerToInteger = &integer;
	
	printf("integer's value is : %d\nit's memory address is : %d\n\n",integer,&integer);
	printf("pointer's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",pointer,&pointer,*pointer);
	printf("pointerToInteger's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",pointerToInteger,&pointerToInteger,*pointerToInteger);
	
	// Complicated way to define a pointer : 
	int *anotherPointer = &integer;
	printf("anotherPointer's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",anotherPointer,&anotherPointer,*anotherPointer);
	
	// Some other ways to define a pointer
	int* pointer2 = pointerToInteger;
	int *pointer3 = pointerToInteger;
	printf("pointer2's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",pointer2,&pointer2,*pointer2);
	printf("pointer3's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",pointer3,&pointer3,*pointer3);
	
	// So basically, ->  varibaleType* pointerName is the best way to declare a pointer;
	// And you can initiallise it by -> pointerName = &variableName;
	// Or you can intiallise it just while declaring as :
	// varibaleType* pointerName = &variable;
	// You can also define a pointer by -> variableType *pointerName;
	// And you can initiallise it by -> pointerName = &variableName;
	// But it is quite misleading (at least for me) when you declare and initiallise a pointer at the same time by this way !
	// Now look at another way to initiallise a pointer
	
	int* pntr;
	*pntr = integer;
	 printf("pntr's value is : %d\nit's memory address is : %d\nthe value at the memory location it points to is : %d\n\n",pntr,&pntr,*pntr);
	 
	 // pntr's value should be the memory address of integer, but cross-check that they are not the same ! What is happening ? pntr had some random value initially i.e. it was pointing to some random memory location. *pntr = integer -> stored the value 10 (the value of integer) at that memory location, while it did not itself store the memory address of integer !
	
	
	return 0;
}
