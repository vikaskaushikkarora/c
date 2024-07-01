#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct reqd{
	long columns;
	long rows;
	double** arrOfArr;
};

// Creating function for getting the entries of the file in a 2D array
struct reqd getArr(char* filename){
	struct reqd s;
	s.columns=1;
	s.rows=0;
	// Getting number of columns
	FILE* fptrC = fopen(filename,"r");
	int c;
	while((c=fgetc(fptrC)) != -1){
		if(c == ' '){
			s.columns++;
		}else if(c == '\n'){
			break;
		}
	}
	fclose(fptrC);
	// Getting number of rows
	FILE* fptrR = fopen(filename,"r");
	while((c=fgetc(fptrR)) != -1){
		if(c == '\n'){
			s.rows++;
		}
	}
	fclose(fptrR);

	s.arrOfArr = malloc(s.columns*sizeof(double*));
	for(long i=0;i<s.columns;i++){
		s.arrOfArr[i]=malloc(s.rows*sizeof(double));
	}

	// Getting Array entries
	FILE* fptr = fopen(filename,"r");
	for(long j=0;j<s.columns-1;j++){
		fscanf(fptr,"%lf ",s.arrOfArr[j]);
	}
	fscanf(fptr,"%lf\n",s.arrOfArr[s.columns-1]);
	for(long i=1;i<s.rows;i++){
		for(long j=0;j<s.columns-1;j++){
			fscanf(fptr,"  %lf",s.arrOfArr[j]+i);
		}
		fscanf(fptr,"%lf\n",s.arrOfArr[s.columns-1]+i);
	}
	fclose(fptr);
	return s;
}

int main(){
	
	char filename[50]="data";
	struct reqd s = getArr(filename);

	for(long i=0;i<s.rows;i++){
		for(long j=0;j<s.columns-1;j++){
			printf("%lf ",*(s.arrOfArr[j]+i));
		}
		printf("%lf\n",*(s.arrOfArr[s.columns-1]+i));
	}
	printf("Columns : %ld ; Rows : %ld\n",s.columns,s.rows);

	for(long j=0;j<s.columns;j++){
		free(s.arrOfArr[j]);
	}
	free(s.arrOfArr);
	return 0;
}
