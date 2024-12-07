#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


// Linspace implementation for C
void linspace(double* arr, long n, double initial, double final){
	double h=(final-initial)/n;
	for(long i=0;i<n;i++){
		arr[i]=initial+h*i;
	}
}

// Integrating an array with respect to a given array for x-variable
double integrate(double* variable, double* integrand, long n){
	double h=variable[1]-variable[0];
	double sum=0;
	for(long i=0;i<n;i++){
		sum += h*integrand[i];
	}
	return sum;
}

// Normallising an array with respect to a given array for x-variable
void normallise(double* variable, double* array, long n){
	double h=variable[1]-variable[0];
	double sum=0;
	for(long i=0;i<n;i++){
		sum += h*array[i];
	}
	for(long i=0;i<n;i++){
		array[i] /= sum;
	}
}

// Writting down the components of arrays in a data file
void writeData(double* arr1, double* arr2, long n, char* filename){
	FILE* fp = fopen(filename,"w");
	for(long i=0;i<n;i++){
		fprintf(fp,"%lf %lf\n",arr1[i],arr2[i]);
	}
	fclose(fp);
}

// Convolution of two arrays with the same size
void convolution(double* arr1, double* arr2, long n, double* conv){
	for(long i=0;i<n;i++){
		conv[i]=0;
		for(long j=0;j<=i;j++){
			conv[i] += arr1[j]*arr2[i-j];
		}
	}
	for(long i=n;i<(2*n-1);i++){
		conv[i]=0;
		for(long j=i;j<(2*n-1);j++){
			conv[i] += arr1[j-n+1]*arr2[n+i-j-1];
		}
	}
}

