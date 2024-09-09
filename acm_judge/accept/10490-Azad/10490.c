#include <stdio.h>
#define PERFECT 1
#define PRIME_NON_PERFECT -2
#define COMPOSITE -1
#define LEN 32

long long perfect[LEN];

void initTable(){
	short i, j;
	short prime[] = {1, 2, 3, 5, 7, 13, 17, 19, 31};
	short nPrime = 9;
	long long tmp[2];
	for(i=0; i<LEN; i++){
		perfect[i] = COMPOSITE;
	}
	for(i=0; i<nPrime; i++){
		j = prime[i];
		tmp[0] = 1 << (j - 1);
		tmp[1] = (1 << j) - 1;
		perfect[j] = tmp[0] * tmp[1];
	}
	perfect[11] = PRIME_NON_PERFECT;
	perfect[23] = PRIME_NON_PERFECT;
	perfect[29] = PRIME_NON_PERFECT;
}

int main(){
	initTable();
	char n;
	while(1 == scanf("%hhd", &n)){
		if(n == 0) return 0;
		if(perfect[n] > 0){
			printf("Perfect: %lld!\n", perfect[n]);
		} else if (perfect[n] == COMPOSITE){
			puts("Given number is NOT prime! NO perfect number is available.");
		} else {
			puts("Given number is prime. But, NO perfect number is available.");
		}
	}
	return 0;
} 