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

//Unifrom double in a range
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
