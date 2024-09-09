#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX 10010
#define TRUE 1
#define FALSE 0

long long *coef;
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
	int highestDegree = -1;
	int i, j;
	for(i= n; (i>=0) && (highestDegree < 0); i--){
		if(coef[i] != 0) highestDegree = i;
	}
	if(highestDegree < 0){
		printf("0\n");
		return 0;
	}
	
	printf("%lld", coef[0]);
	for(i=1; i<=highestDegree; i++){
		printf(" %lld", coef[i]);
	}	
	printf("\n");
	return 0;
}

int main(){
	int i;
	FILE *fp ;
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	coef = (long long *) malloc(sizeof(long long)*MAX);
	
	while(2 == fscanf(fp, "%d %d", &n, &k)){
		if((n==-1) && (k == -1)){
			break;
		}
		
		for(i=0; i<=n; i++){
			fscanf(fp, "%lld", coef + i);
		}
		if(n >= k){
			solve();
		}
		printRemainder();
	}
	free(coef);
	
	return 0;
}