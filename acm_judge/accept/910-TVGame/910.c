#include <stdio.h>
#include <string.h>
#define MAXDIM 27

int dim, m;
long matrix[MAXDIM][MAXDIM];
long result[MAXDIM][MAXDIM];
short finalState[MAXDIM];


void mbym(long result[MAXDIM][MAXDIM], long m1[MAXDIM][MAXDIM], long m2[MAXDIM][MAXDIM]){
	int i, j, k;
	memset(result, 0, sizeof(long)*MAXDIM*MAXDIM);
	for(i=0; i<dim;i++){
		for(j=0;j<dim;j++){
			for(k=0;k<dim;k++){
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void powMatrix(long result[MAXDIM][MAXDIM], long m1[MAXDIM][MAXDIM], int m){
	long temp[MAXDIM][MAXDIM];
	if (m == 1){
		memcpy(result, m1, sizeof(long)*MAXDIM*MAXDIM);
		return ;
	}
	
	powMatrix(temp, m1, m/2);
	mbym(result, temp, temp);
	if(m % 2 == 1){
		memcpy(temp, result, sizeof(long)*MAXDIM*MAXDIM);
		mbym(result, temp, m1);
	}
}  

int main(){
	char start[2], end1[2], end2[2];
	char special[2];
	long ans;
	int i, j;

	while ( 1 == scanf("%d",&dim)){
		memset(finalState, 0, sizeof(short)*MAXDIM);
		memset(matrix, 0, sizeof(long)*MAXDIM*MAXDIM);
		for(i=0; i < dim; i++){
			scanf("%s %s %s %s", start, end1, end2, special);			
			matrix[start[0] - 'A'][end1[0] - 'A'] += 1;
			matrix[start[0] - 'A'][end2[0] - 'A'] += 1;
			if(special[0] == 'x'){
				finalState[start[0] - 'A'] = 1;
			}
			
		}
		scanf("%d", &m);
		if(m == 0){
			if(finalState[0] == 1){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
			continue;
		}
		powMatrix(result, matrix, m);
		ans = 0;

		for(i=0;i<dim;i++){
			if(finalState[i] == 1){
				ans += result[0][i];
			}
		}
		
			printf("%ld\n",ans);
	}
	return 0;
}