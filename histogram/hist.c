#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

long sizeInput=0; // Input Array Size
#define BIN 200 // Bin Array Size
double* input; // Input Array
double* bin; // Bin Array
double* output; // Output Array

// Creating a function for plotting histograms
void hist(double *input, long sizeInput, double *bin, double *output, long sizeBin){
	long temp, net=0;
	double h = bin[1]-bin[0], hInv = 1/h;
	for(long i=0;i<sizeBin;i++){
		output[i]=0;
	}
	for(long j=0;j<sizeInput;j++){
		temp=(input[j]-bin[0]+0.000001)*hInv;
		//printf("%lf\t%ld\n",input[j],temp);
		if(temp>=0 && temp<sizeBin){
			net++;
			output[temp] += 1;
		}else{
			printf("out of range data : %lf\n",input[j]);
		}
	}
	//Normallising the histogram
	for(long i=0;i<sizeBin;i++){
		output[i] /= (net*h);
	}
}

struct reqd{
	long size;
	double* array;
};

// Creating function for getting the entries of the file in array
struct reqd getArr(char* filename){
	struct reqd s;
	s.size=0;
	// Getting the size of the array
	FILE* fptrS = fopen(filename,"r");
	int c;
	while((c=fgetc(fptrS)) != -1){
		if(c == '\n'){
			s.size++;
		}
	}
	fclose(fptrS);
	
	// Getting Array entries
	s.array = malloc(s.size*sizeof(double));
	FILE* fptr = fopen(filename,"r");
	for(long i=0;i<s.size;i++){
		fscanf(fptr,"%lf\n",s.array+i);
	}
	fclose(fptr);
	return s;
}

int main(){
	
	char filename[50]="data";
	struct reqd s = getArr(filename);

	// Specifying bin details
	bin = malloc(BIN*sizeof(double));
	output = malloc(BIN*sizeof(double));
	for(long i=0;i<BIN;i++){
		bin[i]=0.01*i;
	}
	// Making Histograms
	hist(s.array,s.size,bin,output,BIN);
	FILE* fptrH = fopen("dataH","w");
	for(long i=0;i<BIN;i++){
		fprintf(fptrH,"%lf %lf\n",bin[i],output[i]); // wrtting bin and histogram outputs
	}
	fclose(fptrH);
	
	free(s.array);
	free(bin);
	free(output);
	return 0;
}
