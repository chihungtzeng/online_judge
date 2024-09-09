#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX 10010
#define TRUE 1
#define FALSE 0

int *coef;
int n, k;

int solve(){
	int i;
	for(i=n; i>=k; i--){
		coef[i-k] = coef[i - k] - coef[i];
		coef[i] = 0;
	}
	return 0;
}
int printRemainder(){
	int highestDegree = 0;
	int i, j;
	for(i= n; (i>=0) && (!highestDegree); i--){
		if(coef[i] != 0) highestDegree = i;
	}
	
	
	printf("%d", coef[0]);
	for(i=1; i<=highestDegree; i++){
		printf(" %d", coef[i]);
	}	
	printf("\n");
	return 0;
}

int main(){
	int i;
	FILE *fp = stdin;
	
	coef = (int *) malloc(sizeof(int)*MAX);
	
	while(2 == fscanf(fp, "%d %d", &n, &k)){
		if((n==-1) && (k == -1)){
			break;
		}
		
		for(i=0; i<=n; i++){
			fscanf(fp, "%d", coef + i);
		}
		if(n >= k){
			solve();
		}
		printRemainder();
	}
	free(coef);
	
	return 0;
}