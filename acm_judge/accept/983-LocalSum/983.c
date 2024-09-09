#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
#define DEBUG 0

int main(){	
	short matrix[MAX][MAX];
	unsigned long int **prefix;
	int N, M;
	unsigned long int sum, cur;
	int i,j;
	FILE *fp;
	short first=1;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}

	prefix = (unsigned long **) malloc(sizeof(unsigned long *)*MAX);
	for(i=0;i<MAX;i++){
		*(prefix+i) = (unsigned long *) malloc(sizeof(unsigned long)*MAX);
		//prefix[i] = (unsigned long *) malloc(sizeof(unsigned long)*MAX);
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
				fscanf(fp, "%hd",&matrix[i][j]);
				prefix[i][j] = matrix[i][j];
			}
		}
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				prefix[i][j] = prefix[i][j] + prefix[i][j-1]; 
			}
		}
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				prefix[i][j] = prefix[i][j] + prefix[i-1][j]; 
			}
		}
		if(DEBUG){
			for(i=1;i<=N;i++){
				for(j=1;j<=N;j++){
					printf("%d ", matrix[i][j]); 
				}
				printf("\n");
			}
			for(i=1;i<=N;i++){
				for(j=1;j<=N;j++){
					printf("%ld ", prefix[i][j]); 
				}
				printf("\n");
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