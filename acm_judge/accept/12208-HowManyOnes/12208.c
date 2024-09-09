#include <stdio.h>
#define DEBUG 0

long long calcOnes(long long n){
	long long result = 0;
	long long period, nPeriod, nRemain;
	long long m = n + 1;
	long long half;
	
	
	period = 2;
	half = 1;	
	
	do {
		nPeriod = m / period;	
		nRemain = m % period;

		result += half * nPeriod ;
		if(nRemain > half){
			result = result + nRemain - half ;
		}		
		half = period;
		period = (period << 1);
	} while(period < m);
	
	if(m > half){
		result += m - half;
	}
	
	return result;
}

int main(){
	long long low, high;
	int k = 1;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;

	#if 0
	for(low = 0; low <= 12; low++){
		printf("%d : %d\n", low, calcOnes(low));
	}
	#endif
	
	#if 1
	while(2 == fscanf(fp, "%lld %lld", &low, &high)){
		if((0 == low) && (0 == high)) break;
		
		if(low == 0){
			printf("Case %d: %lld\n", k++, calcOnes(high));
		} 
		else {	
			printf("Case %d: %lld\n", k++, calcOnes(high) - calcOnes(low - 1));
		}
	}
	#endif
	return 0;
}
