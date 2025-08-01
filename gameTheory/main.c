#include"reqd.c"
#include"strategies.c"

int main(){
	srand(time(0));
	FILE* fptr;
	fptr=fopen("/home/vikas/work/data.txt","w");
	
	int N=100;
	int scoreA=0,scoreB=0;
	int* strategyA = malloc(N*sizeof(int));
	int* strategyB = malloc(N*sizeof(int));

	strategyA[0]=-1+2*(rand()%2);
	strategyB[0]=-1+2*(rand()%2);
	scoreA=scoreA+score(strategyA[0],strategyB[0]);
	scoreB=scoreB+score(strategyB[0],strategyA[0]);
	fprintf(fptr,"%d\t%d\t%d\t%d\t0\n",scoreA,scoreB,strategyA[0],strategyB[0]);

	for(int i=1;i<N;i++){
		strategyA[i]=playerA(i,strategyA,strategyB);
		strategyB[i]=playerB(i,strategyB,strategyA);
		scoreA=scoreA+score(strategyA[i],strategyB[i]);
		scoreB=scoreB+score(strategyB[i],strategyA[i]);
		fprintf(fptr,"%d\t%d\t%d\t%d\t%d\n",scoreA,scoreB,strategyA[i],strategyB[i],i);
	}
	fclose(fptr);
	return 0;
}
