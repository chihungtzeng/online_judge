#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1000001

char prime[LEN];

void buildPrime(){
	int i, j;
	memset(prime, 1, sizeof(char)*LEN);
	prime[0] = 0;
	prime[1] = 0;
	for(i=2; i<LEN; i++){
		if(prime[i]){
			for(j= i << 1; j < LEN; j += i){
				prime[j] = 0;
			} 
		}
	}
}

int intReverse(int n){
	int result = 0, r;
	while(n > 0){
		r = n % 10;
		result = (result << 3) + (result << 1) + r;
		n = n / 10;
	}
	return result;
}

int main(){
	int n, m;
	buildPrime();
	#if 0
	for(n = 0; n<550; n++){
		if(prime[n]){
			printf("%d ", n);
		}
	}
	#endif
	while(1 == scanf("%d", &n)){
		if(prime[n] == 0){
			printf("%d is not prime.\n",n);
		} else{
			m = intReverse(n);
			if ((prime[m] == 0) || (n == m)){
				printf("%d is prime.\n", n);
			} else {
				printf("%d is emirp.\n", n);
			}
		} 
	}
	return 0;
}