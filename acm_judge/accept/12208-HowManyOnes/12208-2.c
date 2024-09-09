#include <stdio.h>
#define DEBUG 0
#define MAX 11001
#define LOW 0
#define HIGH 1

long long input[MAX][2];
long long period[32], half[32];

long long calcOnes(long long n){
	long long result = 0;
	long long nPeriod, nRemain;
	long long m = n + 1;
	int i = 0;
	
	
	do {
		nPeriod = m / period[i];	
		nRemain = m % period[i];

		result += half[i] * nPeriod ;
		if(nRemain > half[i]){
			result = result + nRemain - half[i] ;
		}		
		i++;
	} while(period[i] < m);
	
	if(m > half[i]){
		result += m - half[i];
	}
	
	return result;
}

int main(){
	long long low, high;
	int nInput = 0;
	int k = 1, i;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	for(i=0; i<32; i++){
		period[i] = (1L << (i+1));
		half[i] = 1L << i;
	}
	
	
	while(2 == fscanf(fp, "%lld %lld", &input[nInput][LOW], &input[nInput][HIGH])){
		if((0 == input[nInput][LOW]) && (0 == input[nInput][HIGH])) break;
		else nInput++;
	}
	
	for(i=0; i<nInput; i++){
		if(input[i][LOW] == 0){
			printf("Case %d: %lld\n", k++, calcOnes(input[i][HIGH]));
		} else {
			printf("Case %d: %lld\n", k++, calcOnes(input[i][HIGH]) - calcOnes(input[i][LOW] - 1));
		}
	} 
	
	return 0;
}
