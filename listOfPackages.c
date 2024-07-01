#include<stdio.h>
#include<stdlib.h>

int main(){
	system("echo $(sudo pacman -Qq) >packages.txt");
	char c;
	FILE* fp=fopen("packages.txt","r");
	FILE* nfp=fopen("names.txt","w");
	while(1){
		c=fgetc(fp);
		if(c=='\n'){
			break;
		}
		if(c==' '){
			fprintf(nfp,"\n");
		}
		else{
			fputc(c,nfp);
		}
	}
	fclose(fp);
	fclose(nfp);
	system("rm packages.txt");
	system("mv names.txt packageNames.txt");
}
