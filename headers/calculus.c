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
