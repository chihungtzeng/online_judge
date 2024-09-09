#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXDIM 100
#define DEBUG 0

void dumpMatrix(int **m,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

int find_maxsum(int **table,int up,int left,int n){
	
	int right,bottom;
	int result=-INT_MAX;
	int temp;
	for(right=left;right<=n;right++){
		for(bottom=up;bottom<=n;bottom++){
			temp = table[right][bottom] - table[right][up-1] - table[left-1][bottom] + table[left-1][up-1];
			if (temp > result){
				result=temp;
			}
		}
	}
	return result;
}


int find_answer(int **matrix, int n){

	int **table;
	int i,j,k,max,temp;
	

	table = (int **) malloc(sizeof(int *)*(n+1));

	for(i=0;i<=n;i++){
		table[i] = (int *) malloc(sizeof(int)*(n+1));
	}
	for(i=0;i<=n;i++){
		table[i][0]=0;
		table[0][i]=0;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			table[i][j] = table[i-1][j]+table[i][j-1]-table[i-1][j-1]+matrix[i][j];
		}
	}
	dumpMatrix(table,n+1);
	max=-INT_MAX;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			temp = find_maxsum(table,i,j,n);
			if(temp>max){
				max=temp;
			}
		}
	}

	return max;
}

int main(int argc, char *argv[]){
	int n,i,j;
	int **matrix;
	FILE *fp;
	int answer;
	char *line,*tmpline;
	
	fp = fopen("input.txt","r");
	if(NULL == fp){
		exit(EXIT_FAILURE);
	}
	
	line = (char *) malloc(sizeof(char)*1024);
	tmpline = (char *) malloc(sizeof(char)*1024);
	strcpy(tmpline,"");
	
	fgets(line,1024,fp);
	n = atoi(line);
	while (NULL != (fgets(line,1024,fp))){
		strcat(tmpline,line);
	}
	
	matrix = (int **) malloc(sizeof(int *)*(n+1));
	for(i=0;i<=n;i++){
		matrix[i] = (int *) malloc(sizeof(int)*(n+1));
	}
	
	for(i=0;i<=n;i++){
		matrix[i][0]=0;
		matrix[0][i]=0;
	}
	matrix[1][1] = atoi(strtok(tmpline," \n"));	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if( 1 != i*j ){
				matrix[i][j] = atoi(strtok(NULL," \n"));
			}
		}
	}
	dumpMatrix(matrix,n+1);
	free(line);
	free(tmpline);

	answer=find_answer(matrix,n);
	printf("%d\n",answer);
	fclose(fp);
}