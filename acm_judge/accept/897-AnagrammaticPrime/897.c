#include <stdio.h>
#define N 22

int prime[] = 
{2, 3, 5, 7, 11,
13, 17, 31, 37, 71,
73, 79, 97, 113, 131,
199, 311, 337, 373, 733,
919, 991}; 


int upperBound(int n){
	if(n == 0) return 1;
	int x = 1;
	while(n > 0){
		n = n / 10;
		x = x*10;
	}
	return x;
}

int main(){
	int target;
	int idx;	
	while(1 == scanf("%d", &target)){
		if(0 == target) break;
		
		idx = 0;
		while((idx < N) && (prime[idx] <= target)) idx++;
		/*printf("idx=%d prime[idx=%d\n",idx, prime[idx]);*/
		
		if((idx < N) && (prime[idx] < upperBound(target))		){
			printf("%d\n",prime[idx]);
		}
		else{
			printf("0\n");
		}
	}

	return 0;
}