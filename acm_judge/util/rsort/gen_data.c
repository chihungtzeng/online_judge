#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
#define RANGE 30000


int main(int argc, char *argv[]){

	FILE *fp;
	int i;

	fp = fopen("num.txt","w");
	fprintf(fp,"%d\n",MAX);
	if(argc < 10){
		srand(time(NULL));
		for(i=0;i<MAX;i++){
			fprintf(fp,"%d\n",rand() % RANGE);
		}
	}
	else{
		for(i=MAX-1;i>=0;i--){
			fprintf(fp,"%d\n", (i)%RANGE);
		}
	}
}