#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
#define DEBUG 0

int main(){	
	unsigned long int **prefix;
	int N, M;
	unsigned long int sum, cur;
	int i,j;
	FILE *fp;
	short first=1;
	short tmp;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}

	prefix = (unsigned long **) malloc(sizeof(unsigned long *)*MAX);
	for(i=0;i<MAX;i++){
		prefix[i] = (unsigned long *) malloc(sizeof(unsigned long)*MAX);
	}
	
	for(i=0;i<MAX;i++){
		prefix[0][i] = 0;
		prefix[i][0] = 0;
	}
	
	
	while(2 == fscanf(fp, "%d %d", &N, &M)){
		if(!first){
			printf("\n");
		}
		else{
			first = 0;
		}
		for(i=N;i>=1;i--){
			for(j=1; j<=N;j++){
				fscanf(fp, "%hd",&tmp);
				prefix[i][j] = prefix[i][j-1] + tmp;
			}
		}

		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				prefix[i][j] = prefix[i][j] + prefix[i-1][j]; 
			}
		}

		sum = 0;
		
		for(i=N; i>=M; i--){
			for(j=M; j<=N; j++){
				cur = prefix[i][j] - prefix[i-M][j] - prefix[i][j-M] + prefix[i-M][j-M];
				printf("%ld\n",cur);
				sum += cur;
			}
		}
		printf("%ld\n",sum);
	}
	
	
	return 0;
}