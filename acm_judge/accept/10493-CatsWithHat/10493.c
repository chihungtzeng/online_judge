#include <stdio.h>


int main(){
	long long N, M, MN;
	while(2 == scanf("%lld %lld", &N, &M)){
		if((M == 0) && (N == 0)) return 0;
		if((M == 1) && (N == 1)){
			puts("1 1 Multiple");
		} else if ((M != 1) && (N == 1)){
			printf("%lld %lld Impossible\n", N, M);
		} else {
			MN = M*N;
			if((MN - 1) % (N - 1) != 0){
				printf("%lld %lld Impossible\n", N, M);
			} else{
				printf("%lld %lld %lld\n", N, M, (MN - 1)/(N-1));
			}
		}
	}
	return 0;
}