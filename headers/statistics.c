//#include<stdio.h>
//#include<math.h>

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
	if(count>0){
		printf("Number of such entries is : %ld\n",count);
	}
	//Normallising the histogram
	for(long i=0;i<sizeBin;i++){
		output[i] /= (net*h);
	}
}

//Mean, Standard Deviation, Skewness and Kurtosis for a given array
void stat(double* arr, long n, double* reqdArr){
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
	double kurtosis=0;
	for(long i=0;i<n;i++){
		kurtosis += pow((arr[i]-mean),4);
	}
	kurtosis /= n*pow(std,4);
	reqdArr[0]=mean;
	reqdArr[1]=std;
	reqdArr[2]=skewness;
	reqdArr[3]=kurtosis;
}

// Linear Fit and Pearson Coefficient for a given array
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

//Mean, Standard Deviation, Skewness and Kurtosis for a distribution given in the form of an array
void statDisbn(double* x, double* disbnX, long n, double* statArr){
	double mean=0,var=0,skewness=0,kurtosis=0;
	double check=0,h=x[1]-x[0];
	for(long i=0;i<n;i++){
		mean += x[i]*disbnX[i]*h;
		check += disbnX[i]*h;
	}
	printf("%lf\n",check); // prints 1 for normallised distribution with closely spaced points
	for(long i=0;i<n;i++){
		var += pow(x[i]-mean,2)*disbnX[i]*h;
	}
	double std=sqrt(var);
	for(long i=0;i<n;i++){
		skewness += pow(x[i]-mean,3)*disbnX[i]*h;
		kurtosis += pow(x[i]-mean,4)*disbnX[i]*h;
	}
	skewness /= pow(std,3);
	kurtosis /= pow(std,4);
	statArr[0]=mean;
	statArr[1]=std;
	statArr[2]=skewness;
	statArr[3]=kurtosis;
}
