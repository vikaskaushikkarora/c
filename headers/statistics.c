#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// A function for plotting histograms
void hist(double *input, long sizeInput, double *bin, double *output, long sizeBin){
	long temp, net=0,count=0;
	double h = bin[1]-bin[0], hInv = 1/h;
	for(long i=0;i<sizeBin;i++){
		output[i]=0;
	}
	for(long j=0;j<sizeInput;j++){
		temp=(input[j]-bin[0]+0.000001)*hInv;
		if(temp>=0 && temp<sizeBin){
			net++;
			output[temp] += 1;
		}else{
			count++;
			printf("out of range data : %lf\n",input[j]);
		}
	}
	printf("Number of such entries is : %ld\n",count);
	//Normallising the histogram
	for(long i=0;i<sizeBin;i++){
		output[i] /= (net*h);
	}
}

// Function for calculating Mean, Standard Deviation, Skewness and Kurtosis
void statistics(double* arr, long n, double* reqdArr){
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
}

void linearRegression(double* x, double* y, long N, double* output){
	double xbar=0;
	double ybar=0;
	double Sxy=0,Sxx=0,Syy=0;
	for(long i=0;i<N;i++){
		xbar += x[i]/N;
		ybar += y[i]/N;
	}
	for(long i=0;i<N;i++){
		Sxx += (x[i]-xbar)*(x[i]-xbar);
		Syy += (y[i]-ybar)*(y[i]-ybar);
		Sxy += (x[i]-xbar)*(y[i]-ybar); // correlation of x and y
	}
	Sxx /= N;
	Syy /= N;
	Sxy /= N;
	output[0] = Sxy/Sxx; // slope
	output[1] = ybar - output[0]*xbar; // intercept
	output[2] = Sxy/sqrt(Sxx*Syy); // pearson coefficent
}
