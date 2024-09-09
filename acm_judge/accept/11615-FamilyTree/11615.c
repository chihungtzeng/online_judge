#include <stdio.h>
#include <math.h>
#define DEBUG 0

inline int level(int x){
	int sq;
	sq = log2(x);
	if(DEBUG){
		printf("level(%d)=%d\n", x, sq);
	}
	return sq;
}

inline int nAncestor(int N, int x){
	int result;
	result = (1 << (N - level(x))) - 2;
	if(DEBUG){
		printf("nAncestor(%d)=%d\n", x, result);
	}
	
	return result;
}

int main(){
	int N, A, B;
	short nTest;
	int na, nb, ans, min;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d %d", &N, &A, &B);
		na = nAncestor(N, A);
		nb = nAncestor(N, B);
		if(DEBUG){
			printf("na=%d nb=%d\n", na, nb);
		}
		if (na > nb){
			min = nb;
		}
		else {
			min = na;
		}
		ans = (1 << N) - min - 1;
		printf("%d\n",ans);
	}	
	return 0;
}