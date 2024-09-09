#include <stdio.h>
#define MAX 31

int p2[MAX];

int gray(int n, int k){
/*find kth gray code of length n*/
	int result = 0;
	int bit = n - 1;
	int reverse = 0;
	while(bit >= 0){
		if(!reverse && (k >= p2[bit])){
			result += p2[bit];
			k = k - p2[bit];
			reverse = !reverse;
		} else if (reverse && (k < p2[bit])){
			result += p2[bit];
			reverse = !reverse;
		} else if (reverse && (k >= p2[bit])){
			k = k - p2[bit];	
		}
		bit--;
	}
	return result;
}

int main(){
	int nTest, n, k;
	for(n=0; n<MAX; n++){
		p2[n] = 1 << n;

	}
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d", &n, &k);
		/*ans = gray(n, k);*/
		printf("%d\n", gray(n, k));
	}
	return 0;
}