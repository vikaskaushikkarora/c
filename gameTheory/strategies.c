//tit for tat player
int playerA(int i, int* strategyA, int* strategyB){
	if(i<1){
		return strategyB[i-1];
	}else{
		if(strategyB[i-2]==-1 && strategyB[i-1]==-1){
			return -1;
		} else{
			return 1;
		}
	}
}

//cunning player
int playerB(int i, int* strategyB, int* strategyA){
	if(i<3){
		return strategyA[i-1];
	}else{
		int count=0;
		for(int j=i-1;j>=i-3;j=j-1){
			if(strategyA[j]==1){
				count=count+1;
			}
		}
		if(count==3){
			return -1;
		} else{
			return 1;
		}
	}
}
