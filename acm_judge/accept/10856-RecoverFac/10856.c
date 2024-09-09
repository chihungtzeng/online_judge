#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2703664


int *ans;

void buildPrimeTable(){
	char *cPrime;
	int i, j, tmp;
	cPrime = (char *) malloc(sizeof(char)*MAX);
	ans = (int *) malloc(sizeof(int)*MAX);
	memset(cPrime, 1, MAX);
	memset(ans, 0, sizeof(int)*MAX);
	
	for(i=2; i<MAX; i++){
		if(cPrime[i]){
			for(j=i+i; j<MAX; j+=i){
                tmp = j;
                while( tmp % i == 0){
                    tmp = tmp / i;
                    ans[j]++;
                }
				cPrime[j] = 0;
			}
            ans[i] = ans[i-1] + 1;
		} else{
            ans[i] += ans[i - 1];
        }
	}
	free(cPrime);
}

int mybsearch(int n){
    int left, right, middle;
    left = 0;
    right = MAX - 1;
    while(left <= right){
        middle = (left + right) >> 1;
        if(ans[middle] == n) return middle;
        else if (ans[middle] < n) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main(){
	int n, k=1, index;
	buildPrimeTable();
	#if 0
	for(n=0; n<10; n++){
		printf("%d ", ans[n]);
	}
    printf("\n");
	#endif
	#if 1
	while(1 == scanf("%d", &n)){
		if(n < 0) break;
        if(n == 0) {
		    printf("Case %d: 0!\n", k++);
            continue;
        }
		index = mybsearch(n);
        if(index < 0){
		    printf("Case %d: Not possible.\n", k++);
        } else{
		    printf("Case %d: %d!\n", k++, index);
        }
	}
	#endif
    free(ans);
	return 0;
}

