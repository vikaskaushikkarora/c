//#include<stdio.h>
//#include<math.h>

// Printing the long int array
void printIntArr(long* arr, long N){
	for(long i=0;i<N;i++){
		printf("%ld\n",arr[i]);
	}
}

// Printing the double array
void printDoubleArr(double* arr, long N){
	for(long i=0;i<N;i++){
		printf("%lf\n",arr[i]);
	}
}

// Linspace implementation for C
void linspace(double* arr, long n, double initial, double final){
	double h=(final-initial)/n;
	for(long i=0;i<n;i++){
		arr[i]=initial+h*i;
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

// Integrating an array with respect to a given array for x-variable
double integrate(double* variable, double* integrand, long n){
	double h=variable[1]-variable[0];
	double sum=0;
	for(long i=0;i<(n-1);i++){
		sum += h*integrand[i];
	}
	return sum;
}

// Integrating an array with respect to a given array for x-variable when stepsize is not uniform
double Integrate(double* variable, double* integrand, long n){
	double sum=0;
	for(long i=0;i<(n-1);i++){
		sum += integrand[i]*(variable[i+1]-variable[i]);
	}
	return sum;
}

// Normallising an array with respect to a given array for x-variable
void normallise(double* variable, double* array, long n){
	for(long i=0;i<n;i++){
		array[i] /= integrate(variable,array,n);
	}
}

// Normallising an array with respect to a given array for x-variable when stepsize is not uniform
void Normallise(double* variable, double* array, long n){
	for(long i=0;i<n;i++){
		array[i] /= Integrate(variable,array,n);
	}
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
