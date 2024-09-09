/*AC using Erdos and Gallai Theorem*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10010
#define UNDECIDE -1
#define IMPOSSIBLE 0
#define POSSIBLE 1
#define VERBOSE 0


int compareInt(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int min(int a, int b){
	if (a < b) return a;
	else return b;
}

short Erdos(short nVertex, int degree[]){
	short i, j, r;
	int sum[nVertex + 1];
	int minsum;	
	
	
	qsort(degree + 1, nVertex, sizeof(int), compareInt);
	
	sum[1] = degree[1];
	for(i=2; i <= nVertex; i++){
		sum[i] = degree[i] + sum[i-1];
	}
	
	if(VERBOSE){
		printf("into Erdos procedure\n");
		for(i=1; i<=nVertex; i++){
			printf("%d ", sum[i]);
		}
		printf("\n\n");
	}
	rsum = 0;
	for(r = 1; r < nVertex; r++) {
		minsum = 0;
		for(i=r+1; i<=nVertex; i++){
			minsum += min(r, degree[i]);
		}
		
		
		if(sum[r] > minsum + r*(r-1)){
		 	return IMPOSSIBLE;
		}
	}
	return POSSIBLE;
	
}


int main(){
	short nVertex, i;
	int totalDegree, degreeBound;
	short nZeroDegreeVertex, nNormalVertex;
	int degree[MAX];
	short ans;
	while(1 == scanf("%hd",&nVertex)){
		if(0 == nVertex) break;
		
		
		totalDegree = 0;
		nZeroDegreeVertex = 0;
		
		for(i = nVertex ; i>=1 ;i--){
			scanf("%d", &degree[i]);
			totalDegree += degree[i];
			if(degree[i] == 0){
				nZeroDegreeVertex += 1;
			}
		}
		nNormalVertex = nVertex - nZeroDegreeVertex;
		
		if(VERBOSE){
			printf("degree 0:%d degree >0: %d\n",nZeroDegreeVertex, nNormalVertex);
		}		
		
		ans = UNDECIDE;
		if(totalDegree % 2 == 1) ans = IMPOSSIBLE;
		for(i=1; (ans == UNDECIDE) && (i <= nVertex); i++){
			if((degree[i] < 0) || ((degree[i] > 0) && (degree[i] >= nNormalVertex))){
				ans = IMPOSSIBLE;
			}
		}
		if((nVertex == 1) && (degree[1] > 0)) ans = IMPOSSIBLE;
		if((nVertex == 1) && (degree[1] == 0)) ans = POSSIBLE;
		
		if(ans == IMPOSSIBLE){
			printf("Not possible\n");
			continue;
		}
		else if (ans == POSSIBLE){
			printf("Possible\n");
			continue;
		}
		
		
		ans = Erdos(nVertex, degree);
		
		if(ans == POSSIBLE){
			printf("Possible\n");
		}
		else if (ans == IMPOSSIBLE){
			printf("Not possible\n");
		}
		
	}
	return 0;
}
