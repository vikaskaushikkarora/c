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

// Convolution of two functions 
float convolutionFunc(float (*func1)(float), float (*func2)(float), float initial, float final, int n, float t){
	float I=0,x=initial;
	float h=(final-initial)/n;
	for(int i=0;i<n;i++){
		I=I+h*func1(x)*func2(t-x);
		x=x+h;
	}
	return I;
}
