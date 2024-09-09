#include <stdio.h>


int gray(int n, int k){
/*find kth gray code of length n*/
	int result = 0;
	int bit = n - 1;
	int half;
	int reverse = 0;
	while(bit >= 0){
		half = 1 << bit;
		if(!reverse && (k >= half)){
			result += half;
			k = k - half;
			reverse = !reverse;
		} else if (!reverse && (k < half)){
			/*do nothing*/			
		} else if (reverse && (k < half)){
			result += half;
			reverse = !reverse;
		} else {
			k = k - half;	
		}

		bit--;
	}
	return result;
}

int main(){
	int nTest, n, k;
	
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d", &n, &k);
		/*ans = gray(n, k);*/
		printf("%d\n", gray(n, k));
	}
	return 0;
}