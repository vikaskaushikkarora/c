#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

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


// Function for calculating Mean, Standard Deviation, Skewness and Kurtosis
double* statistics(double* arr, long n, double* reqdArr){
	double mean=0;
	for(long i=0;i<n;i++){
		mean += arr[i];
	}
	mean /= n;
	double var=0;
	for(long i=0;i<n;i++){
		var += pow((arr[i]-mean),2);
	}
	var /= n;
	double std = sqrt(var);
	double skewness = 0;
	for(long i=0;i<n;i++){
		skewness += pow((arr[i]-mean),3);
	}
	skewness /= n*pow(std,3);
	double excessKurtosis=0;
	for(long i=0;i<n;i++){
		excessKurtosis += pow((arr[i]-mean),4);
	}
	excessKurtosis /= n*pow(std,4);
	reqdArr[0]=mean;
	reqdArr[1]=std;
	reqdArr[2]=skewness;
	reqdArr[3]=excessKurtosis;
	return reqdArr;
}
