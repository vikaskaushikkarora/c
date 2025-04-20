//#include<stdlib.h>
//#include<math.h>
//#include<time.h>

// use srand(time(0)) for the random seed for rand()
// use srand48(time(0)) for the random seed for drand48()

//Unifrom long interger in a range 
long rI(long lowerLimit, long upperLimit){
	return lowerLimit + (rand()%(upperLimit-lowerLimit+1));
}

//Unifrom double in a range
double rU(double lowerLimit, double upperLimit){
	return lowerLimit + (upperLimit-lowerLimit)*drand48();
}

//Gaussian double
double rG(double mu, double s){
	double u = drand48();
	double v = drand48();
	return s*(sqrt(-2*log(u))*sin(2*M_PI*v))+mu;
}

//Poisson Double
double rE(double lambda){
	double a = drand48();
	return -log(1-a)/lambda;
}

//Get a double from a given array with corresponding weight distribution
double* getDisbn(double* arr, double* weightArr, long res, long num){
	// res : resolution and the number in the arr and weight arr, num : number of random doubles to get
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
		random=drand48();
		for(long j=0;j<res;j++){
			if((random-cumWeight[j]) <= 0){
				out[i]=arr[j];
				break;
			}
		}
	}
	return out;
}
