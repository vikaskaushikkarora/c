#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// Convolution
float convolution(float (*func1)(float), float (*func2)(float), float initial, float final, int n, float t){
	float I=0,x=initial;
	float h=(final-initial)/n;
	for(int i=0;i<n;i++){
		I=I+h*func1(x)*func2(t-x);
		x=x+h;
	}
	return I;
}

// A function for plotting histograms
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

// Get mean and standard deviation
void meanStd(double* x, int size, double* pmean, double* pstd){ // pmean = pointer to mean
	double squareMean=0;
	*pmean=0;
	for(int i=0;i<size;i++){
		*pmean += x[i];
		squareMean += x[i]*x[i];
	}
	*pmean /= size;
	squareMean /= size;
	*pstd=pow((squareMean - (*pmean)*(*pmean)),0.5);
}
