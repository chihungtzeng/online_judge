#include <stdio.h>
#define MAX 10

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

long long findUp(int nNum, int num[MAX]){
	int i;
	long long result = nNum;
	for(i=0; i<nNum; i++){
		result *= num[i];
	}
	return result;
}

long long findDown(int nNum, int num[MAX], long long totalProduct){
	int i;
	long long result = 0;
	for(i=0; i<nNum; i++){
		result += (totalProduct / num[i]);
	}
	return result;
}

int main(){
	int nNum, i, k = 1;
	int num[MAX];
	int nTest;
	long long g, up, down;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &nNum);
		for(i=0; i<nNum; i++){
			scanf("%d", num + i);
		}
		up = findUp(nNum, num);
		down = findDown(nNum, num, up/nNum);
		
		g = gcd(up, down);
		#if 0
		printf("up=%lld down=%lld g=%lld, totalProduct=%lld\n", up, down, g, up/nNum);
		#endif
		printf("Case %d: %lld/%lld\n", k++, up/g, down/g);
	}
	return 0;
}