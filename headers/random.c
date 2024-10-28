#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M_PI 3.14159265358979323846

//Unifrom Interger in a range 
int rI(int lowerLimit, int upperLimit){
	int a = lowerLimit + (rand()%(upperLimit-lowerLimit+1));
	return a;
}

//Unifrom Double in a range
double rU(double lowerLimit, double upperLimit){
	double a = lowerLimit + (upperLimit-lowerLimit)*rand()/(RAND_MAX);
	return a;
}

//Gaussian Distribution Float
double rG(double mu, double s){
	double u = (rand()+1.0)/(RAND_MAX+1.0);
	double v = (rand()+1.0)/(RAND_MAX+1.0);
	double x = s*(sqrt(-2*log(u))*sin(2*M_PI*v))+mu;
	return x;
}

//Poisson Distribution Double
double rE(double lambda){
	double a = rand()/(RAND_MAX +1.0);
	return -log(1-a)/lambda;
}

//Get a double from a given array with corresponding weight distribution
double* getDisbn(double* arr, double* weightArr, long res, long num){
	// res : resolution , num : number of random doubles to get
	double* out = malloc(num*sizeof(double)); // output array
	double* cumWeight = malloc(res*sizeof(double)); // cumulative weight array
	double random,sum=0,h=arr[1]-arr[0];
	for(long i=0;i<res;i++){
		sum += h*weightArr[i];
		cumWeight[i] = sum;
	}
	for(long i=0;i<res;i++){ // normallises the cumulative weight array
		cumWeight[i] /= sum;
	}
	for(long i=0;i<num;i++){
		random=rand()*pow(RAND_MAX,-1);
		for(long j=0;j<res;j++){
			if((random-cumWeight[j]) <= 0){
				out[i]=arr[j];
				break;
			}
		}
	}
	return out;
}
