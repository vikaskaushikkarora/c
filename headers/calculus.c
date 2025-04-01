#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// Differentiation of a function
double diff(double (*func)(double), double x, double h){
	return (func(x+h)-func(x))/h; 
}

// Integration of a function
double intg(double (*func)(double), double initial, double final, long n){
	double I=0,x=initial;
	double h=(final-initial)/n;
	for(long i=0;i<n;i++){
		I=I+h*func(x);
		x=x+h;
	}
	return I;
}

// Integration of a function given in the form of an array
double integrate(double* variable, double* integrand, long n){
	double h=variable[1]-variable[0];
	double sum=0;
	for(long i=0;i<n;i++){
		sum += h*integrand[i];
	}
	return sum;
}

// Convolution of two functions 
float convolution(float (*func1)(float), float (*func2)(float), float initial, float final, int n, float t){
	float I=0,x=initial;
	float h=(final-initial)/n;
	for(int i=0;i<n;i++){
		I=I+h*func1(x)*func2(t-x);
		x=x+h;
	}
	return I;
}

// Convolution of two arrays of the same size
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

